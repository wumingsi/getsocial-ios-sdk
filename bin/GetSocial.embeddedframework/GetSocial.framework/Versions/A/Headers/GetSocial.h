//
//  GetSocial.h
//  GetSocialSDK
//
//  Created by Demian Denker on 01/10/13.
//  Copyright (c) 2013 GetSocial. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "GetSocialConstants.h"
#import "GetSocialUserIdentity.h"
#import "GetSocialInvitePlugin.h"
#import "GetSocialAuthState.h"
#import "GetSocialConfigurationProperties.h"
#import "GetSocialConfiguration.h"
#import "GetSocialLeaderboard.h"

/** GetSocial Singleton*/
@interface GetSocial : NSObject

#pragma mark - Singleton
/** @name Singleton */

/**
 * Gets an instance of the GetSocial
 *
 * @return GetSocial instance
 */
+ (instancetype) sharedInstance;

#pragma mark - Properties
/** @name Properties */

/** Language of the SDK */
@property (nonatomic, strong) NSString* language;

/** Returns the currently authenticated user.
 * @return GetSocialUser instance describing the user.
 *         nil if the user hasn't logged with Facebook or E-mail or has logged out.
 */
@property (nonatomic, strong) GetSocialUserIdentity* authenticatedUser;

/** Current game authentication status */
@property (nonatomic, readonly) BOOL isGameAuthenticated;

/** Current user authentication status */
@property (nonatomic, readonly) BOOL isUserAuthenticated;

/** Current chat status */
@property (nonatomic, readonly) BOOL isChatEnabled;

/** Configuration of the SDK */
@property (nonatomic, strong, readonly) GetSocialConfiguration* configuration;

/** Version of the GetSocial SDK */
@property (nonatomic, readonly) NSString* sdkVersion;


#pragma mark - Game Authentication Methods
/** @name Game Authentication Methods */

/**
 * Authenticates the game on GetSocial
 *
 * @param gameKey Key of the game
 * @param success Block to be executed after the game is succesfully authenticated.
 * @param failure Block to be executed if the game was not succesfully authenticated.
 */
- (void) authenticateGame:(NSString*) gameKey success:(void (^)()) success failure:(void (^)(NSError* error)) failure;

#pragma mark - Open UI Methods
/** @name Open UI */

/**
 * Opens the given view.
 *
 * @param viewType Type of view to open
 */
- (void) open:(GetSocialViewType) viewType;

/**
 * Opens the given view based on the provided properties.
 *
 * @param viewType Type of view to open
 * @param properties Dictionary that provides information about the specific page to be opened.
 *
 * Supported properties:
 *
 * - kGetSocialUserID: Open GetSocialViewTypeProfile, GetSocialViewTypeChat for a given GetSocial User ID
 * - kGetSocialInviteImage: Open GetSocialViewTypeSmartInvite and set an image to be sent with the invite
 * - kGetSocialInviteText: Open GetSocialViewTypeSmartInvite and set a text to be sent with the invite
 * - kGetSocialInviteSubject: Open GetSocialViewTypeSmartInvite and set a subject to be sent with the invite
 * - kGetSocialActivityTags: Open GetSocialViewTypeActivities and set the tags to add to any activity posted there
 * - kGetSocialActivityGroup: Open GetSocialViewTypeActivities and set the group to show activities for
 * - kGetSocialSource: A string that defines the source from where GetSocial view was opened
 * - kGetSocialRoomName: A string that defines the unique name of the global chat room
 */
- (void) open:(GetSocialViewType) viewType withProperties:(NSDictionary *) properties;

/**
 * Closes the GetSocial view
 */
- (void) close;

#pragma mark - Plugin Registration Methods
/** @name Plugin Registration */

/**
 * Register a new instance of a plugin for a specified provider.
 *
 * @param plugin an instance of a plugin implementation.
 * @param provider id of the provider for the plugin implementation.
 */
- (void) registerPlugin:(GetSocialPlugin*)plugin provider:(GetSocialProvider)provider;

#pragma mark - SmartInvite Methods
/** @name SmartInvite */

/**
 * Sets a block that will be called when an invite is sent
 * The NSInteger param in the completion block shows how many invites are sent. If it is -1 it means there is no information about that.
 *
 * @param completionBlock Block to be executed after the invite is sent.
 */
- (void) setInviteFriendsBlock:(void (^)(GetSocialInviteFriendsStatus,NSInteger)) completionBlock;

/**
 * Returns all supported invite providers
 *
 * @return Array contains constants of all supported providers
 */
- (NSArray*)getSupportedInviteProviders;

/**
 * Invite friends through a specific invite provider
 *
 * @param provider The provider through which the invite will be sent.
 * @param properties Dictionary that provides information about the smart invite to send
 *
 * Supported Properties:
 *
 * - kGetSocialInviteImage: Open GetSocialViewTypeSmartInvite and set an image to be sent with the invite
 * - kGetSocialInviteText: Open GetSocialViewTypeSmartInvite and set a text to be sent with the invite
 * - kGetSocialInviteSubject: Open GetSocialViewTypeSmartInvite and set a subject to be sent with the invite
 */
- (void) inviteFriendsUsingProvider:(GetSocialProvider)provider withProperties:(NSDictionary*) properties;

#pragma mark - User Authentication Methods
/** @name User Authentication */

/**
 * Call this method when the user has authenticated or reauthenticated with a provider.
 * Typically, this is called during the authentication process by the authentication plugin and
 * when the application (re)authenticates the user directly.
 *
 * @param identityInfo a dictionary with the parameters such as the token. See the specifications of the specific provider what kind of key/value pairs the provider expected.
 * @param provider id of the provider that the user authenticated with.
 * @param success called when the user is succesfully verified. The user's details can be accessed through the authenticatedUser property, which is guranteed to be frozen until success returns.
 * @param error called when the verification failed.
 */
- (void) verifyUserIdentity:(NSDictionary*)identityInfo provider:(GetSocialProvider) provider success:(void (^)()) success error:(void (^)(NSError* err)) error;

/**
 * Clear the identity of the specified provider.
 * @param provider id of the provider for the plugin implementation.
 * @param complete is called when the clear operation completed.
 */
- (void) clearUserIdentityWithProvider:(GetSocialProvider) provider complete:(void (^)()) complete;

#pragma mark - Activities Methods
/** @name Activities */

/**
 * Posts an Activity
 *
 * @param activityText The text of the activity
 * @param image The image to be posted along with the activity.
 * @param buttonText The text of the activity button, or null if no button text should be shown.
 * @param action The action generated on click, or null if no button or image is shown.
 * @param tags An array of strings that define all the tags for the activity.
 * @param success Executed when the activity is posted successfully.
 * @param failure Executed when posting the activity failed.
 */
- (void) postActivity:(NSString *)activityText withImage:(UIImage *)image buttonText:(NSString*) buttonText action:(NSString*) action andTags:(NSArray*)tags success:(void (^)()) success failure:(void (^)(NSError* error)) failure;

/**
 * Takes a screenshot that can be posted later.
 */
- (UIImage*) takeScreenshot;

/**
 * Call this to set a screenshot that you can post later.
 *
 * @param image The screenshot image.
 */
- (void) setScreenshotImage:(UIImage*)image;

/**
 * Opens the post activity screen with preloaded screenshot as a picture.
 */
- (void) postScreenshot;

/**
 * Opens the post activity screen with preloaded screenshot as a picture.
 */
- (void) postScreenshotWithProperties:(NSDictionary*) properties;

#pragma mark - Custom Handlers
/** @name Custom Handlers */

/**
 * Register a block to override GetSocial's default behaviour when clicking on a user avatar. Any click on an avatar from anywhere in the SDK will call this block.
 *
 * @param onUserAvatarClickHandler Block to be executed when a user clicks on a user avatar, user guid will be provided. Return YES if action was handled by the game. Return NO for default GetSocial behaviour
 */
- (void) setOnUserAvatarClickHandler:(BOOL (^)(NSString *getSocialUserID)) onUserAvatarClickHandler;

/**
 * Register a block to be executed when clicking on the game avatar. Any click on the game avatar avatar from anywhere in the SDK will call this block.
 *
 * @param onGameAvatarClickHandler Block to be executed when a user clicks on the game avatar. Return YES if action was handled by the game. Return NO for default GetSocial behaviour
 */
- (void) setOnGameAvatarClickHandler:(BOOL (^)()) onGameAvatarClickHandler;

/**
 * Register a block to get updates on the notifications (conversations and general notifications)
 *
 * @param onNotificationsChangeHandler Block to be executed when the unread notifications count changes.
 */
- (void) setOnNotificationsChangeHandler:(void (^)(NSInteger unreadNotificationsCount, NSInteger unreadConversationsCount)) onNotificationsChangeHandler;

/**
 * Register a block to override GetSocial's Login. Any interaction that requires an authenticated user anywhere in the SDK will call this block.
 *
 * @param onLoginRequestHandler Block to be executed to login a user.
 */
- (void) setOnLoginRequestHandler:(void (^)()) onLoginRequestHandler;

/**
 * Register a block for handling activity action button click. This block is executed when someone clicks on the action button within a Activity. The action is passed as an argument.
 *
 * @param onActivityActionClick Block to be executed if the action button is tapped. Action contains the value defined when Activity was posted.
 */
- (void) setOnActivityActionClickHandler:(void (^)(NSString *action)) onActivityActionClickHandler;


#pragma mark - Cloud Save Methods
/** @name Cloud Save */

/**
 * Saves a game state.
 *
 * @param gameState A string that contains the game state in any format - CSV, JSON, XML etc.
 * @param success Executed when the game state is saved successfully.
 * @param failure Executed when saving the game state failed.
 */
- (void) saveGameState:(NSString *)gameState success:(void (^)()) success failure:(void (^)(NSError* error)) failure;

/**
 * Gets the saved game state.
 *
 * @param success Executed with the gameState string when the game state is retrieved successfully.
 * @param failure Executed when fetching the game state failed.
 */
- (void) getSavedGameStateWithSuccess:(void (^)(NSString *gameState)) success failure:(void (^)(NSError* error)) failure;

#pragma mark - Leaderboards Methods
/** @name Leaderboards */

/**
 * Gets leaderboard by identifier.
 *
 * @param leaderboardID The identifier of the leaderboard.
 * @param success Executed with the leaderboard object when the leaderboard is retrieved successfully.
 * @param failure Executed when fetching the leaderboard failed.
 */
- (void) getLeaderboard:(NSString*)leaderboardID success:(void (^)(GetSocialLeaderboard *leaderboard)) success failure:(void (^)(NSError* error)) failure;

/**
 * Gets leaderboards by array of identifiers.
 *
 * @param leaderboardIDs An array of identifiers of the leaderboard.
 * @param success Executed with an array of leaderboards when the leaderboards are retrieved successfully.
 * @param failure Executed when fetching the leaderboards failed.
 */
- (void) getLeaderboards:(NSArray*)leaderboardIDs success:(void (^)(NSArray *leaderboards)) success failure:(void (^)(NSError* error)) failure;

/**
 * Gets leaderboards page by page.
 *
 * @param offset The offset from which leaderboards will be retrieved.
 * @param count The count of the leaderboards. Could be less than expected if there are less leaderboards.
 * @param success Executed with an array of leaderboards when the leaderboards are retrieved successfully.
 * @param failure Executed when fetching the leaderboard failed.
 */
- (void) getLeaderboards:(NSInteger)offset count:(NSInteger)count success:(void (^)(NSArray *leaderboards)) success failure:(void (^)(NSError* error)) failure;


/**
 * Gets scores page by page.
 *
 * @
 * @param offset The offset from which scores will be retrieved.
 * @param count The count of the scores. Could be less than expected if there are less scores.
 * @param success Executed with an array of scores when the scores are retrieved successfully.
 * @param failure Executed when fetching the scores failed.
 */
- (void) getLeaderboardScores:(NSString*)leaderboardID offset:(NSInteger)offset count:(NSInteger)count scoreType:(GetSocialLeaderboardScoreType)scoreType success:(void (^)(NSArray *scores)) success failure:(void (^)(NSError* error)) failure;

/**
 * Submits the score to a specific leaderboard.
 *
 * @param score The score to be submitted.
 * @param leaderboardID The id of the leaderboard on which the score will be recorded.
 * @param success Executed with a current position in the leaderboard.
 * @param failure Executed when submitting the score failes.
 */
- (void) submitLeaderboardScore:(NSInteger)score forLeaderboardID:(NSString*)leaderboardID success:(void (^)(NSInteger position)) success failure:(void (^)(NSError* error)) failure;
@end
