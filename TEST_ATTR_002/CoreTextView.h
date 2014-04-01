//
//  CoreTextView.h
//  TEST_ATTR_002
//
//  Created by cxjwin on 13-7-29.
//  Copyright (c) 2013年 cxjwin. All rights reserved.
//

#import <CoreText/CoreText.h>
#import <UIKit/UIKit.h>

extern NSString *const kCoreTextViewWillDisappear;

NS_INLINE Boolean CFRangesIntersect(CFRange range1, CFRange range2) {
    CFIndex max_location = MAX(range1.location, range2.location);
    CFIndex min_tail = MIN(range1.location + range1.length, range2.location + range2.length);
    if (min_tail - max_location > 0) {
        return TRUE;
    } else {
        return FALSE;
    }
}

NS_INLINE CFRange CFRangeFromNSRange(NSRange source) {
    return CFRangeMake(source.location, source.length);
}

NS_INLINE Boolean CFLocationInRange(CFIndex loc, CFRange range) {
    return (!(loc < range.location) && (loc - range.location) < range.length) ? TRUE : FALSE;
}

@protocol CoreTextViewDelegate <NSObject>
@optional
- (void)touchedURLWithURLStr:(NSString *)urlStr;
@end

@interface CoreTextView : UIView

@property (weak, nonatomic) id<CoreTextViewDelegate> delegate;

@property (copy, nonatomic) NSMutableAttributedString *attributedString;

@property (nonatomic) CGFloat adjustWidth;

@property (nonatomic) CGSize adjustSize;

- (void)updateFrameWithAttributedString;

@end