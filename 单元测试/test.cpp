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
	printf("%d\n",p->tm_sec); /*��ȡ��ǰ��*/
	printf("%d\n",p->tm_min); /*��ȡ��ǰ��*/
	printf("%d\n",8+p->tm_hour);/*��ȡ��ǰʱ,�����ȡ������ʱ��,�պ����˸�Сʱ*/
	int sec_time = p->tm_sec + (p->tm_min) * 60 + (8+p->tm_hour) * 60 * 60;
	cout<<sec_time;
	return 0;
}
/* 
cout<<" *===================================��ǰ������Ϣ====================================*\n\n\n";
cout<<" *===================================================================================*\n";
cout<<"|  * - * - * - * - * - * - * - * - * - * - * - * - * - * - * - * - * - * - * - *  - * |\n";
cout<<"| *                                                                                 * |\n";
cout<<"| |   ���ͣ�           ���ƣ�             ����������             ״̬��             | |\n";
cout<<"| *                                                                                 * |\n";
cout<<"| |          ˾��                                                                   | |\n";
cout<<"| *                                                                                 * |\n";
cout<<"| |          ����            | |\n";
cout<<"| *                                     * |\n";
cout<<"| |          [4]   �˳�ϵͳ             | |\n";
cout<<"| *                                     * |\n";
cout<<"|  * - * - * - * - * - * - * - * - * - *  |\n\n\n";
*/
