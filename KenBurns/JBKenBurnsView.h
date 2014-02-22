//
//  KenBurnsView.h
//  KenBurns
//
//  Created by Javier Berlana on 9/23/11.
//  Copyright (c) 2011, Javier Berlana
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy of this 
//  software and associated documentation files (the "Software"), to deal in the Software 
//  without restriction, including without limitation the rights to use, copy, modify, merge, 
//  publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons 
//  to whom the Software is furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in all copies 
//  or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, 
//  INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR 
//  PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE 
//  FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, 
//  ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS 
//  IN THE SOFTWARE.
//


#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>

@class JBKenBurnsView;

#pragma - KenBurnsViewDatasource 
@protocol JBKenBurnsViewDatasource <NSObject>

/**
 * Tells the data source to return number of images to show
 * in \c kenBurnsView. (required)
 *
 * @param kenBurnsView The JBKenBurnsView requesting this information
 */
- (NSInteger)numberOfImagesInKenBurnsView:(JBKenBurnsView*)kenBurnsView;

/**
 * Asks the data source for a UIImage for display
 * in \c kenBurnsView. (required)
 *
 * @param kenBurnsView The JBKenBurnsView requesting this information
 * @param imageIndex Index of the UIImage being requested
 */
- (UIImage*)kenBurnsView:(JBKenBurnsView*)kenBurnsView imageAtIndex:(NSInteger)imageIndex;
@end

#pragma - KenBurnsViewDelegate
@protocol JBKenBurnsViewDelegate <NSObject>
@optional
- (void)didShowImageAtIndex:(NSUInteger)index;
- (void)didFinishAllAnimations;
@end

@interface JBKenBurnsView : UIView

@property (unsafe_unretained) id<JBKenBurnsViewDelegate> delegate;
@property (unsafe_unretained) id<JBKenBurnsViewDatasource> datasource;

- (void) animateWithImagePaths:(NSArray *)imagePaths transitionDuration:(float)time loop:(BOOL)isLoop isLandscape:(BOOL)isLandscape;
- (void) animateWithImages:(NSArray *)images transitionDuration:(float)time loop:(BOOL)isLoop isLandscape:(BOOL)isLandscape;

/**
 * Starts animation. Images are requested from datasource
 *
 */
- (void) startAnimationWithDatasource:(id<JBKenBurnsViewDatasource>)datasource transitionDuration:(float)time loop:(BOOL)isLoop isLandscape:(BOOL)isLandscape;

- (void) stopAnimation;

/**
 * Clear images and animation from the view
 *
 */
- (void) clear;

@end


