# tx_cloud_ocr
腾讯云OCR身份证识别Flutter插件

## Getting Started
```
TxCloudOcrVerifyResult? result = await TxCloudOcr.openCloudOcrService(params: TxCloudOcrParams(
   nonce: "",
   userId: "",
   keyLicence: "",
   appId: "",
   order: "",
   sign: ""
));  
debugPrint("识别结果：${result?.result} message：${result?.message}");
```
