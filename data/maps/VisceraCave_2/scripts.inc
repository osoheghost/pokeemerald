VisceraCave_2_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, VisceraCave2_OnFrame
	.byte 0


VisceraCave2_OnFrame::
	map_script_2 VAR_PALKIA_SEQUENCE_STATE, 7, VisceraCave2_EventScript_PalkiaFight
	.2byte 0

VisceraCave2_EventScript_PalkiaFight::
	lock
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitse
	playmoncry SPECIES_PALKIA, CRY_MODE_NORMAL
	waitmoncry
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitse
	waitmovement 0
	setvar VAR_PALKIA_SEQUENCE_STATE, 8
	warpsilent MAP_VISCERA_CAVE3, 10, 49
	delay 48
	release
	end
