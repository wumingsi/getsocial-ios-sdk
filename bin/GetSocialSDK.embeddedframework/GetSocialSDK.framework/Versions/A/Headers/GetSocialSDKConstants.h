//
//  GetSocialSDKConstants.h
//  GetSocialSDK
//
//  Created by Demian Denker on 03/10/13.
//  Copyright (c) 2013 GetSocial. All rights reserved.
//

#ifndef GetSocialSDK_GetSocialSDKConstants_h
#define GetSocialSDK_GetSocialSDKConstants_h

/** Constants for the Invite friends listener  */
typedef NS_ENUM(NSInteger,GetSocialSDKInviteFriendsStatus) {
    /**Invite is sent */
    GetSocialSDKInviteFriendsStatusSent         = 1,
    /**Invite is created but there is no information if it is sent  */
    GetSocialSDKInviteFriendsStatusIntent       = 2,
};

/** Constants for the supported Views that can be directly opened in Social Bar  */
typedef NS_ENUM(NSInteger,GetSocialSDKViewType) {
    /** Current View */
    GetSocialSDKViewTypeCurrentView     = 1,
    /** Activities */
    GetSocialSDKViewTypeActivities      = 2,
    /** Chat */
    GetSocialSDKViewTypeChat            = 3,
    /** Notifications */
    GetSocialSDKViewTypeNotifications   = 6,
    /** Smart Invites */
    GetSocialSDKViewTypeSmartInvite     = 8
};

typedef NSString* GetSocialSDKProvider;

/**
 * The typedef defines the signature of a block that is called when an operation completes.
 */
typedef void (^GetSocialSDKCompleteCallback)();

/**
 * The typedef defines the signature of a block that is called when an operation fails.
 * @param error is the error that caused the failure.
 */
typedef void (^GetSocialSDKErrorCallback)(NSError* error);

/** Constants that define the open/close animation  */
typedef NS_ENUM(NSInteger,GetSocialSDKAnimationStyle) {
    /** Animation scales the element In and Out*/
    GetSocialSDKAnimationStyleScale        = 1,
    /** Animation fades the element In and Out*/
    GetSocialSDKAnimationStyleFade         = 2,
    /** Animation fades and scales the element In and Out*/
    GetSocialSDKAnimationStyleFadeAndScale = 3
};

/** Constants that define the scaling of the content of the GetSocial SDK UI */
typedef NS_ENUM(NSInteger,GetSocialSDKScaleMode) {
    /**The GetSocial UI, fonts and margins don't scale based on the Social Bar width */
    GetSocialSDKScaleModePixelPerfect           = 1,
    /**The GetSocial UI, fonts and margins scale based on the Social Bar width */
    GetSocialSDKScaleModeFixedRatio             = 2
};

#define kGetSocialSDKUserID @"userId"
#define kGetSocialSDKProvider @"providerId"

#define kGetSocialSDKConversationID @"conversationId"

#define kGetSocialSDKInviteImage @"inviteImage"
#define kGetSocialSDKInviteText @"inviteText"
#define kGetSocialSDKInviteSubject @"inviteSubject"

#define kGetSocialSDKActivityTags @"tags"
#define kGetSocialSDKActivityGroup @"group"

#define kGetSocialSDKActivityID @"activityId"
#define kGetSocialSDKTitle @"title"

#define kGetSocialSDKSource @"source"

#define kGetSocialSDKAuthInfoKeyToken @"token"
#define kGetSocialSDKAuthInfoKeyUserId @"user_id"
#define kGetSocialSDKAuthInfoKeyExternalUserId @"external_user_id"
#define kGetSocialSDKAuthPermissionsFacebook @[@"email", @"user_friends"]

extern NSString * const GetSocialSDKViewOpenNotification;
extern NSString * const GetSocialSDKViewCloseNotification;

#endif
