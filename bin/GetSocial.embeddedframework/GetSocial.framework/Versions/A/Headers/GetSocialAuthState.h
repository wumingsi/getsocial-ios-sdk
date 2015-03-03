//
//  GetSocialAuthState.h
//  GetSocialSDK
//
//  Created by Jan-Eric Duden on 02/06/14.
//  Copyright (c) 2014 GetSocial. All rights reserved.
//

#ifndef GetSocialSDK_GetSocialAuthState_h
#define GetSocialSDK_GetSocialAuthState_h

/**
 * Notification send when the user authentication state changes.
 * UserInfo includes the following keys:
 * - GetSocialUserAuthStateChangeNotificationPrevState mapping to a NSNumber representing a value of the GetSocialUserAuthState enum.
 * - GetSocialUserAuthStateChangeNotificationNewState mapping to a NSNumber representing a value of the GetSocialUserAuthState enum.
 */
extern NSString* const GetSocialUserAuthStateChangeNotification;
extern NSString* const GetSocialUserAuthStateChangeNotificationPrevState;
extern NSString* const GetSocialUserAuthStateChangeNotificationNewState;
extern NSString* const GetSocialUserAuthStateChangeNotificationNewUser;

/** Describes a authentication state of the user. */
typedef NS_ENUM(NSInteger,GetSocialUserAuthState) {
    /**
     * The user is not identified.
     */
    GetSocialUserAuthStateUnidentified,
    
    /**
     * There is some process active trying to verify the user's identity.
     */
    GetSocialUserAuthStateVerifying,
    
    /**
     * The user's identity has been successfully verified.
     */
    GetSocialUserAuthStateVerified,
    
    /**
     * The user's identity is being cleared out.
     */
    GetSocialUserAuthStateClearing
};

#endif
