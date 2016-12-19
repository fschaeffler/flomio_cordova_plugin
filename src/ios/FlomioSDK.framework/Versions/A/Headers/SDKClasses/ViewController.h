//
//  ViewController.h
//  SDK
//
//  Created by Richard Grundy on 11/16/14.
//  Copyright (c) 2014 Flomio, Inc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "FmSessionManager.h"

@interface ViewController : UIViewController <FmSessionManagerDelegate,AVAudioPlayerDelegate, UITextFieldDelegate>
{
    
    FmSessionManager *sharedManager;
    
    //FloBLE
    ViewController *viewController;
    UINavigationController *navigationController;
    AVAudioPlayer *_audioPlayer;
    NSMutableArray *connectedDevices;
    NSMutableArray *selectedDevices;
    NSArray *connectionMessages;
    NSMutableArray *logArray;
    NSDictionary *infoDict;
    NSString *appVersion;
    NSString *buildNumber;
}



//UI
@property (nonatomic, strong) IBOutlet UITextView *logView;
@property (nonatomic, strong) IBOutlet UITableView *theTableView;
@property (nonatomic, strong) IBOutlet UILabel *APDUBackgroundLabel;
@property (nonatomic, strong) IBOutlet UILabel *APDULabel;
@property (nonatomic, strong) IBOutlet UILabel *batteryLevelLabel;
@property (nonatomic, strong) IBOutlet UITextField *APDUTextField;
@property (nonatomic, strong) IBOutlet UIButton *APDUButton;
@property (nonatomic, strong) IBOutlet UIImageView *communicationLight;
@property (nonatomic, strong) IBOutlet UIImageView *batteryIndicator;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *logViewTopConstraint;
@property (nonatomic) DeviceType selectedDeviceType;

//FloBLE
@property (strong, nonatomic) ViewController *viewController;

@end

