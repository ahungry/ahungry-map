#ifndef ZONE_LIST_H
#define ZONE_LIST_H

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

/**
 * Class for storing the ZoneList (parser names to file names)
 */
class ZoneList
{
public:
  ZoneList ();
  std::string get (std::string parseName);
};

ZoneList::ZoneList ()
{
  std::cout << " zoneList init " << std::endl;
}

std::string ZoneList::get (std::string parseName)
{
  if ("South Qeynos" == parseName)
    {
      return "qeynos";
    }

  if ("North Qeynos" == parseName)
    {
      return "qeynos2";
    }

  if ("The Surefall Glade" == parseName)
    {
      return "qrg";
    }

  if ("The Qeynos Hills" == parseName)
    {
      return "qeytoqrg";
    }

  if ("Highpass Hold" == parseName)
    {
      return "highpass";
    }

  if ("High Keep" == parseName)
    {
      return "highkeep";
    }

  if ("North Freeport" == parseName)
    {
      return "freportn";
    }

  if ("West Freeport" == parseName)
    {
      return "freportw";
    }

  if ("East Freeport" == parseName)
    {
      return "freporte";
    }

  if ("The Liberated Citadel of Runnyeye" == parseName)
    {
      return "runnyeye";
    }

  if ("The Western Plains of Karana" == parseName)
    {
      return "qey2hh1";
    }

  if ("The Northern Plains of Karana" == parseName)
    {
      return "northkarana";
    }

  if ("The Southern Plains of Karana" == parseName)
    {
      return "southkarana";
    }

  if ("Eastern Plains of Karana" == parseName)
    {
      return "eastkarana";
    }

  if ("Gorge of King Xorbb" == parseName)
    {
      return "beholder";
    }

  if ("Blackburrow" == parseName)
    {
      return "blackburrow";
    }

  if ("The Lair of the Splitpaw" == parseName)
    {
      return "paw";
    }

  if ("Rivervale" == parseName)
    {
      return "rivervale";
    }

  if ("Kithicor Forest" == parseName)
    {
      return "kithicor";
    }

  if ("West Commonlands" == parseName)
    {
      return "commons";
    }

  if ("East Commonlands" == parseName)
    {
      return "ecommons";
    }

  if ("The Erudin Palace" == parseName)
    {
      return "erudnint";
    }

  if ("Erudin" == parseName)
    {
      return "erudnext";
    }

  if ("The Nektulos Forest" == parseName)
    {
      return "nektulos";
    }

  if ("The Nektulos Forest" == parseName)
    {
      return "nektulos";
    }

  if ("Sunset Home" == parseName)
    {
      return "cshome";
    }

  if ("The Lavastorm Mountains" == parseName)
    {
      return "lavastorm";
    }

  if ("Nektropos" == parseName)
    {
      return "nektropos";
    }

  if ("Halas" == parseName)
    {
      return "halas";
    }

  if ("Everfrost Peaks" == parseName)
    {
      return "everfrost";
    }

  if ("Solusek's Eye" == parseName)
    {
      return "soldunga";
    }

  if ("Nagafen's Lair" == parseName)
    {
      return "soldungb";
    }

  if ("Misty Thicket" == parseName)
    {
      return "misty";
    }

  if ("Northern Desert of Ro" == parseName)
    {
      return "nro";
    }

  if ("Southern Desert of Ro" == parseName)
    {
      return "sro";
    }

  if ("Befallen" == parseName)
    {
      return "befallen";
    }

  if ("Oasis of Marr" == parseName)
    {
      return "oasis";
    }

  if ("Toxxulia Forest" == parseName)
    {
      return "tox";
    }

  if ("The Hole" == parseName)
    {
      return "hole";
    }

  if ("Neriak - Foreign Quarter" == parseName)
    {
      return "neriaka";
    }

  if ("Neriak - Commons" == parseName)
    {
      return "neriakb";
    }

  if ("Neriak - 3rd Gate" == parseName)
    {
      return "neriakc";
    }

  if ("Neriak Palace" == parseName)
    {
      return "neriakd";
    }

  if ("Najena" == parseName)
    {
      return "najena";
    }

  if ("The Qeynos Aqueduct System" == parseName)
    {
      return "qcat";
    }

  if ("Innothule Swamp" == parseName)
    {
      return "innothule";
    }

  if ("The Feerrott" == parseName)
    {
      return "feerrott";
    }

  if ("Accursed Temple of CazicThule" == parseName)
    {
      return "cazicthule";
    }

  if ("Oggok" == parseName)
    {
      return "oggok";
    }

  if ("The Rathe Mountains" == parseName)
    {
      return "rathemtn";
    }

  if ("Lake Rathetear" == parseName)
    {
      return "lakerathe";
    }

  if ("Grobb" == parseName)
    {
      return "grobb";
    }

  if ("Aviak Village" == parseName)
    {
      return "aviak";
    }

  if ("The Greater Faydark" == parseName)
    {
      return "gfaydark";
    }

  if ("Ak'Anon" == parseName)
    {
      return "akanon";
    }

  if ("Steamfont Mountains" == parseName)
    {
      return "steamfont";
    }

  if ("The Lesser Faydark" == parseName)
    {
      return "lfaydark";
    }

  if ("Crushbone" == parseName)
    {
      return "crushbone";
    }

  if ("The Castle of Mistmoore" == parseName)
    {
      return "mistmoore";
    }

  if ("South Kaladim" == parseName)
    {
      return "kaladima";
    }

  if ("Northern Felwithe" == parseName)
    {
      return "felwithea";
    }

  if ("Southern Felwithe" == parseName)
    {
      return "felwitheb";
    }

  if ("The Estate of Unrest" == parseName)
    {
      return "unrest";
    }

  if ("Kedge Keep" == parseName)
    {
      return "kedge";
    }

  if ("The City of Guk" == parseName)
    {
      return "guktop";
    }

  if ("The Ruins of Old Guk" == parseName)
    {
      return "gukbottom";
    }

  if ("North Kaladim" == parseName)
    {
      return "kaladimb";
    }

  if ("Butcherblock Mountains" == parseName)
    {
      return "butcher";
    }

  if ("Ocean of Tears" == parseName)
    {
      return "oot";
    }

  if ("Dagnor's Cauldron" == parseName)
    {
      return "cauldron";
    }

  if ("The Plane of Sky" == parseName)
    {
      return "airplane";
    }

  if ("The Plane of Fear" == parseName)
    {
      return "fearplane";
    }

  if ("The Permafrost Caverns" == parseName)
    {
      return "permafrost";
    }

  if ("Kerra Isle" == parseName)
    {
      return "kerraridge";
    }

  if ("Paineel" == parseName)
    {
      return "paineel";
    }

  if ("Plane of Hate" == parseName)
    {
      return "hateplane";
    }

  if ("The Arena" == parseName)
    {
      return "arena";
    }

  if ("The Field of Bone" == parseName)
    {
      return "fieldofbone";
    }

  if ("The Warsliks Woods" == parseName)
    {
      return "warslikswood";
    }

  if ("The Temple of Solusek Ro" == parseName)
    {
      return "soltemple";
    }

  if ("The Temple of Droga" == parseName)
    {
      return "droga";
    }

  if ("Cabilis West" == parseName)
    {
      return "cabwest";
    }

  if ("The Swamp of No Hope" == parseName)
    {
      return "swampofnohope";
    }

  if ("Firiona Vie" == parseName)
    {
      return "firiona";
    }

  if ("Lake of Ill Omen" == parseName)
    {
      return "lakeofillomen";
    }

  if ("The Dreadlands" == parseName)
    {
      return "dreadlands";
    }

  if ("The Burning Wood" == parseName)
    {
      return "burningwood";
    }

  if ("Kaesora" == parseName)
    {
      return "kaesora";
    }

  if ("The Ruins of Sebilis" == parseName)
    {
      return "sebilis";
    }

  if ("The City of Mist" == parseName)
    {
      return "citymist";
    }

  if ("The Skyfire Mountains" == parseName)
    {
      return "skyfire";
    }

  if ("Frontier Mountains" == parseName)
    {
      return "frontiermtns";
    }

  if ("The Overthere" == parseName)
    {
      return "overthere";
    }

  if ("The Emerald Jungle" == parseName)
    {
      return "emeraldjungle";
    }

  if ("Trakanon's Teeth" == parseName)
    {
      return "trakanon";
    }

  if ("Timorous Deep" == parseName)
    {
      return "timorous";
    }

  if ("Kurn's Tower" == parseName)
    {
      return "kurn";
    }

  if ("Erud's Crossing" == parseName)
    {
      return "erudsxing";
    }

  if ("The Stonebrunt Mountains" == parseName)
    {
      return "stonebrunt";
    }

  if ("The Warrens" == parseName)
    {
      return "warrens";
    }

  if ("Karnor's Castle" == parseName)
    {
      return "karnor";
    }

  if ("Chardok" == parseName)
    {
      return "chardok";
    }

  if ("The Crypt of Dalnir" == parseName)
    {
      return "dalnir";
    }

  if ("The Howling Stones" == parseName)
    {
      return "charasis";
    }

  if ("Cabilis East" == parseName)
    {
      return "cabeast";
    }

  if ("The Mines of Nurga" == parseName)
    {
      return "nurga";
    }

  if ("Veeshan's Peak" == parseName)
    {
      return "veeshan";
    }

  if ("Veksar" == parseName)
    {
      return "veksar";
    }

  if ("The Iceclad Ocean" == parseName)
    {
      return "iceclad";
    }

  if ("The Tower of Frozen Shadow" == parseName)
    {
      return "frozenshadow";
    }

  if ("Velketor's Labyrinth" == parseName)
    {
      return "velketor";
    }

  if ("Kael Drakkel" == parseName)
    {
      return "kael";
    }

  if ("Skyshrine" == parseName)
    {
      return "skyshrine";
    }

  if ("Skyshrine" == parseName)
    {
      return "skyshrine";
    }

  if ("The City of Thurgadin" == parseName)
    {
      return "thurgadina";
    }

  if ("Eastern Wastes" == parseName)
    {
      return "eastwastes";
    }

  if ("Cobaltscar" == parseName)
    {
      return "cobaltscar";
    }

  if ("The Great Divide" == parseName)
    {
      return "greatdivide";
    }

  if ("The Wakening Land" == parseName)
    {
      return "wakening";
    }

  if ("The Western Wastes" == parseName)
    {
      return "westwastes";
    }

  if ("The Crystal Caverns" == parseName)
    {
      return "crystal";
    }

  if ("Dragon Necropolis" == parseName)
    {
      return "necropolis";
    }

  if ("The Temple of Veeshan" == parseName)
    {
      return "templeveeshan";
    }

  if ("Siren's Grotto" == parseName)
    {
      return "sirens";
    }

  if ("The Plane of Mischief" == parseName)
    {
      return "mischiefplane";
    }

  if ("The Plane of Growth" == parseName)
    {
      return "growthplane";
    }

  if ("The Sleeper's Tomb" == parseName)
    {
      return "sleeper";
    }

  if ("Icewell Keep" == parseName)
    {
      return "thurgadinb";
    }

  if ("Marauders Mire" == parseName)
    {
      return "erudsxing2";
    }

  if ("Shadow Haven" == parseName)
    {
      return "shadowhaven";
    }

  if ("The Bazaar" == parseName)
    {
      return "bazaar";
    }

  if ("The Bazaar" == parseName)
    {
      return "bazaar";
    }

  if ("Nexus" == parseName)
    {
      return "nexus";
    }

  if ("The Echo Caverns" == parseName)
    {
      return "echo";
    }

  if ("The Acrylia Caverns" == parseName)
    {
      return "acrylia";
    }

  if ("The City of Shar Vahl" == parseName)
    {
      return "sharvahl";
    }

  if ("The Paludal Caverns" == parseName)
    {
      return "paludal";
    }

  if ("The Fungus Grove" == parseName)
    {
      return "fungusgrove";
    }

  if ("Vex Thal" == parseName)
    {
      return "vexthal";
    }

  if ("Sanctus Seru" == parseName)
    {
      return "sseru";
    }

  if ("Katta Castellum" == parseName)
    {
      return "katta";
    }

  if ("Netherbian Lair" == parseName)
    {
      return "netherbian";
    }

  if ("Ssraeshza Temple" == parseName)
    {
      return "ssratemple";
    }

  if ("Grieg's End" == parseName)
    {
      return "griegsend";
    }

  if ("The Deep" == parseName)
    {
      return "thedeep";
    }

  if ("Shadeweaver's Thicket" == parseName)
    {
      return "shadeweaver";
    }

  if ("Hollowshade Moor" == parseName)
    {
      return "hollowshade";
    }

  if ("Grimling Forest" == parseName)
    {
      return "grimling";
    }

  if ("Marus Seru" == parseName)
    {
      return "mseru";
    }

  if ("Mons Letalis" == parseName)
    {
      return "letalis";
    }

  if ("The Twilight Sea" == parseName)
    {
      return "twilight";
    }

  if ("The Grey" == parseName)
    {
      return "thegrey";
    }

  if ("The Tenebrous Mountains" == parseName)
    {
      return "tenebrous";
    }

  if ("The Maiden's Eye" == parseName)
    {
      return "maiden";
    }

  if ("The Dawnshroud Peaks" == parseName)
    {
      return "dawnshroud";
    }

  if ("The Scarlet Desert" == parseName)
    {
      return "scarlet";
    }

  if ("The Umbral Plains" == parseName)
    {
      return "umbral";
    }

  if ("The Akheva Ruins" == parseName)
    {
      return "akheva";
    }

  if ("The Arena Two" == parseName)
    {
      return "arena2";
    }

  if ("The Jaggedpine Forest" == parseName)
    {
      return "jaggedpine";
    }

  if ("Nedaria's Landing" == parseName)
    {
      return "nedaria";
    }

  if ("EverQuest Tutorial" == parseName)
    {
      return "tutorial";
    }

  if ("Loading Zone" == parseName)
    {
      return "load";
    }

  if ("New Loading Zone" == parseName)
    {
      return "load2";
    }

  if ("The Plane of Hate" == parseName)
    {
      return "hateplaneb";
    }

  if ("Shadowrest" == parseName)
    {
      return "shadowrest";
    }

  if ("The Mines of Gloomingdeep" == parseName)
    {
      return "tutoriala";
    }

  if ("The Mines of Gloomingdeep" == parseName)
    {
      return "tutorialb";
    }

  if ("Loading" == parseName)
    {
      return "clz";
    }

  if ("The Crypt of Decay" == parseName)
    {
      return "codecay";
    }

  if ("The Plane of Justice" == parseName)
    {
      return "pojustice";
    }

  if ("The Plane of Knowledge" == parseName)
    {
      return "poknowledge";
    }

  if ("The Plane of Tranquility" == parseName)
    {
      return "potranquility";
    }

  if ("The Plane of Nightmares" == parseName)
    {
      return "ponightmare";
    }

  if ("The Plane of Disease" == parseName)
    {
      return "podisease";
    }

  if ("The Plane of Innovation" == parseName)
    {
      return "poinnovation";
    }

  if ("Torment, the Plane of Pain" == parseName)
    {
      return "potorment";
    }

  if ("The Plane of Valor" == parseName)
    {
      return "povalor";
    }

  if ("Bastion of Thunder" == parseName)
    {
      return "bothunder";
    }

  if ("The Plane of Storms" == parseName)
    {
      return "postorms";
    }

  if ("The Halls of Honor" == parseName)
    {
      return "hohonora";
    }

  if ("The Tower of Solusek Ro" == parseName)
    {
      return "solrotower";
    }

  if ("Plane of War" == parseName)
    {
      return "powar";
    }

  if ("Drunder, the Fortress of Zek" == parseName)
    {
      return "potactics";
    }

  if ("The Plane of Air" == parseName)
    {
      return "poair";
    }

  if ("The Plane of Water" == parseName)
    {
      return "powater";
    }

  if ("The Plane of Fire" == parseName)
    {
      return "pofire";
    }

  if ("The Plane of Earth" == parseName)
    {
      return "poeartha";
    }

  if ("The Plane of Time A" == parseName)
    {
      return "potimea";
    }

  if ("The Temple of Marr" == parseName)
    {
      return "hohonorb";
    }

  if ("The Lair of Terris Thule" == parseName)
    {
      return "nightmareb";
    }

  if ("The Plane of Earth" == parseName)
    {
      return "poearthb";
    }

  if ("The Plane of Time B" == parseName)
    {
      return "potimeb";
    }

  if ("The Gulf of Gunthak" == parseName)
    {
      return "gunthak";
    }

  if ("Dulak's Harbor" == parseName)
    {
      return "dulak";
    }

  if ("The Torgiran Mines" == parseName)
    {
      return "torgiran";
    }

  if ("The Crypt of Nadox" == parseName)
    {
      return "nadox";
    }

  if ("Hate's Fury" == parseName)
    {
      return "hatesfury";
    }

  if ("Deepest Guk: Cauldron of Lost Souls" == parseName)
    {
      return "guka";
    }

  if ("The Rujarkian Hills: Bloodied Quarries" == parseName)
    {
      return "ruja";
    }

  if ("Takish-Hiz: Sunken Library" == parseName)
    {
      return "taka";
    }

  if ("Miragul's Menagerie: Silent Gallery" == parseName)
    {
      return "mira";
    }

  if ("Mistmoore's Catacombs: Forlorn Caverns" == parseName)
    {
      return "mmca";
    }

  if ("The Drowning Crypt" == parseName)
    {
      return "gukb";
    }

  if ("The Rujarkian Hills: Halls of War" == parseName)
    {
      return "rujb";
    }

  if ("Takish-Hiz: Shifting Tower" == parseName)
    {
      return "takb";
    }

  if ("Miragul's Menagerie: Frozen Nightmare" == parseName)
    {
      return "mirb";
    }

  if ("Mistmoore's Catacombs: Dreary Grotto" == parseName)
    {
      return "mmcb";
    }

  if ("Deepest Guk: Ancient Aqueducts" == parseName)
    {
      return "gukc";
    }

  if ("The Rujarkian Hills: Wind Bridges" == parseName)
    {
      return "rujc";
    }

  if ("Takish-Hiz: Fading Temple" == parseName)
    {
      return "takc";
    }

  if ("The Spider Den" == parseName)
    {
      return "mirc";
    }

  if ("Mistmoore's Catacombs: Struggles within the Progeny" == parseName)
    {
      return "mmcc";
    }

  if ("The Mushroom Grove" == parseName)
    {
      return "gukd";
    }

  if ("The Rujarkian Hills: Prison Break" == parseName)
    {
      return "rujd";
    }

  if ("Takish-Hiz: Royal Observatory" == parseName)
    {
      return "takd";
    }

  if ("Miragul's Menagerie: Hushed Banquet" == parseName)
    {
      return "mird";
    }

  if ("Mistmoore's Catacombs: Chambers of Eternal Affliction" == parseName)
    {
      return "mmcd";
    }

  if ("Deepest Guk: The Curse Reborn" == parseName)
    {
      return "guke";
    }

  if ("The Rujarkian Hills: Drudge Hollows" == parseName)
    {
      return "ruje";
    }

  if ("Takish-Hiz: River of Recollection" == parseName)
    {
      return "take";
    }

  if ("The Frosted Halls" == parseName)
    {
      return "mire";
    }

  if ("Mistmoore's Catacombs: Sepulcher of the Damned" == parseName)
    {
      return "mmce";
    }

  if ("Deepest Guk: Chapel of the Witnesses" == parseName)
    {
      return "gukf";
    }

  if ("The Rujarkian Hills: Fortified Lair of the Taskmasters" == parseName)
    {
      return "rujf";
    }

  if ("Takish-Hiz: Sandfall Corridors" == parseName)
    {
      return "takf";
    }

  if ("The Forgotten Wastes" == parseName)
    {
      return "mirf";
    }

  if ("Mistmoore's Catacombs: Scion Lair of Fury" == parseName)
    {
      return "mmcf";
    }

  if ("The Root Garden" == parseName)
    {
      return "gukg";
    }

  if ("The Rujarkian Hills: Hidden Vale of Deceit" == parseName)
    {
      return "rujg";
    }

  if ("Takish-Hiz: Balancing Chamber" == parseName)
    {
      return "takg";
    }

  if ("Miragul's Menagerie: Heart of the Menagerie" == parseName)
    {
      return "mirg";
    }

  if ("Mistmoore's Catacombs: Cesspits of Putrescence" == parseName)
    {
      return "mmcg";
    }

  if ("Deepest Guk: Accursed Sanctuary" == parseName)
    {
      return "gukh";
    }

  if ("The Rujarkian Hills: Blazing Forge" == parseName)
    {
      return "rujh";
    }

  if ("Takish-Hiz: Sweeping Tides" == parseName)
    {
      return "takh";
    }

  if ("The Morbid Laboratory" == parseName)
    {
      return "mirh";
    }

  if ("Mistmoore's Catacombs: Aisles of Blood" == parseName)
    {
      return "mmch";
    }

  if ("The Rujarkian Hills: Arena of Chance" == parseName)
    {
      return "ruji";
    }

  if ("Takish-Hiz: Antiquated Palace" == parseName)
    {
      return "taki";
    }

  if ("The Theater of Imprisoned Horror" == parseName)
    {
      return "miri";
    }

  if ("Mistmoore's Catacombs: Halls of Sanguinary Rites" == parseName)
    {
      return "mmci";
    }

  if ("The Rujarkian Hills: Barracks of War" == parseName)
    {
      return "rujj";
    }

  if ("Takish-Hiz: Prismatic Corridors" == parseName)
    {
      return "takj";
    }

  if ("Miragul's Menagerie: Grand Library" == parseName)
    {
      return "mirj";
    }

  if ("Mistmoore's Catacombs: Infernal Sanctuary" == parseName)
    {
      return "mmcj";
    }

  if ("Chardok: The Halls of Betrayal" == parseName)
    {
      return "chardokb";
    }

  if ("The Caverns of Exile" == parseName)
    {
      return "soldungc";
    }

  if ("The Abysmal Sea" == parseName)
    {
      return "abysmal";
    }

  if ("Natimbi, the Broken Shores" == parseName)
    {
      return "natimbi";
    }

  if ("Qinimi, Court of Nihilia" == parseName)
    {
      return "qinimi";
    }

  if ("Riwwi, Coliseum of Games" == parseName)
    {
      return "riwwi";
    }

  if ("Barindu, Hanging Gardens" == parseName)
    {
      return "barindu";
    }

  if ("Ferubi, Forgotten Temple of Taelosia" == parseName)
    {
      return "ferubi";
    }

  if ("Sewers of Nihilia, Pool of Sludg" == parseName)
    {
      return "snpool";
    }

  if ("Sewers of Nihilia, Lair of Trapp" == parseName)
    {
      return "snlair";
    }

  if ("Sewers of Nihilia, Purifying Pla" == parseName)
    {
      return "snplant";
    }

  if ("Sewers of Nihilia, Emanating Cre" == parseName)
    {
      return "sncrematory";
    }

  if ("Tipt, Treacherous Crags" == parseName)
    {
      return "tipt";
    }

  if ("Vxed, the Crumbling Caverns" == parseName)
    {
      return "vxed";
    }

  if ("Yxtta, Pulpit of Exiles" == parseName)
    {
      return "yxtta";
    }

  if ("Uqua, the Ocean God Chantry" == parseName)
    {
      return "uqua";
    }

  if ("Kod'Taz, Broken Trial Grounds" == parseName)
    {
      return "kodtaz";
    }

  if ("Ikkinz, Chambers of Transcendence" == parseName)
    {
      return "ikkinz";
    }

  if ("Qvic, Prayer Grounds of Calling" == parseName)
    {
      return "qvic";
    }

  if ("Inktu'Ta, the Unmasked Chapel" == parseName)
    {
      return "inktuta";
    }

  if ("Txevu, Lair of the Elite" == parseName)
    {
      return "txevu";
    }

  if ("Tacvi, The Broken Temple" == parseName)
    {
      return "tacvi";
    }

  if ("Qvic, the Hidden Vault" == parseName)
    {
      return "qvicb";
    }

  if ("Wall of Slaughter" == parseName)
    {
      return "wallofslaughter";
    }

  if ("The Bloodfields" == parseName)
    {
      return "bloodfields";
    }

  if ("Dranik's Scar" == parseName)
    {
      return "draniksscar";
    }

  if ("Nobles' Causeway" == parseName)
    {
      return "causeway";
    }

  if ("Muramite Proving Grounds A" == parseName)
    {
      return "chambersa";
    }

  if ("Muramite Proving Grounds B" == parseName)
    {
      return "chambersb";
    }

  if ("Muramite Proving Grounds C" == parseName)
    {
      return "chambersc";
    }

  if ("Muramite Proving Grounds D" == parseName)
    {
      return "chambersd";
    }

  if ("Muramite Proving Grounds E" == parseName)
    {
      return "chamberse";
    }

  if ("Muramite Proving Grounds F" == parseName)
    {
      return "chambersf";
    }

  if ("Muramite Proving Grounds G" == parseName)
    {
      return "provinggrounds";
    }

  if ("Anguish, the Fallen Palace" == parseName)
    {
      return "anguish";
    }

  if ("Dranik's Hollows A" == parseName)
    {
      return "dranikhollowsa";
    }

  if ("Dranik's Hollows B" == parseName)
    {
      return "dranikhollowsb";
    }

  if ("Dranik's Hollows C" == parseName)
    {
      return "dranikhollowsc";
    }

  if ("Catacombs of Dranik A" == parseName)
    {
      return "dranikcatacombsa";
    }

  if ("Catacombs of Dranik B" == parseName)
    {
      return "dranikcatacombsb";
    }

  if ("Catacombs of Dranik C" == parseName)
    {
      return "dranikcatacombsc";
    }

  if ("Sewers of Dranik A" == parseName)
    {
      return "draniksewersa";
    }

  if ("Sewers of Dranik B" == parseName)
    {
      return "draniksewersb";
    }

  if ("Sewers of Dranik C" == parseName)
    {
      return "draniksewersc";
    }

  if ("Riftseekers' Sanctum" == parseName)
    {
      return "riftseekers";
    }

  if ("Harbinger's Spire" == parseName)
    {
      return "harbingers";
    }

  if ("The Ruined City of Dranik" == parseName)
    {
      return "dranik";
    }

  if ("The Broodlands" == parseName)
    {
      return "broodlands";
    }

  if ("Stillmoon Temple" == parseName)
    {
      return "stillmoona";
    }

  if ("The Ascent" == parseName)
    {
      return "stillmoonb";
    }

  if ("Thundercrest Isles" == parseName)
    {
      return "thundercrest";
    }

  if ("Lavaspinner's Lair" == parseName)
    {
      return "delvea";
    }

  if ("Tirranun's Delve" == parseName)
    {
      return "delveb";
    }

  if ("The Nest" == parseName)
    {
      return "thenest";
    }

  if ("Guild Lobby" == parseName)
    {
      return "guildlobby";
    }

  if ("Guild Hall" == parseName)
    {
      return "guildhall";
    }

  if ("The Barter Hall" == parseName)
    {
      return "barter";
    }

  if ("Ruins of Illsalin" == parseName)
    {
      return "illsalin";
    }

  if ("Illsalin Marketplace" == parseName)
    {
      return "illsalina";
    }

  if ("Temple of Korlach" == parseName)
    {
      return "illsalinb";
    }

  if ("The Nargil Pits" == parseName)
    {
      return "illsalinc";
    }

  if ("Dreadspire Keep" == parseName)
    {
      return "dreadspire";
    }

  if ("The Hive" == parseName)
    {
      return "drachnidhive";
    }

  if ("The Hatchery" == parseName)
    {
      return "drachnidhivea";
    }

  if ("The Cocoons" == parseName)
    {
      return "drachnidhiveb";
    }

  if ("Queen Sendaii`s Lair" == parseName)
    {
      return "drachnidhivec";
    }

  if ("Stoneroot Falls" == parseName)
    {
      return "westkorlach";
    }

  if ("Prince's Manor" == parseName)
    {
      return "westkorlacha";
    }

  if ("Caverns of the Lost" == parseName)
    {
      return "westkorlachb";
    }

  if ("Lair of the Korlach" == parseName)
    {
      return "westkorlachc";
    }

  if ("The Undershore" == parseName)
    {
      return "eastkorlach";
    }

  if ("Snarlstone Dens" == parseName)
    {
      return "eastkorlacha";
    }

  if ("Shadow Spine" == parseName)
    {
      return "shadowspine";
    }

  if ("Corathus Creep" == parseName)
    {
      return "corathus";
    }

  if ("Sporali Caverns" == parseName)
    {
      return "corathusa";
    }

  if ("The Corathus Mines" == parseName)
    {
      return "corathusb";
    }

  if ("Shadowed Grove" == parseName)
    {
      return "nektulosa";
    }

  if ("Arcstone, Isle of Spirits" == parseName)
    {
      return "arcstone";
    }

  if ("Relic, the Artifact City" == parseName)
    {
      return "relic";
    }

  if ("Skylance" == parseName)
    {
      return "skylance";
    }

  if ("The Devastation" == parseName)
    {
      return "devastation";
    }

  if ("The Seething Wall" == parseName)
    {
      return "devastationa";
    }

  if ("Sverag, Stronghold of Rage" == parseName)
    {
      return "rage";
    }

  if ("Razorthorn, Tower of Sullon Zek" == parseName)
    {
      return "ragea";
    }

  if ("Ruins of Takish-Hiz" == parseName)
    {
      return "takishruins";
    }

  if ("The Root of Ro" == parseName)
    {
      return "takishruinsa";
    }

  if ("The Elddar Forest" == parseName)
    {
      return "elddar";
    }

  if ("Tunare's Shrine" == parseName)
    {
      return "elddara";
    }

  if ("Theater of Blood" == parseName)
    {
      return "theater";
    }

  if ("Deathknell, Tower of Dissonance" == parseName)
    {
      return "theatera";
    }

  if ("East Freeport" == parseName)
    {
      return "freeporteast";
    }

  if ("West Freeport" == parseName)
    {
      return "freeportwest";
    }

  if ("Freeport Sewers" == parseName)
    {
      return "freeportsewers";
    }

  if ("Academy of Arcane Sciences" == parseName)
    {
      return "freeportacademy";
    }

  if ("Temple of Marr" == parseName)
    {
      return "freeporttemple";
    }

  if ("Freeport Militia House: My Precious" == parseName)
    {
      return "freeportmilitia";
    }

  if ("Arena" == parseName)
    {
      return "freeportarena";
    }

  if ("City Hall" == parseName)
    {
      return "freeportcityhall";
    }

  if ("Theater of the Tranquil" == parseName)
    {
      return "freeporttheater";
    }

  if ("Hall of Truth: Bounty" == parseName)
    {
      return "freeporthall";
    }

  if ("North Desert of Ro" == parseName)
    {
      return "northro";
    }

  if ("South Desert of Ro" == parseName)
    {
      return "southro";
    }

  if ("Crescent Reach" == parseName)
    {
      return "crescent";
    }

  if ("Blightfire Moors" == parseName)
    {
      return "moors";
    }

  if ("Stone Hive" == parseName)
    {
      return "stonehive";
    }

  if ("Goru`kar Mesa" == parseName)
    {
      return "mesa";
    }

  if ("Blackfeather Roost" == parseName)
    {
      return "roost";
    }

  if ("The Steppes" == parseName)
    {
      return "steppes";
    }

  if ("Icefall Glacier" == parseName)
    {
      return "icefall";
    }

  if ("Valdeholm" == parseName)
    {
      return "valdeholm";
    }

  if ("Frostcrypt, Throne of the Shade King" == parseName)
    {
      return "frostcrypt";
    }

  if ("Sunderock Springs" == parseName)
    {
      return "sunderock";
    }

  if ("Vergalid Mines" == parseName)
    {
      return "vergalid";
    }

  if ("Direwind Cliffs" == parseName)
    {
      return "direwind";
    }

  if ("Ashengate, Reliquary of the Scale" == parseName)
    {
      return "ashengate";
    }

  if ("Highpass Hold" == parseName)
    {
      return "highpasshold";
    }

  if ("The Commonlands" == parseName)
    {
      return "commonlands";
    }

  if ("The Ocean of Tears" == parseName)
    {
      return "oceanoftears";
    }

  if ("Kithicor Forest" == parseName)
    {
      return "kithforest";
    }

  if ("Befallen" == parseName)
    {
      return "befallenb";
    }

  if ("HighKeep" == parseName)
    {
      return "highpasskeep";
    }

  if ("The Innothule Swamp" == parseName)
    {
      return "innothuleb";
    }

  if ("Toxxulia Forest" == parseName)
    {
      return "toxxulia";
    }

  if ("The Misty Thicket" == parseName)
    {
      return "mistythicket";
    }

  if ("Katta Castrum" == parseName)
    {
      return "kattacastrum";
    }

  if ("Thalassius, the Coral Keep" == parseName)
    {
      return "thalassius";
    }

  if ("Jewel of Atiiki" == parseName)
    {
      return "atiiki";
    }

  if ("Zhisza, the Shissar Sanctuary" == parseName)
    {
      return "zhisza";
    }

  if ("Silyssar, New Chelsith" == parseName)
    {
      return "silyssar";
    }

  if ("Solteris, the Throne of Ro" == parseName)
    {
      return "solteris";
    }

  if ("Barren Coast" == parseName)
    {
      return "barren";
    }

  if ("The Buried Sea" == parseName)
    {
      return "buriedsea";
    }

  if ("Jardel's Hook" == parseName)
    {
      return "jardelshook";
    }

  if ("Monkey Rock" == parseName)
    {
      return "monkeyrock";
    }

  if ("Suncrest Isle" == parseName)
    {
      return "suncrest";
    }

  if ("Deadbone Reef" == parseName)
    {
      return "deadbone";
    }

  if ("Blacksail Folly" == parseName)
    {
      return "blacksail";
    }

  if ("Maiden's Grave" == parseName)
    {
      return "maidensgrave";
    }

  if ("Redfeather Isle" == parseName)
    {
      return "redfeather";
    }

  if ("The Open Sea" == parseName)
    {
      return "shipmvp";
    }

  if ("The Open Sea" == parseName)
    {
      return "shipmvu";
    }

  if ("The Open Sea" == parseName)
    {
      return "shippvu";
    }

  if ("The Open Sea" == parseName)
    {
      return "shipuvu";
    }

  if ("The Open Sea" == parseName)
    {
      return "shipmvm";
    }

  if ("Fortress Mechanotus" == parseName)
    {
      return "mechanotus";
    }

  if ("Meldrath's Majestic Mansion" == parseName)
    {
      return "mansion";
    }

  if ("The Steam Factory" == parseName)
    {
      return "steamfactory";
    }

  if ("S.H.I.P. Workshop" == parseName)
    {
      return "shipworkshop";
    }

  if ("Gyrospire Beza" == parseName)
    {
      return "gyrospireb";
    }

  if ("Gyrospire Zeka" == parseName)
    {
      return "gyrospirez";
    }

  if ("Dragonscale Hills" == parseName)
    {
      return "dragonscale";
    }

  if ("Loping Plains" == parseName)
    {
      return "lopingplains";
    }

  if ("Hills of Shade" == parseName)
    {
      return "hillsofshade";
    }

  if ("Bloodmoon Keep" == parseName)
    {
      return "bloodmoon";
    }

  if ("Crystallos, Lair of the Awakened" == parseName)
    {
      return "crystallos";
    }

  if ("The Mechamatic Guardian" == parseName)
    {
      return "guardian";
    }

  if ("The Steamfont Mountains" == parseName)
    {
      return "steamfontmts";
    }

  if ("Crypt of Shade" == parseName)
    {
      return "cryptofshade";
    }

  if ("Deepscar's Den" == parseName)
    {
      return "dragonscaleb";
    }

  if ("Field of Scale" == parseName)
    {
      return "oldfieldofbone";
    }

  if ("Kaesora Library" == parseName)
    {
      return "oldkaesoraa";
    }

  if ("Kaesora Hatchery" == parseName)
    {
      return "oldkaesorab";
    }

  if ("Kurn's Tower" == parseName)
    {
      return "oldkurn";
    }

  if ("Bloody Kithicor" == parseName)
    {
      return "oldkithicor";
    }

  if ("Old Commonlands" == parseName)
    {
      return "oldcommons";
    }

  if ("Highpass Hold" == parseName)
    {
      return "oldhighpass";
    }

  if ("The Void A" == parseName)
    {
      return "thevoida";
    }

  if ("The Void B" == parseName)
    {
      return "thevoidb";
    }

  if ("The Void C" == parseName)
    {
      return "thevoidc";
    }

  if ("The Void D" == parseName)
    {
      return "thevoidd";
    }

  if ("The Void E" == parseName)
    {
      return "thevoide";
    }

  if ("The Void F" == parseName)
    {
      return "thevoidf";
    }

  if ("The Void G" == parseName)
    {
      return "thevoidg";
    }

  if ("Oceangreen Hills" == parseName)
    {
      return "oceangreenhills";
    }

  if ("Oceangreen Village" == parseName)
    {
      return "oceangreenvillage";
    }

  if ("BlackBurrow" == parseName)
    {
      return "oldblackburrow";
    }

  if ("Temple of Bertoxxulous" == parseName)
    {
      return "bertoxtemple";
    }

  if ("Korafax, Home of the Riders" == parseName)
    {
      return "discord";
    }

  if ("Citadel of the Worldslayer" == parseName)
    {
      return "discordtower";
    }

  if ("Old Bloodfields" == parseName)
    {
      return "oldbloodfield";
    }

  if ("The Precipice of War" == parseName)
    {
      return "precipiceofwar";
    }

  if ("City of Dranik" == parseName)
    {
      return "olddranik";
    }

  if ("Toskirakk" == parseName)
    {
      return "toskirakk";
    }

  if ("Korascian Warrens" == parseName)
    {
      return "korascian";
    }

  if ("Rathe Council Chamber" == parseName)
    {
      return "rathechamber";
    }

  if ("Brell's Rest" == parseName)
    {
      return "brellsrest";
    }

  if ("Fungal Forest" == parseName)
    {
      return "fungalforest";
    }

  if ("The Underquarry" == parseName)
    {
      return "underquarry";
    }

  if ("The Cooling Chamber" == parseName)
    {
      return "coolingchamber";
    }

  if ("Kernagir, the Shining City" == parseName)
    {
      return "shiningcity";
    }

  if ("Arthicrex" == parseName)
    {
      return "arthicrex";
    }

  if ("The Foundation" == parseName)
    {
      return "foundation";
    }

  if ("Lichen Creep" == parseName)
    {
      return "lichencreep";
    }

  if ("Pellucid Grotto" == parseName)
    {
      return "pellucid";
    }

  if ("Volska's Husk" == parseName)
    {
      return "stonesnake";
    }

  if ("Brell's Temple" == parseName)
    {
      return "brellstemple";
    }

  if ("The Convorteum" == parseName)
    {
      return "convorteum";
    }

  if ("Brell's Arena" == parseName)
    {
      return "brellsarena";
    }

  if ("Wedding Chapel" == parseName)
    {
      return "weddingchapel";
    }

  if ("Wedding Chapel" == parseName)
    {
      return "weddingchapeldark";
    }

  if ("Lair of the Risen" == parseName)
    {
      return "dragoncrypt";
    }

  if ("The Feerrott" == parseName)
    {
      return "feerrott2";
    }

  if ("House of Thule" == parseName)
    {
      return "thulehouse1";
    }

  if ("House of Thule, Upper Floors" == parseName)
    {
      return "thulehouse2";
    }

  if ("The Grounds" == parseName)
    {
      return "housegarden";
    }

  if ("The Library" == parseName)
    {
      return "thulelibrary";
    }

  if ("The Well" == parseName)
    {
      return "well";
    }

  if ("Erudin Burning" == parseName)
    {
      return "fallen";
    }

  if ("Morell's Castle" == parseName)
    {
      return "morellcastle";
    }

  if ("Sanctum Somnium" == parseName)
    {
      return "somnium";
    }

  if ("Al'Kabor's Nightmare" == parseName)
    {
      return "alkabormare";
    }

  if ("Miragul's Nightmare" == parseName)
    {
      return "miragulmare";
    }

  if ("Fear Itself" == parseName)
    {
      return "thuledream";
    }

  if ("Sunrise Hills" == parseName)
    {
      return "neighborhood";
    }

  if ("Argath, Bastion of Illdaera" == parseName)
    {
      return "argath";
    }

  if ("Valley of Lunanyn" == parseName)
    {
      return "arelis";
    }

  if ("Sarith, City of Tides" == parseName)
    {
      return "sarithcity";
    }

  if ("Rubak Oseka, Temple of the Sea" == parseName)
    {
      return "rubak";
    }

  if ("Beasts' Domain" == parseName)
    {
      return "beastdomain";
    }

  if ("The Resplendent Temple" == parseName)
    {
      return "resplendent";
    }

  if ("Pillars of Alra" == parseName)
    {
      return "pillarsalra";
    }

  if ("Windsong Sanctuary" == parseName)
    {
      return "windsong";
    }

  if ("Erillion, City of Bronze" == parseName)
    {
      return "cityofbronze";
    }

  if ("Sepulcher of Order" == parseName)
    {
      return "sepulcher";
    }

  if ("Sepulcher East" == parseName)
    {
      return "eastsepulcher";
    }

  if ("Sepulcher West" == parseName)
    {
      return "westsepulcher";
    }

  if ("Shard's Landing" == parseName)
    {
      return "shardslanding";
    }

  if ("Valley of King Xorbb" == parseName)
    {
      return "xorbb";
    }

  if ("Kael Drakkel: The King's Madness" == parseName)
    {
      return "kaelshard";
    }

  if ("East Wastes: Zeixshi-Kar's Awakening" == parseName)
    {
      return "eastwastesshard";
    }

  if ("The Crystal Caverns: Fragment of Fear" == parseName)
    {
      return "crystalshard";
    }

  if ("The Breeding Grounds" == parseName)
    {
      return "breedinggrounds";
    }

  if ("Evantil, the Vile Oak" == parseName)
    {
      return "eviltree";
    }

  if ("Grelleth's Palace, the Chateau of Filth" == parseName)
    {
      return "grelleth";
    }

  if ("Chapterhouse of the Fallen" == parseName)
    {
      return "chapterhouse";
    }

  if ("Art Testing Domain" == parseName)
    {
      return "arttest";
    }

  if ("The Forgotten Halls" == parseName)
    {
      return "fhalls";
    }

  if ("Designer Apprentice" == parseName)
    {
      return "apprentice";
    }

  return "";
}

#endif
