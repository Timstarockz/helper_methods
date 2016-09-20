//
//  helper_methods.h
//
//  Created by Tim Desir on 4/19/15.
//  Copyright (c) 2015 Tim Desir. All rights reserved.
//

#import <UIKit/UIKit.h>


/***********************************************************************************************************************************************************/


/*
 *  System Versioning Preprocessor Macros
 */

#define SYSTEM_VERSION_EQUAL_TO(v)                  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedSame)
#define SYSTEM_VERSION_GREATER_THAN(v)              ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedDescending)
#define SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(v)  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN(v)                 ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN_OR_EQUAL_TO(v)     ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedDescending)

/*
 
 Usage
 
 
 if (SYSTEM_VERSION_LESS_THAN(@"4.0")) {
 ...
 }
 
 if (SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(@"3.1.1")) {
 ...
 }
 
 */



/***********************************************************************************************************************************************************/



#define Init(NAME, CLASS) CLASS *NAME = [[CLASS alloc] init]

#define CAFadeAnimated(VIEW, ANIMATION_NAME,DURATION) CATransition *ANIMATION_NAME = [CATransition animation];[ANIMATION_NAME setDuration:DURATION]; [ANIMATION_NAME setType:kCATransitionFade];[ANIMATION_NAME setTimingFunction:[CAMediaTimingFunction functionWithName:kCAMediaTimingFunctionEaseIn]];[[VIEW layer] addAnimation:ANIMATION_NAME forKey:kCATransitionFade]


#define Animated(TIME) [UIView beginAnimations:nil context:nil]; [UIView setAnimationDuration:TIME]
#define NonAnimated [UIView commitAnimations]

//#define Animated(TIME) [UIView animateWithDuration:TIME delay:0 usingSpringWithDamping:.5 initialSpringVelocity:.4 options: 0 animations: ^ {
//#define NonAnimated } completion:^(BOOL finished) {}];

#define _eq(OB, OB2) OB == OB2

#define Between(value, min, max) (value < max && value > min)

#define Alert(TITLE, MESSAGE) UIAlertView *al = [[UIAlertView alloc] initWithTitle:TITLE message:MESSAGE delegate:nil cancelButtonTitle:@"Dismiss" otherButtonTitles:nil];[al show]

@interface Helper : NSObject 
+ (NSString *)generateCreatedFromDateString:(NSString *)createdAtDateString;
- (CAShapeLayer *)drawLineFromPoint:(CGPoint)fromPoint toPoint:(CGPoint)toPoint withColor:(UIColor *)color andLineWidth:(CGFloat)lineWidth;
@end


@interface NSString (NSStringAdditions)

@property (NS_NONATOMIC_IOSONLY, readonly, copy) NSString *URLEncode;

+ (NSString *) base64StringFromData:(NSData *)data length:(int)length;
+ (BOOL)isValidEmail:(NSString *)emailString Strict:(BOOL)strictFilter;

@end

@interface NSArray (Extensions)
- (NSString*)jsonStringWithPrettyPrint:(BOOL)prettyPrint;
@end

@interface NSDictionary (BVJSONString)
- (NSString *)jsonStringWithPrettyPrint:(BOOL)prettyPrint;

+ (NSDictionary *)fromJSONString:(NSString *)json;
@end

@interface UIImage (helper_methods)

@property (NS_NONATOMIC_IOSONLY, readonly, copy) NSString *base64String;

+ (UIImage *)roundCornersOfImage:(UIImage *)image toRadius:(float)radius;


- (UIImage *)roundedCornerImage:(NSInteger)cornerSize borderSize:(NSInteger)borderSize;
- (void)addRoundedRectToPath:(CGRect)rect context:(CGContextRef)context ovalWidth:(CGFloat)ovalWidth ovalHeight:(CGFloat)ovalHeight;

@property (NS_NONATOMIC_IOSONLY, readonly) BOOL hasAlpha;
@property (NS_NONATOMIC_IOSONLY, readonly, strong) UIImage *imageWithAlpha;
- (UIImage *)transparentBorderImage:(NSUInteger)borderSize;
- (CGImageRef)newBorderMask:(NSUInteger)borderSize size:(CGSize)size;


- (UIImage *)croppedImage:(CGRect)bounds;
- (UIImage *)thumbnailImage:(NSInteger)thumbnailSize
          transparentBorder:(NSUInteger)borderSize
               cornerRadius:(NSUInteger)cornerRadius
       interpolationQuality:(CGInterpolationQuality)quality;
- (UIImage *)resizedImage:(CGSize)newSize
     interpolationQuality:(CGInterpolationQuality)quality;
- (UIImage *)resizedImageWithContentMode:(UIViewContentMode)contentMode
                                  bounds:(CGSize)bounds
                    interpolationQuality:(CGInterpolationQuality)quality;
- (UIImage *)resizedImage:(CGSize)newSize
                transform:(CGAffineTransform)transform
           drawTransposed:(BOOL)transpose
     interpolationQuality:(CGInterpolationQuality)quality;
- (CGAffineTransform)transformForOrientation:(CGSize)newSize;

@end


#define DictionaryOfStates @"AL" :@"Alabama", @"AK" :@"Alaska",@"AS" :@"America Samoa",@"AZ" :@"Arizona",@"AR" :@"Arkansas",@"CA" :@"California",@"CO" :@"Colorado",@"CT" :@"Connecticut",@"DE" :@"Delaware",@"DC" :@"District of Columbia",@"FM" :@"Micronesia1",@"FL" :@"Florida",@"GA" :@"Georgia",@"GU" :@"Guam",@"HI" :@"Hawaii",@"ID" :@"Idaho",@"IL" :@"Illinois",@"IN" :@"Indiana",@"IA" :@"Iowa",@"KS" :@"Kansas",@"KY" :@"Kentucky",@"LA" :@"Louisiana",@"ME" :@"Maine",@"MH" :@"Islands1",@"MD" :@"Maryland",@"MA" :@"Massachusetts",@"MI" :@"Michigan",@"MN" :@"Minnesota",@"MS" :@"Mississippi",@"MO" :@"Missouri",@"MT" :@"Montana",@"NE" :@"Nebraska",@"NV" :@"Nevada",@"NH" :@"New Hampshire",@"NJ" :@"New Jersey",@"NM" :@"New Mexico",@"NY" :@"New York",@"NC" :@"North Carolina",@"ND" :@"North Dakota",@"OH" :@"Ohio",@"OK" :@"Oklahoma",@"OR" :@"Oregon",@"PW" :@"Palau",@"PA" :@"Pennsylvania",@"PR" :@"Puerto Rico",@"RI" :@"Rhode Island",@"SC" :@"South Carolina",@"SD" :@"South Dakota",@"TN" :@"Tennessee",@"TX" :@"Texas",@"UT" :@"Utah",@"VT" :@"Vermont",@"VI" :@"Virgin Island",@"VA" :@"Virginia",@"WA" :@"Washington",@"WV" :@"West Virginia",@"WI" :@"Wisconsin",@"WY" :@"Wyoming"


