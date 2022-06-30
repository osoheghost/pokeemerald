.set LOCALID_PROF_CYGNUS, 1

LumiourLab_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LumiourLab_OnWarp
	map_script MAP_SCRIPT_ON_TRANSITION, LumiourLab_OnTransition
	.byte 0

LumiourLab_OnTransition:
	call LumiourLab_EventScript_SetCygnusLocation
	end

LumiourLab_OnWarp:
	map_script_2 VAR_INTRO_STATE, 0, LumiourLab_EventScript_SetRun
	map_script_2 VAR_LUMIOUR_ISLAND_STATE, 0 LumiourIsland_EventScript_SetCygnusDirection0
	map_script_2 VAR_LUMIOUR_ISLAND_STATE, 1 LumiourIsland_EventScript_SetCygnusDirection1
	map_script_2 VAR_LUMIOUR_ISLAND_STATE, 2 LumiourIsland_EventScript_SetCygnusDirection2
	map_script_2 VAR_LUMIOUR_ISLAND_STATE, 3 LumiourIsland_EventScript_SetCygnusDirection3
	map_script_2 VAR_LUMIOUR_ISLAND_STATE, 4 LumiourIsland_EventScript_SetCygnusDirection4
	map_script_2 VAR_LUMIOUR_ISLAND_STATE, 5 LumiourIsland_EventScript_SetCygnusDirection5
	map_script_2 VAR_LUMIOUR_ISLAND_STATE, 6 LumiourIsland_EventScript_SetCygnusDirection6
	.2byte 0

LumiourIsland_EventScript_SetCygnusDirection0:
	applymovement LOCALID_PROF_CYGNUS Common_Movement_FaceRight
	return
	end

LumiourIsland_EventScript_SetCygnusDirection1:
	applymovement LOCALID_PROF_CYGNUS Common_Movement_FaceUp
	return
	end

LumiourIsland_EventScript_SetCygnusDirection2:
	applymovement LOCALID_PROF_CYGNUS Common_Movement_FaceDown
	return
	end

LumiourIsland_EventScript_SetCygnusDirection3:
	applymovement LOCALID_PROF_CYGNUS Common_Movement_FaceUp
	return
	end

LumiourIsland_EventScript_SetCygnusDirection4:
	applymovement LOCALID_PROF_CYGNUS Common_Movement_FaceLeft
	return
	end

LumiourIsland_EventScript_SetCygnusDirection5:
	applymovement LOCALID_PROF_CYGNUS Common_Movement_FaceRight
	return
	end

LumiourIsland_EventScript_SetCygnusDirection6:
	applymovement LOCALID_PROF_CYGNUS Common_Movement_FaceLeft
	return
	end

LumiourLab_EventScript_SetCygnusLocation:
	goto_if_unset FLAG_SYS_POKEMON_GET, LumiourIsland_EventScript_SetCygnusLocation0
	goto_if_eq VAR_LUMIOUR_ISLAND_STATE, 0, LumiourIsland_EventScript_SetCygnusLocationPostIntro
	goto_if_eq VAR_LUMIOUR_ISLAND_STATE, 1, LumiourIsland_EventScript_SetCygnusLocation1
	goto_if_eq VAR_LUMIOUR_ISLAND_STATE, 2, LumiourIsland_EventScript_SetCygnusLocation2
	goto_if_eq VAR_LUMIOUR_ISLAND_STATE, 3, LumiourIsland_EventScript_SetCygnusLocation3
	goto_if_eq VAR_LUMIOUR_ISLAND_STATE, 4, LumiourIsland_EventScript_SetCygnusLocation4
	goto_if_eq VAR_LUMIOUR_ISLAND_STATE, 5, LumiourIsland_EventScript_SetCygnusLocation5
	goto_if_eq VAR_LUMIOUR_ISLAND_STATE, 6, LumiourIsland_EventScript_SetCygnusLocation6
	end

LumiourIsland_EventScript_SetCygnusLocationPostIntro::
	setobjectxyperm LOCALID_PROF_CYGNUS, 6, 5
	end

LumiourIsland_EventScript_SetCygnusLocation0::
	setobjectxyperm LOCALID_PROF_CYGNUS, 7, 9
	end

LumiourIsland_EventScript_SetCygnusLocation1::
	setobjectxyperm LOCALID_PROF_CYGNUS, 3, 8
	applymovement LOCALID_PROF_CYGNUS Common_Movement_FaceUp
	end

LumiourIsland_EventScript_SetCygnusLocation2::
	setobjectxyperm LOCALID_PROF_CYGNUS, 12, 4
	applymovement LOCALID_PROF_CYGNUS Common_Movement_FaceDown
	end

LumiourIsland_EventScript_SetCygnusLocation3::
	setobjectxyperm LOCALID_PROF_CYGNUS, 2, 5
	applymovement LOCALID_PROF_CYGNUS Common_Movement_FaceUp
	end

LumiourIsland_EventScript_SetCygnusLocation4::
	setobjectxyperm LOCALID_PROF_CYGNUS, 14, 6
	applymovement LOCALID_PROF_CYGNUS Common_Movement_FaceLeft
	end

LumiourIsland_EventScript_SetCygnusLocation5::
	setobjectxyperm LOCALID_PROF_CYGNUS, 6, 5
	applymovement LOCALID_PROF_CYGNUS Common_Movement_FaceRight
	end

LumiourIsland_EventScript_SetCygnusLocation6::
	setobjectxyperm LOCALID_PROF_CYGNUS, 9, 6
	applymovement LOCALID_PROF_CYGNUS Common_Movement_FaceLeft
	end

LumiourLab_EventScript_SetRun::
	setflag FLAG_SYS_B_DASH
	hideobjectat LOCALID_PROF_CYGNUS, MAP_LUMIOUR_LAB
	return
	end

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
	.string "{COLOR BLUE}Professor Cygnus: Oh, {PLAYER}!\p"
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
	setflag FLAG_CAN_SLEEP
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
	.string "{COLOR BLUE}If you ever find a fossil you can revive\n"
	.string "it here at anytime.\p"
	.string "And if you need to heal your Pokémon use\n"
	.string "the machine behind you.\p"
	.string "Well, I'd say its about time you get to\n"
	.string "know and explore Lumiere Island!\p"
	.string "Nothing too unusual should happen yet…\p"
	.string "I've had enough of the outdoors today.\n"
	.string "I'm gonna stay inside where its safe.\p"
	.string "Whenever you're ready to sleep you can\n"
	.string "use the bed downstairs.\p"
	.string "One last thing!\p"
	.string "If you ever need Pokéballs or potions\n"
	.string "check the cardboard boxes in the corner.\p"
	.string "Be sure to stock up on items every day.$"


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
	.string "{COLOR BLUE}I haven't used one of these since\n"
	.string "college.\p"
	.string "Now we just let it do its thing and\n"
	.string "before you know it you'll have yourself\l"
	.string "a brand new Pokémon.\p"
	.string "Or I guess you could say its a brand 'old'\n"
	.string "Pokémon!$"

LumiourLab_EventScript_Boxes::
	goto_if_unset FLAG_SYS_POKEMON_GET, LumiourLab_EventScript_DontTouchBoxes
	goto_if_eq VAR_LUMIOUR_ISLAND_STATE, 0, LumiourIsland_EventScript_GiveDay0Items
	goto_if_eq VAR_LUMIOUR_ISLAND_STATE, 1, LumiourIsland_EventScript_GiveDay1Items
	goto_if_eq VAR_LUMIOUR_ISLAND_STATE, 2, LumiourIsland_EventScript_GiveDay2Items
	goto_if_eq VAR_LUMIOUR_ISLAND_STATE, 3, LumiourIsland_EventScript_GiveDay3Items
	goto_if_eq VAR_LUMIOUR_ISLAND_STATE, 4, LumiourIsland_EventScript_GiveDay4Items
	goto_if_eq VAR_LUMIOUR_ISLAND_STATE, 5, LumiourIsland_EventScript_GiveDay5Items
	goto LumiourLab_EventScript_DontTouchBoxes
	end

LumiourIsland_EventScript_GiveDay0Items::
	goto_if_set FLAG_GOT_DAY_0_ITEMS, LumiourIsland_EventScript_GotItems
	giveitem ITEM_GREAT_BALL, 20
	giveitem ITEM_SUPER_POTION, 10
	setflag FLAG_GOT_DAY_0_ITEMS
	release
	end

LumiourIsland_EventScript_GiveDay1Items::
	goto_if_set FLAG_GOT_DAY_1_ITEMS, LumiourIsland_EventScript_GotItems
	giveitem ITEM_GREAT_BALL, 10
	giveitem ITEM_FULL_HEAL, 5
	giveitem ITEM_SUPER_REPEL, 5
	setflag FLAG_GOT_DAY_1_ITEMS
	release
	end

LumiourIsland_EventScript_GiveDay2Items::
	goto_if_set FLAG_GOT_DAY_2_ITEMS, LumiourIsland_EventScript_GotItems
	giveitem ITEM_GREAT_BALL, 10
	giveitem ITEM_LEMONADE, 10
	giveitem ITEM_MAX_REPEL, 3
	setflag FLAG_GOT_DAY_2_ITEMS
	release
	end

LumiourIsland_EventScript_GiveDay3Items::
	goto_if_set FLAG_GOT_DAY_3_ITEMS, LumiourIsland_EventScript_GotItems
	giveitem ITEM_ULTRA_BALL, 10
	giveitem ITEM_HP_UP, 3
	giveitem ITEM_PP_MAX, 1
	setflag FLAG_GOT_DAY_3_ITEMS
	release
	end

LumiourIsland_EventScript_GiveDay4Items::
	goto_if_set FLAG_GOT_DAY_4_ITEMS, LumiourIsland_EventScript_GotItems
	giveitem ITEM_ELIXIR, 5
	giveitem ITEM_REVIVE, 10
	giveitem ITEM_MAX_REPEL, 5
	setflag FLAG_GOT_DAY_4_ITEMS
	release
	end

LumiourIsland_EventScript_GiveDay5Items::
	goto_if_set FLAG_GOT_DAY_5_ITEMS, LumiourIsland_EventScript_GotItems
	giveitem ITEM_ULTRA_BALL, 10
	giveitem ITEM_FULL_RESTORE, 5
	giveitem ITEM_REVIVE, 5
	setflag FLAG_GOT_DAY_5_ITEMS
	release
	end

LumiourIsland_EventScript_GotItems::
	msgbox LumiourLab_Text_EmptyBoxes, MSGBOX_DEFAULT
	release
	end

LumiourLab_Text_EmptyBoxes:
	.string "The boxes are empty.$"

LumiourLab_EventScript_DontTouchBoxes::
	lock
	faceplayer
	msgbox LumiourLab_Text_DontTouchBoxes, MSGBOX_DEFAULT
	release
	end

LumiourLab_Text_DontTouchBoxes:
	.string "It's a box full of supplies for trainers.\p"
	.string "Better leave it alone for now…$"

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
	lock
	msgbox LumiourIslandLab_Text_UseFossilMachine, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, LumiourLab_EventScript_Cancel
	case YES, LumiourLab_EventScript_ReviveFossil
	case MULTI_B_PRESSED, LumiourLab_EventScript_Cancel
	end

LumiourLab_EventScript_ReviveFossil::
	checkitem ITEM_HELIX_FOSSIL, 1
	compare VAR_RESULT, 1
	goto_if_ge LumiourLab_EventScript_GiveOmanyte
	checkitem ITEM_DOME_FOSSIL, 1
	compare VAR_RESULT, 1
	goto_if_ge LumiourLab_EventScript_GiveKabuto
	checkitem ITEM_ROOT_FOSSIL, 1
	compare VAR_RESULT, 1
	goto_if_ge LumiourLab_EventScript_GiveLileep
	checkitem ITEM_CLAW_FOSSIL, 1
	compare VAR_RESULT, 1
	goto_if_ge LumiourLab_EventScript_GiveAnorith
	checkitem ITEM_ARMOR_FOSSIL, 1
	compare VAR_RESULT, 1
	goto_if_ge LumiourLab_EventScript_GiveShieldon
	checkitem ITEM_SKULL_FOSSIL, 1
	compare VAR_RESULT, 1
	goto_if_ge LumiourLab_EventScript_GiveCranidos
	checkitem ITEM_PLUME_FOSSIL, 1
	compare VAR_RESULT, 1
	goto_if_ge LumiourLab_EventScript_GiveArchen
	checkitem ITEM_COVER_FOSSIL, 1
	compare VAR_RESULT, 1
	goto_if_ge LumiourLab_EventScript_GiveTirtouga
	goto LumiourLab_EventScript_NoFossil
	end

LumiourLab_EventScript_GiveOmanyte::
	msgbox LumiourLab_Text_PutInHelix, MSGBOX_DEFAULT
	removeitem ITEM_HELIX_FOSSIL, 1
	closemessage
	playse SE_ELEVATOR
	waitse
	playse SE_DING_DONG
	waitse
	setvar VAR_TEMP_1, SPECIES_OMANYTE
	givemon SPECIES_OMANYTE, 25, ITEM_NONE
	bufferspeciesname STR_VAR_1, SPECIES_OMANYTE
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, LumiourLab_EventScript_ReceiveFossilParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, LumiourLab_EventScript_ReceiveFossilPC
	goto Common_EventScript_NoMoreRoomForPokemon
	release
	end

LumiourLab_EventScript_GiveKabuto::
	msgbox LumiourLab_Text_PutInDome, MSGBOX_DEFAULT
	removeitem ITEM_DOME_FOSSIL, 1
	closemessage
	playse SE_ELEVATOR
	waitse
	playse SE_DING_DONG
	waitse
	setvar VAR_TEMP_1, SPECIES_KABUTO
	givemon SPECIES_KABUTO, 25, ITEM_NONE
	bufferspeciesname STR_VAR_1, SPECIES_KABUTO
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, LumiourLab_EventScript_ReceiveFossilParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, LumiourLab_EventScript_ReceiveFossilPC
	goto Common_EventScript_NoMoreRoomForPokemon
	release
	end

LumiourLab_EventScript_GiveLileep::
	msgbox LumiourLab_Text_PutInRoot, MSGBOX_DEFAULT
	removeitem ITEM_ROOT_FOSSIL, 1
	closemessage
	playse SE_ELEVATOR
	waitse
	playse SE_DING_DONG
	waitse
	setvar VAR_TEMP_1, SPECIES_LILEEP
	givemon SPECIES_LILEEP, 25, ITEM_NONE
	bufferspeciesname STR_VAR_1, SPECIES_LILEEP
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, LumiourLab_EventScript_ReceiveFossilParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, LumiourLab_EventScript_ReceiveFossilPC
	goto Common_EventScript_NoMoreRoomForPokemon
	release
	end

LumiourLab_EventScript_GiveAnorith::
	msgbox LumiourLab_Text_PutInClaw, MSGBOX_DEFAULT
	removeitem ITEM_CLAW_FOSSIL, 1
	closemessage
	playse SE_ELEVATOR
	waitse
	playse SE_DING_DONG
	waitse
	setvar VAR_TEMP_1, SPECIES_ANORITH
	givemon SPECIES_ANORITH, 25, ITEM_NONE
	bufferspeciesname STR_VAR_1, SPECIES_ANORITH
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, LumiourLab_EventScript_ReceiveFossilParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, LumiourLab_EventScript_ReceiveFossilPC
	goto Common_EventScript_NoMoreRoomForPokemon
	release
	end

LumiourLab_EventScript_GiveShieldon::
	msgbox LumiourLab_Text_PutInArmor, MSGBOX_DEFAULT
	removeitem ITEM_ARMOR_FOSSIL, 1
	closemessage
	playse SE_ELEVATOR
	waitse
	playse SE_DING_DONG
	waitse
	setvar VAR_TEMP_1, SPECIES_SHIELDON
	givemon SPECIES_SHIELDON, 25, ITEM_NONE
	bufferspeciesname STR_VAR_1, SPECIES_SHIELDON
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, LumiourLab_EventScript_ReceiveFossilParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, LumiourLab_EventScript_ReceiveFossilPC
	goto Common_EventScript_NoMoreRoomForPokemon
	release
	end

LumiourLab_EventScript_GiveCranidos::
	msgbox LumiourLab_Text_PutInSkull, MSGBOX_DEFAULT
	removeitem ITEM_SKULL_FOSSIL, 1
	closemessage
	playse SE_ELEVATOR
	waitse
	playse SE_DING_DONG
	waitse
	setvar VAR_TEMP_1, SPECIES_CRANIDOS
	givemon SPECIES_CRANIDOS, 25, ITEM_NONE
	bufferspeciesname STR_VAR_1, SPECIES_CRANIDOS
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, LumiourLab_EventScript_ReceiveFossilParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, LumiourLab_EventScript_ReceiveFossilPC
	goto Common_EventScript_NoMoreRoomForPokemon
	release
	end

LumiourLab_EventScript_GiveArchen::
	msgbox LumiourLab_Text_PutInPlume, MSGBOX_DEFAULT
	removeitem ITEM_PLUME_FOSSIL, 1
	closemessage
	playse SE_ELEVATOR
	waitse
	playse SE_DING_DONG
	waitse
	setvar VAR_TEMP_1, SPECIES_ARCHEN
	givemon SPECIES_ARCHEN, 25, ITEM_NONE
	bufferspeciesname STR_VAR_1, SPECIES_ARCHEN
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, LumiourLab_EventScript_ReceiveFossilParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, LumiourLab_EventScript_ReceiveFossilPC
	goto Common_EventScript_NoMoreRoomForPokemon
	release
	end

LumiourLab_EventScript_GiveTirtouga::
	msgbox LumiourLab_Text_PutInCover, MSGBOX_DEFAULT
	removeitem ITEM_COVER_FOSSIL, 1
	closemessage
	playse SE_ELEVATOR
	waitse
	playse SE_DING_DONG
	waitse
	setvar VAR_TEMP_1, SPECIES_TIRTOUGA
	givemon SPECIES_TIRTOUGA, 25, ITEM_NONE
	bufferspeciesname STR_VAR_1, SPECIES_TIRTOUGA
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, LumiourLab_EventScript_ReceiveFossilParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, LumiourLab_EventScript_ReceiveFossilPC
	goto Common_EventScript_NoMoreRoomForPokemon
	release
	end

LumiourLab_EventScript_ReceiveFossilParty::
	call LumiourLab_EventScript_ReceivedFossilFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LumiourLab_EventScript_Cancel
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	release
	end

LumiourLab_EventScript_ReceiveFossilPC::
	call LumiourLab_EventScript_ReceivedFossilFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LumiourLab_EventScript_SendFossilToPC
	call Common_EventScript_NameReceivedBoxMon
	goto LumiourLab_EventScript_SendFossilToPC
	end

LumiourLab_EventScript_SendFossilToPC::
	call Common_EventScript_TransferredToPC
	closemessage
	end

LumiourLab_EventScript_ReceivedFossilFanfare:
	playfanfare MUS_OBTAIN_ITEM
	message LumiourLab_Text_PlayerReceivedFossil
	waitmessage
	waitfanfare
	return

LumiourLab_Text_PlayerReceivedFossil:
	.string "{PLAYER} received {STR_VAR_1}$"

LumiourLab_EventScript_NoFossil::
	msgbox LumiourLab_Text_NoFossil, MSGBOX_DEFAULT
	release
	end

LumiourLab_Text_PutInHelix:
	.string "You put the Helix fossil in the machine.$"

LumiourLab_Text_PutInDome:
	.string "You put the Dome fossil in the machine.$"

LumiourLab_Text_PutInRoot:
	.string "You put the Root fossil in the machine.$"

LumiourLab_Text_PutInClaw:
	.string "You put the Claw fossil in the machine.$"

LumiourLab_Text_PutInArmor:
	.string "You put the Armor fossil in the machine.$"

LumiourLab_Text_PutInSkull:
	.string "You put the Skull fossil in the machine.$"

LumiourLab_Text_PutInPlume:
	.string "You put the Plume fossil in the machine.$"

LumiourLab_Text_PutInCover:
	.string "You put the Cover fossil in the machine.$"

LumiourLab_Text_NoFossil:
	.string "You don't have a fossil.$"

LumiourIslandLab_Text_UseFossilMachine:
	.string "Would you like to revive a fossil?$"

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
	.string "It's said to have a keen affinity\n"
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
	.string "Ruler of space and part of the Creation\n"
	.string "Trio alongside Dialga and Giratina.\p"
	.string "Ancient Sinnoh writings tell of early\n"
	.string "civilizations at odds with each other\l"
	.string "over the existence of these Pokémon.\p"
	.string "That was until anomalies in the flow of\n"
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
	.string "of Mirage Islands.\p"
	.string "It appears to just be incoherent\n"
	.string "theorizing.$"

LumiourLab_EventScript_TV::
	goto_if_unset FLAG_SYS_POKEMON_GET, LumiourIslandLab_EventScript_TVCommercial
	goto_if_eq VAR_LUMIOUR_ISLAND_STATE, 0, LumiourIslandLab_EventScript_TVCommercial
	goto_if_eq VAR_LUMIOUR_ISLAND_STATE, 1, LumiourIslandLab_EventScript_TVMemorialPillar
	goto_if_eq VAR_LUMIOUR_ISLAND_STATE, 2, LumiourIslandLab_EventScript_TVWhirlIsland
	goto_if_eq VAR_LUMIOUR_ISLAND_STATE, 3, LumiourIslandLab_EventScript_TVMirageIsland
	goto_if_eq VAR_LUMIOUR_ISLAND_STATE, 4, LumiourIslandLab_EventScript_TVIronIsland
	goto_if_eq VAR_LUMIOUR_ISLAND_STATE, 5, LumiourIslandLab_EventScript_TVLibertyGarden
	goto_if_eq VAR_LUMIOUR_ISLAND_STATE, 6, LumiourIslandLab_EventScript_TVExtinctPokemon
	end

LumiourIslandLab_EventScript_TVExtinctPokemon::
	msgbox LumiourIslandLab_Text_ExtinctPokemon, MSGBOX_SIGN
	end

LumiourIslandLab_Text_ExtinctPokemon:
	.string "The TV is set to a news channel.\p"
	.string "{COLOR RED}News Anchor: The previously thought\n"
	.string "to be extinct Pokémon Kleavor has been\l"
	.string "spotted near Eterna Forest in Sinnoh.$"

LumiourIslandLab_EventScript_TVCommercial::
	msgbox LumiourIslandLab_Text_Commercial, MSGBOX_SIGN
	end

LumiourIslandLab_EventScript_TVMemorialPillar::
	goto_if_set FLAG_DAY_1_COMPLETE, LumiourLab_EventScript_TVMemorialPillarReturned
	msgbox LumiourIslandLab_Text_TVMemorialPillar, MSGBOX_SIGN
	end

LumiourLab_EventScript_TVMemorialPillarReturned:
	msgbox LumiourIslandLab_Text_TVMemorialPillarReturned, MSGBOX_SIGN
	end

LumiourIslandLab_EventScript_TVWhirlIsland::
	goto_if_set FLAG_DAY_2_COMPLETE, LumiourLab_EventScript_TVWhirlIslandReturned
	msgbox LumiourIslandLab_Text_TVWhirlIsland, MSGBOX_SIGN
	end

LumiourLab_EventScript_TVWhirlIslandReturned::
	msgbox LumiourIslandLab_Text_TVWhirlIslandReturned, MSGBOX_SIGN
	end

LumiourIslandLab_EventScript_TVMirageIsland::
	goto_if_set FLAG_DAY_3_COMPLETE, LumiourLab_EventScript_TVMirageIslandReturned
	msgbox LumiourIslandLab_Text_TVMirageIsland, MSGBOX_SIGN
	end

LumiourLab_EventScript_TVMirageIslandReturned::
	msgbox LumiourIslandLab_Text_TVMirageIslandReturned, MSGBOX_SIGN
	end

LumiourIslandLab_EventScript_TVIronIsland::
	goto_if_set FLAG_DAY_4_COMPLETE, LumiourLab_EventScript_TVIronIslandReturned
	msgbox LumiourIslandLab_Text_TVIronIsland, MSGBOX_SIGN
	end

LumiourLab_EventScript_TVIronIslandReturned::
	msgbox LumiourIslandLab_Text_TVIronIslandReturned, MSGBOX_SIGN
	end

LumiourIslandLab_EventScript_TVLibertyGarden::
	goto_if_set FLAG_DAY_5_COMPLETE, LumiourLab_EventScript_TVLibertyGardenReturned
	msgbox LumiourIslandLab_Text_TVLibertyGarden, MSGBOX_SIGN
	end

LumiourLab_EventScript_TVLibertyGardenReturned::
	msgbox LumiourIslandLab_Text_TVLibertyGardenReturned, MSGBOX_SIGN
	end

LumiourIslandLab_Text_Commercial:
	.string "It's on commercial break…$"

LumiourIslandLab_Text_TVMemorialPillar:
	.string "The TV is set to a news channel.\p"
	.string "{COLOR RED}News Anchor: Reports of Mirage Islands\n"
	.string "continue.\p"
	.string "Memorial Pillar off the coast of\n"
	.string "Five Island has dissapeared.\p"
	.string "Its location is currently unknown.$"


LumiourIslandLab_Text_TVMemorialPillarReturned:
	.string "The TV is set to a news channel.\p"
	.string "{COLOR RED}News Anchor: Memorial Pillar has\n"
	.string "returned to the coast of Five Island.\p"
	.string "Trainers are currently prohibited from\n"
	.string "entering until it's confirmed to be safe.$"

LumiourIslandLab_Text_TVWhirlIsland:
	.string "The TV is set to a news channel.\p"
	.string "{COLOR RED}News Anchor: Reports of Mirage Islands\n"
	.string "continue yet again.\p"
	.string "The Johto Region's Whirl Islands\n"
	.string "have reportedly had multiple pieces\l"
	.string "of land dissapear and reappear\l"
	.string "throughout the night.$"

LumiourIslandLab_Text_TVWhirlIslandReturned:
	.string "The TV is set to a news channel.\p"
	.string "{COLOR RED}News Anchor: Trainers are prohibited\n"
	.string "from entering Route 41 until it's\l"
	.string "been deemed safe.$"

LumiourIslandLab_Text_TVMirageIsland:
	.string "The TV is set to a news channel.\p"
	.string "{COLOR RED}News Anchor: A Mirage Island has\n"
	.string "been identified near Pacifidlog Town\l"
	.string "in the Hoenn Region.\p"
	.string "A local trainer managed to travel to\n"
	.string "the island and discovered a never\l"
	.string "before seen Liechi Berry.\p"
	.string "Effects of the berry are being\n"
	.string "studied at the Birch Pokémon Lab.\p"
	.string "Trainers are advised to not use\n"
	.string "any untagged berries.$"

LumiourIslandLab_Text_TVMirageIslandReturned:
	.string "The TV is set to a news channel.\p"
	.string "{COLOR RED}News Anchor: The Liechi Berry\n"
	.string "has been approved and is safe for use.\p"
	.string "However due to such short supply of\n"
	.string "the berry it will likely be unable\l"
	.string "to grow.$"

LumiourIslandLab_Text_TVIronIsland:
	.string "The TV is set to a news channel.\p"
	.string "{COLOR RED}News Anchor: A small section of\n"
	.string "Sinnoh's Iron Island has dissapeared.\p"
	.string "Workers at the mine are unharmed\n"
	.string "however the sudden dissapearance of\l"
	.string "the land has flooded the island,\l"
	.string "rendering the mine inaccessable.$"

LumiourIslandLab_Text_TVIronIslandReturned:
	.string "The TV is set to a news channel.\p"
	.string "{COLOR RED}News Anchor: Iron Island has returned\n"
	.string "to it's previous state.\p"
	.string "All mining equipment is confirmed to be\n"
	.string "functioning as normal.$"

LumiourIslandLab_Text_TVLibertyGarden:
	.string "The TV is set to a news channel.\p"
	.string "{COLOR RED}News Anchor: Radio connection to\n"
	.string "a boat traveling from Castelia City\l"
	.string "To Liberty Garden in the Unova\l"
	.string "Region has been lost.\p"
	.string "Travel logs say approximately 11\n"
	.string "people where on the boat.\p"
	.string "Their names and location are\n"
	.string "currently unknown...$"

LumiourIslandLab_Text_TVLibertyGardenReturned:
	.string "The TV is set to a news channel.\p"
	.string "{COLOR RED}News Anchor: Connection has been made\n"
	.string "with Professor Cygnus on Lumiere Island.\p"
	.string "All missing passengers have been found\n"
	.string "by {PLAYER}, the professor's aide.\p"
	.string "A team of sailors from Castelia City \n"
	.string "has been sent to escort the passengers\l"
	.string "back home safely.$"

LumiourLab_EventScript_ProfCygnus::
	lock
	goto_if_eq VAR_LUMIOUR_ISLAND_STATE, 0, LumiourLab_EventScript_CygnusDay0
	goto_if_eq VAR_LUMIOUR_ISLAND_STATE, 1, LumiourLab_EventScript_CygnusDay1
	goto_if_eq VAR_LUMIOUR_ISLAND_STATE, 2, LumiourLab_EventScript_CygnusDay2
	goto_if_eq VAR_LUMIOUR_ISLAND_STATE, 3, LumiourLab_EventScript_CygnusDay3
	goto_if_eq VAR_LUMIOUR_ISLAND_STATE, 4, LumiourLab_EventScript_CygnusDay4
	goto_if_eq VAR_LUMIOUR_ISLAND_STATE, 5, LumiourLab_EventScript_CygnusDay5
	goto_if_eq VAR_LUMIOUR_ISLAND_STATE, 6, LumiourLab_EventScript_CygnusDay6
	release
	end

LumiourLab_EventScript_CygnusDay6:
	lock
	faceplayer
	msgbox LumiourLab_Text_Cygnus_GoPlayer, MSGBOX_DEFAULT
	release
	end

LumiourLab_Text_Cygnus_GoPlayer:
	.string "{COLOR BLUE}Professor Cygnus: Go {PLAYER}!\n"
	.string "You have to find and stop Palkia!\p"
	.string "Its all up to you now!$"

LumiourLab_EventScript_CygnusDay0:
	lock
	faceplayer
	msgbox LumiourLab_Text_Cygnus_RespondMessages, MSGBOX_DEFAULT
	applymovement LOCALID_PROF_CYGNUS Common_Movement_FaceRight
	waitmovement 0
	release
	end

LumiourLab_Text_Cygnus_RespondMessages:
	.string "{COLOR BLUE}Sorry, I've gotta respond to some\n"
	.string "important messages.\p"
	.string "Whenever you're done exploring Lumiere\n"
	.string "Island you can rest until tomorrow in\l"
	.string "the bed downstairs.$"

LumiourLab_EventScript_CygnusDay1:
	goto_if_set FLAG_DAY_1_COMPLETE, LumiourLab_EventScript_CygnusDay1Complete
	msgbox LumiourLab_Text_Cygnus_Groudon, MSGBOX_DEFAULT
	applymovement LOCALID_PROF_CYGNUS, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LumiourLab_Text_Cygnus_HiPlayer1, MSGBOX_DEFAULT
	applymovement LOCALID_PROF_CYGNUS, Common_Movement_FaceUp
	waitmovement 0
	release
	end

LumiourLab_EventScript_CygnusDay1Complete:
	lock
	faceplayer
	msgbox LumiourLab_Text_Cygnus_Day1Complete, MSGBOX_DEFAULT
	applymovement LOCALID_PROF_CYGNUS, Common_Movement_FaceUp
	waitmovement 0
	release
	end

LumiourLab_Text_Cygnus_Day1Complete:
	.string "{COLOR BLUE}Professor Cygnus: Hmm, so the island\n"
	.string "you found must be Memorial Pillar.\p"
	.string "Whatever you did with the stones\n"
	.string "must have returned the island.\p"
	.string "You should get some rest. Our studies\n"
	.string "will continue tomorrow.$"

LumiourLab_Text_Cygnus_HiPlayer1:
	.string "{COLOR BLUE}OH! Hello {PLAYER}!\p"
	.string "Be sure to check the TV before\n"
	.string "leaving.\p"
	.string "It may seem odd now but its the only\n"
	.string "thing that can prepare you.\p"
	.string "I know you'll do fine today!\p"
	.string "I wish you luck!$"

LumiourLab_Text_Cygnus_Groudon:
	.string "{COLOR BLUE}Professor Cygnus: So if it was Groudon\n"
	.string "it would be sunny outside…$"

LumiourLab_EventScript_CygnusDay2:
	goto_if_set FLAG_DAY_2_COMPLETE, LumiourLab_EventScript_CygnusDay2Complete
	msgbox LumiourLab_Text_Cygnus_Hoopa, MSGBOX_DEFAULT
	applymovement LOCALID_PROF_CYGNUS, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LumiourLab_Text_Cygnus_HiPlayer2, MSGBOX_DEFAULT
	applymovement LOCALID_PROF_CYGNUS, Common_Movement_FaceDown
	waitmovement 0
	release
	end

LumiourLab_EventScript_CygnusDay2Complete:
	lock
	faceplayer
	msgbox LumiourLab_Text_Cygnus_Day2Complete, MSGBOX_DEFAULT
	applymovement LOCALID_PROF_CYGNUS, Common_Movement_FaceDown
	waitmovement 0
	release
	end

LumiourLab_Text_Cygnus_Day2Complete:
	.string "{COLOR BLUE}Professor Cygnus: So you really\n"
	.string "battled with Lugia!?\p"
	.string "I'm very impressed.\n"
	.string "I knew Aerodactyl would protect you!\p"
	.string "You should get some rest. Our studies\n"
	.string "will continue tomorrow.$"

LumiourLab_Text_Cygnus_HiPlayer2:
	.string "{COLOR BLUE}OH! Hello {PLAYER}!\p"
	.string "Sorry I was doing a bit of reading\n"
	.string "to figure out what is causing the\l"
	.string "Mirage Islands.\p"
	.string "Stay safe on the island please!$"

LumiourLab_Text_Cygnus_Hoopa:
	.string "{COLOR BLUE}Professor Cygnus: Hoopa moves islands\n"
	.string "through dimensional portals…\p"
	.string "But the news reports… These islands\n"
	.string "have to be from our dimension.$."

LumiourLab_EventScript_CygnusDay3:
	goto_if_set FLAG_DAY_3_COMPLETE, LumiourLab_EventScript_CygnusDay3Complete
	msgbox LumiourLab_Text_Cygnus_InternetForum, MSGBOX_DEFAULT
	applymovement LOCALID_PROF_CYGNUS, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LumiourLab_Text_Cygnus_HiPlayer3, MSGBOX_DEFAULT
	applymovement LOCALID_PROF_CYGNUS, Common_Movement_FaceUp
	waitmovement 0
	release
	end

LumiourLab_EventScript_CygnusDay3Complete:
	lock
	faceplayer
	msgbox LumiourLab_Text_Cygnus_Day3Complete, MSGBOX_DEFAULT
	applymovement LOCALID_PROF_CYGNUS, Common_Movement_FaceUp
	waitmovement 0
	release
	end

LumiourLab_Text_Cygnus_Day3Complete:
	.string "{COLOR BLUE}Professor Cygnus: So you found\n"
	.string "a Liechi Berry.\p"
	.string "I can get into contact with Professor\n"
	.string "Birch and have it sent to his lab\l"
	.string "to be studied.\p"
	.string "Easy day today huh?\p"
	.string "Thats strange how the island didn't\n"
	.string "dissapear this time…\p"
	.string "Maybe there's still something to \n"
	.string "discover today.\p"
	.string "If not you can relax today.$"

LumiourLab_Text_Cygnus_HiPlayer3:
	.string "{COLOR BLUE}OH! Hello {PLAYER}!\p"
	.string "The people on this website are crazy!\p"
	.string "You know what to do!\p"
	.string "Glad I can always count on you!$"

LumiourLab_Text_Cygnus_InternetForum:
	.string "{COLOR BLUE}Professor Cygnus: I should've known\n"
	.string "I wouldn't find any good ideas on\l"
	.string "the internet…$"

LumiourLab_EventScript_CygnusDay4:
	goto_if_set FLAG_DAY_4_COMPLETE, LumiourLab_EventScript_CygnusDay4Complete
	msgbox LumiourLab_Text_Cygnus_Necrozma, MSGBOX_DEFAULT
	applymovement LOCALID_PROF_CYGNUS, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LumiourLab_Text_Cygnus_HiPlayer4, MSGBOX_DEFAULT
	applymovement LOCALID_PROF_CYGNUS, Common_Movement_FaceLeft
	waitmovement 0
	release
	end

LumiourLab_EventScript_CygnusDay4Complete:
	lock
	faceplayer
	msgbox LumiourLab_Text_Cygnus_Day4Complete, MSGBOX_DEFAULT
	applymovement LOCALID_PROF_CYGNUS, Common_Movement_FaceLeft
	waitmovement 0
	release
	end

LumiourLab_Text_Cygnus_Day4Complete:
	.string "{COLOR BLUE}Professor Cygnus: Nothing of note\n"
	.string "on the island huh?\p"
	.string "However you did battle an extremely\n"
	.string "powerful Lucario.\p"
	.string "We have to find an answer soon.\p"
	.string "Get some sleep, im sure you will\n"
	.string "need it for tomorrow.$"

LumiourLab_Text_Cygnus_HiPlayer4:
	.string "{COLOR BLUE}OH! Hello {PLAYER}!\p"
	.string "I'm running out of ideas for what\n"
	.string "Pokémon could be causing the\l"
	.string "Mirage Islands.\p"
	.string "Hopefully we can find an answer\n"
	.string "soon.$"

LumiourLab_Text_Cygnus_Necrozma:
	.string "{COLOR BLUE}Professor Cygnus: I haven't\n"
	.string "even seen any Ultra Wormwholes.\p"
	.string "Of course it can't be Necrozma.$"

LumiourLab_EventScript_CygnusDay5:
	goto_if_set FLAG_DAY_5_COMPLETE, LumiourLab_EventScript_CygnusDay5Complete
	msgbox LumiourLab_Text_Cygnus_Palkia, MSGBOX_DEFAULT
	applymovement LOCALID_PROF_CYGNUS, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LumiourLab_Text_Cygnus_HiPlayer5, MSGBOX_DEFAULT
	applymovement LOCALID_PROF_CYGNUS, Common_Movement_FaceRight
	waitmovement 0
	release
	end

LumiourLab_EventScript_CygnusDay5Complete:
	lock
	faceplayer
	msgbox LumiourLab_Text_Cygnus_Day5Complete, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_PROF_CYGNUS, Common_Movement_QuestionMark
	waitmovement 0
	waitse
	msgbox LumiourLab_Text_Cygnus_StrangeStone, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement LOCALID_PROF_CYGNUS, Common_Movement_ExclamationMark
	waitmovement 0
	waitse
	msgbox LumiourLab_Text_Cygnus_LustrousOrb, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PROF_CYGNUS, Common_Movement_FaceRight
	waitmovement 0
	release
	end

LumiourLab_Text_Cygnus_LustrousOrb:
	.string "{COLOR BLUE}It can't be…\n"
	.string "{PLAYER}, you know what this is correct?\p"
	.string "This is Palkia's Lustrous Orb…\p"
	.string "So this was found on the Liberty Garden\n"
	.string "When it first appeared near Lumiere.\p"
	.string "That must mean my theories were correct.\p"
	.string "Palkia has the power to control the flow\n"
	.string "of space.\p"
	.string "That must be how these islands can\n"
	.string "appear and dissapear at the blink of\l"
	.string "an eye.\p"
	.string "I have a feeling tomorrow is the big day…\p"
	.string "Go get some well deserved rest {PLAYER}!\p"
	.string "Oh, and check the TV!\p"
	.string "At least im on the news for something\n"
	.string "good this time!$"

LumiourLab_Text_Cygnus_StrangeStone:
	.string "{COLOR BLUE}Huh? The captain gave you a strange\n"
	.string "stone?$"

LumiourLab_Text_Cygnus_Day5Complete:
	.string "{COLOR BLUE}Professor Cygnus: There you are!\p"
	.string "I didn't expect a bunch of stubborn\n"
	.string "trainers to come visit Lumiere Island!\p"
	.string "If it weren't for you I don't think we'd\n"
	.string "be able to get them back home!$"

LumiourLab_Text_Cygnus_HiPlayer5:
	.string "{COLOR BLUE}OH! Hello {PLAYER}!\p"
	.string "I'm not completely sure yet but\n"
	.string "I think I may have a good lead\p"
	.string "Go {PLAYER}! See what you can\n"
	.string "find on the island!\p"
	.string "I'm counting on you!$"

LumiourLab_Text_Cygnus_Palkia:
	.string "{COLOR BLUE}Professor Cygnus: Hmm…\p"
	.string "So Palkia has the ability to\n"
	.string "distort the flow of space…$"

LumiereLab_ShowCredit::
	lock
	msgbox text_credit, MSGBOX_DEFAULT
	special Special_ShowDiploma
	release
	end

text_credit:
	.string "Scan or go to this link to view credits$"
