//
//  DeviceInfoViewController.h
//  SDK
//
//  Created by Boris  on 3/15/16.
//  Copyright © 2016 Flomio, Inc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "FmDevice.h"

@interface DeviceInfoViewController : UIViewController {
    NSString *urlString;
}

@property (nonatomic) FmDevice *device;
@property (nonatomic, strong) NSNumber *cardStatus;
@property (nonatomic, strong) IBOutlet UILabel *serialNumbereLabel;
@property (nonatomic, strong) IBOutlet UITextView *logView;
@property (nonatomic, strong) IBOutlet UIWebView *theWebView;
@property (nonatomic, strong) IBOutlet UIButton *closeButton;

@end
