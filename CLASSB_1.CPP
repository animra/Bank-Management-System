#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<time.h>
#include<dos.h>

class Account{
protected:
	char name[32];
	char account_no[20];
	float balance;
	char* createdAt;
	char* lastTransaction;

public:
///// Menus////////
//int mainMenu();
Account(){}
~Account();

void print()
{
 //	createAccount
	cout<<"\nName : "<<name;
	cout<<"\nAccount No. : "<<account_no;
	cout<<"\nBalance : "<<balance;
	cout<<"\nCreate At : "<<createdAt;
	cout<<"\nLast Transaction : "<<lastTransaction<<endl;
}
char* getAccount_no()
{
	return account_no;
}
char* getName()
{
	return name;
}
int getBalance()
{
	return balance;
}
void createAccount();
//int transactionMenu();

///////// Transaction /////////
void withDrawal();
void deposit();
//void checkBalance();
};
class SavingAccount: public Account
{
	float profit;
public:
SavingAccount(){}
void Apply_Profit()
	{
	profit = ((2*100)/balance);
	balance = balance + profit;
	}
void print()
	{
	Account::print();
	cout<<"\n Last Profit : "<<profit;
	}
};
class User{
//	char name[50];
	SavingAccount a2;
public:
User(){}
char* getName()
{
	return a2.getName();
}
char* getAccount_no()
{
	return a2.getAccount_no();
}
int getBalance()
{
   return a2.getBalance();
}
void createAccount()
{
	a2.createAccount();
}
void deposit()
{
	a2.deposit();
}
void withDrawal()
{
	a2.withDrawal();
}
void Apply_Profit()
{
	a2.Apply_Profit();
}
void print()
{
	a2.print();
}
};



class GUI{

public:
	static int mainMenu();
	static int transactionMenu();

};
void main(void)
{
	User accounts[5];
	int totalAccounts = 0;
	clrscr();
	int userInput;
	while(1){
		userInput = GUI::mainMenu();
		if(userInput==3){
			break;
		}else{
			switch(userInput){
				case 1:
				{
					while(totalAccounts<5){

						accounts[totalAccounts].createAccount();
						totalAccounts++;
						char ch='0';
						if(totalAccounts<5){

							cout<<"\n Press 1 to create another account : ";
							cout<<"\n Press 0 to go back (Main Menu) : ";
							do{
								ch = getch();
							}while(ch!='1' && ch!='0');

						}
						else{
							cout<<"\n Press any key to go back (Main Menu) ";

						}
						if(ch=='0'){
							break;
						}

					}
					if(totalAccounts>4){
						clrscr();
						cout<<"\n\n Accounts reachs at its maximum limit!";
						getch();
					}
				}
				break;
				case 2:
				{
					if(totalAccounts>0){

						int ch = 1;
						while(ch!=4)
						{
							ch = GUI::transactionMenu();
							clrscr();
							switch(ch){

								case 1:
								{
									char acc_no[20];                                             									int accountfound = 0;
									cout<<"\n\n==================== DEPOSIT =========== ";
									do{
										cout<<"\n\n Enter account number : ";
										gets(acc_no);

										for(int i=0;i<5;i++){
											if(strcmp(acc_no,accounts[i].getAccount_no())==0){
												accountfound = 1;
											   accounts[i].deposit();
												break;
											}
										}


									}while(accountfound==0);
									if(accountfound==0){
										cout<<"\n Account not found, Again ";
									}
								}
								break;
								case 2:
								{
									char acc_no[20];
									int accountfound = 0;
									cout<<"\n\n==================== WITHDRAWAL =========== ";
									do{
										cout<<"\n\n Enter account number : ";
										gets(acc_no);
										for(int i=0;i<5;i++){
											if(strcmp(acc_no,accounts[i].getAccount_no())==0){
												accountfound = 1;
												accounts[i].withDrawal();
												break;
											}
										}
										if(accountfound==0){

											cout<<"\n Account not found, Again ";
										}

									}while(accountfound==0);
								}
								break;
								case 3:
								{
									char acc_no[20];
									int accountfound = 0;
									cout<<"\n\n==================== CHECK BALANCE =========== ";
									do{
										cout<<"\n\n Enter account number : ";
										gets(acc_no);
										for(int i=0;i<5;i++){
											if(strcmp(acc_no,accounts[i].getAccount_no())==0){
												accountfound = 1;
												//cout<<"\n\n Customer Name : "<<accounts[i].getName();
												//cout<<"\n Your account balance is : "<<accounts[i].getBalance();
												accounts[i].Apply_Profit();
												accounts[i].print();
												getch();
												break;
											}
										}
										if(accountfound==0){
											cout<<"\n Account not found, Again ";
										}

									}while(accountfound==0);
								}
								break;

							}

						}
					}
					else{
						cout<<"\n\n First create an account to make transaction!";
						getch();
					}

				}
				break;
			}
		}

	}

}
int GUI::mainMenu(){
	clrscr();
	char choice;
	cout<<"======================== UBL BANK SYSTEM =================";
	cout<<"\n\n\t\t Press 1 to create new account";
	cout<<"\n\n\t\t Press 2 to make transaction";
	cout<<"\n\n\t\t Press 3 to exit";
	cout<<"\n\n\t\t Enter your choice : ";
	cin>>choice;
	if(choice>='4'||choice<='0')
	{
	 cout<<"Wrong Input";
	 getch();
	 }
	 else
	 return choice-48;
}
int GUI::transactionMenu(){
   char choice;
   clrscr();
   cout<<"\n\n================ TRANSACTION MENU ================";
   cout<<"\n\n\t\t Press 1 to deposit";
   cout<<"\n\n\t\t Press 2 to withdrawal";
   cout<<"\n\n\t\t Press 3 to check balance";
   cout<<"\n\n\t\t Press 4 to go back (Main Menu)";
   cout<<"\n\n\t\t Enter your choice : ";
   do{
	cin>>choice;
	if(choice<'1' || choice>'4'){
		cout<<"\n Invalid choice\n Re-enter your choice : ";
	}
   }while(choice<'1' || choice>'4');

   return choice-48;
}
void Account::createAccount(){

	clrscr();
	cout<<"\n\n================ CREATE NEW ACCOUNT ============ ";
	cout<<"\n\n Enter customer name : ";
	gets(name);
	cout<<" Enter account number : ";
	gets(account_no);
	cout<<" Enter balance (at least 500) : ";
	cin>>balance;
	while(balance<500)
	{
		cout<<"\nYour minimum Deposit amount should be 500 ";
		cout<<"\nPlease re-enter your deposit amount  :  ";
		cin>>balance;
	}
	time_t seconds = time(NULL);
	struct tm* tBlock = localtime(&seconds);

	char*temp = asctime(tBlock);
	//cout<<"\n Created At length : "<<strlen(createdAt);
	createdAt = new char[strlen(temp)];
	strcpy(createdAt,temp);
	lastTransaction = new char[strlen(temp)];
	strcpy(lastTransaction , createdAt);


}
void Account::withDrawal(){
	int bal;
	cout<<"\n Customer Name : "<<name;
	cout<<"\n Account No.   : "<<account_no;
	cout<<"\n Enter amount to withdrawal : ";
	cin>>bal;
	while(bal>balance){
		cout<<"\n Your entered amount is greater than your balnce";
		cout<<"\n Please re-enter your amount to withdrawal : ";
		cin>>bal;
	}
	balance = balance - bal;
	cout<<"\n Your new balance is : "<<balance;
	time_t seconds = time(NULL);
	struct tm* tBlock = localtime(&seconds);

	char* temp = asctime(tBlock);

	strcpy(lastTransaction,temp);

	getch();

}
void Account::deposit(){
	int amount;
	cout<<"\n Customer Name : "<<name;
	cout<<"\n Account No.   : "<<account_no;
	cout<<"\n Enter amount to deposit : ";
	cin>>amount;
	while(amount<500)
	{
		cout<<"\nYour minimum Deposit amount should be 500 ";
		cout<<"\nPlease re-enter your deposit amount  :  ";
	cin>>amount;
	}
	balance = balance + amount;
	cout<<"\n Your new balance is : "<<balance;

	time_t seconds = time(NULL);
	struct tm* tBlock = localtime(&seconds);

	char* temp = asctime(tBlock);

	strcpy(lastTransaction,temp);
	getch();
}
Account::~Account(){
	delete [] createdAt;
	delete [] lastTransaction;
}