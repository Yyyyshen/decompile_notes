// android_decompile_tools.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

//android反编译工具
//
//环境：
// windows（虽然现在已经用很久mac了，还是习惯用虚拟机在win里做逆向）
// java-1.8（之前一直追新，用到java11，发现很多不兼容反编译工具的情况，最后还是一直使用了比较稳定的JDK8）
// 
//第一步，针对apk，拿到资源文件、dex（看smali/java代码）、so库等
// 
//最常用工具：
// apktool——官网：https://ibotpeaches.github.io/Apktool/
// jadx—— https://github.com/skylot/jadx
// （工具很多，对比用过之后，还是喜欢返璞归真，或者自己封装工具去使用）
// 
//其他学习时用过的工具：
// dex2jar —— https://github.com/pxb1988/dex2jar/releases
// jd-gui（有jadx基本不用这个）—— http://jd.benow.ca/
// 
//别人的封装：
// Android Killer——https://www.52pojie.cn/thread-726176-1-1.html
// Jeb
// 这些相对会比较古老一些，作者也没有更新了，后期有基础之后也会自己去封装，所以不再关注
// 
//第二步，拿到上面东西后，读代码
// 
//需要学习的语法：
// smali —— 至少应该能看得懂，写一些简单的日志语句进去再反打包调试
// https://stackoverflow.com/questions/5656804/whats-the-best-way-to-learn-smali-and-how-when-to-use-dalvik-vm-opcodes
// 
//混淆问题：
// 个人之前的研究中，没有发现很好的解决方案，因为理论上这个东西就是可以做到你完全没办法逆回来
// 基本办法就是耐心点，硬读逻辑
// 
//第三步，如果java代码不能满足需求
// 
//很多关键代码在so库中：
// IDA PRO：https://www.hex-rays.com/products/ida/support/download.shtml
// （比较复杂，自己也没有用的很熟练，后面还需要看看书学习下）
// 
//第0步，现在很多apk都加了壳，没那么容易用上面三步直接去看
// 
//个人感觉最好用的脱壳工具：
// xposed+反射大师
// 其他的网上搜出来了很多，都是没用的，或者局限性很高
// 反射大师是直接在运行内存里dump出dex，感觉十分通用
// 我有一台自己编译的android6.0原生机器，完美脱壳了很多apk
// （一些技术还是在老机器和系统版本中更方便，所以我留了很多台这种用途的设备，nexus+自编译aosp、iphone4s+ios8.0之类的）
//
// 
//还有一些细节，之前写过一个简单的总结 https://yyyyshen.com/2019/01/27/Decomplie/
//不是使用教程，个人感觉自己看官方教程更好 
//


int main()
{
    std::cout << "Hello World!\n";
}
