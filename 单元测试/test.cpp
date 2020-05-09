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

string CharToStr(char * contentChar)
{
	string tempStr;
	for (int i=0;contentChar[i]!='\0';i++)
	{
		tempStr+=contentChar[i];
	}
	return tempStr;
}
void DelLineData(string fileName, int lineNum)
{
	ifstream in;
	in.open(fileName);
	
	string strFileData = "";
	int line = 1;
	char lineData[1024] = {0};
	while(in.getline(lineData, sizeof(lineData)))
	{
		if (line == lineNum)
		{
			strFileData += "";
		}
		else
		{
			strFileData += CharToStr(lineData);
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

int main(){
	string Filename = "Student_Account_Message.txt";
	while(true){
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
		string f_name = "";
		string f_id = "";
		string f_sex = "";
		string f_college = "";
		string f_password = "";
		bool In_Message=false;
		int number = 0;
		
		while(fin.getline(line, sizeof(line))){
			number++;
			stringstream word(line);
			word >> f_name;
			word >> f_sex;
			word >> f_id;
			word >> f_college;
			word >> f_password;
//			cout<< f_name << " " << f_id <<endl;
//			cout<< s_name << " " << s_id <<endl;
			while(s_name == f_name && s_id == f_id){
				cout<<"请输入您的密码:"<<endl;
				string tmp_password = get_password();
				if(f_password == tmp_password){
					DelLineData(Filename, number);
					break;
				}
				In_Message = true;
			}
			if(In_Message == true){
				break;
			}
		}
		fin.clear();
		fin.close();
		if(In_Message == true){
			break;
		}
	}
	return 0;
}
