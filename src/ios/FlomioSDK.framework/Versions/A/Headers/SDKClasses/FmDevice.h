//
//  FmDevice.h
//  SDK
//
//  Created by Boris  on 3/24/16.
//  Copyright © 2016 Flomio, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FmBluetoothDevice.h"
#import "FmAudioJackDevice.h"

@class AcsBtReader;

@interface FmDevice : NSObject

@property (nonatomic) DeviceType deviceType;
@property (nonatomic, strong) id device;
@property (nonatomic) NSUInteger batteryLevel;
@property (nonatomic, strong) NSString *serialNumber;
@property (nonatomic, strong) NSString *cardStatus;
@property (nonatomic, strong) NSNumber *communication;


- (void)sendApduCommand:(NSString *)command;
- (void)getDataBlocks;
- (void)setDevice:(id)device;

@end
