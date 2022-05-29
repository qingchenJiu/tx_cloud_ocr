//
//  WBIDCardInfoModel.h
//  WBOCRService
//
//  Created by tank on 2019/8/27.
//

#import <Foundation/Foundation.h>
#import "WBOCRBaseModel.h"
NS_ASSUME_NONNULL_BEGIN


////////////////////////////////////////////////////////////////////////////////
//////////////////                   ///////////////////////////////////////////
////////////////// WBIDCardInfoModel ///////////////////////////////////////////
//////////////////                   ///////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
/*
 * @brief WBIDCardInfoModel类封装了身份证的正反面信息
 *        SDK会将识别结果包装成一个WBIDCardInfoModel实例，通过回调block通知第三方
 
 * @detail 字段含义
 - idcard        公民身份号码
 - name          姓名
 - sex           性别
 - nation        民族
 - address       住址
 - birth         出生
 - authority     签发机关
 - validDate     有效期限
 - frontFullImg  国徽面截图
 - backFullImg   人像面截图
 - orderNo       订单号，和本次业务相关
 - sign          签名信息
 - warning       识别结果警告信息
 - multiWarning  多重告警码，人像面是frontMultiWarning，国徽面对应backMultiWarning
 - clarity       图片清晰度，人像面是frontClarity，国徽面对应backClarity
 */

@interface WBIDCardInfoModel : WBOCRBaseModel

/// 身份证人像面信息
@property (nonatomic, copy) NSString *idcard;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *sex;
@property (nonatomic, copy) NSString *nation;
@property (nonatomic, copy) NSString *address;
@property (nonatomic, copy) NSString *birth;

/// 身份证国徽面信息
@property (nonatomic, copy) NSString *authority;
@property (nonatomic, copy) NSString *validDate;

/// 本次业务相关信息
@property (nonatomic, copy) NSString *orderNo;
@property (nonatomic, copy) NSString *sign;

/// 人像面/国徽面识别结果截图信息
@property (nonatomic, strong) UIImage *frontFullImg;
@property (nonatomic, strong) UIImage *backFullImg;

@property (nonatomic, copy) NSString *frontCode;
@property (nonatomic, copy) NSString *backCode;

/// warning，人像面/国徽面识别结果对应的警告信息
@property (nonatomic, copy) NSString *frontWarning;
@property (nonatomic, copy) NSString *frontMultiWarning;

@property (nonatomic, copy) NSString *backWarning;
@property (nonatomic, copy) NSString *backMultiWarning;

@property (nonatomic, copy) NSString *frontClarity;
@property (nonatomic, copy) NSString *backClarity;

/// 人像面/国徽面识别视频 URL
@property (nonatomic, copy) NSURL *frontVideoURL;
@property (nonatomic, copy) NSURL *backVideoURL;


/// 人像面/国徽面切边图 base64 编码字符串
@property (nonatomic, copy) NSString *frontCrop;
@property (nonatomic, copy) NSString *backCrop;

@end

NS_ASSUME_NONNULL_END
