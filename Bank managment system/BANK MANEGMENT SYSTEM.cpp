#include <iostream>
#include <fstream>
using namespace std;
char account_numbers[50][20];  
int initial_balance[50];
char account_store[50][50];
int current_index = 0;
int create_account(int size);
void Deposit();
void withdraw();
void display();
void saveData();
void loadData();
int main()
{
    int size = 50;
    int choice = 0;
    loadData();
    do {
        cout << "Bank Management System" << endl;
        cout << "1. Create Account" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Display account information" << endl;
        cout << "0.  save  and exit program" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
switch (choice) 
		{
        case 1:
            create_account(size);
            break;
        case 2:
            Deposit();
            break;
        case 3:
            withdraw();
            break;
        case 4:
            display();
            break;
        case 0:
            saveData();
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    } while (choice != 0);
   system("pause");
    return 0;
}
int create_account(int size)
{
    char account_name[50];
    cout << "Enter account holder name : ";
    cin.getline(account_name, 50);
    int i;
    for (i = 0; account_name[i] != '\0' && i < 50; ++i) 
	{
        account_store[current_index][i] = account_name[i];
    }
    account_store[current_index][i] = '\0';
    cin.ignore();
cout << "Enter account number : ";
    cin.getline(account_numbers[current_index], 20);
    int initial_balance_value;
    cout << "Enter initial balance : ";
    cin >> initial_balance_value;
    initial_balance[current_index] = initial_balance_value;
cout << "Account created successfully" << endl;
    ++current_index;
    saveData();
    return 0;
}
void Deposit()
{
    char user_account_number[20];
    cout << "Enter an account number : ";
    cin >> user_account_number;
    for (int i = 0; i < current_index; ++i) 
	{
        if (strcmp(user_account_number, account_numbers[i]) == 0) 
		{
            int deposit;
            cout << "Enter your deposit amount : ";
            cin >> deposit;
            initial_balance[i] += deposit;
            cout << "Deposit successful and new amount is : " << initial_balance[i] << endl;
            return;
        }
    }
    cout << "Account not found" << endl;
}
void withdraw()
{
    char user_account_number[20];
    cout << "Enter an account number : ";
    cin >> user_account_number;
    for (int i = 0; i < current_index; ++i) 
	{
        if (strcmp(user_account_number, account_numbers[i]) == 0) 
		{
            int withdraw_amount;
            cout << "Enter your withdraw amount : ";
            cin >> withdraw_amount;
            initial_balance[i] -= withdraw_amount;
            cout << "Withdraw successful and new amount is : " << initial_balance[i] << endl;
            return;
        }
    }
cout << "Account not found" << endl;
}
void display()
{
    char user_account_number[20];
    cout << "Enter an account number : ";
    cin >> user_account_number;
    for (int i = 0; i < current_index; ++i) 
	{
        if (strcmp(user_account_number, account_numbers[i]) == 0) 
		{
            cout << "Account information" << endl;
            cout << "Account holder name : " << account_store[i] << endl;
            cout << "Total amount : " << initial_balance[i] << endl;
            return;
        }
    }
cout << "Account not found" << endl;
}
void saveData()
{
    ofstream fout("bank_data.txt");
    if (!fout) 
	{
        cout << "Error opening file." << endl;
        return;
    }
for (int i = 0; i < current_index; ++i) 
{
        fout << account_numbers[i] << " " << initial_balance[i] << " " << account_store[i] << endl;
    }
    fout.close();
}
void loadData()
{
    ifstream fin("bank_data.txt");
    if (!fin) {
        cout << "No existing data." << endl;
        return;
    }
    while (fin >> account_numbers[current_index] >> initial_balance[current_index]) 
	{
        fin.get();  
		        fin.getline(account_store[current_index], 50);
        ++current_index;
    }
    fin.close();
}
