#include<iostream>
#include<stdlib.h>
#include<numeric>
using namespace std;
class Rational{
	private:
		int p; int q;
	public:
		Rational(): p(1), q(1){}
		Rational(int p_, int q_): p(p_), q(q_){}
		void set(int p_, int q_){
			p= p_;
			q=q_;}
		void get(){
			cout<<"Enter the values of p and q.";
			cout<<"\nP: "; cin>>p;
			cout<<"\nQ: "; cin>>q;
		}
		void show(){
			cout<<"\n"<<p<<"/"<<q<<endl;
		}
//		void gcd(){
//			int GCD = std::gcd(p, q); 
//            cout << "\nGCD: " << GCD << endl;
//		}	 
		
	
};




