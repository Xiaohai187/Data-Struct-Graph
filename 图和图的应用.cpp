// 图和图的应用.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include"StructDefine.h"
using namespace std;

int main()
{
    int chose;
    while (1) {
        cout << "\n*********************************************************************\n";
        cout << "                       Graph BasicOpreation                          \n\n";
        cout << "1、邻接矩阵存储相关图操作                        2、邻接表存储相关图操作\n";
        cout << "3、暂定  \n\n输入选择，输入0直接退出！\n";
        cout << "*********************************************************************\n";
        cin >> chose;
        switch (chose)
        {
        case 1:
            AMgraphBasicOperation();
            break;
        case 2:
            ALgraphBasicOperation();
        default:
            break;
        }
    }
}

