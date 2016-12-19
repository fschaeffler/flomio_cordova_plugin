//
//  FmAudioJackDevice.h
//  SDK
//
//  Created by Boris  on 3/24/16.
//  Copyright © 2016 Flomio, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "FmCustomTypes.h"

@class Reader;


@interface FmAudioJackDevice : NSObject

@property (nonatomic) DeviceType deviceType;
@property (nonatomic) NSUInteger batteryLevel;
@property (nonatomic, strong) id device;
@property (nonatomic, strong) NSString *serialNumber;
@property (nonatomic, strong) NSString *cardStatus;
@property (nonatomic, strong) NSNumber *communication;


- (void)sendApduCommand:(NSString *)command;
- (void)getDataBlocks;
- (void)setDevice:(id)device ofType:(DeviceType)type;


typedef NS_ENUM(NSInteger, ReaderStateType) { // new Apple way of doing emums http://nshipster.com/ns_enum-ns_options/
    kReadUUID,
    kReadDataBlocks,
    kWriteDataBlocks
};


@end
