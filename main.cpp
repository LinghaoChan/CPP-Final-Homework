/* Copyright Linghao Chen, Xidian University, xdu.lhchen@gmail.com*/

#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <sstream>
#include <fstream>

using namespace std;
class People{
public:
	string name;
	char sex;
	string id;
};

class Student : public People {
private:
	string college;	
	string password;
	double money;
public:
	Student();
	Student(string name, string sex, string id, string password);
	
}; 
Student::Student(){
	
}

Student::Student(string name, string sex, string id, string password){
	
}

class Teacher{
private:
	string college;	
	double money;

};

class Teacher_Fam{
private:
	string password;
public:
	
};

class Bus{
	
	
};


namespace System{
	int MONTH = 5; 
	void System_open(void);
	void System_choice(void);
	void System_Initialize_User_Message(void);
	void Create_Account_menu(void); 
	void Create_Teacher(void); 
	void Create_Student(void); 
	void Create_Teacher_Fam(void); 
	void Check_MONTH(void);
	void Delete_Account_menu(void);
	void Delete_Teacher();
	void Delete_Student();
	void Delete_Teacher_Fam();
	string CharToStr(char * contentChar);
	void DelLineData(string fileName, int lineNum);
	string get_password(void);

}


void System :: System_open(void){
	cout<<"\n\n\n\n\n\n\t\t\t\t\t";
	cout<<"-------------------------------------"<<endl;
	cout<<"\t\t\t\t\t\t欢迎使用西电公交系统"<<endl;
	cout<<"\t\t\t\t\t-------------------------------------"<<endl;
	Sleep(500);
	system("cls"); 	
	cout<<"\n\n\n\n\n\n\t\t\t数据获取中";
	System_Initialize_User_Message();							//3?ê??ˉó??§D??￠￡¨2?D′ò?μ?μ?￡? 
	system("cls"); 	
	System_choice();											//1|?ü????￡¨μY1é?D￡? 
}

void System :: System_Initialize_User_Message(void){
	Student* student_pointer = (Student*) malloc(500 * sizeof(Student));
	/*  */
	cout<<"..";Sleep(100);	
	/*  */		
	cout<<"..";Sleep(100);
	/*  */	
	cout<<"..";Sleep(100);
	/*  */	
	cout<<"..";Sleep(100);	
}

void System :: System_choice(void){
	int flag = 1;
	
	while(flag){
		cout<<"\n\n";
		cout<<"\t\t\t *==============西电公交系统=============*\n\n\n";
		cout<<"\t\t\t *=======================================*\n";
		cout<<"\t\t\t|  * - * - * - * - * - * - * - * - * - *  |\n";
		cout<<"\t\t\t| *                                     * |\n";
		cout<<"\t\t\t| |          [1]   创建账户             | |\n";
		cout<<"\t\t\t| *                                     * |\n";
		cout<<"\t\t\t| |          [2]   注销账户             | |\n";
		cout<<"\t\t\t| *                                     * |\n";
		cout<<"\t\t\t| |          [3]   乘车/充值            | |\n";
		cout<<"\t\t\t| *                                     * |\n";
		cout<<"\t\t\t| |          [4]   退出系统             | |\n";
		cout<<"\t\t\t| *                                     * |\n";
		cout<<"\t\t\t|  * - * - * - * - * - * - * - * - * - *  |\n\n\n";
		cout<<"请选择(1-4):";
		char choice = getch();
		while(choice!='1'&&choice!='2'&&choice!='3'&&choice!='4'){
  			choice = getch();		
		}
		cout<<choice;
		fflush(stdin);
		system("cls");

		if (choice == '1'){
			Create_Account_menu();
		} else if (choice == '2'){
			Delete_Account_menu();	
		} else if (choice == '3'){
			/*  */	
		} else if ( choice == '4'){
			flag = 0;
		}	
	}

	system("cls");
	fflush(stdin);
	printf("你已经安全退出系统!(按任意键关闭界面)\n\n\t欢迎您的再次使用!\n\n");
	getch();
}
void System :: Create_Account_menu(void){
	int status_flag = 1; 
	while (status_flag){
		cout<<"跳转中";
		cout<<"..";Sleep(100);		
		cout<<"..";Sleep(100);
		cout<<"..";Sleep(100); 
		system("cls") ;
		cout<<"\n\n";
		cout<<"\t\t\t *================创建账户===============*\n\n\n";
		cout<<"\t\t\t *=======================================*\n";
		cout<<"\t\t\t|  * - * - * - * - * - * - * - * - * - *  |\n";
		cout<<"\t\t\t| *                                     * |\n";
		cout<<"\t\t\t| |          [1]   我是老师             | |\n";
		cout<<"\t\t\t| *                                     * |\n";
		cout<<"\t\t\t| |          [2]   我是学生             | |\n";
		cout<<"\t\t\t| *                                     * |\n";
		cout<<"\t\t\t| |          [3]   我是家属             | |\n";
		cout<<"\t\t\t| *                                     * |\n";
		cout<<"\t\t\t| |          [4]   返回上级             | |\n";
		cout<<"\t\t\t| *                                     * |\n";
		cout<<"\t\t\t|  * - * - * - * - * - * - * - * - * - *  |\n\n\n";
		cout<<"请选择(1-4):";
		char status_choice = getch();
		while(status_choice!='1'&&status_choice!='2'&&status_choice!='3'&&status_choice!='4'){
  			status_choice = getch();		
		}
		cout<<status_choice;
		fflush(stdin);
		system("cls");

		if (status_choice == '1'){
			Create_Teacher();
		} else if (status_choice == '2'){
			Create_Student();	
		} else if (status_choice == '3'){
			Create_Teacher_Fam();	
		} else if (status_choice == '4'){
			cout<<"正在返回上级";
			cout<<"..";Sleep(100);		
			cout<<"..";Sleep(100);
			cout<<"..";Sleep(100); 
			system("cls");
			status_flag = 0;
		}	
		
	}
}

void System :: Create_Teacher(void){
	string r_name = "";
	string r_id = ""; 
	string r_sex = "";
	string r_college = "";
	bool flag = false;
	while(true)
	{
		system("cls");
		fflush(stdin);
	
		string s_name; 
		cout<<"请输入您的名字:"<<endl;
		cin>>s_name;
		
		string s_id;
		cout<<"请输入您的工号"<<endl;
		cin>>s_id;		
		
		
		ifstream fin("Teacher_Message.txt", std::ios::in);
		char line[1024]={0};
		string f_name = "";
		string f_id = "";
		string f_sex = "";
		string f_college = "";
		bool In_Message=false;
		while(fin.getline(line, sizeof(line))){
			stringstream word(line);
			word >> f_name;
			word >> f_id;
			word >> f_sex;
			word >> f_college;
//			cout<< f_name << " " << f_id << " " << f_sex << " "<< f_college <<endl;
			if(s_name == f_name && s_id == f_id){
				r_id = s_id;
				r_name = s_name;
				r_sex = f_sex;
				r_college = f_college;
				In_Message = true;
				break;
			}
		}
		fin.clear();
		fin.close();
		
		ifstream fin2("Teacher_Account_Message.txt", std::ios::in);
		char line2[1024]={0};
		string accout_name = "";
		string accout_id = "";
		string accout_sex = "";
		string accout_college = "";
		string accout_password = "";
		bool Account_Message = false;		
		while(fin2.getline(line2, sizeof(line2)))
		{
			stringstream word2(line2);
			word2 >> accout_name;
			word2 >> accout_id;
			word2 >> accout_sex;
			word2 >> accout_college;
			word2 >> accout_password;
//			cout<< f_name << " " << f_id << " " << f_sex << " "<< f_college <<endl;
			if(s_name == accout_name && s_id == accout_id){
				Account_Message = true;
				break;
			}
		}
		fin2.clear();
		fin2.close();
		if(In_Message==true && Account_Message == false) {
			flag = true;
			break;
		} else if(In_Message==false){
			cout<<"账户信息不匹配！请重新注册！\n";
			cout<<"按任意键重新注册\n\n";
			getch();				
		} else{
			cout<<"该ID已被注册！请重新注册！\n";
			cout<<"按任意键重新注册\n\n";
			getch();
		}
	}

	while(true){
		system("cls");
		fflush(stdin);
		string s_password;
		cout<<"请输入您的密码:"<<endl;
		s_password = get_password();
		string s_password_verify;
		cout<< endl << "请确认您的密码:"<<endl;
		s_password_verify = get_password();	
		cout<<endl; 
		if(s_password == s_password_verify) {
			ofstream outfile;
		    outfile.open("Teacher_Account_Message.txt", ios::app); 
		    if(!outfile.is_open ())
		        cout << "Open file failure" << endl;
		    outfile << r_name << " " << r_id << " " << r_sex << " " << r_college << " " << s_password << endl;  
		    outfile.close();
		    cout<<"\07用户创建成功！"<<endl; 
		    Sleep(500);
			break;					
		} else{
			cout<<"两次输入密码不一致，请重新输入";
			cout<<"按任意键重新验证密码\n\n";
			getch();
		} 
	}

}

void System :: Create_Student(void){
	string r_name = "";
	string r_id = ""; 
	string r_sex = "";
	string r_college = "";
	string r_money = "0";
	bool flag = false;
	while(true)
	{
		system("cls");
		fflush(stdin);
	
		string s_name; 
		cout<<"请输入您的名字:"<<endl;
		cin>>s_name;
		
		string s_id;
		cout<<"请输入您的学号"<<endl;
		cin>>s_id;		
		
		
		ifstream fin("Student_Message.txt", std::ios::in);
		char line[1024]={0};
		string f_name = "";
		string f_id = "";
		string f_sex = "";
		string f_college = "";
		bool In_Message=false;
		while(fin.getline(line, sizeof(line))){
			stringstream word(line);
			word >> f_name;
			word >> f_sex;
			word >> f_id;
			word >> f_college;
//			cout<< f_name << " " << f_id <<endl;
			if(s_name == f_name && s_id == f_id){
				r_id = s_id;
				r_name = s_name;
				r_sex = f_sex;
				r_college = f_college;
				In_Message = true;
				break;
			}
		}
		fin.clear();
		fin.close();
		
		ifstream fin2("Student_Account_Message.txt", std::ios::in);
		char line2[1024]={0};
		string accout_name = "";
		string accout_id = "";
		string accout_sex = "";
		string accout_college = "";
		string accout_password = "";
		bool Account_Message = false;		
		while(fin2.getline(line2, sizeof(line2)))
		{
			stringstream word2(line2);
			word2 >> accout_name;
			word2 >> accout_sex;
			word2 >> accout_id;
			word2 >> accout_college;
			word2 >> accout_password;
//			cout<< s_name<<"-"<<accout_name << "-" <<s_id<<"-"<< accout_id << "-" << accout_sex << "-"<< accout_college <<endl;Sleep(500);
			if(s_name == accout_name && s_id == accout_id){
				Account_Message = true;
				
				break;
			}
		}
		fin2.clear();
		fin2.close();
 
		if(In_Message==true && (Account_Message == false)) {

			flag = true;
			break;
		} else if(In_Message==false){
			cout<<"账户信息不匹配！请重新注册！\n";
			cout<<"按任意键重新注册\n\n";
			getch();				
		} else{
			cout<<"该ID已被注册！请重新注册！\n";
			cout<<"按任意键重新注册\n\n";
			getch();
		}
	}

	while(true){
		system("cls");
		fflush(stdin);
		string s_password;
		cout<<"请输入您的密码:"<<endl;
		s_password = get_password();
		string s_password_verify;
		cout<< endl << "请确认您的密码:"<<endl;
		s_password_verify = get_password();	
		cout<<endl; 
		if(s_password == s_password_verify) {
			ofstream outfile;
		    outfile.open("Student_Account_Message.txt", ios::app); 
		    if(!outfile.is_open ())
		        cout << "Open file failure" << endl;
		    outfile << r_name << " " << r_sex << " " << r_id << " " << r_college << " " << s_password << endl;  
		    outfile.close();
		    cout<<"\07用户创建成功！"<<endl; 
		    Sleep(500);
			break;					
		} else{
			cout<<"两次输入密码不一致，请重新输入";
			cout<<"按任意键重新验证密码\n";
			getch();
		} 
	}
}

void System :: Create_Teacher_Fam(){
	string r_name = "";
	string r_id = ""; 
	string r_sex = "";
	string r_money = "0";
	bool flag = false;
	while(true)
	{
		system("cls");
		fflush(stdin);
	
		string s_name; 
		cout<<"请输入您的名字:"<<endl;
		cin>>s_name;
		
		string s_id;
		cout<<"请输入您的家属编号："<<endl;
		cin>>s_id;		
		
		
		ifstream fin("Teacher_Fam_Message.txt", std::ios::in);
		char line[1024]={0};
		string f_name = "";
		string f_id = "";
		string f_sex = "";

		bool In_Message=false;
		while(fin.getline(line, sizeof(line))){
			stringstream word(line);
			word >> f_name;
			word >> f_sex;
			word >> f_id;

//			cout<< f_name << " " << f_id <<endl;
			if(s_name == f_name && s_id == f_id){
				r_id = s_id;
				r_name = s_name;
				r_sex = f_sex;

				In_Message = true;
				break;
			}
		}
		fin.clear();
		fin.close();
		
		ifstream fin2("Teacher_Fam_Account_Message.txt", std::ios::in);
		char line2[1024]={0};
		string accout_name = "";
		string accout_id = "";
		string accout_sex = "";
		string accout_money = "";
		string account_times = "";
		string accout_password = "";
		bool Account_Message = false;		
		while(fin2.getline(line2, sizeof(line2)))
		{
			stringstream word2(line2);
			word2 >> accout_name;
			word2 >> accout_sex;
			word2 >> accout_id;
			word2 >> accout_money;
			word2 >> account_times;
			word2 >> accout_password;
//			cout<< s_name<<"-"<<accout_name << "-" <<s_id<<"-"<< accout_id << "-" << accout_sex << "-"<< accout_college <<endl;Sleep(500);
			if(s_name == accout_name && s_id == accout_id){
				Account_Message = true;
				
				break;
			}
		}
		fin2.clear();
		fin2.close();
 
		if(In_Message==true && (Account_Message == false)) {

			flag = true;
			break;
		} else if(In_Message==false){
			cout<<"账户信息不匹配！请重新注册！\n";
			cout<<"按任意键重新注册\n\n";
			getch();				
		} else{
			cout<<"该ID已被注册！请重新注册！\n";
			cout<<"按任意键重新注册\n\n";
			getch();
		}
	}

	while(true){
		system("cls");
		fflush(stdin);
		string s_password;
		cout<<"请输入您的密码:"<<endl;
		s_password = get_password();
		string s_password_verify;
		cout<< endl << "请确认您的密码:"<<endl;
		s_password_verify = get_password();	
		cout<<endl; 
		if(s_password == s_password_verify) {
			ofstream outfile;
		    outfile.open("Teacher_Fam_Account_Message.txt", ios::app); 
		    if(!outfile.is_open ())
		        cout << "Open file failure" << endl;
		    outfile << r_name << " " << r_sex << " " << r_id << " 0 20 " << s_password << endl;  
		    outfile.close();
		    cout<<"\07用户创建成功！"<<endl; 
		    Sleep(500);
			break;					
		} else{
			cout<<"两次输入密码不一致，请重新输入";
			cout<<"按任意键重新验证密码\n";
			getch();
		} 
	}	
}

string System :: get_password(){
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

void System :: Delete_Account_menu(){
	int status_flag = 1; 
	while (status_flag){
		cout<<"跳转中";
		cout<<"..";Sleep(100);		
		cout<<"..";Sleep(100);
		cout<<"..";Sleep(100); 
		system("cls") ;
		cout<<"\n\n";
		cout<<"\t\t\t *================注销账户===============*\n\n\n";
		cout<<"\t\t\t *=======================================*\n";
		cout<<"\t\t\t|  * - * - * - * - * - * - * - * - * - *  |\n";
		cout<<"\t\t\t| *                                     * |\n";
		cout<<"\t\t\t| |          [1]   我是老师             | |\n";
		cout<<"\t\t\t| *                                     * |\n";
		cout<<"\t\t\t| |          [2]   我是学生             | |\n";
		cout<<"\t\t\t| *                                     * |\n";
		cout<<"\t\t\t| |          [3]   我是家属             | |\n";
		cout<<"\t\t\t| *                                     * |\n";
		cout<<"\t\t\t| |          [4]   返回上级             | |\n";
		cout<<"\t\t\t| *                                     * |\n";
		cout<<"\t\t\t|  * - * - * - * - * - * - * - * - * - *  |\n\n\n";
		cout<<"请选择(1-4):";
		char status_choice = getch();
		while(status_choice!='1'&&status_choice!='2'&&status_choice!='3'&&status_choice!='4'){
  			status_choice = getch();		
		}
		cout<<status_choice;
		fflush(stdin);
		system("cls");

		if (status_choice == '1'){
			Delete_Teacher();
		} else if (status_choice == '2'){
			Delete_Student();	
		} else if (status_choice == '3'){
			Delete_Teacher_Fam();	
		} else if (status_choice == '4'){
			cout<<"正在返回上级";
			cout<<"..";Sleep(100);		
			cout<<"..";Sleep(100);
			cout<<"..";Sleep(100); 
			system("cls");
			status_flag = 0;
		}	
		
	}	
}

void System :: Delete_Teacher(){
	
	
}

void System :: Delete_Student(){
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
			cout<<"\07用户创建成功！"<<endl; 
		    Sleep(500);
			break;
		}
	}	
}

void System :: Delete_Teacher_Fam(){
	
	
	
}

string System :: CharToStr(char * contentChar)
{
	string tempStr;
	for (int i=0;contentChar[i]!='\0';i++)
	{
		tempStr+=contentChar[i];
	}
	return tempStr;
}
void System :: DelLineData(string fileName, int lineNum)
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
	ofstream out;
	out.open(fileName);
	out.flush();
	out<<strFileData;
	out.close();
}

int main(){
	System::System_open();
	
	return 0;
}

