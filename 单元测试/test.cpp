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

 
// prototype   ʵ�������������Ĳ����б��ǵȼ۵� 
const double* f1(const double arr[], int n);
const double* f2(const double [], int);
const double* f3(const double* , int);

int s(){
	cout<<"sdfa";
	return 1;
}
 
 
int main(int argc, char *argv[])
{
	double a[3] = {12.1, 3.4, 4.5};
	
	// ����ָ��
	const double* (*p1)(const double*, int) = f1;
	cout << "Pointer 1 : " << p1(a, 3) << " : " << *(p1(a, 3)) << endl;
	cout << "Pointer 1 : " << (*p1)(a, 3) << " : " << *((*p1)(a, 3)) << endl;
	
	const double* (*parray[3])(const double *, int) = {f1, f2, f3};   // ����һ��ָ�����飬�洢���������ĵ�ַ 
	cout << "Pointer array : " << parray[2](a, 3) << " : ";cout<< *(parray[2](a, 3)) << endl;
	cout << "Pointer array : " << parray[2](a, 3) << " : " << *(parray[2](a, 3)) << endl;
    cout << "Pointer array : " << (*parray[2])(a, 3) << " : " << *((*parray[2])(a, 3)) << endl;
    *((*parray[2])(a, 3));
    cout <<  "  fdsf     "<< s();
	return 0;
}
 
 
const double* f1(const double arr[], int n)
{
	cout<<"1";
	return arr;     // �׵�ַ 
} 
 
const double* f2(const double arr[], int n)
{
	cout<<"2";
	return arr+1;
}
 
const double* f3(const double* arr, int n)
{
	cout<<"ff3";
	return arr+2;
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
