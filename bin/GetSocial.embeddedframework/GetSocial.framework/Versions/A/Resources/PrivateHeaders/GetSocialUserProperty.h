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

/**
 *  Constants for the differents property scope
 */
typedef NS_ENUM(NSUInteger, GetSocialUserPropertyScope) {
    /**
     *  Private properties can only be accesible from the current user
     */
    GetSocialUserPropertyScopePrivate,
    /**
     *  Public properties can be accesible by any other user
     */
    GetSocialUserPropertyScopePublic
};

/**
 *  Describes a property of an user.
 */
@interface GetSocialUserProperty : NSObject

/**
 *  Unique Key of the property
 */
@property(nonatomic, strong, readonly) NSString *key;

/**
 *  Value of the property.
 */
@property(nonatomic, strong, readonly) NSString *value;

/**
 *  Scope of the property.
 */
@property(nonatomic, assign, readonly) GetSocialUserPropertyScope scope;

/**
 *  Creates and returns a new GetSocialUserProperty
 *
 *  @param key   Key of the property
 *  @param value Value of the property
 *  @param scope Scope of the property (see GetSocialUserPropertyScope enum)
 *
 *  @return A instance of GetSocialUserProperty with the specified parameters
 */
+ (GetSocialUserProperty *)propertyWithKey:(NSString *)key value:(NSString *)value scope:(GetSocialUserPropertyScope)scope;

@end
