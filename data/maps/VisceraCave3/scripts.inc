VisceraCave3_MapScripts::
	.byte 0

VisceraCave_3_EventScript_Palkia::
	lock
	faceplayer
	waitse
	delay 20
	playse SE_THUNDERSTORM_STOP
	setvar VAR_0x8004, 0  @ vertical pan
	setvar VAR_0x8005, 3  @ horizontal pan
	setvar VAR_0x8006, 4  @ num shakes
	setvar VAR_0x8007, 2  @ shake delay
	special ShakeCamera
	delay 30
	playse SE_THUNDERSTORM_STOP
	setvar VAR_0x8004, 0  @ vertical pan
	setvar VAR_0x8005, 3  @ horizontal pan
	setvar VAR_0x8006, 4  @ num shakes
	setvar VAR_0x8007, 2  @ shake delay
	special ShakeCamera
	delay 30
	delay 50
	waitse
	playmoncry SPECIES_PALKIA, CRY_MODE_ENCOUNTER
	waitmoncry
	delay 20
	seteventmon SPECIES_PALKIA, 45
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, VisceraCave_3_EventScript_DefeatedPalkia
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, VisceraCave_3_EventScript_RanFromPalkia
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, VisceraCave_3_EventScript_RanFromPalkia
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, VisceraCave_3_EventScript_DefeatedPalkia
	release
	end

VisceraCave_3_EventScript_DefeatedPalkia::
	setflag FLAG_PALKIA
	setvar VAR_0x8004, SPECIES_PALKIA
	goto VisceraCave_3_EventScript_EndScene
	end

VisceraCave_3_EventScript_RanFromPalkia::
	end

VisceraCave_3_EventScript_EndScene::
	setflag FLAG_GAME_COMPLETE
	warpteleport MAP_LUMIOUR_LAB_B1, 4, 4
	end
