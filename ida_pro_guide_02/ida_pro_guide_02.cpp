// ida_pro_guide_02.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

//
//IDA基本用法
//


//IDA入门
// 
//基本使用日常中已经有所了解
// 
//控制台两个基本点
// 可以开始浏览了（但不能改）
// You may start to explore the input file right now.
// 初始化分析完成
// The initial autoanalysis has been finished.
// 


//IDA数据显示窗口
// 
//切换基于图形的流程视图和面向文本的列表试图
// 在IDA View-A界面 空格键
// 
//流程图形视图
// 条件控制流中：执行分支的边默认为绿色，不执行分支默认为红色
// 普通流程中，使用蓝色箭头
// 
//多窗口
// views-》open subviews-》disassembly
// 
//设置行前缀
// options-》general-》disassembly-》line prefix
// 启用后图形试图每条语句前也会有偏移地址信息
// 
//函数窗口
// 记录了函数名，起始偏移地址、函数长度、一些函数标记
// 
//16进制窗口
// Hex View-n，可与反汇编窗口同步，同样支持多窗口，可分别对应多个不同的IDA View
// 
//strings
// view-》open subviews-》strings，开启字符串窗口
// IDA默认扫描至少包含5个字符的C风格、以null结尾的7位ASCII字符
// 另外可以setup设置其他格式，如windows程序，可以搜索Unicode等
// 
//names窗口
// 列举二进制文件的所有全局名称（指对一个程序虚拟地址的符号描述）
// 
//反汇编代码清单中的位置名称
// sub_xxxxx 地址xxxxx处的子例程
// loc_xxxxx 一个指令
// byte_xxxxx 一个8位数据
// word_xxxxx 一个16位数据
// dword_xxxxx 32位数据
// unk_xxxxx 未知大小数据
// 
//function calls
// 显示一个函数在不同位置被调用
// 以及该函数调用的其他函数
//


int main()
{
    std::cout << "Hello World!\n";
}
