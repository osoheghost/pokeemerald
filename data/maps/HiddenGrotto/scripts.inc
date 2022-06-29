.set LOCALID_GROTTO_OBJECT1, 1
.set LOCALID_GROTTO_OBJECT2, 2
.set LOCALID_GROTTO_OBJECT3, 3
.set LOCALID_SUDOWOODO, 4
.set LOCALID_GROTTO_OBJECT5, 5
.set LOCALID_GROTTO_OBJECT0, 6

HiddenGrotto_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, HiddenGrotto_OnWarp
	.byte 0

HiddenGrotto_OnWarp:
	map_script_2 VAR_LUMIOUR_ISLAND_STATE, 0, HiddenGrotto_EventScript_HideItems0
	map_script_2 VAR_LUMIOUR_ISLAND_STATE, 1, HiddenGrotto_EventScript_HideItems1
	map_script_2 VAR_LUMIOUR_ISLAND_STATE, 2, HiddenGrotto_EventScript_HideItems2
	map_script_2 VAR_LUMIOUR_ISLAND_STATE, 3, HiddenGrotto_EventScript_HideItems3
	map_script_2 VAR_LUMIOUR_ISLAND_STATE, 4, HiddenGrotto_EventScript_HideItems4
	map_script_2 VAR_LUMIOUR_ISLAND_STATE, 5, HiddenGrotto_EventScript_HideItems5
	.2byte 0

HiddenGrotto_EventScript_HideItems0::
	showobjectat LOCALID_GROTTO_OBJECT0, MAP_HIDDEN_GROTTO
	setobjectxyperm LOCALID_GROTTO_OBJECT0, 5, 5
	end

HiddenGrotto_EventScript_HideItems1::
	setobjectxyperm LOCALID_GROTTO_OBJECT1, 5, 5
	end

HiddenGrotto_EventScript_HideItems2::
	setobjectxyperm LOCALID_GROTTO_OBJECT2, 5, 5
	end

HiddenGrotto_EventScript_HideItems3::
	setobjectxyperm LOCALID_GROTTO_OBJECT3, 5, 5
	end

HiddenGrotto_EventScript_HideItems4::
	setobjectxyperm LOCALID_SUDOWOODO, 5, 5
	end

HiddenGrotto_EventScript_HideItems5::
	setobjectxyperm LOCALID_GROTTO_OBJECT5, 5, 5
	end

HiddenGrotto_EventScript_Item3::
	lock
	faceplayer
	msgbox HiddenGrotto_Text_Item3, MSGBOX_DEFAULT
	release
	end

HiddenGrotto_Text_Item3:
	.string "Item 3.$"

HiddenGrotto_EventScript_Item5::
	lock
	faceplayer
	msgbox HiddenGrotto_Text_Item5, MSGBOX_DEFAULT
	release
	end

HiddenGrotto_Text_Item5:
	.string "Item 5.$"

HiddenGrotto_EventScript_Sudowoodo::
	lock
	faceplayer
	playse SE_SUDOWOODO_SHAKE
	applymovement LOCALID_SUDOWOODO, HiddenGrotto_Movement_SudowoodoShake
	waitmovement 0
	waitse
	playmoncry SPECIES_SUDOWOODO, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_SUDOWOODO
	setwildbattle SPECIES_SUDOWOODO, 30
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, HiddenGrotto_EventScript_DefeatedSudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, HiddenGrotto_EventScript_DefeatedSudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, HiddenGrotto_EventScript_DefeatedSudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, HiddenGrotto_EventScript_DefeatedSudowoodo
	setflag FLAG_HIDDEN_GROTTO_4
	release
	end

HiddenGrotto_EventScript_DefeatedSudowoodo::
	setflag FLAG_HIDDEN_GROTTO_4
	goto Common_EventScript_RemoveStaticPokemon
	end

HiddenGrotto_Movement_SudowoodoShake:
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	delay_8
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	step_end
