######################云 ocr 混淆规则 ocr-BEGIN###########################
-keepattributes InnerClasses
-keep public class com.webank.mbank.ocr.WbCloudOcrSDK{
    public <methods>;
    public static final *;
}
-keep public class com.webank.mbank.ocr.WbCloudOcrSDK$*{
    *;
}

-keep public class com.webank.mbank.ocr.tools.ErrorCode{
    *;
}

-keep public class com.webank.mbank.ocr.net.*$*{
    *;
}
-keep public class com.webank.mbank.ocr.net.*{
    *;
}
#######################云 ocr 混淆规则 ocr-END#############################

#######################webank normal混淆规则-BEGIN#############################
#不混淆内部类
-keepattributes InnerClasses
-keepattributes *Annotation*
-keepattributes Signature

-keep, allowobfuscation @interface com.webank.normal.xview.Inflater
-keep, allowobfuscation @interface com.webank.normal.xview.Find
-keep, allowobfuscation @interface com.webank.normal.xview.BindClick

-keep @com.webank.normal.xview.Inflater class *
-keepclassmembers class * {
    @com.webank.normal.Find *;
    @com.webank.normal.BindClick *;
}

-keep public class com.webank.normal.net.*$*{
    *;
}
-keep public class com.webank.normal.net.*{
    *;
}
-keep public class com.webank.normal.thread.*{
   *;
}
-keep public class com.webank.normal.thread.*$*{
   *;
}
-keep public class com.webank.normal.tools.WLogger{
    *;
}

#webank normal 包含的第三方库 bugly
-keep class com.tencent.bugly.webank.**{
    *;
}

#wehttp 混淆规则
-dontwarn com.webank.mbank.okio.**

-keep class com.webank.mbank.wehttp.**{
    public <methods>;
}
-keep interface com.webank.mbank.wehttp.**{
    public <methods>;
}
-keep public class com.webank.mbank.wehttp.WeLog$Level{
    *;
}
-keep class com.webank.mbank.wejson.WeJson{
    public <methods>;
}


#######################webank normal混淆规则-END#############################