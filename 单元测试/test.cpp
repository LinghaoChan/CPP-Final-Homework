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


int main()
{

	time_t timep;
	struct tm *p;
	time (&timep);
	p=gmtime(&timep);
	printf("%d\n",p->tm_sec); /*获取当前秒*/
	printf("%d\n",p->tm_min); /*获取当前分*/
	printf("%d\n",8+p->tm_hour);/*获取当前时,这里获取西方的时间,刚好相差八个小时*/
	int sec_time = p->tm_sec + (p->tm_min) * 60 + (8+p->tm_hour) * 60 * 60;
	cout<<sec_time;
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
