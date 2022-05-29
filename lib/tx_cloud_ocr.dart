
import 'dart:async';
import 'dart:convert';
import 'package:flutter/services.dart';
import 'package:tx_cloud_ocr/ocr_verify_model/tx_cloud_ocr_params.dart';
import 'package:tx_cloud_ocr/ocr_verify_model/tx_cloud_ocr_verify_result.dart';

class TxCloudOcr {
  static const MethodChannel _channel = MethodChannel('tx_cloud_ocr');

  static Future<TxCloudOcrVerifyResult?> openCloudOcrService({
    required TxCloudOcrParams params,
  }) async {
    final res = await _channel.invokeMethod('openCloudOcrService', params.toJson());
    return TxCloudOcrVerifyResult.fromJson(json.decode(res));
  }
}
