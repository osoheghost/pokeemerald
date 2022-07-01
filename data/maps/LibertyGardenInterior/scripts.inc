.set LOCALID_WOMAN, 1
.set LOCALID_BOY, 2
.set LOCALID_CAMPER, 3
.set LOCALID_GENTELMAN, 4
.set LOCALID_LASS, 5

LibertyGardenInterior_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LibertyGardenInterior_OnFrame
	.byte 0

LibertyGardenInterior_OnFrame::
	map_script_2 VAR_LIBERTY_GARDEN_TRAINERS, 10, LibertyGardenInterior_EventScript_TrainerSequence
	.2byte 0

LibertyGardenInterior_EventScript_TrainerSequence::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, LibertyGardenInterior_Movement_Player1
	waitmovement 0
	applymovement LOCALID_CAMPER, LibertyGardenInterior_Movement_Camper1
	waitmovement 0
	msgbox LibertyGardenInterior_Text_WhatDoYouMean, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_IVAN, LibertyGardenInterior_Text_CamperDefeat
	applymovement LOCALID_CAMPER, LibertyGardenInterior_Movement_CamperLeave
	waitmovement 0
	playse SE_DOOR
	removeobject LOCALID_CAMPER

	applymovement LOCALID_BOY, LibertyGardenInterior_Movement_Boy1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	msgbox LibertyGardenInterior_Text_ImScared, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_CLAUDE, LibertyGardenInterior_Text_KidDefeat
	applymovement LOCALID_BOY, LibertyGardenInterior_Movement_KidLeave
	waitmovement 0
	playse SE_DOOR
	removeobject LOCALID_BOY

	applymovement LOCALID_GENTELMAN, LibertyGardenInterior_Movement_Gentelman1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	msgbox LibertyGardenInterior_Text_ItsTradition, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_ELLIOT_1, LibertyGardenInterior_Text_GentelmanDefeat
	applymovement LOCALID_GENTELMAN, LibertyGardenInterior_Movement_GentelmanLeave
	waitmovement 0
	playse SE_DOOR
	removeobject LOCALID_GENTELMAN

	applymovement LOCALID_WOMAN, LibertyGardenInterior_Movement_Woman1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	msgbox LibertyGardenInterior_Text_IJustWanted, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_NED, LibertyGardenInterior_Text_AromaLadyDefeat
	applymovement LOCALID_WOMAN, LibertyGardenInterior_Movement_AromaLadyLeave
	waitmovement 0
	playse SE_DOOR
	removeobject LOCALID_WOMAN

	applymovement LOCALID_LASS, LibertyGardenInterior_Movement_Lass1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	msgbox LibertyGardenInterior_Text_IHaveNo, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_DALE, LibertyGardenInterior_Text_LassDefeat
	setvar VAR_LIBERTY_GARDEN_TRAINERS, 5
	applymovement LOCALID_LASS, LibertyGardenInterior_Movement_LassLeave
	waitmovement 0
	playse SE_DOOR
	removeobject LOCALID_LASS
	setflag FLAG_LIBERTY_LASS
	setflag FLAG_LIBERTY_AROMA_LADY
	setflag FLAG_LIBERTY_GENTELMAN
	setflag FLAG_LIBERTY_BOY
	setflag FLAG_LIBERTY_CAMPER
	setflag FLAG_DAY_5_COMPLETE
	release
	end

LibertyGardenInterior_Text_LassDefeat:
	.string "That was a fun battle!\p"
	.string "I'll get to safety now!$"

LibertyGardenInterior_Text_IHaveNo:
	.string "{COLOR RED}I have no idea what's going on.\p"
	.string "I guess we can have a Pokémon battle.$"

LibertyGardenInterior_Movement_Lass1:
	walk_down
	walk_down
	walk_left
	step_end

LibertyGardenInterior_Movement_LassLeave:
	Walk_down
	walk_left
	face_down
	step_end

LibertyGardenInterior_Movement_AromaLadyLeave:
	Walk_down
	walk_right
	face_down
	step_end

LibertyGardenInterior_Text_AromaLadyDefeat:
	.string "This has officially been the worst\n"
	.string "vacation ever.$"

LibertyGardenInterior_Text_IJustWanted:
	.string "{COLOR RED}I just wanted to go on a fun trip to\n"
	.string "Liberty Garden…$"

LibertyGardenInterior_Movement_Woman1:	
	walk_down
	walk_down
	walk_right
	step_end

LibertyGardenInterior_Movement_GentelmanLeave:
	Walk_down
	walk_left
	face_down
	step_end

LibertyGardenInterior_Text_GentelmanDefeat:
	.string "Alright, I admit defeat.\p"
	.string "Liberty Garden could dissapear\n"
	.string "at any moment you say?\p"
	.string "Well why didn't you say something\n"
	.string "earlier?$"

LibertyGardenInterior_Text_ItsTradition:
	.string "{COLOR BLUE}Its tradition to have a Pokémon\n"
	.string "battle to settle a dissagreement.$"

LibertyGardenInterior_Movement_Gentelman1:
	walk_down
	walk_down
	face_left
	step_end

LibertyGardenInterior_Text_ImScared:
	.string "{COLOR BLUE}I'm a little scared the island might\n"
	.string "dissapear.\p"
	.string "Maybe a Pokémon battle will help get\n"
	.string "my mind off it!$"

LibertyGardenInterior_Text_KidDefeat:
	.string "Nope, I'm still scared.$"

LibertyGardenInterior_Movement_KidLeave:
	Walk_down
	walk_right
	face_down
	step_end

LibertyGardenInterior_Movement_Boy1:
	walk_down
	walk_down
	face_right
	step_end

LibertyGardenInterior_Movement_Player1:
	walk_up
	step_end

LibertyGardenInterior_Movement_Camper1:
	walk_down
	step_end

LibertyGardenInterior_Movement_CamperLeave:
	walk_left
	walk_down
	Walk_down
	walk_right
	face_down
	step_end

LibertyGardenInterior_Text_WhatDoYouMean:
	.string	"{COLOR BLUE}What do you mean this island could\n"
	.string "dissapear at any moment?\p"
	.string "I just want to battle!$"

LibertyGardenInterior_Text_CamperDefeat:
	.string "Wait, you're being serious?\p"
	.string "I gotta get outta here!$"

LibertyGardenInterior_EventScript_TV::
	lock
	msgbox LibertyGardenInterior_Text_TVBroken, MSGBOX_DEFAULT
	release
	end

LibertyGardenInterior_Text_TVBroken:
	.string "The TV is very old and broken.$"
