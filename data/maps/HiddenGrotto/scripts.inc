.set LOCALID_GROTTO_OBJECT1, 1
.set LOCALID_GROTTO_OBJECT2, 2
.set LOCALID_GROTTO_OBJECT3, 3
.set LOCALID_GROTTO_OBJECT4, 4
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
	setobjectxyperm LOCALID_GROTTO_OBJECT4, 5, 5
	end

HiddenGrotto_EventScript_HideItems5::
	setobjectxyperm LOCALID_GROTTO_OBJECT5, 5, 5
	end

HiddenGrotto_EventScript_Item0::
	lock
	faceplayer
	msgbox HiddenGrotto_Text_Item0, MSGBOX_DEFAULT
	release
	end

HiddenGrotto_Text_Item0:
	.string "Item 0.$"

HiddenGrotto_EventScript_Item1::
	lock
	faceplayer
	msgbox HiddenGrotto_Text_Item1, MSGBOX_DEFAULT
	release
	end

HiddenGrotto_Text_Item1:
	.string "Item 1.$"

HiddenGrotto_EventScript_Item2::
	lock
	faceplayer
	msgbox HiddenGrotto_Text_Item2, MSGBOX_DEFAULT
	release
	end

HiddenGrotto_Text_Item2:
	.string "Item 2.$"

HiddenGrotto_EventScript_Item3::
	lock
	faceplayer
	msgbox HiddenGrotto_Text_Item3, MSGBOX_DEFAULT
	release
	end

HiddenGrotto_Text_Item3:
	.string "Item 3.$"

HiddenGrotto_EventScript_Item4::
	lock
	faceplayer
	msgbox HiddenGrotto_Text_Item4, MSGBOX_DEFAULT
	release
	end

HiddenGrotto_Text_Item4:
	.string "Item 4.$"

HiddenGrotto_EventScript_Item5::
	lock
	faceplayer
	msgbox HiddenGrotto_Text_Item5, MSGBOX_DEFAULT
	release
	end

HiddenGrotto_Text_Item5:
	.string "Item 5.$"
