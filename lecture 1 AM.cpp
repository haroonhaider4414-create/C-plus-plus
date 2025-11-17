#include<iostream>
#include<stdlib.h>
using namespace std;
enum posneg { pos, neg};
class Distance{
	protected:
		int feet;
		float inches;
	public:
		Distance(): feet(0), inches(0){}
		Distance(int ft, float in) : feet(ft), inches(in){}
		void get(){
			cout<<"\nEnter the values of feet and inches.";
			cout<<"\n Feet: "; cin>>feet;
			cout<<"\n Inches: "; cin>>inches;
		}
		void show(){
			cout<<"\nFeet: "<<feet;
			cout<<"\nInches: "<<inches;
		}
};
 class DistSign : public Distance {
private:
    posneg sign;

public:
    DistSign() : Distance() {  
        sign = pos;             
    }
    DistSign(int ft, float in, posneg sg=pos): Distance(ft, in){
    	sign=sg;
	}
	void getdist(){
		Distance::get();
		char ch;
		cout<<"\nEnter the sign (+ or -) "; cin>>ch;
		sign=(ch == '+') ? pos : neg;
	}
	void showdist(){
		cout <<  ((sign == pos) ? "(+)" : "(-)");

		Distance::show();
	}
};
int main(){
	DistSign alpha;
	alpha.getdist();
	DistSign beta(11, 6.25);
	DistSign gamma(100, 4.54, neg);
	cout<<"\n Alpha = "; alpha.showdist();
	cout<<"\n Beta = "; beta.showdist();
	cout<<"\n Gamma = "; gamma.showdist();
	
	
}







