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

//
//cocosjs
// jsc逆向
// 前阵子又看了下cocos游戏的逆向相关，其中对于js语言的包，搜索了下so文件下一些关键字，发现并不含加密，只是将js编译为类似于字节码的jsc，找到了一个脚本来反编译。
// 是php的脚本，可以自己配合python脚本，批量转换，记录在这：
//  https://github.com/irelance/jsc-decompile-mozjs-34
//


/*

frida调试
应用列表
frida-ps -Uai

-f  spawn模式启动App
frida -U -f com.example.app -l test.js --no-pause
先启动App，再attach上去
frida -U -l test.js com.example.app
直接指定进程号
frida -U -l test.js -p pid
查看被attach的情况
cat /proc/{pid}/status | grep TracerPid

anti反调试，先执行
frida -U -f com.example.app --no-pause
提示Process terminated之后，再执行
frida -U com.example.app -l test.js

*/

/*	test.py

import frida, sys

def on_message(message, data):
	if message['type'] == 'send':
		print("[*] {0}".format(message['payload']))
	else:
		print(message)

jscode = """
Java.perform(function () {
  // Function to hook is defined here
  var MainActivity = Java.use('com.example.seccon2015.rock_paper_scissors.MainActivity');

  // Whenever button is clicked
  var onClick = MainActivity.onClick;
  onClick.implementation = function (v) {
	// Show a message to know that the function got called
	send('onClick');

	// Call the original onClick handler
	onClick.call(this, v);

	// Set our values after running the original onClick handler
	this.m.value = 0;
	this.n.value = 1;
	this.cnt.value = 99;

	// Log to the console that it's done, and we should have the flag!
	console.log('Done:' + JSON.stringify(this.cnt));
  };
});
"""

process = frida.get_usb_device().attach('rock_paper_scissors')
script = process.create_script(jscode)
script.on('message', on_message)
print('[*] Running CTF')
script.load()
sys.stdin.read()

*/


int main()
{
    std::cout << "Hello World!\n";
}
