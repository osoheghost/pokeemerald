.set LOCALID_BOULDER1, 1
.set LOCALID_BOULDER2, 2
.set LOCALID_BOULDER3, 3
.set LOCALID_BOULDER4, 4
.set LOCALID_METAL_COAT, 5
.set LOCALID_PROF_CYGNUS, 6
.set LOCALID_LIECHI_BERRY, 7
.set LOCALID_FLAMETHROWER, 16
.set LOCALID_SAILOR, 17
.set LOCALID_WOMAN, 18
.set LOCALID_LASS, 19
.set LOCALID_AROMA_LADY, 20
.set LOCALID_CAMPER, 21
.set LOCALID_LITTLE_BOY, 22
.set LOCALID_GENTELMAN, 23
.set LOCALID_BEAUTY, 24
.set LOCALID_BRENDAN, 25
.set LOCALID_MAY, 26

LumiourIsland_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, LumiourIsland_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LumiourIsland_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LumiereIsland_OnFrame
	.byte 0

LumiereIsland_OnFrame::
	map_script_2 VAR_LIBERTY_GARDEN_TRAINERS, 5, LumiereIsland_EventScript_Day5EndScene
	.2byte 0

LumiourIsland_OnWarp:
	map_script_2 VAR_LUMIOUR_ISLAND_STATE, 1, LumiourIsland_EventScript_SetMetalCoatLocation
	map_script_2 VAR_LUMIOUR_ISLAND_STATE, 3, LumiourIsland_EventScript_SetLiechiLocation
	map_script_2 VAR_LUMIOUR_ISLAND_STATE, 4, LumiourIsland_EventScript_SetFlamethrowerLocation
	map_script_2 VAR_LUMIOUR_ISLAND_STATE, 5, LumiourIsland_EventScript_SetLibertyGardenOWS
	map_script_2 VAR_PALKIA_SEQUENCE_STATE, 3 LumiereIsland_EventScript_SetVisceraCaveClosed
	.2byte 0

LumiourIsland_EventScript_SetLibertyGardenOWS::
	goto_if_set FLAG_DAY_5_COMPLETE LumiereIsland_EventScript_SetLibertyGardenOWs2
	setobjectxyperm LOCALID_SAILOR, 42, 46
	setobjectxyperm LOCALID_WOMAN, 40, 53
	setobjectxyperm LOCALID_BEAUTY, 55, 52
	setvar VAR_LIBERTY_GARDEN_TRAINERS, 10
	end

LumiereIsland_EventScript_SetLibertyGardenOWs2::
	setobjectxyperm LOCALID_SAILOR, 46, 31
	setobjectxyperm LOCALID_WOMAN, 18, 26
	setobjectxyperm LOCALID_BEAUTY, 60, 20
	setobjectxyperm LOCALID_LASS, 43, 15
	setobjectxyperm LOCALID_AROMA_LADY, 10, 20
	setobjectxyperm LOCALID_CAMPER, 37, 7
	setobjectxyperm LOCALID_LITTLE_BOY, 36, 26
	setobjectxyperm LOCALID_GENTELMAN, 62, 10
	end

LumiourIsland_EventScript_SetFlamethrowerLocation::
	setobjectxyperm LOCALID_FLAMETHROWER, 58, 53
	end

LumiourIsland_EventScript_SetLiechiLocation::
	setobjectxyperm LOCALID_LIECHI_BERRY, 62, 51
	setvar VAR_MIRAGE_ISLAND_BATTLE, 1
	end

LumiourIsland_EventScript_SetMetalCoatLocation::
	setobjectxyperm LOCALID_BOULDER1, 18, 28
	setobjectxyperm LOCALID_METAL_COAT, 50, 58
	goto_if_set FLAG_DAY_1_COMPLETE LumiereIsland_EventScript_HideBoulder
	end
	
LumiereIsland_EventScript_HideBoulder::
	setobjectxyperm LOCALID_BOULDER1, 79, 41
	end

LumiourIsland_OnLoad:
	goto_if_eq VAR_PALKIA_SEQUENCE_STATE, 3 LumiereIsland_EventScript_SetVisceraCaveClosed
	goto_if_eq VAR_PALKIA_SEQUENCE_STATE, 4 LumiereIsland_EventScript_PalkiaTiles4
	goto_if_eq VAR_PALKIA_SEQUENCE_STATE, 5 LumiereIsland_EventScript_PalkiaTiles5
	goto_if_eq VAR_PALKIA_SEQUENCE_STATE, 6 LumiereIsland_EventScript_PalkiaTiles6
	goto_if_eq VAR_PALKIA_SEQUENCE_STATE, 7 LumiereIsland_EventScript_PalkiaTiles7
	goto_if_eq VAR_LUMIOUR_ISLAND_STATE, 1, LumiourIsland_EventScript_SetMemorialPillar
	goto_if_eq VAR_LUMIOUR_ISLAND_STATE, 2, LumiourIsland_EventScript_SetWhirlIsland
	goto_if_eq VAR_LUMIOUR_ISLAND_STATE, 3, LumiourIsland_EventScript_SetMirageIsland
	goto_if_eq VAR_LUMIOUR_ISLAND_STATE, 4, LumiourIsland_EventScript_SetIronIsland
	goto_if_eq VAR_LUMIOUR_ISLAND_STATE, 5, LumiourIsland_EventScript_SetLibertyIsland
	goto_if_eq VAR_LUMIOUR_ISLAND_STATE, 6, LumiourIsland_EventScript_SetDay6tiles
	end

LumiourIsland_EventScript_SetDay6tiles:
	goto_if_eq VAR_PALKIA_SEQUENCE_STATE, 0, LumiereIsland_EventScript_SetPalkiaSequenceVar
	end

LumiereIsland_EventScript_SetPalkiaSequenceVar::
	setvar VAR_PALKIA_SEQUENCE_STATE, 1
	end

LumiourIsland_Trigger_Strength_Button1::
	lockall
	setvar VAR_STRENGTH_TRIGGER, 100
	setobjectxyperm LOCALID_BOULDER1, 15, 28
	hideobjectat LOCALID_BOULDER2, MAP_LUMIOUR_ISLAND
	setobjectxyperm LOCALID_BOULDER2, 61, 27
	setmetatile 61, 31, METATILE_General_GrassMarking, FALSE
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_QuestionMark
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	setvar VAR_0x8004, 61  @ x
	setvar VAR_0x8005, 27  @ y
	fadescreenswapbuffers FADE_TO_BLACK
	special TeleportCamera
	applymovement LOCALID_BOULDER2, Common_Movement_SetInvisible
	fadescreenswapbuffers FADE_FROM_BLACK
	delay 48
	applymovement LOCALID_BOULDER2, Movement_KecleonAppears
	delay 48
	delay 48
	delay 48
	fadescreenswapbuffers FADE_TO_BLACK
	special ReturnCameraToPlayer
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

LumiourIsland_Trigger_Strength_Button2::
	lockall
	setvar VAR_STRENGTH_TRIGGER, 100
	setobjectxyperm LOCALID_BOULDER2, 61, 31
	hideobjectat LOCALID_BOULDER3, MAP_LUMIOUR_ISLAND
	setobjectxyperm LOCALID_BOULDER3, 33, 10
	setmetatile 37, 7, METATILE_General_GrassMarking, FALSE
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_QuestionMark
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	setvar VAR_0x8004, 33  @ x
	setvar VAR_0x8005, 10  @ y
	fadescreenswapbuffers FADE_TO_BLACK
	special TeleportCamera
	applymovement LOCALID_BOULDER3, Common_Movement_SetInvisible
	fadescreenswapbuffers FADE_FROM_BLACK
	delay 48
	applymovement LOCALID_BOULDER3, Movement_KecleonAppears
	delay 48
	delay 48
	delay 48
	fadescreenswapbuffers FADE_TO_BLACK
	special ReturnCameraToPlayer
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

LumiourIsland_Trigger_Strength_Button3::
	lockall
	setmetatile 53, 55, METATILE_General_GrassMarking, FALSE
	setvar VAR_STRENGTH_TRIGGER, 100
	setobjectxyperm LOCALID_BOULDER3, 37, 7
	hideobjectat LOCALID_BOULDER4, MAP_LUMIOUR_ISLAND
	setobjectxyperm LOCALID_BOULDER4, 48, 35
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_QuestionMark
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	setvar VAR_0x8004, 48  @ x
	setvar VAR_0x8005, 35  @ y
	fadescreenswapbuffers FADE_TO_BLACK
	special TeleportCamera
	applymovement LOCALID_BOULDER4, Common_Movement_SetInvisible
	fadescreenswapbuffers FADE_FROM_BLACK
	delay 48
	applymovement LOCALID_BOULDER4, Movement_KecleonAppears
	delay 48
	delay 48
	delay 48
	fadescreenswapbuffers FADE_TO_BLACK
	special ReturnCameraToPlayer
	fadescreenswapbuffers FADE_FROM_BLACK
	setflag FLAG_FALSE_MARKING
	release
	end

LumiourIsland_Trigger_Strength_Button4::
	lockall
	setobjectxyperm LOCALID_BOULDER4, 37, 7
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitse
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitse
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Movement_KecleonAppears
	waitmovement 0
	playse SE_WARP_OUT
	fadescreenswapbuffers FADE_TO_BLACK
	setobjectxy OBJ_EVENT_ID_PLAYER, 47, 28
	setvar VAR_0x8004, 47  @ x
	setvar VAR_0x8005, 28  @ y
	special TeleportCamera
	setflag FLAG_DAY_1_COMPLETE
	fadescreenswapbuffers FADE_FROM_BLACK
	setmetatile 47, 32, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 48, 32, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 49, 32, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 47, 33, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 48, 33, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 49, 33, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 47, 34, METATILE_General_CalmWater, TRUE
	setmetatile 48, 34, METATILE_General_CalmWater, TRUE
	setmetatile 49, 34, METATILE_General_CalmWater, TRUE
	setmetatile 47, 35, METATILE_General_CalmWater, TRUE
	setmetatile 48, 35, METATILE_General_CalmWater, TRUE
	setmetatile 49, 35, METATILE_General_CalmWater, TRUE
	setmetatile 47, 36, METATILE_General_CalmWater, TRUE
	setmetatile 48, 36, METATILE_General_CalmWater, TRUE
	setmetatile 49, 36, METATILE_General_CalmWater, TRUE
	special DrawWholeMapView
	setobjectxyperm LOCALID_PROF_CYGNUS, 39, 28
	addobject LOCALID_PROF_CYGNUS
	goto LumiourIsland_EventScript_Day1PuzzleEnd
	setvar VAR_ENCOUNTER_STATE, 0
	setvar VAR_LUMIOUR_WILD_SET, 0
	end

LumiourIsland_Text_Strength:
	.string "Strength$"

LumiourIsland_EventScript_Day1PuzzleEnd:
	applymovement OBJ_EVENT_ID_PLAYER, Movement_KecleonAppears
	waitmovement 0
	applymovement LOCALID_PROF_CYGNUS, LumiourIsland_Movement_WalkOnScreen
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	msgbox LumiourIsland_Text_CygnusHeardTremor, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PROF_CYGNUS, Common_Movement_FaceDown
	waitmovement 0
	delay 48
	applymovement LOCALID_PROF_CYGNUS, Common_Movement_FaceRight
	waitmovement 0
	msgbox LumiourIsland_Text_CygnusComeBackToLab, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PROF_CYGNUS, LumiourIsland_Movement_WalkOffScreen
	waitmovement 0
	removeobject LOCALID_PROF_CYGNUS
	setflag FLAG_HIDE_CYGNUS_OUTDOOR_LUMIOUR
	setflag FLAG_CAN_SLEEP
	release
	end

LumiourIsland_Text_CygnusHeardTremor:
	.string "{COLOR BLUE}{PLAYER}, I'm glad you're safe!\p"
	.string "I felt a tremor just now and came running\n"
	.string "to check on you.$"

LumiourIsland_Text_CygnusComeBackToLab:
	.string "{COLOR BLUE}And the island… It's dissapeared…\p"
	.string "Come back to the lab and we can\n"
	.string "discuss this more.$"

LumiourIsland_EventScript_End:
	end

LumiourIsland_Movement_WalkOnScreen:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

LumiourIsland_Movement_WalkOffScreen:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

LumiourIsland_EventScript_SetMemorialPillar::
	setvar VAR_ENCOUNTER_STATE, 0
	setvar VAR_LUMIOUR_WILD_SET, 0
	goto_if_set FLAG_DAY_1_COMPLETE, LumiourIsland_EventScript_End
	setmetatile 44, 44, METATILE_General_WaterCliffTL, TRUE
	setmetatile 45, 44, METATILE_General_WaterCliffT, TRUE
	setmetatile 46, 44, METATILE_General_WaterCliffT, TRUE
	setmetatile 50, 44, METATILE_General_WaterCliffT, TRUE
	setmetatile 51, 44, METATILE_General_WaterCliffT, TRUE
	setmetatile 52, 44, METATILE_General_WaterCliffT, TRUE
	setmetatile 53, 44, METATILE_General_WaterCliffTR, TRUE
	setmetatile 42, 45, METATILE_General_WaterCliffTL, TRUE
	setmetatile 43, 45, METATILE_General_WaterCliffT, TRUE
	setmetatile 44, 45, METATILE_General_CliffVertexTL, TRUE
	setmetatile 45, 45, METATILE_General_RockRockCliffTL, TRUE
	setmetatile 46, 45, METATILE_General_GrassThinRockL, FALSE
	setmetatile 47, 45, METATILE_General_GrassThinRock, FALSE
	setmetatile 48, 45, METATILE_General_GrassThinRock, FALSE
	setmetatile 49, 45, METATILE_General_GrassThinRock, FALSE
	setmetatile 50, 45, METATILE_General_GrassThinRock, FALSE
	setmetatile 51, 45, METATILE_General_GrassThinRockR, FALSE
	setmetatile 52, 45, METATILE_General_RockRockCliffTR, TRUE
	setmetatile 53, 45, METATILE_General_CliffVertexTR, TRUE
	setmetatile 54, 45, METATILE_General_WaterCliffT, TRUE
	setmetatile 55, 45, METATILE_General_WaterCliffTR, TRUE
	setmetatile 41, 46, METATILE_General_ShallowWaterCornerTL, TRUE
	setmetatile 42, 46, METATILE_Petalburg_HalfSWCliffL, TRUE
	setmetatile 43, 46, METATILE_General_RockRockCliffTL, TRUE
	setmetatile 44, 46, METATILE_General_GrassThinRockL, FALSE
	setmetatile 45, 46, METATILE_General_GrassThinRock, FALSE
	setmetatile 46, 46, METATILE_General_Grass3, FALSE
	setmetatile 47, 46, METATILE_General_Grass4, FALSE
	setmetatile 48, 46, METATILE_General_Grass3, FALSE
	setmetatile 49, 46, METATILE_General_Grass4, FALSE
	setmetatile 50, 46, METATILE_General_Grass3, FALSE
	setmetatile 51, 46, METATILE_General_Grass4, FALSE
	setmetatile 52, 46, METATILE_General_GrassThinRock, FALSE
	setmetatile 53, 46, METATILE_General_GrassThinRockR, FALSE
	setmetatile 54, 46, METATILE_General_RockRockCliffTR, TRUE
	setmetatile 55, 46, METATILE_Petalburg_HalfSWCliffR, TRUE
	setmetatile 56, 46, METATILE_General_ShallowWaterCornerTR, TRUE
	setmetatile 41, 47, METATILE_General_ShallowWaterEdgeL, TRUE
	setmetatile 42, 47, METATILE_General_SWCliffL, TRUE
	setmetatile 43, 47, METATILE_General_RockRockCliffL, TRUE
	setmetatile 44, 47, METATILE_General_TallGrass, FALSE
	setmetatile 45, 47, METATILE_General_RockGrass, TRUE
	setmetatile 46, 47, METATILE_General_Grass1, FALSE
	setmetatile 47, 47, METATILE_General_FlowerBlue, FALSE
	setmetatile 48, 47, METATILE_Petalburg_MP1, FALSE
	setmetatile 49, 47, METATILE_Petalburg_MP2, FALSE
	setmetatile 50, 47, METATILE_General_FlowerBlue, FALSE
	setmetatile 51, 47, METATILE_General_Grass2, FALSE
	setmetatile 52, 47, METATILE_General_Grass1, FALSE
	setmetatile 53, 47, METATILE_General_TallGrass, FALSE
	setmetatile 54, 47, METATILE_General_RockRockCliffR, TRUE
	setmetatile 55, 47, METATILE_General_SWCliffR, TRUE
	setmetatile 56, 47, METATILE_General_ShallowWaterEdgeR, TRUE
	setmetatile 41, 48, METATILE_General_ShallowWaterEdgeL, TRUE
	setmetatile 42, 48, METATILE_General_SWCliffL, TRUE
	setmetatile 43, 48, METATILE_General_RockRockCliffL, TRUE
	setmetatile 44, 48, METATILE_General_TallGrass, FALSE
	setmetatile 45, 48, METATILE_General_TallGrass, FALSE
	setmetatile 46, 48, METATILE_General_FlowerBlue, FALSE
	setmetatile 47, 48, METATILE_General_DirtPathTL, FALSE
	setmetatile 48, 48, METATILE_Petalburg_MP3, FALSE
	setmetatile 49, 48, METATILE_Petalburg_MP4, FALSE
	setmetatile 50, 48, METATILE_General_DirtPathTR, FALSE
	setmetatile 51, 48, METATILE_General_FlowerBlue, FALSE
	setmetatile 52, 48, METATILE_General_TallGrass, FALSE
	setmetatile 53, 48, METATILE_General_TallGrass, FALSE
	setmetatile 54, 48, METATILE_General_RockRockCliffR TRUE
	setmetatile 55, 48, METATILE_General_SWCliffR, TRUE
	setmetatile 56, 48, METATILE_General_ShallowWaterEdgeR, TRUE
	setmetatile 41, 49, METATILE_General_ShallowWaterEdgeL, TRUE
	setmetatile 42, 49, METATILE_General_SWCliffL, TRUE
	setmetatile 43, 49, METATILE_General_RockRockCliffL, TRUE
	setmetatile 44, 49, METATILE_General_TallGrass, FALSE
	setmetatile 45, 49, METATILE_General_TallGrass, FALSE
	setmetatile 46, 49, METATILE_General_TallGrass, FALSE
	setmetatile 47, 49, METATILE_General_DirtPathL, FALSE
	setmetatile 48, 49, METATILE_Petalburg_MP5, TRUE
	setmetatile 49, 49, METATILE_Petalburg_MP6, TRUE
	setmetatile 50, 49, METATILE_General_DirtPathR, FALSE
	setmetatile 51, 49, METATILE_General_TallGrass, FALSE
	setmetatile 52, 49, METATILE_General_TallGrass, FALSE
	setmetatile 53, 49, METATILE_General_TallGrass, FALSE
	setmetatile 54, 49, METATILE_General_RockRockCliffR, TRUE
	setmetatile 55, 49, METATILE_General_CliffVertexTR, TRUE
	setmetatile 56, 49, METATILE_Petalburg_VertexSWTRCliffT, TRUE
	setmetatile 57, 49, METATILE_General_WaterCliffTR, TRUE
	setmetatile 41, 50, METATILE_General_ShallowWaterEdgeL, TRUE
	setmetatile 42, 50, METATILE_General_SWCliffL, TRUE
	setmetatile 43, 50, METATILE_General_RockRockCliffL, TRUE
	setmetatile 44, 50, METATILE_General_RockGrass, TRUE
	setmetatile 45, 50, METATILE_General_TallGrass, FALSE
	setmetatile 46, 50, METATILE_General_TallGrass, FALSE
	setmetatile 47, 50, METATILE_General_DirtPathL, FALSE
	setmetatile 48, 50, METATILE_Petalburg_MP7, TRUE
	setmetatile 49, 50, METATILE_Petalburg_MP8, TRUE
	setmetatile 50, 50, METATILE_General_DirtPathR, FALSE
	setmetatile 51, 50, METATILE_General_TallGrass, FALSE
	setmetatile 52, 50, METATILE_General_TallGrass, FALSE
	setmetatile 53, 50, METATILE_General_TallGrass, FALSE
	setmetatile 54, 50, METATILE_General_GrassThinRock, FALSE
	setmetatile 55, 50, METATILE_General_GrassThinRockR, FALSE
	setmetatile 56, 50, METATILE_General_RockRockCliffTR, TRUE
	setmetatile 57, 50, METATILE_Petalburg_HalfSWCliffR, TRUE
	setmetatile 58, 50, METATILE_General_ShallowWaterEdgeT, TRUE
	setmetatile 59, 50, METATILE_General_ShallowWaterEdgeT, TRUE
	setmetatile 60, 50, METATILE_General_ShallowWaterCornerTR, TRUE
	setmetatile 41, 51, METATILE_General_ShallowWaterEdgeL, TRUE
	setmetatile 42, 51, METATILE_General_SWCliffL, TRUE
	setmetatile 43, 51, METATILE_General_RockRockCliffL, TRUE
	setmetatile 44, 51, METATILE_General_TallGrass, FALSE
	setmetatile 45, 51, METATILE_General_TallGrass, FALSE
	setmetatile 46, 51, METATILE_General_TallGrass, FALSE
	setmetatile 47, 51, METATILE_General_DirtPathBL, FALSE
	setmetatile 48, 51, METATILE_General_DirtPathB, FALSE
	setmetatile 49, 51, METATILE_General_DirtPathB, FALSE
	setmetatile 50, 51, METATILE_General_DirtPathBR, FALSE
	setmetatile 51, 51, METATILE_General_TallGrass, FALSE
	setmetatile 52, 51, METATILE_General_TallGrass, FALSE
	setmetatile 53, 51, METATILE_General_TallGrass, FALSE
	setmetatile 54, 51, METATILE_General_TallGrass, FALSE
	setmetatile 55, 51, METATILE_General_RockGrass, TRUE
	setmetatile 56, 51, METATILE_General_RockRockCliffR, TRUE
	setmetatile 57, 51, METATILE_General_SWCliffR, TRUE
	setmetatile 58, 51, METATILE_General_ShallowWaterMid, FALSE
	setmetatile 59, 51, METATILE_General_ShallowWaterMid, FALSE
	setmetatile 60, 51, METATILE_General_ShallowWaterEdgeR, TRUE
	setmetatile 41, 52, METATILE_General_ShallowWaterEdgeL, TRUE
	setmetatile 42, 52, METATILE_General_SWCliffL, TRUE
	setmetatile 43, 52, METATILE_General_RockRockCliffL, TRUE
	setmetatile 44, 52, METATILE_General_TallGrass, FALSE
	setmetatile 45, 52, METATILE_General_Grass4, FALSE
	setmetatile 46, 52, METATILE_General_Grass3, FALSE
	setmetatile 47, 52, METATILE_General_TallGrass, FALSE
	setmetatile 48, 52, METATILE_General_TallGrass, FALSE
	setmetatile 49, 52, METATILE_General_TallGrass, FALSE
	setmetatile 50, 52, METATILE_General_TallGrass, FALSE
	setmetatile 51, 52, METATILE_General_TallGrass, FALSE
	setmetatile 52, 52, METATILE_General_Grass4, FALSE
	setmetatile 53, 52, METATILE_General_Grass3, FALSE
	setmetatile 54, 52, METATILE_General_TallGrass, FALSE
	setmetatile 55, 52, METATILE_General_TallGrass, FALSE
	setmetatile 56, 52, METATILE_General_RockRockCliffR, TRUE
	setmetatile 57, 52, METATILE_General_SWCliffR, TRUE
	setmetatile 58, 52, METATILE_General_ShallowWaterMid, FALSE
	setmetatile 59, 52, METATILE_General_ShallowWaterMid, FALSE
	setmetatile 60, 52, METATILE_General_ShallowWaterEdgeR, TRUE
	setmetatile 41, 53, METATILE_General_ShallowWaterEdgeL, TRUE
	setmetatile 42, 53, METATILE_General_SWCliffL, TRUE
	setmetatile 43, 53, METATILE_General_RockGrassCliffBL, TRUE
	setmetatile 44, 53, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 45, 53, METATILE_General_StairsShade, FALSE
	setmetatile 46, 53, METATILE_General_Stairs, FALSE
	setmetatile 47, 53, METATILE_General_CliffVertexBL, TRUE
	setmetatile 48, 53, METATILE_General_TallGrass, FALSE
	setmetatile 49, 53, METATILE_General_TallGrass, FALSE
	setmetatile 50, 53, METATILE_General_TallGrass, FALSE
	setmetatile 51, 53, METATILE_General_CliffVertexBR, TRUE
	setmetatile 52, 53, METATILE_General_StairsShade, FALSE
	setmetatile 53, 53, METATILE_General_Stairs, FALSE
	setmetatile 54, 53, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 55, 53, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 56, 53, METATILE_General_RockGrassCliffBR, TRUE
	setmetatile 57, 53, METATILE_General_SWCliffR, TRUE
	setmetatile 58, 53, METATILE_General_ShallowWaterMid, FALSE
	setmetatile 59, 53, METATILE_General_ShallowWaterMid, FALSE
	setmetatile 60, 53, METATILE_General_ShallowWaterEdgeR, TRUE
	setmetatile 41, 54, METATILE_General_ShallowWaterEdgeL, TRUE
	setmetatile 42, 54, METATILE_General_SWCliffL, TRUE
	setmetatile 43, 54, METATILE_General_RockGrass, TRUE
	setmetatile 44, 54, METATILE_General_Grass2, FALSE
	setmetatile 45, 54, METATILE_General_Grass1, FALSE
	setmetatile 46, 54, METATILE_General_Grass2, FALSE
	setmetatile 47, 54, METATILE_General_RockGrassCliffBL, TRUE
	setmetatile 48, 54, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 49, 54, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 50, 54, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 51, 54, METATILE_General_RockGrassCliffBR, TRUE
	setmetatile 52, 54, METATILE_General_Grass3, FALSE
	setmetatile 53, 54, METATILE_General_Grass4, FALSE
	setmetatile 54, 54, METATILE_General_Grass3, FALSE
	setmetatile 55, 54, METATILE_General_TallGrass, FALSE
	setmetatile 56, 54, METATILE_General_TallGrass, FALSE
	setmetatile 57, 54, METATILE_General_SWCliffR, TRUE
	setmetatile 58, 54, METATILE_General_ShallowWaterMid, FALSE
	setmetatile 59, 54, METATILE_General_ShallowWaterMid, FALSE
	setmetatile 60, 54, METATILE_General_ShallowWaterEdgeR, TRUE
	setmetatile 40, 55, METATILE_General_ShallowWaterCornerTL, TRUE
	setmetatile 41, 55, METATILE_General_ShallowWaterVertexTL, TRUE
	setmetatile 42, 55, METATILE_General_SWCliffBL, TRUE
	setmetatile 43, 55, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 44, 55, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 45, 55, METATILE_General_StairsShade, FALSE
	setmetatile 46, 55, METATILE_General_Stairs, FALSE
	setmetatile 47, 55, METATILE_General_CliffVertexBL, TRUE
	setmetatile 48, 55, METATILE_General_RockGrass, TRUE
	setmetatile 49, 55, METATILE_General_TallGrass, FALSE
	setmetatile 50, 55, METATILE_General_TallGrass, FALSE
	setmetatile 51, 55, METATILE_General_TallGrass, FALSE
	setmetatile 52, 55, METATILE_General_TallGrass, FALSE
	setmetatile 53, 55, METATILE_General_Grass2, FALSE
	setmetatile 54, 55, METATILE_General_Grass1, FALSE
	setmetatile 55, 55, METATILE_General_Grass2, FALSE
	setmetatile 56, 55, METATILE_General_Grass1, FALSE
	setmetatile 57, 55, METATILE_General_SWCliffR, TRUE
	setmetatile 58, 55, METATILE_General_ShallowWaterMid, FALSE
	setmetatile 59, 55, METATILE_General_ShallowWaterMid, FALSE
	setmetatile 60, 55, METATILE_General_ShallowWaterEdgeR, TRUE
	setmetatile 40, 56, METATILE_General_ShallowWaterEdgeL, TRUE
	setmetatile 41, 56, METATILE_General_SWCliffTL, TRUE
	setmetatile 42, 56, METATILE_General_SWCliffT, TRUE
	setmetatile 43, 56, METATILE_General_SWCliffT, TRUE
	setmetatile 44, 56, METATILE_General_SWCliffTR TRUE
	setmetatile 45, 56, METATILE_General_ShallowWaterMid, FALSE
	setmetatile 46, 56, METATILE_General_ShallowWaterMid, FALSE
	setmetatile 47, 56, METATILE_General_SWCliffL, TRUE
	setmetatile 48, 56, METATILE_General_TallGrass, FALSE
	setmetatile 49, 56, METATILE_General_TallGrass, FALSE
	setmetatile 50, 56, METATILE_General_TallGrass, FALSE
	setmetatile 51, 56, METATILE_General_TallGrass, FALSE
	setmetatile 52, 56, METATILE_General_TallGrass, FALSE
	setmetatile 53, 56, METATILE_General_TallGrass, FALSE
	setmetatile 54, 56, METATILE_General_CliffVertexBR, TRUE
	setmetatile 55, 56, METATILE_General_StairsShade, FALSE
	setmetatile 56, 56, METATILE_General_Stairs, FALSE
	setmetatile 57, 56, METATILE_General_SWCliffBR, TRUE
	setmetatile 58, 56, METATILE_General_ShallowWaterMid, FALSE
	setmetatile 59, 56, METATILE_General_ShallowWaterMid, FALSE
	setmetatile 60, 56, METATILE_General_ShallowWaterEdgeR, TRUE
	setmetatile 40, 57, METATILE_General_ShallowWaterEdgeL, TRUE
	setmetatile 41, 57, METATILE_General_SWCliffL, TRUE
	setmetatile 42, 57, METATILE_General_CliffM, TRUE
	setmetatile 43, 57, METATILE_General_CliffM, TRUE
	setmetatile 44, 57, METATILE_General_SWCliffR, TRUE
	setmetatile 45, 57, METATILE_General_ShallowWaterMid, FALSE
	setmetatile 46, 57, METATILE_General_ShallowWaterMid, FALSE
	setmetatile 47, 57, METATILE_General_SWCliffBL, TRUE
	setmetatile 48, 57, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 49, 57, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 50, 57, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 51, 57, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 52, 57, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 53, 57, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 54, 57, METATILE_General_SWCliffBR, TRUE
	setmetatile 55, 57, METATILE_General_ShallowWaterMid, FALSE
	setmetatile 56, 57, METATILE_General_ShallowWaterMid, FALSE
	setmetatile 57, 57, METATILE_General_ShallowWaterMid, FALSE
	setmetatile 58, 57, METATILE_General_ShallowWaterMid, FALSE
	setmetatile 59, 57, METATILE_General_ShallowWaterMid, FALSE
	setmetatile 60, 57, METATILE_General_ShallowWaterEdgeR, TRUE
	setmetatile 40, 58, METATILE_General_ShallowWaterEdgeL, TRUE
	setmetatile 41, 58, METATILE_General_SWCliffBL, TRUE
	setmetatile 42, 58, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 43, 58, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 44, 58, METATILE_General_SWCliffBR, TRUE
	setmetatile 45, 58, METATILE_General_ShallowWaterMid, FALSE
	setmetatile 46, 58, METATILE_General_ShallowWaterMid, FALSE
	setmetatile 47, 58, METATILE_General_ShallowWaterMid, FALSE
	setmetatile 48, 58, METATILE_General_ShallowWaterMid, FALSE
	setmetatile 49, 58, METATILE_General_ShallowWaterMid, FALSE
	setmetatile 50, 58, METATILE_General_ShallowWaterMid, FALSE
	setmetatile 51, 58, METATILE_General_SWCliffTL, TRUE
	setmetatile 52, 58, METATILE_General_SWCliffT, TRUE
	setmetatile 53, 58, METATILE_General_SWCliffT, TRUE
	setmetatile 54, 58, METATILE_General_SWCliffTR, TRUE
	setmetatile 55, 58, METATILE_General_ShallowWaterMid, FALSE
	setmetatile 56, 58, METATILE_General_ShallowWaterMid, FALSE
	setmetatile 57, 58, METATILE_General_ShallowWaterMid, FALSE
	setmetatile 58, 58, METATILE_General_ShallowWaterMid, FALSE
	setmetatile 59, 58, METATILE_General_ShallowWaterMid, FALSE
	setmetatile 60, 58, METATILE_General_ShallowWaterEdgeR, TRUE
	setmetatile 40, 59, METATILE_General_ShallowWaterCornerBL, TRUE
	setmetatile 41, 59, METATILE_General_ShallowWaterEdgeB, TRUE
	setmetatile 42, 59, METATILE_General_SWRockTL, FALSE
	setmetatile 43, 59, METATILE_General_SWRockTR, FALSE
	setmetatile 44, 59, METATILE_General_ShallowWaterVertexBL, TRUE
	setmetatile 45, 59, METATILE_General_ShallowWaterMid, FALSE
	setmetatile 46, 59, METATILE_General_ShallowWaterMid, FALSE
	setmetatile 47, 59, METATILE_General_ShallowWaterMid, FALSE
	setmetatile 48, 59, METATILE_General_ShallowWaterMid, FALSE
	setmetatile 49, 59, METATILE_General_ShallowWaterMid, FALSE
	setmetatile 50, 59, METATILE_General_ShallowWaterMid, FALSE
	setmetatile 51, 59, METATILE_General_SWCliffL, TRUE
	setmetatile 52, 59, METATILE_General_CliffM, TRUE
	setmetatile 53, 59, METATILE_General_CliffM, TRUE
	setmetatile 54, 59, METATILE_General_CliffVertexTR, TRUE
	setmetatile 55, 59, METATILE_General_SWCliffTR, TRUE
	setmetatile 56, 59, METATILE_General_ShallowWaterMid, FALSE
	setmetatile 57, 59, METATILE_General_ShallowWaterMid, FALSE
	setmetatile 58, 59, METATILE_General_ShallowWaterMid, FALSE
	setmetatile 59, 59, METATILE_General_ShallowWaterMid, FALSE
	setmetatile 60, 59, METATILE_General_ShallowWaterEdgeR, TRUE
	setmetatile 42, 60, METATILE_General_WaterRockBL, TRUE
	setmetatile 43, 60, METATILE_General_WaterRockBR, TRUE
	setmetatile 44, 60, METATILE_General_ShallowWaterCornerBL, TRUE
	setmetatile 45, 60, METATILE_General_ShallowWaterEdgeB, TRUE
	setmetatile 46, 60, METATILE_General_ShallowWaterEdgeB, TRUE
	setmetatile 47, 60, METATILE_General_ShallowWaterEdgeB, TRUE
	setmetatile 48, 60, METATILE_General_ShallowWaterEdgeB, TRUE
	setmetatile 49, 60, METATILE_General_ShallowWaterEdgeB, TRUE
	setmetatile 50, 60, METATILE_General_ShallowWaterVertexBL, TRUE
	setmetatile 51, 60, METATILE_General_SWCliffBL, TRUE
	setmetatile 52, 60, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 53, 60, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 54, 60, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 55, 60, METATILE_General_SWCliffBR, TRUE
	setmetatile 56, 60, METATILE_General_ShallowWaterVertexBR, TRUE
	setmetatile 57, 60, METATILE_General_ShallowWaterEdgeB, TRUE
	setmetatile 58, 60, METATILE_General_ShallowWaterEdgeB, TRUE
	setmetatile 59, 60, METATILE_General_ShallowWaterEdgeB, TRUE
	setmetatile 60, 60, METATILE_General_ShallowWaterCornerBR, TRUE
	setmetatile 50, 61, METATILE_General_ShallowWaterCornerBL, FALSE
	setmetatile 51, 61, METATILE_General_ShallowWaterEdgeB, FALSE
	setmetatile 52, 61, METATILE_General_ShallowWaterEdgeB, FALSE
	setmetatile 53, 61, METATILE_General_SWRockTL, TRUE
	setmetatile 54, 61, METATILE_General_SWRockTR, TRUE
	setmetatile 55, 61, METATILE_General_ShallowWaterEdgeB, FALSE
	setmetatile 56, 61, METATILE_General_ShallowWaterCornerBR, FALSE
	setmetatile 41, 61, METATILE_General_WaterRockTL, TRUE
	setmetatile 42, 61, METATILE_General_WaterRockTR, TRUE
	setmetatile 41, 62, METATILE_General_WaterRockBL, TRUE
	setmetatile 42, 62, METATILE_General_WaterRockBR, TRUE
	setmetatile 43, 63, METATILE_General_WaterRockTL, TRUE
	setmetatile 44, 63, METATILE_General_WaterRockTR, TRUE
	setmetatile 43, 64, METATILE_General_WaterRockBL, TRUE
	setmetatile 44, 64, METATILE_General_WaterRockBR, TRUE
	setmetatile 45, 64, METATILE_General_WaterRockTL, TRUE
	setmetatile 46, 64, METATILE_General_WaterRockTR, TRUE
	setmetatile 45, 65, METATILE_General_WaterRockBL, TRUE
	setmetatile 46, 65, METATILE_General_WaterRockBR, TRUE
	setmetatile 47, 64, METATILE_General_WaterRockTL, TRUE
	setmetatile 48, 64, METATILE_General_WaterRockTR, TRUE
	setmetatile 47, 65, METATILE_General_WaterRockBL, TRUE
	setmetatile 48, 65, METATILE_General_WaterRockBR, TRUE
	setmetatile 49, 63, METATILE_General_WaterRockTL, TRUE
	setmetatile 50, 63, METATILE_General_WaterRockTR, TRUE
	setmetatile 49, 64, METATILE_General_WaterRockBL, TRUE
	setmetatile 50, 64, METATILE_General_WaterRockBR, TRUE
	setmetatile 51, 62, METATILE_General_WaterRockTL, TRUE
	setmetatile 52, 62, METATILE_General_WaterRockTR, TRUE
	setmetatile 51, 63, METATILE_General_WaterRockBL, TRUE
	setmetatile 52, 63, METATILE_General_WaterRockBR, TRUE
	setmetatile 53, 64, METATILE_General_WaterRockTL, TRUE
	setmetatile 54, 64, METATILE_General_WaterRockTR, TRUE
	setmetatile 53, 65, METATILE_General_WaterRockBL, TRUE
	setmetatile 54, 65, METATILE_General_WaterRockBR, TRUE
	setmetatile 53, 62, METATILE_General_WaterRockBL, TRUE
	setmetatile 54, 62, METATILE_General_WaterRockBR, TRUE
	setmetatile 55, 62, METATILE_General_WaterRockTL, TRUE
	setmetatile 56, 62, METATILE_General_WaterRockTR, TRUE
	setmetatile 55, 63, METATILE_General_WaterRockBL, TRUE
	setmetatile 56, 63, METATILE_General_WaterRockBR, TRUE
	setmetatile 57, 63, METATILE_General_WaterRockTL, TRUE
	setmetatile 58, 63, METATILE_General_WaterRockTR, TRUE
	setmetatile 57, 64, METATILE_General_WaterRockBL, TRUE
	setmetatile 58, 64, METATILE_General_WaterRockBR, TRUE
	setmetatile 58, 61, METATILE_General_WaterRockTL, TRUE
	setmetatile 59, 61, METATILE_General_WaterRockTR, TRUE
	setmetatile 58, 62, METATILE_General_WaterRockBL, TRUE
	setmetatile 59, 62, METATILE_General_WaterRockBR, TRUE
	setmetatile 60, 61, METATILE_General_WaterRockTL, TRUE
	setmetatile 61, 61, METATILE_General_WaterRockTR, TRUE
	setmetatile 60, 62, METATILE_General_WaterRockBL, TRUE
	setmetatile 61, 62, METATILE_General_WaterRockBR, TRUE
	setmetatile 62, 59, METATILE_General_WaterRockTL, TRUE
	setmetatile 63, 59, METATILE_General_WaterRockTR, TRUE
	setmetatile 62, 60, METATILE_General_WaterRockBL, TRUE
	setmetatile 63, 60, METATILE_General_WaterRockBR, TRUE
	setmetatile 63, 57, METATILE_General_WaterRockTL, TRUE
	setmetatile 64, 57, METATILE_General_WaterRockTR, TRUE
	setmetatile 63, 58, METATILE_General_WaterRockBL, TRUE
	setmetatile 64, 58, METATILE_General_WaterRockBR, TRUE
	setmetatile 63, 55, METATILE_General_WaterRockTL, TRUE
	setmetatile 64, 55, METATILE_General_WaterRockTR, TRUE
	setmetatile 63, 56, METATILE_General_WaterRockBL, TRUE
	setmetatile 64, 56, METATILE_General_WaterRockBR, TRUE
	setmetatile 62, 53, METATILE_General_WaterRockTL, TRUE
	setmetatile 63, 53, METATILE_General_WaterRockTR, TRUE
	setmetatile 62, 54, METATILE_General_WaterRockBL, TRUE
	setmetatile 63, 54, METATILE_General_WaterRockBR, TRUE
	setmetatile 63, 51, METATILE_General_WaterRockTL, TRUE
	setmetatile 64, 51, METATILE_General_WaterRockTR, TRUE
	setmetatile 63, 52, METATILE_General_WaterRockBL, TRUE
	setmetatile 64, 52, METATILE_General_WaterRockBR, TRUE
	setmetatile 62, 49, METATILE_General_WaterRockTL, TRUE
	setmetatile 63, 49, METATILE_General_WaterRockTR, TRUE
	setmetatile 62, 50, METATILE_General_WaterRockBL, TRUE
	setmetatile 63, 50, METATILE_General_WaterRockBR, TRUE
	setmetatile 61, 47, METATILE_General_WaterRockTL, TRUE
	setmetatile 62, 47, METATILE_General_WaterRockTR, TRUE
	setmetatile 61, 48, METATILE_General_WaterRockBL, TRUE
	setmetatile 62, 48, METATILE_General_WaterRockBR, TRUE
	setmetatile 63, 46, METATILE_General_WaterRockTL, TRUE
	setmetatile 64, 46, METATILE_General_WaterRockTR, TRUE
	setmetatile 63, 47, METATILE_General_WaterRockBL, TRUE
	setmetatile 64, 47, METATILE_General_WaterRockBR, TRUE
	setmetatile 62, 44, METATILE_General_WaterRockTL, TRUE
	setmetatile 63, 44, METATILE_General_WaterRockTR, TRUE
	setmetatile 62, 45, METATILE_General_WaterRockBL, TRUE
	setmetatile 63, 45, METATILE_General_WaterRockBR, TRUE
	setmetatile 63, 42, METATILE_General_WaterRockTL, TRUE
	setmetatile 64, 42, METATILE_General_WaterRockTR, TRUE
	setmetatile 63, 43, METATILE_General_WaterRockBL, TRUE
	setmetatile 64, 43, METATILE_General_WaterRockBR, TRUE
	setmetatile 64, 40, METATILE_General_WaterRockTL, TRUE
	setmetatile 65, 40, METATILE_General_WaterRockTR, TRUE
	setmetatile 64, 41, METATILE_General_WaterRockBL, TRUE
	setmetatile 65, 41, METATILE_General_WaterRockBR, TRUE
	setmetatile 47, 32, METATILE_General_BridgeLeft, FALSE
	setmetatile 47, 33, METATILE_General_BridgeLeft, FALSE
	setmetatile 47, 34, METATILE_General_BridgeLeft, FALSE
	setmetatile 47, 35, METATILE_General_BridgeLeft, FALSE
	setmetatile 47, 36, METATILE_General_BridgeLeft, FALSE
	setmetatile 47, 37, METATILE_General_BridgeLeft, FALSE
	setmetatile 47, 38, METATILE_General_BridgeLeft, FALSE
	setmetatile 47, 39, METATILE_General_BridgeLeft, FALSE
	setmetatile 47, 40, METATILE_General_BridgeLeft, FALSE
	setmetatile 47, 41, METATILE_General_BridgeLeft, FALSE
	setmetatile 47, 42, METATILE_General_BridgeLeft, FALSE
	setmetatile 47, 43, METATILE_General_BridgeLeft, FALSE
	setmetatile 47, 44, METATILE_General_BridgeLeft, FALSE
	setmetatile 48, 32, METATILE_General_BridgeHorizontalMiddle, FALSE
	setmetatile 48, 33, METATILE_General_BridgeHorizontalMiddle, FALSE
	setmetatile 48, 34, METATILE_General_BridgeHorizontalMiddle, FALSE
	setmetatile 48, 35, METATILE_General_BridgeHorizontalMiddle, FALSE
	setmetatile 48, 36, METATILE_General_BridgeHorizontalMiddle, FALSE
	setmetatile 48, 37, METATILE_General_BridgeHorizontalMiddle, FALSE
	setmetatile 48, 38, METATILE_General_BridgeHorizontalMiddle, FALSE
	setmetatile 48, 39, METATILE_General_BridgeHorizontalMiddle, FALSE
	setmetatile 48, 40, METATILE_General_BridgeHorizontalMiddle, FALSE
	setmetatile 48, 41, METATILE_General_BridgeHorizontalMiddle, FALSE
	setmetatile 48, 42, METATILE_General_BridgeHorizontalMiddle, FALSE
	setmetatile 48, 43, METATILE_General_BridgeHorizontalMiddle, FALSE
	setmetatile 48, 44, METATILE_General_BridgeHorizontalMiddle, FALSE
	setmetatile 49, 32, METATILE_General_BridgeRight, FALSE
	setmetatile 49, 33, METATILE_General_BridgeRight, FALSE
	setmetatile 49, 34, METATILE_General_BridgeRight, FALSE
	setmetatile 49, 35, METATILE_General_BridgeRight, FALSE
	setmetatile 49, 36, METATILE_General_BridgeRight, FALSE
	setmetatile 49, 37, METATILE_General_BridgeRight, FALSE
	setmetatile 49, 38, METATILE_General_BridgeRight, FALSE
	setmetatile 49, 39, METATILE_General_BridgeRight, FALSE
	setmetatile 49, 40, METATILE_General_BridgeRight, FALSE
	setmetatile 49, 41, METATILE_General_BridgeRight, FALSE
	setmetatile 49, 42, METATILE_General_BridgeRight, FALSE
	setmetatile 49, 43, METATILE_General_BridgeRight, FALSE
	setmetatile 49, 44, METATILE_General_BridgeRight, FALSE
	goto_if_set FLAG_FALSE_MARKING, LumiourIsland_EventScript_SetRealMarking
	end

LumiourIsland_EventScript_SetRealMarking::
	setmetatile 53, 55, METATILE_General_GrassMarking, FALSE
	end

LumiourIsland_EventScript_SetWhirlIsland::
	goto_if_set FLAG_DAY_2_COMPLETE LumiourIsland_EventScript_End
	setmetatile 32, 40, METATILE_General_WaterRockTL, TRUE
	setmetatile 33, 40, METATILE_General_WaterRockTR, TRUE
	setmetatile 32, 41, METATILE_General_WaterRockBL, TRUE
	setmetatile 33, 41, METATILE_General_WaterRockBR, TRUE

	setmetatile 34, 41, METATILE_General_WaterRockTL, TRUE
	setmetatile 35, 41, METATILE_General_WaterRockTR, TRUE
	setmetatile 34, 42, METATILE_General_WaterRockBL, TRUE
	setmetatile 35, 42, METATILE_General_WaterRockBR, TRUE

	setmetatile 36, 42, METATILE_General_WaterRockTL, TRUE
	setmetatile 37, 42, METATILE_General_WaterRockTR, TRUE
	setmetatile 36, 43, METATILE_General_WaterRockBL, TRUE
	setmetatile 37, 43, METATILE_General_WaterRockBR, TRUE

	setmetatile 38, 44, METATILE_General_WaterRockTL, TRUE
	setmetatile 39, 44, METATILE_General_WaterRockTR, TRUE
	setmetatile 38, 45, METATILE_General_WaterRockBL, TRUE
	setmetatile 39, 45, METATILE_General_WaterRockBR, TRUE

	setmetatile 37, 46, METATILE_General_WaterRockTL, TRUE
	setmetatile 38, 46, METATILE_General_WaterRockTR, TRUE
	setmetatile 37, 47, METATILE_General_WaterRockBL, TRUE
	setmetatile 38, 47, METATILE_General_WaterRockBR, TRUE

	setmetatile 39, 47, METATILE_General_WaterRockTL, TRUE
	setmetatile 40, 47, METATILE_General_WaterRockTR, TRUE
	setmetatile 39, 48, METATILE_General_WaterRockBL, TRUE
	setmetatile 40, 48, METATILE_General_WaterRockBR, TRUE

	setmetatile 40, 49, METATILE_General_WaterRockTL, TRUE
	setmetatile 41, 49, METATILE_General_WaterRockTR, TRUE
	setmetatile 40, 50, METATILE_General_WaterRockBL, TRUE
	setmetatile 41, 50, METATILE_General_WaterRockBR, TRUE

	setmetatile 38, 51, METATILE_General_WaterRockTL, TRUE
	setmetatile 39, 51, METATILE_General_WaterRockTR, TRUE
	setmetatile 38, 52, METATILE_General_WaterRockBL, TRUE
	setmetatile 39, 52, METATILE_General_WaterRockBR, TRUE

	setmetatile 40, 53, METATILE_General_WaterRockTL, TRUE
	setmetatile 41, 53, METATILE_General_WaterRockTR, TRUE
	setmetatile 40, 54, METATILE_General_WaterRockBL, TRUE
	setmetatile 41, 54, METATILE_General_WaterRockBR, TRUE

	setmetatile 39, 55, METATILE_General_WaterRockTL, TRUE
	setmetatile 40, 55, METATILE_General_WaterRockTR, TRUE
	setmetatile 39, 56, METATILE_General_WaterRockBL, TRUE
	setmetatile 40, 56, METATILE_General_WaterRockBR, TRUE

	setmetatile 40, 57, METATILE_General_WaterRockTL, TRUE
	setmetatile 41, 57, METATILE_General_WaterRockTR, TRUE
	setmetatile 40, 58, METATILE_General_WaterRockBL, TRUE
	setmetatile 41, 58, METATILE_General_WaterRockBR, TRUE

	setmetatile 41, 59, METATILE_General_WaterRockTL, TRUE
	setmetatile 42, 59, METATILE_General_WaterRockTR, TRUE
	setmetatile 41, 60, METATILE_General_WaterRockBL, TRUE
	setmetatile 42, 60, METATILE_General_WaterRockBR, TRUE

	setmetatile 43, 58, METATILE_General_WaterRockTL, TRUE
	setmetatile 44, 58, METATILE_General_WaterRockTR, TRUE
	setmetatile 43, 59, METATILE_General_WaterRockBL, TRUE
	setmetatile 44, 59, METATILE_General_WaterRockBR, TRUE

	setmetatile 45, 57, METATILE_General_WaterRockTL, TRUE
	setmetatile 46, 57, METATILE_General_WaterRockTR, TRUE
	setmetatile 45, 58, METATILE_General_WaterRockBL, TRUE
	setmetatile 46, 58, METATILE_General_WaterRockBR, TRUE

	setmetatile 46, 59, METATILE_General_WaterRockTL, TRUE
	setmetatile 47, 59, METATILE_General_WaterRockTR, TRUE
	setmetatile 46, 60, METATILE_General_WaterRockBL, TRUE
	setmetatile 47, 60, METATILE_General_WaterRockBR, TRUE

	setmetatile 48, 60, METATILE_General_WaterRockTL, TRUE
	setmetatile 49, 60, METATILE_General_WaterRockTR, TRUE
	setmetatile 48, 61, METATILE_General_WaterRockBL, TRUE
	setmetatile 49, 61, METATILE_General_WaterRockBR, TRUE

	setmetatile 50, 59, METATILE_General_WaterRockTL, TRUE
	setmetatile 51, 59, METATILE_General_WaterRockTR, TRUE
	setmetatile 50, 60, METATILE_General_WaterRockBL, TRUE
	setmetatile 51, 60, METATILE_General_WaterRockBR, TRUE

	setmetatile 52, 60, METATILE_General_WaterRockTL, TRUE
	setmetatile 53, 60, METATILE_General_WaterRockTR, TRUE
	setmetatile 52, 61, METATILE_General_WaterRockBL, TRUE
	setmetatile 53, 61, METATILE_General_WaterRockBR, TRUE

	setmetatile 43, 58, METATILE_General_WaterRockTL, TRUE
	setmetatile 44, 58, METATILE_General_WaterRockTR, TRUE
	setmetatile 43, 59, METATILE_General_WaterRockBL, TRUE
	setmetatile 44, 59, METATILE_General_WaterRockBR, TRUE

	setmetatile 53, 62, METATILE_General_WaterRockTL, TRUE
	setmetatile 54, 62, METATILE_General_WaterRockTR, TRUE
	setmetatile 53, 63, METATILE_General_WaterRockBL, TRUE
	setmetatile 54, 63, METATILE_General_WaterRockBR, TRUE

	setmetatile 55, 61, METATILE_General_WaterRockTL, TRUE
	setmetatile 56, 61, METATILE_General_WaterRockTR, TRUE
	setmetatile 55, 62, METATILE_General_WaterRockBL, TRUE
	setmetatile 56, 62, METATILE_General_WaterRockBR, TRUE

	setmetatile 46, 59, METATILE_General_WaterRockTL, TRUE
	setmetatile 47, 59, METATILE_General_WaterRockTR, TRUE
	setmetatile 46, 60, METATILE_General_WaterRockBL, TRUE
	setmetatile 47, 60, METATILE_General_WaterRockBR, TRUE

	setmetatile 58, 58, METATILE_General_WaterRockTL, TRUE
	setmetatile 59, 58, METATILE_General_WaterRockTR, TRUE
	setmetatile 58, 59, METATILE_General_WaterRockBL, TRUE
	setmetatile 59, 59, METATILE_General_WaterRockBR, TRUE

	setmetatile 59, 56, METATILE_General_WaterRockTL, TRUE
	setmetatile 60, 56, METATILE_General_WaterRockTR, TRUE
	setmetatile 59, 57, METATILE_General_WaterRockBL, TRUE
	setmetatile 60, 57, METATILE_General_WaterRockBR, TRUE

	setmetatile 61, 57, METATILE_General_WaterRockTL, TRUE
	setmetatile 62, 57, METATILE_General_WaterRockTR, TRUE
	setmetatile 61, 58, METATILE_General_WaterRockBL, TRUE
	setmetatile 62, 58, METATILE_General_WaterRockBR, TRUE

	setmetatile 62, 55, METATILE_General_WaterRockTL, TRUE
	setmetatile 63, 55, METATILE_General_WaterRockTR, TRUE
	setmetatile 62, 56, METATILE_General_WaterRockBL, TRUE
	setmetatile 63, 56, METATILE_General_WaterRockBR, TRUE

	setmetatile 63, 53, METATILE_General_WaterRockTL, TRUE
	setmetatile 64, 53, METATILE_General_WaterRockTR, TRUE
	setmetatile 63, 54, METATILE_General_WaterRockBL, TRUE
	setmetatile 64, 54, METATILE_General_WaterRockBR, TRUE

	setmetatile 62, 51, METATILE_General_WaterRockTL, TRUE
	setmetatile 63, 51, METATILE_General_WaterRockTR, TRUE
	setmetatile 62, 52, METATILE_General_WaterRockBL, TRUE
	setmetatile 63, 52, METATILE_General_WaterRockBR, TRUE

	setmetatile 63, 49, METATILE_General_WaterRockTL, TRUE
	setmetatile 64, 49, METATILE_General_WaterRockTR, TRUE
	setmetatile 63, 50, METATILE_General_WaterRockBL, TRUE
	setmetatile 64, 50, METATILE_General_WaterRockBR, TRUE

	setmetatile 61, 48, METATILE_General_WaterRockTL, TRUE
	setmetatile 62, 48, METATILE_General_WaterRockTR, TRUE
	setmetatile 61, 49, METATILE_General_WaterRockBL, TRUE
	setmetatile 62, 49, METATILE_General_WaterRockBR, TRUE

	setmetatile 62, 46, METATILE_General_WaterRockTL, TRUE
	setmetatile 63, 46, METATILE_General_WaterRockTR, TRUE
	setmetatile 62, 47, METATILE_General_WaterRockBL, TRUE
	setmetatile 63, 47, METATILE_General_WaterRockBR, TRUE

	setmetatile 61, 44, METATILE_General_WaterRockTL, TRUE
	setmetatile 62, 44, METATILE_General_WaterRockTR, TRUE
	setmetatile 61, 45, METATILE_General_WaterRockBL, TRUE
	setmetatile 62, 45, METATILE_General_WaterRockBR, TRUE

	setmetatile 60, 42, METATILE_General_WaterRockTL, TRUE
	setmetatile 61, 42, METATILE_General_WaterRockTR, TRUE
	setmetatile 60, 43, METATILE_General_WaterRockBL, TRUE
	setmetatile 61, 43, METATILE_General_WaterRockBR, TRUE

	setmetatile 58, 43, METATILE_General_WaterRockTL, TRUE
	setmetatile 59, 43, METATILE_General_WaterRockTR, TRUE
	setmetatile 58, 44, METATILE_General_WaterRockBL, TRUE
	setmetatile 59, 44, METATILE_General_WaterRockBR, TRUE

	setmetatile 57, 41, METATILE_General_WaterRockTL, TRUE
	setmetatile 58, 41, METATILE_General_WaterRockTR, TRUE
	setmetatile 57, 42, METATILE_General_WaterRockBL, TRUE
	setmetatile 58, 42, METATILE_General_WaterRockBR, TRUE

	setmetatile 58, 39, METATILE_General_WaterRockTL, TRUE
	setmetatile 59, 39, METATILE_General_WaterRockTR, TRUE
	setmetatile 58, 40, METATILE_General_WaterRockBL, TRUE
	setmetatile 59, 40, METATILE_General_WaterRockBR, TRUE

	setmetatile 57, 37, METATILE_General_WaterRockTL, TRUE
	setmetatile 58, 37, METATILE_General_WaterRockTR, TRUE
	setmetatile 57, 38, METATILE_General_WaterRockBL, TRUE
	setmetatile 58, 38, METATILE_General_WaterRockBR, TRUE
	
	setmetatile 55, 36, METATILE_General_WaterRockTL, TRUE
	setmetatile 56, 36, METATILE_General_WaterRockTR, TRUE
	setmetatile 55, 37, METATILE_General_WaterRockBL, TRUE
	setmetatile 56, 37, METATILE_General_WaterRockBR, TRUE

	setmetatile 57, 60, METATILE_General_WaterRockTL, TRUE
	setmetatile 58, 60, METATILE_General_WaterRockTR, TRUE
	setmetatile 57, 61, METATILE_General_WaterRockBL, TRUE
	setmetatile 58, 61, METATILE_General_WaterRockBR, TRUE

	setmetatile 46, 56, METATILE_General_WaterRockBL, TRUE
	setmetatile 47, 56, METATILE_General_WaterRockBR, TRUE

	setmetatile 45, 34, METATILE_General_OceanSandBL, FALSE
	setmetatile 46, 34, METATILE_General_OceanSandVertexBL, TRUE
	setmetatile 47, 34, METATILE_General_OceanSand, FALSE
	setmetatile 48, 34, METATILE_General_OceanSand, FALSE
	setmetatile 49, 34, METATILE_General_OceanSand, FALSE
	setmetatile 50, 34, METATILE_General_OceanSand, FALSE
	setmetatile 51, 34, METATILE_General_OceanSandVertexBR, TRUE
	setmetatile 52, 34, METATILE_Petalburg_LedgeLOnOceanSandB, TRUE

	setmetatile 46, 35, METATILE_General_OceanSandL, TRUE
	setmetatile 47, 35, METATILE_General_OceanSand, FALSE
	setmetatile 48, 35, METATILE_General_OceanSand, FALSE
	setmetatile 49, 35, METATILE_General_OceanSand, FALSE
	setmetatile 50, 35, METATILE_General_OceanSandVertexBR, TRUE
	setmetatile 51, 35, METATILE_General_OceanSandBR, TRUE

	setmetatile 46, 36, METATILE_General_OceanSandL, TRUE
	setmetatile 47, 36, METATILE_General_OceanSand, FALSE
	setmetatile 48, 36, METATILE_General_OceanSand, FALSE
	setmetatile 49, 36, METATILE_General_OceanSand, FALSE
	setmetatile 50, 36, METATILE_General_OceanSandR, TRUE

	setmetatile 46, 37, METATILE_General_OceanSandL, TRUE
	setmetatile 47, 37, METATILE_General_OceanSand, FALSE
	setmetatile 48, 37, METATILE_General_OceanSand, FALSE
	setmetatile 49, 37, METATILE_General_OceanSand, FALSE
	setmetatile 50, 37, METATILE_General_OceanSandR, TRUE

	setmetatile 46, 38, METATILE_General_OceanSandL, TRUE
	setmetatile 47, 38, METATILE_General_OceanSand, FALSE
	setmetatile 48, 38, METATILE_General_OceanSand, FALSE
	setmetatile 49, 38, METATILE_General_OceanSand, FALSE
	setmetatile 50, 38, METATILE_General_OceanSandR, TRUE

	setmetatile 46, 39, METATILE_General_OceanSandL, TRUE
	setmetatile 47, 39, METATILE_General_OceanSand, FALSE
	setmetatile 48, 39, METATILE_General_OceanSand, FALSE
	setmetatile 49, 39, METATILE_General_OceanSand, FALSE
	setmetatile 50, 39, METATILE_General_OceanSandR, TRUE

	setmetatile 46, 40, METATILE_General_OceanSandL, TRUE
	setmetatile 47, 40, METATILE_General_OceanSand, FALSE
	setmetatile 48, 40, METATILE_General_OceanSand, FALSE
	setmetatile 49, 40, METATILE_General_OceanSand, FALSE
	setmetatile 50, 40, METATILE_General_OceanSandR, TRUE

	setmetatile 46, 41, METATILE_General_OceanSandL, TRUE
	setmetatile 47, 41, METATILE_General_OceanSand, FALSE
	setmetatile 48, 41, METATILE_General_OceanSand, FALSE
	setmetatile 49, 41, METATILE_General_OceanSand, FALSE
	setmetatile 50, 41, METATILE_General_OceanSandR, TRUE

	setmetatile 46, 42, METATILE_General_OceanSandL, TRUE
	setmetatile 47, 42, METATILE_General_OceanSand, FALSE
	setmetatile 48, 42, METATILE_General_OceanSand, FALSE
	setmetatile 49, 42, METATILE_General_OceanSand, FALSE
	setmetatile 50, 42, METATILE_General_OceanSandR, TRUE

	setmetatile 46, 43, METATILE_General_OceanSandL, TRUE
	setmetatile 47, 43, METATILE_General_OceanSand, FALSE
	setmetatile 48, 43, METATILE_General_OceanSand, FALSE
	setmetatile 49, 43, METATILE_General_OceanSand, FALSE
	setmetatile 50, 43, METATILE_General_OceanSandR, TRUE

	setmetatile 46, 44, METATILE_General_OceanSandL, TRUE
	setmetatile 47, 44, METATILE_General_OceanSand, FALSE
	setmetatile 48, 44, METATILE_General_OceanSand, FALSE
	setmetatile 49, 44, METATILE_General_OceanSand, FALSE
	setmetatile 50, 44, METATILE_General_OceanSandR, TRUE

	setmetatile 46, 45, METATILE_General_OceanSandL, TRUE
	setmetatile 47, 45, METATILE_General_OceanSand, FALSE
	setmetatile 48, 45, METATILE_General_OceanSand, FALSE
	setmetatile 49, 45, METATILE_General_OceanSand, FALSE
	setmetatile 50, 45, METATILE_General_OceanSandR, TRUE

	setmetatile 46, 46, METATILE_General_OceanSandL, TRUE
	setmetatile 47, 46, METATILE_General_OceanSand, FALSE
	setmetatile 48, 46, METATILE_General_OceanSand, FALSE
	setmetatile 49, 46, METATILE_General_OceanSand, FALSE
	setmetatile 50, 46, METATILE_Petalburg_WCliffTRSandVertexTR, TRUE
	setmetatile 51, 46, METATILE_Petalburg_WWCliffT, TRUE
	setmetatile 52, 46, METATILE_Petalburg_WWCliffTR, TRUE

	setmetatile 45, 47, METATILE_General_OceanSandTL, TRUE
	setmetatile 46, 47, METATILE_General_OceanSandVertexTL, FALSE
	setmetatile 47, 47, METATILE_General_OceanSand, FALSE
	setmetatile 48, 47, METATILE_General_OceanSand, FALSE
	setmetatile 49, 47, METATILE_General_OceanSand, FALSE
	setmetatile 50, 47, METATILE_Petalburg_WRSandL, TRUE
	setmetatile 51, 47, METATILE_Petalburg_WR, TRUE
	setmetatile 52, 47, METATILE_Petalburg_WCliffVertexTL, TRUE
	setmetatile 53, 47, METATILE_Petalburg_WWCliffTR, TRUE

	setmetatile 45, 48, METATILE_General_OceanSandL, TRUE
	setmetatile 46, 48, METATILE_General_OceanSand, FALSE
	setmetatile 47, 48, METATILE_General_OceanSand, FALSE
	setmetatile 48, 48, METATILE_General_OceanSand, FALSE
	setmetatile 49, 48, METATILE_General_OceanSand, FALSE
	setmetatile 50, 48, METATILE_Petalburg_WRSandBL, TRUE
	setmetatile 51, 48, METATILE_Petalburg_WRSandB, TRUE
	setmetatile 52, 48, METATILE_Petalburg_WRSandB, TRUE
	setmetatile 53, 48, METATILE_Petalburg_WRSandBR, TRUE
	setmetatile 54, 48, METATILE_General_OceanSandT, FALSE
	setmetatile 55, 48, METATILE_General_OceanSandTR, TRUE

	setmetatile 56, 48, METATILE_General_CalmWater, TRUE
	setmetatile 57, 48, METATILE_General_CalmWater, TRUE
	setmetatile 58, 48, METATILE_General_CalmWater, TRUE
	setmetatile 54, 47, METATILE_General_CalmWater, TRUE
	setmetatile 60, 50, METATILE_General_CalmWater, TRUE

	setmetatile 45, 49, METATILE_General_OceanSandL, TRUE
	setmetatile 46, 49, METATILE_General_OceanSand, FALSE
	setmetatile 47, 49, METATILE_General_OceanSand, FALSE
	setmetatile 48, 49, METATILE_General_OceanSand, FALSE
	setmetatile 49, 49, METATILE_Petalburg_WRSandTL, TRUE
	setmetatile 50, 49, METATILE_Petalburg_WRSandT, FALSE
	setmetatile 51, 49, METATILE_Petalburg_WRSandT, FALSE
	setmetatile 52, 49, METATILE_Petalburg_WRSandT, FALSE
	setmetatile 53, 49, METATILE_Petalburg_WRSandTR, TRUE
	setmetatile 54, 49, METATILE_General_OceanSand, FALSE
	setmetatile 55, 49, METATILE_General_OceanSandVertexTR, FALSE
	setmetatile 56, 49, METATILE_General_OceanSandT, FALSE
	setmetatile 57, 49, METATILE_General_OceanSandT, FALSE
	setmetatile 58, 49, METATILE_General_OceanSandT, FALSE
	setmetatile 59, 49, METATILE_General_OceanSandTR, TRUE

	setmetatile 44, 50, METATILE_General_OceanSandTL, TRUE
	setmetatile 45, 50, METATILE_Petalburg_WCliffTRSandVertexTL, TRUE
	setmetatile 46, 50, METATILE_Petalburg_WRSandTR, TRUE
	setmetatile 47, 50, METATILE_General_OceanSand, FALSE
	setmetatile 48, 50, METATILE_Petalburg_WRSandTL, TRUE
	setmetatile 49, 50, METATILE_Petalburg_WRRCliffL, TRUE
	setmetatile 50, 50, METATILE_Petalburg_WR, FALSE
	setmetatile 51, 50, METATILE_Petalburg_WR, FALSE
	setmetatile 52, 50, METATILE_Petalburg_WR, FALSE
	setmetatile 53, 50, METATILE_Petalburg_WRRCliffR, TRUE
	setmetatile 54, 50, METATILE_Petalburg_WRSandTR, TRUE
	setmetatile 55, 50, METATILE_General_OceanSand, FALSE
	setmetatile 56, 50, METATILE_General_OceanSand, FALSE
	setmetatile 57, 50, METATILE_General_OceanSand, FALSE
	setmetatile 58, 50, METATILE_General_OceanSand, FALSE
	setmetatile 59, 50, METATILE_General_OceanSandR, TRUE

	setmetatile 44, 51, METATILE_General_OceanSandL, TRUE
	setmetatile 45, 51, METATILE_Petalburg_WRSandL, TRUE
	setmetatile 46, 51, METATILE_Petalburg_WRSandR, TRUE
	setmetatile 47, 51, METATILE_General_OceanSand, FALSE
	setmetatile 48, 51, METATILE_Petalburg_WRSandL, TRUE
	setmetatile 49, 51, METATILE_Petalburg_WRCRockL, TRUE
	setmetatile 50, 51, METATILE_Petalburg_WR, FALSE
	setmetatile 51, 51, METATILE_Petalburg_WR, FALSE
	setmetatile 52, 51, METATILE_Petalburg_WR, FALSE
	setmetatile 53, 51, METATILE_Petalburg_WRRCliffR, TRUE
	setmetatile 54, 51, METATILE_Petalburg_WRSandR, TRUE
	setmetatile 55, 51, METATILE_General_RSandTL, TRUE
	setmetatile 56, 51, METATILE_General_RSandTR, TRUE
	setmetatile 57, 51, METATILE_General_OceanSand, FALSE
	setmetatile 58, 51, METATILE_General_OceanSand, FALSE
	setmetatile 59, 51, METATILE_General_OceanSandVertexTR, FALSE
	setmetatile 60, 51, METATILE_General_OceanSandT, FALSE
	setmetatile 61, 51, METATILE_General_OceanSandTR, TRUE

	setmetatile 44, 52, METATILE_General_OceanSandL, TRUE
	setmetatile 45, 52, METATILE_Petalburg_WRSandL, TRUE
	setmetatile 46, 52, METATILE_Petalburg_WRSandR, TRUE
	setmetatile 47, 52, METATILE_General_OceanSand, FALSE
	setmetatile 48, 52, METATILE_Petalburg_WRCSandL, TRUE
	setmetatile 49, 52, METATILE_Petalburg_WRRCliffL, TRUE
	setmetatile 50, 52, METATILE_Petalburg_WR, FALSE
	setmetatile 51, 52, METATILE_Petalburg_WR, FALSE
	setmetatile 52, 52, METATILE_Petalburg_WR, FALSE
	setmetatile 53, 52, METATILE_Petalburg_WRCRockR, TRUE
	setmetatile 54, 52, METATILE_Petalburg_WRSandR, TRUE
	setmetatile 55, 52, METATILE_General_RSandBL, TRUE
	setmetatile 56, 52, METATILE_General_RSandBR, TRUE
	setmetatile 57, 52, METATILE_General_OceanSand, FALSE
	setmetatile 58, 52, METATILE_General_OceanSand, FALSE
	setmetatile 59, 52, METATILE_Petalburg_WRSandTL, TRUE
	setmetatile 60, 52, METATILE_Petalburg_WRSandTR, TRUE
	setmetatile 61, 52, METATILE_General_OceanSandR, TRUE

	setmetatile 44, 53, METATILE_General_OceanSandL, TRUE
	setmetatile 45, 53, METATILE_Petalburg_WRSandBL, TRUE
	setmetatile 46, 53, METATILE_Petalburg_RockLedgeWRSandBR, TRUE
	setmetatile 47, 53, METATILE_General_RSandTR, TRUE
	setmetatile 48, 53, METATILE_Petalburg_WRSandL, TRUE
	setmetatile 49, 53, METATILE_Petalburg_WRRCliffBL, TRUE
	setmetatile 50, 53, METATILE_Petalburg_WRRCliffB, TRUE
	setmetatile 51, 53, METATILE_Petalburg_WRRCliffB, TRUE
	setmetatile 52, 53, METATILE_Petalburg_WRRCliffB, TRUE
	setmetatile 53, 53, METATILE_Petalburg_WRRCliffBR, TRUE
	setmetatile 54, 53, METATILE_Petalburg_WRCSandR, TRUE
	setmetatile 55, 53, METATILE_General_OceanSand, FALSE
	setmetatile 56, 53, METATILE_General_OceanSand, FALSE
	setmetatile 57, 53, METATILE_General_OceanSand, FALSE
	setmetatile 58, 53, METATILE_General_OceanSand, FALSE
	setmetatile 59, 53, METATILE_Petalburg_WRSandBL, TRUE
	setmetatile 60, 53, METATILE_Petalburg_WRSandBR, TRUE
	setmetatile 61, 53, METATILE_General_OceanSandR, TRUE

	setmetatile 44, 54, METATILE_General_OceanSandBL, TRUE
	setmetatile 45, 54, METATILE_General_OceanSandVertexBL, TRUE
	setmetatile 46, 54, METATILE_General_RSandBL, TRUE
	setmetatile 47, 54, METATILE_General_RSandBR, TRUE
	setmetatile 48, 54, METATILE_Petalburg_WRSandBL, TRUE
	setmetatile 49, 54, METATILE_Petalburg_WRSandB, TRUE
	setmetatile 50, 54, METATILE_Petalburg_WRSandB, TRUE
	setmetatile 51, 54, METATILE_Petalburg_WRCave, FALSE
	setmetatile 52, 54, METATILE_Petalburg_WRSandB, TRUE
	setmetatile 53, 54, METATILE_Petalburg_WRSandB, TRUE
	setmetatile 54, 54, METATILE_Petalburg_WRSandBR, TRUE
	setmetatile 55, 54, METATILE_General_OceanSand, FALSE
	setmetatile 56, 54, METATILE_General_OceanSand, FALSE
	setmetatile 57, 54, METATILE_General_OceanSandVertexBR, TRUE
	setmetatile 58, 54, METATILE_General_OceanSandB, TRUE
	setmetatile 59, 54, METATILE_General_OceanSandB, TRUE
	setmetatile 60, 54, METATILE_General_OceanSandB, TRUE
	setmetatile 61, 54, METATILE_General_OceanSandBR, TRUE

	setmetatile 45, 55, METATILE_General_OceanSandBL, TRUE
	setmetatile 46, 55, METATILE_General_WaterRockTLSand, TRUE
	setmetatile 47, 55, METATILE_General_WaterRockTRSand, TRUE
	setmetatile 48, 55, METATILE_General_OceanSandB, TRUE
	setmetatile 49, 55, METATILE_General_OceanSandVertexBL, TRUE
	setmetatile 50, 55, METATILE_General_OceanSand, FALSE
	setmetatile 51, 55, METATILE_General_OceanSand, FALSE
	setmetatile 52, 55, METATILE_General_OceanSand, FALSE
	setmetatile 53, 55, METATILE_General_OceanSand, FALSE
	setmetatile 54, 55, METATILE_General_OceanSand, FALSE
	setmetatile 55, 55, METATILE_General_OceanSand, FALSE
	setmetatile 56, 55, METATILE_General_OceanSand, FALSE
	setmetatile 57, 55, METATILE_General_OceanSandR, TRUE

	setmetatile 49, 56, METATILE_General_OceanSandL, TRUE
	setmetatile 50, 56, METATILE_General_OceanSand, FALSE
	setmetatile 51, 56, METATILE_General_OceanSand, FALSE
	setmetatile 52, 56, METATILE_General_OceanSand, FALSE
	setmetatile 53, 56, METATILE_General_OceanSand, FALSE
	setmetatile 54, 56, METATILE_General_OceanSand, FALSE
	setmetatile 55, 56, METATILE_General_OceanSand, FALSE
	setmetatile 56, 56, METATILE_General_OceanSandVertexBR, TRUE
	setmetatile 57, 56, METATILE_General_OceanSandBR, TRUE

	setmetatile 49, 57, METATILE_General_OceanSandBL, TRUE
	setmetatile 50, 57, METATILE_General_OceanSandB, TRUE
	setmetatile 51, 57, METATILE_General_OceanSandB, TRUE
	setmetatile 52, 57, METATILE_General_OceanSandB, TRUE
	setmetatile 53, 57, METATILE_General_OceanSandB, TRUE
	setmetatile 54, 57, METATILE_General_OceanSandB, TRUE
	setmetatile 55, 57, METATILE_General_OceanSandB, TRUE
	setmetatile 56, 57, METATILE_General_OceanSandBR, TRUE

	setmetatile 47, 32, METATILE_General_StairsShade, FALSE
	setmetatile 48, 32, METATILE_General_Stairs, FALSE
	setmetatile 49, 32, METATILE_General_Stairs, FALSE

	setmetatile 47, 33, METATILE_General_StairsShade, FALSE
	setmetatile 48, 33, METATILE_General_Stairs, FALSE
	setmetatile 49, 33, METATILE_General_Stairs, FALSE
	end

LumiourIsland_EventScript_SetMirageIsland::
	setvar VAR_ENCOUNTER_STATE, 0
	setvar VAR_LUMIOUR_WILD_SET, 0
	setmetatile 36, 15, METATILE_General_GrassMarking, FALSE
	setmetatile 23, 37, METATILE_Petalburg_MarkingTreeTR, FALSE
	setmetatile 38, 56, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 39, 56, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 40, 56, METATILE_General_RockWall_GrassBase, TRUE

	setmetatile 42, 59, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 43, 59, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 44, 59, METATILE_General_RockWall_GrassBase, TRUE

	setmetatile 46, 60, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 47, 60, METATILE_General_RockWall_GrassBase, TRUE

	setmetatile 49, 61, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 50, 61, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 51, 61, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 52, 61, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 53, 61, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 54, 61, METATILE_General_RockWall_GrassBase, TRUE

	setmetatile 56, 60, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 57, 60, METATILE_General_RockWall_GrassBase, TRUE

	setmetatile 59, 59, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 60, 59, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 61, 59, METATILE_General_RockWall_GrassBase, TRUE

	setmetatile 63, 56, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 64, 56, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 65, 56, METATILE_General_RockWall_GrassBase, TRUE

	setmetatile 39, 55, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 40, 55, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 41, 55, METATILE_General_RockWall_RockBase, TRUE

	setmetatile 43, 58, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 44, 58, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 45, 58, METATILE_General_RockWall_RockBase, TRUE

	setmetatile 47, 59, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 48, 59, METATILE_General_RockWall_RockBase, TRUE

	setmetatile 50, 60, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 51, 60, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 52, 60, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 53, 60, METATILE_General_RockWall_RockBase, TRUE

	setmetatile 55, 59, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 56, 59, METATILE_General_RockWall_RockBase, TRUE

	setmetatile 58, 58, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 59, 58, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 60, 58, METATILE_General_RockWall_RockBase, TRUE

	setmetatile 62, 55, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 63, 55, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 64, 55, METATILE_General_RockWall_RockBase, TRUE

	setmetatile 37, 56, METATILE_General_WaterCliffBL, TRUE
	setmetatile 41, 59, METATILE_General_WaterCliffBL, TRUE
	setmetatile 45, 60, METATILE_General_WaterCliffBL, TRUE
	setmetatile 48, 61, METATILE_General_WaterCliffBL, TRUE

	setmetatile 66, 56, METATILE_General_WaterCliffBR, TRUE
	setmetatile 62, 59, METATILE_General_WaterCliffBR, TRUE
	setmetatile 58, 60, METATILE_General_WaterCliffBR, TRUE
	setmetatile 55, 61, METATILE_General_WaterCliffBR, TRUE

	setmetatile 38, 55, METATILE_General_RockRockCliffBL, TRUE
	setmetatile 42, 58, METATILE_General_RockRockCliffBL, TRUE
	setmetatile 46, 59, METATILE_General_RockRockCliffBL, TRUE
	setmetatile 49, 60, METATILE_General_RockRockCliffBL, TRUE

	setmetatile 65, 55, METATILE_General_RockRockCliffBR, TRUE
	setmetatile 61, 58, METATILE_General_RockRockCliffBR, TRUE
	setmetatile 57, 59, METATILE_General_RockRockCliffBR, TRUE
	setmetatile 54, 60, METATILE_General_RockRockCliffBR, TRUE

	setmetatile 44, 55, METATILE_General_FlowerBlue, FALSE
	setmetatile 43, 56, METATILE_General_FlowerBlue, FALSE
	setmetatile 44, 57, METATILE_General_FlowerBlue, FALSE
	setmetatile 45, 56, METATILE_General_FlowerBlue, FALSE
	setmetatile 46, 57, METATILE_General_FlowerBlue, FALSE
	setmetatile 48, 57, METATILE_General_FlowerBlue, FALSE
	setmetatile 47, 58, METATILE_General_FlowerBlue, FALSE

	setmetatile 37, 51, METATILE_General_WaterCliffL, TRUE
	setmetatile 37, 52, METATILE_General_WaterCliffL, TRUE
	setmetatile 37, 53, METATILE_General_WaterCliffL, TRUE
	setmetatile 37, 54, METATILE_General_WaterCliffL, TRUE
	setmetatile 37, 55, METATILE_General_WaterCliffL, TRUE

	setmetatile 66, 51, METATILE_General_WaterCliffR, TRUE
	setmetatile 66, 52, METATILE_General_WaterCliffR, TRUE
	setmetatile 66, 53, METATILE_General_WaterCliffR, TRUE
	setmetatile 66, 54, METATILE_General_WaterCliffR, TRUE
	setmetatile 66, 55, METATILE_General_WaterCliffR, TRUE

	setmetatile 38, 50, METATILE_General_RockRockCliffL, TRUE
	setmetatile 38, 51, METATILE_General_RockRockCliffL, TRUE
	setmetatile 38, 52, METATILE_General_RockRockCliffL, TRUE
	setmetatile 38, 53, METATILE_General_RockRockCliffL, TRUE
	setmetatile 38, 54, METATILE_General_RockRockCliffL, TRUE

	setmetatile 65, 50, METATILE_General_RockRockCliffR, TRUE
	setmetatile 65, 51, METATILE_General_RockRockCliffR, TRUE
	setmetatile 65, 52, METATILE_General_RockRockCliffR, TRUE
	setmetatile 65, 53, METATILE_General_RockRockCliffR, TRUE
	setmetatile 65, 54, METATILE_General_RockRockCliffR, TRUE

	setmetatile 41, 57, METATILE_General_WaterCliffL, TRUE
	setmetatile 41, 58, METATILE_General_WaterCliffL, TRUE

	setmetatile 42, 56, METATILE_General_RockRockCliffL, TRUE
	setmetatile 42, 57, METATILE_General_RockRockCliffL, TRUE

	setmetatile 62, 57, METATILE_General_WaterCliffR, TRUE
	setmetatile 62, 58, METATILE_General_WaterCliffR, TRUE

	setmetatile 61, 56, METATILE_General_RockRockCliffR, TRUE
	setmetatile 61, 57, METATILE_General_RockRockCliffR, TRUE

	setmetatile 41, 56, METATILE_General_CliffVertexBL, TRUE
	setmetatile 42, 55, METATILE_General_CliffVertexBL, TRUE
	setmetatile 45, 59, METATILE_General_CliffVertexBL, TRUE
	setmetatile 46, 58, METATILE_General_CliffVertexBL, TRUE
	setmetatile 48, 60, METATILE_General_CliffVertexBL, TRUE
	setmetatile 49, 59, METATILE_General_CliffVertexBL, TRUE

	setmetatile 62, 56, METATILE_General_CliffVertexBR, TRUE
	setmetatile 61, 55, METATILE_General_CliffVertexBR, TRUE
	setmetatile 58, 59, METATILE_General_CliffVertexBR, TRUE
	setmetatile 57, 58, METATILE_General_CliffVertexBR, TRUE
	setmetatile 55, 60, METATILE_General_CliffVertexBR, TRUE
	setmetatile 54, 59, METATILE_General_CliffVertexBR, TRUE

	setmetatile 37, 50, METATILE_General_WaterCliffTL, TRUE
	setmetatile 38, 49, METATILE_General_WaterCliffTL, TRUE
	setmetatile 39, 48, METATILE_General_WaterCliffTL, TRUE
	setmetatile 41, 47, METATILE_General_WaterCliffTL, TRUE
	setmetatile 42, 46, METATILE_General_WaterCliffTL, TRUE
	setmetatile 43, 45, METATILE_General_WaterCliffTL, TRUE
	setmetatile 44, 44, METATILE_General_WaterCliffTL, TRUE

	setmetatile 66, 50, METATILE_General_WaterCliffTR, TRUE
	setmetatile 65, 49, METATILE_General_WaterCliffTR, TRUE
	setmetatile 64, 48, METATILE_General_WaterCliffTR, TRUE
	setmetatile 62, 47, METATILE_General_WaterCliffTR, TRUE
	setmetatile 61, 46, METATILE_General_WaterCliffTR, TRUE
	setmetatile 60, 45, METATILE_General_WaterCliffTR, TRUE
	setmetatile 59, 44, METATILE_General_WaterCliffTR, TRUE

	setmetatile 42, 47, METATILE_General_RockRockCliffL, TRUE
	setmetatile 61, 47, METATILE_General_RockRockCliffR, TRUE

	setmetatile 42, 51, METATILE_General_Grass_TreeDown, TRUE
	setmetatile 43, 52, METATILE_General_Grass_TreeDown, TRUE
	setmetatile 44, 52, METATILE_General_Grass_TreeDown, TRUE
	setmetatile 45, 51, METATILE_General_Grass_TreeDown, TRUE
	setmetatile 46, 51, METATILE_General_Grass_TreeDown, TRUE

	setmetatile 50, 54, METATILE_General_Grass_TreeDown, TRUE
	setmetatile 51, 55, METATILE_General_Grass_TreeDown, TRUE
	setmetatile 52, 56, METATILE_General_Grass_TreeDown, TRUE
	setmetatile 53, 58, METATILE_General_Grass_TreeDown, TRUE
	setmetatile 54, 58, METATILE_General_Grass_TreeDown, TRUE
	setmetatile 55, 58, METATILE_General_Grass_TreeDown, TRUE
	setmetatile 56, 58, METATILE_General_Grass_TreeDown, TRUE
	setmetatile 57, 57, METATILE_General_Grass_TreeDown, TRUE
	setmetatile 58, 57, METATILE_General_Grass_TreeDown, TRUE

	setmetatile 42, 49, METATILE_General_Grass_TreeUp, FALSE
	setmetatile 43, 48, METATILE_General_Grass_TreeUp, FALSE
	setmetatile 44, 47, METATILE_General_Grass_TreeUp, FALSE
	setmetatile 45, 46, METATILE_General_Grass_TreeUp, FALSE
	setmetatile 46, 47, METATILE_General_Grass_TreeUp, FALSE

	setmetatile 50, 52, METATILE_General_Grass_TreeUp, FALSE
	setmetatile 51, 51, METATILE_General_Grass_TreeUp, FALSE
	setmetatile 52, 51, METATILE_General_Grass_TreeUp, FALSE
	setmetatile 53, 51, METATILE_General_Grass_TreeUp, FALSE
	setmetatile 54, 52, METATILE_General_Grass_TreeUp, FALSE
	setmetatile 55, 52, METATILE_General_Grass_TreeUp, FALSE
	setmetatile 56, 53, METATILE_General_Grass_TreeUp, FALSE
	setmetatile 57, 53, METATILE_General_Grass_TreeUp, FALSE
	setmetatile 58, 54, METATILE_General_Grass_TreeUp, FALSE

	setmetatile 45, 47, METATILE_General_Grass_TreeOverlap, TRUE
	setmetatile 44, 48, METATILE_General_Grass_TreeOverlap, TRUE
	setmetatile 45, 48, METATILE_General_Grass_TreeOverlap, TRUE
	setmetatile 46, 48, METATILE_General_Grass_TreeOverlap, TRUE
	setmetatile 43, 49, METATILE_General_Grass_TreeOverlap, TRUE
	setmetatile 44, 49, METATILE_General_Grass_TreeOverlap, TRUE
	setmetatile 45, 49, METATILE_General_Grass_TreeOverlap, TRUE
	setmetatile 46, 49, METATILE_General_Grass_TreeOverlap, TRUE
	setmetatile 42, 50, METATILE_General_Grass_TreeOverlap, TRUE
	setmetatile 43, 50, METATILE_General_Grass_TreeOverlap, TRUE
	setmetatile 44, 50, METATILE_General_Grass_TreeOverlap, TRUE
	setmetatile 45, 50, METATILE_General_Grass_TreeOverlap, TRUE
	setmetatile 46, 50, METATILE_General_Grass_TreeOverlap, TRUE
	setmetatile 43, 51, METATILE_General_Grass_TreeOverlap, TRUE
	setmetatile 44, 51, METATILE_General_Grass_TreeOverlap, TRUE

	setmetatile 51, 52, METATILE_General_Grass_TreeOverlap, TRUE
	setmetatile 52, 52, METATILE_General_Grass_TreeOverlap, TRUE
	setmetatile 53, 52, METATILE_General_Grass_TreeOverlap, TRUE
	setmetatile 50, 53, METATILE_General_Grass_TreeOverlap, TRUE
	setmetatile 51, 53, METATILE_General_Grass_TreeOverlap, TRUE
	setmetatile 52, 53, METATILE_General_Grass_TreeOverlap, TRUE
	setmetatile 53, 53, METATILE_General_Grass_TreeOverlap, TRUE
	setmetatile 54, 53, METATILE_General_Grass_TreeOverlap, TRUE
	setmetatile 55, 53, METATILE_General_Grass_TreeOverlap, TRUE
	setmetatile 51, 54, METATILE_General_Grass_TreeOverlap, TRUE
	setmetatile 52, 54, METATILE_General_Grass_TreeOverlap, TRUE
	setmetatile 53, 54, METATILE_General_Grass_TreeOverlap, TRUE
	setmetatile 54, 54, METATILE_General_Grass_TreeOverlap, TRUE
	setmetatile 55, 54, METATILE_General_Grass_TreeOverlap, TRUE
	setmetatile 56, 54, METATILE_General_Grass_TreeOverlap, TRUE
	setmetatile 57, 54, METATILE_General_Grass_TreeOverlap, TRUE
	setmetatile 52, 55, METATILE_General_Grass_TreeOverlap, TRUE
	setmetatile 53, 55, METATILE_General_Grass_TreeOverlap, TRUE
	setmetatile 54, 55, METATILE_General_Grass_TreeOverlap, TRUE
	setmetatile 55, 55, METATILE_General_Grass_TreeOverlap, TRUE
	setmetatile 56, 55, METATILE_General_Grass_TreeOverlap, TRUE
	setmetatile 57, 55, METATILE_General_Grass_TreeOverlap, TRUE
	setmetatile 58, 55, METATILE_General_Grass_TreeOverlap, TRUE
	setmetatile 53, 56, METATILE_General_Grass_TreeOverlap, TRUE
	setmetatile 54, 56, METATILE_General_Grass_TreeOverlap, TRUE
	setmetatile 55, 56, METATILE_General_Grass_TreeOverlap, TRUE
	setmetatile 56, 56, METATILE_General_Grass_TreeOverlap, TRUE
	setmetatile 57, 56, METATILE_General_Grass_TreeOverlap, TRUE
	setmetatile 58, 56, METATILE_General_Grass_TreeOverlap, TRUE
	setmetatile 53, 57, METATILE_General_Grass_TreeOverlap, TRUE
	setmetatile 54, 57, METATILE_General_Grass_TreeOverlap, TRUE
	setmetatile 55, 57, METATILE_General_Grass_TreeOverlap, TRUE
	setmetatile 56, 57, METATILE_General_Grass_TreeOverlap, TRUE

	setmetatile 51, 45, METATILE_General_TallGrass, FALSE
	setmetatile 52, 45, METATILE_General_TallGrass, FALSE
	setmetatile 53, 45, METATILE_General_TallGrass, FALSE

	setmetatile 50, 46, METATILE_General_TallGrass, FALSE
	setmetatile 51, 46, METATILE_General_TallGrass, FALSE
	setmetatile 52, 46, METATILE_General_TallGrass, FALSE
	setmetatile 53, 46, METATILE_General_TallGrass, FALSE
	setmetatile 54, 46, METATILE_General_TallGrass, FALSE
	setmetatile 55, 46, METATILE_General_TallGrass, FALSE
	setmetatile 56, 46, METATILE_General_TallGrass, FALSE
	setmetatile 57, 46, METATILE_General_TallGrass, FALSE

	setmetatile 49, 47, METATILE_General_TallGrass, FALSE
	setmetatile 50, 47, METATILE_General_TallGrass, FALSE
	setmetatile 51, 47, METATILE_General_TallGrass, FALSE
	setmetatile 52, 47, METATILE_General_TallGrass, FALSE
	setmetatile 53, 47, METATILE_General_TallGrass, FALSE
	setmetatile 54, 47, METATILE_General_TallGrass, FALSE
	setmetatile 55, 47, METATILE_General_TallGrass, FALSE
	setmetatile 56, 47, METATILE_General_TallGrass, FALSE
	setmetatile 57, 47, METATILE_General_TallGrass, FALSE
	setmetatile 58, 47, METATILE_General_TallGrass, FALSE

	setmetatile 49, 48, METATILE_General_TallGrass, FALSE
	setmetatile 50, 48, METATILE_General_TallGrass, FALSE
	setmetatile 51, 48, METATILE_General_TallGrass, FALSE
	setmetatile 52, 48, METATILE_General_TallGrass, FALSE
	setmetatile 53, 48, METATILE_General_TallGrass, FALSE
	setmetatile 54, 48, METATILE_General_TallGrass, FALSE
	setmetatile 55, 48, METATILE_General_TallGrass, FALSE
	setmetatile 56, 48, METATILE_General_TallGrass, FALSE
	setmetatile 57, 48, METATILE_General_TallGrass, FALSE
	setmetatile 58, 48, METATILE_General_TallGrass, FALSE
	setmetatile 59, 48, METATILE_General_TallGrass, FALSE

	setmetatile 49, 49, METATILE_General_TallGrass, FALSE
	setmetatile 50, 49, METATILE_General_TallGrass, FALSE
	setmetatile 51, 49, METATILE_General_TallGrass, FALSE
	setmetatile 52, 49, METATILE_General_TallGrass, FALSE
	setmetatile 53, 49, METATILE_General_TallGrass, FALSE
	setmetatile 54, 49, METATILE_General_TallGrass, FALSE
	setmetatile 55, 49, METATILE_General_TallGrass, FALSE
	setmetatile 56, 49, METATILE_General_TallGrass, FALSE
	setmetatile 57, 49, METATILE_General_TallGrass, FALSE
	setmetatile 58, 49, METATILE_General_TallGrass, FALSE
	setmetatile 59, 49, METATILE_General_TallGrass, FALSE
	setmetatile 60, 49, METATILE_General_TallGrass, FALSE

	setmetatile 50, 50, METATILE_General_TallGrass, FALSE
	setmetatile 51, 50, METATILE_General_TallGrass, FALSE
	setmetatile 52, 50, METATILE_General_TallGrass, FALSE
	setmetatile 53, 50, METATILE_General_TallGrass, FALSE
	setmetatile 54, 50, METATILE_General_TallGrass, FALSE
	setmetatile 55, 50, METATILE_General_TallGrass, FALSE
	setmetatile 56, 50, METATILE_General_TallGrass, FALSE
	setmetatile 57, 50, METATILE_General_TallGrass, FALSE
	setmetatile 58, 50, METATILE_General_TallGrass, FALSE
	setmetatile 59, 50, METATILE_General_TallGrass, FALSE
	setmetatile 60, 50, METATILE_General_TallGrass, FALSE

	setmetatile 54, 51, METATILE_General_TallGrass, FALSE
	setmetatile 55, 51, METATILE_General_TallGrass, FALSE
	setmetatile 56, 51, METATILE_General_TallGrass, FALSE
	setmetatile 57, 51, METATILE_General_TallGrass, FALSE
	setmetatile 58, 51, METATILE_General_TallGrass, FALSE
	setmetatile 59, 51, METATILE_General_TallGrass, FALSE
	setmetatile 60, 51, METATILE_General_TallGrass, FALSE

	setmetatile 56, 52, METATILE_General_TallGrass, FALSE
	setmetatile 57, 52, METATILE_General_TallGrass, FALSE
	setmetatile 58, 52, METATILE_General_TallGrass, FALSE
	setmetatile 59, 52, METATILE_General_TallGrass, FALSE
	setmetatile 60, 52, METATILE_General_TallGrass, FALSE

	setmetatile 58, 53, METATILE_General_TallGrass, FALSE
	setmetatile 59, 53, METATILE_General_TallGrass, FALSE
	setmetatile 60, 53, METATILE_General_TallGrass, FALSE

	setmetatile 59, 54, METATILE_General_TallGrass, FALSE

	setmetatile 61, 50, METATILE_General_SQBerrySoilTL, FALSE
	setmetatile 62, 50, METATILE_General_SQBerrySoilT, FALSE
	setmetatile 63, 50, METATILE_General_SQBerrySoilTR, FALSE
	setmetatile 61, 51, METATILE_General_SQBerrySoilL, FALSE
	setmetatile 62, 51, METATILE_General_SQBerrySoil, TRUE
	setmetatile 63, 51, METATILE_General_SQBerrySoilR, FALSE
	setmetatile 61, 52, METATILE_General_SQBerrySoilBL, FALSE
	setmetatile 62, 52, METATILE_General_SQBerrySoilB, FALSE
	setmetatile 63, 52, METATILE_General_SQBerrySoilBR, FALSE

	setmetatile 39, 49, METATILE_General_GrassThinRockL, FALSE
	setmetatile 40, 48, METATILE_General_GrassThinRockL, FALSE
	setmetatile 43, 46, METATILE_General_GrassThinRockL, FALSE
	setmetatile 44, 45, METATILE_General_GrassThinRockL, FALSE
	setmetatile 45, 44, METATILE_General_GrassThinRockL, FALSE

	setmetatile 64, 49, METATILE_General_GrassThinRockR, FALSE
	setmetatile 63, 48, METATILE_General_GrassThinRockR, FALSE
	setmetatile 60, 46, METATILE_General_GrassThinRockR, FALSE
	setmetatile 59, 45, METATILE_General_GrassThinRockR, FALSE
	setmetatile 58, 44, METATILE_General_GrassThinRockR, FALSE

	setmetatile 41, 48, METATILE_General_GrassThinRock, FALSE
	setmetatile 42, 48, METATILE_General_GrassThinRock, FALSE

	setmetatile 61, 48, METATILE_General_GrassThinRock, FALSE
	setmetatile 62, 48, METATILE_General_GrassThinRock, FALSE

	setmetatile 46, 44, METATILE_General_GrassThinRock, FALSE
	setmetatile 47, 44, METATILE_General_GrassThinRock, FALSE
	setmetatile 48, 44, METATILE_General_GrassThinRock, FALSE
	setmetatile 49, 44, METATILE_General_GrassThinRock, FALSE
	setmetatile 50, 44, METATILE_General_GrassThinRock, FALSE
	setmetatile 51, 44, METATILE_General_GrassThinRock, FALSE
	setmetatile 52, 44, METATILE_General_GrassThinRock, FALSE
	setmetatile 53, 44, METATILE_General_GrassThinRock, FALSE
	setmetatile 54, 44, METATILE_General_GrassThinRock, FALSE
	setmetatile 55, 44, METATILE_General_GrassThinRock, FALSE
	setmetatile 56, 44, METATILE_General_GrassThinRock, FALSE
	setmetatile 57, 44, METATILE_General_GrassThinRock, FALSE

	setmetatile 45, 45, METATILE_General_Grass2, FALSE
	setmetatile 46, 45, METATILE_General_Grass1, FALSE
	setmetatile 47, 45, METATILE_General_Grass2, FALSE
	setmetatile 48, 45, METATILE_General_Grass1, FALSE
	setmetatile 49, 45, METATILE_General_Grass2, FALSE
	setmetatile 50, 45, METATILE_General_Grass1, FALSE

	setmetatile 54, 45, METATILE_General_Grass1, FALSE
	setmetatile 55, 45, METATILE_General_Grass2, FALSE
	setmetatile 56, 45, METATILE_General_Grass1, FALSE
	setmetatile 57, 45, METATILE_General_Grass2, FALSE
	setmetatile 58, 45, METATILE_General_Grass1, FALSE

	setmetatile 44, 46, METATILE_General_Grass3, FALSE
	setmetatile 46, 46, METATILE_General_Grass3, FALSE
	setmetatile 47, 46, METATILE_General_Grass4, FALSE
	setmetatile 48, 46, METATILE_General_Grass3, FALSE
	setmetatile 49, 46, METATILE_General_Grass4, FALSE
	setmetatile 58, 46, METATILE_General_Grass3, FALSE
	setmetatile 59, 46, METATILE_General_Grass4, FALSE

	setmetatile 43, 47, METATILE_General_Grass2, FALSE
	setmetatile 47, 47, METATILE_General_Grass2, FALSE
	setmetatile 48, 47, METATILE_General_Grass1, FALSE
	setmetatile 59, 47, METATILE_General_Grass2, FALSE
	setmetatile 60, 47, METATILE_General_Grass1, FALSE

	setmetatile 47, 48, METATILE_General_Grass4, FALSE
	setmetatile 48, 48, METATILE_General_Grass3, FALSE
	setmetatile 60, 48, METATILE_General_Grass3, FALSE

	setmetatile 40, 49, METATILE_General_Grass1, FALSE
	setmetatile 41, 49, METATILE_General_Grass2, FALSE
	setmetatile 47, 49, METATILE_General_Grass2, FALSE
	setmetatile 48, 49, METATILE_General_Grass1, FALSE
	setmetatile 61, 49, METATILE_General_Grass2, FALSE
	setmetatile 62, 49, METATILE_General_Grass1, FALSE
	setmetatile 63, 49, METATILE_General_Grass2, FALSE

	setmetatile 39, 50, METATILE_General_Grass4, FALSE
	setmetatile 40, 50, METATILE_General_Grass3, FALSE
	setmetatile 41, 50, METATILE_General_Grass4, FALSE
	setmetatile 47, 50, METATILE_General_Grass4, FALSE
	setmetatile 48, 50, METATILE_General_Grass3, FALSE
	setmetatile 49, 50, METATILE_General_Grass4, FALSE
	setmetatile 64, 50, METATILE_General_Grass3, FALSE

	setmetatile 39, 51, METATILE_General_Grass2, FALSE
	setmetatile 40, 51, METATILE_General_Grass1, FALSE
	setmetatile 41, 51, METATILE_General_Grass2, FALSE
	setmetatile 47, 51, METATILE_General_Grass2, FALSE
	setmetatile 48, 51, METATILE_General_Grass1, FALSE
	setmetatile 49, 51, METATILE_General_Grass2, FALSE
	setmetatile 50, 51, METATILE_General_Grass1, FALSE
	setmetatile 64, 51, METATILE_General_Grass1, FALSE

	setmetatile 39, 52, METATILE_General_Grass4, FALSE
	setmetatile 40, 52, METATILE_General_Grass3, FALSE
	setmetatile 41, 52, METATILE_General_Grass4, FALSE
	setmetatile 42, 52, METATILE_General_Grass3, FALSE
	setmetatile 45, 52, METATILE_General_Grass4, FALSE
	setmetatile 46, 52, METATILE_General_Grass3, FALSE
	setmetatile 47, 52, METATILE_General_Grass4, FALSE
	setmetatile 48, 52, METATILE_General_Grass3, FALSE
	setmetatile 49, 52, METATILE_General_Grass4, FALSE
	setmetatile 64, 52, METATILE_General_Grass3, FALSE

	setmetatile 39, 53, METATILE_General_Grass2, FALSE
	setmetatile 40, 53, METATILE_General_Grass1, FALSE
	setmetatile 41, 53, METATILE_General_Grass2, FALSE
	setmetatile 42, 53, METATILE_General_Grass1, FALSE
	setmetatile 43, 53, METATILE_General_Grass2, FALSE
	setmetatile 44, 53, METATILE_General_Grass1, FALSE
	setmetatile 45, 53, METATILE_General_Grass2, FALSE
	setmetatile 46, 53, METATILE_General_Grass1, FALSE
	setmetatile 47, 53, METATILE_General_Grass2, FALSE
	setmetatile 48, 53, METATILE_General_Grass1, FALSE
	setmetatile 49, 53, METATILE_General_Grass2, FALSE
	setmetatile 61, 53, METATILE_General_Grass2, FALSE
	setmetatile 62, 53, METATILE_General_Grass1, FALSE
	setmetatile 63, 53, METATILE_General_Grass2, FALSE
	setmetatile 64, 53, METATILE_General_Grass1, FALSE

	setmetatile 39, 54, METATILE_General_Grass4, FALSE
	setmetatile 40, 54, METATILE_General_Grass3, FALSE
	setmetatile 41, 54, METATILE_General_Grass4, FALSE
	setmetatile 42, 54, METATILE_General_Grass3, FALSE
	setmetatile 43, 54, METATILE_General_Grass4, FALSE
	setmetatile 44, 54, METATILE_General_Grass3, FALSE
	setmetatile 45, 54, METATILE_General_Grass4, FALSE
	setmetatile 46, 54, METATILE_General_Grass3, FALSE
	setmetatile 47, 54, METATILE_General_Grass4, FALSE
	setmetatile 48, 54, METATILE_General_Grass3, FALSE
	setmetatile 49, 54, METATILE_General_Grass4, FALSE
	setmetatile 60, 54, METATILE_General_Grass3, FALSE
	setmetatile 61, 54, METATILE_General_Grass4, FALSE
	setmetatile 62, 54, METATILE_General_Grass3, FALSE
	setmetatile 63, 54, METATILE_General_Grass4, FALSE
	setmetatile 64, 54, METATILE_General_Grass3, FALSE

	setmetatile 43, 55, METATILE_General_Grass2, FALSE
	setmetatile 45, 55, METATILE_General_Grass2, FALSE
	setmetatile 46, 55, METATILE_General_Grass1, FALSE
	setmetatile 47, 55, METATILE_General_Grass2, FALSE
	setmetatile 48, 55, METATILE_General_Grass1, FALSE
	setmetatile 49, 55, METATILE_General_Grass2, FALSE
	setmetatile 50, 55, METATILE_General_Grass1, FALSE
	setmetatile 59, 55, METATILE_General_Grass2, FALSE
	setmetatile 60, 55, METATILE_General_Grass1, FALSE

	setmetatile 44, 56, METATILE_General_Grass3, FALSE
	setmetatile 46, 56, METATILE_General_Grass3, FALSE
	setmetatile 47, 56, METATILE_General_Grass4, FALSE
	setmetatile 48, 56, METATILE_General_Grass3, FALSE
	setmetatile 49, 56, METATILE_General_Grass4, FALSE
	setmetatile 50, 56, METATILE_General_Grass3, FALSE
	setmetatile 51, 56, METATILE_General_Grass4, FALSE
	setmetatile 59, 56, METATILE_General_Grass4, FALSE
	setmetatile 60, 56, METATILE_General_Grass3, FALSE

	setmetatile 43, 57, METATILE_General_Grass2, FALSE
	setmetatile 45, 57, METATILE_General_Grass2, FALSE
	setmetatile 47, 57, METATILE_General_Grass2, FALSE
	setmetatile 49, 57, METATILE_General_Grass2, FALSE
	setmetatile 50, 57, METATILE_General_Grass1, FALSE
	setmetatile 51, 57, METATILE_General_Grass2, FALSE
	setmetatile 52, 57, METATILE_General_Grass1, FALSE
	setmetatile 59, 57, METATILE_General_Grass2, FALSE
	setmetatile 60, 57, METATILE_General_Grass1, FALSE

	setmetatile 48, 58, METATILE_General_Grass3, FALSE
	setmetatile 49, 58, METATILE_General_Grass4, FALSE
	setmetatile 50, 58, METATILE_General_Grass3, FALSE
	setmetatile 51, 58, METATILE_General_Grass4, FALSE
	setmetatile 52, 58, METATILE_General_Grass3, FALSE

	setmetatile 50, 59, METATILE_General_Grass1, FALSE
	setmetatile 51, 59, METATILE_General_Grass2, FALSE
	setmetatile 52, 59, METATILE_General_Grass1, FALSE
	setmetatile 53, 59, METATILE_General_Grass2, FALSE

	setmetatile 45, 43, METATILE_General_CalmWater, TRUE
	setmetatile 46, 43, METATILE_General_CalmWater, TRUE
	setmetatile 50, 43, METATILE_General_CalmWater, TRUE
	setmetatile 51, 43, METATILE_General_CalmWater, TRUE
	setmetatile 52, 43, METATILE_General_CalmWater, TRUE
	setmetatile 53, 43, METATILE_General_CalmWater, TRUE
	setmetatile 54, 43, METATILE_General_CalmWater, TRUE
	setmetatile 55, 43, METATILE_General_CalmWater, TRUE
	setmetatile 56, 43, METATILE_General_CalmWater, TRUE
	setmetatile 57, 43, METATILE_General_CalmWater, TRUE
	setmetatile 58, 43, METATILE_General_CalmWater, TRUE

	setmetatile 40, 47, METATILE_General_CalmWater, TRUE
	setmetatile 63, 47, METATILE_General_CalmWater, TRUE

	setmetatile 47, 32, METATILE_General_BridgeLeft, FALSE
	setmetatile 47, 33, METATILE_General_BridgeLeft, FALSE
	setmetatile 47, 34, METATILE_General_BridgeLeft, FALSE
	setmetatile 47, 35, METATILE_General_BridgeLeft, FALSE
	setmetatile 47, 36, METATILE_General_BridgeLeft, FALSE
	setmetatile 47, 37, METATILE_General_BridgeLeft, FALSE
	setmetatile 47, 38, METATILE_General_BridgeLeft, FALSE
	setmetatile 47, 39, METATILE_General_BridgeLeft, FALSE
	setmetatile 47, 40, METATILE_General_BridgeLeft, FALSE
	setmetatile 47, 41, METATILE_General_BridgeLeft, FALSE
	setmetatile 47, 42, METATILE_General_BridgeLeft, FALSE
	setmetatile 47, 43, METATILE_General_BridgeLeft, FALSE

	setmetatile 48, 32, METATILE_General_BridgeHorizontalMiddle, FALSE
	setmetatile 48, 33, METATILE_General_BridgeHorizontalMiddle, FALSE
	setmetatile 48, 34, METATILE_General_BridgeHorizontalMiddle, FALSE
	setmetatile 48, 35, METATILE_General_BridgeHorizontalMiddle, FALSE
	setmetatile 48, 36, METATILE_General_BridgeHorizontalMiddle, FALSE
	setmetatile 48, 37, METATILE_General_BridgeHorizontalMiddle, FALSE
	setmetatile 48, 38, METATILE_General_BridgeHorizontalMiddle, FALSE
	setmetatile 48, 39, METATILE_General_BridgeHorizontalMiddle, FALSE
	setmetatile 48, 40, METATILE_General_BridgeHorizontalMiddle, FALSE
	setmetatile 48, 41, METATILE_General_BridgeHorizontalMiddle, FALSE
	setmetatile 48, 42, METATILE_General_BridgeHorizontalMiddle, FALSE
	setmetatile 48, 43, METATILE_General_BridgeHorizontalMiddle, FALSE

	setmetatile 49, 32, METATILE_General_BridgeRight, FALSE
	setmetatile 49, 33, METATILE_General_BridgeRight, FALSE
	setmetatile 49, 34, METATILE_General_BridgeRight, FALSE
	setmetatile 49, 35, METATILE_General_BridgeRight, FALSE
	setmetatile 49, 36, METATILE_General_BridgeRight, FALSE
	setmetatile 49, 37, METATILE_General_BridgeRight, FALSE
	setmetatile 49, 38, METATILE_General_BridgeRight, FALSE
	setmetatile 49, 39, METATILE_General_BridgeRight, FALSE
	setmetatile 49, 40, METATILE_General_BridgeRight, FALSE
	setmetatile 49, 41, METATILE_General_BridgeRight, FALSE
	setmetatile 49, 42, METATILE_General_BridgeRight, FALSE
	setmetatile 49, 43, METATILE_General_BridgeRight, FALSE
	end

LumiourIsland_EventScript_SetIronIsland::
	goto_if_set FLAG_DAY_4_COMPLETE LumiourIsland_EventScript_End
	setmetatile 47, 32, METATILE_General_BridgeLeft, FALSE
	setmetatile 47, 33, METATILE_General_BridgeLeft, FALSE
	setmetatile 47, 34, METATILE_General_BridgeLeft, FALSE
	setmetatile 47, 35, METATILE_General_BridgeLeft, FALSE
	setmetatile 47, 36, METATILE_General_BridgeLeft, FALSE
	setmetatile 47, 37, METATILE_General_BridgeLeft, FALSE
	setmetatile 47, 38, METATILE_General_BridgeLeft, FALSE
	setmetatile 47, 39, METATILE_General_BridgeLeft, FALSE
	setmetatile 47, 40, METATILE_General_BridgeLeft, FALSE
	setmetatile 47, 41, METATILE_General_BridgeLeft, FALSE
	setmetatile 47, 42, METATILE_General_BridgeLeft, FALSE
	setmetatile 47, 43, METATILE_General_BridgeLeft, FALSE

	setmetatile 48, 32, METATILE_General_BridgeHorizontalMiddle, FALSE
	setmetatile 48, 33, METATILE_General_BridgeHorizontalMiddle, FALSE
	setmetatile 48, 34, METATILE_General_BridgeHorizontalMiddle, FALSE
	setmetatile 48, 35, METATILE_General_BridgeHorizontalMiddle, FALSE
	setmetatile 48, 36, METATILE_General_BridgeHorizontalMiddle, FALSE
	setmetatile 48, 37, METATILE_General_BridgeHorizontalMiddle, FALSE
	setmetatile 48, 38, METATILE_General_BridgeHorizontalMiddle, FALSE
	setmetatile 48, 39, METATILE_General_BridgeHorizontalMiddle, FALSE
	setmetatile 48, 40, METATILE_General_BridgeHorizontalMiddle, FALSE
	setmetatile 48, 41, METATILE_General_BridgeHorizontalMiddle, FALSE
	setmetatile 48, 42, METATILE_General_BridgeHorizontalMiddle, FALSE
	setmetatile 48, 43, METATILE_General_BridgeHorizontalMiddle, FALSE

	setmetatile 49, 32, METATILE_General_BridgeRight, FALSE
	setmetatile 49, 33, METATILE_General_BridgeRight, FALSE
	setmetatile 49, 34, METATILE_General_BridgeRight, FALSE
	setmetatile 49, 35, METATILE_General_BridgeRight, FALSE
	setmetatile 49, 36, METATILE_General_BridgeRight, FALSE
	setmetatile 49, 37, METATILE_General_BridgeRight, FALSE
	setmetatile 49, 38, METATILE_General_BridgeRight, FALSE
	setmetatile 49, 39, METATILE_General_BridgeRight, FALSE
	setmetatile 49, 40, METATILE_General_BridgeRight, FALSE
	setmetatile 49, 41, METATILE_General_BridgeRight, FALSE
	setmetatile 49, 42, METATILE_General_BridgeRight, FALSE
	setmetatile 49, 43, METATILE_General_BridgeRight, FALSE

	setmetatile 47, 44, METATILE_Petalburg_SandThinRock, FALSE
	setmetatile 48, 44, METATILE_Petalburg_SandThinRock, FALSE
	setmetatile 49, 44, METATILE_Petalburg_SandThinRock, FALSE

	setmetatile 47, 45, METATILE_General_Dirt, FALSE
	setmetatile 48, 45, METATILE_General_Dirt, FALSE
	setmetatile 49, 45, METATILE_General_Dirt, FALSE

	setmetatile 47, 46, METATILE_General_Dirt, FALSE
	setmetatile 48, 46, METATILE_General_Dirt, FALSE
	setmetatile 49, 46, METATILE_General_Dirt, FALSE

	setmetatile 47, 48, METATILE_General_Dirt, FALSE
	setmetatile 48, 48, METATILE_General_Dirt, FALSE
	setmetatile 49, 48, METATILE_General_Dirt, FALSE

	setmetatile 47, 49, METATILE_General_Dirt, FALSE
	setmetatile 48, 49, METATILE_General_Dirt, FALSE
	setmetatile 49, 49, METATILE_General_Dirt, FALSE

	setmetatile 47, 51, METATILE_General_Dirt, FALSE
	setmetatile 48, 51, METATILE_General_Dirt, FALSE
	setmetatile 49, 51, METATILE_General_Dirt, FALSE

	setmetatile 47, 52, METATILE_General_Dirt, FALSE
	setmetatile 48, 52, METATILE_General_Dirt, FALSE
	setmetatile 49, 52, METATILE_General_Dirt, FALSE

	setmetatile 47, 53, METATILE_General_Dirt, FALSE
	setmetatile 48, 53, METATILE_General_Dirt, FALSE
	setmetatile 49, 53, METATILE_General_Dirt, FALSE

	setmetatile 47, 54, METATILE_General_Dirt, FALSE
	setmetatile 48, 54, METATILE_General_Dirt, FALSE
	setmetatile 49, 54, METATILE_General_DirtPathR, FALSE
	
	setmetatile 47, 55, METATILE_General_Dirt, FALSE
	setmetatile 48, 55, METATILE_General_Dirt, FALSE
	setmetatile 49, 55, METATILE_General_DirtPathR, FALSE

	setmetatile 47, 56, METATILE_General_Dirt, FALSE
	setmetatile 48, 56, METATILE_General_Dirt, FALSE
	setmetatile 49, 56, METATILE_General_DirtPathR, FALSE

	setmetatile 47, 57, METATILE_General_Dirt, FALSE
	setmetatile 48, 57, METATILE_General_RockDirt, TRUE
	setmetatile 49, 57, METATILE_General_Dirt, FALSE

	setmetatile 47, 47, METATILE_General_LedgeJumpL, TRUE
	setmetatile 48, 47, METATILE_General_LedgeJumpS, TRUE
	setmetatile 49, 47, METATILE_General_LedgeJumpR, TRUE

	setmetatile 47, 50, METATILE_General_LedgeJumpL, TRUE
	setmetatile 48, 50, METATILE_General_LedgeJumpS, TRUE
	setmetatile 49, 50, METATILE_General_LedgeJumpR, TRUE

	setmetatile 55, 49, METATILE_General_Dirt, FALSE
	setmetatile 56, 49, METATILE_General_Dirt, FALSE
	setmetatile 57, 49, METATILE_General_Dirt, FALSE
	setmetatile 58, 49, METATILE_General_Dirt, FALSE
	setmetatile 59, 49, METATILE_General_Dirt, FALSE
	setmetatile 60, 49, METATILE_General_Dirt, FALSE

	setmetatile 55, 50, METATILE_General_Dirt, FALSE
	setmetatile 56, 50, METATILE_General_Dirt, FALSE
	setmetatile 57, 50, METATILE_General_Dirt, FALSE
	setmetatile 58, 50, METATILE_General_Dirt, FALSE
	setmetatile 59, 50, METATILE_General_Dirt, FALSE
	setmetatile 60, 50, METATILE_General_Dirt, FALSE

	setmetatile 55, 51, METATILE_General_Dirt, FALSE
	setmetatile 56, 51, METATILE_General_Dirt, FALSE
	setmetatile 57, 51, METATILE_General_Dirt, FALSE
	setmetatile 58, 51, METATILE_General_RSandTL, TRUE
	setmetatile 59, 51, METATILE_General_RSandTR, TRUE
	setmetatile 60, 51, METATILE_General_Dirt, FALSE

	setmetatile 55, 52, METATILE_General_Dirt, FALSE
	setmetatile 56, 52, METATILE_General_Dirt, FALSE
	setmetatile 57, 52, METATILE_General_Dirt, FALSE
	setmetatile 58, 52, METATILE_General_RSandBL, TRUE
	setmetatile 59, 52, METATILE_General_RSandBR, TRUE
	setmetatile 60, 52, METATILE_General_Dirt, FALSE

	setmetatile 55, 53, METATILE_General_Dirt, FALSE
	setmetatile 56, 53, METATILE_General_Dirt, FALSE
	setmetatile 57, 53, METATILE_General_RockDirt, TRUE
	setmetatile 58, 53, METATILE_General_Dirt, FALSE
	setmetatile 59, 53, METATILE_General_Dirt, FALSE
	setmetatile 60, 53, METATILE_General_Dirt, FALSE

	setmetatile 50, 53, METATILE_General_DirtPathBR, FALSE
	setmetatile 50, 54, METATILE_General_Grass4, FALSE
	setmetatile 50, 55, METATILE_General_Grass2, FALSE
	setmetatile 50, 56, METATILE_General_Grass4, FALSE
	setmetatile 50, 57, METATILE_General_DirtPathTR, FALSE

	setmetatile 51, 53, METATILE_General_SSGrassTL, FALSE
	setmetatile 51, 54, METATILE_General_SSGrassL, FALSE
	setmetatile 51, 55, METATILE_General_SSGrassL, FALSE
	setmetatile 51, 56, METATILE_General_SSGrassBL, FALSE

	setmetatile 52, 52, METATILE_General_SSRockTL, FALSE
	setmetatile 52, 53, METATILE_General_SSGrassL, FALSE
	setmetatile 52, 54, METATILE_General_SSGrassL, FALSE
	setmetatile 52, 55, METATILE_General_SSRockBL, FALSE

	setmetatile 53, 51, METATILE_General_SSRockTL, FALSE
	setmetatile 53, 52, METATILE_General_SSGrassL, FALSE
	setmetatile 53, 53, METATILE_General_SSGrassL, FALSE
	setmetatile 53, 54, METATILE_General_SSRockBL, FALSE

	setmetatile 54, 50, METATILE_General_SSRockTL, FALSE
	setmetatile 54, 51, METATILE_General_SSGrassL, FALSE
	setmetatile 54, 52, METATILE_General_SSGrassL, FALSE
	setmetatile 54, 53, METATILE_General_SSRockBL, FALSE

	setmetatile 45, 46, METATILE_General_WaterCliffL, TRUE
	setmetatile 45, 47, METATILE_General_WaterCliffL, TRUE
	setmetatile 45, 48, METATILE_General_WaterCliffL, TRUE
	setmetatile 45, 49, METATILE_General_WaterCliffL, TRUE
	setmetatile 45, 50, METATILE_General_WaterCliffL, TRUE
	setmetatile 45, 51, METATILE_General_WaterCliffL, TRUE
	setmetatile 45, 52, METATILE_General_WaterCliffL, TRUE
	setmetatile 45, 53, METATILE_General_WaterCliffL, TRUE
	setmetatile 45, 54, METATILE_General_WaterCliffL, TRUE
	setmetatile 45, 55, METATILE_General_WaterCliffL, TRUE
	setmetatile 45, 56, METATILE_General_WaterCliffL, TRUE
	setmetatile 45, 57, METATILE_General_WaterCliffL, TRUE
	setmetatile 45, 58, METATILE_General_WaterCliffL, TRUE

	setmetatile 46, 45, METATILE_General_RockRockCliffL, TRUE
	setmetatile 46, 46, METATILE_General_RockRockCliffL, TRUE
	setmetatile 46, 47, METATILE_General_RockRockCliffL, TRUE
	setmetatile 46, 48, METATILE_General_RockRockCliffL, TRUE
	setmetatile 46, 49, METATILE_General_RockRockCliffL, TRUE
	setmetatile 46, 50, METATILE_General_RockRockCliffL, TRUE
	setmetatile 46, 51, METATILE_General_RockRockCliffL, TRUE
	setmetatile 46, 52, METATILE_General_RockRockCliffL, TRUE
	setmetatile 46, 53, METATILE_General_RockRockCliffL, TRUE
	setmetatile 46, 54, METATILE_General_RockRockCliffL, TRUE
	setmetatile 46, 55, METATILE_General_RockRockCliffL, TRUE
	setmetatile 46, 56, METATILE_General_RockRockCliffL, TRUE
	setmetatile 46, 57, METATILE_General_RockRockCliffL, TRUE

	setmetatile 50, 44, METATILE_General_RSandL, TRUE
	setmetatile 50, 45, METATILE_General_RSandL, TRUE
	setmetatile 50, 46, METATILE_General_RSandL, TRUE
	setmetatile 50, 47, METATILE_General_RSandL, TRUE
	setmetatile 50, 48, METATILE_General_RSandL, TRUE
	setmetatile 50, 49, METATILE_General_RSandL, TRUE
	setmetatile 50, 50, METATILE_General_RSandL, TRUE
	setmetatile 50, 51, METATILE_General_RSandL, TRUE

	setmetatile 51, 43, METATILE_General_RockRockCliffL, TRUE
	setmetatile 51, 44, METATILE_General_RockRockCliffL, TRUE
	setmetatile 51, 45, METATILE_General_RockRockCliffL, TRUE
	setmetatile 51, 46, METATILE_General_RockRockCliffL, TRUE
	setmetatile 51, 47, METATILE_General_RockRockCliffL, TRUE
	setmetatile 51, 48, METATILE_General_RockRockCliffL, TRUE
	setmetatile 51, 49, METATILE_General_RockRockCliffL, TRUE
	setmetatile 51, 50, METATILE_General_RockRockCliffL, TRUE

	setmetatile 52, 42, METATILE_General_RockRockCliffL, TRUE
	setmetatile 52, 43, METATILE_General_RockRockCliffL, TRUE
	setmetatile 52, 44, METATILE_General_RockRockCliffL, TRUE
	setmetatile 52, 45, METATILE_General_RockRockCliffL, TRUE
	setmetatile 52, 46, METATILE_General_RockRockCliffL, TRUE
	setmetatile 52, 47, METATILE_General_RockRockCliffL, TRUE
	setmetatile 52, 48, METATILE_General_RockRockCliffL, TRUE
	setmetatile 52, 49, METATILE_General_RockRockCliffL, TRUE

	setmetatile 53, 41, METATILE_General_RockRockCliffL, TRUE
	setmetatile 53, 42, METATILE_General_RockRockCliffL, TRUE
	setmetatile 53, 43, METATILE_General_RockRockCliffL, TRUE
	setmetatile 53, 44, METATILE_General_RockRockCliffL, TRUE
	setmetatile 53, 45, METATILE_General_RockRockCliffL, TRUE
	setmetatile 53, 46, METATILE_General_RockRockCliffL, TRUE
	setmetatile 53, 47, METATILE_General_RockRockCliffL, TRUE
	setmetatile 53, 48, METATILE_General_RockRockCliffL, TRUE

	setmetatile 54, 40, METATILE_General_RockRockCliffL, TRUE
	setmetatile 54, 41, METATILE_General_RockRockCliffL, TRUE
	setmetatile 54, 42, METATILE_General_RockRockCliffL, TRUE
	setmetatile 54, 43, METATILE_General_RockRockCliffL, TRUE
	setmetatile 54, 44, METATILE_General_RockRockCliffL, TRUE
	setmetatile 54, 45, METATILE_General_RockRockCliffL, TRUE
	setmetatile 54, 46, METATILE_General_RockRockCliffL, TRUE
	setmetatile 54, 47, METATILE_General_RockRockCliffL, TRUE

	setmetatile 55, 39, METATILE_General_RockRockCliffL, TRUE
	setmetatile 55, 40, METATILE_General_RockRockCliffL, TRUE
	setmetatile 55, 41, METATILE_General_RockRockCliffL, TRUE
	setmetatile 55, 42, METATILE_General_RockRockCliffL, TRUE
	setmetatile 55, 43, METATILE_General_RockRockCliffL, TRUE
	setmetatile 55, 44, METATILE_General_RockRockCliffL, TRUE
	setmetatile 55, 45, METATILE_General_RockRockCliffL, TRUE

	setmetatile 56, 42, METATILE_General_RockRockCliffL, TRUE
	setmetatile 56, 43, METATILE_General_RockRockCliffL, TRUE
	setmetatile 56, 44, METATILE_General_RockRockCliffL, TRUE

	setmetatile 57, 41, METATILE_General_RockRockCliffL, TRUE
	setmetatile 57, 42, METATILE_General_RockRockCliffL, TRUE
	setmetatile 57, 43, METATILE_General_RockRockCliffL, TRUE

	setmetatile 61, 49, METATILE_General_RSandL, TRUE
	setmetatile 61, 50, METATILE_General_RSandL, TRUE
	setmetatile 61, 51, METATILE_General_RSandL, TRUE
	setmetatile 61, 52, METATILE_General_RSandL, TRUE

	setmetatile 62, 48, METATILE_General_RockRockCliffL, TRUE
	setmetatile 62, 49, METATILE_General_RockRockCliffL, TRUE
	setmetatile 62, 50, METATILE_General_RockRockCliffL, TRUE
	setmetatile 62, 51, METATILE_General_RockRockCliffL, TRUE

	setmetatile 46, 59, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 47, 59, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 48, 59, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 49, 59, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 50, 59, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 51, 59, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 52, 59, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 53, 59, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 54, 59, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 55, 59, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 56, 59, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 57, 59, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 58, 59, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 59, 59, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 60, 59, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 61, 59, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 62, 59, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 63, 59, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 64, 59, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 65, 59, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 66, 59, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 67, 59, METATILE_General_RockWall_GrassBase, TRUE

	setmetatile 47, 58, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 48, 58, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 49, 58, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 50, 58, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 51, 58, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 52, 58, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 53, 58, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 54, 58, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 55, 58, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 56, 58, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 57, 58, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 58, 58, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 59, 58, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 60, 58, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 61, 58, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 62, 58, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 63, 58, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 64, 58, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 65, 58, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 66, 58, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 67, 58, METATILE_General_RockWall_RockBase, TRUE

	setmetatile 52, 57, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 53, 57, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 54, 57, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 55, 57, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 56, 57, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 57, 57, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 58, 57, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 59, 57, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 60, 57, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 61, 57, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 62, 57, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 63, 57, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 64, 57, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 65, 57, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 66, 57, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 67, 57, METATILE_General_RockWall_RockBase, TRUE

	setmetatile 53, 56, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 54, 56, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 55, 56, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 56, 56, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 57, 56, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 58, 56, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 59, 56, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 60, 56, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 61, 56, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 62, 56, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 63, 56, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 64, 56, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 65, 56, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 66, 56, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 67, 56, METATILE_General_RockWall_RockBase, TRUE

	setmetatile 54, 55, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 55, 55, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 56, 55, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 57, 55, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 58, 55, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 59, 55, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 60, 55, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 61, 55, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 62, 55, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 63, 55, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 64, 55, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 65, 55, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 66, 55, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 67, 55, METATILE_General_RockWall_RockBase, TRUE

	setmetatile 55, 54, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 56, 54, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 57, 54, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 58, 54, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 59, 54, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 60, 54, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 61, 54, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 62, 54, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 63, 54, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 64, 54, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 65, 54, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 66, 54, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 67, 54, METATILE_General_RockWall_RockBase, TRUE

	setmetatile 62, 53, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 63, 53, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 64, 53, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 65, 53, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 66, 53, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 67, 53, METATILE_General_RockWall_RockBase, TRUE

	setmetatile 63, 52, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 64, 52, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 65, 52, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 66, 52, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 67, 52, METATILE_General_RockWall_RockBase, TRUE


	setmetatile 59, 47, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 60, 47, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 61, 47, METATILE_General_RockWall_RockBase, TRUE

	setmetatile 60, 46, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 61, 46, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 62, 46, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 63, 46, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 64, 46, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 65, 46, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 66, 46, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 67, 46, METATILE_General_RockWall_RockBase, TRUE

	setmetatile 61, 45, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 62, 45, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 63, 45, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 64, 45, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 65, 45, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 66, 45, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 67, 45, METATILE_General_RockWall_RockBase, TRUE

	setmetatile 58, 44, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 59, 44, METATILE_General_RockWall_RockBase, TRUE

	setmetatile 63, 47, METATILE_General_CliffM, TRUE
	setmetatile 64, 47, METATILE_General_CliffM, TRUE
	setmetatile 65, 47, METATILE_General_CliffM, TRUE
	setmetatile 66, 47, METATILE_General_CliffM, TRUE
	setmetatile 67, 47, METATILE_General_CliffM, TRUE

	setmetatile 63, 48, METATILE_General_CliffM, TRUE
	setmetatile 64, 48, METATILE_General_CliffM, TRUE
	setmetatile 65, 48, METATILE_General_CliffM, TRUE
	setmetatile 66, 48, METATILE_General_CliffM, TRUE
	setmetatile 67, 48, METATILE_General_CliffM, TRUE

	setmetatile 63, 49, METATILE_General_CliffM, TRUE
	setmetatile 64, 49, METATILE_General_CliffM, TRUE
	setmetatile 65, 49, METATILE_General_CliffM, TRUE
	setmetatile 66, 49, METATILE_General_CliffM, TRUE
	setmetatile 67, 49, METATILE_General_CliffM, TRUE

	setmetatile 63, 50, METATILE_General_CliffM, TRUE
	setmetatile 64, 50, METATILE_General_CliffM, TRUE
	setmetatile 65, 50, METATILE_General_CliffM, TRUE
	setmetatile 66, 50, METATILE_General_CliffM, TRUE
	setmetatile 67, 50, METATILE_General_CliffM, TRUE

	setmetatile 63, 51, METATILE_General_CliffM, TRUE
	setmetatile 64, 51, METATILE_General_CliffM, TRUE
	setmetatile 65, 51, METATILE_General_CliffM, TRUE
	setmetatile 66, 51, METATILE_General_CliffM, TRUE
	setmetatile 67, 51, METATILE_General_CliffM, TRUE

	setmetatile 58, 41, METATILE_General_CliffM, TRUE
	setmetatile 59, 41, METATILE_General_CliffM, TRUE
	setmetatile 60, 41, METATILE_General_CliffM, TRUE
	setmetatile 61, 41, METATILE_General_CliffM, TRUE
	setmetatile 62, 41, METATILE_General_CliffM, TRUE
	setmetatile 63, 41, METATILE_General_CliffM, TRUE
	setmetatile 64, 41, METATILE_General_CliffM, TRUE
	setmetatile 65, 41, METATILE_General_CliffM, TRUE
	setmetatile 66, 41, METATILE_General_CliffM, TRUE
	setmetatile 67, 41, METATILE_General_CliffM, TRUE

	setmetatile 58, 42, METATILE_General_CliffM, TRUE
	setmetatile 59, 42, METATILE_General_CliffM, TRUE
	setmetatile 60, 42, METATILE_General_CliffM, TRUE
	setmetatile 61, 42, METATILE_General_CliffM, TRUE
	setmetatile 62, 42, METATILE_General_CliffM, TRUE
	setmetatile 63, 42, METATILE_General_CliffM, TRUE
	setmetatile 64, 42, METATILE_General_CliffM, TRUE
	setmetatile 65, 42, METATILE_General_CliffM, TRUE
	setmetatile 66, 42, METATILE_General_CliffM, TRUE
	setmetatile 67, 42, METATILE_General_CliffM, TRUE

	setmetatile 58, 43, METATILE_General_CliffM, TRUE
	setmetatile 59, 43, METATILE_General_CliffM, TRUE
	setmetatile 60, 43, METATILE_General_CliffM, TRUE
	setmetatile 61, 43, METATILE_General_CliffM, TRUE
	setmetatile 62, 43, METATILE_General_CliffM, TRUE
	setmetatile 63, 43, METATILE_General_CliffM, TRUE
	setmetatile 64, 43, METATILE_General_CliffM, TRUE
	setmetatile 65, 43, METATILE_General_CliffM, TRUE
	setmetatile 66, 43, METATILE_General_CliffM, TRUE
	setmetatile 67, 43, METATILE_General_CliffM, TRUE

	setmetatile 61, 44, METATILE_General_CliffM, TRUE
	setmetatile 62, 44, METATILE_General_CliffM, TRUE
	setmetatile 63, 44, METATILE_General_CliffM, TRUE
	setmetatile 64, 44, METATILE_General_CliffM, TRUE
	setmetatile 65, 44, METATILE_General_CliffM, TRUE
	setmetatile 66, 44, METATILE_General_CliffM, TRUE
	setmetatile 67, 44, METATILE_General_CliffM, TRUE

	setmetatile 56, 39, METATILE_General_CliffM, TRUE
	setmetatile 57, 39, METATILE_General_CliffM, TRUE
	setmetatile 58, 39, METATILE_General_CliffM, TRUE
	setmetatile 59, 39, METATILE_General_CliffM, TRUE
	setmetatile 60, 39, METATILE_General_CliffM, TRUE
	setmetatile 61, 39, METATILE_General_CliffM, TRUE
	setmetatile 62, 39, METATILE_General_CliffM, TRUE
	setmetatile 63, 39, METATILE_General_CliffM, TRUE

	setmetatile 56, 40, METATILE_General_CliffM, TRUE

	setmetatile 57, 46, METATILE_General_Dirt, FALSE
	setmetatile 58, 46, METATILE_General_Dirt, FALSE

	setmetatile 57, 47, METATILE_General_StairsShade, FALSE
	setmetatile 58, 47, METATILE_General_Stairs, FALSE

	setmetatile 57, 48, METATILE_General_StairsShade, FALSE
	setmetatile 58, 48, METATILE_General_Stairs, FALSE

	setmetatile 55, 47, METATILE_General_CliffM, TRUE

	setmetatile 56, 38, METATILE_General_WaterCliffT, TRUE
	setmetatile 57, 38, METATILE_General_WaterCliffT, TRUE
	setmetatile 58, 38, METATILE_General_WaterCliffT, TRUE
	setmetatile 59, 38, METATILE_General_WaterCliffT, TRUE
	setmetatile 60, 38, METATILE_General_WaterCliffT, TRUE
	setmetatile 61, 38, METATILE_General_WaterCliffT, TRUE
	setmetatile 62, 38, METATILE_General_WaterCliffT, TRUE
	setmetatile 63, 38, METATILE_General_WaterCliffT, TRUE

	setmetatile 58, 40, METATILE_General_WaterCliffT, TRUE
	setmetatile 59, 40, METATILE_General_WaterCliffT, TRUE
	setmetatile 60, 40, METATILE_General_WaterCliffT, TRUE
	setmetatile 61, 40, METATILE_General_WaterCliffT, TRUE
	setmetatile 62, 40, METATILE_General_WaterCliffT, TRUE
	setmetatile 63, 40, METATILE_General_WaterCliffT, TRUE
	setmetatile 64, 40, METATILE_General_WaterCliffT, TRUE
	setmetatile 65, 40, METATILE_General_WaterCliffT, TRUE
	setmetatile 66, 40, METATILE_General_WaterCliffT, TRUE
	setmetatile 67, 40, METATILE_General_WaterCliffT, TRUE

	setmetatile 55, 48, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 56, 48, METATILE_General_RockWall_GrassBase, TRUE

	setmetatile 59, 48, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 60, 48, METATILE_General_RockWall_GrassBase, TRUE

	setmetatile 57, 45, METATILE_General_RockWall_GrassBase, TRUE

	setmetatile 45, 45, METATILE_General_WaterCliffTL, TRUE
	setmetatile 46, 44, METATILE_General_WaterCliffTL, TRUE
	setmetatile 50, 43, METATILE_General_WaterCliffTL, TRUE
	setmetatile 51, 42, METATILE_General_WaterCliffTL, TRUE
	setmetatile 52, 41, METATILE_General_WaterCliffTL, TRUE
	setmetatile 53, 40, METATILE_General_WaterCliffTL, TRUE
	setmetatile 54, 39, METATILE_General_WaterCliffTL, TRUE
	setmetatile 55, 38, METATILE_General_WaterCliffTL, TRUE

	setmetatile 56, 41, METATILE_General_RockRockCliffTL, TRUE
	setmetatile 57, 40, METATILE_General_RockRockCliffTL, TRUE

	setmetatile 45, 59, METATILE_General_WaterCliffBL, TRUE

	setmetatile 50, 52, METATILE_General_RSandBL, TRUE
	setmetatile 61, 53, METATILE_General_RSandBL, TRUE
	setmetatile 51, 57, METATILE_General_RockGrassCliffBL, TRUE
	setmetatile 59, 46, METATILE_General_RSandBL, TRUE

	setmetatile 46, 58, METATILE_General_RockRockCliffBL, TRUE
	setmetatile 52, 56, METATILE_General_RockRockCliffBL, TRUE
	setmetatile 53, 55, METATILE_General_RockRockCliffBL, TRUE
	setmetatile 54, 54, METATILE_General_RockRockCliffBL, TRUE
	setmetatile 62, 52, METATILE_General_RockRockCliffBL, TRUE
	setmetatile 60, 45, METATILE_General_RockRockCliffBL, TRUE
	setmetatile 57, 44, METATILE_General_RockRockCliffBL, TRUE
	setmetatile 56, 45, METATILE_General_RockRockCliffBL, TRUE
	setmetatile 55, 46, METATILE_General_RockRockCliffBL, TRUE
	setmetatile 54, 48, METATILE_General_RockRockCliffBL, TRUE
	setmetatile 53, 49, METATILE_General_RockRockCliffBL, TRUE
	setmetatile 52, 50, METATILE_General_RockRockCliffBL, TRUE
	setmetatile 51, 51, METATILE_General_RockRockCliffBL, TRUE
	setmetatile 56, 47, METATILE_General_RockRockCliffBL, TRUE

	setmetatile 51, 52, METATILE_General_CliffVertexBL, TRUE
	setmetatile 52, 51, METATILE_General_CliffVertexBL, TRUE
	setmetatile 53, 50, METATILE_General_CliffVertexBL, TRUE
	setmetatile 54, 49, METATILE_General_CliffVertexBL, TRUE
	setmetatile 56, 46, METATILE_General_CliffVertexBL, TRUE
	setmetatile 61, 48, METATILE_General_CliffVertexBL, TRUE
	setmetatile 62, 47, METATILE_General_CliffVertexBL, TRUE
	setmetatile 60, 44, METATILE_General_CliffVertexBL, TRUE
	setmetatile 59, 45, METATILE_General_CliffVertexBL, TRUE
	setmetatile 58, 45, METATILE_General_CaveEntrance_Bottom, FALSE
	end

LumiereIsland_EventScript_Day5EndScene::
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitse
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitse
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Movement_KecleonAppears
	waitmovement 0
	playse SE_WARP_OUT
	fadescreenswapbuffers FADE_TO_BLACK
	setobjectxy OBJ_EVENT_ID_PLAYER, 47, 28
	setvar VAR_0x8004, 47  @ x
	setvar VAR_0x8005, 28  @ y
	special TeleportCamera
	setmetatile 47, 32, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 48, 32, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 49, 32, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 47, 33, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 48, 33, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 49, 33, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 47, 34, METATILE_General_CalmWater, TRUE
	setmetatile 48, 34, METATILE_General_CalmWater, TRUE
	setmetatile 49, 34, METATILE_General_CalmWater, TRUE
	setmetatile 47, 35, METATILE_General_CalmWater, TRUE
	setmetatile 48, 35, METATILE_General_CalmWater, TRUE
	setmetatile 49, 35, METATILE_General_CalmWater, TRUE
	setmetatile 47, 36, METATILE_General_CalmWater, TRUE
	setmetatile 48, 36, METATILE_General_CalmWater, TRUE
	setmetatile 49, 36, METATILE_General_CalmWater, TRUE
	special DrawWholeMapView
	fadescreenswapbuffers FADE_FROM_BLACK
	goto LumiereIsland_EventScript_SailorGiveLustrousOrb
	end

LumiereIsland_EventScript_SailorGiveLustrousOrb:
	applymovement OBJ_EVENT_ID_PLAYER, Movement_KecleonAppears
	waitmovement 0
	applymovement LOCALID_SAILOR, LumiereIsland_Movement_SailorWalkToPlayer
	waitmovement 0
	msgbox LumiereIsland_Text_ThanksForHelping, MSGBOX_DEFAULT
	giveitem ITEM_LUSTROUS_ORB, 1
	setflag FLAG_HAS_LUSTROUS_ORB
	msgbox LumiereIsland_Text_ThinkItsImportant, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SAILOR, LumiereIsland_Movement_SailorWalkBack
	waitmovement 0
	setflag FLAG_CAN_SLEEP
	setvar VAR_LIBERTY_GARDEN_TRAINERS, 6
	release
	end

LumiereIsland_Text_ThanksForHelping:
	.string "{COLOR BLUE}Hey kid!\p"
	.string "Thanks helping convince those trainers\n"
	.string "to get to safety.\p"
	.string "I found this stone on Liberty Garden.\p"
	.string "It started glowing right before we\n"
	.string "were first transported here.$"

LumiereIsland_Text_ThinkItsImportant:
	.string "{COLOR BLUE}I think it might be important for\n"
	.string "something here on Lumiere Island.\p"
	.string "Maybe show it to that Professor\n"
	.string "friend of yours!$"


LumiereIsland_Movement_SailorWalkToPlayer:
	walk_right
	walk_up
	walk_up
	step_end

LumiereIsland_Movement_SailorWalkBack:
	walk_down
	walk_down
	walk_left
	face_right
	step_end

LumiourIsland_EventScript_SetLibertyIsland::
	goto_if_set FLAG_HAS_LUSTROUS_ORB, LumiourIsland_EventScript_End
	setmetatile 47, 32, METATILE_General_BridgeLeft, FALSE
	setmetatile 47, 33, METATILE_General_BridgeLeft, FALSE
	setmetatile 47, 34, METATILE_General_BridgeLeft, FALSE
	setmetatile 47, 35, METATILE_General_BridgeLeft, FALSE
	setmetatile 47, 36, METATILE_General_BridgeLeft, FALSE
	setmetatile 47, 37, METATILE_General_BridgeLeft, FALSE
	setmetatile 47, 38, METATILE_General_BridgeLeft, FALSE
	setmetatile 47, 39, METATILE_General_BridgeLeft, FALSE
	setmetatile 47, 40, METATILE_General_BridgeLeft, FALSE
	setmetatile 47, 41, METATILE_General_BridgeLeft, FALSE
	setmetatile 47, 42, METATILE_General_BridgeLeft, FALSE
	setmetatile 47, 43, METATILE_General_BridgeLeft, FALSE

	setmetatile 48, 32, METATILE_General_BridgeHorizontalMiddle, FALSE
	setmetatile 48, 33, METATILE_General_BridgeHorizontalMiddle, FALSE
	setmetatile 48, 34, METATILE_General_BridgeHorizontalMiddle, FALSE
	setmetatile 48, 35, METATILE_General_BridgeHorizontalMiddle, FALSE
	setmetatile 48, 36, METATILE_General_BridgeHorizontalMiddle, FALSE
	setmetatile 48, 37, METATILE_General_BridgeHorizontalMiddle, FALSE
	setmetatile 48, 38, METATILE_General_BridgeHorizontalMiddle, FALSE
	setmetatile 48, 39, METATILE_General_BridgeHorizontalMiddle, FALSE
	setmetatile 48, 40, METATILE_General_BridgeHorizontalMiddle, FALSE
	setmetatile 48, 41, METATILE_General_BridgeHorizontalMiddle, FALSE
	setmetatile 48, 42, METATILE_General_BridgeHorizontalMiddle, FALSE
	setmetatile 48, 43, METATILE_General_BridgeHorizontalMiddle, FALSE

	setmetatile 49, 32, METATILE_General_BridgeRight, FALSE
	setmetatile 49, 33, METATILE_General_BridgeRight, FALSE
	setmetatile 49, 34, METATILE_General_BridgeRight, FALSE
	setmetatile 49, 35, METATILE_General_BridgeRight, FALSE
	setmetatile 49, 36, METATILE_General_BridgeRight, FALSE
	setmetatile 49, 37, METATILE_General_BridgeRight, FALSE
	setmetatile 49, 38, METATILE_General_BridgeRight, FALSE
	setmetatile 49, 39, METATILE_General_BridgeRight, FALSE
	setmetatile 49, 40, METATILE_General_BridgeRight, FALSE
	setmetatile 49, 41, METATILE_General_BridgeRight, FALSE
	setmetatile 49, 42, METATILE_General_BridgeRight, FALSE
	setmetatile 49, 43, METATILE_General_BridgeRight, FALSE

	setmetatile 50, 54, METATILE_General_FlowerBlue, FALSE
	setmetatile 51, 54, METATILE_General_FlowerBlue, FALSE
	setmetatile 57, 54, METATILE_General_FlowerBlue, FALSE
	setmetatile 58, 54, METATILE_General_FlowerBlue, FALSE

	setmetatile 53, 54, METATILE_General_StairsShade, FALSE
	setmetatile 54, 54, METATILE_General_Stairs, FALSE
	setmetatile 55, 54, METATILE_General_Stairs, FALSE

	setmetatile 52, 44, METATILE_Petalburg_LH1, TRUE
	setmetatile 53, 44, METATILE_Petalburg_LH2, TRUE
	setmetatile 54, 44, METATILE_Petalburg_LH3, TRUE

	setmetatile 52, 45, METATILE_Petalburg_LH4, TRUE
	setmetatile 53, 45, METATILE_Petalburg_LH5, TRUE
	setmetatile 54, 45, METATILE_Petalburg_LH6, TRUE

	setmetatile 52, 46, METATILE_Petalburg_LH7, TRUE
	setmetatile 53, 46, METATILE_Petalburg_LH8, TRUE
	setmetatile 54, 46, METATILE_Petalburg_LH9, TRUE

	setmetatile 52, 47, METATILE_Petalburg_LH10, TRUE
	setmetatile 53, 47, METATILE_Petalburg_LH11, TRUE
	setmetatile 54, 47, METATILE_Petalburg_LH12, TRUE

	setmetatile 52, 48, METATILE_Petalburg_LH13, TRUE
	setmetatile 53, 48, METATILE_Petalburg_LH14, TRUE
	setmetatile 54, 48, METATILE_Petalburg_LH15, TRUE

	setmetatile 52, 49, METATILE_Petalburg_LH16, TRUE
	setmetatile 53, 49, METATILE_Petalburg_LH17, TRUE
	setmetatile 54, 49, METATILE_Petalburg_LH18, TRUE

	setmetatile 52, 50, METATILE_Petalburg_LH19, TRUE
	setmetatile 53, 50, METATILE_Petalburg_LH20, TRUE
	setmetatile 54, 50, METATILE_Petalburg_LH21, TRUE

	setmetatile 52, 51, METATILE_Petalburg_LH22, TRUE
	setmetatile 53, 51, METATILE_Petalburg_LH23, FALSE
	setmetatile 54, 51, METATILE_Petalburg_LH24, TRUE

	setmetatile 39, 49, METATILE_Petalburg_Fountain1, TRUE
	setmetatile 40, 49, METATILE_Petalburg_Fountain2, TRUE
	setmetatile 41, 49, METATILE_Petalburg_Fountain3, TRUE
	setmetatile 39, 50, METATILE_Petalburg_Fountain4, TRUE
	setmetatile 40, 50, METATILE_Petalburg_Fountain5, TRUE
	setmetatile 41, 50, METATILE_Petalburg_Fountain6, TRUE
	setmetatile 39, 51, METATILE_Petalburg_Fountain7, TRUE
	setmetatile 40, 51, METATILE_Petalburg_Fountain8, TRUE
	setmetatile 41, 51, METATILE_Petalburg_Fountain9, TRUE
	setmetatile 40, 52, METATILE_Petalburg_Fountain10, FALSE


	setmetatile 39, 56, METATILE_Petalburg_Fountain1, TRUE
	setmetatile 40, 56, METATILE_Petalburg_Fountain2, TRUE
	setmetatile 41, 56, METATILE_Petalburg_Fountain3, TRUE
	setmetatile 39, 57, METATILE_Petalburg_Fountain4, TRUE
	setmetatile 40, 57, METATILE_Petalburg_Fountain5, TRUE
	setmetatile 41, 57, METATILE_Petalburg_Fountain6, TRUE
	setmetatile 39, 58, METATILE_Petalburg_Fountain7, TRUE
	setmetatile 40, 58, METATILE_Petalburg_Fountain8, TRUE
	setmetatile 41, 58, METATILE_Petalburg_Fountain9, TRUE
	setmetatile 40, 59, METATILE_Petalburg_Fountain10, FALSE

	setmetatile 46, 44, METATILE_General_GrassThinRock, FALSE
	setmetatile 47, 44, METATILE_General_GrassThinRock, FALSE
	setmetatile 48, 44, METATILE_General_GrassThinRock, FALSE
	setmetatile 49, 44, METATILE_General_GrassThinRock, FALSE
	setmetatile 50, 44, METATILE_General_GrassThinRock, FALSE

	setmetatile 38, 43, METATILE_General_Water_TreeLeft, TRUE
	setmetatile 39, 43, METATILE_General_Water_TreeRight, TRUE
	setmetatile 40, 43, METATILE_General_Water_TreeLeft, TRUE
	setmetatile 41, 43, METATILE_General_Water_TreeRight, TRUE
	setmetatile 42, 43, METATILE_General_Water_TreeLeft, TRUE
	setmetatile 43, 43, METATILE_General_Water_TreeRight, TRUE
	setmetatile 44, 43, METATILE_General_Water_TreeLeft, TRUE
	setmetatile 45, 43, METATILE_General_Water_TreeRight, TRUE

	setmetatile 38, 44, METATILE_General_TreeLThinRock, TRUE
	setmetatile 39, 44, METATILE_General_TreeRThinRock, TRUE
	setmetatile 40, 44, METATILE_General_TreeLThinRock, TRUE
	setmetatile 41, 44, METATILE_General_TreeRThinRock, TRUE
	setmetatile 42, 44, METATILE_General_TreeLThinRock, TRUE
	setmetatile 43, 44, METATILE_General_TreeRThinRock, TRUE
	setmetatile 44, 44, METATILE_General_TreeLThinRock, TRUE
	setmetatile 45, 44, METATILE_General_TreeRThinRock, TRUE

	setmetatile 38, 45, METATILE_General_TreeBL, TRUE
	setmetatile 39, 45, METATILE_General_TreeBR, TRUE
	setmetatile 40, 45, METATILE_General_TreeBL, TRUE
	setmetatile 41, 45, METATILE_General_TreeBR, TRUE
	setmetatile 42, 45, METATILE_General_TreeBL, TRUE
	setmetatile 43, 45, METATILE_General_TreeBR, TRUE
	setmetatile 44, 45, METATILE_General_TreeBL, TRUE
	setmetatile 45, 45, METATILE_General_TreeBR, TRUE

	setmetatile 38, 46, METATILE_Petalburg_TileTL, FALSE
	setmetatile 39, 46, METATILE_Petalburg_TileT, FALSE
	setmetatile 40, 46, METATILE_Petalburg_TileT, FALSE
	setmetatile 41, 46, METATILE_Petalburg_TileT, FALSE
	setmetatile 42, 46, METATILE_Petalburg_TileT, FALSE
	setmetatile 43, 46, METATILE_Petalburg_TileT, FALSE
	setmetatile 44, 46, METATILE_Petalburg_TileT, FALSE
	setmetatile 45, 46, METATILE_Petalburg_TileT, FALSE
	setmetatile 46, 46, METATILE_Petalburg_TileT, FALSE
	setmetatile 47, 46, METATILE_Petalburg_TileTR, FALSE

	setmetatile 38, 47, METATILE_Petalburg_TileL, FALSE
	setmetatile 39, 47, METATILE_Petalburg_Tile, FALSE
	setmetatile 40, 47, METATILE_Petalburg_Tile, FALSE
	setmetatile 41, 47, METATILE_Petalburg_Tile, FALSE
	setmetatile 42, 47, METATILE_Petalburg_Tile, FALSE
	setmetatile 43, 47, METATILE_Petalburg_Tile, FALSE
	setmetatile 44, 47, METATILE_Petalburg_Tile, FALSE
	setmetatile 45, 47, METATILE_Petalburg_Tile, FALSE
	setmetatile 46, 47, METATILE_Petalburg_Tile, FALSE
	setmetatile 47, 47, METATILE_Petalburg_TileR, FALSE

	setmetatile 38, 48, METATILE_Petalburg_TileBL, FALSE
	setmetatile 39, 48, METATILE_Petalburg_TileB, FALSE
	setmetatile 40, 48, METATILE_Petalburg_TileB, FALSE
	setmetatile 41, 48, METATILE_Petalburg_TileB, FALSE
	setmetatile 42, 48, METATILE_Petalburg_TileB, FALSE
	setmetatile 43, 48, METATILE_Petalburg_TileVertexTR, FALSE
	setmetatile 44, 48, METATILE_Petalburg_Tile, FALSE
	setmetatile 45, 48, METATILE_Petalburg_TileVertexTL, FALSE
	setmetatile 46, 48, METATILE_Petalburg_TileB, FALSE
	setmetatile 47, 48, METATILE_Petalburg_TileBR, FALSE

	setmetatile 46, 45, METATILE_General_Grass4, FALSE
	setmetatile 47, 45, METATILE_General_Grass3, FALSE
	setmetatile 48, 45, METATILE_General_Grass4, FALSE
	setmetatile 49, 45, METATILE_General_Grass3, FALSE
	setmetatile 50, 45, METATILE_General_Grass4, FALSE

	setmetatile 48, 46, METATILE_General_Grass4, FALSE
	setmetatile 49, 46, METATILE_General_Grass3, FALSE
	setmetatile 50, 46, METATILE_General_Grass4, FALSE

	setmetatile 48, 47, METATILE_General_Grass2, FALSE
	setmetatile 49, 47, METATILE_General_Grass1, FALSE

	setmetatile 48, 48, METATILE_General_Grass4, FALSE
	setmetatile 49, 48, METATILE_General_Grass3, FALSE

	setmetatile 46, 49, METATILE_General_Grass2, FALSE

	setmetatile 47, 49, METATILE_General_Grass_TreeUp, FALSE
	setmetatile 48, 49, METATILE_General_Grass_TreeUp, FALSE
	setmetatile 49, 49, METATILE_General_Grass_TreeUp, FALSE

	setmetatile 47, 50, METATILE_General_Grass_TreeOverlap, TRUE
	setmetatile 48, 50, METATILE_General_Grass_TreeOverlap, TRUE
	setmetatile 49, 50, METATILE_General_Grass_TreeOverlap, TRUE

	setmetatile 47, 51, METATILE_General_Grass_TreeOverlap, TRUE
	setmetatile 48, 51, METATILE_General_Grass_TreeOverlap, TRUE
	setmetatile 49, 51, METATILE_General_Grass_TreeOverlap, TRUE

	setmetatile 47, 52, METATILE_General_Grass_TreeOverlap, TRUE
	setmetatile 48, 52, METATILE_General_Grass_TreeOverlap, TRUE
	setmetatile 49, 52, METATILE_General_Grass_TreeOverlap, TRUE

	setmetatile 47, 53, METATILE_General_Grass_TreeDown, TRUE
	setmetatile 48, 53, METATILE_General_Grass_TreeDown, TRUE
	setmetatile 49, 53, METATILE_General_Grass_TreeDown, TRUE

	setmetatile 43, 49, METATILE_Petalburg_TileL, FALSE
	setmetatile 44, 49, METATILE_Petalburg_Tile, FALSE
	setmetatile 45, 49, METATILE_Petalburg_TileR, FALSE

	setmetatile 43, 50, METATILE_Petalburg_TileL, FALSE
	setmetatile 44, 50, METATILE_Petalburg_Tile, FALSE
	setmetatile 45, 50, METATILE_Petalburg_TileR, FALSE

	setmetatile 43, 51, METATILE_Petalburg_TileL, FALSE
	setmetatile 44, 51, METATILE_Petalburg_Tile, FALSE
	setmetatile 45, 51, METATILE_Petalburg_TileR, FALSE

	setmetatile 43, 52, METATILE_Petalburg_TileL, FALSE
	setmetatile 44, 52, METATILE_Petalburg_Tile, FALSE
	setmetatile 45, 52, METATILE_Petalburg_TileR, FALSE

	setmetatile 43, 53, METATILE_Petalburg_TileVertexBR, FALSE
	setmetatile 44, 53, METATILE_Petalburg_Tile, FALSE
	setmetatile 45, 53, METATILE_Petalburg_TileR, FALSE

	setmetatile 43, 54, METATILE_Petalburg_Tile, FALSE
	setmetatile 44, 54, METATILE_Petalburg_Tile, FALSE
	setmetatile 45, 54, METATILE_Petalburg_TileR, FALSE

	setmetatile 43, 55, METATILE_Petalburg_TileVertexTR, FALSE
	setmetatile 44, 55, METATILE_Petalburg_Tile, FALSE
	setmetatile 45, 55, METATILE_Petalburg_TileVertexBL, FALSE

	setmetatile 43, 56, METATILE_Petalburg_TileL, FALSE
	setmetatile 44, 56, METATILE_Petalburg_Tile, FALSE
	setmetatile 45, 56, METATILE_Petalburg_Tile, FALSE

	setmetatile 43, 57, METATILE_Petalburg_TileBL, FALSE
	setmetatile 44, 57, METATILE_Petalburg_TileB, FALSE
	setmetatile 45, 57, METATILE_Petalburg_TileB, FALSE

	setmetatile 37, 53, METATILE_Petalburg_TileTL, FALSE
	setmetatile 38, 53, METATILE_Petalburg_TileT, FALSE
	setmetatile 39, 53, METATILE_Petalburg_TileT, FALSE
	setmetatile 40, 53, METATILE_Petalburg_TileT, FALSE
	setmetatile 41, 53, METATILE_Petalburg_TileT, FALSE
	setmetatile 42, 53, METATILE_Petalburg_TileT, FALSE

	setmetatile 37, 54, METATILE_Petalburg_TileL, FALSE
	setmetatile 38, 54, METATILE_Petalburg_Tile, FALSE
	setmetatile 39, 54, METATILE_Petalburg_Tile, FALSE
	setmetatile 40, 54, METATILE_Petalburg_Tile, FALSE
	setmetatile 41, 54, METATILE_Petalburg_Tile, FALSE
	setmetatile 42, 54, METATILE_Petalburg_Tile, FALSE

	setmetatile 37, 55, METATILE_Petalburg_TileBL, FALSE
	setmetatile 38, 55, METATILE_Petalburg_TileB, FALSE
	setmetatile 39, 55, METATILE_Petalburg_TileB, FALSE
	setmetatile 40, 55, METATILE_Petalburg_TileB, FALSE
	setmetatile 41, 55, METATILE_Petalburg_TileB, FALSE
	setmetatile 42, 55, METATILE_Petalburg_TileB, FALSE

	setmetatile 46, 55, METATILE_Petalburg_TileT, FALSE
	setmetatile 47, 55, METATILE_Petalburg_TileT, FALSE
	setmetatile 48, 55, METATILE_Petalburg_TileT, FALSE
	setmetatile 49, 55, METATILE_Petalburg_TileT, FALSE
	setmetatile 50, 55, METATILE_Petalburg_TileT, FALSE
	setmetatile 51, 55, METATILE_Petalburg_TileT, FALSE
	setmetatile 52, 55, METATILE_Petalburg_TileT, FALSE
	setmetatile 53, 55, METATILE_Petalburg_TileVertexBR, FALSE
	setmetatile 54, 55, METATILE_Petalburg_Tile, FALSE
	setmetatile 55, 55, METATILE_Petalburg_TileVertexBL, FALSE
	setmetatile 56, 55, METATILE_Petalburg_TileT, FALSE
	setmetatile 57, 55, METATILE_Petalburg_TileT, FALSE
	setmetatile 58, 55, METATILE_Petalburg_TileTR, FALSE

	setmetatile 46, 56, METATILE_Petalburg_Tile, FALSE
	setmetatile 47, 56, METATILE_Petalburg_Tile, FALSE
	setmetatile 48, 56, METATILE_Petalburg_Tile, FALSE
	setmetatile 49, 56, METATILE_Petalburg_Tile, FALSE
	setmetatile 50, 56, METATILE_Petalburg_Tile, FALSE
	setmetatile 51, 56, METATILE_Petalburg_Tile, FALSE
	setmetatile 52, 56, METATILE_Petalburg_Tile, FALSE
	setmetatile 53, 56, METATILE_Petalburg_Tile, FALSE
	setmetatile 54, 56, METATILE_Petalburg_Tile, FALSE
	setmetatile 55, 56, METATILE_Petalburg_Tile, FALSE
	setmetatile 56, 56, METATILE_Petalburg_Tile, FALSE
	setmetatile 57, 56, METATILE_Petalburg_Tile, FALSE
	setmetatile 58, 56, METATILE_Petalburg_TileR, FALSE

	setmetatile 46, 57, METATILE_Petalburg_TileB, FALSE
	setmetatile 47, 57, METATILE_Petalburg_TileB, FALSE
	setmetatile 48, 57, METATILE_Petalburg_TileB, FALSE
	setmetatile 49, 57, METATILE_Petalburg_TileBTreeL, FALSE
	setmetatile 50, 57, METATILE_Petalburg_TileBTreeR, FALSE
	setmetatile 51, 57, METATILE_Petalburg_TileBTreeL, FALSE
	setmetatile 52, 57, METATILE_Petalburg_TileBTreeR, FALSE
	setmetatile 53, 57, METATILE_Petalburg_TileBTreeL, FALSE
	setmetatile 54, 57, METATILE_Petalburg_TileBTreeR, FALSE
	setmetatile 55, 57, METATILE_Petalburg_TileBTreeL, FALSE
	setmetatile 56, 57, METATILE_Petalburg_TileBTreeR, FALSE
	setmetatile 57, 57, METATILE_Petalburg_TileBTreeL, FALSE
	setmetatile 58, 57, METATILE_Petalburg_TileBRTreeR, FALSE

	setmetatile 53, 52, METATILE_Petalburg_TileTL, FALSE
	setmetatile 54, 52, METATILE_Petalburg_TileT, FALSE
	setmetatile 55, 52, METATILE_Petalburg_TileTR, FALSE
	setmetatile 53, 53, METATILE_Petalburg_TileL, FALSE
	setmetatile 54, 53, METATILE_Petalburg_Tile, FALSE
	setmetatile 55, 53, METATILE_Petalburg_TileR, FALSE

	setmetatile 49, 58, METATILE_General_TreeL, TRUE
	setmetatile 50, 58, METATILE_General_TreeR, TRUE
	setmetatile 51, 58, METATILE_General_TreeL, TRUE
	setmetatile 52, 58, METATILE_General_TreeR, TRUE
	setmetatile 53, 58, METATILE_General_TreeL, TRUE
	setmetatile 54, 58, METATILE_General_TreeR, TRUE
	setmetatile 55, 58, METATILE_General_TreeL, TRUE
	setmetatile 56, 58, METATILE_General_TreeR, TRUE
	setmetatile 57, 58, METATILE_General_TreeL, TRUE
	setmetatile 58, 58, METATILE_General_TreeR, TRUE

	setmetatile 49, 59, METATILE_General_TreeBLShade, TRUE
	setmetatile 50, 59, METATILE_General_TreeBRShade, TRUE
	setmetatile 51, 59, METATILE_General_TreeBLShade, TRUE
	setmetatile 52, 59, METATILE_General_TreeBRShade, TRUE
	setmetatile 53, 59, METATILE_General_TreeBLShade, TRUE
	setmetatile 54, 59, METATILE_General_TreeBRShade, TRUE
	setmetatile 55, 59, METATILE_General_TreeBLShade, TRUE
	setmetatile 56, 59, METATILE_General_TreeBRShade, TRUE
	setmetatile 57, 59, METATILE_General_TreeBLShade, TRUE
	setmetatile 58, 59, METATILE_General_TreeBRShade, TRUE

	setmetatile 38, 49, METATILE_Petalburg_AltTile, FALSE
	setmetatile 42, 49, METATILE_Petalburg_AltTile, FALSE
	setmetatile 38, 50, METATILE_Petalburg_AltTile, FALSE
	setmetatile 42, 50, METATILE_Petalburg_AltTile, FALSE
	setmetatile 38, 51, METATILE_Petalburg_AltTile, FALSE
	setmetatile 42, 51, METATILE_Petalburg_AltTile, FALSE
	setmetatile 38, 52, METATILE_Petalburg_AltTile, FALSE
	setmetatile 42, 52, METATILE_Petalburg_AltTile, FALSE

	setmetatile 39, 52, METATILE_Petalburg_AltTile, FALSE
	setmetatile 41, 52, METATILE_Petalburg_AltTile, FALSE

	setmetatile 38, 52, METATILE_Petalburg_AltTile, FALSE
	setmetatile 42, 52, METATILE_Petalburg_AltTile, FALSE

	setmetatile 38, 56, METATILE_Petalburg_AltTile, FALSE
	setmetatile 42, 56, METATILE_Petalburg_AltTile, FALSE

	setmetatile 38, 57, METATILE_Petalburg_AltTile, FALSE
	setmetatile 42, 57, METATILE_Petalburg_AltTile, FALSE

	setmetatile 38, 58, METATILE_Petalburg_AltTile, FALSE
	setmetatile 42, 58, METATILE_Petalburg_AltTile, FALSE

	setmetatile 38, 59, METATILE_Petalburg_AltTile, FALSE
	setmetatile 42, 59, METATILE_Petalburg_AltTile, FALSE

	setmetatile 39, 59, METATILE_Petalburg_AltTile, FALSE
	setmetatile 41, 59, METATILE_Petalburg_AltTile, FALSE

	setmetatile 36, 52, METATILE_Petalburg_AltTile, FALSE
	setmetatile 36, 53, METATILE_Petalburg_AltTile, FALSE
	setmetatile 36, 54, METATILE_Petalburg_AltTile, FALSE
	setmetatile 36, 55, METATILE_Petalburg_AltTile, FALSE
	setmetatile 36, 56, METATILE_Petalburg_AltTile, FALSE
	setmetatile 36, 57, METATILE_Petalburg_AltTile, FALSE

	setmetatile 37, 52, METATILE_Petalburg_AltTile, FALSE

	setmetatile 37, 56, METATILE_Petalburg_AltTile, FALSE
	setmetatile 37, 57, METATILE_Petalburg_AltTile, FALSE


	setmetatile 55, 48, METATILE_General_TreeL, TRUE
	setmetatile 55, 49, METATILE_General_TreeOverlapL, TRUE
	setmetatile 55, 50, METATILE_General_TreeL, TRUE
	setmetatile 55, 51, METATILE_General_TreeBL, TRUE

	setmetatile 56, 48, METATILE_General_TreeR, TRUE
	setmetatile 56, 49, METATILE_General_TreeOverlapR, TRUE
	setmetatile 56, 50, METATILE_General_TreeR, TRUE
	setmetatile 56, 51, METATILE_General_TreeBR, TRUE

	setmetatile 36, 46, METATILE_General_WaterCliffL, TRUE
	setmetatile 36, 47, METATILE_General_WaterCliffL, TRUE
	setmetatile 36, 48, METATILE_General_WaterCliffL, TRUE
	setmetatile 36, 49, METATILE_General_WaterCliffL, TRUE
	setmetatile 36, 50, METATILE_General_WaterCliffL, TRUE

	setmetatile 37, 45, METATILE_General_RockRockCliffL, TRUE
	setmetatile 37, 46, METATILE_General_RockRockCliffL, TRUE
	setmetatile 37, 47, METATILE_General_RockRockCliffL, TRUE
	setmetatile 37, 48, METATILE_General_RockRockCliffL, TRUE
	setmetatile 37, 49, METATILE_General_RockRockCliffL, TRUE
	setmetatile 37, 50, METATILE_General_RockRockCliffL, TRUE

	setmetatile 34, 53, METATILE_General_WaterCliffL, TRUE
	setmetatile 34, 54, METATILE_General_WaterCliffL, TRUE
	setmetatile 34, 55, METATILE_General_WaterCliffL, TRUE
	setmetatile 34, 56, METATILE_General_WaterCliffL, TRUE
	setmetatile 34, 57, METATILE_General_WaterCliffL, TRUE
	setmetatile 34, 58, METATILE_General_WaterCliffL, TRUE

	setmetatile 35, 52, METATILE_General_RockRockCliffL, TRUE
	setmetatile 35, 53, METATILE_General_RockRockCliffL, TRUE
	setmetatile 35, 54, METATILE_General_RockRockCliffL, TRUE
	setmetatile 35, 55, METATILE_General_RockRockCliffL, TRUE
	setmetatile 35, 56, METATILE_General_RockRockCliffL, TRUE
	setmetatile 35, 57, METATILE_General_RockRockCliffL, TRUE

	setmetatile 36, 60, METATILE_General_WaterCliffL, TRUE
	setmetatile 47, 60, METATILE_General_WaterCliffL, TRUE

	setmetatile 37, 59, METATILE_General_RockRockCliffL, TRUE
	setmetatile 48, 59, METATILE_General_RockRockCliffL, TRUE

	setmetatile 50, 48, METATILE_General_RockGrassCliffL, TRUE
	setmetatile 50, 49, METATILE_General_RockGrassCliffL, TRUE
	setmetatile 50, 50, METATILE_General_RockGrassCliffL, TRUE
	setmetatile 50, 51, METATILE_General_RockGrassCliffL, TRUE
	setmetatile 50, 52, METATILE_General_RockGrassCliffL, TRUE

	setmetatile 60, 50, METATILE_General_WaterCliffR, TRUE
	setmetatile 60, 51, METATILE_General_WaterCliffR, TRUE
	setmetatile 60, 52, METATILE_General_WaterCliffR, TRUE
	setmetatile 60, 53, METATILE_General_WaterCliffR, TRUE
	setmetatile 60, 54, METATILE_General_WaterCliffR, TRUE
	setmetatile 60, 55, METATILE_General_WaterCliffR, TRUE
	setmetatile 60, 56, METATILE_General_WaterCliffR, TRUE
	setmetatile 60, 57, METATILE_General_WaterCliffR, TRUE
	setmetatile 60, 58, METATILE_General_WaterCliffR, TRUE
	setmetatile 60, 59, METATILE_General_WaterCliffR, TRUE
	setmetatile 60, 60, METATILE_General_WaterCliffR, TRUE

	setmetatile 59, 49, METATILE_General_RockRockCliffR, TRUE
	setmetatile 59, 50, METATILE_General_RockRockCliffR, TRUE
	setmetatile 59, 51, METATILE_General_RockRockCliffR, TRUE
	setmetatile 59, 52, METATILE_General_RockRockCliffR, TRUE
	setmetatile 59, 53, METATILE_General_RockRockCliffR, TRUE
	setmetatile 59, 54, METATILE_General_RockRockCliffR, TRUE
	setmetatile 59, 55, METATILE_General_RockRockCliffR, TRUE
	setmetatile 59, 56, METATILE_General_RockRockCliffR, TRUE
	setmetatile 59, 57, METATILE_General_RockRockCliffR, TRUE
	setmetatile 59, 58, METATILE_General_RockRockCliffR, TRUE
	setmetatile 59, 59, METATILE_General_RockRockCliffR, TRUE

	setmetatile 58, 48, METATILE_General_RockRockCliffR, TRUE
	setmetatile 58, 49, METATILE_General_RockRockCliffR, TRUE
	setmetatile 58, 50, METATILE_General_RockRockCliffR, TRUE
	setmetatile 58, 51, METATILE_General_RockRockCliffR, TRUE
	setmetatile 58, 52, METATILE_General_RockRockCliffR, TRUE

	setmetatile 51, 45, METATILE_General_RockRockCliffR, TRUE
	setmetatile 51, 46, METATILE_General_RockRockCliffR, TRUE

	setmetatile 37, 44, METATILE_General_WaterCliffTL, TRUE
	setmetatile 36, 45, METATILE_General_WaterCliffTL, TRUE
	setmetatile 35, 51, METATILE_General_WaterCliffTL, TRUE
	setmetatile 34, 52, METATILE_General_WaterCliffTL, TRUE

	setmetatile 51, 44, METATILE_General_WaterCliffTR, TRUE
	setmetatile 58, 47, METATILE_General_WaterCliffTR, TRUE
	setmetatile 59, 48, METATILE_General_WaterCliffTR, TRUE
	setmetatile 60, 49, METATILE_General_WaterCliffTR, TRUE

	setmetatile 36, 51, METATILE_Petalburg_AltTileThinRock, FALSE
	setmetatile 37, 51, METATILE_Petalburg_AltTileThinRock, FALSE

	setmetatile 44, 60, METATILE_General_WaterCliffR, TRUE
	setmetatile 43, 59, METATILE_General_RockRockCliffR, TRUE

	setmetatile 37, 61, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 38, 61, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 39, 61, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 40, 61, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 41, 61, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 42, 61, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 43, 61, METATILE_General_RockWall_GrassBase, TRUE

	setmetatile 48, 61, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 49, 61, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 50, 61, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 51, 61, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 52, 61, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 53, 61, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 54, 61, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 55, 61, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 56, 61, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 57, 61, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 58, 61, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 59, 61, METATILE_General_RockWall_GrassBase, TRUE

	setmetatile 38, 60, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 39, 60, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 40, 60, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 41, 60, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 42, 60, METATILE_General_RockWall_RockBase, TRUE

	setmetatile 49, 60, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 50, 60, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 51, 60, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 52, 60, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 53, 60, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 54, 60, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 55, 60, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 56, 60, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 57, 60, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 58, 60, METATILE_General_RockWall_RockBase, TRUE

	setmetatile 34, 59, METATILE_General_WaterCliffBL, TRUE
	setmetatile 36, 61, METATILE_General_WaterCliffBL, TRUE
	setmetatile 47, 61, METATILE_General_WaterCliffBL, TRUE

	setmetatile 60, 61, METATILE_General_WaterCliffBR, TRUE
	setmetatile 44, 61, METATILE_General_WaterCliffBR, TRUE

	setmetatile 35, 58, METATILE_General_RockRockCliffBL, TRUE
	setmetatile 37, 60, METATILE_General_RockRockCliffBL, TRUE
	setmetatile 48, 60, METATILE_General_RockRockCliffBL, TRUE

	setmetatile 43, 60, METATILE_General_RockRockCliffBR, TRUE
	setmetatile 59, 60, METATILE_General_RockRockCliffBR, TRUE

	setmetatile 45, 59, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 46, 59, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 35, 59, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 51, 53, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 57, 53, METATILE_General_RockWall_GrassBase, TRUE

	setmetatile 36, 58, METATILE_General_RockWall_RockBase, TRUE

	setmetatile 44, 58, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 45, 58, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 46, 58, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 47, 58, METATILE_General_RockWall_RockBase, TRUE

	setmetatile 36, 59, METATILE_General_CliffVertexBL, TRUE
	setmetatile 37, 58, METATILE_General_CliffVertexBL, TRUE

	setmetatile 47, 59, METATILE_General_CliffVertexBL, TRUE
	setmetatile 48, 58, METATILE_General_CliffVertexBL, TRUE

	setmetatile 43, 58, METATILE_General_CliffVertexBR, TRUE
	setmetatile 44, 59, METATILE_General_CliffVertexBR, TRUE

	setmetatile 52, 53, METATILE_General_CliffVertexBL, TRUE
	setmetatile 56, 53, METATILE_General_CliffVertexBR, TRUE

	setmetatile 50, 53, METATILE_General_RockGrassCliffBL, TRUE
	setmetatile 52, 54, METATILE_General_RockGrassCliffBL, TRUE

	setmetatile 58, 53, METATILE_General_RockGrassCliffBR, TRUE
	setmetatile 56, 54, METATILE_General_RockGrassCliffBR, TRUE

	setmetatile 50, 47, METATILE_General_RockGrassCliffTL, TRUE

	setmetatile 46, 50, METATILE_Petalburg_MetalFenceT, TRUE
	setmetatile 46, 51, METATILE_Petalburg_MetalFenceM, TRUE
	setmetatile 46, 52, METATILE_Petalburg_MetalFenceM, TRUE
	setmetatile 46, 53, METATILE_Petalburg_MetalFenceM, TRUE
	setmetatile 46, 54, METATILE_Petalburg_MetalFenceBL, TRUE
	setmetatile 47, 54, METATILE_Petalburg_MetalFenceD, TRUE
	setmetatile 48, 54, METATILE_Petalburg_MetalFenceD, TRUE
	setmetatile 49, 54, METATILE_Petalburg_MetalFenceDendL, TRUE

	setmetatile 51, 47, METATILE_Petalburg_MetalFenceW, TRUE
	setmetatile 51, 48, METATILE_Petalburg_MetalFenceM, TRUE
	setmetatile 51, 49, METATILE_Petalburg_MetalFenceM, TRUE
	setmetatile 51, 50, METATILE_Petalburg_MetalFenceM, TRUE
	setmetatile 51, 51, METATILE_Petalburg_MetalFenceM, TRUE
	setmetatile 51, 52, METATILE_Petalburg_MetalFenceBL, TRUE

	setmetatile 52, 52, METATILE_Petalburg_MetalFenceDendL, TRUE

	setmetatile 55, 47, METATILE_Petalburg_MetalFenceX, TRUE
	setmetatile 56, 47, METATILE_Petalburg_MetalFenceY, TRUE
	setmetatile 57, 47, METATILE_Petalburg_MetalFenceZ, TRUE

	setmetatile 56, 52, METATILE_Petalburg_MetalFenceDendR, TRUE
	setmetatile 57, 52, METATILE_Petalburg_MetalFenceBR, TRUE

	setmetatile 57, 48, METATILE_Petalburg_MetalFenceM, TRUE
	setmetatile 57, 49, METATILE_Petalburg_MetalFenceM, TRUE
	setmetatile 57, 50, METATILE_Petalburg_MetalFenceM, TRUE
	setmetatile 57, 51, METATILE_Petalburg_MetalFenceM, TRUE
	end

LumiourIsland_EventScript_LabSign::
	msgbox LumiourIsland_Text_LabSign, MSGBOX_SIGN
	end

LumiourIsland_Text_LabSign:
	.string "Lumiere Island laboratory.$"

LumiourIsland_EventScript_SetLumiourEncounters::
	setvar VAR_ENCOUNTER_STATE, 0
	setvar VAR_LUMIOUR_WILD_SET, 0
	release
	end

LumiourIsland_EventScript_SetIslandEncounters::
	setvar VAR_ENCOUNTER_STATE, 1
	goto_if_eq VAR_LUMIOUR_ISLAND_STATE, 3, LumiourIsland_EventScript_SetMirageIslandEncounter
	goto_if_eq VAR_LUMIOUR_ISLAND_STATE, 1, LumiourIsland_EventScript_SetMemorialPillarEncounter
	end

LumiourIsland_EventScript_SetMirageIslandEncounter::
	setvar VAR_LUMIOUR_WILD_SET, 1
	release
	end

LumiourIsland_EventScript_SetMemorialPillarEncounter::
	setvar VAR_LUMIOUR_WILD_SET, 2
	release
	end

LumiourIsland_Trigger_SetRockClimb::
	lock
	fadescreenswapbuffers FADE_TO_BLACK
	setmetatile 36, 21, METATILE_General_RockClimbBase, TRUE
	setmetatile 36, 20, METATILE_General_RockClimbTop, TRUE
	setmetatile 36, 19, METATILE_General_RockClimbTop, TRUE
	setmetatile 36, 18, METATILE_General_RockClimbTop, TRUE
	setmetatile 36, 17, METATILE_General_RockClimbTop, TRUE
	setmetatile 36, 16, METATILE_General_RockClimbTop, TRUE
	special DrawWholeMapView
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

LumiourIsland_EventScript_MemorialPillarTectonix::
	msgbox LumiourIsland_Text_Tectonix, MSGBOX_DEFAULT
	release
	end

LumiourIsland_Text_Tectonix:
    .string "“Here lies TECTONIX” is engraved\n"
    .string "on a boulder.$"

LumiereIsland_Trigger_SetShore::
	lock
	fadescreenswapbuffers FADE_TO_BLACK
	setmetatile 22, 37, METATILE_General_TallGrass, FALSE
	setmetatile 23, 37, METATILE_General_GrassMarking, FALSE
	setmetatile 22, 40, METATILE_General_StairsShade FALSE
	setmetatile 23, 40, METATILE_General_Stairs, FALSE
	setmetatile 22, 41, METATILE_General_StairsShade, FALSE
	setmetatile 23, 41, METATILE_General_Stairs, FALSE

	setmetatile 22, 38, METATILE_General_Grass1, FALSE
	setmetatile 23, 38, METATILE_General_Grass2, FALSE
	setmetatile 22, 39, METATILE_General_Grass3, FALSE
	setmetatile 23, 39, METATILE_General_Grass4, FALSE

	setmetatile 22, 42, METATILE_General_ShallowWaterMid, FALSE
	setmetatile 23, 42, METATILE_General_ShallowWaterMid, FALSE
	setmetatile 24, 42, METATILE_General_ShallowWaterMid, FALSE
	setmetatile 25, 42, METATILE_General_ShallowWaterMid, FALSE
	setmetatile 26, 42, METATILE_General_ShallowWaterMid, FALSE
	setmetatile 27, 42, METATILE_General_ShallowWaterMid, FALSE
	setmetatile 28, 42, METATILE_General_ShallowWaterEdgeR, TRUE

	setmetatile 22, 43, METATILE_General_ShallowWaterMid, FALSE
	setmetatile 23, 43, METATILE_General_ShallowWaterMid, FALSE
	setmetatile 24, 43, METATILE_General_ShallowWaterMid, FALSE
	setmetatile 25, 43, METATILE_General_ShallowWaterMid, TRUE
	setmetatile 26, 43, METATILE_General_ShallowWaterVertexBR, TRUE
	setmetatile 27, 43, METATILE_General_ShallowWaterEdgeB, TRUE
	setmetatile 28, 43, METATILE_General_ShallowWaterCornerBR, TRUE
	setmetatile 21, 42, METATILE_General_SWCliffR, FALSE
	special DrawWholeMapView
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

LumiereIsland_EventScript_Sailor::
	lock
	faceplayer
	goto_if_set FLAG_HAS_LUSTROUS_ORB, LumiereIsland_EventScript_SailorPostLG
	msgbox LumiereIsland_Text_Sailor, MSGBOX_DEFAULT
	release
	end

LumiereIsland_EventScript_SailorPostLG::
	msgbox LumiereIsland_Text_ThanksAgain, MSGBOX_DEFAULT
	release
	end

LumiereIsland_Text_ThanksAgain:
	.string "{COLOR BLUE}Thanks again for all the help!$"

LumiereIsland_Text_Sailor:
	.string "{COLOR BLUE}Are you a trainer?\p"
	.string "You have to help us. There are trainers\n"
	.string "inside Liberty Garden that won't leave!$"

LumiereIsland_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_HAS_LUSTROUS_ORB, LumiereIsland_EventScript_WomanPostLG
	msgbox LumiereIsland_Text_Woman, MSGBOX_DEFAULT
	release
	end

LumiereIsland_EventScript_WomanPostLG::
	msgbox LumiereIsland_Text_SonIsSafe, MSGBOX_DEFAULT
	release
	end

LumiereIsland_Text_SonIsSafe:
	.string "{COLOR RED}Thank you so much!\p"
	.string "Sorry my son can be so stubborn\n"
	.string "sometimes.$"

LumiereIsland_Text_Woman:
	.string "{COLOR RED}Please, my son won't leave Liberty\n"
	.string "Garden until you battle him!$"

LumiereIsland_Trigger_TrainerWarning::
	lock
	playse SE_PIN
	applymovement LOCALID_BEAUTY, Common_Movement_ExclamationMark
	waitmovement 0
	waitse
	applymovement LOCALID_BEAUTY, LumiereIsland_Movement_Beauty_StepLeft
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	msgbox LumiereIsland_Text_BeCareful, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY, LumiereIsland_Movement_Beauty_Stepback
	waitmovement 0
	clearflag FLAG_LIBERTY_AROMA_LADY
	clearflag FLAG_LIBERTY_CAMPER
	clearflag FLAG_LIBERTY_GENTELMAN
	clearflag FLAG_LIBERTY_LASS
	clearflag FLAG_LIBERTY_BOY
	release
	end

LumiereIsland_EventScript_Beauty::
	lock
	faceplayer
	goto_if_set FLAG_HAS_LUSTROUS_ORB, LumiereIsland_EventScript_Beauty2
	msgbox LumiereIsland_Text_BeCareful, MSGBOX_DEFAULT
	clearflag FLAG_LIBERTY_AROMA_LADY
	clearflag FLAG_LIBERTY_CAMPER
	clearflag FLAG_LIBERTY_GENTELMAN
	clearflag FLAG_LIBERTY_LASS
	clearflag FLAG_LIBERTY_BOY
	release
	end

LumiereIsland_EventScript_Beauty2::
	msgbox LumiereIsland_Text_ComingFromCastelia, MSGBOX_DEFAULT
	release
	end

LumiereIsland_Text_ComingFromCastelia:
	.string "{COLOR RED}I heard a boat from Castelia City\n"
	.string "is being sent over to pick us up.\p"
	.string "How close is Lumiere Island to the\n"
	.string "Unova Region?$"


LumiereIsland_Text_BeCareful:
	.string "{COLOR RED}Before you go inside make sure you're\n"
	.string "ready to have a Pokémon battle.\p"
	.string "There are five trainers inside who\n"
	.string "will only leave if you defeat them\l"
	.string "all in a row.$"

LumiereIsland_Movement_Beauty_StepLeft:
	walk_left
	step_end

LumiereIsland_Movement_Beauty_Stepback:
	walk_right
	face_left
	step_end

LumiereIsland_EventScript_Gentleman::
	lock
	faceplayer
	msgbox LumiereIsland_Text_SentRescue, MSGBOX_DEFAULT
	release
	end

LumiereIsland_Text_SentRescue:
	.string "{COLOR BLUE}This is quite a strange Island\p"
	.string "Exploring here reminds me of all the\n"
	.string "traveling I did when I was young.$"

LumiereIsland_EventScript_SchoolKid::
	lock
	faceplayer
	msgbox LumiereIsland_Text_MissSchool, MSGBOX_DEFAULT
	release
	end

LumiereIsland_Text_MissSchool:
	.string "{COLOR BLUE}I think I may have to miss a day\n"
	.string "of school if the rescue boat doesn't\l"
	.string "arrive soon.$"

LumiereIsland_EventScript_Camper::
	lock
	faceplayer
	msgbox LumiereIsland_Text_GreatPlaceTo, MSGBOX_DEFAULT
	release
	end

LumiereIsland_Text_GreatPlaceTo:
	.string "{COLOR BLUE}Lumiere Island would be a perfect\n"
	.string "place to setup camp!$"

LumiereIsland_EventScript_AromaLady::
	lock
	faceplayer
	msgbox LumiereIsland_Text_TheseFlowers, MSGBOX_DEFAULT
	release
	end

LumiereIsland_Text_TheseFlowers:
	.string "{COLOR RED}I've never seen flowers like this in\n"
	.string "the Unova Region!$"

LumiereIsland_EventScript_Lass::
	lock
	faceplayer
	msgbox LumiereIsland_Text_ProfCygnusWeird, MSGBOX_DEFAULT
	release
	end

LumiereIsland_Text_ProfCygnusWeird:
	.string "{COLOR RED}Professor Cygnus is quite a strange\n"
	.string "fella, isn't he?$"

LumiereIsland_Trigger_SetPalkiaSequenceTiles3::
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
	waitse
	waitmovement 0
	fadescreenswapbuffers FADE_TO_BLACK
	setvar VAR_PALKIA_SEQUENCE_STATE, 4
	setmetatile 47, 16, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 48, 16, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 49, 16, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 47, 17, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 48, 17, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 49, 17, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 22, 9, METATILE_General_RockGrassCliffL, TRUE
	setmetatile 22, 10, METATILE_General_RockGrassCliffL, TRUE
	setmetatile 22, 11, METATILE_General_RockGrassCliffL, TRUE
	setmetatile 22, 12, METATILE_General_RockGrassCliffL, TRUE
	setmetatile 23, 8, METATILE_General_RockRockCliffL, TRUE
	setmetatile 23, 9, METATILE_General_RockRockCliffL, TRUE
	setmetatile 23, 10, METATILE_General_RockRockCliffL, TRUE
	setmetatile 23, 11, METATILE_General_RockRockCliffL, TRUE
	special DrawWholeMapView
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

LumiereIsland_Trigger_SetPalkiaSequenceTiles4::
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
	waitse
	waitmovement 0
	fadescreenswapbuffers FADE_TO_BLACK
	setvar VAR_PALKIA_SEQUENCE_STATE, 5
	setmetatile 15, 19, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 16, 19, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 17, 19, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 18, 19, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 19, 19, METATILE_General_RockGrassCliffBR, TRUE
	setmetatile 20, 19, METATILE_General_TreeBL, TRUE
	setmetatile 21, 19, METATILE_General_TreeBR, TRUE

	setmetatile 15, 20, METATILE_General_Grass3, FALSE
	setmetatile 16, 20, METATILE_General_Grass4, FALSE
	setmetatile 17, 20, METATILE_General_Grass3, FALSE
	setmetatile 18, 20, METATILE_General_Grass4, FALSE
	setmetatile 19, 20, METATILE_General_Grass3, FALSE
	setmetatile 20, 20, METATILE_General_Grass4, FALSE
	setmetatile 21, 20, METATILE_General_Grass3, FALSE

	setmetatile 15, 21, METATILE_General_Grass1, FALSE
	setmetatile 16, 21, METATILE_General_Grass2, FALSE
	setmetatile 17, 21, METATILE_General_Grass1, FALSE
	setmetatile 18, 21, METATILE_General_Grass2, FALSE
	setmetatile 19, 21, METATILE_General_Grass1, FALSE
	setmetatile 20, 21, METATILE_General_Grass2, FALSE
	setmetatile 21, 21, METATILE_General_Grass1, FALSE

	setmetatile 15, 22, METATILE_General_Grass3, FALSE
	setmetatile 16, 22, METATILE_General_Grass4, FALSE
	setmetatile 17, 22, METATILE_General_Grass3, FALSE
	setmetatile 18, 22, METATILE_General_Grass4, FALSE
	setmetatile 19, 22, METATILE_General_Grass3, FALSE
	setmetatile 20, 22, METATILE_General_Grass4, FALSE
	setmetatile 21, 22, METATILE_General_Grass3, FALSE

	setmetatile 18, 23, METATILE_General_Grass2, FALSE
	setmetatile 19, 23, METATILE_General_Grass1, FALSE
	setmetatile 20, 23, METATILE_General_Grass2, FALSE

	special DrawWholeMapView
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

LumiereIsland_Trigger_SetPalkiaSequenceTiles5::
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
	waitse
	waitmovement 0
	fadescreenswapbuffers FADE_TO_BLACK
	setvar VAR_PALKIA_SEQUENCE_STATE, 6
	setmetatile 32, 26, METATILE_General_CalmWater, TRUE
	setmetatile 33, 26, METATILE_General_CalmWater, TRUE
	setmetatile 34, 26, METATILE_General_CalmWater, TRUE
	setmetatile 35, 26, METATILE_General_CalmWater, TRUE
	setmetatile 36, 26, METATILE_General_CalmWater, TRUE
	setmetatile 37, 26, METATILE_General_CalmWater, TRUE
	setmetatile 38, 26, METATILE_General_CalmWater, TRUE
	setmetatile 39, 26, METATILE_General_CalmWater, TRUE
	setmetatile 40, 26, METATILE_General_CalmWater, TRUE
	setmetatile 41, 26, METATILE_General_CalmWater, TRUE

	setmetatile 32, 27, METATILE_General_CalmWater, TRUE
	setmetatile 33, 27, METATILE_General_CalmWater, TRUE
	setmetatile 34, 27, METATILE_General_CalmWater, TRUE
	setmetatile 35, 27, METATILE_General_CalmWater, TRUE
	setmetatile 36, 27, METATILE_General_CalmWater, TRUE
	setmetatile 37, 27, METATILE_General_CalmWater, TRUE
	setmetatile 38, 27, METATILE_General_CalmWater, TRUE
	setmetatile 39, 27, METATILE_General_CalmWater, TRUE
	setmetatile 40, 27, METATILE_General_CalmWater, TRUE
	setmetatile 41, 27, METATILE_General_CalmWater, TRUE

	setmetatile 32, 28, METATILE_General_CalmWater, TRUE
	setmetatile 33, 28, METATILE_General_CalmWater, TRUE
	setmetatile 34, 28, METATILE_General_CalmWater, TRUE
	setmetatile 35, 28, METATILE_General_CalmWater, TRUE
	setmetatile 36, 28, METATILE_General_CalmWater, TRUE
	setmetatile 37, 28, METATILE_General_CalmWater, TRUE
	setmetatile 38, 28, METATILE_General_CalmWater, TRUE
	setmetatile 39, 28, METATILE_General_CalmWater, TRUE
	setmetatile 40, 28, METATILE_General_CalmWater, TRUE
	setmetatile 41, 28, METATILE_General_CalmWater, TRUE

	setmetatile 30, 26, METATILE_General_RockRockCliffR, TRUE
	setmetatile 30, 27, METATILE_General_RockRockCliffR, TRUE
	setmetatile 30, 28, METATILE_General_RockRockCliffR, TRUE
	setmetatile 31, 26, METATILE_General_WaterCliffR, TRUE
	setmetatile 31, 27, METATILE_General_WaterCliffR, TRUE
	setmetatile 31, 28, METATILE_General_WaterCliffR, TRUE


	setmetatile 43, 26, METATILE_General_RockRockCliffL, TRUE
	setmetatile 43, 27, METATILE_General_RockRockCliffL, TRUE
	setmetatile 43, 28, METATILE_General_RockRockCliffL, TRUE
	setmetatile 42, 26, METATILE_General_WaterCliffL, TRUE
	setmetatile 42, 27, METATILE_General_WaterCliffL, TRUE
	setmetatile 42, 28, METATILE_General_WaterCliffL, TRUE

	special DrawWholeMapView
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

LumiereIsland_Trigger_SetPalkiaSequenceTiles6::
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
	waitse
	waitmovement 0
	fadescreenswapbuffers FADE_TO_BLACK
	setvar VAR_PALKIA_SEQUENCE_STATE, 7
	setmetatile 58, 14, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 58, 15, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 58, 16, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 58, 17, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 63, 9, METATILE_General_CaveEntrance_Bottom, FALSE
	special DrawWholeMapView
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

LumiereIsland_EventScript_SetVisceraCaveClosed::
	setmetatile 49, 9, METATILE_General_RockWall_GrassBase, TRUE
	end

LumiereIsland_EventScript_PalkiaTiles4::
	setmetatile 49, 9, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 47, 16, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 48, 16, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 49, 16, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 47, 17, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 48, 17, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 49, 17, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 22, 9, METATILE_General_RockGrassCliffL, TRUE
	setmetatile 22, 10, METATILE_General_RockGrassCliffL, TRUE
	setmetatile 22, 11, METATILE_General_RockGrassCliffL, TRUE
	setmetatile 22, 12, METATILE_General_RockGrassCliffL, TRUE
	setmetatile 23, 8, METATILE_General_RockRockCliffL, TRUE
	setmetatile 23, 9, METATILE_General_RockRockCliffL, TRUE
	setmetatile 23, 10, METATILE_General_RockRockCliffL, TRUE
	setmetatile 23, 11, METATILE_General_RockRockCliffL, TRUE
	end

LumiereIsland_EventScript_PalkiaTiles5::
	setmetatile 49, 9, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 47, 16, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 48, 16, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 49, 16, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 47, 17, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 48, 17, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 49, 17, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 22, 9, METATILE_General_RockGrassCliffL, TRUE
	setmetatile 22, 10, METATILE_General_RockGrassCliffL, TRUE
	setmetatile 22, 11, METATILE_General_RockGrassCliffL, TRUE
	setmetatile 22, 12, METATILE_General_RockGrassCliffL, TRUE
	setmetatile 23, 8, METATILE_General_RockRockCliffL, TRUE
	setmetatile 23, 9, METATILE_General_RockRockCliffL, TRUE
	setmetatile 23, 10, METATILE_General_RockRockCliffL, TRUE
	setmetatile 23, 11, METATILE_General_RockRockCliffL, TRUE
	setmetatile 15, 19, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 16, 19, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 17, 19, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 18, 19, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 19, 19, METATILE_General_RockGrassCliffBR, TRUE
	setmetatile 20, 19, METATILE_General_TreeBL, TRUE
	setmetatile 21, 19, METATILE_General_TreeBR, TRUE

	setmetatile 15, 20, METATILE_General_Grass3, FALSE
	setmetatile 16, 20, METATILE_General_Grass4, FALSE
	setmetatile 17, 20, METATILE_General_Grass3, FALSE
	setmetatile 18, 20, METATILE_General_Grass4, FALSE
	setmetatile 19, 20, METATILE_General_Grass3, FALSE
	setmetatile 20, 20, METATILE_General_Grass4, FALSE
	setmetatile 21, 20, METATILE_General_Grass3, FALSE

	setmetatile 15, 21, METATILE_General_Grass1, FALSE
	setmetatile 16, 21, METATILE_General_Grass2, FALSE
	setmetatile 17, 21, METATILE_General_Grass1, FALSE
	setmetatile 18, 21, METATILE_General_Grass2, FALSE
	setmetatile 19, 21, METATILE_General_Grass1, FALSE
	setmetatile 20, 21, METATILE_General_Grass2, FALSE
	setmetatile 21, 21, METATILE_General_Grass1, FALSE

	setmetatile 15, 22, METATILE_General_Grass3, FALSE
	setmetatile 16, 22, METATILE_General_Grass4, FALSE
	setmetatile 17, 22, METATILE_General_Grass3, FALSE
	setmetatile 18, 22, METATILE_General_Grass4, FALSE
	setmetatile 19, 22, METATILE_General_Grass3, FALSE
	setmetatile 20, 22, METATILE_General_Grass4, FALSE
	setmetatile 21, 22, METATILE_General_Grass3, FALSE

	setmetatile 18, 23, METATILE_General_Grass2, FALSE
	setmetatile 19, 23, METATILE_General_Grass1, FALSE
	setmetatile 20, 23, METATILE_General_Grass2, FALSE
	end

LumiereIsland_EventScript_PalkiaTiles6::
	setmetatile 49, 9, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 47, 16, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 48, 16, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 49, 16, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 47, 17, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 48, 17, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 49, 17, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 22, 9, METATILE_General_RockGrassCliffL, TRUE
	setmetatile 22, 10, METATILE_General_RockGrassCliffL, TRUE
	setmetatile 22, 11, METATILE_General_RockGrassCliffL, TRUE
	setmetatile 22, 12, METATILE_General_RockGrassCliffL, TRUE
	setmetatile 23, 8, METATILE_General_RockRockCliffL, TRUE
	setmetatile 23, 9, METATILE_General_RockRockCliffL, TRUE
	setmetatile 23, 10, METATILE_General_RockRockCliffL, TRUE
	setmetatile 23, 11, METATILE_General_RockRockCliffL, TRUE
	setmetatile 15, 19, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 16, 19, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 17, 19, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 18, 19, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 19, 19, METATILE_General_RockGrassCliffBR, TRUE
	setmetatile 20, 19, METATILE_General_TreeBL, TRUE
	setmetatile 21, 19, METATILE_General_TreeBR, TRUE

	setmetatile 15, 20, METATILE_General_Grass3, FALSE
	setmetatile 16, 20, METATILE_General_Grass4, FALSE
	setmetatile 17, 20, METATILE_General_Grass3, FALSE
	setmetatile 18, 20, METATILE_General_Grass4, FALSE
	setmetatile 19, 20, METATILE_General_Grass3, FALSE
	setmetatile 20, 20, METATILE_General_Grass4, FALSE
	setmetatile 21, 20, METATILE_General_Grass3, FALSE

	setmetatile 15, 21, METATILE_General_Grass1, FALSE
	setmetatile 16, 21, METATILE_General_Grass2, FALSE
	setmetatile 17, 21, METATILE_General_Grass1, FALSE
	setmetatile 18, 21, METATILE_General_Grass2, FALSE
	setmetatile 19, 21, METATILE_General_Grass1, FALSE
	setmetatile 20, 21, METATILE_General_Grass2, FALSE
	setmetatile 21, 21, METATILE_General_Grass1, FALSE

	setmetatile 15, 22, METATILE_General_Grass3, FALSE
	setmetatile 16, 22, METATILE_General_Grass4, FALSE
	setmetatile 17, 22, METATILE_General_Grass3, FALSE
	setmetatile 18, 22, METATILE_General_Grass4, FALSE
	setmetatile 19, 22, METATILE_General_Grass3, FALSE
	setmetatile 20, 22, METATILE_General_Grass4, FALSE
	setmetatile 21, 22, METATILE_General_Grass3, FALSE

	setmetatile 18, 23, METATILE_General_Grass2, FALSE
	setmetatile 19, 23, METATILE_General_Grass1, FALSE
	setmetatile 20, 23, METATILE_General_Grass2, FALSE

	setmetatile 32, 26, METATILE_General_CalmWater, TRUE
	setmetatile 33, 26, METATILE_General_CalmWater, TRUE
	setmetatile 34, 26, METATILE_General_CalmWater, TRUE
	setmetatile 35, 26, METATILE_General_CalmWater, TRUE
	setmetatile 36, 26, METATILE_General_CalmWater, TRUE
	setmetatile 37, 26, METATILE_General_CalmWater, TRUE
	setmetatile 38, 26, METATILE_General_CalmWater, TRUE
	setmetatile 39, 26, METATILE_General_CalmWater, TRUE
	setmetatile 40, 26, METATILE_General_CalmWater, TRUE
	setmetatile 41, 26, METATILE_General_CalmWater, TRUE

	setmetatile 32, 27, METATILE_General_CalmWater, TRUE
	setmetatile 33, 27, METATILE_General_CalmWater, TRUE
	setmetatile 34, 27, METATILE_General_CalmWater, TRUE
	setmetatile 35, 27, METATILE_General_CalmWater, TRUE
	setmetatile 36, 27, METATILE_General_CalmWater, TRUE
	setmetatile 37, 27, METATILE_General_CalmWater, TRUE
	setmetatile 38, 27, METATILE_General_CalmWater, TRUE
	setmetatile 39, 27, METATILE_General_CalmWater, TRUE
	setmetatile 40, 27, METATILE_General_CalmWater, TRUE
	setmetatile 41, 27, METATILE_General_CalmWater, TRUE

	setmetatile 32, 28, METATILE_General_CalmWater, TRUE
	setmetatile 33, 28, METATILE_General_CalmWater, TRUE
	setmetatile 34, 28, METATILE_General_CalmWater, TRUE
	setmetatile 35, 28, METATILE_General_CalmWater, TRUE
	setmetatile 36, 28, METATILE_General_CalmWater, TRUE
	setmetatile 37, 28, METATILE_General_CalmWater, TRUE
	setmetatile 38, 28, METATILE_General_CalmWater, TRUE
	setmetatile 39, 28, METATILE_General_CalmWater, TRUE
	setmetatile 40, 28, METATILE_General_CalmWater, TRUE
	setmetatile 41, 28, METATILE_General_CalmWater, TRUE

	setmetatile 30, 26, METATILE_General_RockRockCliffR, TRUE
	setmetatile 30, 27, METATILE_General_RockRockCliffR, TRUE
	setmetatile 30, 28, METATILE_General_RockRockCliffR, TRUE
	setmetatile 31, 26, METATILE_General_WaterCliffR, TRUE
	setmetatile 31, 27, METATILE_General_WaterCliffR, TRUE
	setmetatile 31, 28, METATILE_General_WaterCliffR, TRUE


	setmetatile 43, 26, METATILE_General_RockRockCliffL, TRUE
	setmetatile 43, 27, METATILE_General_RockRockCliffL, TRUE
	setmetatile 43, 28, METATILE_General_RockRockCliffL, TRUE
	setmetatile 42, 26, METATILE_General_WaterCliffL, TRUE
	setmetatile 42, 27, METATILE_General_WaterCliffL, TRUE
	setmetatile 42, 28, METATILE_General_WaterCliffL, TRUE
	end

LumiereIsland_EventScript_PalkiaTiles7::
	setmetatile 49, 9, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 47, 16, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 48, 16, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 49, 16, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 47, 17, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 48, 17, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 49, 17, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 22, 9, METATILE_General_RockGrassCliffL, TRUE
	setmetatile 22, 10, METATILE_General_RockGrassCliffL, TRUE
	setmetatile 22, 11, METATILE_General_RockGrassCliffL, TRUE
	setmetatile 22, 12, METATILE_General_RockGrassCliffL, TRUE
	setmetatile 23, 8, METATILE_General_RockRockCliffL, TRUE
	setmetatile 23, 9, METATILE_General_RockRockCliffL, TRUE
	setmetatile 23, 10, METATILE_General_RockRockCliffL, TRUE
	setmetatile 23, 11, METATILE_General_RockRockCliffL, TRUE
	setmetatile 15, 19, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 16, 19, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 17, 19, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 18, 19, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 19, 19, METATILE_General_RockGrassCliffBR, TRUE
	setmetatile 20, 19, METATILE_General_TreeBL, TRUE
	setmetatile 21, 19, METATILE_General_TreeBR, TRUE

	setmetatile 15, 20, METATILE_General_Grass3, FALSE
	setmetatile 16, 20, METATILE_General_Grass4, FALSE
	setmetatile 17, 20, METATILE_General_Grass3, FALSE
	setmetatile 18, 20, METATILE_General_Grass4, FALSE
	setmetatile 19, 20, METATILE_General_Grass3, FALSE
	setmetatile 20, 20, METATILE_General_Grass4, FALSE
	setmetatile 21, 20, METATILE_General_Grass3, FALSE

	setmetatile 15, 21, METATILE_General_Grass1, FALSE
	setmetatile 16, 21, METATILE_General_Grass2, FALSE
	setmetatile 17, 21, METATILE_General_Grass1, FALSE
	setmetatile 18, 21, METATILE_General_Grass2, FALSE
	setmetatile 19, 21, METATILE_General_Grass1, FALSE
	setmetatile 20, 21, METATILE_General_Grass2, FALSE
	setmetatile 21, 21, METATILE_General_Grass1, FALSE

	setmetatile 15, 22, METATILE_General_Grass3, FALSE
	setmetatile 16, 22, METATILE_General_Grass4, FALSE
	setmetatile 17, 22, METATILE_General_Grass3, FALSE
	setmetatile 18, 22, METATILE_General_Grass4, FALSE
	setmetatile 19, 22, METATILE_General_Grass3, FALSE
	setmetatile 20, 22, METATILE_General_Grass4, FALSE
	setmetatile 21, 22, METATILE_General_Grass3, FALSE

	setmetatile 18, 23, METATILE_General_Grass2, FALSE
	setmetatile 19, 23, METATILE_General_Grass1, FALSE
	setmetatile 20, 23, METATILE_General_Grass2, FALSE

	setmetatile 32, 26, METATILE_General_CalmWater, TRUE
	setmetatile 33, 26, METATILE_General_CalmWater, TRUE
	setmetatile 34, 26, METATILE_General_CalmWater, TRUE
	setmetatile 35, 26, METATILE_General_CalmWater, TRUE
	setmetatile 36, 26, METATILE_General_CalmWater, TRUE
	setmetatile 37, 26, METATILE_General_CalmWater, TRUE
	setmetatile 38, 26, METATILE_General_CalmWater, TRUE
	setmetatile 39, 26, METATILE_General_CalmWater, TRUE
	setmetatile 40, 26, METATILE_General_CalmWater, TRUE
	setmetatile 41, 26, METATILE_General_CalmWater, TRUE

	setmetatile 32, 27, METATILE_General_CalmWater, TRUE
	setmetatile 33, 27, METATILE_General_CalmWater, TRUE
	setmetatile 34, 27, METATILE_General_CalmWater, TRUE
	setmetatile 35, 27, METATILE_General_CalmWater, TRUE
	setmetatile 36, 27, METATILE_General_CalmWater, TRUE
	setmetatile 37, 27, METATILE_General_CalmWater, TRUE
	setmetatile 38, 27, METATILE_General_CalmWater, TRUE
	setmetatile 39, 27, METATILE_General_CalmWater, TRUE
	setmetatile 40, 27, METATILE_General_CalmWater, TRUE
	setmetatile 41, 27, METATILE_General_CalmWater, TRUE

	setmetatile 32, 28, METATILE_General_CalmWater, TRUE
	setmetatile 33, 28, METATILE_General_CalmWater, TRUE
	setmetatile 34, 28, METATILE_General_CalmWater, TRUE
	setmetatile 35, 28, METATILE_General_CalmWater, TRUE
	setmetatile 36, 28, METATILE_General_CalmWater, TRUE
	setmetatile 37, 28, METATILE_General_CalmWater, TRUE
	setmetatile 38, 28, METATILE_General_CalmWater, TRUE
	setmetatile 39, 28, METATILE_General_CalmWater, TRUE
	setmetatile 40, 28, METATILE_General_CalmWater, TRUE
	setmetatile 41, 28, METATILE_General_CalmWater, TRUE

	setmetatile 30, 26, METATILE_General_RockRockCliffR, TRUE
	setmetatile 30, 27, METATILE_General_RockRockCliffR, TRUE
	setmetatile 30, 28, METATILE_General_RockRockCliffR, TRUE
	setmetatile 31, 26, METATILE_General_WaterCliffR, TRUE
	setmetatile 31, 27, METATILE_General_WaterCliffR, TRUE
	setmetatile 31, 28, METATILE_General_WaterCliffR, TRUE


	setmetatile 43, 26, METATILE_General_RockRockCliffL, TRUE
	setmetatile 43, 27, METATILE_General_RockRockCliffL, TRUE
	setmetatile 43, 28, METATILE_General_RockRockCliffL, TRUE
	setmetatile 42, 26, METATILE_General_WaterCliffL, TRUE
	setmetatile 42, 27, METATILE_General_WaterCliffL, TRUE
	setmetatile 42, 28, METATILE_General_WaterCliffL, TRUE
	setmetatile 58, 14, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 58, 15, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 58, 16, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 58, 17, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 63, 9, METATILE_General_CaveEntrance_Bottom, FALSE
	end

LumiereIsland_Trigger_BrendanMay::
	lock
	setvar VAR_MIRAGE_ISLAND_BATTLE, 2
	setobjectxyperm LOCALID_BRENDAN, 60, 59
	setobjectxyperm LOCALID_MAY, 60, 59
	addobject LOCALID_BRENDAN
	addobject LOCALID_MAY
	applymovement LOCALID_MAY, LumiereIsland_Movement_MayWalkUp
	waitmovement 0
	msgbox LumiereIsland_Text_MayBerryOverHere, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BRENDAN, LumiereIsland_Movement_BrendanWalkUp
	waitmovement 0
	applymovement LOCALID_MAY, Common_Movement_FaceLeft
	waitmovement 0
	msgbox LumiereIsland_Text_StrangeBerryConversation, MSGBOX_DEFAULT
	closemessage
	release
	end

LumiereIsland_Movement_MayWalkUp:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_up
	walk_up
	step_end

LumiereIsland_Movement_BrendanWalkUp:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	face_right
	step_end

LumiereIsland_Text_MayBerryOverHere:
	.string "{COLOR RED}May: Brendan, there's a strange berry\n"
	.string "tree over here!$"

LumiereIsland_Text_StrangeBerryConversation:
	.string "{COLOR BLUE}Brendan: I've never seen this one before.\p"
	.string "{COLOR RED} May: We'll have to send one to Professor\n"
	.string "Birch.$"

LumiereIsland_EventScript_May::
	lock
	faceplayer
	playse SE_PIN
	applymovement LOCALID_MAY, Common_Movement_ExclamationMark
	waitmovement 0
	waitse
	applymovement LOCALID_BRENDAN, Common_Movement_FaceDown
	waitmovement 0
	trainerbattle_double TRAINER_MIU_AND_YUKI, LumiereIsland_Text_MayWeFoundFirst, LumiereIsland_Text_BrendanMayDefeat, LumiereIsland_Text_BrendanMayNotEnoughMons
	msgbox Route123_Text_MiuPostBattle, MSGBOX_AUTOCLOSE
	end

LumiereIsland_EventScript_Brendan::
	lock
	faceplayer
	playse SE_PIN
	applymovement LOCALID_BRENDAN, Common_Movement_ExclamationMark
	waitmovement 0
	waitse
	applymovement LOCALID_MAY, Common_Movement_FaceDown
	waitmovement 0
	trainerbattle_double TRAINER_MIU_AND_YUKI, LumiereIsland_Text_BrendanWeFoundFirst, LumiereIsland_Text_BrendanMayDefeat, LumiereIsland_Text_BrendanMayNotEnoughMons
	msgbox Route123_Text_MiuPostBattle, MSGBOX_AUTOCLOSE
	end

LumiereIsland_Text_MayWeFoundFirst:
	.string "{COLOR RED}Hey! We found this berry first!\p"
	.string "{COLOR BLUE}I know. We should have a Pokémon\n"
	.string "battle to settle it!$"

LumiereIsland_Text_BrendanWeFoundFirst:
	.string "{COLOR BLUE}Hey! We found this berry first!\p"
	.string "{COLOR RED}I know. We should have a Pokémon\n"
	.string "battle to settle it!$"

LumiereIsland_Text_BrendanMayDefeat:
	.string "Alright I guess you can have the berry.$"

LumiereIsland_Text_BrendanMayNotEnoughMons:
	.string "You don't have enough Pokémon.$"

