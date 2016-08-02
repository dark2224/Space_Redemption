// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

UENUM(BlueprintType)
enum class State_Type : uint8
{
	STATE_ALIVE UMETA(DisplayName = "State_Alive"),
	STATE_DEATH UMETA(DisplayName = "State_Death"),
	STATE_END UMETA(DisplayName = "State_End"),
};

UENUM(BlueprintType)
enum class Action_Type : uint8
{
	ACTION_IDLE UMETA(DisplayName = "Action_Idle"),
	ACTION_MOVE UMETA(DisplayName = "Action_Move"),
	ACTION_ATTACK UMETA(DisplayName = "Action_Attack"),
	ACTION_END UMETA(DisplayName = "Action_End"),
};

UENUM(BlueprintType)
enum class EGroup_Formation : uint8
{
	FORMATION_TRIANGLE	UMETA(DisplayName = "Formation_Triangle"),
	FORMATION_RECT	UMETA(DisplayName = "Formation_Rect"),
	FORMATION_END	UMETA(DisplayName = "Formation_End")
};