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

/**
 *  Defines GetSocialPublicChatRoom class
 * By default a public room won't receive messages until subscribe method is not called
 */
@interface GetSocialPublicChatRoom : GetSocialChatRoom

@property(nonatomic, strong, readonly) NSString *name;

/**
 *  Returs if current user is subscribed to the room
 *
 *  @return YES, if subscribed, NO if not
 */
- (BOOL)isSubscribed;

/**
 *  Subscribes to room, which means room will receive messages
 *
 *  @param success Block called if successfully subscribed
 *  @param failure Block called if operation failed
 */
- (void)subscribeWithSuccess:(GetSocialSuccessCallback)success failure:(GetSocialFailureCallback)failure;

/**
 *  Unsubscribes from room, will not receive messages
 *
 *  @param success Block called if successfully unsubscribed
 *  @param failure Block called if operation failed
 */
- (void)unsubscribeWithSuccess:(GetSocialSuccessCallback)success failure:(GetSocialFailureCallback)failure;

@end
