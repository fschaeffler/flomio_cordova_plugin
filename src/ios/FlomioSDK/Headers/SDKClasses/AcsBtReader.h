//
//  AcsBtReader.h
//  SDK
//
//  Created by Boris  on 1/20/16.
//  Copyright © 2016 Flomio, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "ACSBluetooth.h"
#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#import <CommonCrypto/CommonCrypto.h>

#import "FmBluetoothDevice.h"
#import "NdefMessage.h"

@protocol AcsBtReaderDelegate<NSObject>

@optional

- (void)didReceiveReaderError:(NSError *)error;
- (void)didFindATagUuid:(NSString *)UUID fromDevice:(NSString *)serialNumber withError:(NSError *)error;
- (void)didFindADataBlockWithNdef:(NdefMessage *)ndef fromDevice:(NSString *)device withError:(NSError *)error;
- (void)didReturnResponseApdu:(NSString *)response fromDevice:(NSString *)device withError:(NSError *)error;
- (void)updateConnectedDevicesWithDevice:(FmBluetoothDevice *)device;
- (void)didChangeCardStatus:(NSNumber *)status fromDevice:(NSString *)device;
- (void)didMasterKeyUpdate:(BOOL)success withError:(NSError *)error;

@end


@interface AcsBtReader : NSObject <ABTBluetoothReaderManagerDelegate, ABTBluetoothReaderDelegate> {

    NSString *deviceId;
    NSArray *connectedPeripherals;    
    BOOL isRequestingUuid;
    
    // NDEF
    BOOL isRequestingDataBlocks;
    NSMutableData *dataBlock;
    int currentPosition;
    NDEFState state;
    CardType cardType;

    NSString *newMasterKey;
    NSString *oldMasterKey;
    
    //semaphores
    dispatch_semaphore_t sem;
    
}

- (void)startReaderWithPeripheral:(CBPeripheral *)peripheral;
- (void)transmitApdu:(NSData *)apdu;
- (void)stopReader;
- (void)requestUuid;
- (void)getDataBlocks;
//- (void)resetMasterKey:(NSString *)nmk withOldMasterKey:(NSString *)omk;

@property (nonatomic) NSUInteger batteryLevel;
@property (nonatomic, strong) id<AcsBtReaderDelegate> delegate;
@property (nonatomic, strong) NSString *serialNumber;
@property (nonatomic, strong) CBPeripheral *peripheral;
@property (nonatomic, strong) FmBluetoothDevice *device;
@property (nonatomic, strong) NSMutableArray *acceptedSerialNumbers;


@end
