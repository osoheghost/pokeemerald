LumiourLab_B1_MapScripts::
	.byte 0

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
	release
	end

LumiourIsland_B1_Text_UseBed:
	.string "Go to sleep until morning?$"
