// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ModuleManager.h"
#include "IAdvertisingProvider.h"
#include "IOSAppDelegate.h"
#include "Modules/ModuleInterface.h"
#include "Modules/ModuleManager.h"
#include "Misc/ConfigCacheIni.h"

class FVungleIosProvider : public IAdvertisingProvider
{
    /** IModuleInterface implementation */
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
    
    /** IAdvertisingProvider implementation */
    virtual void ShowAdBanner(bool bShowOnBottomOfScreen, int32 adID) override;
    virtual void HideAdBanner() override{}
    virtual void CloseAdBanner() override{}
    virtual int32 GetAdIDCount() override {return 1;}
    
    virtual void LoadInterstitialAd(int32 adID) override{}
    virtual bool IsInterstitialAdAvailable() override{return true;}
    virtual bool IsInterstitialAdRequested() override{return true;}
    virtual void ShowInterstitialAd() override{}
};
