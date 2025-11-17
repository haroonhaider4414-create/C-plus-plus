#include<iostream>
#include<stdlib.h>
using namespace std;
class Distance{
	private:
		const float MTF;
		int feet;
		float inches;
		
	public:
		Distance (): feet(0), inches(0), MTF(3.28){}
		
		Distance(float meters): MTF(3.28){
			float fltfeet=MTF*meters;
			feet= int (fltfeet);
			inches = 12* (fltfeet - feet);
			
		}
		Distance(int ft, float in): feet(ft), inches(in), MTF(3.28){}
		
		void get_dist(){
			cout<<"Enter the distance in Feet and inches."<<endl;
			cout<<"\n Feet: "; cin>>feet;
			cout<<"\n Inches: ";cin>>inches;
		} 
		void show_dist(){
			cout<<"\n Feet"<<feet<<"inches"<<inches<<endl;
		}
		operator float() const{
			float fracfeet = inches/12;
			fracfeet += static_cast<float>(fracfeet);
			return fracfeet/MTF;
		}
		
		
};







