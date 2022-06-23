VisceraCave_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, VisceraCave_OnLoad
	.byte 0

VisceraCave_OnLoad:
	goto_if_eq VAR_LUMIOUR_ISLAND_STATE, 1, VisceraCave_EventScript_SetTiles1
	goto_if_eq VAR_LUMIOUR_ISLAND_STATE, 2, VisceraCave_EventScript_SetTiles2
	goto_if_eq VAR_LUMIOUR_ISLAND_STATE, 3, VisceraCave_EventScript_SetTiles3
	goto_if_eq VAR_LUMIOUR_ISLAND_STATE, 4, VisceraCave_EventScript_SetTiles4
	goto_if_eq VAR_LUMIOUR_ISLAND_STATE, 5, VisceraCave_EventScript_SetTiles5
	end

VisceraCave_EventScript_Fossil1::
	lock
	random 2
	switch VAR_RESULT
	case 0, VisceraCave_EventScript_Helix
	case 1, VisceraCave_EventScript_Dome
	end

VisceraCave_EventScript_Helix:
	giveitem ITEM_HELIX_FOSSIL, 1
	removeobject VAR_LAST_TALKED
	setflag FLAG_VISCERA_CAVE_FOSSIL_1
	release
	end

VisceraCave_EventScript_Dome:
	giveitem ITEM_DOME_FOSSIL, 1
	removeobject VAR_LAST_TALKED
	setflag FLAG_VISCERA_CAVE_FOSSIL_1
	release
	end

VisceraCave_EventScript_Fossil2::
	lock
	random 2
	switch VAR_RESULT
	case 0, VisceraCave_EventScript_Root
	case 1, VisceraCave_EventScript_Claw
	end

VisceraCave_EventScript_Root:
	giveitem ITEM_ROOT_FOSSIL, 1
	removeobject VAR_LAST_TALKED
	setflag FLAG_VISCERA_CAVE_FOSSIL_2
	release
	end

VisceraCave_EventScript_Claw:
	giveitem ITEM_CLAW_FOSSIL, 1
	removeobject VAR_LAST_TALKED
	setflag FLAG_VISCERA_CAVE_FOSSIL_2
	release
	end

VisceraCave_EventScript_Fossil3::
	lock
	random 2
	switch VAR_RESULT
	case 0, VisceraCave_EventScript_Armor
	case 1, VisceraCave_EventScript_Skull
	end

VisceraCave_EventScript_Armor:
	giveitem ITEM_ARMOR_FOSSIL, 1
	removeobject VAR_LAST_TALKED
	setflag FLAG_VISCERA_CAVE_FOSSIL_3
	release
	end

VisceraCave_EventScript_Skull:
	giveitem ITEM_SKULL_FOSSIL, 1
	removeobject VAR_LAST_TALKED
	setflag FLAG_VISCERA_CAVE_FOSSIL_3
	release
	end

VisceraCave_EventScript_Fossil4::
	lock
	random 2
	switch VAR_RESULT
	case 0, VisceraCave_EventScript_Cover
	case 1, VisceraCave_EventScript_Plume
	end

VisceraCave_EventScript_Cover:
	giveitem ITEM_COVER_FOSSIL, 1
	removeobject VAR_LAST_TALKED
	setflag FLAG_VISCERA_CAVE_FOSSIL_4
	release
	end

VisceraCave_EventScript_Plume:
	giveitem ITEM_PLUME_FOSSIL, 1
	removeobject VAR_LAST_TALKED
	setflag FLAG_VISCERA_CAVE_FOSSIL_4
	release
	end

VisceraCave_EventScript_SetTiles1::
	setmetatile 11, 12, METATILE_Fortree_CaveStairs, FALSE
	setmetatile 12, 12, METATILE_Fortree_CaveStairs, FALSE
	setmetatile 13, 12, METATILE_Fortree_CaveStairs, FALSE
	setmetatile 11, 13, METATILE_Fortree_CaveStairs, FALSE
	setmetatile 12, 13, METATILE_Fortree_CaveStairs, FALSE
	setmetatile 13, 13, METATILE_Fortree_CaveStairs, FALSE
	end

VisceraCave_EventScript_SetTiles2::
	setmetatile 27, 15, METATILE_Fortree_CaveStairs, FALSE
	setmetatile 28, 15, METATILE_Fortree_CaveStairs, FALSE
	setmetatile 27, 16, METATILE_Fortree_CaveStairs, FALSE
	setmetatile 28, 16, METATILE_Fortree_CaveStairs, FALSE
	setmetatile 11, 12, METATILE_Fortree_CaveStairs, FALSE
	setmetatile 12, 12, METATILE_Fortree_CaveStairs, FALSE
	setmetatile 13, 12, METATILE_Fortree_CaveStairs, FALSE
	setmetatile 11, 13, METATILE_Fortree_CaveStairs, FALSE
	setmetatile 12, 13, METATILE_Fortree_CaveStairs, FALSE
	setmetatile 13, 13, METATILE_Fortree_CaveStairs, FALSE
	end

VisceraCave_EventScript_SetTiles3::
	setmetatile 34, 9, METATILE_Fortree_BridgeT, FALSE
	setmetatile 35, 9, METATILE_Fortree_BridgeT, FALSE
	setmetatile 36, 9, METATILE_Fortree_BridgeT, FALSE
	setmetatile 37, 9, METATILE_Fortree_BridgeT, FALSE
	setmetatile 38, 9, METATILE_Fortree_BridgeT, FALSE
	setmetatile 39, 9, METATILE_Fortree_BridgeT, FALSE
	setmetatile 40, 9, METATILE_Fortree_BridgeT, FALSE
	setmetatile 41, 9, METATILE_Fortree_BridgeT, FALSE
	setmetatile 42, 9, METATILE_Fortree_BridgeT, FALSE
	setmetatile 43, 9, METATILE_Fortree_BridgeT, FALSE
	setmetatile 34, 10, METATILE_Fortree_BridgeM, FALSE
	setmetatile 35, 10, METATILE_Fortree_BridgeM, FALSE
	setmetatile 36, 10, METATILE_Fortree_BridgeM, FALSE
	setmetatile 37, 10, METATILE_Fortree_BridgeM, FALSE
	setmetatile 38, 10, METATILE_Fortree_BridgeM, FALSE
	setmetatile 39, 10, METATILE_Fortree_BridgeM, FALSE
	setmetatile 40, 10, METATILE_Fortree_BridgeM, FALSE
	setmetatile 41, 10, METATILE_Fortree_BridgeM, FALSE
	setmetatile 42, 10, METATILE_Fortree_BridgeM, FALSE
	setmetatile 43, 10, METATILE_Fortree_BridgeM, FALSE
	setmetatile 34, 11, METATILE_Fortree_BridgeB, FALSE
	setmetatile 35, 11, METATILE_Fortree_BridgeB, FALSE
	setmetatile 36, 11, METATILE_Fortree_BridgeB, FALSE
	setmetatile 37, 11, METATILE_Fortree_BridgeB, FALSE
	setmetatile 38, 11, METATILE_Fortree_BridgeB, FALSE
	setmetatile 39, 11, METATILE_Fortree_BridgeB, FALSE
	setmetatile 40, 11, METATILE_Fortree_BridgeB, FALSE
	setmetatile 41, 11, METATILE_Fortree_BridgeB, FALSE
	setmetatile 42, 11, METATILE_Fortree_BridgeB, FALSE
	setmetatile 43, 11, METATILE_Fortree_BridgeB, FALSE
	setmetatile 27, 15, METATILE_Fortree_CaveStairs, FALSE
	setmetatile 28, 15, METATILE_Fortree_CaveStairs, FALSE
	setmetatile 27, 16, METATILE_Fortree_CaveStairs, FALSE
	setmetatile 28, 16, METATILE_Fortree_CaveStairs, FALSE
	setmetatile 11, 12, METATILE_Fortree_CaveStairs, FALSE
	setmetatile 12, 12, METATILE_Fortree_CaveStairs, FALSE
	setmetatile 13, 12, METATILE_Fortree_CaveStairs, FALSE
	setmetatile 11, 13, METATILE_Fortree_CaveStairs, FALSE
	setmetatile 12, 13, METATILE_Fortree_CaveStairs, FALSE
	setmetatile 13, 13, METATILE_Fortree_CaveStairs, FALSE
	end

VisceraCave_EventScript_SetTiles4::
	setmetatile 47, 13, METATILE_Fortree_CaveStairs, FALSE
	setmetatile 48, 13, METATILE_Fortree_CaveStairs, FALSE
	setmetatile 49, 13, METATILE_Fortree_CaveStairs, FALSE
	setmetatile 47, 14, METATILE_Fortree_CaveStairs, FALSE
	setmetatile 48, 14, METATILE_Fortree_CaveStairs, FALSE
	setmetatile 49, 14, METATILE_Fortree_CaveStairs, FALSE
	setmetatile 34, 9, METATILE_Fortree_BridgeT, FALSE
	setmetatile 35, 9, METATILE_Fortree_BridgeT, FALSE
	setmetatile 36, 9, METATILE_Fortree_BridgeT, FALSE
	setmetatile 37, 9, METATILE_Fortree_BridgeT, FALSE
	setmetatile 38, 9, METATILE_Fortree_BridgeT, FALSE
	setmetatile 39, 9, METATILE_Fortree_BridgeT, FALSE
	setmetatile 40, 9, METATILE_Fortree_BridgeT, FALSE
	setmetatile 41, 9, METATILE_Fortree_BridgeT, FALSE
	setmetatile 42, 9, METATILE_Fortree_BridgeT, FALSE
	setmetatile 43, 9, METATILE_Fortree_BridgeT, FALSE
	setmetatile 34, 10, METATILE_Fortree_BridgeM, FALSE
	setmetatile 35, 10, METATILE_Fortree_BridgeM, FALSE
	setmetatile 36, 10, METATILE_Fortree_BridgeM, FALSE
	setmetatile 37, 10, METATILE_Fortree_BridgeM, FALSE
	setmetatile 38, 10, METATILE_Fortree_BridgeM, FALSE
	setmetatile 39, 10, METATILE_Fortree_BridgeM, FALSE
	setmetatile 40, 10, METATILE_Fortree_BridgeM, FALSE
	setmetatile 41, 10, METATILE_Fortree_BridgeM, FALSE
	setmetatile 42, 10, METATILE_Fortree_BridgeM, FALSE
	setmetatile 43, 10, METATILE_Fortree_BridgeM, FALSE
	setmetatile 34, 11, METATILE_Fortree_BridgeB, FALSE
	setmetatile 35, 11, METATILE_Fortree_BridgeB, FALSE
	setmetatile 36, 11, METATILE_Fortree_BridgeB, FALSE
	setmetatile 37, 11, METATILE_Fortree_BridgeB, FALSE
	setmetatile 38, 11, METATILE_Fortree_BridgeB, FALSE
	setmetatile 39, 11, METATILE_Fortree_BridgeB, FALSE
	setmetatile 40, 11, METATILE_Fortree_BridgeB, FALSE
	setmetatile 41, 11, METATILE_Fortree_BridgeB, FALSE
	setmetatile 42, 11, METATILE_Fortree_BridgeB, FALSE
	setmetatile 43, 11, METATILE_Fortree_BridgeB, FALSE
	setmetatile 27, 15, METATILE_Fortree_CaveStairs, FALSE
	setmetatile 28, 15, METATILE_Fortree_CaveStairs, FALSE
	setmetatile 27, 16, METATILE_Fortree_CaveStairs, FALSE
	setmetatile 28, 16, METATILE_Fortree_CaveStairs, FALSE
	setmetatile 11, 12, METATILE_Fortree_CaveStairs, FALSE
	setmetatile 12, 12, METATILE_Fortree_CaveStairs, FALSE
	setmetatile 13, 12, METATILE_Fortree_CaveStairs, FALSE
	setmetatile 11, 13, METATILE_Fortree_CaveStairs, FALSE
	setmetatile 12, 13, METATILE_Fortree_CaveStairs, FALSE
	setmetatile 13, 13, METATILE_Fortree_CaveStairs, FALSE
	end

VisceraCave_EventScript_SetTiles5::
	setmetatile 39, 6, METATILE_Fortree_RockClimb, TRUE
	setmetatile 39, 7, METATILE_Fortree_RockClimb, TRUE
	setmetatile 47, 13, METATILE_Fortree_CaveStairs, FALSE
	setmetatile 48, 13, METATILE_Fortree_CaveStairs, FALSE
	setmetatile 49, 13, METATILE_Fortree_CaveStairs, FALSE
	setmetatile 47, 14, METATILE_Fortree_CaveStairs, FALSE
	setmetatile 48, 14, METATILE_Fortree_CaveStairs, FALSE
	setmetatile 49, 14, METATILE_Fortree_CaveStairs, FALSE
	setmetatile 34, 9, METATILE_Fortree_BridgeT, FALSE
	setmetatile 35, 9, METATILE_Fortree_BridgeT, FALSE
	setmetatile 36, 9, METATILE_Fortree_BridgeT, FALSE
	setmetatile 37, 9, METATILE_Fortree_BridgeT, FALSE
	setmetatile 38, 9, METATILE_Fortree_BridgeT, FALSE
	setmetatile 39, 9, METATILE_Fortree_BridgeT, FALSE
	setmetatile 40, 9, METATILE_Fortree_BridgeT, FALSE
	setmetatile 41, 9, METATILE_Fortree_BridgeT, FALSE
	setmetatile 42, 9, METATILE_Fortree_BridgeT, FALSE
	setmetatile 43, 9, METATILE_Fortree_BridgeT, FALSE
	setmetatile 34, 10, METATILE_Fortree_BridgeM, FALSE
	setmetatile 35, 10, METATILE_Fortree_BridgeM, FALSE
	setmetatile 36, 10, METATILE_Fortree_BridgeM, FALSE
	setmetatile 37, 10, METATILE_Fortree_BridgeM, FALSE
	setmetatile 38, 10, METATILE_Fortree_BridgeM, FALSE
	setmetatile 39, 10, METATILE_Fortree_BridgeM, FALSE
	setmetatile 40, 10, METATILE_Fortree_BridgeM, FALSE
	setmetatile 41, 10, METATILE_Fortree_BridgeM, FALSE
	setmetatile 42, 10, METATILE_Fortree_BridgeM, FALSE
	setmetatile 43, 10, METATILE_Fortree_BridgeM, FALSE
	setmetatile 34, 11, METATILE_Fortree_BridgeB, FALSE
	setmetatile 35, 11, METATILE_Fortree_BridgeB, FALSE
	setmetatile 36, 11, METATILE_Fortree_BridgeB, FALSE
	setmetatile 37, 11, METATILE_Fortree_BridgeB, FALSE
	setmetatile 38, 11, METATILE_Fortree_BridgeB, FALSE
	setmetatile 39, 11, METATILE_Fortree_BridgeB, FALSE
	setmetatile 40, 11, METATILE_Fortree_BridgeB, FALSE
	setmetatile 41, 11, METATILE_Fortree_BridgeB, FALSE
	setmetatile 42, 11, METATILE_Fortree_BridgeB, FALSE
	setmetatile 43, 11, METATILE_Fortree_BridgeB, FALSE
	setmetatile 27, 15, METATILE_Fortree_CaveStairs, FALSE
	setmetatile 28, 15, METATILE_Fortree_CaveStairs, FALSE
	setmetatile 27, 16, METATILE_Fortree_CaveStairs, FALSE
	setmetatile 28, 16, METATILE_Fortree_CaveStairs, FALSE
	setmetatile 11, 12, METATILE_Fortree_CaveStairs, FALSE
	setmetatile 12, 12, METATILE_Fortree_CaveStairs, FALSE
	setmetatile 13, 12, METATILE_Fortree_CaveStairs, FALSE
	setmetatile 11, 13, METATILE_Fortree_CaveStairs, FALSE
	setmetatile 12, 13, METATILE_Fortree_CaveStairs, FALSE
	setmetatile 13, 13, METATILE_Fortree_CaveStairs, FALSE
	end
