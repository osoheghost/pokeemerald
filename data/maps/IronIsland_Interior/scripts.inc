.set LOCALID_LUCARIO, 1

IronIsland_Interior_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, IronIsland_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, IronIsland_OnResume
	.byte 0

IronIsland_OnTransition:
	call_if_set FLAG_CAUGHT_LUCARIO, IronIsland_EventScript_HideLucario
	call_if_unset FLAG_CAUGHT_LUCARIO, IronIsland_EventScript_TryShowLucario
	end

IronIsland_EventScript_HideLucario::
	setflag FLAG_CAUGHT_LUCARIO
	return

IronIsland_EventScript_TryShowLucario::
	goto_if_set FLAG_DEFEATED_LUCARIO, Common_EventScript_NopReturn
	clearflag FLAG_CAUGHT_LUCARIO
	return

IronIsland_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, IronIsland_EventScript_TryRemoveLucario
	end

IronIsland_EventScript_TryRemoveLucario::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_LUCARIO
	return

IronIsland_EventScript_Lucario::
	lock
	faceplayer
	playmoncry SPECIES_LUCARIO, CRY_MODE_ENCOUNTER
	waitmoncry
	delay 20
	settotemboost 1, 1, 1, 1, 1, 1
	setwildbattle SPECIES_LUCARIO, 40
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, IronIsland_EventScript_DefeatedLucario
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, IronIsland_EventScript_RanFromLucario
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, IronIsland_EventScript_RanFromLucario
	setflag FLAG_CAUGHT_LUCARIO
	goto IronIsland_EventScript_LucarioLeftItem
	release
	end

IronIsland_EventScript_DefeatedLucario::
	setflag FLAG_DEFEATED_LUCARIO
	setvar VAR_0x8004, SPECIES_LUCARIO
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	goto IronIsland_EventScript_WarpBack
	release
	end

IronIsland_EventScript_RanFromLucario::
	setvar VAR_0x8004, SPECIES_LUCARIO
	release
	end

IronIsland_EventScript_LucarioLeftItem::
	msgbox IronIsland_Text_LucarioLeftItem, MSGBOX_DEFAULT
	giveitem ITEM_LUCARIONITE, 1
	goto IronIsland_EventScript_WarpBack
	release
	end

IronIsland_Text_LucarioLeftItem:
	.string "Lucario left behind an item.$"

IronIsland_EventScript_WarpBack::
	setflag FLAG_DAY_4_COMPLETE
	setflag FLAG_CAN_SLEEP
	warpteleport MAP_LUMIOUR_ISLAND, 47, 29
	release
	end
