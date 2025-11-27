#include<stdlib.h>
#include<iostream>
using namespace std;
const int LEN=80;
class student{
	private:
		char school [LEN];
		char degree [LEN];
	public:
		void getstu(){
			cout<<"\n Enter the name of your school: "; cin>>school;
			cout<<"\n Enter your highest degre earned: "; cin>>degree;
	}
		void showstu(){
			cout<<"\n School: "<<school;
			cout<<"\n Degree: "<<degree;
	}
};
class employee{
	private:
		char name [LEN];
		unsigned long number;
	
	public:
		void getemp(){
			cout<<"\n Enter your name: "; cin>>name;
			cout<<"\n Enter your employee ID: "; cin >>number;
	}
		void showemp(){
			cout<<"\n Name: "<< name;
			cout<<"\n Employee's ID: "<<number;
	}	
};
class manager: private employee, private student{
	private:
		char title [LEN];
		int dues;
	public:
		void getman(){
			employee::getemp();
			cout<<"\nEnter your title: "; cin>>title;
			cout<<"\n Enter your dues: "; cin>>dues;
			student::getstu(); 
		}
		void showMan(){
			employee::showemp();
			cout<<"\n Title: "<<title;
			cout<<"\n Dues: "<<dues;
			student::showstu();
		}
		
};
class scientist : public employee, public student{
	private:
		int publications;
	public:
		void getScie(){
			employee::getemp();
			cout<<"\nEnter your publications: "; cin>>publications;
			student::getstu();
		}
		void showScie(){
			employee::showemp();
			cout<<"\nPublications: "<<publications;
			student::showstu();
		}
		
};
class labour: public employee{};

int main(){
	manager m1;    scientist s1, s2;   labour l1;
	cout<<"\n Enter the data for manager: "; m1.getman();
	cout<<"\n Enter the data for scientist 1: "; s1.getScie();
	cout<<"\n Enter the data for scientist 2: "; s2.getScie();
	cout<<"\n Enter the data for labour 1: "; l1.getemp();
	cout<<"\n Display the data.";
	cout<<"\n Data of manager 1: "; m1.showMan();
	cout<<"\n Data of scientist 1: "; s1.showScie();
	cout<<"\nData of scientist 2: "; s2.showScie();
	cout<<"\n Data of labour 1: "; l1.showemp();
	}
	






