//
//  MainViewController.h
//  SDK
//
//  Created by Boris  on 10/14/15.
//  Copyright © 2015 Flomio, Inc. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface MainViewController : UIViewController {
    
    NSArray *tableArray;
}

@property (nonatomic, strong) IBOutlet UITableView *theTable;
@property (nonatomic, strong) IBOutlet UILabel *buildLabel;


@end
