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

class Bus{
private:
	int number_of_passengers;
	int size;
	int count;
	string id;
	string brand;
	string driver; 
public:
	Bus(int un_permit);
	string Get_Bus_Id(void);
	int Get_count(void);
	int Get_number_of_passengers(void);
	void Show_Status(void);
};

Bus :: Bus(int un_permit){
	string Filename = "Bus_Message.txt";
	ifstream fin(Filename, std::ios::in);
	char line[1024]={0};
	string f_id = "";
	string f_name = "";
	string f_brand = "";
	string f_size = "";
	srand((unsigned)time(NULL));
	int choice, number=0;  
	while((choice = (rand()%50+1))==un_permit){	
		//busy waiting
	} 
	while(fin.getline(line, sizeof(line))){
		number++;
		stringstream word(line);
		if(choice == number){
			word >> f_id;
			word >> f_name;
			word >> f_brand;
			word >> f_size;	
			id = f_id;
			driver = f_name;
			brand = f_brand;
			size = atoi(f_size.c_str());
			count = number;
			number_of_passengers = rand()%size+1;
			cout<<id<<driver<<brand<<size<<endl;
			break;
		}
	}
	fin.clear();
	fin.close();
}

string Bus :: Get_Bus_Id(){
	return id;
}

void Bus :: Show_Status(){
	string status;
	if(number_of_passengers<size){
		status = "δ��"; 
	}
	else{
		status = "����";
	}
	cout<<"|  * - * - * - * - * - * - * - * - * - * - * - * - * - * - * - * - * - * - * - * - * - * - *  - * |\n";
	cout<<"| *                                                                                             * |\n";
	cout<<"| |   ���ͣ�"<<brand<<"\t\t���ƣ�"<<id<<"\t\t����������"<<number_of_passengers<<"\t\t״̬��"<<status<<"      | |\n";
	cout<<"| *                                                                                             * |\n";
	cout<<"|  * - * - * - * - * - * - * - * - * - * - * - * - * - * - * - * - * - * - * - * - * - * - * - *  |\n\n\n";
}

int main(){
	Bus bus1(2);
	cout<<bus1.Get_Bus_Id()<<endl;
	bus1.Show_Status();
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
