//
//  Reader.h
//  SDK
//
//  Created by Richard Grundy on 11/16/14.
//  Copyright (c) 2014 Flomio, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import <AudioToolbox/AudioToolbox.h>
#import <CommonCrypto/CommonCrypto.h>
#import "Tag.h" 
#import "AudioJack.h"
#import "FmAudioJackDevice.h"
#import "NdefMessage.h"

typedef NS_ENUM(NSInteger, DispatchTimerCommands) {
    startTimer,
    stopTimer,
    initializeTimer
};

@protocol AcsAjReaderDelegate<NSObject>

@required

- (void)didReceiveReaderError:(NSError *)error;
- (void)didFindATagUuid:(NSString *)uuid fromDevice:(NSString *)deviceId withError:(NSError *)error;
- (void)didReturnResponseApdu:(NSString *)apdu fromDevice:(NSString *)device withError:(NSError *)error;
- (void)didGetBatteryLevel:(NSInteger)batteryLevel;
- (void)didChangeCardStatus:(NSNumber *)status fromDevice:(NSString *)device;
- (void)didFindADataBlockWithNdef:(NdefMessage *)ndef fromDevice:(NSString *)device withError:(NSError *)error;

@end

@interface AcsAjReader : NSObject <ACRAudioJackReaderDelegate, AVAudioPlayerDelegate> {
        
    BOOL registry_mode;
    BOOL is_resetting;
    
    BOOL didTagEnterInRange;
    
    BOOL isRequestingUuid;
    
    // NDEF
    BOOL isRequestingDataBlocks;
    NSMutableData *dataBlock;
    int currentPosition;
    NDEFState state;
    CardType cardType;
    
    //semaphores
    dispatch_semaphore_t sem;
    
}

+ (instancetype)sharedInstanceWithParent:(id)parent;

- (id)initWithParent:(id)parent;
- (void)startScan;
- (void)suspendScan;
- (void)reset;
- (void)sleep;
- (void)wake;
- (void)transmitApdu:(NSData *)apdu;
- (void)getDataBlocks;
- (void)playNotification;
- (void)registerNewDevice;
- (void)isDeviceLicensed:(NSString*)deviceIDString;
- (void)resetTimerSource;
- (void)controlTimerSource:(int)tCommand;

@property (nonatomic, strong) id <AcsAjReaderDelegate> delegate;

@property (readonly) Tag *tag;
@property (nonatomic) int batteryLevel;
@property (readonly, strong) NSString *serialNumber;

@property (nonatomic) BOOL routeInProcess;
@property (nonatomic, assign) BOOL isProLicensed;
@property (nonatomic, assign) ReaderStateType operationState; // primitives (NSInteger) must be "assigned" since not objects

@property (nonatomic, strong) dispatch_source_t timerSource;
@property (nonatomic, strong) NSNumber *scanPeriod;
@property (nonatomic, strong) NSNumber *scanSound;
@property (nonatomic, strong) NSNumber *isPolling;              //initialize to YES, set to NO while in bacground
@property (nonatomic, strong) NSNumber *communication;
@property (nonatomic, strong) NSNumber *commSuspended;

@end

