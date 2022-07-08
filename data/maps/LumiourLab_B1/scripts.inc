LumiourLab_B1_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LumiereLab_B1_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LumiereLab_B1_OnFrame
	.byte 0

LumiereLab_B1_OnFrame::
	map_script_2 VAR_PALKIA_SEQUENCE_STATE, 8, LumiereLab_B1_EventScript_Credits2
	.2byte 0

LumiereLab_B1_OnWarp:
	map_script_2 VAR_PALKIA_SEQUENCE_STATE, 8, LumiereLab_B1_EventScript_SetDirection
	.2byte 0

LumiourLab_B1_EventScript_Bed::
	lock
	goto_if_unset FLAG_SYS_POKEMON_GET, LumiourIsland_B1_EventScript_WaitForCygnus
	goto_if_set FLAG_CAN_SLEEP, LumiourIsland_B1_EventScript_Sleep
	msgbox LumiourIsland_B1_Text_CantSleep, MSGBOX_DEFAULT
	release
	end

LumiourIsland_B1_EventScript_Sleep::
	msgbox LumiourIsland_B1_Text_UseBed, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, LumiourLab_B1_EventScript_Cancel
	case YES, LumiourLab_B1_EventScript_GotoMorningCheck2
	case MULTI_B_PRESSED, LumiourLab_B1_EventScript_Cancel
	end

LumiourLab_B1_EventScript_GotoMorningCheck2::
	msgbox LumiourIsland_B1_Text_UseBed2, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, LumiourLab_B1_EventScript_Cancel
	case YES, LumiourLab_B1_EventScript_GotoMorningCheck
	case MULTI_B_PRESSED, LumiourLab_B1_EventScript_Cancel
	end

LumiourIsland_B1_EventScript_WaitForCygnus:
	msgbox LumiourIsland_B1_Text_WaitForCygnus, MSGBOX_DEFAULT
	release
	end

LumiourIsland_B1_Text_WaitForCygnus:	
	.string "I need to wait for Professor Cygnus\n"
	.string "to return.$"

LumiourLab_B1_EventScript_Cancel::
	release
	end

LumiourLab_B1_EventScript_GotoMorningCheck:
	goto_if_set FLAG_CAN_SLEEP LumiourLab_B1_EventScript_GotoMorning
	msgbox LumiourIsland_B1_Text_CantSleep, MSGBOX_DEFAULT
	release
	end

LumiourIsland_B1_Text_CantSleep:
	.string "I can't sleep now, I need to study the\n"
	.string "island.$"

LumiourLab_B1_EventScript_GotoMorning::
	closemessage
	fadeoutbgm 1
	fadescreen 1
	playfanfare MUS_HEAL
	special HealPlayerParty
	addvar VAR_LUMIOUR_ISLAND_STATE, 1
	waitfanfare
	fadescreen 0
	fadeinbgm 1
	clearflag FLAG_CAN_SLEEP
	clearflag FLAG_BERRY_1
	clearflag FLAG_BERRY_2
	clearflag FLAG_BERRY_3
	clearflag FLAG_BERRY_4
	clearflag FLAG_BERRY_5
	clearflag FLAG_BERRY_6
	release
	end

LumiourIsland_B1_Text_UseBed:
	.string "Go to sleep until morning?$"

LumiourIsland_B1_Text_UseBed2:
	.string "You may miss out on daily items and\n"
	.string "secrets around Lumiere Island.\p"
	.string "Are you sure you want to continue?$"

LumiereLab_B1_EventScript_Computer::
	lock
	goto_if_set FLAG_GAME_COMPLETE LumiereLab_B1_EventScript_Credits
	msgbox LumiereIsland_B1_Text_CygnusPC, MSGBOX_DEFAULT
	release
	end

LumiereIsland_B1_Text_CygnusPC:
	.string "Its Professor Cygnus' computer.\p"
	.string "Better leave it alone.$"

LumiereLab_B1_EventScript_TrashCan::
	goto_if_set FLAG_LUMIERE_LAB_B1_LEFTOVERS, LumiereLab_B1_EventScript_OnlyTrash
	giveitem ITEM_LEFTOVERS, 1
	setflag FLAG_LUMIERE_LAB_B1_LEFTOVERS
	release
	end

LumiereLab_B1_EventScript_OnlyTrash:
	lock
	msgbox LumiereLab_B1_Text_OnlyTrash, MSGBOX_DEFAULT
	release
	end

LumiereLab_B1_Text_OnlyTrash:	
	.string "The trash can is empty.$"

LumiereLab_B1_EventScript_SetDirection::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	end

LumiereLab_B1_EventScript_Credits::
	lock
	msgbox LumiereLab_B1_Text_QRCode, MSGBOX_DEFAULT
	special Special_ShowDiploma
	waitbuttonpress
	msgbox LumiereLab_B1_Text_ViewInGame, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LumiourLab_B1_EventScript_End
	msgbox LumiereLab_B1_Text_Credits, MSGBOX_DEFAULT
	release
	end

LumiereLab_B1_EventScript_Credits2::
	lock
	setvar VAR_PALKIA_SEQUENCE_STATE, 9
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	msgbox LumiereLab_B1_Text_QRCode, MSGBOX_AUTOCLOSE
	closemessage
	special Special_ShowDiploma
	waitstate
	release
	end


LumiourLab_B1_EventScript_End::
	closemessage
	end

LumiereLab_B1_Text_QRCode:
	.string "There's a QR code on the computer.$"

LumiereLab_B1_Text_ViewInGame:
	.string "Would you like to view credits in game?$"

LumiereLab_B1_Text_Credits:
	.string "Projects Space Taker:\n"
	.string "Designed and created by OsoheGhost.\p"
	.string "Player sprites: Rankomon\p"
	.string "Pokémon Gaia Tileset:\n"
	.string "Spherical Ice, Cuddlesthefatcat\l"
	.string "Mateo, Fanking Omega, Kyle-Dove\l"
	.string "LunaMaddalena.\p"
	.string "Decomp base:\n"
	.string "Pret/RHH team\p"
	.string "Additional code:\n"
	.string "Ghoulslash, Spherical Ice, Jaizu\l"
	.string "DizzyEgg, Zeturic, TheXaman, Lunos\l"
	.string "Blurose.\p"
	.string "Beta Testers:\n"
	.string "Rankomon, Snugboat, VLN-VS and Nick\p"
	.string "Special thanks to Spherical Ice!\n"
	.string "If it weren't for Gaia I would've\l"
	.string "never been as interested in romhacks\l"
	.string "and fangames as I am now :>$"
