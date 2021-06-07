// apktool_common.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

//整个反编译过程中常用的命令行
// 
//主要步骤
// 解包
// 修改文件、读代码等等
// 反打包
// 签名
// 
//解包
// apktool.bat d appname.apk
// 报错的话，首先检查是否使用的是最新版的工具包
// 一个常见的情况是，现在资源文件里常常出现一些dex文件，与app代码无关，但默认解包时会影响工具判断
// apktool.bat d apkname.apk -f --only-main-classes
// 这样加脚本参数，可以忽略其他的dex，只关注主要的classes
// 
//中间要做什么
// 自己定，注意分寸
// 
//反打包
// apktool.bat b -o newappname.apk dirname
// dirname为第一步解包时生成的那个文件夹
// 此步骤会重新将资源打包为未签名的apk
// 如果失败了，主要有以下的理由
//  修改了smali，语法错误
//  .9资源文件问题
//  资源id冲突
// 等等，可以使用apktool.bat b xxx 2>errlog.txt 输出错误，根据信息进行调整
// 
//签名
// 系统测试签名，使用pem和pk8文件形式
//  java -jar signapk.jar  testkey.x509.pem testkey.pk8　old.apk new.apk
// 日常使用的jks文件签名方式
//  jarsigner -verbose \
        -keystore ${WORKSPACE}/app/key.jks \
        -storepass "storepass" \
        -keypass "keypass" \
        -signedjar ${WORKSPACE}/apppath/appname.apk \
        ${WORKSPACE}/apppath/outputs/appname-signed.apk \
        keyAlias
// 
// 查看签名信息，不是很常用
//  keytool -printcert -file META-INF/CERT.RSA
//  
//这些基本就能封装一个很方便的小工具了
//

int main()
{
    std::cout << "Hello World!\n";
}
