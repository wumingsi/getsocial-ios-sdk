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

#import "GetSocialConstants.h"
#import "GetSocialUser.h"
#import "GetSocialUserIdentity.h"

/**
 *  Describes the current user
 */
@interface GetSocialCurrentUser : GetSocialUser

#pragma mark - User Details
/** @name User Details */

/**
 *  Sets a new display name for the user
 *
 *  @param displayName New display name of the user
 *  @param success     Block called if display name was updated
 *  @param failure     Block called if display name was not updated because includes invalid characters or exceeds the max length
 */

- (void)setDisplayName:(NSString *)displayName success:(GetSocialSuccessCallback)success failure:(GetSocialFailureCallback)failure;

/**
 *  Sets a new avatar url for the user
 *
 *  @param avatarUrl New avatar url of the user
 *  @param success   Block called if avatar url was updated
 *  @param failure   Block called if avatar url was not updated because url is not valid or not accesible
 */
- (void)setAvatarUrl:(NSString *)avatarUrl success:(GetSocialSuccessCallback)success failure:(GetSocialFailureCallback)failure;

#pragma mark - User Identity
/** @name User Identity */

/**
 *  Adds an identity to the user
 *
 *  @param identity     Identity information to add to the user
 *  @param complete     Block called when operation is completed, result param tells if identity was added, or current/remote user has been used
 *  @param failure      Block called if identity could not be added
 *  @param conflict     Block called if identity already belongs to another user and the conflict needs to be resolved. The resolve block
 *                      needs to be called with the chosen resolution strategy
 */
- (void)addUserIdentity:(GetSocialUserIdentity *)identity
               complete:(GetSocialUserIdentityCompleteCallback)complete
                failure:(GetSocialFailureCallback)failure
               conflict:
                   (void (^)(GetSocialUser *currentUser, GetSocialUser *remoteUser, GetSocialUserIdentityResolveConflictCallback conflict))conflict;

/**
 *  Removes an identity from the user
 *
 *  @param provider Provider of the identity to be removed, will be lowercased
 *  @param success  Block called if identity was removed
 *  @param failure  Block called if identity couldn't be removed
 */
- (void)removeUserIdentityForProvider:(GetSocialProvider)provider success:(GetSocialSuccessCallback)success failure:(GetSocialFailureCallback)failure;

/**
 *  Resets the current user and generates a new anonymous user.
 *
 *  @param success Block called if user was reset
 *  @param failure Block called if operation was not completed, probably because connectivity issues
 */
- (void)resetWithSuccess:(GetSocialSuccessCallback)success failure:(GetSocialFailureCallback)failure;

/**
 *  Adds specified user to list of users who the current user is following
 *
 *  @param user    User to follow
 *  @param success Block called if the user is followed
 *  @param failure Block called if operation was not completed
 */
- (void)followUser:(GetSocialUser *)userToFollow success:(void (^)())success failure:(GetSocialFailureCallback)failure;

/**
 *  Adds user with specified userId and provider to list of users who the current user is following
 *
 *  @param provider Provider
 *  @param userId   Id of user on the specified provider
 *  @param success  Block called if the user is followed
 *  @param failure  Block called if operation was not completed
 */
- (void)followUserWithProvider:(GetSocialProvider)provider
                        userId:(NSString *)userId
                       success:(GetSocialSuccessCallback)success
                       failure:(GetSocialFailureCallback)failure;

/**
 *  Removes specified user from list of users who the current user is following
 *
 *  @param user     User to unfollow
 *  @param success  Block called if the user is not followed
 *  @param failure  Block called if operation was not completed
 */
- (void)unfollowUser:(GetSocialUser *)userToUnfollow success:(void (^)())success failure:(GetSocialFailureCallback)failure;

/**
 *  Removes user with specified userId and provider from list of users who the current user is following
 *
 *  @param provider Provider
 *  @param userId   Id of user on the specified provider
 *  @param success  Block called if the user is not followed
 *  @param failure  Block called if operation was not completed
 */
- (void)unfollowUserWithProvider:(GetSocialProvider)provider
                          userId:(NSString *)userId
                         success:(GetSocialSuccessCallback)success
                         failure:(GetSocialFailureCallback)failure;

/**
 *  Returns the list of followers for the current user
 *
 *  @param offset  Offset from which users will be retrieved
 *  @param count   Count of users. Could be less than expected if there are less users
 *  @param success Block called if the list is retrieved
 *  @param failure Block called if operation was not completed
 */
- (void)followersWithOffset:(NSInteger)offset
                      count:(NSInteger)count
                    success:(void (^)(NSArray<GetSocialUser *> *))success
                    failure:(GetSocialFailureCallback)failure;

/**
 *  Returns the list of users who the current user is following
 *
 *  @param offset  Offset from which users will be retrieved
 *  @param count   Count of users. Could be less than expected if there are less users
 *  @param success Block called if the list is retrieved
 *  @param failure Block called if operation was not completed
 */
- (void)followingWithOffset:(NSInteger)offset
                      count:(NSInteger)count
                    success:(void (^)(NSArray<GetSocialUser *> *))success
                    failure:(GetSocialFailureCallback)failure;

@end
