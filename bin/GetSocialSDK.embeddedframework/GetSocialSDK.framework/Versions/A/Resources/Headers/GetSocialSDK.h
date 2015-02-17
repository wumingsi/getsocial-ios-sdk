//
//  GetSocialSDK.h
//  GetSocialSDK
//
//  Created by Demian Denker on 01/10/13.
//  Copyright (c) 2013 GetSocial. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "GetSocialSDKConstants.h"
#import "GetSocialSDKUser.h"
#import "GetSocialSDKInvitePlugin.h"
#import "GetSocialSDKAuthState.h"
#import "GetSocialSDKConfigurationProperties.h"
#import "GetSocialSDKConfiguration.h"

/** GetSocialSDK Singleton*/
@interface GetSocialSDK : NSObject

#pragma mark - Singleton

/**
 * Gets an instance of the GetSocialSDK
 *
 * @return GetSocialSDK instance
 */
+ (instancetype) sharedInstance;

#pragma mark - Properties

/** Language of the SDK */
@property (nonatomic, strong) NSString* language;

/** Returns the currently authenticated user.
 * @return GetSocialSDKUser instance describing the user.
 *         nil if the user hasn't logged with Facebook or E-mail or has logged out.
 */
@property (nonatomic, strong) GetSocialSDKUser* authenticatedUser;

/** Returns the currently game authentication status */
@property (nonatomic, readonly) BOOL isGameAuthenticated;

/** Configuration of the SDK */
@property (nonatomic, strong, readonly) GetSocialSDKConfiguration* configuration;
@property (nonatomic, readonly) NSString* sdkVersion;

#pragma mark - Game Authentication Methods

/**
 * Authenticates the game on GetSocial
 *
 * @param gameKey Key of the game
 */
- (void) authenticateGame:(NSString*) gameKey success:(void (^)()) success failure:(void (^)(NSError* error)) failure;

#pragma mark - Open UI Methods

/**
 * Opens the given view.
 *
 * @param viewType Type of view to open
 */
- (void) open:(GetSocialSDKViewType)viewType;

/**
 * Opens the given view based on the provided properties.
 *
 * @param viewType Type of view to open
 * @param properties Dictionary that provides information about the specific page to be opened
 *
 * Supported Properties: 
 * kGetSocialUserID: Open GetSocialSDKViewTypeProfile, GetSocialSDKViewTypeChat for a given GetSocial User ID
 *
 * kGetSocialInviteImage: Open GetSocialSDKViewTypeSmartInvite and set an image to be sent with the invite
 * kGetSocialInviteText Open GetSocialSDKViewTypeSmartInvite and set a text to be sent with the invite
 *
 * kGetSocialActivityTags: Open GetSocialSDKViewTypeActivities and set the tags to add to any activity posted there
 * kGetSocialActivityGroup: Open GetSocialSDKViewTypeActivities and set the group to show activities for

 * kGetSocialSource: A string that defines the source from where GetSocial view was opened
 */
- (void) open:(GetSocialSDKViewType)viewType withProperties:(NSDictionary *)properties;

/**
 * Closes the GetSocial view
 */
- (void) close;

#pragma mark - Plugin Registration Methods

/**
 * Register a new instance of a plugin for a specified provider.
 *
 * @param plugin an instance of a plugin implementation.
 * @param provider id of the provider for the plugin implementation.
 */
- (void) registerPlugin:(GetSocialSDKPlugin*)plugin provider:(GetSocialSDKProvider)provider;

#pragma mark - SmartInvite Methods

/**
 * Sets a block that will be called when an invite is sent
 * The NSInteger param in the completion block shows how many invites are sent. If it is -1 it means there is no information about that.
 *
 * @param completionBlock Block to be executed after the invite is sent.
 */
- (void) setInviteFriendsBlock:(void (^)(GetSocialSDKInviteFriendsStatus,NSInteger)) completionBlock;

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
 * @param inviteText The text to be sent with the invite. If it is nil the default text is sent.
 * @param inviteImage The image to be sent with the invite. If it is nil the default image from the sandbox will be sent.
 */
- (void) inviteFriendsUsingProvider:(GetSocialSDKProvider)provider withProperties:(NSDictionary*) properties;


#pragma mark - User Authentication Methods

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
- (void) verifyUserIdentity:(NSDictionary*)identityInfo provider:(GetSocialSDKProvider) provider success:(void (^)()) success error:(void (^)(NSError* err)) error;

/**
 * Clear the identity of the specified provider.
 * @param provider id of the provider for the plugin implementation.
 * @param complete is called when the clear operation completed.
 */
- (void) clearUserIdentityWithProvider:(GetSocialSDKProvider) provider complete:(void (^)()) complete;

#pragma mark - Activities Methods

/**
 * Posts a Purchase Activity
 *
 * @param activityText The text of the activity (can't be nil)
 * @param itemID The ID of the item purchased (will be sent in the callback if someone clicks the action button, can't be nil)
 * @param itemName The name of the item purchased (can't be nil, max 16 characters)
 * @param imageURL The URL for the image of the item purchased. (suggested size: 48 x 48)
 * @param buttonText The text for the action button dislayed in the purchase activity (max 10 characters)
 * @param tags An array of strings that define all the tags for the activity.
 *
 * @return YES if valid parameters were passed, NO otherwise
 */
- (BOOL) postPurchaseActivity:(NSString *)activityText andItemID:(NSString *)itemID andItemName:(NSString *)itemName andImageURL:(NSString *)imageURL andButtonText:(NSString *)buttonText andTags:(NSArray*) tags;

/**
 * Posts an Activity
 *
 * @param activityText The text of the activity
 * @param image The image to be posted along with the activity.
 * @param tags An array of strings that define all the tags for the activity.
 * @param success Executed when the activity is posted successfully.
 * @param failure Executed when posting the activity failed.
 */
- (void) postActivity:(NSString *)activityText withImage:(UIImage *)image andTags:(NSArray*)tags success:(void (^)()) success failure:(void (^)(NSError* error)) failure;

/**
 * Register a Handler Block for Purchase Activity. This block is executed when someone taps on the action button within a Purchase type activity. The itemID is passed as an argument.
 *
 * @param onPurchaseActivityButtonPressed Block to be executed if the action button is tapped
 */
- (void) setPurchaseActivityButtonPressedHandler:(void (^)(NSString *itemID)) onPurchaseActivityButtonPressed;

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

/**
 * Register a block to override GetSocial's User Profile. Any attempt to open a profile from anywhere in the SDK will call this block.
 *
 * @param onOpenProfileHandler Block to be executed when a user profile with given guid is opened.
 */
- (void) setOnOpenProfileHandler:(void (^)(NSString *getSocialUserID)) onOpenProfileHandler;

/**
 * Register a block to get updates on the notifications (conversations and general notifications)
 *
 * @param onNotificationsChangedHandler Block to be executed when the unread notifications count changes.
 */
- (void) setOnNotificationsChangedHandler:(void (^)(NSInteger unreadNotificationsCount, NSInteger unreadConversationsCount)) onNotificationsChangedHandler;

/**
 * Register a block to override GetSocial's Login. Any interaction that requires an authenticated user anywhere in the SDK will call this block.
 *
 * @param onLoginRequestHandler Block to be executed to login a user.
 */
- (void) setOnLoginRequestHandler:(void (^)()) onLoginRequestHandler;

#pragma mark - Cloud Save Methods

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

@end
