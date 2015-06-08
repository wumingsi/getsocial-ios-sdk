//
//  GetSocialConfiguration.h
//  GetSocialSDK
//
//  Created by Demian Denker on 05/02/15.
//  Copyright (c) 2015 GrambleWorld. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "GetSocialConstants.h"

@interface GetSocialConfiguration : NSObject

+ (instancetype)sharedInstance;

#pragma mark - Customisation Methods

/**
 * Clear SDK Customizations and set them to default
 *
 */
- (void) clear;

/**
 * Sets the image path for a specific elementID.
 *
 * @param path The path to the file.
 * @param elementID The ID of the element to customise.
 */
- (void) setImagePath:(NSString*)path forElementID:(NSString*)elementID;

/**
 * Sets the image for a specific elementID.
 *
 * @param image The image to use.
 * @param elementID The ID of the element to customise.
 */
- (void) setImageResource:(UIImage*)image forElementID:(NSString*)elementID;

/**
 * Sets the image for a specific elementID.
 *
 * @param color The color to use.
 * @param elementID The ID of the element to customise.
 */
- (void) setColor:(UIColor*)color forElementID:(NSString*)elementID;

/**
 * Sets the dimension for a specific elementID.
 *
 * @param dimension The dimension value.
 * @param elementID The ID of the element to customise.
 */
- (void) setDimension:(CGFloat)dimension forElementID:(NSString*)elementID;

/**
 * Sets the dimension for a specific elementID with an implicit option to turn off any scaling.
 *
 * @param dimension The dimension value.
 * @param prescaled YES if scaling calculations are already done.
 * @param elementID The ID of the element to customise.
 */
-(void) setDimension:(CGFloat)dimension prescaled:(BOOL)prescaled forElementID:(NSString*)elementID;

/**
 * Sets the aspect ratio for a specific elementID.
 *
 * @param aspectRatio The aspectRatio value.
 * @param elementID The ID of the element to customise.
 */
- (void) setAspectRatio:(CGFloat)aspectRatio forElementID:(NSString*)elementID;

/**
 * Sets the text style for a specific elementID.
 *
 * @param font The font for the element.
 * @param fontColor The color of the font for the element.
 * @param elementID The ID of the element to customise.
 */
- (void) setTextStyle:(UIFont*)font fontColor:(UIColor*) fontColor forElementID:(NSString*)elementID;

/**
 * Sets the text style for a specific elementID.
 *
 * @param font The font for the element.
 * @param fontColor The color of the font for the element.
 * @param strokeColor The color of the stroke of the font for the element.
 * @param strokeSize The size of the stroke of the font for the element.
 * @param strokeOffset The offset of the stroke of the font for the element.
 * @param elementID The ID of the element to customise.
 */
- (void) setTextStyle:(UIFont*)font fontColor:(UIColor*) fontColor strokeColor:(UIColor*) strokeColor strokeSize:(CGFloat) strokeSize strokeOffset:(CGSize) strokeOffset forElementID:(NSString*)elementID;

/**
 * Sets the animation style for a specific elementID.
 *
 * @param style The style of animation.
 * @param elementID The ID of the element to customise.
 */
- (void) setAnimationStyle:(GetSocialAnimationStyle)style forElementID:(NSString*)elementID;

/**
 * Sets the preferable width of GetSocial view.
 *
 * @param width The preferable width.
 */
- (void) setPreferredWindowWidth:(CGFloat)width;

/**
 * Sets the preferable height of GetSocial view.
 *
 * @param height The preferable height.
 */
- (void) setPreferredWindowHeight:(CGFloat)height;

/**
 * Override the default scale factor for the GetSocial view.
 *
 * @param scaleFactor Scale Factor multiplier.
 */
- (void) setScaleFactor:(CGFloat)scaleFactor;

/**
 * Override the default scale mode for the GetSocial view.
 *
 * @param scaleMode Scale Mode for GetSocial view.
 */
- (void) setScaleMode:(GetSocialScaleMode)scaleMode;

/**
 * Sets the base path for all the images.
 *
 * @param path The path to the images.
 */
- (void)setBasePathForImages:(NSString*)path;

/**
 * Sets flags.
 *
 * @param flagID The ID of the flag.
 * @param flagValue The value of the flag
 * 
 */
- (void)setFlag:(BOOL)flagValue forID:(NSString*)flagID;

/**
 * Specifies the base width of the designs for your GetSocial integration.
 *
 * @param baseDesignWidth The design width.
 */
- (void) setBaseDesignWidth:(CGFloat)baseDesignWidth;

@end