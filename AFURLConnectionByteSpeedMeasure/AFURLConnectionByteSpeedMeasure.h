// AFURLConnectionByteSpeedMeasure.h
//
//  Created by Oliver Letterer on 27.01.13.
//  Copyright (c) 2013 Oliver Letterer. All rights reserved.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#import <Foundation/Foundation.h>



/**
 Class that measures speed (e.g. download or upload) of an AFURLConnectionOperation. A window function over the last `windowSize` values is used to calculate the average `speed`. To not fire calculation every time a now data chunk is appended, one can set `speedCalculationTimeInterval`.
 */
@interface AFURLConnectionByteSpeedMeasure : NSObject

/**
 BOOL flag indicating if this speed measure is active.
 */
@property (nonatomic, assign) BOOL active;

/**
 The calculated speed in bytes/s.
 */
@property (nonatomic, readonly) double speed;

/**
 The request start time.
 */
@property (nonatomic, assign) double startTime;

/**
 The `speed` in a human readable format.
 */
@property (nonatomic, copy, readonly) NSString *humanReadableSpeed;

/**
 The size of the window used to calculate `speed`.
 */
@property (nonatomic, assign) NSUInteger windowSize;

/**
 Speed calculation will only happen if the last calculation if `speedCalculationTimeInterval` seconds in the past. Default is 0 (calculation happens on each chunks).
 */
@property (nonatomic, assign) NSTimeInterval speedCalculationTimeInterval;

/**
 Updates the calculated speed if `active` is `YES`.
 */
- (void)updateSpeedWithDataChunkLength:(NSUInteger)dataChunkLength receivedAtTime:(double)time;

/**
 Computes the estimated remaining time in seconds based on the current `speed`.
 */
- (NSTimeInterval)remainingTimeOfTotalSize:(long long)totalSize numberOfCompletedBytes:(long long)numberOfCompletedBytes;

/**
 Computes the estimated remaining time in seconds based on the current `speed` and returns it in a human readable form.
 */
- (NSString *)humanReadableRemainingTimeOfTotalSize:(long long)totalSize numberOfCompletedBytes:(long long)numberOfCompletedBytes;

@end
