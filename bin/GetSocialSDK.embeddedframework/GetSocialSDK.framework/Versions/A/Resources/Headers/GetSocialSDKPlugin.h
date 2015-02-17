//
//  GetSocialSDKPlugin.h
//  GetSocialSDK
//
//  Created by Jan-Eric Duden on 26/05/14.
//  Copyright (c) 2014 GetSocial. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GetSocialSDKConstants.h"
/**
 * This protocol provides the base protocol for all plugins of by the GetSocial SDK.
 */

@interface GetSocialSDKPlugin : NSObject

@property (nonatomic, strong) id title;
@property (nonatomic, strong) id details;
@property (nonatomic, strong) NSString* imageUrl;
@property (nonatomic) BOOL enabled;
@property (nonatomic) NSInteger displayOrder;

- (BOOL) isAvailableForDevice;

@end
