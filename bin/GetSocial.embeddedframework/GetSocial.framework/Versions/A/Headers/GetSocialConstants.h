//
//  GetSocialConstants.h
//  GetSocialSDK
//
//  Created by Demian Denker on 03/10/13.
//  Copyright (c) 2013 GetSocial. All rights reserved.
//

#ifndef GetSocialSDK_GetSocialConstants_h
#define GetSocialSDK_GetSocialConstants_h

/** Constants for the Invite friends listener  */
typedef NS_ENUM(NSInteger,GetSocialInviteFriendsStatus) {
    /**Invite is sent */
    GetSocialInviteFriendsStatusSent         = 1,
    /**Invite is created but there is no information if it is sent  */
    GetSocialInviteFriendsStatusIntent       = 2,
};

/** Constants for the supported Views that can be directly opened in Social Bar  */
typedef NS_ENUM(NSInteger,GetSocialViewType) {
    /** Current View */
    GetSocialViewTypeCurrentView     = 1,
    /** Activities */
    GetSocialViewTypeActivities      = 2,
    /** Chat */
    GetSocialViewTypeChat            = 3,
    /** Notifications */
    GetSocialViewTypeNotifications   = 6,
    /** Smart Invites */
    GetSocialViewTypeSmartInvite     = 8
};

typedef NSString* GetSocialProvider;

/**
 * The typedef defines the signature of a block that is called when an operation completes.
 */
typedef void (^GetSocialCompleteCallback)();

/**
 * The typedef defines the signature of a block that is called when an operation fails.
 * @param error is the error that caused the failure.
 */
typedef void (^GetSocialErrorCallback)(NSError* error);

/** Constants that define the open/close animation  */
typedef NS_ENUM(NSInteger,GetSocialAnimationStyle) {
    /** Animation scales the element In and Out*/
    GetSocialAnimationStyleScale        = 1,
    /** Animation fades the element In and Out*/
    GetSocialAnimationStyleFade         = 2,
    /** Animation fades and scales the element In and Out*/
    GetSocialAnimationStyleFadeAndScale = 3
};

/** Constants that define the scaling of the content of the GetSocial UI */
typedef NS_ENUM(NSInteger,GetSocialScaleMode) {
    /**The GetSocial UI, fonts and margins don't scale based on the Social Bar width */
    GetSocialScaleModePixelPerfect           = 1,
    /**The GetSocial UI, fonts and margins scale based on the Social Bar width */
    GetSocialScaleModeFixedRatio             = 2
};

#define kGetSocialUserID @"userId"
#define kGetSocialProvider @"providerId"

#define kGetSocialConversationID @"conversationId"

#define kGetSocialInviteImage @"inviteImage"
#define kGetSocialInviteText @"inviteText"
#define kGetSocialInviteSubject @"inviteSubject"

#define kGetSocialActivityTags @"tags"
#define kGetSocialActivityGroup @"group"

#define kGetSocialActivityID @"activityId"
#define kGetSocialTitle @"title"

#define kGetSocialSource @"source"

#define kGetSocialAuthInfoKeyToken @"token"
#define kGetSocialAuthInfoKeyUserId @"user_id"
#define kGetSocialAuthInfoKeyExternalUserId @"external_user_id"
#define kGetSocialAuthPermissionsFacebook @[@"email", @"user_friends"]

extern NSString * const GetSocialViewOpenNotification;
extern NSString * const GetSocialViewCloseNotification;

#endif
