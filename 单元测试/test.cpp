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
    char c;//��ʱ���������������
    while (cin>>c) {
        if (isdigit(c)) {
            cout<<c<<"������"<<endl;
        } else cout<<c<<"��������"<<endl;
    }
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
