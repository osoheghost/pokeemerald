BerryTreeScript1::
	goto_if_set FLAG_BERRY_1, BerryTree_EventScript_PickedAlready
	goto BerryTree_EventScript_CheckBerryFullyGrown1
	end
	
@ VAR_0x8006 here is the number of berries
BerryTree_EventScript_CheckBerryFullyGrown1::
	buffernumberstring STR_VAR_2, VAR_0x8006
	lock
	faceplayer
	special ObjectEventInteractionGetBerryCountString
	msgbox BerryTree_Text_WantToPick, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, BerryTree_EventScript_PickBerry1
	goto_if_eq VAR_RESULT, NO, BerryTree_EventScript_CancelPickingBerry

BerryTree_EventScript_PickBerry1::
	setflag FLAG_BERRY_1
	special ObjectEventInteractionPickBerryTree
	goto_if_eq VAR_0x8004, 0, BerryTree_EventScript_BerryPocketFull
	special IncrementDailyPickedBerries
	special ObjectEventInteractionRemoveBerryTree
	message BerryTree_Text_PickedTheBerry
	delay 10
	showberrydesc
	playfanfare MUS_OBTAIN_BERRY
	waitmessage
	waitfanfare
	waitbuttonpress
	message BerryTree_Text_PutAwayBerry
	waitmessage
	waitbuttonpress
	hideitemdesc
	release
	end

BerryTreeScript2::
	goto_if_set FLAG_BERRY_2, BerryTree_EventScript_PickedAlready
	goto BerryTree_EventScript_CheckBerryFullyGrown2
	end
	
@ VAR_0x8006 here is the number of berries
BerryTree_EventScript_CheckBerryFullyGrown2::
	buffernumberstring STR_VAR_2, VAR_0x8006
	lock
	faceplayer
	special ObjectEventInteractionGetBerryCountString
	msgbox BerryTree_Text_WantToPick, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, BerryTree_EventScript_PickBerry2
	goto_if_eq VAR_RESULT, NO, BerryTree_EventScript_CancelPickingBerry

BerryTree_EventScript_PickBerry2::
	setflag FLAG_BERRY_2
	special ObjectEventInteractionPickBerryTree
	goto_if_eq VAR_0x8004, 0, BerryTree_EventScript_BerryPocketFull
	special IncrementDailyPickedBerries
	special ObjectEventInteractionRemoveBerryTree
	message BerryTree_Text_PickedTheBerry
	delay 10
	showberrydesc
	playfanfare MUS_OBTAIN_BERRY
	waitmessage
	waitfanfare
	waitbuttonpress
	message BerryTree_Text_PutAwayBerry
	waitmessage
	waitbuttonpress
	hideitemdesc
	release
	end

BerryTreeScript3::
	goto_if_set FLAG_BERRY_3, BerryTree_EventScript_PickedAlready
	goto BerryTree_EventScript_CheckBerryFullyGrown3
	end
	
@ VAR_0x8006 here is the number of berries
BerryTree_EventScript_CheckBerryFullyGrown3::
	buffernumberstring STR_VAR_2, VAR_0x8006
	lock
	faceplayer
	special ObjectEventInteractionGetBerryCountString
	msgbox BerryTree_Text_WantToPick, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, BerryTree_EventScript_PickBerry3
	goto_if_eq VAR_RESULT, NO, BerryTree_EventScript_CancelPickingBerry

BerryTree_EventScript_PickBerry3::
	setflag FLAG_BERRY_3
	special ObjectEventInteractionPickBerryTree
	goto_if_eq VAR_0x8004, 0, BerryTree_EventScript_BerryPocketFull
	special IncrementDailyPickedBerries
	special ObjectEventInteractionRemoveBerryTree
	message BerryTree_Text_PickedTheBerry
	delay 10
	showberrydesc
	playfanfare MUS_OBTAIN_BERRY
	waitmessage
	waitfanfare
	waitbuttonpress
	message BerryTree_Text_PutAwayBerry
	waitmessage
	waitbuttonpress
	hideitemdesc
	release
	end

BerryTreeScript4::
	goto_if_set FLAG_BERRY_4, BerryTree_EventScript_PickedAlready
	goto BerryTree_EventScript_CheckBerryFullyGrown4
	end
	
@ VAR_0x8006 here is the number of berries
BerryTree_EventScript_CheckBerryFullyGrown4::
	buffernumberstring STR_VAR_2, VAR_0x8006
	lock
	faceplayer
	special ObjectEventInteractionGetBerryCountString
	msgbox BerryTree_Text_WantToPick, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, BerryTree_EventScript_PickBerry4
	goto_if_eq VAR_RESULT, NO, BerryTree_EventScript_CancelPickingBerry

BerryTree_EventScript_PickBerry4::
	setflag FLAG_BERRY_4
	special ObjectEventInteractionPickBerryTree
	goto_if_eq VAR_0x8004, 0, BerryTree_EventScript_BerryPocketFull
	special IncrementDailyPickedBerries
	special ObjectEventInteractionRemoveBerryTree
	message BerryTree_Text_PickedTheBerry
	delay 10
	showberrydesc
	playfanfare MUS_OBTAIN_BERRY
	waitmessage
	waitfanfare
	waitbuttonpress
	message BerryTree_Text_PutAwayBerry
	waitmessage
	waitbuttonpress
	hideitemdesc
	release
	end

BerryTreeScript5::
	goto_if_set FLAG_BERRY_5, BerryTree_EventScript_PickedAlready
	goto BerryTree_EventScript_CheckBerryFullyGrown5
	end
	
@ VAR_0x8006 here is the number of berries
BerryTree_EventScript_CheckBerryFullyGrown5::
	buffernumberstring STR_VAR_2, VAR_0x8006
	lock
	faceplayer
	special ObjectEventInteractionGetBerryCountString
	msgbox BerryTree_Text_WantToPick, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, BerryTree_EventScript_PickBerry5
	goto_if_eq VAR_RESULT, NO, BerryTree_EventScript_CancelPickingBerry

BerryTree_EventScript_PickBerry5::
	setflag FLAG_BERRY_5
	special ObjectEventInteractionPickBerryTree
	goto_if_eq VAR_0x8004, 0, BerryTree_EventScript_BerryPocketFull
	special IncrementDailyPickedBerries
	special ObjectEventInteractionRemoveBerryTree
	message BerryTree_Text_PickedTheBerry
	delay 10
	showberrydesc
	playfanfare MUS_OBTAIN_BERRY
	waitmessage
	waitfanfare
	waitbuttonpress
	message BerryTree_Text_PutAwayBerry
	waitmessage
	waitbuttonpress
	hideitemdesc
	release
	end

BerryTreeScript6::
	goto_if_set FLAG_BERRY_6, BerryTree_EventScript_PickedAlready
	goto BerryTree_EventScript_CheckBerryFullyGrown6
	end
	
@ VAR_0x8006 here is the number of berries
BerryTree_EventScript_CheckBerryFullyGrown6::
	buffernumberstring STR_VAR_2, VAR_0x8006
	lock
	faceplayer
	special ObjectEventInteractionGetBerryCountString
	msgbox BerryTree_Text_WantToPick, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, BerryTree_EventScript_PickBerry6
	goto_if_eq VAR_RESULT, NO, BerryTree_EventScript_CancelPickingBerry

BerryTree_EventScript_PickBerry6::
	setflag FLAG_BERRY_6
	special ObjectEventInteractionPickBerryTree
	goto_if_eq VAR_0x8004, 0, BerryTree_EventScript_BerryPocketFull
	special IncrementDailyPickedBerries
	special ObjectEventInteractionRemoveBerryTree
	message BerryTree_Text_PickedTheBerry
	delay 10
	showberrydesc
	playfanfare MUS_OBTAIN_BERRY
	waitmessage
	waitfanfare
	waitbuttonpress
	message BerryTree_Text_PutAwayBerry
	waitmessage
	waitbuttonpress
	hideitemdesc
	release
	end

BerryTreeScript7::
	lock
	msgbox BerryTree_Text_StrangeTree, MSGBOX_DEFAULT
	release
	end

BerryTree_Text_StrangeTree:
	.string "A never before seen berry tree.\p"
	.string "The berries have been taken already.$"

@ VAR_0x8006 here is the number of berries
BerryTree_EventScript_CheckBerryFullyGrown7::
	buffernumberstring STR_VAR_2, VAR_0x8006
	lock
	faceplayer
	special ObjectEventInteractionGetBerryCountString
	msgbox BerryTree_Text_WantToPick1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, BerryTree_EventScript_PickBerry7
	goto_if_eq VAR_RESULT, NO, BerryTree_EventScript_CancelPickingBerry

BerryTree_EventScript_PickBerry7::
	setflag FLAG_BERRY_7
	special ObjectEventInteractionPickBerryTree
	goto_if_eq VAR_0x8004, 0, BerryTree_EventScript_BerryPocketFull
	special IncrementDailyPickedBerries
	special ObjectEventInteractionRemoveBerryTree
	message BerryTree_Text_PickedTheBerry1
	delay 10
	showberrydesc
	playfanfare MUS_OBTAIN_BERRY
	waitmessage
	waitfanfare
	waitbuttonpress
	message BerryTree_Text_PutAwayBerry1
	waitmessage
	waitbuttonpress
	hideitemdesc
	goto BerryTree_EventScript_SetDay3Complete
	release
	end

BerryTree_EventScript_SetDay3Complete::
	setflag FLAG_DAY_3_COMPLETE
	setflag FLAG_CAN_SLEEP
	release
	end

BerryTree_EventScript_BerryPocketFull::
	message BerryTree_Text_BerryPocketFull
	waitmessage
	waitbuttonpress
	release
	end

BerryTree_EventScript_PickedAlready::
	message BerryTree_Text_PickedTheBerryAlready
	waitmessage
	waitbuttonpress
	release
	end

BerryTree_EventScript_CancelPickingBerry::
	message BerryTree_Text_BerryLeftUnpicked
	waitmessage
	waitbuttonpress
	release
	end


BerryTree_Text_WantToPick:
	.string "You found 2 {STR_VAR_1}!\p"
	.string "Do you want to pick the\n"
	.string "{STR_VAR_1}?$"

BerryTree_Text_PickedTheBerry:
	.string "{PLAYER} picked the 2 {STR_VAR_1}.$"

BerryTree_Text_WantToPick1:
	.string "You found a {STR_VAR_1}!\p"
	.string "Do you want to pick the\n"
	.string "{STR_VAR_1}?$"

BerryTree_Text_PickedTheBerry1:
	.string "{PLAYER} picked the {STR_VAR_1}.$"

BerryTree_Text_PutAwayBerry:
	.string "{PLAYER} put away the {STR_VAR_1}\n"
	.string "in the BAG's BERRIES POCKET.$"

BerryTree_Text_PutAwayBerry1:
	.string "{PLAYER} put away the {STR_VAR_1}\n"
	.string "in the BAG's BERRIES POCKET.$"

BerryTree_Text_BerryPocketFull:
	.string "The BAG's BERRIES POCKET is full.\p"
	.string "The {STR_VAR_1} couldn't be taken.$"

BerryTree_Text_BerryLeftUnpicked:
	.string "{PLAYER} left the {STR_VAR_1}\n"
	.string "unpicked.$"

BerryTree_Text_PickedTheBerryAlready:
	.string "You picked the berry already.$"

BerryTree_Text_ExclamationPoint:
	.string "!$"

BerryTreeScript::
	end

BerryTree_EventScript_ItemUsePlantBerry::
	end

BerryTree_EventScript_ItemUseWailmerPail::
	end
