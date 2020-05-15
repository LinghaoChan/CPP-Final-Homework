#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <sstream>
#include <fstream>
#include <time.h>
#include <math.h>
using namespace std;

class People{
public:
	string name;
	string sex;
	string id;
};

class Student : public People {
private:
	string college;	
	string password;
	int times;
	double money;
public:
	Student(string, string, string, string, string, string, string);
	~Student();
	string Student_Times_Plus(void);
	string Stuent_Money_Decrease(void); 
	string Student_Deposit(double);
}; 

Student :: Student(string i_name, string i_sex, string i_id, string i_college, string i_password, string i_times, string i_money){
	name = i_name;
	sex = i_sex;
	id = i_id;
	college = i_college;
	password = i_password;
	times = atoi(i_times.c_str()); 
	money = atof(i_money.c_str());
}

Student :: ~Student(){
	
}

string Student :: Student_Times_Plus(){
	times++;
	return to_string(times);
}

string Student :: Stuent_Money_Decrease(){
	money = money - 2.0;
	return to_string(money);
}

string Student :: Student_Deposit(double deposit){
	money += deposit;
	return to_string(money);
}

string get_password(){
	int count = 0;
	char str[25];
	char c;
	while((c = getch()) != 13){
		if(c==8 && count>0){
			cout<<"\b \b";
			count--;
			continue;
		} else if(c != 8){
			putchar('*');	
			str[count] = c;
			count++;			
		}
		if (count >= 20){
			cout << endl << "密码不超过20位,重新输入" <<endl;
			break;
		}
	}
	str[count] = '\0';
	string s = str; 
	return s;
}

string  CharToStr(char * contentChar){
	string tempStr;
	for (int i=0;contentChar[i]!='\0';i++)
	{
		tempStr+=contentChar[i];
	}
	return tempStr;
}

void DelLineData(string fileName, int lineNum){
	ifstream in;
	in.open(fileName);
	
	string strFileData = "";
	int line = 1;
	char lineData[1024] = {0};
	while(in.getline(lineData, sizeof(lineData))){
		if (line == lineNum){
			strFileData += "";
		}else{
			strFileData += CharToStr(lineData);
			strFileData += "\n";
		}
		line++;
	}
	in.close();
	ofstream out;
	out.open(fileName);
	out.flush();
	out<<strFileData;
	out.close();
}

void ModifyLineData(char* fileName, int lineNum, char* lineData)
{
	ifstream in;
	in.open(fileName);
 
	string strFileData = "";
	int line = 1;
	char tmpLineData[1024] = {0};
	while(in.getline(tmpLineData, sizeof(tmpLineData)))
	{
		if (line == lineNum)
		{
			strFileData += CharToStr(lineData);
			strFileData += "\n";
		}
		else
		{
			strFileData += CharToStr(tmpLineData);
			strFileData += "\n";
		}
		line++;
	}
	in.close();
 
	//写入文件
	ofstream out;
	out.open(fileName);
	out.flush();
	out<<strFileData;
	out.close();
}


void Student_Deposit(){
	string Filename = "Student_Account_Message.txt";
	bool sign = true;
	while(sign == true){
		system("cls");
		fflush(stdin);
		string s_name; 
		cout<<"请输入您的名字:"<<endl;
		cin>>s_name; 
		string s_id;
		cout<<"请输入您的学号："<<endl;
		cin>>s_id;
		
		ifstream fin(Filename, std::ios::in);
		char line[1024]={0};
		string f_name = "", f_sex = "", f_id = "", f_college = "", f_password = "", f_times = "", f_money = "";
		bool In_Message=false;
		int number = 0;	
		while(fin.getline(line, sizeof(line))){
			number++;
			stringstream word(line);
			word >> f_name >> f_sex >> f_id >> f_college >> f_password >> f_times >> f_money;
//			cout << f_name << f_sex << f_id << f_college << f_password << f_times << f_money;
			if(f_name == s_name && f_id == s_id){
				Student student(f_name, f_sex, f_id, f_college, f_password, f_times, f_money);
				sign = false;
				while(true){
					system("cls");
					fflush(stdin);
					cout<<"请输入您的密码"<<endl;
					string input_password = get_password();
					if(input_password == f_password){
						double dep; 
						cout<<"\n请输入您的充值金额："<<endl;
						cin>>dep;
						string m = student.Student_Deposit(dep);
						string new_inputline = f_name +" "+ f_sex +" "+ f_id +" "+ f_college +" "+ f_password +" "+ f_times +" "+ m; 
						char* chr1 = const_cast<char*>(Filename.c_str());
						char* chr2 = const_cast<char*>(new_inputline.c_str());
						ModifyLineData(chr1, number, chr2);
						cout<<"\07充值成功"<<endl; 
						Sleep(300);
						break;
					} else{
						
						cout<<"\n密码错误，按任意键返回"<<endl;
						getch();
					}
				}
			}
		}
	} 
	if(sign == true){
		cout<<"您不在当前账户中，按任意键返回"<<endl;
		getch();
	}
	
}


int main() {
	Student_Deposit();	
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
