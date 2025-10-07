#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;
class vector{
	private:
		double i, j, k, l , m, n;
	public:
		vector(): i(0), j(0), k(0), l(0), m(0), n(0) {}
		vector(double i_, double j_, double k_, double l_, double m_, double n_): i(i_), j(j_), k(k_), l(l_), m(m_), n(n_) {}
		
		void get_a(){
			cout<<"Enter the attributes of vector A."<<endl;
			cout<<"Vector A"<<endl;
			cout<<"i:"; cin>>i;
			cout<<"\nj:"; cin>>j;
			cout<<"\nk:"; cin>>k;
			
		}
		void get_b(){
			
			cout<<"Enter the attributes of vector B."<<endl;
			cout<<"\nl: "; cin>>l;
			cout<<"\nm: "; cin>>m;
			cout<<"\nn: "; cin>>n;
		}
		void show_a(){
			cout<<"Vector A"<<endl;
			cout<<"<"<<i<<", "<<j<<", "<<k<<">"<<endl;
			
		}
		void show_b(){
			cout<<"vector B"<<endl;
			cout<<"<"<<l<<", "<<m<<", "<<n<<">"<<endl;
		}
		void mod_a(){
			int magnitude= sqrt(i*i+j*j+k*k);
			cout<<"The magnitude of vector A: "<<magnitude<<endl;
			}
		void mod_b(){
			int magnitude= sqrt(l*l+m*m+n*n);
			cout<<"The magnitude of vector B: "<<magnitude<<endl;
		}
		void dot(){
			int product= (i*l+j*m+k*n);
			cout<<"The dot product of vector A and vector B is "<<product<<endl;
		}	
		void cross(){
			double cx= j*n-k*m;
			double cy= -(k*l - i*n);
			double cz= i*m-j*l;
			cout<<"The Cross product of vector A and vector B is <"<<cx<<" "<<cy<<" "<<cz<<">"<<endl;
		}	
		void add(){
			double cx= i+l;
			double cy= j+m;
			double cz= k+n;
			cout<<"<"<<cx<<" "<<cy<<" "<<cz<<">"<<endl;
		}	
		void subtract(){
			double cx= i-l;
			double cy= j-m;
			double cz= k-n;
			cout<<"<"<<cx<<" "<<cy<<" "<<cz<<">"<<endl;
		}
		
		
		  
		
	
};
int main(){
	vector v;
	int choice;
	cout<<"______VECTOR OPERATION PROGRAM______"<<endl;
	v.get_a();
	v.get_b();
	
	do{
		cout<<"\n__Choose your operation__"<<endl;
		cout<<"1. Add (A+B)."<<endl;
		cout<<"2. Subtract (A-B)."<<endl;
		cout<<"3. Dot product (A.B)."<<endl;
		cout<<"4. Cross product (AxB)."<<endl;
		cout<<"5. Magnitude of vector A."<<endl;
		cout<<"6. Magnitude of vector B."<<endl;
		cout<<"7. Exit"<<endl;
		cin>>choice;
		switch(choice){
			case 1:
				v.add();
				break;
			case 2:
				v.subtract();
				break;
			case 3:
				v.dot();
				break;
			case 4:
				v.cross();
				break;
			case 5:
				v.mod_a();
				break;
			case 6:
				v.mod_b();
				break;
			case 7:
				cout<<"Exiting program."<<endl;
				break;
			default:
			cout<<"Invalid input. Select between 1-7. "<<endl;	
			 
				
				
				
				
				
				}
				
		
	
	}while(choice !=7);
	return 0;
	
	
}

