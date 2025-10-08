#include <iostream>
#include <string>
#include <cctype>
using namespace std;
// Declaration of functions
void storeditems(); 
void adminlogin();
bool adminlogincheck(string adminname, string password);
void adminmenu();
void additemtostore();
void deleteitemfromstore();
void updateitem();
void viewallitem();
void usermenu();
void additemtocart();
void removeitemfromcart();
void clearcart();
void viewcart();
void calculatetotal();
string tolower(string str) {  // conversion of string into lowercase
    for (char &c : str) {
        c = tolower(c);
    }
    return str;
}
struct Item{ // structure of item
	string name;
	float price;
	int quantity;
};

const int max_item=100;// globle initialization
int itemcount=0;
Item store[max_item];

struct Cartitem { // structure of cart
    string name;
    float price;
    int quantity;
};
const int max_cart = 100; // globle initialization
Cartitem cart[max_cart];
int cartcount = 0;
					//main function
int main() {
	storeditems();										
	string role;
	cout<<"------- Welcome to grocery store -------\n";	
	while(true){
		cout<<"Enter role (admin/user)";cin>>role;
		if(role=="user"){											//check role for user
			usermenu();
			break;
		}
		else if(role=="admin"){										//check role for admin
			adminlogin();
			break;
		}
		else{
			cout<<"\nInvalid role.Please enter again:\n";				//invalid role
		}
	}
	system("PAUSE");
	return 0;
}
void adminlogin(){               	 //admin login page
	string adminname,password;
	cout<<"\n----- Login Page -----\n\n";
	cout<<"Enter Admin name:";cin>>adminname;
	cout<<"Enter Password:";cin>>password;
	if (adminlogincheck(adminname,password)){
		adminmenu();
	}
	else{
		cout<<"Login failed exiting...";
	}
}
bool adminlogincheck(string adminname, string password){   //admin login checker
	return (adminname=="admin" && password =="admin123");
}
			//admin menu
void adminmenu(){		
	int choise;
	while(true){
		cout<<"\n----- Admin Menu -----\n";
		cout<<"\nenter '1' for additemtostore \nenter '2' for deleteitemfromstore \n"
		"enter '3' for updateitem \nenter '4' for viewallitem \nenter '5'for exit\n";
		cin>>choise;
		if(choise==1){
			additemtostore();
		}
		else if(choise==2){
			deleteitemfromstore();
		}
		else if(choise==3){
			updateitem();
		}
		else if(choise==4){
			viewallitem();
		}
		else if(choise==5){
			cout << "Exit admin menu...\n";
			break;	
		}
		else{
			cout<<"Invalid choise.Please enter valid choise";
		}
	}
}
void additemtostore(){ // function of add item to store

	if(itemcount >=max_item){
		cout<<"Store is full!\n";
		return;
	}
	cout<<"enter item name to add to store: ";
	cin.ignore();getline(cin,store[itemcount].name);
	
	cout<<"enter item price: ";cin>>(store[itemcount].price);
	cout<<"enter item quantity: ";cin>>(store[itemcount].quantity);
	itemcount++;
	cout<<"item added to store successfully!...\n";
}
void deleteitemfromstore(){ //function to delete item from store
	if(itemcount==0){
		cout << "Store is empty!\n";
		return;
	}
	string item_name;
	cout<<"enter item name to delete from store:";cin.ignore();getline(cin,item_name);
	item_name=tolower(item_name);
	for(int i=0;i < itemcount;i++){
		if(tolower(store[i].name)==item_name){
			for(int j=i;j<itemcount-1;j++){
				store[j]=store[j+1];
			}
		itemcount--;
		cout<<"item deleted from the store successfully!...\n";
		return;
		}
	}
	cout<<"item not found.\n"; 
}
void updateitem(){ // function of update item
	string item_name;
	cout<<"enter item name to update :";
	cin.ignore();getline(cin, item_name);
	item_name = tolower(item_name);
	for(int i=0;i<itemcount;i++){
		if(tolower(store[i].name)==item_name){
			cout << "Current price: " << store[i].price << "\n";
            cout << "Current quantity: " << store[i].quantity << "\n";
			cout<<"enter new price: ";cin>>store[i].price;
			cout<<"enter new quantity: ";cin>>store[i].quantity;
			cout<<"item is updated successfully!...\n";
			return;
		}
	}
	cout<<"item not found.\n";
}
void viewallitem(){ // function of view all items 
	if(itemcount==0){
		cout<<"store is empty \n";
		return;
	}
	cout<<"\n----- Items in Store ----- \n\n";
	for(int i=0;i<itemcount;i++){
		cout<<i+1<<". Name: "<<store[i].name<<"  | Price: Rs "<<store[i].price<<"  | Quantity: "<<store[i].quantity<<endl;
	}
}

//user menu
void usermenu(){	
	int choise;
	while(true){
		cout<<"\n----- User Menu -----\n";
		cout<<"\nenter '1' to view items in store \nenter '2' for additemtocart "
		"\nenter '3' for removeitemfromcart \n"			
		"enter '4' for clearcart \nenter '5' for viewcart" 
		"\nenter '6' for calculatetotal \nenter '7'for exit\n";
		cin>>choise;
		if(choise==1){
			viewallitem();
		}
		else if(choise==2){
			additemtocart();
		}
		else if(choise==3){
			removeitemfromcart();
		}
		else if(choise==4){
			clearcart();
		}
		else if(choise==5){
			viewcart();
		}
		else if(choise==6){
			calculatetotal();
		}
		else if(choise==7){
			cout << "Exit user menu...\n";
			break;	
		}
		else{
			cout<<"invalid choise.please enter valid choise\n";
		}
	}
}
void additemtocart(){ // add item to cart  function
	string item_name;
	int neededquantity;
	cout<<"enter item name to add to cart: ";cin.ignore();getline(cin,item_name);
	item_name= tolower(item_name);
	for(int i=0;i<itemcount;i++){
		if(tolower(store[i].name)==item_name){
			cout<<"enter quantity to add to cart: ";cin>>neededquantity;
			if(store[i].quantity>=neededquantity){
				cart[cartcount].name=store[i].name;
				cart[cartcount].price=store[i].price;
				cart[cartcount].quantity=neededquantity;
				cartcount++;
				store[i].quantity-=neededquantity;
				cout << "Item added to cart successfully!\n";
			}else{
				cout<<"Not enough stock in store .Available: "<<store[i].quantity<<endl;
			}
		return;		
		}
	}
    cout << "Item not found in store.\n";
}
void removeitemfromcart(){  //remove item from cart function
	if(cartcount==0){
		cout << "cart is empty!\n";
		return;
	}
	string item_name;
	cout<<"enter item name to remove from cart: ";cin.ignore();getline(cin,item_name);
	item_name= tolower(item_name);
	for(int i=0;i < cartcount;i++){
		if(tolower(cart[i].name) == item_name){
			for (int j=0; j<itemcount; j++) {
                if (tolower(store[j].name) == item_name) {
                    store[j].quantity += cart[i].quantity;
                    break;
                }
            }
			for(int j=i;j<cartcount-1;j++){
				cart[j]=cart[j+1];
			}
		cartcount--;
		cout<<"item removed  from the cart successfully!...\n";
		return;
		}
	}
	cout<<"item not found.\n"; 
}
void clearcart(){ //clear cart function
	if(cartcount==0){
		cout<<"cart is already empty.\n";
		return;
	}
	for(int i=0;i<cartcount;i++){
		for(int j=0;j<itemcount;j++){
			if(tolower(store[j].name) == tolower(cart[i].name)){
				store[j].quantity+=cart[i].quantity;
				break;
			}
		}
	}
	cartcount=0;
	cout<<"cart is cleared successfully!...\n";
}
void viewcart(){ // view cart function
	if(cartcount==0){
		cout<<"cart is empty \n";
		return;
	}
	cout<<"\n----- Items in cart ----- \n";
	for(int i=0;i<cartcount;i++){
		cout<<i+1<<". Name:"<<cart[i].name<<"\t| Price: Rs "<<cart[i].price<<"  | Quantity: "<<cart[i].quantity<<endl;
	}
}
void calculatetotal(){   // bill calculation function
	if(cartcount==0){
		cout<<"cart is empty.nothing to calculate. \n";
		return;
	}
	float total=0;
	for(int i=0;i<cartcount;i++){
		total+=cart[i].price*cart[i].quantity;
	}
	cout<<"Total amount of your cart is: Rs "<<total<< "\n";
}
void storeditems() {   //  stored items function
    store[0] = {"Sugar", 50.0, 20};
    store[1] = {"Salt", 30.0, 55};
    store[2] = {"Oil", 250.0, 15};
    store[3] = {"Chicken", 540.0, 115};
    store[4] = {"Soy Sauce", 60.0, 42};
    store[5] = {"Onion", 150.0, 20};
    store[6] = {"Powdered Sugar", 270.0, 25};
    store[7] = {"Eggs", 300.0, 200};
    store[8] = {"Bread", 110.0, 35};
    store[9] = {"Milk", 190.0, 12};
    itemcount = 10;
}
