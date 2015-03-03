//
//  GetSocialUserIdentity.h
//  GetSocialSDK
//
//  Created by Jan-Eric Duden on 12/05/14.
//  Copyright (c) 2014 GetSocial. All rights reserved.
//

#import <Foundation/Foundation.h>

/** Describes an authentictaed user. 
 */
@interface GetSocialUserIdentity : NSObject

/**
 * initializes the object 
 * @param identifier unique identifier of the user. Must not be nil.
 * @param displayName can be nil.
 * @return object instance. nil if the initialization failed.
 */
-(id) initWithGuid:(NSString*) guid displayName:(NSString*) displayName;

/** Unique Identifier of the user. */
@property (strong,readonly) NSString* guid;

/** Display name of the user. Can be nil if no display name is avaialble. */
@property (strong,readonly) NSString* displayName;

@end
