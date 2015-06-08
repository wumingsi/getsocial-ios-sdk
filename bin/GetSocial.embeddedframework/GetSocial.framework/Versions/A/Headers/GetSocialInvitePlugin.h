//
//  GetSocialInvitePlugin.h
//  GetSocialSDK
//
//  Created by Jan-Eric Duden on 23/07/14.
//  Copyright (c) 2014 GetSocial. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "GetSocialPlugin.h"

#define GetSocialInviteInfoKeyInvitesSent @"invites_sent"
#define GetSocialInviteInfoKeyInviteId @"invite_id"
#define GetSocialInviteInfoKeyInvitedUserIds @"invited_users_ids"

/** The definition of the success callback.*/
typedef void (^GetSocialInviteSuccessCallback)(NSDictionary* inviteInfo);

/** The definition of the cancel callback.*/
typedef void (^GetSocialCancelCallback)();

/**
 * This interface provides the invite friends functionality used by the GetSocial SDK.
 */
@interface GetSocialInvitePlugin : GetSocialPlugin

/** The default subject to use.*/
@property (nonatomic, strong) id inviteSubject;

/** The default text to use.*/
@property (nonatomic, strong) id inviteText;

/** The default image to use.*/
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
 * @param subject Subject to be sent with the invite
 * @param text Text to be sent with the invite
 * @param image Image to be sent with the invite
 * @param referralDataUrl URL to be sent with the invite
 * @param successCallback has to be called when invite friends was successful
 * @param cancelCallback has to be called when the user aborted
 * @param errorCallback when there was an error
 */
-(void) inviteFriendsWithSubject:(NSString*) subject text:(NSString*) text referralDataUrl:(NSString*) referralDataUrl image:(UIImage*) image success:(GetSocialInviteSuccessCallback) successCallback cancel:(GetSocialCancelCallback) cancelCallback error:(GetSocialErrorCallback) errorCallback;

@end
