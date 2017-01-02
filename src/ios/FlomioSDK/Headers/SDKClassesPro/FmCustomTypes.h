//
//  FmCustomTypes.h
//  SDK
//
//  Created by Boris  on 3/24/16.
//  Copyright © 2016 Flomio, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, DeviceType) {
    kFlojackBzr,
    kFlojackMsr,
    kFlojackAny,
    kFloBleEmv,
    kFloBlePlus,
    kFloBleMini,
};

typedef NS_ENUM(NSInteger, NDEFState) {
    kTagApplicationSelect,
    kSelectCCFile,
    kReadCCFile,
    kSelectNDEFFile,
    kReadNLEN,
    kReadNDEFFile,
    kComplete,
    kIncomplete
};

typedef NS_ENUM(NSInteger, CardType) {
    kUnknown,
    kMifareUltralight,
    kMifareType4
};

@interface FmCustomTypes : NSObject

@end
