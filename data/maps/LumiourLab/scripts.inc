.set LOCALID_PROF_CYGNUS, 1

LumiourLab_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LumiourLab_OnWarp
	map_script MAP_SCRIPT_ON_TRANSITION, LumiourLab_OnTransition
	.byte 0

LumiourLab_OnTransition:
	call LumiourLab_EventScript_SetCygnusMoveType
	end

LumiourLab_OnWarp:
	map_script_2 VAR_INTRO_STATE, 0, LumiourLab_EventScript_SetRun
	map_script_2 VAR_INTRO_STATE, 1, LumiourLab_EventScript_SetCygnusLocation 
	.2byte 0

LumiourLab_EventScript_SetCygnusLocation:
	setobjectxy LOCALID_PROF_CYGNUS, 6, 5

LumiourLab_EventScript_SetCygnusMoveType::
	setobjectmovementtype LOCALID_PROF_CYGNUS, MOVEMENT_TYPE_FACE_RIGHT
	return


LumiourLab_EventScript_SetRun::
	setflag FLAG_SYS_B_DASH
	hideobjectat LOCALID_PROF_CYGNUS, MAP_LUMIOUR_LAB
	return

LumiourLab_Trigger_ProfCygnus1::
	setvar VAR_TEMP_1, 1
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	goto LumiourIslandLab_EventScript_CygnusIntro
	end

LumiourLab_Trigger_ProfCygnus2::
	setvar VAR_TEMP_1, 2
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	goto LumiourIslandLab_EventScript_CygnusIntro
	end

LumiourLab_Trigger_ProfCygnus3::
	setvar VAR_TEMP_1, 3
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	goto LumiourIslandLab_EventScript_CygnusIntro
	end

LumiourIslandLab_EventScript_CygnusIntro::
	lock
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	waitse
	delay 48
	playse SE_DOOR
	showobjectat LOCALID_PROF_CYGNUS, MAP_LUMIOUR_LAB
	applymovement LOCALID_PROF_CYGNUS, LumiourLab_Movement_ProfCygnusEnter
	waitmovement 0
	waitse
	msgbox LumiourLab_Text_ProfCygnus, MSGBOX_DEFAULT
	closemessage
	compare VAR_TEMP_1, 2
	goto_if_lt LumiourLab_EventScript_East
	goto_if_eq LumiourLab_EventScript_South
	goto_if_gt LumiourLab_EventScript_West
	end

LumiourLab_EventScript_South::
	applymovement LOCALID_PROF_CYGNUS, LumiourLab_Movement_ProfCygnusFollowMeSouth
	applymovement OBJ_EVENT_ID_PLAYER, LumiourLab_Movement_PlayerSouth
	waitmovement 0
	goto LumiourLab_EventScript_ExplainFossil
	end

LumiourLab_EventScript_East::
	applymovement LOCALID_PROF_CYGNUS, LumiourLab_Movement_ProfCygnusFollowMe
	applymovement OBJ_EVENT_ID_PLAYER, LumiourLab_Movement_PlayerEast
	waitmovement 0
	goto LumiourLab_EventScript_ExplainFossil
	end

LumiourLab_EventScript_West::
	applymovement LOCALID_PROF_CYGNUS, LumiourLab_Movement_ProfCygnusFollowMe
	applymovement OBJ_EVENT_ID_PLAYER, LumiourLab_Movement_PlayerWest
	waitmovement 0
	goto LumiourLab_EventScript_ExplainFossil
	end

LumiourLab_Movement_ProfCygnusFollowMeSouth:
	walk_right
	walk_up
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	face_right
	step_end

LumiourLab_Movement_ProfCygnusFollowMe:
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	face_right
	step_end

LumiourLab_Movement_PlayerSouth:
	delay_16
	delay_16
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	face_left
	step_end


LumiourLab_Movement_PlayerWest:
	walk_left
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	step_end
	
LumiourLab_Movement_PlayerEast:
	walk_right
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	step_end

LumiourLab_Movement_ProfCygnusEnter:
	walk_in_place_up
	face_player
	step_end

LumiourLab_Text_ProfCygnus:
	.string "{COLOR BLUE}Professor Cygnus: Oh {PLAYER}!\p"
	.string "I found something for you.\p"
	.string "If you're going to help study this island\n"
	.string "you're going to need a Pokémon!\p"
	.string "But I can't really show you right now…\p"
	.string "Follow me. I'll explain!$"

LumiourLab_EventScript_ExplainFossil:
	msgbox LumiourLab_Text_FoundFossil, MSGBOX_DEFAULT
	applymovement LOCALID_PROF_CYGNUS, Common_Movement_FaceUp
	playse SE_VEND
	waitmovement 1
	waitse
	msgbox LumiourLab_Text_UsingMachine, MSGBOX_DEFAULT
	applymovement LOCALID_PROF_CYGNUS, Common_Movement_FaceRight
	msgbox LumiourLab_Text_DumbJoke, MSGBOX_DEFAULT
	closemessage
	playse SE_DING_DONG
	waitse
	applymovement LOCALID_PROF_CYGNUS, Common_Movement_FaceUp
	waitmovement 1
	msgbox LumiourLab_Text_FossilDone, MSGBOX_DEFAULT
	applymovement LOCALID_PROF_CYGNUS, Common_Movement_FaceRight
	msgbox LumiourLab_Text_GetStarter, MSGBOX_DEFAULT
	setflag FLAG_SYS_POKEMON_GET
	givemon SPECIES_AERODACTYL, 25, ITEM_NONE
	playfanfare MUS_OBTAIN_ITEM
	bufferleadmonspeciesname 0
	msgbox LumiourLab_Text_RecievedAerodactyl, MSGBOX_DEFAULT
	waitfanfare
	msgbox LumiourLab_Text_NicknameAerodactyl, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LumiourLab_EventScript_ExplainFossilMachine
	call Common_EventScript_NameReceivedPartyMon
	goto LumiourLab_EventScript_ExplainFossilMachine
	end

LumiourLab_EventScript_ExplainFossilMachine::
	msgbox LumiourLab_Text_ExplainFossilMachine, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PROF_CYGNUS, LumiourLab_Movement_CygnusMoveDown
	waitmovement 1
	setvar VAR_INTRO_STATE, 1
	release
	end

LumiourLab_Movement_CygnusMoveDown:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	face_right
	step_end

LumiourLab_Text_ExplainFossilMachine:
	.string "{COLOR BLUE}If you ever find a fossil you can revive \n"
	.string "it here anytime.\p"
	.string "And if you need to heal your Pokémon use\n"
	.string "the machine behind you.\p"
	.string "Well, I'd say its about time you get to\n"
	.string "know and explore Lumiour Island!\p"
	.string "Nothing too unusual should happen yet…\p"
	.string "I've had enough of the outdoors today.\n"
	.string "I'm gonna stay inside where its safe.$"

LumiourLab_Text_NicknameAerodactyl:
	.string "{COLOR BLUE}Professor Cygnus: I know!\p"
	.string "You should nickname Aerodactyl!$"

LumiourLab_Text_RecievedAerodactyl:
	.string "{PLAYER} recieved Aerodactyl!$"

LumiourLab_Text_GetStarter:
	.string "{COLOR BLUE}I knew you would be needing a very\n"
	.string "powerful Pokémon.\p"
	.string "One that will be able to protect you from\n"
	.string "any unknown danger.$"

LumiourLab_Text_FossilDone:
	.string "{COLOR BLUE}Oh! Done already.$"

LumiourLab_Text_FoundFossil:
	.string "{COLOR BLUE}Professor Cygnus: I was correct!\p"
	.string "Viscera Cave did have a Pokémon\n"
	.string "fossil hidden inside!\p"
	.string "All we need to do is revive it!$"

LumiourLab_Text_UsingMachine:
	.string "{COLOR BLUE}Okay…\n"
	.string "So how do I use this thing again?\p"
	.string "Ah there we go!$"

LumiourLab_Text_DumbJoke:
	.string "{COLOR BLUE}I havn't used one of these since\n"
	.string "college.\p"
	.string "Now we just let it do its thing and\n"
	.string "before you know it you'll have yourself\l"
	.string "a brand new Pokémon.\p"
	.string "Or I guess you could say its a brand 'old'\n"
	.string "Pokémon!$"

LumiourLab_EventScript_InstantRevitalizingDevice::
	goto_if_unset FLAG_SYS_POKEMON_GET, LumiourLab_EventScript_DontTouch
	msgbox LumiourIslandLab_Text_InstantRevitalizingDevice, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, LumiourLab_EventScript_Cancel
	case YES, LumiourLab_EventScript_HealPokemon
	case MULTI_B_PRESSED, LumiourLab_EventScript_Cancel
	end

LumiourLab_EventScript_FossilMachine::
	goto_if_unset FLAG_SYS_POKEMON_GET, LumiourLab_EventScript_DontTouchFossilMachine
	end

LumiourLab_EventScript_DontTouchFossilMachine::
	lock
	faceplayer
	msgbox LumiourLab_Text_DontTouchFossilMachine, MSGBOX_DEFAULT
	release
	end

LumiourLab_Text_DontTouchFossilMachine:
	.string "It's a device for reviving fossils.\p"
	.string "Better leave it alone for now…$"

LumiourLab_EventScript_DontTouch::
	lock
	faceplayer
	msgbox LumiourLab_Text_DontTouch, MSGBOX_DEFAULT
	release
	end

LumiourLab_Text_DontTouch:
	.string "It's a device for healing Pokémon.\p"
	.string "Better leave it alone for now…$"

LumiourLab_EventScript_HealPokemon::
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
	.string "Device fully revitalizes your Pokémon.\p"
	.string "Use the Instant Revitalizing Device?$"

LumiourLab_EventScript_HoopaReport::
	msgbox LumiourIslandLab_Text_HoopaReport, MSGBOX_SIGN
	end

LumiourIslandLab_Text_HoopaReport:
	.string "It's a lab report on the Pokémon Hoopa.\p"
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
	.string "It's a lab report on the Pokémon\n"
	.string "Necrozma.\p"
	.string "Necrozma is capable of opening and\n"
	.string "traveling through Ultra Wormholes.\p"
	.string "Its appearance in the Alola Region along\n"
	.string "with the interference of the Aether\l"
	.string "Foundation released the Pokémon\l"
	.string "known as Ultra Beasts into the world.$"

LumiourLab_EventScript_PalkiaWebpage::
	msgbox LumiourIslandLab_Text_PalkiaWebpage, MSGBOX_SIGN
	end

LumiourIslandLab_Text_PalkiaWebpage:
	.string "It's a web page about the Pokémon\n"
	.string "Palkia.\p"
	.string "Palkia, ruler of time is part of the\n"
	.string "Creation Trio with Dialga and Giratina.\p"
	.string "Ancient Sinnoh writings tell of early\n"
	.string "civilizations at odds with eachother\l"
	.string "over the existence of these Pokémon.\p"
	.string "That was until anomolies in the flow of\n"
	.string "space-time led to both their discoveries.$"

LumiourLab_EventScript_GroudonWebpage::
	msgbox LumiourIslandLab_Text_GroudonWebpage, MSGBOX_SIGN
	end

LumiourIslandLab_Text_GroudonWebpage:
	.string "It's a web page about the Pokémon\n"
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
	goto_if_unset FLAG_SYS_POKEMON_GET, LumiourIslandLab_EventScript_TVCommercial
	goto_if_eq VAR_LUMIOUR_ISLAND_STATE, 1, LumiourIslandLab_EventScript_TVMemorialPillar
	goto_if_eq VAR_LUMIOUR_ISLAND_STATE, 2, LumiourIslandLab_EventScript_TVWhirlIsland
	goto_if_eq VAR_LUMIOUR_ISLAND_STATE, 3, LumiourIslandLab_EventScript_TVMirageIsland
	goto_if_eq VAR_LUMIOUR_ISLAND_STATE, 4, LumiourIslandLab_EventScript_TVIronIsland
	goto_if_eq VAR_LUMIOUR_ISLAND_STATE, 5, LumiourIslandLab_EventScript_TVLibertyIsland
	goto_if_eq VAR_LUMIOUR_ISLAND_STATE, 6, LumiourIslandLab_EventScript_TVUndergroundSinnoh
	end

LumiourIslandLab_EventScript_TVCommercial::
	msgbox LumiourIslandLab_Text_Commercial, MSGBOX_SIGN
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

LumiourIslandLab_EventScript_TVUndergroundSinnoh::
	msgbox LumiourIslandLab_Text_TVUnderGroundSinnoh, MSGBOX_SIGN
	end

LumiourIslandLab_Text_Commercial:
	.string "Its on commercial break…$"

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
	.string "studied at the Birch Pokémon Lab.\p"
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

LumiourIslandLab_Text_TVUnderGroundSinnoh:
	.string "The TV is set to a news channel.\p"
	.string "News Anchor: A portion of Sinnoh's\n"
	.string "Underground has caved in.\p"
	.string "Expert explorers are currently\n"
	.string "working to rescue the last few\l"
	.string "trainers trapped inside.$"

LumiourLab_EventScript_SetVar::
	lock
	faceplayer
	addvar VAR_LUMIOUR_ISLAND_STATE, 1
	msgbox LumiourIslandLab_Text_AddVar, MSGBOX_DEFAULT
	release
	end

LumiourIslandLab_Text_AddVar:
	.string "added 1 to island state var$"
