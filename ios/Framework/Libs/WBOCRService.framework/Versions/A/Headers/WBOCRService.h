//
//  WBOCRService.h
//  Pods
//
//  1. `WBOCRService` 是SDK的入口类，是一个单例类，是SDK的入口
//  2. SDK的具体调用请参考接入文档和SDK附带的demo
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "WBOCRConfig.h"

#import "WBIDCardInfoModel.h"
#import "WBBankCardInfoModel.h"
#import "WBDriverLicenseModel.h"
#import "WBVehicleLicenseModel.h"
#import <AVFoundation/AVFoundation.h>

/**
 * @brief WBOCRService类提供了SDK的入口,
 *        通过调用startService方法可以启动SDK,
 *        可以从几个不同的回调中获取相应的结果回调.
 */
@interface WBOCRService : NSObject

/**
 * @brief SDK启动成功回调，APP已经进入OCR识别界面
 */
typedef void(^WBOCRServiceStartSucceedBlock)(void);

/**
 * @brief SDK识别完成回调，SDK即将退出，回调中包含有包含有本次识别信息
 *
 * @param resultModel 识别到的OCR信息
 * @param extension   扩展字段，目前版本没有使用，为空
 */
typedef void(^WBOCRServiceRecognizeSuccessBlock)(id _Nonnull resultModel,id _Nullable extension);

/**
 * @brief SDK异常退出后回调，SDK即将退出，回调中包含有异常原因
 *
 * @param error     导致退出的Error信息，里面包含错误码和错误描述，具体错误码的对照请参考在线接入文档
 * @param extension 扩展字段，目前版本没有使用，为空
 */
typedef void(^WBOCRServiceFailedBlock) (NSError * _Nonnull error,id _Nullable extension);

/**
 * @brief 预检测结果回掉
 * @param clear       当前帧的清晰度, YES 表示清晰,NO 表示模糊
 * @param border    当前帧中是否检测出有效的边框, YES 表示检测出有效的边框,NO 表示没有有效的边框
 * @param distance   当前帧中是否检测出证件距离过远,  YES 表示证件距离过远,可以提示用户将证件靠近摄像头; NO 可以忽略不处理
 */
typedef void(^WBOCRServiceProcessBlock)(BOOL clear,BOOL border, BOOL distance);

/**
 * @brief 识别 warning 信息回调, 在使用 samplebuffer 接口时,会收到这个回调
 * @param code warning code 信息
 * @param msg   warning message 信息
 */
typedef void(^WBOCRServiceWarningBlock)(NSString * _Nonnull code,NSString * _Nonnull msg);

/**
 * @brief 识别 warning 信息回调, 在使用 samplebuffer 接口时,会收到这个回调
 * @param code warning code 信息
 * @param msg   warning message 信息
 */
typedef void(^WBOCRServiceErrorBlock)(NSString * _Nonnull code,NSString * _Nonnull msg);

/**
 * @brief WBOCRService 单例方法，通过调用该方法实例化 WBOCRService对象
 *
 * @return WBOCRService对象
 */
+ (nonnull instancetype) sharedService;

/**
 * @brief sdk版本号，readonly参数
 */
@property (nonatomic,readonly,nonnull) NSString *sdkVersion;

@property (nonatomic, readonly, copy, nonnull) WBOCRServiceRecognizeSuccessBlock successBlock;
@property (nonatomic, readonly, copy, nonnull) WBOCRServiceFailedBlock   failedBlock;
@property (nonatomic, readonly, copy, nonnull) WBOCRServiceProcessBlock  processBlock;

#pragma mark - SDK 标准接入入口,需要传入 license
/**
 * @brief SDK 入口 -- 标准接入入口,需要传入 license
 
 * @param config           配置参数
 * @param version         openAPI接口版本号,由腾讯服务统一分配
 * @param appId             appId，由腾讯服务分配的
 * @param license         license，由腾讯服务分配的
 * @param nonce             每次请求需要的一次性nonce，一次有效
 * @param userId            每个用户唯一的标识
 * @param sign              签名信息，有接入方后台提供，一次有效
 * @param orderNo           订单号，长度不能超过32位的字符串
 * @param startSucceed      SDK启动成功回调
 * @param recognizeSucceed  识别成功回调，即将退出SDK
 * @param failed            SDK发生异常退出后回调，即将退出SDK
 *
 */
- (void)startOCRServiceWithConfig:(nullable WBOCRConfig *)config
                          version:(nonnull NSString *)version
                            appId:(nonnull NSString *)appId
                          license:(nonnull NSString *)license
                            nonce:(nonnull NSString *)nonce
                           userId:(nonnull NSString *)userId
                             sign:(nonnull NSString *)sign
                          orderNo:(nonnull NSString *)orderNo
                     startSucceed:(nonnull WBOCRServiceStartSucceedBlock)startSucceed
                 recognizeSucceed:(nonnull WBOCRServiceRecognizeSuccessBlock)recognizeSucceed
                           failed:(nonnull WBOCRServiceFailedBlock)failed;


#pragma mark - SDK 非标接入入口,流识别接口
/**
 * @brief 调起SDK入口方法 -- 非标接口, SDK 初始化
 
 * @param version           openAPI接口版本号,由腾讯服务统一分配
 * @param appId             appId，由腾讯服务分配的
 * @param license           license，由腾讯服务分配的
 * @param nonce             每次请求需要的一次性nonce，一次有效
 * @param userId            每个用户唯一的标识
 * @param sign              签名信息，有接入方后台提供，一次有效
 * @param orderNo           订单号，长度不能超过32位的字符串
 * @param isVertical        这个参数很重要!!!! 卡片识别方向, 取 YES 的时候,是横屏识别(卡片长边和手机短边平行); 取 NO 的时候,是竖屏识别(卡片长边和手机长边平行)
 * @param roi               图片的 ROI 区域
 * @param startSucceed      SDK认证成功回调, 回调是异步的,只有收到 startSucceed 回调之后,后面的识别功能才能使用!
 *
 */
-(void) setupOCRServiceWithLicense:(nonnull NSString *)license
                              sign:(nonnull NSString *)sign
                             appId:(nonnull NSString *)appId
                           orderNo:(nonnull NSString *)orderNo
                            userId:(nonnull NSString *)userId
                             nonce:(nonnull NSString *)nonce
                           version:(nonnull NSString *)version
                     verticalScreen:(BOOL) isVertical
                               ROI:(CGRect)roi
                      startSucceed:(nonnull WBOCRServiceStartSucceedBlock)startSucceed
                            failed:(nonnull WBOCRServiceFailedBlock)failed;


/**
 @brief 调起SDK入口方法 -- 非标接口, 流识别
 
 * @param sampleBuffer        从 camera 获取到的视频流
 * @param type            卡片类型,支持的卡片类型情况详见 WBOCRCardType 的定义
 * @param processCallback     识别中信息反馈, 接入方可以通过这些信息给用户进行识别提示,收到此回调,可以继续识别
 * @param warningCallback     识别中信息反馈,接入方可以通过这些信息给用户进行识别提示,收到此回调,可以继续识别
 * @param succeedCallback     识别成功回调, 识别成功,收到此回调,识别终止
 * @param errorCallback       识别异常回调, 识别发生异常,收到此回调,识别终止
 *
 */
-(void) startRecognizeSampleBuffer:(CMSampleBufferRef _Nonnull )sampleBuffer
                          cardType:(WBOCRCardType)type
                  recognizeProcess:(WBOCRServiceProcessBlock _Nullable ) processCallback
                  recognizeWarning:(WBOCRServiceWarningBlock _Nullable ) warningCallback
                  recognizeSucceed:(nonnull WBOCRServiceRecognizeSuccessBlock)succeedCallback
                            failed:(nonnull WBOCRServiceErrorBlock)errorCallback;

@end

