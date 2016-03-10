/*
 *    	Copyright 2015-2016 GetSocial B.V.
 *
 *	Licensed under the Apache License, Version 2.0 (the "License");
 *	you may not use this file except in compliance with the License.
 *	You may obtain a copy of the License at
 *
 *    	http://www.apache.org/licenses/LICENSE-2.0
 *
 *	Unless required by applicable law or agreed to in writing, software
 *	distributed under the License is distributed on an "AS IS" BASIS,
 *	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *	See the License for the specific language governing permissions and
 *	limitations under the License.
 */

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

// GetSocial SDK Constants
#import "GetSocialConstants.h"

// UI Configuration
#import "GetSocialConfiguration.h"
#import "GetSocialConfigurationProperties.h"

// View Builders
#import "GetSocialActivitiesViewBuilder.h"
#import "GetSocialNotificationsViewBuilder.h"
#import "GetSocialSmartInviteViewBuilder.h"
#import "GetSocialUserListViewBuilder.h"

// Smart Invite Base Plugin
#import "GetSocialInvitePlugin.h"

// User Management
#import "GetSocialCurrentUser.h"
#import "GetSocialUserIdentity.h"

// Leaderboards
#import "GetSocialLeaderboard.h"

/**
 *  The GetSocial Singleton provides the main entry point for all the social features in the Core module
 */
@interface GetSocial : NSObject

#pragma mark - Singleton
/** @name Singleton */

/**
 *  Gets the shared instance of GetSocial
 *
 *  @return GetSocial instance
 */
+ (instancetype)sharedInstance;

#pragma mark - Properties
/** @name Properties */

/**
 *  Sets/Gets language to use inside the SDK
 */
@property(nonatomic, strong) NSString *language;

/**
 *  Gets the GetSocialCurrentUser instance
 */
@property(nonatomic, strong, readonly) GetSocialCurrentUser *currentUser;

/**
 *  Gets GetSocialConfiguration instance to change SDK configuration
 */
@property(nonatomic, strong, readonly) GetSocialConfiguration *configuration;

/**
 *  Gets Version of the GetSocial SDK
 */
@property(nonatomic, readonly) NSString *sdkVersion;

/**
 *  Gets if the GetSocial SDK was already initialized
 */
@property(nonatomic, readonly) BOOL isInitialized;

#pragma mark - App Initialization
/** @name App Initialization */

/**
 *  Initializes the GetSocial SDK.
 *
 *  @param key     App Key as shown on the Developer Portal
 *  @param success Block to be executed after the app is succesfully initialized
 *  @param failure Block to be executed if the app was not succesfully initialized
 */
- (void)initWithKey:(NSString *)key success:(void (^)())success failure:(void (^)(NSError *error))failure;

#pragma mark - Plugin Registration
/** @name Plugin Registration */

/**
 *  Registers a new instance of a plugin for a specified provider.
 *
 *  @param plugin   an instance of a plugin implementation
 *  @param provider Id of the provider for the plugin implementation
 */
- (void)registerPlugin:(GetSocialPlugin *)plugin provider:(GetSocialProvider)provider;

#pragma mark - Global Handlers
/** @name Custom Handlers */

/**
 *  Registers a block to override GetSocial's default behaviour when clicking on a user avatar.
 *  Any click on an avatar from anywhere in the SDK will call this block.
 *
 *  @param onUserAvatarClickHandler Block to be executed when a user clicks on a user avatar, user will
 *                                  be provided as param and from which view the avatar is clicked as source.
 *
 *                                  Return YES if action was handled by the app.
 *                                  Return NO for default GetSocial behaviour
 */
- (void)setOnUserAvatarClickHandler:(BOOL (^)(GetSocialUser *user, GetSocialSourceView source))onUserAvatarClickHandler;

/**
 *  Registers a block to be executed when clicking on the app avatar.
 *  Any click on the app avatar avatar from anywhere in the SDK will call this block.
 *
 *  @param onAppAvatarClickHandler  Block to be executed when a user clicks on the app avatar.
 *
 *                                  Return YES if action was handled by the app.
 *                                  Return NO for default GetSocial behaviour
 */
- (void)setOnAppAvatarClickHandler:(BOOL (^)())onAppAvatarClickHandler;

/**
 *  Registers a block to be executed when specific actions (GetSocialAction) are being done in the SDK
 *
 *  @param onActionPerformHandler Block to be executed when an action is being done.
 *                                The finalize block needs to be called always with either YES to continue performing the action
 *                                or NO if action needs to be cancelled.
 */
- (void)setOnActionPerformHandler:(void (^)(GetSocialAction action, void (^finalize)(BOOL shouldPerformAction)))onActionPerformHandler;

/**
 *  Registers a block to handle user generated content. This block is executed when a user sends any type of content through activities or chat.
 *  See GetSocialContentSource
 *
 *  @param onUserGeneratedContentHandler Block to be executed when the content is ready to be send.
 *                                       Return the approved content to send or nil if the content shouldn't be send.
 */
- (void)setOnUserGeneratedContentHandler:(NSString * (^)(GetSocialContentSource source, NSString *content))onUserGeneratedContentHandler;

#pragma mark - Activities
/** @name Activities */

/**
 *  Creates activity view builder used to open the Activities View
 *
 *  @return An instance of GetSocialActivitiesViewBuilder
 */
- (GetSocialActivitiesViewBuilder *)createActivitiesView;

/**
 *  Creates activity view builder used to open the Activities View.
 *
 *  @param group Group of the activities
 *  @param tag   Tag of the activities
 *
 *  @return An instance of GetSocialActivitiesViewBuilder
 */
- (GetSocialActivitiesViewBuilder *)createActivitiesViewWithGroup:(NSString *)group andTag:(NSString *)tag;

/**
 *  Creates activity view builder used to open the Activities View.
 *
 *  @param group Group of the activities
 *  @param tags  Tags of the activities
 *
 *  @return An instance of GetSocialActivitiesViewBuilder
 */
- (GetSocialActivitiesViewBuilder *)createActivitiesViewWithGroup:(NSString *)group andTags:(NSArray *)tags;

/**
 *  Posts an Activity
 *
 *  @param activityText Text of the activity
 *  @param image        Image to be posted along with the activity
 *  @param buttonText   Text of the activity button, or null if no button text should be shown
 *  @param action       Action generated on click, or null if no button or image is shown
 *  @param tags         An array of strings that define all the tags for the activity
 *  @param success      Block called when the activity is posted successfully
 *  @param failure      Block called when posting the activity failed
 */
- (void)postActivity:(NSString *)activityText
           withImage:(UIImage *)image
          buttonText:(NSString *)buttonText
              action:(NSString *)action
             andTags:(NSArray *)tags
             success:(void (^)())success
             failure:(void (^)(NSError *error))failure;

/**
 *  Registers a block for handling activity action button click.
 *  This block is executed when someone clicks on the action button within a Activity.
 *  The action is passed as an argument.
 *
 *  @param onActivityActionClickHandler Block called if the action button is clicked. Action contains the value defined when Activity was posted.
 */
- (void)setOnActivityActionClickHandler:(void (^)(NSString *action))onActivityActionClickHandler;

#pragma mark - Notification Center
/** @name Notification Center */

/**
 *  Gets number of unread notifications
 */
@property(nonatomic, readonly) NSInteger unreadNotificationsCount;

/**
 *  Creates notifications view builder used to open the Notifications View.
 *
 *  @return An instance of GetSocialNotificationsViewBuilder
 */
- (GetSocialNotificationsViewBuilder *)createNotificationsView;

/**
 *  Registers a block to get updates on the notifications
 *
 *  @param onNotificationsChangeHandler Block called when the unread notifications count changes.
 */
- (void)setOnNotificationsChangeHandler:(void (^)(NSInteger unreadNotificationsCount))onNotificationsChangeHandler;

#pragma mark - Smart Invites
/** @name Smart Invites */

/**
 *  Creates smart invite view builder used to open the SmartInvite View.
 *
 *  @return An instance of GetSocialSmartInviteViewBuilder
 */
- (GetSocialSmartInviteViewBuilder *)createSmartInviteView;

/**
 *  Sets a block that will be called when an invite is sent.
 *  The NSInteger param in the completion block shows how many invites are sent. If it is -1 it means there is no
 *  information about that.
 *
 *  @param completionBlock Block to be called after the invite is sent
 */
- (void)setInviteFriendsBlock:(void (^)(GetSocialInviteFriendsStatus, NSInteger))completionBlock;

/**
 *  Returns all supported invite providers.
 *
 *  @return NSArray containing constants of all supported invite providers
 */
- (NSArray *)getSupportedInviteProviders;

/**
 *  Invites friends through a specific invite provider
 *
 *  @param provider   The provider through which the invite will be sent.
 *  @param properties Dictionary that provides information about the smart invite to send
 *
 *  Supported Properties:
 *
 *  - kGetSocialImage:          Open GetSocialViewTypeSmartInvite and set an image to be sent with the invite
 *  - kGetSocialText:           Open GetSocialViewTypeSmartInvite and set a text to be sent with the invite
 *  - kGetSocialSubject:        Open GetSocialViewTypeSmartInvite and set a subject to be sent with the invite
 *  - kGetSocialReferralData:   set custom data to be sent with the invite
 */
- (void)inviteFriendsUsingProvider:(GetSocialProvider)provider withProperties:(NSDictionary *)properties;

/**
 *  Registers a block for handling referral data received
 *
 *  @param onReferralDataReceivedHandler Block to be called when the app was installed through a Smart Invite link, referralData is passed as
 *argument.
 */
- (void)setOnReferralDataReceivedHandler:(void (^)(NSArray *referralData))onReferralDataReceivedHandler;

/**
 *  Registers a block to override Invite action. This block is executed when someone clicks on a invite button.
 *
 *  @param onInviteButtonClickHandler Block to be called when the invite button is clicked.
 *                                    Return YES if action was handled by the app. Return NO for default GetSocial behaviour
 */
- (void)setOnInviteButtonClickHandler:(BOOL (^)())onInviteButtonClickHandler;

#pragma mark - User List
/** @name User List */

/**
 *  Creates user list view builder used to open the User List.
 *
 *  @param handler Block to be called when User List is closed or an User was selected
 *
 *  @return An instance of GetSocialUserListViewBuilder
 */
- (GetSocialUserListViewBuilder *)createUserListViewWithDismissHandler:(void (^)(GetSocialUser *user, BOOL didCancel))handler;

#pragma mark - Extra UI
/** @name Extra UI */

/**
 *  Closes the GetSocial current view.
 */
- (void)closeView;

/**
 *  Close the GetSocial UI temporarily, it can later be restored by calling restoreView().
 *
 *  @param saveViewState true if the state of the GetSocial UI needs to be restored later by calling restoreView().
 */
- (void)closeView:(BOOL)saveViewState;

/**
 *  Restored the GetSocial view before it was closed by closeView.
 */
- (void)restoreView;

#pragma mark - Cloud Save
/** @name Cloud Save */

/**
 *  Saves a state.
 *
 *  @param state   A string that contains the state in any format - CSV, JSON, XML etc.
 *  @param success Block called when the state is saved successfully
 *  @param failure Block called when saving the state failed
 */
- (void)saveState:(NSString *)state success:(void (^)())success failure:(void (^)(NSError *error))failure;

/**
 *  Gets the saved state.
 *
 *  @param success Block called with the state string when the state is retrieved successfully
 *  @param failure Block called when requesting the state failed
 */
- (void)savedStateWithSuccess:(void (^)(NSString *state))success failure:(void (^)(NSError *error))failure;

#pragma mark - Leaderboards
/** @name Leaderboards */

/**
 *  Requests leaderboard by identifier.
 *
 *  @param leaderboardId Identifier of the leaderboard
 *  @param success       Block called with the leaderboard object when the leaderboard is retrieved successfully
 *  @param failure       Block called when requesting the leaderboard failed
 */
- (void)leaderboard:(NSString *)leaderboardId success:(void (^)(GetSocialLeaderboard *leaderboard))success failure:(void (^)(NSError *error))failure;

/**
 *  Requests leaderboards by array of identifiers.
 *
 *  @param leaderboardIds An array of identifiers of the leaderboard
 *  @param success        Block called with an array of leaderboards when the leaderboards are retrieved successfully
 *  @param failure        Block called when requesting the leaderboards failed
 */
- (void)leaderboards:(NSArray *)leaderboardIds success:(void (^)(NSArray *leaderboards))success failure:(void (^)(NSError *error))failure;

/**
 *  Requests leaderboards page by page.
 *
 *  @param offset  Offset from which leaderboards will be retrieved
 *  @param count   Count of the leaderboards. Could be less than expected if there are less leaderboards
 *  @param success Block called with an array of leaderboards when the leaderboards are retrieved successfully
 *  @param failure Block called when requesting the leaderboard failed
 */
- (void)leaderboards:(NSInteger)offset
               count:(NSInteger)count
             success:(void (^)(NSArray *leaderboards))success
             failure:(void (^)(NSError *error))failure;

/**
 *  Requests scores page by page.
 *
 *  @param leaderboardId Identifier of the leaderboard
 *  @param offset        Offset from which scores will be retrieved
 *  @param count         Count of the scores. Could be less than expected if there are less scores
 *  @param scoreType     Type of score to retrieve, check enum GetSocialLeaderboardScoreType
 *  @param success       Block called with an array of scores when the scores are retrieved successfully
 *  @param failure       Block called when fetching the scores failed
 */
- (void)leaderboardScores:(NSString *)leaderboardId
                   offset:(NSInteger)offset
                    count:(NSInteger)count
                scoreType:(GetSocialLeaderboardScoreType)scoreType
                  success:(void (^)(NSArray *scores))success
                  failure:(void (^)(NSError *error))failure;

/**
 *  Submits the score to a specific leaderboard.
 *
 *  @param score         Score to be submitted
 *  @param leaderboardId Identifier of the leaderboard
 *  @param success       Block called with a current position in the leaderboard
 *  @param failure       Block called when submitting the score failed
 */
- (void)submitLeaderboardScore:(NSInteger)score
              forLeaderboardId:(NSString *)leaderboardId
                       success:(void (^)(NSInteger position))success
                       failure:(void (^)(NSError *error))failure;

@end
