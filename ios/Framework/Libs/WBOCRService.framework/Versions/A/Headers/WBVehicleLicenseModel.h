//
//  WBVehicleLicenseModel.h
//  FBRetainCycleDetector
//
//  Created by tank on 2019/8/27.
//

#import <Foundation/Foundation.h>
#import "WBOCRBaseModel.h"
NS_ASSUME_NONNULL_BEGIN

@interface WBVehicleLicenseModel : WBOCRBaseModel

/// 正本内容
/// - plateNo                                 车牌号码
/// - vehicleType                          车辆类型
/// - owner                                    所有人
/// - address                                地址
/// - useCharacter                       使用性质
/// - model                                   品牌型号
/// - vin                                        识别代码
/// - engineNo                            发动机号
/// - registeDate                         注册日期
/// - issueDate                           发证日期
/// - licenseStamp                     红章
///
/// - authorizedCarryCapacity    核定载人数
/// - authorizedLoadQuality        核定载质量
/// - fileNumber                            档案编号
/// - total                                      总质量
/// - inspectionRecord               检验记录
/// - externalDimensions           外廓尺寸
/// - totalQuasiTractionMass    准牵引总质量
/// - curbWeright                        整备质量
/// - licensePlateNum                车牌号码
///
@property (nonatomic, strong) UIImage  *homePageFullImage;
@property (nonatomic, copy) NSString *plateNo;
@property (nonatomic, copy) NSString *vehicleType;
@property (nonatomic, copy) NSString *owner;
@property (nonatomic, copy) NSString *address;
@property (nonatomic, copy) NSString *useCharacter;
@property (nonatomic, copy) NSString *model;
@property (nonatomic, copy) NSString *vin;
@property (nonatomic, copy) NSString *engineNo;
@property (nonatomic, copy) NSString *registeDate;
@property (nonatomic, copy) NSString *issueDate;
@property (nonatomic, copy) NSString *licenseStamp;

@property (nonatomic, strong) UIImage  *secondaryPageFullImage;
@property (nonatomic, copy) NSString *authorizedCarryCapacity;
@property (nonatomic, copy) NSString *authorizedLoadQuality;
@property (nonatomic, copy) NSString *fileNumber;
@property (nonatomic, copy) NSString *total;
@property (nonatomic, copy) NSString *inspectionRecord;
@property (nonatomic, copy) NSString *externalDimensions;
@property (nonatomic, copy) NSString *totalQuasiTractionMass;
@property (nonatomic, copy) NSString *curbWeright;
@property (nonatomic, copy) NSString *licensePlateNum;
@property (nonatomic, copy) NSString *sign;

@end

NS_ASSUME_NONNULL_END
