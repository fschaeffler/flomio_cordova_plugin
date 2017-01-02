//
//  FmAudioJackDeviceManager.h
//  SDK
//
//  Created by Boris  on 3/24/16.
//  Copyright © 2016 Flomio, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

#import <AudioToolbox/AudioToolbox.h>
#import "AcsAjReader.h"
#import "FeitianAjReader.h"
#import "NdefMessage.h"
#import "FmCustomTypes.h"
#import "FmAudioJackDevice.h"

@protocol FmAudioJackSessionManagerDelegate<NSObject>

@optional

- (void)didReceiveReaderError:(NSError *)error;
- (void)didFindATagUuid:(NSString *)UUID fromDevice:(NSString *)deviceId withError:(NSError *)error;
- (void)didFindADataBlockWithNdef:(NdefMessage *)ndef fromDevice:(NSString *)device withError:(NSError *)error;
- (void)didReturnResponseApdu:(NSString *)response fromDevice:(NSString *)device withError:(NSError *)error;
- (void)updateConnectedDevicesWithDevice:(FmAudioJackDevice *)device ifIsConnected:(BOOL)connected;
- (void)DeviceManager:(id)reader didSendBatteryLevel:(int)level;
- (void)didChangeCardStatus:(NSNumber *)status fromDevice:(NSString *)device;

@end


@interface FmAudioJackSessionManager : NSObject <AcsAjReaderDelegate, FeitianAjReaderDelegate> {
    
    NSTimer *timer;
    BOOL _isProLicensed;
    
}

@property (nonatomic, strong) AcsAjReader *reader;
@property (nonatomic, strong) FeitianAjReader *ar530;


@property (nonatomic, strong) id<FmAudioJackSessionManagerDelegate> delegate;
@property (nonatomic, assign) BOOL isProLicensed;
@property (nonatomic, strong) NSNumber *scanPeriod; // in milliseconds
@property (nonatomic, assign) NSNumber *scanSound;
@property (nonatomic) DeviceType selectedDeviceType;

- (void)setDevice:(DeviceType)device;
- (void)handleRouteChange:(NSNotification*)notification;
- (id)getAvailableReader;
- (NSNumber *)isReaderConnected;

@end
