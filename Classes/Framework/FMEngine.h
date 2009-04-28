//
//  FMEngine.h
//  LastFMAPI
//
//  Created by Nicolas Haunold on 4/26/09.
//  Copyright 2009 Tapolicious Software. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NHDebug.h"
#import "NSString+FMEngine.h"

#define _LASTFM_API_KEY_ @"YOUR_API_KEY"
#define _LASTFM_SECRETK_ @"YOUR_SECRET_KEY"
#define _LASTFM_BASEURL_ @"http://ws.audioscrobbler.com/2.0/"

// Uncomment to use XML
#define _USE_JSON_ 1

#define POST_TYPE	@"POST"
#define GET_TYPE	@"GET"

@class FMEngine;

@protocol FMEngineDelegate <NSObject>
@required
- (void)engine:(FMEngine *)engine didFailWithError:(NSError *)error;
@end

@interface FMEngine : NSObject {
	id <FMEngineDelegate> _delegate;
	NSMutableData *receivedData;
	NSMutableDictionary *connections;

}

@property (nonatomic, retain) id <FMEngineDelegate> delegate;

- (id)initWithDelegate:(id<FMEngineDelegate>)theDelegate;

- (NSString *)generateAuthTokenFromUsername:(NSString *)username password:(NSString *)password;
- (NSString *)generateSignatureFromDictionary:(NSDictionary *)dict;
- (NSString *)generatePOSTBodyFromDictionary:(NSDictionary *)dict;
- (NSURL *)generateURLFromDictionary:(NSDictionary *)dict;

- (void)performMethod:(NSString *)method withTarget:(id)target withParameters:(NSDictionary *)params andAction:(SEL)callback useSignature:(BOOL)useSig httpMethod:(NSString *)httpMethod;
- (NSData *)dataForMethod:(NSString *)method withParameters:(NSDictionary *)params useSignature:(BOOL)useSig httpMethod:(NSString *)httpMethod;


@end