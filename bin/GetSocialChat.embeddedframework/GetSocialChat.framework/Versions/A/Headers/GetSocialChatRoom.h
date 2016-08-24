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
#import "GetSocialChatMessage.h"

typedef NS_ENUM(NSInteger, GetSocialTypingStatus) {
    /**
     *  User is not typing
     */
    GetSocialTypingStatusNotTyping = 1,
    /**
     *  User is typing
     */
    GetSocialTypingStatusTyping = 2,
    /**
     *  unknown
     */
    GetSocialTypingStatusUnknown = 1000
};

/**
 *  Defines GetSocialChatRoom class
 */
@interface GetSocialChatRoom : NSObject

/**
 *  Id of the room
 */
@property(nonatomic, assign, readonly) NSString *roomId;

/**
 *  Contains the last received message
 */
@property(nonatomic, strong, readonly) GetSocialChatMessage *lastMessage;

/**
 *  Contains if the room has an unread message
 */
@property(nonatomic, assign, readonly) BOOL unread;

/**
 *  Marks room as read, which means there will be no unread messages
 *
 *  @param success Block called if room is marked as read
 *  @param failure Block called if operation failed
 */
- (void)markAsReadWithSuccess:(GetSocialSuccessCallback)success failure:(GetSocialFailureCallback)failure;

/**
 *  Retrieves messages of the room
 *
 *  @param lastMessage  Offset parameter
 *  @param limit        Maximum number of retrieved messages
 *  @param success      Block called if list of messages retrieved
 *  @param failure      Block called if operation failed
 */
- (void)messagesBeforeChatMessage:(GetSocialChatMessage *)lastMessage
                            limit:(NSInteger)limit
                          success:(void (^)(NSArray<GetSocialChatMessage *> *messages))success
                          failure:(GetSocialFailureCallback)failure;

/**
 *  Sends a message to the room
 *
 *  @param content Content to send
 *  @param success Block called if message was sent
 *  @param failure Block called if operation failed
 */
- (void)sendMessage:(GetSocialChatMessageContent *)content success:(GetSocialSuccessCallback)success failure:(GetSocialFailureCallback)failure;

/**
 *  Sends a Typing Status to the room
 *  Please note that if the same status is sent twice in 1 sec interval the receiver is going to receive it only once
 *
 *  @param typingStatus Typing status to send
 *  @param success      Block called if message was sent
 *  @param failure      Block called if operation failed
 */
- (void)setTypingStatus:(GetSocialTypingStatus)typingStatus success:(GetSocialSuccessCallback)success failure:(GetSocialFailureCallback)failure;

@end
