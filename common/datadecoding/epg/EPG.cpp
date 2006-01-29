/******************************************************************************\
 * British Broadcasting Corporation
 * Copyright (c) 2006
 *
 * Author(s):
 *	Julian Cable
 *
 * Description:
 *	ETSI DAB/DRM Electronic Programme Guide class
 *
 *
 ******************************************************************************
 *
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation; either version 2 of the License, or (at your option) any later 
 * version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT 
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more 
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc., 
 * 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 *
\******************************************************************************/

#include "EPG.h"
#include "epgutil.h"
#include <qfile.h>
#include <qtextstream.h>
#include <qregexp.h>

EPG::EPG ()
{
    genres["3"] = "CONTENT";
    genres["3.1"] = "INFORMATION";
    genres["3.1.1"] = "News";
    genres["3.3.3.1"] = "Daily news";
    genres["3.3.3.2"] = "Current affairs";
    genres["3.3.3.3"] = "Weather forecasts";
    genres["3.3.3.4"] = "Service information";
    genres["3.3.3.5"] = "Special news programs";
    genres["3.3.3.6"] = "Local / regional";
    genres["3.3.3.7"] = "Traffic";
    genres["3.3.3.8"] = "Magazines";
    genres["3.3.3.9"] = "News magazine";
    genres["3.3.3.10"] = "News/Report";
    genres["3.3.3.11"] = "Periodical/General";
    genres["3.3.3.12"] = "Special Edition/Documentary";
    genres["3.3.3.13"] = "Politics/National Assembly";
    genres["3.3.3.14"] = "Economy/Market";
    genres["3.3.3.15"] = "Foreign/International";
    genres["3.3.3.16"] = "Commentary";
    genres["3.3.3.17"] = "Debate/Talk";
    genres["3.3.3.18"] = "Special Report";
    genres["3.3.3.19"] = "Sports News";
    genres["3.3.3.20"] = "Others";
    genres["3.1.2"] = "Philosophies of life";
    genres["3.1.2.1"] = "Religious philosophies";
    genres["3.1.2.1.1"] = "Buddhism";
    genres["3.1.2.1.2"] = "Hinduism";
    genres["3.1.2.1.3"] = "Christinanity";
    genres["3.1.2.1.4"] = "Islam";
    genres["3.1.2.1.5"] = "Judaism";
    genres["3.1.2.2"] = "Non-religious philosophies";
    genres["3.1.2.2.1"] = "Communism";
    genres["3.1.2.2.2"] = "Humanism";
    genres["3.1.3"] = "Social/Political";
    genres["3.1.3.1"] = "Political";
    genres["3.1.3.2"] = "Social";
    genres["3.1.3.3"] = "Economical";
    genres["3.1.3.4"] = "Legal";
    genres["3.1.4"] = "Sports";
    genres["3.1.4.1"] = "Aeronautics";
    genres["3.1.4.2"] = "Aikido";
    genres["3.1.4.3"] = "American Football";
    genres["3.1.4.4"] = "Archery";
    genres["3.1.4.5"] = "Athletics";
    genres["3.1.4.6"] = "Badminton";
    genres["3.1.4.7"] = "Bandy";
    genres["3.1.4.8"] = "Baseball";
    genres["3.1.4.9"] = "basketball";
    genres["3.1.4.10"] = "Biathlon";
    genres["3.1.4.11"] = "Bicycle";
    genres["3.1.4.12"] = "Billiards";
    genres["3.1.4.13"] = "Bobsleigh/tobogganing";
    genres["3.1.4.14"] = "Body-building";
    genres["3.1.4.15"] = "Boules sport";
    genres["3.1.4.16"] = "Bowling";
    genres["3.1.4.17"] = "Boxing";
    genres["3.1.4.18"] = "Canoeing";
    genres["3.1.4.19"] = "Casting";
    genres["3.1.4.20"] = "Cricket";
    genres["3.1.4.21"] = "Croquet";
    genres["3.1.4.22"] = "Curling";
    genres["3.1.4.23"] = "Cycling";
    genres["3.1.4.24"] = "Dance sport";
    genres["3.1.4.25"] = "Diving";
    genres["3.1.4.26"] = "Equestrian";
    genres["3.1.4.27"] = "Faustball";
    genres["3.1.4.28"] = "Fencing";
    genres["3.1.4.29"] = "Fishing";
    genres["3.1.4.30"] = "Flying disc";
    genres["3.1.4.31"] = "football";
    genres["3.1.4.32"] = "golf";
    genres["3.1.4.33"] = "gymnastics";
    genres["3.1.4.34"] = "handball";
    genres["3.1.4.35"] = "hockey";
    genres["3.1.4.36"] = "ice-hockey";
    genres["3.1.4.37"] = "jai-alai";
    genres["3.1.4.38"] = "judo";
    genres["3.1.4.39"] = "ju-jitsu";
    genres["3.1.4.40"] = "karate";
    genres["3.1.4.41"] = "korfball";
    genres["3.1.4.42"] = "lacrosse";
    genres["3.1.4.43"] = "luge";
    genres["3.1.4.44"] = "maccabi";
    genres["3.1.4.45"] = "Marathon";
    genres["3.1.4.46"] = "modern pentathlon";
    genres["3.1.4.47"] = "motor boating";
    genres["3.1.4.48"] = "motor racing";
    genres["3.1.4.49"] = "motor cycling";
    genres["3.1.4.50"] = "mounteneering";
    genres["3.1.4.51"] = "netball";
    genres["3.1.4.52"] = "orienteering";
    genres["3.1.4.53"] = "polo";
    genres["3.1.4.54"] = "powerlifting";
    genres["3.1.4.55"] = "racquetball";
    genres["3.1.4.56"] = "roller skating";
    genres["3.1.4.57"] = "rowing";
    genres["3.1.4.58"] = "rugby";
    genres["3.1.4.59"] = "Running";
    genres["3.1.4.60"] = "shooting";
    genres["3.1.4.61"] = "skating";
    genres["3.1.4.62"] = "skiing";
    genres["3.1.4.63"] = "skibob";
    genres["3.1.4.64"] = "sleddog";
    genres["3.1.4.65"] = "soccer";
    genres["3.1.4.66"] = "softball";
    genres["3.1.4.67"] = "soft tennis";
    genres["3.1.4.68"] = "sombo";
    genres["3.1.4.69"] = "sport acrobatics";
    genres["3.1.4.70"] = "squash";
    genres["3.1.4.71"] = "subaquatics";
    genres["3.1.4.72"] = "surfing";
    genres["3.1.4.73"] = "swimming/diving";
    genres["3.1.4.74"] = "table tennis";
    genres["3.1.4.75"] = "taekwondo";
    genres["3.1.4.76"] = "tennis";
    genres["3.1.4.77"] = "trampoline";
    genres["3.1.4.78"] =
	"Track/Field Collection of sports at athletic field and track";
    genres["3.1.4.79"] = "triathlon";
    genres["3.1.4.80"] = "tug-of-war";
    genres["3.1.4.81"] = "volleyball";
    genres["3.1.4.82"] = "water polo";
    genres["3.1.4.83"] = "water-skiing";
    genres["3.1.4.84"] = "weightlifting";
    genres["3.1.4.85"] = "wrestling";
    genres["3.1.4.86"] = "yachting";
    genres["3.1.4.87"] = "Other ball games";
    genres["3.1.4.88"] = "combative sports";
    genres["3.1.4.89"] = "Snowboarding";
    genres["3.1.4.90"] = "Team sport (excluding football / soccer)";
    genres["3.1.4.91"] = "Martial sports";
    genres["3.1.4.92"] = "SUMO/Fighting Games";
    genres["3.1.4.93"] = "Snooker";
    genres["3.1.4.94"] = "Pool";
    genres["3.1.4.95"] = "Darts";
    genres["3.1.4.93"] = "Others";
    genres["3.1.5"] = "Human interest";
    genres["3.1.5.1"] = "Reality";
    genres["3.1.5.2"] = "Show business";
    genres["3.1.5.3"] = "Notable personalities";
    genres["3.1.5.4"] = "Personal problems";
    genres["3.1.6"] = "Leisure";
    genres["3.1.6.1"] = "Do-it-yourself";
    genres["3.1.6.2"] = "Cookery";
    genres["3.1.6.3"] = "Gardening";
    genres["3.1.6.4"] = "Tourism";
    genres["3.1.6.5"] = "Travel";
    genres["3.1.6.6"] = "fishing";
    genres["3.1.6.7"] = "Outdoors sports just for fun or personal health";
    genres["3.1.6.8"] = "Motoring";
    genres["3.1.6.9"] = "Keep-fit";
    genres["3.1.6.10"] = "Fashion";
    genres["3.1.6.11"] = "Computing";
    genres["3.1.6.12"] = "handicrafts";
    genres["3.1.6.13"] = "pets";
    genres["3.1.6.14"] = "Music";
    genres["3.1.6.15"] = "Igo / shogi (Japanese chess)";
    genres["3.1.6.16"] = "Mah-jongg / pachinko";
    genres["3.1.6.17"] = "Fitness";
    genres["3.1.6.18"] = "Health / medical";
    genres["3.1.6.19"] = "Advertisement / Schopping";
    genres["3.1.7"] = "Arts & Media";
    genres["3.1.7.1"] =
	"Music Programme about a musical subject Not programme consisting of music";
    genres["3.1.7.2"] = "art";
    genres["3.1.7.3"] = "industrial arts";
    genres["3.1.7.4"] = "Plastic Arts";
    genres["3.1.7.5"] =
	"Theatre/Cinema Programme about subject concerning the world of the film and cinema. Not programme consisting of cinema films";
    genres["3.1.7.6"] =
	"Advertising Programme about (the world of) advertising";
    genres["3.1.7.7"] = "Press";
    genres["3.1.7.8"] = "Performing";
    genres["3.1.7.9"] = "Fine arts";
    genres["3.1.7.10"] = "Traditional arts";
    genres["3.1.7.11"] = "exprimental arts Film / Video";
    genres["3.1.7.12"] = "New Media";
    genres["3.1.8"] =
	"Humanities The branches of learning regarded as having primarily a cultural character and which usually include languge, literature, history, mathematics and philosophy.";
    genres["3.1.8.1"] = "Literature";
    genres["3.1.8.2"] = "Languages";
    genres["3.1.8.3"] = "History";
    genres["3.1.9"] = "Sciences";
    genres["3.1.9.1"] =
	"Applied sciences Sciences dealing with material phenomena or industrial processes.";
    genres["3.1.9.2"] =
	"Natural sciences Biology, botany, geology and zoology.";
    genres["3.1.9.3"] =
	"Physical sciences Astronomy, chemistry, electricity, mechanics, physics.";
    genres["3.1.9.4"] =
	"Medicine Programmes bout medical subjects, health etc";
    genres["3.1.9.5"] = "Technology";
    genres["3.1.9.6"] = "Physiology";
    genres["3.1.9.7"] = "Psychology";
    genres["3.1.9.8"] = "Social";
    genres["3.1.9.9"] = "Spiritual";
    genres["3.2"] = "Drama";
    genres["3.2.1"] = "Popular drama";
    genres["3.2.1.1"] = "General light drama";
    genres["3.2.1.2"] =
	"Comedy Dramatized series in a humourous style and performed by a vary­ing cast.";
    genres["3.2.1.3"] = "Comedy sketch show";
    genres["3.2.1.4"] = "Sitcom";
    genres["3.2.1.5"] = "Soap";
    genres["3.2.1.6"] = "Medical";
    genres["3.2.1.7"] = "Action";
    genres["3.2.7.1"] = "Adventure/disaster";
    genres["3.2.7.2"] = "Detective/thriller";
    genres["3.2.7.3"] = "Epic";
    genres["3.2.7.4"] = "Horror";
    genres["3.2.7.5"] = "Science fiction";
    genres["3.2.7.6"] = "War";
    genres["3.2.7.7"] = "Western";
    genres["3.2.7.8"] = "Folkloric";
    genres["3.2.1.8"] = "Fantasy/Fairy tale";
    genres["3.2.1.9"] = "Erotica";
    genres["3.2.1.10"] = "Romance";
    genres["3.2.1.11"] = "Legal";
    genres["3.2.1.12"] = "Soap Opera";
    genres["3.2.1.13"] = "Soap Special";
    genres["3.2.1.14"] = "Soap Talk";
    genres["3.2.2"] = "Serious drama";
    genres["3.2.2.1"] = "Clasical drama";
    genres["3.2.2.2"] = "Contemporary drama";
    genres["3.4.1"] = "Music";
    genres["3.4.1.2"] = "Classical and Romantic music";
    genres["3.4.1.3"] = "Contemporary Serious music";
    genres["3.4.1.4"] = "Light classical";
    genres["3.4.1.5"] = "Opera";
    genres["3.4.1.6"] = "Classical music";
    genres["3.4.2"] = "Jazz";
    genres["3.4.2.1"] = "Jazz / fusion";
    genres["3.4.2.2"] = "Traditional Jazz";
    genres["3.4.2.3"] = "Modern Jazz";
    genres["3.4.2.4"] = "Pop Jazz";
    genres["3.4.3"] = "Middle-of-the-road Music";
    genres["3.4.3.1"] = "European popular traditional music";
    genres["3.4.3.2"] = "World Music";
    genres["3.4.4"] = "Pop/rock";
    genres["3.4.4.1"] = "World Music";
    genres["3.4.4.2"] = "Folk Music";
    genres["3.4.4.2.1"] = "Traditional Folk Music";
    genres["3.4.4.2.2"] = "Contemporary Folk Music";
    genres["3.4.4.2.3"] = "Folk Ballads";
    genres["3.4.5"] = "Country Music";
    genres["3.4.6"] = "Traditional Music";
    genres["3.4.5.1"] = "Ethnic Music";
    genres["3.4.6"] = "Popular music";
    genres["3.4.6.1"] = "Foreign rock / pop";
    genres["3.4.6.2"] = "Japanese rock / pop";
    genres["3.4.6.3"] = "Japanese ballads / Enka";
    genres["3.4.6.4"] = "Live performances / concerts";
    genres["3.4.6.5"] = "Rankings / requests";
    genres["3.4.6.6"] = "Karaoke / singing contests";
    genres["3.4.6.7"] = "Folk music / (Japanese) folk music";
    genres["3.4.6.8"] = "Nursery songs / children's music";
    genres["3.4.6.9"] = "Culture-specific music / world music";
    genres["3.4.6.10"] = "Domestic Rock/Pop";
    genres["3.4.7"] =
	"Ballet TV programmes (predominantly) consisting of music, dance or ballet.";
    genres["3.4.7.1"] = "Ballet";
    genres["3.4.8"] = "Dance";
    genres["3.4.8.1"] = "Dance Programme performed by (ballet) dancers";
    genres["3.4.9"] = "Live Concert";
    genres["3.4.10"] = "Hit-Chart/Song Requests";
    genres["3.4.11"] = "Traditional Folksong/Traditional Music";
    genres["3.4.12"] = "Children's Song";
    genres["3.4.13"] = "Ethnic Music/World Music";
    genres["3.4.14"] = "National Music";
    genres["3.4.15"] = "Alternative";
    genres["3.4.16"] = "Events";
    genres["3.4.17"] = "Hip Hop";
    genres["3.4.18"] = "Soul Rythm and Blues";
    genres["3.4.19"] = "Club and Dance";
    genres["3.4.20"] = "Others";
    genres["3.5"] = "ENRICHMENT";
    genres["3.5.1"] =
	"General enrichment Programme primarily intended to increase knowledge about non-current subjects in a non-didactic way";
    genres["3.5.2"] =
	"Inspirational enrichment Programme based on different forms of religious beliefs or intended to edify the audience.";
    genres["3.5.3"] =
	"Education Programme primarily intended to increase knowledge about non-current subjects in a explicitly didactic way.";
    genres["3.5.4"] = "language studies";
    genres["3.5.5"] = "Foreign language conversation";
    genres["3.5.6"] = "Informational";
    genres["3.5.7"] = "School programmes";
    genres["3.5.8"] = "entrance exams";
    genres["3.5.9"] = "Lifelong education";
    genres["3.5.10"] = "certification";
    genres["3.5.11"] = "Educational issues";
    genres["3.6"] = "Movies Film, Cinema";
    genres["3.6.1"] = "Eastern";
    genres["3.6.2"] = "Effect Movies";
    genres["3.6.3"] = "Fiction";
    genres["3.6.4"] = "Science Fiction";
    genres["3.6.5"] = "Horror";
    genres["3.6.6"] = "Romance";
    genres["3.6.7"] = "Romance comedy";
    genres["3.6.8"] = "Thriller";
    genres["3.6.9"] = "War";
    genres["3.6.10"] = "Western";
    genres["3.6.11"] = "Western comedy";
    genres["3.6.12"] = "Detective";
    genres["3.6.13"] = "Adventure";
    genres["3.6.14"] = "Fantasy";
    genres["3.6.15"] = "Comedy";
    genres["3.6.16"] = "Romance";
    genres["3.6.17"] = "Historical";
    genres["3.6.18"] = "Adult";
    genres["3.6.19"] = "Foreign Movie";
    genres["3.6.20"] = "Domestic Movie";
    genres["3.6.21"] = "Animation";
    genres["3.6.22"] = "Family";
    genres["3.6.23"] = "Musical";
    genres["3.6.24"] = "Mystery";
    genres["3.6.25"] = "Action";
    genres["3.6.26"] = "Factual";
    genres["3.6.27"] = "Erotic";
    genres["3.6.28"] = "Drama";
    genres["3.6.29"] = "Others";
    genres["3.7"] = "Animations / special effects";
    genres["3.7.1"] = "Animated films";
    genres["3.7.2"] = "Animated musical";
    genres["3.7.3"] = "Japanese animations";
    genres["3.7.4"] = "Foreign animations";
    genres["3.7.5"] = "Animation/SFX Special effects animation movie";
    genres["3.7.6"] = "Domestic Animation";
    genres["3.7.7"] = "SFX Special effects movie";
    genres["3.7.8"] = "Animation";
    genres["3.7.9"] = "Others";
    genres["3.8"] = "Hobby";
    genres["3.8.1"] = "Travel";
    genres["3.8.2"] = "Fishing";
    genres["3.8.3"] = "Outdoor";
    genres["3.8.4"] = "Gardening";
    genres["3.8.5"] = "Pet";
    genres["3.8.6"] = "Handicraft";
    genres["3.8.7"] = "Art";
    genres["3.8.8"] = "Craft";
    genres["3.8.9"] = "Music";
    genres["3.8.10"] = "SHOGI";
    genres["3.8.11"] = "GO";
    genres["3.8.12"] = "PACHINCO";
    genres["3.8.13"] = "MAJAN";
    genres["3.8.14"] = "Car";
    genres["3.8.15"] = "Motorcycle";
    genres["3.8.16"] = "Computer";
    genres["3.8.17"] = "Video Game";
    genres["3.8.18"] = "Life/ House Keeping";
    genres["3.8.19"] = "Technology";
    genres["3.8.20"] = "Shopping";
    genres["3.8.21"] = "Others";
    genres["3.9"] = "Sport Events";
    genres["3.9.1"] = "international competitions";
    genres["3.9.2"] =
	"Horseracing / Government-sponsored sporting events (cycling, boat races, etc.)";
    genres["3.9.3"] = "Marine";
    genres["3.9.4"] = "Sports Event";
    genres["3.9.5"] = "winter sports";
    genres["3.9.6"] = "Sports Non-Event";
    genres["3.9.7"] = "Sports Talk";
    genres["3.9.8"] = "track and field";
    genres["3.9.9"] = "Special Events";
    genres["3.9.10"] = "Olympic games";
    genres["3.9.11"] = "Woldcup";
    genres["3.9.12"] = "Sports magazine";
    genres["3.9.13"] = "Water sport";
    genres["3.9.14"] = "Live sports events";
    genres["3.9.15"] = "Motorsport";
    genres["3.9.16"] = "Others";
    genres["3.10"] = "Pure information";
    genres["3.10.1"] =
	"Infotainment Programmes intended primarily to entertain but with substantial informative elements.";
    genres["3.10.2"] =
	"Advice Programme intended to advise about matters of personal interest such as consumer prices and quality, financial matters, health, or, for the interest of special groups, weather or traffic information";
    genres["3.10.3"] = "Politics / the Diet";
    genres["3.10.4"] = "Economy / Market conditions";
    genres["3.10.5"] = "Overseas / international";
    genres["3.10.6"] = "Commentary";
    genres["3.10.7"] = "Debates / conferences";
    genres["3.10.8"] = "Social issues";
    genres["3.10.9"] = "Economics advisory";
    genres["3.10.10"] = "Discussion";
    genres["3.10.11"] = "Social advisory";
    genres["3.10.12"] = "Interviews";
    genres["3.10.13"] = "Others";
    genres["3.11"] = "Information/ tabloid";
    genres["3.11.1"] = "Entertainment / tabloid";
    genres["3.11.2"] = "Fashion";
    genres["3.11.3"] = "Lifestyle / living space";
    genres["3.11.4"] = "Health";
    genres["3.11.5"] = "Shopping / mail order & telephone shopping";
    genres["3.11.6"] = "Gourmet eating / cooking";
    genres["3.11.7"] = "Special Events";
    genres["3.11.8"] = "Program introductions / notices";
    genres["3.11.9"] = "Remarkable people";
    genres["3.11.10"] = "medical care";
    genres["3.11.11"] = "Others";
    genres["3.12"] =
	"Documentary Programme concerning a single theme, involving descriptive and/or interpretative commentaries, illustrations, interviews, statements, photos or other documentation.";
    genres["3.12.1"] = "Society";
    genres["3.12.2"] = "current events";
    genres["3.12.3"] = "History";
    genres["3.12.4"] = "travelogues";
    genres["3.12.5"] = "Nature";
    genres["3.12.6"] = "animals";
    genres["3.12.7"] = "the environment";
    genres["3.12.8"] = "Space";
    genres["3.12.9"] = "science";
    genres["3.12.10"] = "medicine";
    genres["3.12.11"] = "Culture";
    genres["3.12.12"] = "tradition";
    genres["3.12.13"] = "Literature and the arts";
    genres["3.12.14"] = "Sports";
    genres["3.12.15"] = "General documentaries";
    genres["3.12.16"] = "Interviews";
    genres["3.12.17"] = "debates";
    genres["3.12.18"] =
	"Discussion Mainly verbal programme in which more than one person participates.";
    genres["3.12.19"] =
	"Lecture Mainly verbal programme in which only one person participates.";
    genres["3.12.20"] = "Speech";
    genres["3.12.21"] = "Presentation";
    genres["3.12.22"] =
	"Textual (incl. relayed teletext) Programme consisting only of alphanumerical information.";
    genres["3.12.23"] = "Special features";
    genres["3.12.24"] = "Foreign countries";
    genres["3.12.25"] = "Expeditions";
    genres["3.12.26"] = "Current Topics";
    genres["3.12.27"] = "Universe";
    genres["3.12.28"] = "Traditional Culture";
    genres["3.12.29"] = "War";
    genres["3.12.30"] = "Transport";
    genres["3.12.31"] = "Business";
    genres["3.12.32"] = "World Culture";
    genres["3.12.33"] = "Biography";
    genres["3.12.34"] = "Adventure";
    genres["3.12.35"] = "Features";
    genres["3.12.36"] = "Politics";
    genres["3.12.37"] = "Educational";
    genres["3.12.38"] = "Features";
    genres["3.12.39"] = "Religious";
    genres["3.12.40"] = "Showbiz";
    genres["3.12.41"] = "Others";
    genres["3.13"] = "Education";
    genres["3.13.1"] = "Education Study";
    genres["3.13.2"] = "Further education";
    genres["3.13.3"] = "Languages";
    genres["3.13.4"] = "Infants";
    genres["3.13.5"] = "School Children";
    genres["3.13.6"] = "Junior High-school";
    genres["3.13.7"] = "High-school";
    genres["3.13.8"] = "Students";
    genres["3.13.9"] = "Entrance Examination";
    genres["3.13.10"] = "Lifelong Education";
    genres["3.13.11"] = "Qualification";
    genres["3.13.12"] = "Educational Problems";
    genres["3.14"] = "Children";
    genres["3.14.1"] = "Cartoons";
    genres["3.14.2"] = "Comedy";
    genres["3.14.3"] = "Drama";
    genres["3.14.4"] = "Educational";
    genres["3.14.5"] = "Factual";
    genres["3.14.6"] = "Magazine";
    genres["3.14.7"] = "Game Shows";
    genres["3.14.8"] = "Other";
    dir = EPG_SAVE_PATH;
    servicesFilename = dir + "/services.xml";
    loadChannels (servicesFilename);
    saveChannels (servicesFilename);
}

void
EPG::addChannel (const QString & label, uint32_t sid)
{
    if (!sids.contains (label))
      {
	  sids[label] = sid;
	  saveChannels (servicesFilename);
      }
}

void
EPG::select (const QString & chan, const CDateAndTime & d)
{
    if (!sids.contains (chan))
      {
	  return;
      }
    uint32_t sid = sids[chan];
    progs.clear ();
    /* look for the basic profile */
    QString fileName;
    fileName = dir + "/" + QString (epgFilename (d, sid, 1, false).c_str ());
    getFile (basic, fileName);
    /* look for the advanced profile */
    fileName = dir + "/" + QString (epgFilename (d, sid, 1, true).c_str ());
    getFile (advanced, fileName);
    if (progs.count () == 0)
      {
	  return;
      }
}

void
EPG::getFile (CEPGDecoder & epg, const QString & fileName)
{
    QFile file (fileName);
    if (!file.open (IO_ReadOnly))
      {
	  return;
      }
    vector < _BYTE > vecData;
    vecData.resize (file.size ());
    vecData.resize (file.size ());
    file.readBlock ((char *) &vecData.front (), file.size ());
    file.close ();
    epg.decode (vecData);
    QDomNodeList programmes = epg.doc.elementsByTagName ("programme");
    parseDoc (programmes.item (0));
}

void
EPG::parseDoc (const QDomNode & n)
{
    QDomNode l1 = n;
    while (!l1.isNull ())
      {
	  if (l1.nodeName () == "programme")
	    {
		QDomNode l2 = l1.firstChild ();
		uint32_t shortId =
		    l1.toElement ().attribute ("shortId", "0").toInt ();
		CProg p;
		if (progs.contains (shortId))
		    p = progs[shortId];
		while (!l2.isNull ())
		  {
		      if (l2.isElement ())
			{
			    QDomElement e = l2.toElement ();
			    if (e.tagName () == "location")
			      {
				  QDomNode l3 = e.firstChild ();
				  while (!l3.isNull ())
				    {
					if (l3.isElement ())
					  {
					      QDomElement e = l3.toElement ();
					      if (e.tagName () == "time")
						{
						    QString start =
							e.
							attribute
							("actualTime");
						    if (start != "")
						      {
							  p.start =
							      parseStart
							      (start);
							  p.duration =
							      parseDuration
							      (e.
							       attribute
							       ("actualDuration"));
						      }
						    else
						      {
							  start =
							      e.
							      attribute
							      ("time");
							  if (start != "")
							    {
								p.start =
								    parseStart
								    (start);
								p.duration =
								    parseDuration
								    (e.
								     attribute
								     ("duration"));
							    }
						      }
						}
					  }
					l3 = l3.nextSibling ();
				    }
			      }
			    if (e.tagName () == "mediumName" && p.name == "")
				p.name = e.text ();
			    if (e.tagName () == "longName")
				p.name = e.text ();
			    if (e.tagName () == "mediaDescription")
			      {
				  QDomNode l3 = e.firstChild ();
				  while (!l3.isNull ())
				    {
					if (l3.isElement ())
					  {
					      QDomElement e = l3.toElement ();
					      if (e.tagName () ==
						  "shortDescription")
						{
						    p.description = e.text ();
						}
					  }
					l3 = l3.nextSibling ();
				    }
			      }
			    if (e.tagName () == "genre")
			      {
				  QString type = e.attribute ("type", "main");
				  if (type == "main")
				      p.mainGenre =
					  genres[e.attribute ("href")];
				  else if (type == "secondary")
				      p.secondaryGenre =
					  genres[e.attribute ("href")];
				  else if (type == "other")
				      p.otherGenre =
					  genres[e.attribute ("href")];
			      }
			}
		      l2 = l2.nextSibling ();
		  }
		if (shortId != 0)
		  {
		      progs[shortId] = p;
		  }
	    }
	  l1 = l1.nextSibling ();
      }
}

/*
<service>
<serviceID id="e1.ce15.c221.0" />
<shortName>Radio 1</shortName>
<mediumName>BBC Radio 1</mediumName>
</service>
*/

void
EPG::saveChannels (const QString & fileName)
{
    QFile f (fileName);
    if (!f.open (IO_WriteOnly))
      {
	  return;
      }
    QDomDocument doc ("serviceInformation");
    QDomElement root = doc.createElement ("serviceInformation");
    doc.appendChild (root);
    QDomElement ensemble = doc.createElement ("ensemble");
    root.appendChild (ensemble);
    for (QMap < QString, uint32_t >::Iterator i = sids.begin ();
	 i != sids.end (); i++)
      {
	  QDomElement service = doc.createElement ("service");
	  QDomElement serviceID = doc.createElement ("serviceID");
	  serviceID.setAttribute ("id",
				  QString::number (ulong (i.data ()), 16));
	  service.appendChild (serviceID);
	  QDomElement shortName = doc.createElement ("shortName");
	  QDomText text = doc.createTextNode (i.key ());
	  shortName.appendChild (text);
	  service.appendChild (shortName);
	  ensemble.appendChild (service);
      }
    QTextStream stream (&f);
    stream << doc.toString ();
    f.close ();

}

void
EPG::loadChannels (const QString & fileName)
{
    sids.clear ();
    QDomDocument domTree;
    QFile f (fileName);
    if (!f.open (IO_ReadOnly))
      {
	  sids.insert ("BBCWorld Service", 0xE1C238);
	  return;
      }
    if (!domTree.setContent (&f))
      {
	  f.close ();
	  return;
      }
    f.close ();
    QDomNodeList ensembles = domTree.elementsByTagName ("ensemble");
    QDomNode n = ensembles.item (0).firstChild ();
    while (!n.isNull ())
      {
	  if (n.nodeName () == "service")
	    {
		QDomNode e = n.firstChild ();
		QString name, sid;
		while (!e.isNull ())
		  {
		      if (e.isElement ())
			{
			    QDomElement s = e.toElement ();
			    if (s.tagName () == "shortName")
				name = s.text ();
			    if (s.tagName () == "serviceID")
				sid = s.attribute ("id");
			}
		      e = e.nextSibling ();
		  }
		if (name != "")
		  {
		      sids.insert (name, sid.toUInt (NULL, 16));
		  }
	    }
	  n = n.nextSibling ();
      }
}

QString
EPG::parseStart (const QString & start)
{
    QStringList d = QStringList::split ('+', start, true);
    QStringList t = QStringList::split ('T', d[0], true);
    QStringList hms = QStringList::split (':', t[1], true);
    if (hms[2] == "00")
	return hms[0] + ":" + hms[1];
    else
	return t[1];
}

QString
EPG::parseDuration (const QString & duration)
{
    QRegExp r ("[TPHMS]");
    QStringList dur = QStringList::split (r, duration);
    return
	QCString ("").sprintf ("%02u:%02u", dur[1].toInt (), dur[2].toInt ());
}
