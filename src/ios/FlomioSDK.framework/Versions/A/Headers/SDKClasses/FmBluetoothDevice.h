//
//  BluetoothDevice.h
//  SDK
//
//  Created by Boris  on 3/9/16.
//  Copyright © 2016 Flomio, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

#import "FmCustomTypes.h"

@class AcsBtReader;

@interface FmBluetoothDevice : NSObject

@property (nonatomic) DeviceType deviceType;
@property (nonatomic) NSUInteger batteryLevel;
@property (nonatomic, strong) NSObject *device;
@property (nonatomic, strong) CBPeripheral *peripheral;
@property (nonatomic, strong) NSString *serialNumber;
@property (nonatomic, strong) NSString *cardStatus;

- (void)sendApduCommand:(NSString *)command;
- (void)getDataBlocks;

@end
