//
//  GetSocialSDKAuthState.h
//  GetSocialSDK
//
//  Created by Jan-Eric Duden on 02/06/14.
//  Copyright (c) 2014 GetSocial. All rights reserved.
//

#ifndef GetSocialSDK_GetSocialSDKAuthState_h
#define GetSocialSDK_GetSocialSDKAuthState_h

/**
 * Notification send when the user authentication state changes.
 * UserInfo includes the following keys:
 * - GetSocialSDKUserAuthStateChangeNotificationPrevState mapping to a NSNumber representing a value of the GetSocialSDKUserAuthState enum.
 * - GetSocialSDKUserAuthStateChangeNotificationNewState mapping to a NSNumber representing a value of the GetSocialSDKUserAuthState enum.
 */
extern NSString* const GetSocialSDKUserAuthStateChangeNotification;

extern NSString* const GetSocialSDKUserAuthStateChangeNotificationPrevState;
extern NSString* const GetSocialSDKUserAuthStateChangeNotificationNewState;
extern NSString* const GetSocialSDKUserAuthStateChangeNotificationNewUser;

/** Describes a authentication state of the user. */
typedef NS_ENUM(NSInteger,GetSocialSDKUserAuthState) {
    /**
     * The user is not identified.
     */
    GetSocialSDKUserAuthStateUnidentified,
    
    /**
     * There is some process active trying to verify the user's identity.
     */
    GetSocialSDKUserAuthStateVerifying,
    
    /**
     * The user's identity has been successfully verified.
     */
    GetSocialSDKUserAuthStateVerified,
    
    /**
     * The user's identity is being cleared out.
     */
    GetSocialSDKUserAuthStateClearing
};

#endif
