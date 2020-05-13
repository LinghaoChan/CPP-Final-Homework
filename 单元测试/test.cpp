#include <iostream>
#include <stdio.h>
#include <sstream>
#include <fstream>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
using namespace std;



int main() {
    char c;//此时输入的是整型数字
    while (cin>>c) {
        if (isdigit(c)) {
            cout<<c<<"是数字"<<endl;
        } else cout<<c<<"不是数字"<<endl;
    }
    return 0;
}
 
 
 
/* 
cout<<" *===================================当前车辆信息====================================*\n\n\n";
cout<<" *===================================================================================*\n";
cout<<"|  * - * - * - * - * - * - * - * - * - * - * - * - * - * - * - * - * - * - * - *  - * |\n";
cout<<"| *                                                                                 * |\n";
cout<<"| |   车型：           车牌：             车上人数：             状态：             | |\n";
cout<<"| *                                                                                 * |\n";
cout<<"| |          司机                                                                   | |\n";
cout<<"| *                                                                                 * |\n";
cout<<"| |          车牌            | |\n";
cout<<"| *                                     * |\n";
cout<<"| |          [4]   退出系统             | |\n";
cout<<"| *                                     * |\n";
cout<<"|  * - * - * - * - * - * - * - * - * - *  |\n\n\n";
*/
