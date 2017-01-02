//
//  MainTableViewCell.h
//  SDK
//
//  Created by Boris Polania on 4/21/16.
//  Copyright © 2016 Flomio, Inc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "FmDevice.h"

@interface MainTableViewCell : UITableViewCell

@property (nonatomic, strong) IBOutlet UILabel *textLabel;
@property (nonatomic, strong) IBOutlet UIButton *theButton;
@property (nonatomic, strong) NSNumber *deviceIndex;

@end
