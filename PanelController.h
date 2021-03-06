//
//  PanelController.h
//  Lyrics in Sight
//
//  Created by Michel Steuwer on 16.04.10.
//

#import <Cocoa/Cocoa.h>
@class AppController;
@class AbstractNotifier;

@interface PanelController : NSWindowController {
	AppController *controller;
	AbstractNotifier *notifier;
	IBOutlet NSTextView *textView;
	
	BOOL inEditMode;
	
	// data to be stored in NSUserDefaults see: dictionary / initWithController:andDictionary
	NSString *type;
	NSString *formula;
	NSRect rect;	
}

@property (readonly) NSString* type;

// initialize and set up methods
- (id)initWithController:(AppController *)aController andType:(NSString *)aType;

// converting the content stored in NSUserDefualts to and from a dictionary
- (id)initWithController:(AppController *)aController andDictionary:(NSDictionary *)aDictionary;
- (NSDictionary *)dictionary;

// panel content management methods
- (void)update:(NSDictionary *)userInfo;

// edit mode management methods
- (void)editModeStarted;
- (void)editModeStopped;
- (void)setEditable:(BOOL)newState;

// NSWindow delegate methods
- (void)windowDidLoad;
- (void)windowWillClose:(NSNotification *)notification;

@end
