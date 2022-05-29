//
//  WBOCRBaseModel.h
//
//  Created by tank on 2020/8/11.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface WBOCRBaseModel : NSObject
- (NSDictionary *)dictionaryValue;

- (WBOCRBaseModel *)toModel:(NSDictionary *)dic;
@end

NS_ASSUME_NONNULL_END
