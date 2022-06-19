LumiourLab_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LumiourLab_OnWarp
	.byte 0

LumiourLab_OnWarp:
	map_script_2 VAR_TEMP_1, 0, LumiourLab_EventScript_StartCutscene
	.2byte 0

LumiourLab_EventScript_StartCutscene::
	setflag FLAG_SYS_B_DASH
	end

LumiourLab_EventScript_InstantRevitalizingDevice::
	msgbox LumiourIslandLab_Text_InstantRevitalizingDevice, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, LumiourLab_EventScript_Cancel
	case YES, LumiourLab_EventScript_HealPokemon
	case MULTI_B_PRESSED, LumiourLab_EventScript_Cancel
	end

LumiourLab_EventScript_HealPokemon:
	closemessage
	fadescreen 1
	playfanfare MUS_HEAL
	special HealPlayerParty
	waitfanfare
	fadescreen 0
	release
	end

LumiourLab_EventScript_Cancel:
	closemessage
	release
	end

LumiourIslandLab_Text_InstantRevitalizingDevice:
	.string "In only a second the Instant Revitalizing\n"
	.string "Device fully revitalizes your Pokemon.\p"
	.string "Use the Instant Revitalizing Device?$"

LumiourLab_EventScript_HoopaReport::
	msgbox LumiourIslandLab_Text_HoopaReport, MSGBOX_SIGN
	end

LumiourIslandLab_Text_HoopaReport:
	.string "It's a lab report on the Pokemon Hoopa.\p"
	.string "Hoopa has been known to transport\n"
	.string "particular pieces of land through\l"
	.string "interdimensional portals.\p"
	.string "Its said to have a keen affinity\n"
	.string "for transporting Islands, as recorded\l"
	.string "during its sightings in the Hoenn Region.$"

LumiourLab_EventScript_NecrozmaReport::
	msgbox LumiourIslandLab_Text_NecrozmaReport, MSGBOX_SIGN
	end

LumiourIslandLab_Text_NecrozmaReport:
	.string "It's a lab report on the Pokemon\n"
	.string "Necrozma.\p"
	.string "Necrozma is capable of opening and\n"
	.string "traveling through Ultra Wormholes.\p"
	.string "Its appearance in the Alola Region along\n"
	.string "with the interference of the Aether\l"
	.string "Foundation released the Pokemon\l"
	.string "known as Ultra Beasts into\l"
	.string "the world.$"

LumiourLab_EventScript_PalkiaWebpage::
	msgbox LumiourIslandLab_Text_PalkiaWebpage, MSGBOX_SIGN
	end

LumiourIslandLab_Text_PalkiaWebpage:
	.string "It's a web page about the Pokemon\n"
	.string "Palkia.\p"
	.string "Palkia, ruler of time is part of the\n"
	.string "Creation Trio with Dialga and Giratina.\p"
	.string "Ancient Sinnoh writings tell of early\n"
	.string "civilizations at odds with eachother\l"
	.string "over the existence of these Pokemon.\p"
	.string "That was until anomolies in the flow of\n"
	.string "space-time led to both their discoveries.$"

LumiourLab_EventScript_GroudonWebpage::
	msgbox LumiourIslandLab_Text_GroudonWebpage, MSGBOX_SIGN
	end

LumiourIslandLab_Text_GroudonWebpage:
	.string "It's a web page about the Pokemon\n"
	.string "Groudon.\p"
	.string "Studies from the Hoenn Weather Institute\n"
	.string "claim Groudon has the ability to shape\l"
	.string "bodies of land at will.\p"
	.string "Its presence can be forewarned by the\n"
	.string "intense sunlight it summons.$"

LumiourLab_EventScript_InternetForum::
	msgbox LumiourIslandLab_Text_InternetForum, MSGBOX_SIGN
	end

LumiourIslandLab_Text_InternetForum:
	.string "It's a web forum about the recent cases\n"
	.string "of Mirage Islands\p"
	.string "It appears to just be incoherent\n"
	.string "theorizing.$"

LumiourLab_EventScript_TV::
	goto_if_eq VAR_LUMIOUR_ISLAND_STATE, 1, LumiourIslandLab_EventScript_TVMemorialPillar
	goto_if_eq VAR_LUMIOUR_ISLAND_STATE, 2, LumiourIslandLab_EventScript_TVWhirlIsland
	goto_if_eq VAR_LUMIOUR_ISLAND_STATE, 3, LumiourIslandLab_EventScript_TVMirageIsland
	goto_if_eq VAR_LUMIOUR_ISLAND_STATE, 4, LumiourIslandLab_EventScript_TVIronIsland
	goto_if_eq VAR_LUMIOUR_ISLAND_STATE, 5, LumiourIslandLab_EventScript_TVLibertyIsland
	end

LumiourIslandLab_EventScript_TVMemorialPillar::
	msgbox LumiourIslandLab_Text_TVMemorialPillar, MSGBOX_SIGN
	end

LumiourIslandLab_EventScript_TVWhirlIsland::
	msgbox LumiourIslandLab_Text_TVWhirlIsland, MSGBOX_SIGN
	end

LumiourIslandLab_EventScript_TVMirageIsland::
	msgbox LumiourIslandLab_Text_TVMirageIsland, MSGBOX_SIGN
	end

LumiourIslandLab_EventScript_TVIronIsland::
	msgbox LumiourIslandLab_Text_TVIronIsland, MSGBOX_SIGN
	end

LumiourIslandLab_EventScript_TVLibertyIsland::
	msgbox LumiourIslandLab_Text_TVLibertyIsland, MSGBOX_SIGN
	end

LumiourIslandLab_Text_TVMemorialPillar:
	.string "The TV is set to a news channel.\p"
	.string "News Anchor: Reports of Mirage Islands\n"
	.string "across multiple regions continue\l"
	.string "with claims of Memorial Pillar,\l"
	.string "a small monument off the coast of\l"
	.string "Five Island being the next target.\p"
	.string "The Island's whereabouts are currently\n"
	.string "unknown.$"

LumiourIslandLab_Text_TVWhirlIsland:
	.string "The TV is set to a news channel.\p"
	.string "News Anchor: Reports of Mirage Islands\n"
	.string "continue yet again.\p"
	.string "The Johto Region's Whirl Islands\n"
	.string "have reportedly had multiple pieces\l"
	.string "of land dissapear and reappear\l"
	.string "throughout the night.$"

LumiourIslandLab_Text_TVMirageIsland:
	.string "The TV is set to a news channel.\p"
	.string "News Anchor: A Mirage Island has\n"
	.string "been identified near Pacifidlog Town\l"
	.string "in the Hoenn Region.\p"
	.string "A local trainer managed to travel to\n"
	.string "the island and discovered a never\l"
	.string "before seen Enigma Berry.\p"
	.string "Effects of the berry are being\n"
	.string "studied at the Birch Pokemon Lab.\p"
	.string "Trainers are advised to not use\n"
	.string "any untagged berries.$"

LumiourIslandLab_Text_TVIronIsland:
	.string "The TV is set to a news channel.\p"
	.string "News Anchor: A small section of\n"
	.string "Sinnoh's Iron Island has dissapeared.\p"
	.string "Workers at the mine are unharmed\n"
	.string "however the sudden dissapearance of\l"
	.string "the land has flooded the island,\l"
	.string "rendering the mine inaccessable.$"

LumiourIslandLab_Text_TVLibertyIsland:
	.string "The TV is set to a news channel.\p"
	.string "News Anchor: Radio connection to\n"
	.string "a boat traveling from Castelia City\l"
	.string "To Liberty Island in the Unova\l"
	.string "Region has been lost.\p"
	.string "Travel logs say approximately 11\n"
	.string "people where on the boat.\p"
	.string "Their names and location are\n"
	.string "currently unknown...$"

LumiourLab_EventScript_SetVar::
	lock
	faceplayer
	addvar VAR_LUMIOUR_ISLAND_STATE, 1
	msgbox LumiourIslandLab_Text_AddVar, MSGBOX_DEFAULT
	release
	end

LumiourIslandLab_Text_AddVar:
	.string "added 1 to island state var$"
