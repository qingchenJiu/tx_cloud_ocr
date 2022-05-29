package com.example.tx_cloud_ocr;

import android.app.Activity;
import android.content.Context;
import android.os.Bundle;

import androidx.annotation.NonNull;

import io.flutter.embedding.engine.plugins.FlutterPlugin;
import io.flutter.embedding.engine.plugins.activity.ActivityAware;
import io.flutter.embedding.engine.plugins.activity.ActivityPluginBinding;
import io.flutter.plugin.common.MethodCall;
import io.flutter.plugin.common.MethodChannel;
import io.flutter.plugin.common.MethodChannel.MethodCallHandler;
import io.flutter.plugin.common.MethodChannel.Result;

import com.tencent.cloud.huiyansdkocr.WbCloudOcrSDK;
import com.tencent.cloud.huiyansdkocr.tools.WbCloudOcrConfig;

import org.json.JSONException;
import org.json.JSONObject;

import java.util.HashMap;

/** TxCloudOcrPlugin */
public class TxCloudOcrPlugin implements FlutterPlugin, MethodCallHandler, ActivityAware {
  /// The MethodChannel that will the communication between Flutter and native Android
  ///
  /// This local reference serves to register the plugin with the Flutter Engine and unregister it
  /// when the Flutter Engine is detached from the Activity
  private MethodChannel channel;
  private Activity mContext;

  @Override
  public void onAttachedToEngine(@NonNull FlutterPluginBinding flutterPluginBinding) {
    channel = new MethodChannel(flutterPluginBinding.getBinaryMessenger(), "tx_cloud_ocr");
    channel.setMethodCallHandler(this);
  }

  @Override
  public void onMethodCall(@NonNull MethodCall call, @NonNull Result result) {
    if (call.method.equals("openCloudOcrService")) {

      Bundle data = new Bundle();
//      WbCloudOcrSDK.InputData inputData = new WbCloudOcrSDK.InputData(
//              orderNo,
//              appId,
//              openApiAppVersion,
//              nonce,
//              userId,
//              sign);
      HashMap<String, String> params = call.arguments();
      WbCloudOcrSDK.InputData inputData = new WbCloudOcrSDK.InputData(
              params.get("orderNo"),
              params.get("appId"),
              params.get("openApiAppVersion"),
              params.get("nonce"),
              params.get("userId"),
              params.get("sign"));
      data.putSerializable(WbCloudOcrSDK.INPUT_DATA, inputData);
      data.putString(WbCloudOcrSDK.TITLE_BAR_COLOR, "#ffffff");
      data.putString(WbCloudOcrSDK.TITLE_BAR_CONTENT, "");
      data.putString(WbCloudOcrSDK.WATER_MASK_TEXT, "仅供本次业务使用");
      data.putLong(WbCloudOcrSDK.SCAN_TIME, 20000);

      //这项配置可选，只适用标准模式：传“2”则在标准模式下会对正反面识别进行强校验，即正反面都识别了“完成”按钮才能点击；不传或传其他则不校验
      data.putString(WbCloudOcrSDK.OCR_FLAG, "1");
      WbCloudOcrConfig.getInstance().setSitEnv(false);
      WbCloudOcrConfig.getInstance().setEnableLog(true);
      WbCloudOcrConfig.getInstance().setCheckWarnings(false);
      //配置sdk是否返回切边图
      WbCloudOcrConfig.getInstance().setRetCrop(true);

      ///类型
      WbCloudOcrSDK.WBOCRTYPEMODE type = WbCloudOcrSDK.WBOCRTYPEMODE.WBOCRSDKTypeVehicleLicenseNormal;

      //启动SDK，进入SDK界面
      WbCloudOcrSDK.getInstance().init(mContext, data, new WbCloudOcrSDK.OcrLoginListener() {
        @Override
        public void onLoginSuccess() {
          //登录成功,拉起SDk页面
          //证件结果回调接口
          WbCloudOcrSDK.getInstance().startActivityForOcr(mContext, new WbCloudOcrSDK.IDCardScanResultListener() {
            @Override
            public void onFinish(String resultCode, String resultMsg) {
              // resultCode为0，则刷脸成功；否则刷脸失败
              if ("0".equals(resultCode)) {
                // 登录成功  第三方应用对扫描的结果进行操作
                JSONObject data = new JSONObject();
                try {
                  data.put("result", true);
                  data.put("message", "成功");
                  data.put("frontFullImageSrc", WbCloudOcrSDK.getInstance().getResultReturn().frontFullImageSrc);
                  data.put("backFullImageSrc", WbCloudOcrSDK.getInstance().getResultReturn().backFullImageSrc);
                  data.put("cardNum", WbCloudOcrSDK.getInstance().getResultReturn().cardNum);
                  data.put("name", WbCloudOcrSDK.getInstance().getResultReturn().name);
                } catch (JSONException e) {
                  e.printStackTrace();
                }
                result.success(data.toString());
              } else {
                result.notImplemented();
              }

            }
          }, type);
        }

        @Override
        public void onLoginFailed(String errorCode, String errorMsg) {
          JSONObject data = new JSONObject();
          try {
            data.put("result", false);
            data.put("message", errorMsg);
          } catch (JSONException e) {
            e.printStackTrace();
          }
          result.success(data.toString());

        }
      });
    } else {
      result.notImplemented();
    }
  }

  @Override
  public void onDetachedFromEngine(@NonNull FlutterPluginBinding binding) {
    channel.setMethodCallHandler(null);
  }

  @Override
  public void onAttachedToActivity(@NonNull ActivityPluginBinding binding) {
    mContext = binding.getActivity();
  }

  @Override
  public void onDetachedFromActivityForConfigChanges() {
    this.onDetachedFromActivity();
  }

  @Override
  public void onReattachedToActivityForConfigChanges(@NonNull ActivityPluginBinding binding) {
    this.onAttachedToActivity(binding);
  }

  @Override
  public void onDetachedFromActivity() {
    mContext = null;
  }
}
