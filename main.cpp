/* Copyright Linghao Chen, Xidian University, xdu.lhchen@gmail.com*/

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
	string Student_Tiems_Plus(void);
	string Stuent_Money_Decrease(void); 
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

string Student :: Student_Tiems_Plus(){
	times++;
	return to_string(times);
}

string Student :: Stuent_Money_Decrease(){
	money = money - 2.0;
	return to_string(money);
}
//void System :: Student_Tiems_Plus(){
//	//
//}

class Teacher : public People {
private:
	string college;	
	int times;
	string password;
public:
	Teacher(string i_name,string i_id, string i_sex, string i_college, string i_password, string i_times);
	~Teacher(); 
	string Teacher_Tiems_Plus();
};

Teacher :: Teacher(string i_name,string i_id, string i_sex, string i_college, string i_password, string i_times){
	name = i_name;
	id = i_id;
	sex = i_sex;
	college = i_college;
	password = i_password;
	times = atoi(i_times.c_str()); 
}

Teacher :: ~Teacher(){
	
}

string Teacher :: Teacher_Tiems_Plus() {
	times++;
	return to_string(times);;
}

class Teacher_Fam : public People {
private:
	string password;
public:
	
};

class Bus{
private:
	int number_of_passengers;
	int size;
	int count;
	double place;
	string id;
	string brand;
	string driver; 
public:
	Bus(int un_permit);
	string Get_Bus_Id(void);
	int Get_count(void);
	int Get_number_of_passengers(void);
	double Get_place(void);
	void Show_Status(void);
	void Get_On_One_Person(void);
	bool Get_Status(void);
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
			time_t nowtime;
			struct tm* p;;
			time(&nowtime);
			p = localtime(&nowtime);
			int system_time = p->tm_min;
			if(system_time>=0.0 && system_time < 1.0){
				place = system_time/10.0;
			} else if(system_time>=1.0 && system_time<20.0){
				place = 1.0;
			} else if (system_time>=20.0 && system_time <35.0){
				place = 1.0 + (system_time-20.0)/15.0;
			} else if (system_time>=35.0 && system_time<45.0){
				place = 2.0;
			} else{
				place = 2.0 + (system_time-45.0)/15.0;
			}
//			cout<<id<<driver<<brand<<size<<endl;
			break;
		}
	}
	fin.clear();
	fin.close();
}

string Bus :: Get_Bus_Id(){
	return id;
}

int Bus :: Get_count(){
	return count;
}

int Bus :: Get_number_of_passengers(){
	return number_of_passengers;
}

void Bus :: Show_Status(){
	string status;
	if(number_of_passengers<size){
		status = "未满"; 
	}
	else{
		status = "已满";
	}
	cout<<"|  * - * - * - * - * - * - * - * - * - * - * - * - * - * - * - * - * - * - * - * - * - * - *  - * |\n";
	cout<<"| *                                                                                             * |\n";
	cout<<"| |   车型："<<brand<<"\t\t车牌："<<id<<"\t\t车上人数："<<number_of_passengers<<"\t\t状态："<<status<<"      | |\n";
	cout<<"| *                                                                                             * |\n";
	cout<<"|  * - * - * - * - * - * - * - * - * - * - * - * - * - * - * - * - * - * - * - * - * - * - * - *  |\n\n\n";
}

bool Bus :: Get_Status(){
	if(number_of_passengers<size){
		return true; 
	}else{
		return false;
	}
}

double Bus :: Get_place(){
	return place;
}

void Bus :: Get_On_One_Person(){
	number_of_passengers++;
}


class System{
	int MONTH = 5; 
	void (System :: *Function_Get_On_Bus_pointer[3])(Bus&, Bus&) = {&System :: Teacher_Get_On_Bus_Check, &System :: Student_Get_On_Bus_Check, &System :: Teacher_Fam_Get_On_Bus_Check};
public:
	void System_open(void);
	void System_choice(void);
	void System_Initialize_User_Message(void);
	void Create_Account_menu(void); 
	void Create_Teacher(void); 
	void Create_Student(void); 
	void Create_Teacher_Fam(void); 
	void Check_MONTH(void);
	void Delete_Account_menu(void);
	void Delete_Teacher(void);
	void Delete_Student(void);
	void Delete_Teacher_Fam(void);
	void DelLineData(string fileName, int lineNum);
	void Get_On_Bus_And_Deposit_menu(Bus&, Bus&);
	void Get_On_Bus(Bus&, Bus&);	
	void People_Get_On_Bus(Bus&, Bus&, int);
	void Deposit(void);
	void Teacher_Get_On_Bus_Check(Bus&, Bus&);
	void Student_Get_On_Bus_Check(Bus&, Bus&);
	void Teacher_Fam_Get_On_Bus_Check(Bus&, Bus&);
	string CharToStr(char* contentChar);
	string get_password(void);

};


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
	Bus bus1(51);
	int bus1_number = bus1.Get_count();
	Bus bus2(bus1_number);
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
			Get_On_Bus_And_Deposit_menu(bus1, bus2); 
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
		    outfile << r_name << " " << r_id << " " << r_sex << " " << r_college << " " << s_password << " 0" << endl;  
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
		    outfile << r_name << " " << r_sex << " " << r_id << " " << r_college << " " << s_password << " 0 0.0" <<endl;  
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
		    outfile << r_name << " " << r_sex << " " << r_id << " 0.0 0 " << s_password << endl;  
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
	string Filename = "Teacher_Account_Message.txt";
	while(true){
		system("cls");
		fflush(stdin);
		string s_name; 
		cout<<"请输入您的名字:"<<endl;
		cin>>s_name; 
		string s_id;
		cout<<"请输入您的工号："<<endl;
		cin>>s_id;		
		
		ifstream fin(Filename, std::ios::in);
		char line[1024]={0};
		string f_name = "";
		string f_id = "";
		string f_sex = "";
		string f_college = "";
		string f_password = "";
		string f_times = ""; 
		bool In_Message=false;
		int number = 0;
		
		while(fin.getline(line, sizeof(line))){
			number++;
			stringstream word(line);
			word >> f_name;
			word >> f_id;
			word >> f_sex;
			word >> f_college;
			word >> f_password;
			word >> f_times;
//			cout<< f_name << " " << f_id <<endl;
//			cout<< s_name << " " << s_id <<endl;
			while(s_name == f_name && s_id == f_id){
				system("cls");
				fflush(stdin);
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
		string f_times = "";
		string f_money = "";
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
			word >> f_times;
			word >> f_money;
//			cout<< f_name << " " << f_id <<endl;
//			cout<< s_name << " " << s_id <<endl;
			while(s_name == f_name && s_id == f_id){
				system("cls");
				fflush(stdin);
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
	string Filename = "Teacher_Fam_Account_Message.txt";
	while(true){
		system("cls");
		fflush(stdin);
		string s_name; 
		cout<<"请输入您的名字:"<<endl;
		cin>>s_name; 
		string s_id;
		cout<<"请输入您的家属编号："<<endl;
		cin>>s_id;		
		
		ifstream fin(Filename, std::ios::in);
		char line[1024]={0};
		string f_name = "";
		string f_id = "";
		string f_sex = "";
		string f_money = "";
		string f_times = "";
		string f_password = "";
		bool In_Message=false;
		int number = 0;
		
		while(fin.getline(line, sizeof(line))){
			number++;
			stringstream word(line);
			word >> f_name;
			word >> f_sex;
			word >> f_id;
			word >> f_money;
			word >> f_times;
			word >> f_password;
//			cout<< f_name << " " << f_id <<endl;
//			cout<< s_name << " " << s_id <<endl;
			while(s_name == f_name && s_id == f_id){
				system("cls");
				fflush(stdin);
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

void System :: Get_On_Bus_And_Deposit_menu(Bus& bus1, Bus& bus2){
	int status_flag = 1; 
	while (status_flag){
		cout<<"跳转中";
		cout<<"..";Sleep(100);		
		cout<<"..";Sleep(100);
		cout<<"..";Sleep(100); 
		system("cls") ;
		cout<<"\n\n";
		cout<<"\t\t\t *===============乘车/充值===============*\n\n\n";
		cout<<"\t\t\t *=======================================*\n";
		cout<<"\t\t\t|  * - * - * - * - * - * - * - * - * - *  |\n";
		cout<<"\t\t\t| *                                     * |\n";
		cout<<"\t\t\t| |          [1]   搭乘车辆             | |\n";
		cout<<"\t\t\t| *                                     * |\n";
		cout<<"\t\t\t| |          [2]   账户充值             | |\n";
		cout<<"\t\t\t| *                                     * |\n";
		cout<<"\t\t\t| |          [3]   返回上级             | |\n";
		cout<<"\t\t\t| *                                     * |\n";
		cout<<"\t\t\t|  * - * - * - * - * - * - * - * - * - *  |\n\n\n";
		cout<<"请选择(1-3):";
		char status_choice = getch();
		while(status_choice!='1'&&status_choice!='2'&&status_choice!='3'){
  			status_choice = getch();		
		}
		cout<<status_choice;
		fflush(stdin);
		system("cls");

		if (status_choice == '1'){
			Get_On_Bus(bus1, bus2);
		} else if (status_choice == '2'){
			Deposit();	
		} else if (status_choice == '3'){
			cout<<"正在返回上级";
			cout<<"..";Sleep(100);		
			cout<<"..";Sleep(100);
			cout<<"..";Sleep(100); 
			system("cls");
			status_flag = 0;
		}	
		
	}	
}

void System :: Get_On_Bus(Bus& bus1, Bus& bus2){
	int status_flag = 1; 
	while (status_flag){
		cout<<"跳转中";
		cout<<"..";Sleep(100);		
		cout<<"..";Sleep(100);
		cout<<"..";Sleep(100); 
		system("cls") ;
		cout<<"\n\n";
		cout<<"\t\t\t *================我要乘车===============*\n\n\n";
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
			People_Get_On_Bus(bus1, bus2, 0);
		} else if (status_choice == '2'){
			People_Get_On_Bus(bus1, bus2, 1);	
		} else if (status_choice == '3'){
			People_Get_On_Bus(bus1, bus2, 2);	
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

void System :: People_Get_On_Bus(Bus& bus1, Bus& bus2, int ch){ //老师信息验证 
//	Bus bus1(51);
//	int bus1_number = bus1.Get_count();
//	Bus bus2(bus1_number);	
	time_t timep;
	struct tm *p;
	time (&timep);
	p=gmtime(&timep);
	int sec_time = p->tm_sec + (p->tm_min) * 60 + (8+p->tm_hour) * 60 * 60;
	if(sec_time<28800 || sec_time>=64800){
		cout<<"当日车辆已停运"<<endl;
		cout<<"早上8点为第一班车，晚上18点为最后一班车"<<endl;
		cout<<"按任意键重返回\n";
		getch();		 
	}	
	else{
		cout<<"请选择您目前的位置:"<<endl;
		cout<<"[1]教学楼  [2]宿舍  请选择(1-2)："<<endl;
		char status_choice = getch();
		while(status_choice!='1'&&status_choice!='2'){
			status_choice = getch();		
		}
		fflush(stdin);
		system("cls");
		double my_place;
		if(status_choice == '1'){
			my_place = 1.0; 
		} else{
			my_place = 2.0;
		}
		cout<<" *============================================车辆1信息=============================================*\n\n\n";
		bus1.Show_Status();
		cout<<" *============================================车辆2信息=============================================*\n\n\n";
		bus2.Show_Status();
		double bus1_place = bus1.Get_place(), bus2_place = bus2.Get_place();
		if(bus1_place>my_place){
			cout<<"\n您已错过车辆\n"<<endl;
		} else if(bus1_place>=my_place-0.1 && bus1_place<my_place){
			cout<<"\n车辆即将入站，请耐心等待\n"<<endl;
		} else if(fabs(bus1_place-my_place) < 0.02){
			
			cout<<"\n车辆正在当前站点\n"<<endl;
			cout<<"\n *====================================================================================*\n\n\n";
			bool status1 = bus1.Get_Status(), status2 = bus2.Get_Status();
			if(status1&&status2){
//				Teacher_Get_On_Bus_Check();
				(this->*Function_Get_On_Bus_pointer[ch])(bus1, bus2);
				cout<<"\n车辆均未满员，请上车"<<endl;
				cout<<"请选择车辆:"<<endl;
				cout<<"[1]车辆一  [2]车辆二  请选择(1-2)："<<endl;
				char choice = getch();
				while(choice!='1'&&choice!='2'){
					choice = getch();		
				}
				if(choice == '1'){
					bus1.Get_On_One_Person();
				} else{
					bus2.Get_On_One_Person();
				}
			} else if(status1 && (!status2)){
				(this->*Function_Get_On_Bus_pointer[ch])(bus1, bus2);
				cout<<"车辆二已满员，请上第一辆车";
				bus1.Get_On_One_Person();
			} else if((!status1) && status2){
				(this->*Function_Get_On_Bus_pointer[ch])(bus1, bus2);
				cout<<"车辆一已满员，请上第二辆车";
				bus2.Get_On_One_Person();
			} else{
				cout<<"两辆车均已满员，请等待下一班次";
			}	
				
		} else{
			cout<<"\n车辆距离您："<<fabs(bus1_place-my_place)<<"km\n"<<endl; 
		}	
		cout<<"按任意键重返回\n";
		getch();	
	}

	
//	cout <<  bus1_place << bus2_place;

}
void System :: Teacher_Get_On_Bus_Check(Bus& bus1, Bus& bus2){
	string Filename = "Teacher_Account_Message.txt";
	while(true){
		system("cls");
		fflush(stdin);
		cout<<" *============================================车辆1信息=============================================*\n\n\n";
		bus1.Show_Status();
		cout<<" *============================================车辆2信息=============================================*\n\n\n";
		bus2.Show_Status();
		string s_name; 
		cout<<"请输入您的名字:"<<endl;
		cin>>s_name; 
		string s_id;
		cout<<"请输入您的工号："<<endl;
		cin>>s_id;		
		
		ifstream fin(Filename, std::ios::in);
		char line[1024]={0};
		string f_name = "";
		string f_id = "";
		string f_sex = "";
		string f_college = "";
		string f_password = "";
		string f_times = "";
		bool In_Message=false;
		int number = 0;
		
		while(fin.getline(line, sizeof(line))){
			number++;
			stringstream word(line);
			word >> f_name;
			word >> f_id;
			word >> f_sex;
			word >> f_college;
			word >> f_password;
			word >> f_times;
//			cout<< f_name << " " << f_id <<endl;
//			cout<< s_name << " " << s_id <<endl;
			while(s_name == f_name && s_id == f_id){
				Teacher teacher(f_name, f_id, f_sex, f_college, f_password, f_times);
				system("cls");
				fflush(stdin);
				cout<<"请输入您的密码:"<<endl;
				string tmp_password = get_password();
				if(f_password == tmp_password){
					f_times = teacher.Teacher_Tiems_Plus();
					DelLineData(Filename, number);
					ofstream outfile;
					outfile.open(Filename, ios::app); 
					outfile << f_name << " " << f_id << " " << f_sex << " " << f_college << " " << f_password <<" " << f_times << endl; 
					outfile.close(); 
					In_Message = true;
					teacher.~Teacher();
					break;
				}
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
} 

void System :: Student_Get_On_Bus_Check(Bus& bus1, Bus& bus2)	{
	string Filename = "Student_Account_Message.txt";
	while(true){
		system("cls");
		fflush(stdin);
		cout<<" *============================================车辆1信息=============================================*\n\n\n";
		bus1.Show_Status();
		cout<<" *============================================车辆2信息=============================================*\n\n\n";
		bus2.Show_Status();
		string s_name; 
		cout<<"请输入您的名字:"<<endl;
		cin>>s_name; 
		string s_id;
		cout<<"请输入您的学号："<<endl;
		cin>>s_id;		
		
		ifstream fin(Filename, std::ios::in);
		char line[1024]={0};
		string f_name = "";
		string f_sex = "";
		string f_id = "";
		string f_college = "";
		string f_password = "";
		string f_times = "";
		string f_money = "";
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
			word >> f_times;
			word >> f_money;
			double check_times = atoi(f_times.c_str());
			if(s_name == f_name && s_id == f_id && check_times < 2.0){
				cout<<"账户余额不足2.0元，请充值"<<endl;
				cout<<"按任意键返回"<<endl;
				getch(); 
				In_Message = true;
				break;
			}
//			cout<< f_name << " " << f_id <<endl;
//			cout<< s_name << " " << s_id <<endl;
			while(s_name == f_name && s_id == f_id){
				Student student(f_name, f_sex, f_id, f_college, f_password, f_times, f_money);
				system("cls");
				fflush(stdin);
				cout<<"请输入您的密码:"<<endl;
				string tmp_password = get_password();
				if(f_password == tmp_password){
					f_times = student.Student_Tiems_Plus();
					f_money = student.Stuent_Money_Decrease();
					DelLineData(Filename, number);
					ofstream outfile;
					outfile.open(Filename, ios::app); 
					outfile << f_name << " " << f_id << " " << f_sex << " " << f_college << " " << f_password <<" " << f_times << f_money <<endl; 
					outfile.close(); 
					if(check_times<7.0){
						cout<<"当前账户余额不足5.0元，请尽快充值"<<endl;
						cout<<"按任意键返回";
						getch();
					}
					In_Message = true;
					student.~Student();
					break;
				}
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
}

void System :: Teacher_Fam_Get_On_Bus_Check(Bus& bus1, Bus& bus2)	{
	
}

void System :: Deposit(){
	
	
}

int main(){
	System s;
	s.System_open();
	
	return 0;
}

