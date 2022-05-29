import 'package:flutter/material.dart';
import 'dart:async';

import 'package:flutter/services.dart';
import 'package:tx_cloud_ocr/ocr_verify_model/tx_cloud_ocr_params.dart';
import 'package:tx_cloud_ocr/ocr_verify_model/tx_cloud_ocr_verify_result.dart';
import 'package:tx_cloud_ocr/tx_cloud_ocr.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatefulWidget {
  const MyApp({Key? key}) : super(key: key);

  @override
  State<MyApp> createState() => _MyAppState();
}

class _MyAppState extends State<MyApp> {

  @override
  void initState() {
    super.initState();
    initPlatformState();
  }

  // Platform messages are asynchronous, so we initialize in an async method.
  Future<void> initPlatformState() async {
    TxCloudOcrVerifyResult? result = await TxCloudOcr.openCloudOcrService(params: TxCloudOcrParams(
        nonce: "",
        userId: "",
        keyLicence: "",
        appId: "",
        order: "",
        sign: ""
    ));
    debugPrint("识别结果：${result?.result} message：${result?.message}");
  }

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        appBar: AppBar(
          title: const Text('Plugin example app'),
        ),
        body: const Center(
          child: Text('身份证识别'),
        ),
      ),
    );
  }
}
