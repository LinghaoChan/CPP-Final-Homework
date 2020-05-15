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

class Teacher : public People {
private:
	string college;	
	int times;
	string password;
public:
	Teacher(string i_name,string i_id, string i_sex, string i_college, string i_password, string i_times);
	~Teacher(); 
	string Teacher_Times_Plus();
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

string Teacher :: Teacher_Times_Plus() {
	times++;
	return to_string(times);;
}

class Teacher_Fam : public People {
private:
	int times;
	double money;
	string password;
public:
	Teacher_Fam(string, string, string, string, string, string);
	~Teacher_Fam(void);	
	string Teacher_Fam_Times_Plus(void);
	string Teacher_Fam_Money_Decrease(void); 
	int Get_Times(void);
	string Teacher_Fam_Deposit(double);
};

Teacher_Fam :: Teacher_Fam(string i_name, string i_sex, string i_id, string i_money, string i_times, string i_password){
	name = i_name;
	sex = i_sex;
	id = i_id;
	money = atof(i_money.c_str());
	times = atoi(i_times.c_str());
	password = i_password;
}

Teacher_Fam :: ~Teacher_Fam(){
	
}

string Teacher_Fam :: Teacher_Fam_Times_Plus(){
	times++;
	return to_string(times); 
}

string Teacher_Fam :: Teacher_Fam_Money_Decrease(){
	money = money - 2.0;
	return to_string(money);
}

int Teacher_Fam :: Get_Times(){
	return times;
}

string Teacher_Fam :: Teacher_Fam_Deposit(double deposit_money){
	money += deposit_money;
	return to_string(money);
}

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
	string f_id = "", f_name = "", f_brand = "", f_size = "";
	srand((unsigned)time(NULL));
	int choice, number=0;  
	while((choice = (rand()%50+1))==un_permit){	
		//busy waiting
	} 
	while(fin.getline(line, sizeof(line))){
		number++;
		stringstream word(line);
		if(choice == number){
			word >> f_id >> f_name >> f_brand >> f_size;	
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
			if(system_time>=0.0 && system_time < 10.0){
				place = system_time/10.0;
			} else if(system_time>=10.0 && system_time<20.0){
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
	bool (System :: *Function_Get_On_Bus_pointer[3])(Bus&, Bus&) = {&System :: Teacher_Get_On_Bus_Check, &System :: Student_Get_On_Bus_Check, &System :: Teacher_Fam_Get_On_Bus_Check};
	void (System :: *People_Deposit_pointer[2])(void) = {&System :: Student_Deposit, &System :: Teacher_Fam_Deposit};
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
	bool Teacher_Get_On_Bus_Check(Bus&, Bus&);
	bool Student_Get_On_Bus_Check(Bus&, Bus&);
	bool Teacher_Fam_Get_On_Bus_Check(Bus&, Bus&);
	void Student_Deposit(void);
	void Teacher_Fam_Deposit(void);
	void ModifyLineData(char* fileName, int lineNum, char* lineData);
	string CharToStr(char* contentChar);
	string get_password(void);

};


void System :: System_open(void){
	cout<<"\n\n\n\n\n\n\t\t\t\t\t";
	cout<<"-------------------------------------"<<endl;
	cout<<"\t\t\t\t\t\t��ӭʹ�����繫��ϵͳ"<<endl;
	cout<<"\t\t\t\t\t-------------------------------------"<<endl;
	Sleep(500);
	system("cls"); 	
	cout<<"\n\n\n\n\n\n\t\t\t���ݻ�ȡ��";
	System_Initialize_User_Message();						
	system("cls"); 	
	System_choice();										
}

void System :: System_Initialize_User_Message(void){
	Student* student_pointer = (Student*) malloc(500 * sizeof(Student));
	cout<<"..";Sleep(200);		
	cout<<"..";Sleep(200);
	cout<<"..";Sleep(200);
}

void System :: System_choice(void){
	int flag = 1;
	Bus bus1(51);
	int bus1_number = bus1.Get_count();
	Bus bus2(bus1_number);
	while(flag){
		cout<<"\n\n";
		cout<<"\t\t\t *==============���繫��ϵͳ=============*\n\n\n";
		cout<<"\t\t\t *=======================================*\n";
		cout<<"\t\t\t|  * - * - * - * - * - * - * - * - * - *  |\n";
		cout<<"\t\t\t| *                                     * |\n";
		cout<<"\t\t\t| |          [1]   �����˻�             | |\n";
		cout<<"\t\t\t| *                                     * |\n";
		cout<<"\t\t\t| |          [2]   ע���˻�             | |\n";
		cout<<"\t\t\t| *                                     * |\n";
		cout<<"\t\t\t| |          [3]   �˳�/��ֵ            | |\n";
		cout<<"\t\t\t| *                                     * |\n";
		cout<<"\t\t\t| |          [4]   �˳�ϵͳ             | |\n";
		cout<<"\t\t\t| *                                     * |\n";
		cout<<"\t\t\t|  * - * - * - * - * - * - * - * - * - *  |\n\n\n";
		cout<<"��ѡ��(1-4):";
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
	printf("���Ѿ���ȫ�˳�ϵͳ!(��������رս���)\n\n\t��ӭ�����ٴ�ʹ��!\n\n");
	getch();
}
void System :: Create_Account_menu(void){
	int status_flag = 1; 
	while (status_flag){
		cout<<"��ת��";
		cout<<"..";Sleep(100);		
		cout<<"..";Sleep(100);
		cout<<"..";Sleep(100); 
		system("cls") ;
		cout<<"\n\n";
		cout<<"\t\t\t *================�����˻�===============*\n\n\n";
		cout<<"\t\t\t *=======================================*\n";
		cout<<"\t\t\t|  * - * - * - * - * - * - * - * - * - *  |\n";
		cout<<"\t\t\t| *                                     * |\n";
		cout<<"\t\t\t| |          [1]   ������ʦ             | |\n";
		cout<<"\t\t\t| *                                     * |\n";
		cout<<"\t\t\t| |          [2]   ����ѧ��             | |\n";
		cout<<"\t\t\t| *                                     * |\n";
		cout<<"\t\t\t| |          [3]   ���Ǽ���             | |\n";
		cout<<"\t\t\t| *                                     * |\n";
		cout<<"\t\t\t| |          [4]   �����ϼ�             | |\n";
		cout<<"\t\t\t| *                                     * |\n";
		cout<<"\t\t\t|  * - * - * - * - * - * - * - * - * - *  |\n\n\n";
		cout<<"��ѡ��(1-4):";
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
			cout<<"���ڷ����ϼ�";
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
		cout<<"��������������:"<<endl;
		cin>>s_name;
		string s_id;
		cout<<"���������Ĺ��ţ�"<<endl;
		cin>>s_id;		
		ifstream fin("Teacher_Message.txt", std::ios::in);
		char line[1024]={0};
		string f_name = "", f_id = "", f_sex = "", f_college = "";
		bool In_Message=false;
		while(fin.getline(line, sizeof(line))){
			stringstream word(line);
			word >> f_name >> f_id >> f_sex >> f_college;
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
		string accout_name = "", accout_id = "", accout_sex = "", accout_college = "", accout_password = "";
		bool Account_Message = false;		
		while(fin2.getline(line2, sizeof(line2)))
		{
			stringstream word2(line2);
			word2 >> accout_name >> accout_id >> accout_sex >> accout_college >> accout_password;
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
			cout<<"\07�˻���Ϣ��ƥ�䣡������ע�ᣡ\n";
			cout<<"�����������ע��\n\n";
			getch();				
		} else{
			cout<<"\07��ID�ѱ�ע�ᣡ������ע�ᣡ\n";
			cout<<"�����������ע��\n\n";
			getch();
		}
	}

	while(true){
		system("cls");
		fflush(stdin);
		string s_password;
		cout<<"��������������:"<<endl;
		s_password = get_password();
		string s_password_verify;
		cout<< endl << "��ȷ����������:"<<endl;
		s_password_verify = get_password();	
		cout<<endl; 
		if(s_password == s_password_verify) {
			ofstream outfile;
		    outfile.open("Teacher_Account_Message.txt", ios::app); 
		    if(!outfile.is_open ())
		        cout << "Open file failure" << endl;
		    outfile << r_name << " " << r_id << " " << r_sex << " " << r_college << " " << s_password << " 0" << endl;  
		    outfile.close();
		    cout<<"\07�û������ɹ���"<<endl; 
		    Sleep(500);
			break;					
		} else{
			cout<<"\07�����������벻һ�£�����������";
			cout<<"�������������֤����\n\n";
			getch();
		} 
	}

}

void System :: Create_Student(void){
	string r_name = "", r_id = "", r_sex = "", r_college = "", r_money = "0";
	bool flag = false;
	while(true)
	{
		system("cls");
		fflush(stdin);
		string s_name; 
		cout<<"��������������:"<<endl;
		cin>>s_name;
		string s_id;
		cout<<"����������ѧ��:"<<endl;
		cin>>s_id;		
		ifstream fin("Student_Message.txt", std::ios::in);
		char line[1024]={0};
		string f_name = "", f_id = "", f_sex = "", f_college = "";
		bool In_Message=false;
		while(fin.getline(line, sizeof(line))){
			stringstream word(line);
			word >> f_name >> f_sex >> f_id >> f_college;
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
		string accout_name = "", accout_id = "", accout_sex = "", accout_college = "", accout_password = "";
		bool Account_Message = false;		
		while(fin2.getline(line2, sizeof(line2)))
		{
			stringstream word2(line2);
			word2 >> accout_name >> accout_sex >> accout_id >> accout_college >> accout_password;
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
			cout<<"\07�˻���Ϣ��ƥ�䣡������ע�ᣡ\n";
			cout<<"�����������ע��\n\n";
			getch();				
		} else{
			cout<<"\07��ID�ѱ�ע�ᣡ������ע�ᣡ\n";
			cout<<"�����������ע��\n\n";
			getch();
		}
	}

	while(true){
		system("cls");
		fflush(stdin);
		string s_password;
		cout<<"��������������:"<<endl;
		s_password = get_password();
		string s_password_verify;
		cout<< endl << "��ȷ����������:"<<endl;
		s_password_verify = get_password();	
		cout<<endl; 
		if(s_password == s_password_verify) {
			ofstream outfile;
		    outfile.open("Student_Account_Message.txt", ios::app); 
		    if(!outfile.is_open ())
		        cout << "Open file failure" << endl;
		    outfile << r_name << " " << r_sex << " " << r_id << " " << r_college << " " << s_password << " 0 0.0" <<endl;  
		    outfile.close();
		    cout<<"\07�û������ɹ���"<<endl; 
		    Sleep(500);
			break;					
		} else{
			cout<<"\07�����������벻һ�£�����������";
			cout<<"�������������֤����\n";
			getch();
		} 
	}
}

void System :: Create_Teacher_Fam(){
	string r_name = "", r_id = "", r_sex = "", r_money = "0";
	bool flag = false;
	while(true)
	{
		system("cls");
		fflush(stdin);
		string s_name; 
		cout<<"��������������:"<<endl;
		cin>>s_name;		
		string s_id;
		cout<<"���������ļ�����ţ�"<<endl;
		cin>>s_id;						
		ifstream fin("Teacher_Fam_Message.txt", std::ios::in);
		char line[1024]={0};
		string f_name = "", f_sex = "", f_id = "";
		bool In_Message=false;
		while(fin.getline(line, sizeof(line))){
			stringstream word(line);
			word >> f_name >> f_sex >> f_id;
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
		string accout_name = "", accout_id = "", accout_sex = "", accout_money = "", account_times = "", accout_password = "";
		bool Account_Message = false;		
		while(fin2.getline(line2, sizeof(line2)))
		{
			stringstream word2(line2);
			word2 >> accout_name >> accout_sex >> accout_id >> accout_money >> account_times >> accout_password;
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
			cout<<"\07�˻���Ϣ��ƥ�䣡������ע�ᣡ\n";
			cout<<"�����������ע��\n\n";
			getch();				
		} else{
			cout<<"\07��ID�ѱ�ע�ᣡ������ע�ᣡ\n";
			cout<<"�����������ע��\n\n";
			getch();
		}
	}

	while(true){
		system("cls");
		fflush(stdin);
		string s_password;
		cout<<"��������������:"<<endl;
		s_password = get_password();
		string s_password_verify;
		cout<< endl << "��ȷ����������:"<<endl;
		s_password_verify = get_password();	
		cout<<endl; 
		if(s_password == s_password_verify) {
			ofstream outfile;
		    outfile.open("Teacher_Fam_Account_Message.txt", ios::app); 
		    if(!outfile.is_open ())
		        cout << "Open file failure" << endl;
		    outfile << r_name << " " << r_sex << " " << r_id << " 0.0 0 " << s_password << endl;  
		    outfile.close();
		    cout<<"\07�û������ɹ���"<<endl; 
		    Sleep(500);
			break;					
		} else{
			cout<<"\07�����������벻һ�£�����������";
			cout<<"�������������֤����\n";
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
			cout << endl << "���벻����20λ,��������" <<endl;
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
		cout<<"\n��ת��";
		cout<<"..";Sleep(100);		
		cout<<"..";Sleep(100);
		cout<<"..";Sleep(100); 
		system("cls") ;
		cout<<"\n\n";
		cout<<"\t\t\t *================ע���˻�===============*\n\n\n";
		cout<<"\t\t\t *=======================================*\n";
		cout<<"\t\t\t|  * - * - * - * - * - * - * - * - * - *  |\n";
		cout<<"\t\t\t| *                                     * |\n";
		cout<<"\t\t\t| |          [1]   ������ʦ             | |\n";
		cout<<"\t\t\t| *                                     * |\n";
		cout<<"\t\t\t| |          [2]   ����ѧ��             | |\n";
		cout<<"\t\t\t| *                                     * |\n";
		cout<<"\t\t\t| |          [3]   ���Ǽ���             | |\n";
		cout<<"\t\t\t| *                                     * |\n";
		cout<<"\t\t\t| |          [4]   �����ϼ�             | |\n";
		cout<<"\t\t\t| *                                     * |\n";
		cout<<"\t\t\t|  * - * - * - * - * - * - * - * - * - *  |\n\n\n";
		cout<<"��ѡ��(1-4):";
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
			cout<<"���ڷ����ϼ�";
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
		cout<<"��������������:"<<endl;
		cin>>s_name; 
		string s_id;
		cout<<"���������Ĺ��ţ�"<<endl;
		cin>>s_id;		
		
		ifstream fin(Filename, std::ios::in);
		char line[1024]={0};
		string f_name = "", f_id = "", f_sex = "", f_college = "", f_password = "", f_times = ""; 
		bool In_Message=false;
		int number = 0;
		
		while(fin.getline(line, sizeof(line))){
			number++;
			stringstream word(line);
			word >> f_name >> f_id >> f_sex >> f_college >> f_password >> f_times;
			while(s_name == f_name && s_id == f_id){
				system("cls");
				fflush(stdin);
				cout<<"��������������:"<<endl;
				string tmp_password = get_password();
				if(f_password == tmp_password){
					DelLineData(Filename, number);
					In_Message = true;
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
			cout<<"\07\n�û�ע���ɹ���"<<endl; 
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
		cout<<"��������������:"<<endl;
		cin>>s_name;
		string s_id;
		cout<<"����������ѧ�ţ�"<<endl;
		cin>>s_id;		
		ifstream fin(Filename, std::ios::in);
		char line[1024]={0};
		string f_name = "", f_id = "", f_sex = "", f_college = "", f_password = "", f_times = "", f_money = "";
		bool In_Message=false;
		int number = 0;
		while(fin.getline(line, sizeof(line))){
			number++;
			stringstream word(line);
			word >> f_name >> f_sex >> f_id >> f_college >> f_password >> f_times >> f_money;
			while(s_name == f_name && s_id == f_id){
				system("cls");
				fflush(stdin);
				cout<<"��������������:"<<endl;
				string tmp_password = get_password();
				if(f_password == tmp_password){
					DelLineData(Filename, number);
					In_Message = true;
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
			cout<<"\07\n�û�ע���ɹ���"<<endl; 
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
		cout<<"��������������:"<<endl;
		cin>>s_name; 
		string s_id;
		cout<<"���������ļ�����ţ�"<<endl;
		cin>>s_id;		
		ifstream fin(Filename, std::ios::in);
		char line[1024]={0};
		string f_name = "", f_id = "", f_sex = "", f_money = "", f_times = "", f_password = "";
		bool In_Message=false;
		int number = 0;
		
		while(fin.getline(line, sizeof(line))){
			number++;
			stringstream word(line);
			word >> f_name >> f_sex >> f_id >> f_money >> f_times >> f_password;
			while(s_name == f_name && s_id == f_id){
				system("cls");
				fflush(stdin);
				cout<<"��������������:"<<endl;
				string tmp_password = get_password();
				if(f_password == tmp_password){
					DelLineData(Filename, number);
					In_Message = true;
					break;
				}
			}
			if(In_Message == true){
				cout<<"\07\n�û�ע���ɹ���"<<endl; 
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

string System :: CharToStr(char * contentChar){
	string tempStr;
	for (int i=0;contentChar[i]!='\0';i++)
	{
		tempStr+=contentChar[i];
	}
	return tempStr;
}
void System :: DelLineData(string fileName, int lineNum){
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

void System :: Get_On_Bus_And_Deposit_menu(Bus& bus1, Bus& bus2){
	int status_flag = 1; 
	while (status_flag){
		cout<<"��ת��";
		cout<<"..";Sleep(100);		
		cout<<"..";Sleep(100);
		cout<<"..";Sleep(100); 
		system("cls") ;
		cout<<"\n\n";
		cout<<"\t\t\t *===============�˳�/��ֵ===============*\n\n\n";
		cout<<"\t\t\t *=======================================*\n";
		cout<<"\t\t\t|  * - * - * - * - * - * - * - * - * - *  |\n";
		cout<<"\t\t\t| *                                     * |\n";
		cout<<"\t\t\t| |          [1]   ��˳���             | |\n";
		cout<<"\t\t\t| *                                     * |\n";
		cout<<"\t\t\t| |          [2]   �˻���ֵ             | |\n";
		cout<<"\t\t\t| *                                     * |\n";
		cout<<"\t\t\t| |          [3]   �����ϼ�             | |\n";
		cout<<"\t\t\t| *                                     * |\n";
		cout<<"\t\t\t|  * - * - * - * - * - * - * - * - * - *  |\n\n\n";
		cout<<"��ѡ��(1-3):";
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
			cout<<"���ڷ����ϼ�";
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
		cout<<"��ת��";
		cout<<"..";Sleep(100);		
		cout<<"..";Sleep(100);
		cout<<"..";Sleep(100); 
		system("cls") ;
		cout<<"\n\n";
		cout<<"\t\t\t *================��Ҫ�˳�===============*\n\n\n";
		cout<<"\t\t\t *=======================================*\n";
		cout<<"\t\t\t|  * - * - * - * - * - * - * - * - * - *  |\n";
		cout<<"\t\t\t| *                                     * |\n";
		cout<<"\t\t\t| |          [1]   ������ʦ             | |\n";
		cout<<"\t\t\t| *                                     * |\n";
		cout<<"\t\t\t| |          [2]   ����ѧ��             | |\n";
		cout<<"\t\t\t| *                                     * |\n";
		cout<<"\t\t\t| |          [3]   ���Ǽ���             | |\n";
		cout<<"\t\t\t| *                                     * |\n";
		cout<<"\t\t\t| |          [4]   �����ϼ�             | |\n";
		cout<<"\t\t\t| *                                     * |\n";
		cout<<"\t\t\t|  * - * - * - * - * - * - * - * - * - *  |\n\n\n";
		cout<<"��ѡ��(1-4):";
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
			cout<<"���ڷ����ϼ�";
			cout<<"..";Sleep(100);		
			cout<<"..";Sleep(100);
			cout<<"..";Sleep(100); 
			system("cls");
			status_flag = 0;
		}	
	}	
}

void System :: People_Get_On_Bus(Bus& bus1, Bus& bus2, int ch){ //��ʦ��Ϣ��֤ 
	time_t timep;
	struct tm *p;
	time (&timep);
	p=gmtime(&timep);
	int sec_time = p->tm_sec + (p->tm_min) * 60 + (8+p->tm_hour) * 60 * 60;
	if(sec_time<28800 || sec_time>=100000){										//64800 
		cout<<"���ճ�����ͣ��"<<endl;
		cout<<"����8��Ϊ��һ�೵������18��Ϊ���һ�೵"<<endl;
		cout<<"��������ط���\n";
		getch();		 
	}	
	else{
		cout<<"��ѡ����Ŀǰ��λ��:"<<endl;
		cout<<"[1]��ѧ¥  [2]����  ��ѡ��(1-2)��"<<endl;
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
		cout<<" *============================================����1��Ϣ=============================================*\n\n\n";
		bus1.Show_Status();
		cout<<" *============================================����2��Ϣ=============================================*\n\n\n";
		bus2.Show_Status();
		double bus1_place = bus1.Get_place(), bus2_place = bus2.Get_place();
		if(bus1_place>my_place){
			cout<<"\n���Ѵ������\n"<<endl;
		} else if(bus1_place>=my_place-0.1 && bus1_place<my_place){
			cout<<"\n����������վ�������ĵȴ�\n"<<endl;
		} else if(fabs(bus1_place-my_place) < 0.02){
			
			cout<<"\n�������ڵ�ǰվ��\n"<<endl;
			cout<<"\n *====================================================================================*\n\n\n";
			bool status1 = bus1.Get_Status(), status2 = bus2.Get_Status();
			if(status1&&status2){
//				Teacher_Get_On_Bus_Check();
				if((this->*Function_Get_On_Bus_pointer[ch])(bus1, bus2)){
					cout<<"\n������δ��Ա�����ϳ�"<<endl;						//����Ƿ���Ǯ�ϳ� 
					cout<<"��ѡ����:"<<endl;
					cout<<"[1]����һ  [2]������  ��ѡ��(1-2)��"<<endl;
					char choice = getch();
					while(choice!='1'&&choice!='2'){
						choice = getch();		
					}
					if(choice == '1'){
						bus1.Get_On_One_Person();
					} else{
						bus2.Get_On_One_Person();
					}
				}

			} else if(status1 && (!status2)){
				(this->*Function_Get_On_Bus_pointer[ch])(bus1, bus2);
				cout<<"����������Ա�����ϵ�һ����";
				bus1.Get_On_One_Person();
			} else if((!status1) && status2){
				(this->*Function_Get_On_Bus_pointer[ch])(bus1, bus2);
				cout<<"����һ����Ա�����ϵڶ�����";
				bus2.Get_On_One_Person();
			} else{
				cout<<"������������Ա����ȴ���һ���";
			}	
				
		} else{
			cout<<"\n������������"<<fabs(bus1_place-my_place)<<"km\n"<<endl; 
		}	
		cout<<"��������ط���\n";
		getch();	
	}
}
bool System :: Teacher_Get_On_Bus_Check(Bus& bus1, Bus& bus2){
	string Filename = "Teacher_Account_Message.txt";
	while(true){
		system("cls");
		fflush(stdin);
		cout<<" *============================================����1��Ϣ=============================================*\n\n\n";
		bus1.Show_Status();
		cout<<" *============================================����2��Ϣ=============================================*\n\n\n";
		bus2.Show_Status();
		string s_name; 
		cout<<"��������������:"<<endl;
		cin>>s_name; 
		string s_id;
		cout<<"���������Ĺ��ţ�"<<endl;
		cin>>s_id;		
		
		ifstream fin(Filename, std::ios::in);
		char line[1024]={0};
		string f_name = "", f_id = "", f_sex = "", f_college = "", f_password = "", f_times = "";
		bool In_Message=false;
		int number = 0;
		
		while(fin.getline(line, sizeof(line))){
			number++;
			stringstream word(line);
			word >> f_name >> f_id >> f_sex >> f_college >> f_password >> f_times;
			while(s_name == f_name && s_id == f_id){
				Teacher teacher(f_name, f_id, f_sex, f_college, f_password, f_times);
				system("cls");
				fflush(stdin);
				cout<<"��������������:"<<endl;
				string tmp_password = get_password();
				if(f_password == tmp_password){
					f_times = teacher.Teacher_Times_Plus();
					DelLineData(Filename, number);
					ofstream outfile;
					outfile.open(Filename, ios::app); 
					outfile << f_name << " " << f_id << " " << f_sex << " " << f_college << " " << f_password <<" " << f_times << endl; 
					outfile.close(); 
					In_Message = true;
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
		} else{
			cout<<"�û���Ϣ����,�����������"<<endl;
			getch();
		}
	}
	return true;
} 

bool System :: Student_Get_On_Bus_Check(Bus& bus1, Bus& bus2)	{
	bool target = true;
	bool target2 = true;
	string Filename = "Student_Account_Message.txt";
	while(true){
		system("cls");
		fflush(stdin);
		cout<<" *============================================����1��Ϣ=============================================*\n\n\n";
		bus1.Show_Status();
		cout<<" *============================================����2��Ϣ=============================================*\n\n\n";
		bus2.Show_Status();
		string s_name; 
		cout<<"��������������:"<<endl;
		cin>>s_name; 
		string s_id;
		cout<<"����������ѧ�ţ�"<<endl;
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
			double check_money = atof(f_money.c_str());
			if(s_name == f_name && s_id == f_id && check_money < 2.0){
				target = false;
				cout<<"�˻�����2.0Ԫ�����ֵ"<<endl;
				cout<<"�����������"<<endl;
				getch(); 
				In_Message = true;
				target2 = false;
				break;
			}
			while(s_name == f_name && s_id == f_id){
				Student student(f_name, f_sex, f_id, f_college, f_password, f_times, f_money);
				system("cls");
				fflush(stdin);
				cout<<"��������������:"<<endl;
				string tmp_password = get_password();
				if(f_password == tmp_password){
					f_times = student.Student_Times_Plus();
					f_money = student.Stuent_Money_Decrease();
					DelLineData(Filename, number);
					ofstream outfile;
					outfile.open(Filename, ios::app); 
					outfile << f_name << " " << f_sex << " " << f_id << " " << f_college << " " << f_password <<" " << f_times << " "  << f_money <<endl; 
					outfile.close(); 
					if(check_money<7.0){
						cout<<"��ǰ�˻�����5.0Ԫ���뾡���ֵ"<<endl;
						cout<<"�����������";
						getch();
					}
					In_Message = true;
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
		} else{
			if(target2 == true){
				cout<<"�û���Ϣ����,�����������"<<endl;
				getch();
			}
		}
	}	
	return target;
}

bool System :: Teacher_Fam_Get_On_Bus_Check(Bus& bus1, Bus& bus2)	{
	bool target = true;
	bool target2 = true;
	string Filename = "Teacher_Fam_Account_Message.txt";
	while(true){
		system("cls");
		fflush(stdin);
		cout<<" *============================================����1��Ϣ=============================================*\n\n\n";
		bus1.Show_Status();
		cout<<" *============================================����2��Ϣ=============================================*\n\n\n";
		bus2.Show_Status();
		string s_name; 
		cout<<"��������������:"<<endl;
		cin>>s_name; 
		string s_id;
		cout<<"���������ļ����ţ�"<<endl;
		cin>>s_id;		
		
		ifstream fin(Filename, std::ios::in);
		char line[1024]={0};
		string f_name = "", f_sex = "", f_id = "", f_money = "", f_times = "", f_password = "";
		bool In_Message=false;
		int number = 0;
		
		while(fin.getline(line, sizeof(line))){
			number++;
			stringstream word(line);
			word >> f_name >> f_sex >> f_id >> f_money >> f_times >> f_password;
			double check_money = atof(f_money.c_str());
			if(s_name == f_name && s_id == f_id && check_money < 2.0){
				target = false;
				cout<<"�˻�����2.0Ԫ�����ֵ"<<endl;
				cout<<"�����������"<<endl;
				getch(); 
				In_Message = true;
				target2 = false;
				break;
			}
			while(s_name == f_name && s_id == f_id){
				Teacher_Fam teacher_fam(f_name, f_sex, f_id, f_money, f_times, f_password);
				system("cls");
				fflush(stdin);
				cout<<"��������������:"<<endl;
				string tmp_password = get_password();
				if(f_password == tmp_password){
					bool flag = false;
					if(teacher_fam.Get_Times()<=20){
						flag = true;
						f_times = teacher_fam.Teacher_Fam_Times_Plus();
						DelLineData(Filename, number);
						ofstream outfile;
						outfile.open(Filename, ios::app); 
						outfile << f_name << " " << f_sex << " " << f_id << " " << f_money <<" " << f_times << " " << f_password  <<endl; 
						outfile.close();
						In_Message = true;
						break;
					} else{
						flag = true;
						f_times = teacher_fam.Teacher_Fam_Times_Plus();
						f_money = teacher_fam.Teacher_Fam_Money_Decrease();
						DelLineData(Filename, number);
						ofstream outfile;
						outfile.open(Filename, ios::app); 
						outfile << f_name << " " << f_sex << " " << f_id << " " << f_money <<" " << f_times << " " << f_password  <<endl; 
						outfile.close(); 
						if(check_money<7.0 && flag){
							cout<<"\07����ʾ������ǰ�˻�����5.0Ԫ���뾡���ֵ"<<endl;
						}
						In_Message = true;
						break;
					}

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
		} else{
			if(target2 == true){
			cout<<"�û���Ϣ����,�����������"<<endl;
			getch();
			}
		}
	} 
	return target;
}

void System :: Deposit(){
	int status_flag = 1; 
	while (status_flag){
		cout<<"��ת��";
		cout<<"..";Sleep(100);		
		cout<<"..";Sleep(100);
		cout<<"..";Sleep(100); 
		system("cls") ;
		cout<<"\n\n";
		cout<<"\t\t\t *================��Ҫ��ֵ===============*\n\n\n";
		cout<<"\t\t\t *=======================================*\n";
		cout<<"\t\t\t|  * - * - * - * - * - * - * - * - * - *  |\n";
		cout<<"\t\t\t| *                                     * |\n";
		cout<<"\t\t\t| |          [1]   ����ѧ��             | |\n";
		cout<<"\t\t\t| *                                     * |\n";
		cout<<"\t\t\t| |          [2]   ���Ǽ���             | |\n";
		cout<<"\t\t\t| *                                     * |\n";
		cout<<"\t\t\t| |          [3]   �����ϼ�             | |\n";
		cout<<"\t\t\t| *                                     * |\n";
		cout<<"\t\t\t|  * - * - * - * - * - * - * - * - * - *  |\n\n\n";
		cout<<"��ѡ��(1-3):";
		char status_choice = getch();
		while(status_choice!='1'&&status_choice!='2'&&status_choice!='3'){
  			status_choice = getch();		
		}
		cout<<status_choice;
		fflush(stdin);
		system("cls");

		if (status_choice == '1'){
			(this->*People_Deposit_pointer[0])();
		} else if (status_choice == '2'){
			(this->*People_Deposit_pointer[1])();	
		} else if (status_choice == '3'){
			cout<<"���ڷ����ϼ�";
			cout<<"..";Sleep(100);		
			cout<<"..";Sleep(100);
			cout<<"..";Sleep(100); 
			system("cls");
			status_flag = 0;
		}	
		
	}	
}

void System :: ModifyLineData(char* fileName, int lineNum, char* lineData)
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
 
	//д���ļ�
	ofstream out;
	out.open(fileName);
	out.flush();
	out<<strFileData;
	out.close();
}

void System :: Student_Deposit(){
	string Filename = "Student_Account_Message.txt";
	bool sign = true;
	while(sign == true){
		system("cls");
		fflush(stdin);
		string s_name; 
		cout<<"��������������:"<<endl;
		cin>>s_name; 
		string s_id;
		cout<<"����������ѧ�ţ�"<<endl;
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
					cout<<"��������������"<<endl;
					string input_password = get_password();
					if(input_password == f_password){
						double dep; 
						cout<<"\n���������ĳ�ֵ��"<<endl;
						cin>>dep;
						string m = student.Student_Deposit(dep);
						string new_inputline = f_name +" "+ f_sex +" "+ f_id +" "+ f_college +" "+ f_password +" "+ f_times +" "+ m; 
						char* chr1 = const_cast<char*>(Filename.c_str());
						char* chr2 = const_cast<char*>(new_inputline.c_str());
						ModifyLineData(chr1, number, chr2);
						cout<<"\07��ֵ�ɹ�"<<endl; 
						Sleep(300);
						break;
					} else{
						
						cout<<"\n������󣬰����������"<<endl;
						getch();
					}
				}
			}
		}
	} 
	if(sign == true){
		cout<<"�����ڵ�ǰ�˻��У������������"<<endl;
		getch();
	}
	
}

void System :: Teacher_Fam_Deposit(){
	string Filename = "Teacher_Fam_Account_Message.txt";
	bool sign = true;
	while(sign == true){
		system("cls");
		fflush(stdin);
		string s_name; 
		cout<<"��������������:"<<endl;
		cin>>s_name; 
		string s_id;
		cout<<"����������ѧ�ţ�"<<endl;
		cin>>s_id;
		
		ifstream fin(Filename, std::ios::in);
		char line[1024]={0};
		string f_name = "", f_sex = "", f_id = "", f_money = "", f_times = "", f_password = "";
		bool In_Message=false;
		int number = 0;	
		while(fin.getline(line, sizeof(line))){
			number++;
			stringstream word(line);
			word >> f_name >> f_sex >> f_id >> f_money >> f_times >> f_password;
			if(f_name == s_name && f_id == s_id){
				Teacher_Fam teacher_fam(f_name, f_sex, f_id, f_money, f_times, f_password);
				sign = false;
				while(true){
					system("cls");
					fflush(stdin);
					cout<<"��������������"<<endl;
					string input_password = get_password();
					if(input_password == f_password){
						double dep; 
						cout<<"\n���������ĳ�ֵ��"<<endl;
						cin>>dep;
						string m = teacher_fam.Teacher_Fam_Deposit(dep);
						string new_inputline = f_name +" "+ f_sex +" "+ f_id +" "+ m +" "+ f_times +" "+ f_password; 
						char* chr1 = const_cast<char*>(Filename.c_str());
						char* chr2 = const_cast<char*>(new_inputline.c_str());
						ModifyLineData(chr1, number, chr2);
						cout<<"\07��ֵ�ɹ�"<<endl; 
						Sleep(300);
						break;
					} else{
						
						cout<<"\n������󣬰����������"<<endl;
						getch();
					}
				}
			}
		}
	} 
	if(sign == true){
		cout<<"�����ڵ�ǰ�˻��У������������"<<endl;
		getch();
	}
	
}

int main(){
	System s;
	s.System_open();
	
	return 0;
}

