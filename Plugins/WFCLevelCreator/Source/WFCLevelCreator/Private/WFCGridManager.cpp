﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "WFCGridManager.h"
#include "K2Node_SpawnActor.h"
#include "WFCItemBase.h"
#include "WFCRolesManager.h"

AWFCGridManager::AWFCGridManager()
{
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AWFCGridManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWFCGridManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AWFCGridManager::UpdateGridSetting(UWFCRolesManagerAsset* RolesManager)
{
	if(RolesManager)
	{
		Num_X = RolesManager->Num_X;
		Num_Y = RolesManager->Num_Y;
		GridSize = RolesManager->GridSize;
		ResetGrid();
	}
}

void AWFCGridManager::SetGridItemsHidenInEditor(bool IsHid)
{
	for (auto GridItem : GridItemsSave)
	{
		GridItem.Value->SetIsTemporarilyHiddenInEditor(IsHid);
	}
}



