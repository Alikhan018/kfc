#include <iostream>
#include <fstream>
using namespace std;
class EmployeeStartUp{
	public:
	EmployeeStartUp(){
		cout << "Hey! Set Up you data and start the cash counter of KFC\n";
		cout << "Dont forgert to be nice with the customer and do get a feedback from them after your order\n";
	}
};
class Logo{
	public:
		Logo(){
			for(int i=0;i<11;i++)
				cout << " ";
			for(int i=0;i<20;i++)
				cout << "*";
			cout << endl;
			for(int i=0;i<14;i++)
				cout << " ";
			cout << "WELCOME TO KFC\n";
			for(int i=0;i<11;i++)
				cout << " ";
			for(int i=0;i<20;i++)
				cout << "*";
			cout << endl;		
		}
};
class Person{
	protected:
	string name;
	public:
	Person(){
		cout << "Enter you name\n"; cin >> name;
	}
	virtual void setName(string n) = 0;
	virtual string getName() = 0;
};
class Customer : public Person {
	private:
	public:
	Customer(){}
	Customer(string name){
		setName(name);
	}
	void setName(string n){
		name = n;
	}
	string getName(){
		return name;
	}
};
class Employee:public EmployeeStartUp,public Person{
	protected:
	string id;
	public:
	Employee(){
		cout << "Enter your employee id : "; cin >> id; 
	}
	Employee(string id,string name){
		this->id = id;
		this->name = name;
	}
	void setName(string n){
		name = n;
	}
	void setId(string i){
		id = i;
	}
	string getName(){
		return name;
	}
	string getId(){
		return id;
	}
};
class Cashier:public Employee{
	char x;
	public:
	Cashier() {
		while (true) {
			cout << "Have you completed your set up?(y/n): ";
			cin >> x;
			if (x == 'Y' || x == 'y') {
				cout << "Great lets start the business now\n";
				break;
			}
            Cashier();
            break;
		}
	}

	Cashier(string a,string b):Employee(a,b){
		while(true){
			cout << "Have you completed your set up?(y/n): ";
			cin >> x;
			if(x=='Y' || x=='y'){
				cout << "Great lets start the business now\n";
				break;
			}
			else{
				continue;
			}
		}
	}
	char getX(){
		return x;
	}
};
class Menu{
	public:
		Menu(){
			
		}
		virtual void display() {
			cout << "error";
		}
		virtual int getTotal() {
			cout << "error";
			return 0;
		}
};
class Drinks:public Menu{
	string* name;
	int drinksAmount;
	public:
		Drinks(){
			cout << "How many drinks would you like to have\n";
			cin >> drinksAmount;
			name = new string[drinksAmount];
			int i=0;
			while(i<drinksAmount){
				cout << "Which Drink would you like to have:\n"
					<< "1.Pepsi\n2.Fanta\n3.Sprite\n";
				cin >> name[i];
				if(name[i]=="1"){
					name[i]="Pepsi";
				}
				else if(name[i]=="2"){
					name[i]="Fanta";
				}
				else if(name[i]=="3"){
					name[i]="Sprite";
				}
				else{
					cout << "Invalid choice made\n";
					continue;
				}
				i++;
			}
		}
		int getDrinksAmount(){
			return drinksAmount;
		}
		void display(){
			for(int i=0;i<drinksAmount;i++){
				cout << name[i] << " ";
			}
			cout << endl;
		}
		int getTotal(){
			return 220*drinksAmount;
		}
};
class Fries:public Menu{
	int fries;
	public:
		Fries(){
				cout << "How many fries would you like to have\n";
				cin >> fries;
			}
		int getFries(){
			return fries;
		}
		void display(){
			cout << getFries() << " fries\n";
		}
		int getTotal(){
			return 220*fries;
		}
};
class Burgers:public Menu{
	string* name;
	int burgersAmount;
	int k,z,m,kty,zs;
	public:
		Burgers(){
			k=0,z=0,m=0,kty=0,zs=0;
			cout << "How many burgers would you like to have\n";
			cin >> burgersAmount;
			name = new string[burgersAmount];
			int i=0;
			while(i<burgersAmount){
				cout << "Which burger would you like to have(Type burger number):\n";
				cout << "1.Krunch\n2.Zinger\n3.Mighty\n4.Kentucky\n5.ZigerStacker\n";
				cin >> name[i];
				if(name[i]=="1"){
					name[i]="Krunch";
					k++;
				}
				else if(name[i]=="2"){
					name[i]="Zinger";
					z++;
				}
				else if(name[i]=="3"){
					name[i]="Mighty";
					m++;
				}
				else if(name[i]=="4"){
					name[i]="Kentucky";
					kty++;
				}
				else if(name[i]=="5"){
					name[i]="ZingerStacker";
					zs++;
				}
				else{
					cout << "Invalid choice selected\n";
					continue;
				}
				i++;
			}
		}
		int getBurgersAmount(){
			return burgersAmount;
		}
		void display(){
			for(int i=0;i<burgersAmount;i++){
				cout << name[i] << " ";
			}
			cout << endl;
		}
		int getK(){
			return k;
		}
		int getZ(){
			return z;
		}
		int getM(){
			return m;
		}
		int getZs(){
			return zs;
		}
		int getKty(){
			return kty;
		}	
		int getTotal(){
			return ((350*k)+(560*z)+(710*m)+(660*zs)+(750*kty));
		}
};
class Deals:public Menu{
	string* deal;
	int dealAmount;
	int ff1,ff2,ff3;
	public:
		Deals(){
			ff1=0,ff2=0,ff3=0;
			cout << "How many deals would you like to have\n";
			cin >> dealAmount;
			deal = new string[dealAmount];
			int i = 0;
			while(i<dealAmount){
				cout << "Which deal(s) would you like to have\n"
					<< "1.Family Fest 1(4 Krunch Burgers with drinks)\n" 
					<< "2.Family Fest 2(4 Zinger Burgers with drinks)\n" 
					<< "3.Family Fest 3(4 Zinger Burgers with drinks and fries)\n";
					cin >> deal[i];
					if(deal[i]=="1"){
						deal[i] = "Family Fest 1";
						ff1++;
					}
					else if(deal[i]=="2"){
						deal[i] = "Family Fest 2";
						ff2++;
					}
					else if(deal[i]=="3"){
						deal[i] = "Family Fest 3";
						ff3++;
					}
					else{
						cout << "Invalid choice\n";
					}
					i++;
			}
		}
		int getF1(){
			return ff1;
		}
		int getF2(){
			return ff2;
		}
		int getF3(){
			return ff3;
		}
		void display(){
			for(int i=0;i<dealAmount;i++)
				cout << deal[i] << " ";
			cout << endl;
		}
		int getTotal(){
			return ((2050*ff1)+(2550*ff2)+(3050*ff3));
		}
};
class Bill{
	int totalBill;
	public:
		Bill(){
			totalBill = 0;
		}
		int calculateBill(Menu** m,int size){
			for(int i = 0;i<size; i++){
				totalBill+=m[i]->getTotal();
			}
			return totalBill;
		}
		int addBill(int a){
			totalBill+=a;
			return totalBill;
		}
		int getBill(){
			return totalBill;
		}
};
class Order{
	protected:
	int charges;
	string type;
	public:
	Order(){
		charges = 0;
		type="";
	}
	virtual void setType(string x)=0;
	virtual string getType()=0;
	virtual void setCharges(int x)=0;
	virtual int getCharges()=0;
	virtual ~Order(){}
};
class DineIn: public Order{
	public:
	DineIn(){
		cout << "Order type set to Dine In\n";
		setType("Dine-In");
		setCharges(100);
	}
	void setType(string x) override {
		type=x;
	}
	string getType() override {
		return type;
	}
	void setCharges(int x) override {
		charges=x;
	}
	int getCharges() override {
		return charges;
	}
};
class Takeaway: public Order{
	public:
	Takeaway(){
		cout << "Order type set to Takeaway\n";
		setType("Takeaway");
		setCharges(50);
	}
	void setType(string x) override
	{
		type = x;
	}
	string getType() override
	{
		return type;
	}
	void setCharges(int x) override
	{
		charges = x;
	}
	int getCharges() override
	{
		return charges;
	}
};
class Payment{
	public:
	Payment(){}
	virtual void makePayment(Bill b,Order* o)=0;
};
class Cash:public Payment{
	public:
		Cash(){}
		void makePayment(Bill b, Order* o){
			cout << "Your bill of " << b.getBill() << " is paid and cleared\n";
			if(o->getType()=="Dine-In"){
				cout << "Please have a seat your order will be shortly served\n";
			}
			else{
				cout << "Your takeaway order will be sent shortly.\n";
			}
		}
};
class Card:public Payment{
	public:
		void makePayment(Bill b, Order *o)
		{
			string x;
			bool flag = false;
			ifstream checkCard("Banks.txt");
			cout << "Enter your card cvv number\n";
			cin >> x;
			string str;
			while(checkCard>>str){
				if (x==str){
					cleared(b,o);
					flag = true;
				}
			}
			if(flag == false){
				cout << "Your card is declined\n";
			}

		}
		void cleared(Bill b,Order* o){
			cout << "Your bill of " << b.getBill() << " is paid and cleared\n";
			if (o->getType() == "Dine-In"){
				cout << "Please have a seat your order will be shortly served\n";
			}
			else
			{
				cout << "Your takeaway order will be sent shortly.\n";
			}
		}
};
class Exit{
    public:
    Exit(Cashier &c){
        cout << c.getName() << " closed the cash counter \n ID: " << c.getId() <<endl;
    }
};
class FeedBack{
    string str;
    public:
    FeedBack(){
        cin.ignore();
        cout << "\nGive us some feedback\n";
        getline(cin,str);
    }
    string getstr(){
        return str;
    }
};
int main(){
	Cashier c;
	Logo l;
	Menu* f[100];
	int size = 0;
	int choice; 
	char response = 'y';
	int i=0;
	Customer cus;
	while(response=='y' || response=='Y'){
		size++;
		cout << "What would you like to have:\n"
			<< "1.Burgers\n2.Fries\n3.Drinks\n4.Deals\n5.Exit\n";
		cin >> choice;
		if(choice==1){
			f[i] = new Burgers();
			
		}
		else if(choice==2){
			f[i] = new Fries();
		}
		else if(choice==3){
			f[i] = new Drinks();
		}
		else if(choice==4){
			f[i] = new Deals();
		}
		else if(choice==5){
			break;
		}
		else{
			cout << "Invalid choice\n";
			continue;
		}
		cout << "Order placed is \n";
		f[i]->display();
		cout << "Would you like to have anything else?(y/n)\n";
		cin >> response;
		i++;
	}
	Bill bill;
	char ch;
	cout << "Would you like to dine in or take away(d/t)? : \n";
    Order* o = NULL;
	while (true){
		cin >> ch;
		if (ch == 'd' || ch == 'D'){
			o = new DineIn();
			break;
		}
		else if (ch == 'T' || ch == 't'){
			o = new Takeaway();
			break;
		}
		else{
			cout << "invalid choice please tell correctly would you like to dine in or take away(d/t) :\n";
		}
	}
	cout << "Following order is placed\n";
	for (int i = 0; i < size; i++)
	{
		f[i]->display();
	}
	cout << endl << "Your bill is : " << bill.calculateBill(f, size) << endl;
	cout << "Charges of your " << o->getType() << " are " << o->getCharges() << endl; 
	cout << "Your total bill is : ";
	bill.addBill(o->getCharges());
	cout << bill.getBill();
	cout << "How would you like to pay your bill:\n1.Cash\n2.Card\n";
	while(true){
		cin >> choice;
		if(choice==1){
			Cash cash;
			cash.makePayment(bill,o);
			break;
		}
		else if(choice==2){
			Card card;
			card.makePayment(bill,o);
			break;
		}
		else{
			cout<<"Please enter a valid option:-\n1.Cash\n2.Card\n";
		}
	}
    FeedBack fdb;
    Exit e(c);
	cout << "Thank you for visiting us hope to see you again\n";
}
