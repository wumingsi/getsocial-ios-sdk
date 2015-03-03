//
//  GetSocialConfigurationProperties.h
//  GetSocialSDK
//
//  Created by Chirag Gupta on 12/1/15.
//  Copyright (c) 2015 GetSocial. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface GetSocialConfigurationProperties : NSObject

struct GetSocialConfigurationPropertyStruct {

    __unsafe_unretained NSString *const WINDOW;  // drawable, color
    __unsafe_unretained NSString *const MODAL; // color
    __unsafe_unretained NSString *const HEADER; // textStyle, color, dimension
    __unsafe_unretained NSString *const TITLE_MARGIN_TOP; // dimension
    
    __unsafe_unretained NSString *const BACK_BUTTON_MARGIN_LEFT; // dimension
    __unsafe_unretained NSString *const BACK_BUTTON_MARGIN_TOP; // dimension
    __unsafe_unretained NSString *const BACK_BUTTON_NORMAL; // drawable
    __unsafe_unretained NSString *const BACK_BUTTON_PRESSED; // drawable
    
    __unsafe_unretained NSString *const CLOSE_BUTTON_MARGIN_TOP; // dimension
    __unsafe_unretained NSString *const CLOSE_BUTTON_MARGIN_RIGHT; // dimension
    __unsafe_unretained NSString *const CLOSE_BUTTON_NORMAL; // drawable
    __unsafe_unretained NSString *const CLOSE_BUTTON_PRESSED; // drawable
    
    __unsafe_unretained NSString *const CONTENT; // textStyle
    __unsafe_unretained NSString *const CONTENT_MARGIN_LEFT; // dimension
    __unsafe_unretained NSString *const CONTENT_MARGIN_TOP; // dimension
    __unsafe_unretained NSString *const CONTENT_MARGIN_RIGHT; // dimension
    __unsafe_unretained NSString *const CONTENT_MARGIN_BOTTOM; // dimension
    
    __unsafe_unretained NSString *const ENTITY_NAME; // textStyle
    __unsafe_unretained NSString *const TIMESTAMP; // textStyle
    __unsafe_unretained NSString *const BADGE; // textStyle, drawable
    __unsafe_unretained NSString *const LINK; // textStyle
    __unsafe_unretained NSString *const CALL_TO_ACTION; // textStyle
    __unsafe_unretained NSString *const CALL_TO_ACTION_TEXT_Y_OFFSET_NORMAL; //dimension
    __unsafe_unretained NSString *const CALL_TO_ACTION_TEXT_Y_OFFSET_PRESSED; //dimension
    __unsafe_unretained NSString *const MY_CHAT_NORMAL; // textStyle, drawable
    __unsafe_unretained NSString *const MY_CHAT_PRESSED; // textStyle, drawable
    __unsafe_unretained NSString *const THEIR_CHAT_NORMAL; // textStyle, drawable
    __unsafe_unretained NSString *const THEIR_CHAT_PRESSED; // textStyle, drawable
    __unsafe_unretained NSString *const PLACEHOLDER_TITLE; // textStyle
    __unsafe_unretained NSString *const PLACEHOLDER_CONTENT; // textStyle
    __unsafe_unretained NSString *const OVERSCROLL; // textStyle
    __unsafe_unretained NSString *const INPUT_FIELD; // textStyle, color
    __unsafe_unretained NSString *const HINT; // color
    __unsafe_unretained NSString *const TOOLTIP; // textStyle, drawable
    
    __unsafe_unretained NSString *const AVATAR_BORDER_SIZE; // dimension
    __unsafe_unretained NSString *const AVATAR_BORDER_COLOR; // color
    __unsafe_unretained NSString *const AVATAR_RADIUS; // dimension
    
    __unsafe_unretained NSString *const LIKE_NORMAL; // drawable
    __unsafe_unretained NSString *const LIKE_SELECTED; // drawable
    
    __unsafe_unretained NSString *const DIVIDER; // color, dimension
    
    __unsafe_unretained NSString *const FLOAT; // color
    __unsafe_unretained NSString *const INPUT_FIELD_BORDER_SIZE; // dimension
    __unsafe_unretained NSString *const INPUT_FIELD_BORDER_COLOR; // color
    __unsafe_unretained NSString *const INPUT_FIELD_RADIUS; // dimension
    
    __unsafe_unretained NSString *const POST_BUTTON_NORMAL; // drawable
    __unsafe_unretained NSString *const POST_BUTTON_PRESSED; // drawable
    
    __unsafe_unretained NSString *const LOAD_MORE_BUTTON_NORMAL; // drawable
    __unsafe_unretained NSString *const LOAD_MORE_BUTTON_PRESSED; // drawable
    
    __unsafe_unretained NSString *const INVITE_FRIENDS_BUTTON_NORMAL; // drawable
    __unsafe_unretained NSString *const INVITE_FRIENDS_BUTTON_PRESSED; // drawable
    
    __unsafe_unretained NSString *const START_CHAT_BUTTON_NORMAL; // drawable
    __unsafe_unretained NSString *const START_CHAT_BUTTON_PRESSED; // drawable
    
    __unsafe_unretained NSString *const SEGMENTED_CONTROL_BORDER_SIZE; // dimension
    __unsafe_unretained NSString *const SEGMENTED_CONTROL_BORDER_COLOR; // color
    __unsafe_unretained NSString *const SEGMENTED_CONTROL_RADIUS; // dimension
    __unsafe_unretained NSString *const SEGMENT_NORMAL; // textStyle, color
    __unsafe_unretained NSString *const SEGMENT_SELECTED; // textStyle, color
    
    __unsafe_unretained NSString *const LOADING_INDICATOR; // drawable
    __unsafe_unretained NSString *const NOTIFICATION_ICON_COMMENT; // drawable
    __unsafe_unretained NSString *const NOTIFICATION_ICON_LIKE; // drawable
    __unsafe_unretained NSString *const PLACEHOLDER_NETWORK; // drawable
    __unsafe_unretained NSString *const PLACEHOLDER_ACTIVITY; // drawable
    __unsafe_unretained NSString *const PLACEHOLDER_CHAT; // drawable
    __unsafe_unretained NSString *const DEFAULT_AVATAR; // drawable
    __unsafe_unretained NSString *const DEFAULT_INVITE_PROVIDER; // drawable
    __unsafe_unretained NSString *const LIST_ITEM_EVEN; // color
    __unsafe_unretained NSString *const LIST_ITEM_ODD; // color
    __unsafe_unretained NSString *const LIST_ITEM_UNREAD; // color
    __unsafe_unretained NSString *const LIST_ITEM_READ; // color
    
    __unsafe_unretained NSString *const IMAGE_PLACEHOLDER; // drawable
    __unsafe_unretained NSString *const BUTTON_CLOSE_IMAGE_OVERLAY; // drawable
    __unsafe_unretained NSString *const NOTIFICATION_ICON_FOLLOW; // drawable
    __unsafe_unretained NSString *const BUTTON_FACEBOOK; // drawable
    __unsafe_unretained NSString *const BUTTON_CLOSE_FACEBOOK_INVITE; // drawable
    __unsafe_unretained NSString *const CAMERA_ICON_EDITTEXT; // drawable
    __unsafe_unretained NSString *const CLOSE_IMAGE; // drawable
    __unsafe_unretained NSString *const ADD_PARTICIPANT_DISABLED; // drawable
    __unsafe_unretained NSString *const ADD_PARTICIPANT_UNCHECKED; // drawable
    __unsafe_unretained NSString *const ADD_PARTICIPANT_CHECKED; // drawable
    __unsafe_unretained NSString *const ADD_PARTICIPANTS; // drawable
    __unsafe_unretained NSString *const USER_ICON; // drawable
    __unsafe_unretained NSString *const PASSWORD_ICON; // drawable
    __unsafe_unretained NSString *const EMAIL_ICON; // drawable
    __unsafe_unretained NSString *const TICK_ICON; // drawable
    __unsafe_unretained NSString *const ERROR_ICON; // drawable
    __unsafe_unretained NSString *const FOLLOWED_ICON; // drawable
    __unsafe_unretained NSString *const FOLLOW_ICON; // drawable
    __unsafe_unretained NSString *const PLACEHOLDER_CHAT_GROUP_AVATAR; // drawable
    __unsafe_unretained NSString *const PROFILE_FOLLOW; // drawable
    __unsafe_unretained NSString *const PROFILE_FOLLOWING; // drawable
    __unsafe_unretained NSString *const PROFILE_UPLOAD; // drawable
    __unsafe_unretained NSString *const PROFILE_START_CHAT; // drawable
    __unsafe_unretained NSString *const IMAGE_CHOOSER_CAMERA; // drawable
    __unsafe_unretained NSString *const IMAGE_CHOOSER_SCREENSHOT; // drawable
    __unsafe_unretained NSString *const IMAGE_CHOOSER_PLACEHOLDER; // drawable
    __unsafe_unretained NSString *const TAKE_PICTURE_CHANGE_CAMERA; // drawable
    __unsafe_unretained NSString *const ICON_INVITE_FRIENDS_COLORED; // drawable
    __unsafe_unretained NSString *const ICON_INVITE_FRIENDS_WHITE; // drawable
    __unsafe_unretained NSString *const ENABLE_CHAT_MIGRATION;
};

extern const struct GetSocialConfigurationPropertyStruct Property;


@end
