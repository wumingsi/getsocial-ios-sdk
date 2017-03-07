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
#import "GetSocialChatConfigurationProperties.h"
#import "GetSocialChatListViewBuilder.h"
#import "GetSocialChatViewBuilder.h"
#import "GetSocialConstants.h"
#import "GetSocialPrivateChatRoom.h"
#import "GetSocialPublicChatRoom.h"

@class GetSocialUser;

/**
 *  The GetSocial Singleton provides the main entry point for all the social features in the Core module
 */
@interface GetSocialChat : NSObject

#pragma mark - Singleton
/** @name Singleton */

/**
 *  Gets the shared instance of GetSocialChat
 *
 *  @return GetSocialChat instance
 */
+ (instancetype)sharedInstance;

#pragma mark - Properties
/** @name Properties */

/**
 *  Gets number of unread conversations
 */
@property(nonatomic, readonly) NSInteger unreadConversationsCount __attribute__((deprecated("use unreadPrivateRoomsCount or unreadPublicRoomsCount")))
;

/**
 *  Gets if the Chat Module is enabled
 */
@property(nonatomic, readonly) BOOL isEnabled;

/**
 *  Registers a block to get updates on the notifications
 *
 *  @param onChatNotificationsChangeHandler Block called when the unread conversations count changes.
 *  @deprecated
 */
- (void)setOnChatNotificationsChangeHandler:(void (^)(NSInteger unreadConversationsCount))onChatNotificationsChangeHandler
    __attribute__((deprecated("use setOnUnreadPrivateRoomsCountChangeHandler or setOnUnreadPublicRoomsCountChangeHandler")));

/**
 *  Adds blocks to get updates on the notifications
 *
 *  @param onUnreadPublicRoomsCountChangeHandler    Block called when the unread public rooms count changes.
 *  @param onUnreadPrivateRoomsCountChangeHandler   Block called when the unread private rooms count changes.
 *
 */
- (void)addOnUnreadRoomsCountChangeHandler:(void (^)(NSInteger unreadPublicRoomsCount))onUnreadPublicRoomsCountChangeHandler
    onUnreadPrivateRoomsCountChangeHandler:(void (^)(NSInteger unreadPrivateRoomsCount))onUnreadPrivateRoomsCountChangeHandler;

/**
 *  Remove registered blocks, stops receiving notifications
 *
 *  @param onUnreadPublicRoomsCountChangeHandler    Block to handle unread public rooms count changes.
 *  @param onUnreadPrivateRoomsCountChangeHandler   Block to handle unread private rooms count changes.
 *
 */
- (void)removeOnUnreadRoomsCountChangeHandler:(void (^)(NSInteger unreadPublicRoomsCount))onUnreadPublicRoomsCountChangeHandler
       onUnreadPrivateRoomsCountChangeHandler:(void (^)(NSInteger unreadPrivateRoomsCount))onUnreadPrivateRoomsCountChangeHandler;

#pragma mark - Create Views
/** @name Create Views */

/**
 *  Creates chat view builder used to open the Chat View.
 *
 *  @param user User to chat with
 *
 *  @return An instance of GetSocialChatViewBuilder
 */
- (GetSocialChatViewBuilder *)createChatViewForUser:(GetSocialUser *)user;

/**
 *  Creates chat view builder used to open the Chat View.
 *
 *  @param userId Id of GetSocial User to chat with
 *
 *  @return An instance of GetSocialChatViewBuilder
 */
- (GetSocialChatViewBuilder *)createChatViewForUserId:(NSString *)userId;

/**
 *  Creates chat view builder used to open the Chat View.
 *
 *  @param userId     Id of the user to chat with
 *  @param providerId Id of the external provider
 *
 *  @return An instance of GetSocialChatViewBuilder
 */
- (GetSocialChatViewBuilder *)createChatViewForProvider:(GetSocialProvider)provider userId:(NSString *)userId;

/**
 *  Creates chat view builder used to open the Chat View.
 *
 *  @param roomName Name of the chat room
 *
 *  @return An instance of GetSocialChatViewBuilder
 */
- (GetSocialChatViewBuilder *)createChatViewForRoomName:(NSString *)roomName;

/**
 *  Creates chat list view builder used to open the Chat List View.
 *
 *  @return An instance of GetSocialChatListViewBuilder
 */
- (GetSocialChatListViewBuilder *)createChatListView;

#pragma mark - Get list of rooms

/**
 *  Retrieves list of private rooms which belong to current user
 *
 *  @param success Block called if list of private rooms retrieved
 *  @param failure Block called if operation failed
 */
- (void)privateRoomsWithSuccess:(void (^)(NSArray<GetSocialPrivateChatRoom *> *rooms))success failure:(GetSocialFailureCallback)failure;

#pragma mark - Get rooms

/**
 *  Creates a new private room with the given user
 *
 *  @param user     User to chat with
 *  @param success  Block called if private room successfully created
 *  @param failure  Block called if operation failed
 *
 *  @return new private room
 */
- (void)privateRoomWithUser:(GetSocialUser *)user success:(void (^)(GetSocialPrivateChatRoom *room))success failure:(GetSocialFailureCallback)failure;

/**
 *  Creates a new private room
 *
 *  @param provider Provider
 *  @param userId   Id of other user
 *  @param success  Block called if private room successfully created
 *  @param failure  Block called if operation failed
 */
- (void)privateRoomWithProvider:(GetSocialProvider)provider
                         userId:(NSString *)userId
                        success:(void (^)(GetSocialPrivateChatRoom *room))success
                        failure:(GetSocialFailureCallback)failure;

/**
 *  Creates a new global room with the given name
 *
 *  @param roomName Name of new room
 *  @param success  Block called if private room successfully created
 *  @param failure  Block called if operation failed
 */
- (void)publicRoomWithName:(NSString *)roomName success:(void (^)(GetSocialPublicChatRoom *room))success failure:(GetSocialFailureCallback)failure;

#pragma mark - Handle messages

/**
 *  Adds handler for receiving messages
 *
 *  @param publicRoomMessageHandler        Block called if a message received in a public room
 *  @param privateRoomMessageHandler       Block called if a message received in a private room
 */
- (void)addHandlerForPublicRoomMessage:(void (^)(GetSocialPublicChatRoom *room, GetSocialChatMessage *message))publicRoomMessageHandler
                    privateRoomMessage:(void (^)(GetSocialPrivateChatRoom *room, GetSocialChatMessage *message))privateRoomMessageHandler;

/**
 *  Removes handler for receiving messages
 *
 *  @param publicRoomMessageHandler        Block to handle message received in a public room
 *  @param privateRoomMessageHandler       Block to handle message received in a private room
 */
- (void)removeHandlerForPublicRoomMessage:(void (^)(GetSocialPublicChatRoom *room, GetSocialChatMessage *message))publicRoomMessageHandler
                       privateRoomMessage:(void (^)(GetSocialPrivateChatRoom *room, GetSocialChatMessage *message))privateRoomMessageHandler;

#pragma mark - Handle Events

/**
 *  Adds handler for messages
 *
 *  @param publicRoomTypingStatusHandler        Block called if a typing status received in a public room
 *  @param privateRoomTypingStatusHandler       Block called if a typing status received in a private room
 */
- (void)addHandlerForPublicRoomTypingStatus:(void (^)(GetSocialPublicChatRoom *room, GetSocialUser *user,
                                                      GetSocialTypingStatus typingStatus))publicRoomTypingStatusHandler
                    privateRoomTypingStatus:(void (^)(GetSocialPrivateChatRoom *room, GetSocialUser *user,
                                                      GetSocialTypingStatus typingStatus))privateRoomTypingStatusHandler;

/**
 *  Removes handler for typing status messages
 *
 *  @param publicRoomTypingStatusHandler        Block to handle typing status received in a public room
 *  @param privateRoomTypingStatusHandler       Block to handle typing status received in a private room
 */
- (void)removeHandlerForPublicRoomTypingStatus:(void (^)(GetSocialPublicChatRoom *room, GetSocialUser *user,
                                                         GetSocialTypingStatus typingStatus))publicRoomTypingStatusHandler
                       privateRoomTypingStatus:(void (^)(GetSocialPrivateChatRoom *room, GetSocialUser *user,
                                                         GetSocialTypingStatus typingStatus))privateRoomTypingStatusHandler;

#pragma mark - Chat counters

/**
 *  Returns the number of private rooms with unread messages
 *
 *  @return number of rooms
 */
- (NSInteger)unreadPrivateRoomsCount;

/**
 *  Returns the number of public rooms with unread messages
 *
 *  @return number of rooms
 */
- (NSInteger)unreadPublicRoomsCount;

@end
