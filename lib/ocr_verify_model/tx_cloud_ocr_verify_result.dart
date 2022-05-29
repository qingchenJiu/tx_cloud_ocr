import 'dart:convert';

TxCloudOcrVerifyResult txCloudOcrVerifyResultFromJson(String str) =>
    TxCloudOcrVerifyResult.fromJson(json.decode(str));

String txCloudOcrVerifyResultToJson(TxCloudOcrVerifyResult data) =>
    json.encode(data.toJson());

class TxCloudOcrVerifyResult {
  TxCloudOcrVerifyResult({
    this.result = false,
    this.message = '',
    this.frontFullImageSrc = '',
    this.backFullImageSrc = '',
    this.cardNum = '',
    this.name = '',
  });

  bool result;
  String message;
  String frontFullImageSrc;
  String backFullImageSrc;
  String cardNum;
  String name;

  factory TxCloudOcrVerifyResult.fromJson(Map<String, dynamic> json) =>
      TxCloudOcrVerifyResult(
        result: json["result"],
        message: json["message"],
        frontFullImageSrc: json["frontFullImageSrc"] ?? "",
        backFullImageSrc: json["backFullImageSrc"] ?? "",
        cardNum: json["cardNum"] ?? "",
        name: json["name"] ?? "",
      );

  Map<String, dynamic> toJson() => {
    "result": result,
    "message": message,
    "frontFullImageSrc": frontFullImageSrc,
    "backFullImageSrc": backFullImageSrc,
    "cardNum": cardNum,
    "name": name,
  };
}