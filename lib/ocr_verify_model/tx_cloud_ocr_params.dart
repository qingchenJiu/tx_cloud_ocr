import 'dart:convert';
TxCloudOcrParams txCloudOcrParamsFromJson(String str) =>
    TxCloudOcrParams.fromJson(json.decode(str));

String txCloudOcrParamsToJson(TxCloudOcrParams data) =>
    json.encode(data.toJson());

class TxCloudOcrParams {
  TxCloudOcrParams({
    this.nonce = '',
    this.userId = '',
    this.keyLicence = '',
    this.appId = '',
    this.order = '',
    this.sign = '',
    this.openApiAppVersion = '1.0.0'
  });

  String nonce;
  String userId;
  String keyLicence;
  String appId;
  String order;
  String sign;
  String openApiAppVersion;

  factory TxCloudOcrParams.fromJson(Map<String, dynamic> json) =>
      TxCloudOcrParams(
        nonce: json["nonce"],
        userId: json["userId"],
        keyLicence: json["keyLicence"],
        appId: json["appId"],
        order: json["order"],
        sign: json["sign"],
        openApiAppVersion: json["openApiAppVersion"],
      );

  Map<String, dynamic> toJson() => {
    "nonce": nonce,
    "userId": userId,
    "keyLicence": keyLicence,
    "appId": appId,
    "order": order,
    "sign": sign,
    "openApiAppVersion": openApiAppVersion,
  };
}