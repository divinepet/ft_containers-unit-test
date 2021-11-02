/*
	BASS recording example
	Copyright (c) 2002-2021 Un4seen Developments Ltd.
*/

#import <Cocoa/Cocoa.h>

@interface ViewController : NSViewController
@property (weak) IBOutlet NSPopUpButton *deviceSelector;
@property (weak) IBOutlet NSPopUpButton *inputSelector;
@property (weak) IBOutlet NSSlider *volumeSlider;
@property (weak) IBOutlet NSPopUpButton *formatSelector;
@property (weak) IBOutlet NSButton *recordButton;
@property (weak) IBOutlet NSButton *playButton;
@property (weak) IBOutlet NSButton *saveButton;
@property (weak) IBOutlet NSTextField *positionText;
@property (weak) IBOutlet NSLevelIndicator *levelIndicator;

@end

