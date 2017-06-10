// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "VungleIOS.h"
#import "VungleSDK/VungleSDK.h"

#define LOCTEXT_NAMESPACE "FVungleIOSModule"

static FString AppIDString( TEXT( "" ) );

@interface IOSVungle :NSObject

@end

@implementation IOSVungle


+ (IOSVungle*)GetDelegate
{
    static IOSVungle * Singleton = [[IOSVungle alloc] init];
    return Singleton;
}

- (void) initSDK{
    VungleSDK* sdk = [VungleSDK sharedSDK];
    [sdk startWithAppId:[NSString stringWithFString:AppIDString]];
}

- (void) play{
    VungleSDK* sdk = [VungleSDK sharedSDK];
    NSError* error;
    [sdk playAd:(UIViewController*)[IOSAppDelegate GetDelegate].IOSController error:&error];
}

@end

void FVungleIosProvider::ShowAdBanner(bool bShowOnBottomOfScreen, int32 adID)
{
    [[IOSVungle GetDelegate] performSelectorOnMainThread:@selector(play) withObject:nil waitUntilDone : NO];
}


void FVungleIosProvider::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
    
    GConfig->GetString( TEXT( "Vungle" ), TEXT( "AppID" ),			AppIDString,		GEngineIni );
    [[IOSVungle GetDelegate] performSelectorOnMainThread:@selector(initSDK) withObject:nil waitUntilDone : NO];
}

void FVungleIosProvider::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FVungleIosProvider, VungleIOS)


