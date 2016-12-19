//
//  FmNdefManager.h
//  SDK
//
//  Created by Boris Polania on 4/26/16.
//  Copyright © 2016 Flomio, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FmCustomTypes.h"
#import "NdefMessage.h"

@interface FmNdefManager : NSObject

+ (NSString *)selectNDEFTagApplication;
+ (NSString *)selectCCFile;
+ (NSString *)readCCFile;
+ (NSString *)getNDEFFileId:(NSString *)response;
+ (NSString *)selectNDEFFile:(NSString *)fileId;
+ (NSString *)readNLEN;
+ (NSString *)readNDEFFile:(NSString *)nlen;
+ (NSString *)getUriIndentifierCode:(NSString *)hex;
//+ (NSString *)readBinaryForMifareUL;
+ (NdefMessage *)handleFinalNdef:(NSData *)apdu;

@end
