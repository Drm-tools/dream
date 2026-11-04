# cmake -P script: writes the objcopy --redefine-syms map for the partially linked
# encoder object: every defined symbol except the API (odr_api.txt) gets the prefix
# "odrint_". Input: NM, RAW (the object), API (list of API symbols), MAP (output).
execute_process(COMMAND ${NM} --defined-only ${RAW} OUTPUT_VARIABLE NM_OUT RESULT_VARIABLE NM_RES)
if(NOT NM_RES EQUAL 0)
  message(FATAL_ERROR "nm failed on ${RAW}")
endif()
file(STRINGS ${API} API_SYMS)
string(REPLACE "\n" ";" NM_LINES "${NM_OUT}")
set(MAP_TEXT "")
set(SEEN "")
foreach(line IN LISTS NM_LINES)
  # "<address> <type> <name>" ; section and file symbols have no such form
  if(line MATCHES "^[0-9a-fA-F]+ ([A-Za-z]) (.+)$")
    set(type ${CMAKE_MATCH_1})
    set(name ${CMAKE_MATCH_2})
    # absolute symbols and the assembler's local labels (.LC0, ...) are not renamed;
    # a name that several objects define locally is listed once, objcopy renames all
    if(NOT type STREQUAL "a" AND NOT type STREQUAL "A" AND NOT name MATCHES "^\\.")
      list(FIND API_SYMS "${name}" idx)
      list(FIND SEEN "${name}" seen)
      if(idx EQUAL -1 AND seen EQUAL -1)
        list(APPEND SEEN "${name}")
        string(APPEND MAP_TEXT "${name} odrint_${name}\n")
      endif()
    endif()
  endif()
endforeach()
file(WRITE ${MAP} "${MAP_TEXT}")
