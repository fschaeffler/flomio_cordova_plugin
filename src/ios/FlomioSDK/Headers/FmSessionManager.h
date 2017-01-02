//
//  ReaderManager.h
//  SDK
//
//  Created by Richard Grundy on 11/16/14.
//  Copyright (c) 2014 Flomio, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreBluetooth/CoreBluetooth.h>

#import "FmBluetoothSessionManager.h"
#import "FmAudioJackSessionManager.h"
#import "FmDevice.h"

#pragma mark - FloBLE Imports

#import "Logging.h"

#pragma mark - bR500 Imports

#import "FeitianReader.h"

@protocol FmSessionManagerDelegate<NSObject>

@optional

- (void)didFindATagUuid:(NSString *)UUID fromDevice:(NSString *)deviceId withError:(NSError *)error;
- (void)didFindADataBlockWithNdef:(NdefMessage *)ndef fromDevice:(NSString *)device withError:(NSError *)error;
- (void)didRespondToApduCommand:(NSString *)response fromDevice:(NSString *)deviceId withError:(NSError *)error;
- (void)didUpdateConnectedDevices:(NSArray *)devices;
- (void)didReceiveReaderError:(NSError *)error;

// Bluetooth Methods
- (void)didMasterKeyUpdate:(BOOL)success withError:(NSError *)error;
- (void)didChangeCardStatus:(NSNumber *)status fromDevice:(NSString *)device;

//BR500 Reader
- (void)didUpdateConnectedBR500:(NSArray *)peripherals;

@end

@interface FmSessionManager : NSObject <AVAudioPlayerDelegate, FeitianReaderDelegate, FmBluetoothSessionManagerDelegate, FmAudioJackSessionManagerDelegate> {
    
    // Reader Variables
    AVAudioPlayer *_audioPlayer;
    BOOL isAppLaunching;
    
    //2.0
    NSMutableArray *connectedDevices;
}

+ (id)sharedManager;

- (id)init;
- (void)startReaders;
- (void)stopReaders;

@property (nonatomic, strong) id<FmSessionManagerDelegate> delegate;
@property (nonatomic) DeviceType selectedDeviceType;

#pragma mark - Flojack Properties
@property (nonatomic, strong) NSNumber *scanPeriod; // in milliseconds
@property (nonatomic, assign) NSNumber *scanSound;


#pragma  mark - FloBLE Plus and EMV Properties

@property (nonatomic, strong) FmBluetoothSessionManager *btManager;
@property (nonatomic, strong) FmAudioJackSessionManager *ajManager;
@property (nonatomic, strong) FeitianReader *br500;
@property (nonatomic, strong) NSMutableArray *acceptedSerialNumbers;

// Set the tag polling rate in milliseconds. Value must be in range [0, 6375] and an increment of 25.
@property (nonatomic) NSInteger pollPeriod;

- (void)sendAPDUtoDevice:(NSString *)apdu;
//- (void)resetMasterKey:(NSString *)nmk withOldMasterKey:(NSString *)omk andReader:(FmBluetoothDevice *)btdevice;

@end

