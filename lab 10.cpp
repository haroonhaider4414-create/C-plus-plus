#include <iostream>
#include<windows.h>
using namespace std;

class electric_car {
public:
    int battery;

    electric_car() : battery(0) {}
    electric_car(int b) : battery(b) {}

    void getBtry() {
        cout << "\nEnter the battery level (1-100): ";
        cin >> battery;
    }

    void recharge() {
        while (battery < 100) {
            battery++;
            cout << "\nBattery: "<<battery;
            Sleep(100);
        }
        cout << "\nBattery is fully charged.";
    }

    void showBtry() {
        cout << "\nBattery: " << battery;
    }
};

class petrol_car {
public:
    float fuel;

    petrol_car() : fuel(0) {}

    void getFuel() {
        cout << "\nEnter the fuel level in litres (1-50): ";
        cin >> fuel;
    }

    void fill_up() {
        while (fuel < 50) {
            fuel += 0.5;
            cout << "\nTank fuel: "<<fuel;
            Sleep(100);
        }
        cout << "\nTank is full.";
    }
    void showFuel() {
        cout << "\nFuel: " << fuel << " litres";
    }
};
class hybrid_car : public electric_car, public petrol_car {
public:
    char Running_Mode;
    hybrid_car() : Running_Mode('b') {}
    void Switch_Mode(char mode) {
        if (mode == 'b' || mode == 'B') {
            Running_Mode = 'b';
            cout << "\nSwitched to Battery Mode.";
        }
        else if (mode == 'f' || mode == 'F') {
            Running_Mode = 'f';
            cout << "\nSwitched to Fuel Mode.";
        }
        else {
            cout << "\nInvalid mode!";
        }
    }

    void Run() {
        if (Running_Mode == 'b') {
            if (battery > 0) {
                battery -= 1;
                cout << "\nCar running on Battery. Battery -= 1";
            } else {
                cout << "\nBattery empty!";
            }
        }
        else if (Running_Mode == 'f') {
            if (fuel > 0) {
                fuel -= 0.5;
                cout << "\nCar running on Fuel. Fuel -= 0.5";
            } else {
                cout << "\nFuel empty!";
            }
        }
    }
};

int main() {
    hybrid_car h1;
    int choice;
     h1.getBtry();
     h1.getFuel();
    while(true){
    	

    	cout << "\nEnter your choice (0-4):";
    	cout << "\n0. Fill fuel";
    	cout << "\n1. Recharge battery";
    	cout << "\n2. Switch to battery mode";
    	cout << "\n3. Switch to fuel mode";
    	cout << "\n4. Run car\n";
    	cout<< "\n5. Exit.";

    	cin >> choice;

    	if (choice == 0) {
        	h1.fill_up();
    }
    	else if (choice == 1) {
        	h1.recharge();
    }
    	else if (choice == 2) {
        	h1.Switch_Mode('b');
    }
    	else if (choice == 3) {
        	h1.Switch_Mode('f');
    }
    	else if (choice == 4) {
        	h1.Run();
    }
    	else if(choice==5){
    		break;
	}

    cout << "\n";
    h1.showBtry();
    h1.showFuel();

    
	}

   
}






