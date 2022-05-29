#import "TxCloudOcrPlugin.h"
#import <WBOCRService/WBOCRService.h>

@implementation TxCloudOcrPlugin
FlutterResult resultFunc;
+ (void)registerWithRegistrar:(NSObject<FlutterPluginRegistrar>*)registrar {
  FlutterMethodChannel* channel = [FlutterMethodChannel
      methodChannelWithName:@"tx_cloud_ocr"
            binaryMessenger:[registrar messenger]];
  TxCloudOcrPlugin* instance = [[TxCloudOcrPlugin alloc] init];
  [registrar addMethodCallDelegate:instance channel:channel];
}

- (void)handleMethodCall:(FlutterMethodCall*)call result:(FlutterResult)result {
    resultFunc = result;
  if ([@"openCloudOcrService" isEqualToString:call.method]) {
//      NSString *ver = [WBOCRService sharedService].sdkVersion;
//    result([@"iOS " stringByAppendingString:ver]);
      
      [self openCloudOcrService:call.arguments];
      
  } else {
    result(FlutterMethodNotImplemented);
  }
}

-(void)openCloudOcrService:(NSDictionary<NSString*, NSString*>*)_inputData {
    WBOCRConfig *config = [WBOCRConfig sharedConfig];
    // 身份证两面识别
    config.SDKType = WBOCRSDKTypeIDCardNormal;
    // 身份证识别返回切边图.
    config.retCrop = YES;
    
    [[WBOCRService sharedService] startOCRServiceWithConfig:config version:_inputData[@"openApiAppVersion"] appId:_inputData[@"appId"] license:_inputData[@"keyLicence"] nonce:_inputData[@"nonce"] userId:_inputData[@"userId"] sign:_inputData[@"sign"] orderNo:_inputData[@"orderNo"] startSucceed:^{
        /** SDK服务拉起成功回调 */
        
    } recognizeSucceed:^(id  _Nonnull resultModel, id  _Nullable extension) {
        /** SDK本次识别成功回调 */
        WBIDCardInfoModel *resultInfoModel = (WBIDCardInfoModel *)resultModel;
        
        NSDictionary *result;
        result = @{@"result": @YES, @"message": @"成功", @"frontFullImageSrc": resultInfoModel.frontFullImg, @"backFullImageSrc": resultInfoModel.backFullImg, @"cardNum": resultInfoModel.idcard, @"name": resultInfoModel.name};
        
        resultFunc([self convertToJsonData:result]);
    } failed:^(NSError * _Nonnull error, id  _Nullable extension) {
        /** SDK异常回调 */
        NSString *message = [NSString stringWithFormat:@"%@", error.description];
        NSDictionary *result = @{@"result": @NO, @"message": message};
        resultFunc([self convertToJsonData:result]);
    }];
}

- (NSString *)convertToJsonData:(NSDictionary *)dict
{
    NSError *error;
    NSData *jsonData = [NSJSONSerialization dataWithJSONObject:dict options:NSJSONWritingPrettyPrinted error:&error];
    NSString *jsonString;
    if (!jsonData) {
        NSLog(@"%@",error);
    } else {
        jsonString = [[NSString alloc]initWithData:jsonData encoding:NSUTF8StringEncoding];
    }
    NSMutableString *mutStr = [NSMutableString stringWithString:jsonString];
    NSRange range = {0,jsonString.length};
    //去掉字符串中的空格
    [mutStr replaceOccurrencesOfString:@" " withString:@"" options:NSLiteralSearch range:range];
    NSRange range2 = {0,mutStr.length};
    //去掉字符串中的换行符
    [mutStr replaceOccurrencesOfString:@"\n" withString:@"" options:NSLiteralSearch range:range2];
    return mutStr;
}

@end
