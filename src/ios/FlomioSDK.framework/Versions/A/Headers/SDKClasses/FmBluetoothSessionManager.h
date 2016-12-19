//
//  BluetoothManager.h
//  SDK
//
//  Created by Boris  on 3/8/16.
//  Copyright © 2016 Flomio, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

#import "AcsBtReader.h"

@protocol FmBluetoothSessionManagerDelegate<NSObject>

@optional

- (void)didReceiveReaderError:(NSError *)error;
- (void)didFindATagUuid:(NSString *)UUID fromDevice:(NSString *)deviceId withError:(NSError *)error;
- (void)didFindADataBlockWithNdef:(NdefMessage *)ndef fromDevice:(NSString *)device withError:(NSError *)error;
- (void)didReturnResponseApdu:(NSString *)response fromDevice:(NSString *)device withError:(NSError *)error;
- (void)updateConnectedDevicesWithDevice:(FmBluetoothDevice *)device;
- (void)removeDevicewithPeripheral:(CBPeripheral *)peripheral;
- (void)didChangeCardStatus:(NSNumber *)status fromDevice:(NSString *)device;
- (void)didMasterKeyUpdate:(BOOL)success withError:(NSError *)error;

@end

@interface FmBluetoothSessionManager : NSObject <CBCentralManagerDelegate, CBPeripheralDelegate, AcsBtReaderDelegate> {
    
    CBCentralManager * centralManager;
    CBPeripheral *activePeripheral;
    
    AcsBtReader *reader;
}

@property (nonatomic, strong) id<FmBluetoothSessionManagerDelegate> delegate;
@property (nonatomic, strong) NSMutableArray *acceptedSerialNumbers;

//- (void)resetMasterKey:(NSString *)nmk withOldMasterKey:(NSString *)omk andReader:(AcsBtReader *)acsbt;

@end
