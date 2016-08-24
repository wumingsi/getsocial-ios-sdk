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
#import "GetSocialChatMessageContent.h"

@class GetSocialUser;

/**
 *  Defines GetSocialChatMessage abstract class
 */
@interface GetSocialChatMessage : NSObject

/**
 *  Unique identifier of the message
 */
@property(nonatomic, strong, readonly) NSString *guid;

/**
 *  Sender of message
 */
@property(nonatomic, strong, readonly) GetSocialUser *sender;

/**
 *  Timestamp when message is sent
 */
@property(nonatomic, strong, readonly) NSDate *timestamp;

/**
 *  Returns if message was sent by current user or not
 */
@property(assign, readonly) BOOL wasSentByMe;

/**
 *  Content of message
 */
@property(nonatomic, strong, readonly) GetSocialChatMessageContent *content;

@end
