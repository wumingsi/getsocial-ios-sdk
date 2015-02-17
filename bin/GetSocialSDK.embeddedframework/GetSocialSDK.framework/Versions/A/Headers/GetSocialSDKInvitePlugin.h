//
//  GetSocialSDKInvitePlugin.h
//  GetSocialSDK
//
//  Created by Jan-Eric Duden on 23/07/14.
//  Copyright (c) 2014 GetSocial. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "GetSocialSDKPlugin.h"

#define GetSocialSDKInviteInfoKeyInvitesSent @"invites_sent"
#define GetSocialSDKInviteInfoKeyInviteId @"invite_id"
#define GetSocialSDKInviteInfoKeyInvitedUserIds @"invited_users_ids"

typedef void (^GetSocialSDKInviteSuccessCallback)(NSDictionary* inviteInfo);
typedef void (^GetSocialSDKCancelCallback)();

/**
 * This interface provides the invite friends functionality used by the GetSocial SDK.
 */
@interface GetSocialSDKInvitePlugin : GetSocialSDKPlugin

@property (nonatomic, strong) id inviteSubject;
@property (nonatomic, strong) id inviteText;
@property (nonatomic, strong) NSString* inviteImageUrl;

/**
 * When this method is called, the plugin can assume:
 *
 * - the game is authenticated
 * - no other invite plugin is active.
 *
 * The plugin MUST NOT assume:
 * - handlers listing for the state change from unidentified to verifying have completed.
 *
 * inviteFriends MUST guarantee that exactly one of the callbacks is eventually called. (i.e. either completeCallback or cancelCallback)
 *
 * @param successCallback has to be called when invite friends was successful
 * @param cancelCallback has to be called when the user aborted
 * @param errorCallback when there was an error
 */
-(void) inviteFriendsWithSubject:(NSString*) subject text:(NSString*) text image:(UIImage*) image success:(GetSocialSDKInviteSuccessCallback) successCallback cancel:(GetSocialSDKCancelCallback) cancelCallback error:(GetSocialSDKErrorCallback) errorCallback;

@end
