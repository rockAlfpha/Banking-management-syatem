#include<iostream>
using namespace std;

class account{
private:
	string name;
	int accno;
	string atype;
	
public:
    void getAccountDetails(){
    	cout<<"Enter Customer Name: ";
    	cin>>name;
    	cout<<endl;
    	cout<<"Enter Account Number: ";
    	cin>>accno;
    	cout<<endl;
    	cout<<"Enter Account Type: ";
    	cin>>atype;  
    }
    
    void displayDetails(){
    	cout<<"Customers Name: "<<name<<endl;
    	cout<<"Account Number: "<<accno<<endl;
    	cout<<"Account Type: "<<atype<<endl;
    }

};

class current_account : public account{
private:
	float balance;
	
public:
	void c_display(){
		cout<<"Balance: "<<balance<<endl;
	
	}
	
	void c_deposit(){
		float deposit;
		cout<<"Enter amount to Deposit: ";
		cin>>deposit;
		balance += deposit;
	}
	
	void c_withdraw(){
		float withdraw;
		cout<<"Balance: "<<endl;
		cout<<"Enter amount to withdraw: ";
		cin>>withdraw;
		if(balance > 1000){
			balance -= withdraw;
			cout<<"Balance Amount After Withdraw: "<<balance;
		
		}else{
			cout<<"Insufficient Balance"<<endl;
		
		}
	}
};

class saving_account : public account{
private:
	float sav_balance;
public:
	
	void s_display(){
		cout<<"Balance: "<<sav_balance;
	}
	
	void s_deposit(){
		float deposit, interest;
		cout<<"Enter amount to Deposite: ";
		cin>>deposit;
		sav_balance += deposit;
		interest = (sav_balance*2)/100;
		sav_balance += interest;
	}
	
	void s_withdraw(){
	float withdraw;
		cout<<"Balance: "<<sav_balance<<endl;
		cout<<"Enter amount to Withdraw: ";
		cin>>withdraw;
		if(sav_balance > 500){
			sav_balance -= withdraw;
			cout<<"Balance Amount After Withdraw: "<<sav_balance;
		}else{
			cout<<"\n Insifficient Balance"<<endl;
		
		}
	}
};


int main(){
	current_account c1;
	saving_account s1;
	
	char type;
	cout<<"Enter S for saving customer and C for current a/c customer: ";
	cin>>type;
	int choice;
	if(type=='s' || type=='S'){
		s1.getAccountDetails();
		while(1){
			cout<<"Choose Your Choice"<<endl;
			cout<<"1) Deposite"<<endl;
			cout<<"2) Withdraw"<<endl;
			cout<<"3) Display Balance"<<endl;
			cout<<"4) Display with full Details"<<endl;
			cout<<"5) Exit"<<endl;
			cout<<"Enter Your Choice: ";
			cin>>choice;
			switch(choice){
				case 1:
					s1.s_deposit();
					break;
				case 2:
					s1.s_withdraw();
					break;
				case 3:
					s1.s_display();
					break;
				case 4:
					s1.displayDetails();
					s1.s_display();
					break;
				case 5:
					goto end;
				default:
					cout<<"Entered choice is Invalid,\"TRY AGAIN\"";
			} 
		}
	}else if(type == 'c' || type == 'C'){
		c1.getAccountDetails();
		while(1){
			cout<<"Choose Your Choice"<<endl;
			cout<<"1) Deposit"<<endl;
			cout<<"2) Withdraw"<<endl;
			cout<<"3) Display Balance"<<endl;
			cout<<"4) Display with full Details"<<endl;
			cout<<"5) Exit"<<endl;
			cout<<"Enter Your Choice: ";
			cin>>choice;
			switch(choice){
			case 1:
				c1.c_deposit();
				break;
			case 2:
				c1.c_withdraw();
				break;
			case 3:
				c1.c_display();
				break;
			case 4:
				c1.c_display();
				break;
			default:
				cout<<"Entered choice is Invalid, \"TRY AGAIN\"";
			}
		}
	}else{
		cout<<"Invalid Account Selection";
	}
	end:
		cout<<"Thank You for Banking with us...";
		return 0;
}
