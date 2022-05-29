//
//  WBBankCardInfoModel.h
//  WBOCRService
//
//  Created by tank on 2019/8/27.
//

#import <Foundation/Foundation.h>
#import "WBOCRBaseModel.h"
NS_ASSUME_NONNULL_BEGIN

///////////////////////////////////////////////////////////////////////////////
//////////////////                     ////////////////////////////////////////
////////////////// WBBankCardInfoModel ////////////////////////////////////////
//////////////////                     ////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

/**
 * @brief 银行卡信息
 * @detail 字段含义
 - bankcardFullImg    银行卡识别的照片
 - bankcardNoPhoto  银行卡卡号切图
 - bankcardNo         银行卡号
 - bankcardValidDate  银行卡有效期(年／月，没有为空)
 - warningCode        警告码
 - warningMsg         警告码描述
 - multiWarningCode   多重警告码
 - multiWarningMsg    多重警告码描述
 - clarity            图片清晰度
 */

@interface WBBankCardInfoModel :WBOCRBaseModel


@property (nonatomic, strong)  UIImage  *bankcardFullImg;
@property (nonatomic, strong)  UIImage  *bankcardNoPhoto;

@property (nonatomic, copy) NSString *bankcardNo;
@property (nonatomic, copy) NSString *bankcardValidDate;
@property (nonatomic, copy) NSString *warningCode;
@property (nonatomic, copy) NSString *warningMsg;

@property (nonatomic, copy) NSString *multiWarningCode;
@property (nonatomic, copy) NSString *multiWarningMsg;

@property (nonatomic, copy) NSString *clarity;
@property (nonatomic, copy) NSString *sign;

@end

NS_ASSUME_NONNULL_END
