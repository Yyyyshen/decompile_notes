// iOS_decompile_tools.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

//iOS逆向工具
// 
//环境：
// macos
// xcode
// 
//第一步，拿到ipa包
// 
//能直接下载到最好，官方的现在似乎已经拿不到了
//或者只能砸壳的时候去动态拿了
// 
//第二步，砸壳
// 
//主要有官方壳和第三方壳
// 
//工具大致有几种
// Clutch
// dumpdecrypted
// frida-ios-dump
// CrackerXI
// 总结很详细的文章很多，这里贴一个别人的：https://www.jianshu.com/p/1991854c65af
// 
//高版本的ios系统完美越狱似乎比较难，当时用了爱思助手的CheckRa1n，但重启后需要重新越狱，不是很方便，并且所有砸壳工具都没成功
// 
//最后，翻出陈年的4和5，在一些装了8和9版本系统的设备里做了完美越狱，然后用Clutch和dumpdecrypted顺利砸壳
// 
//第三步，dump头文件
// 
//拿到砸壳的二进制文件之后，主要是先看一下头文件的函数声明，大概确定后续要逆向的方向
// 
//需要使用工具class-dump
// http://stevenygard.com/projects/class-dump/
// 基本命令 class-dump filename -H -o outputdir
// 其中，官方的库没有对swift+oc混编的应用做适配，需要使用第三方MonkeyDev的完善版本
// https://github.com/AloneMonkey/MonkeyDev/blob/master/bin/class-dump
// 
//第四步，运行、调试、注入等
// 
//拿到砸好壳的ipa包之后，需要在xcode里跑起来
//
//工具就是上面提到的MonkeyDev
// https://github.com/AloneMonkey/MonkeyDev
// 使用说明、xm注入语法等在官方wiki上都有比较清楚的说明
// 项目已经三四年没有更新了，使用上是没问题的，但跟新版本macos有些冲突，官方也没有说明，之前自己研究了下，问题不大
// 安装脚本中有个文件路径在macos10.15以上的xcode中路径不同，当时我正好有一台停留在10.14的本子，就直接把对应路径按报错放到新版本中，发现就直接解决了
// 另外，国内安装的时候经常被墙，有时甚至挂了代理也一直连不通，可以手动安装
// 这些内容都记录在我另一个库里
//  https://github.com/Yyyyshen/MonkeyDevInMacOS15
//

int main()
{
    std::cout << "Hello World!\n";
}
