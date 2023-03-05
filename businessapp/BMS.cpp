#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <time.h>
using namespace std;

void loadDatafromFile1();
int userCount = 0;
int accountnum = 0;
string username, password, role;
int loginaccountnumber;
float loginaccountbalance;
string usernames[100];
string passwords[100];
string roles[100];
string accounttypes[100];
float balances[100];
string phonenumbers[100];
string statuses[100];
int accountnumbers[100];

void header();
string firstinterface();
void viewUsers();
string pincheck(string password);
string checkRole(string username, string password);
string parsedata(string line, int feild);
bool signIn(string username, string password);
string admininterface();
bool alreadytakenpin(string newpin);
string checkaccounttype(string type);
bool checkstatus(string name, int accountnumber);
string phone_numbercheck(string number);
float minimum_balance(float balance, string type);
bool accountAlreadyexists(string name, string pin);
void storeinFile1(int accountnum, string username, string pin, string type, float balance, string phone);
void storeDatainArray(int accountnum, string name, string pin, string acctype, float balance, string phone);
void account_close(int accountnumber, string name, string pin);
void updatedatainfile1();
bool validnumber(int accountnum);
int checkNewAccountnumber();
bool checkaccountPresence(int accountnum, string pin);
void freezeAccount(int accountnum, string pin);
void searchuserdetails(string name, int accountnumber);
void updatinguserpersonalinfo(string name, int accountnumber, string newname, string newpin, int newbalance, string newtype, string newstatus, string newnumber);
void takevalidpin(string newpin);
string updateMenu();
bool alreadytakename(string name);
void updateName(string name, int accountnumber, string newname);
void updatePin(string name, int accountnumber, string newpin);
void updatebalance(string name, int accountnumber, float newbalance);
void updatetype(string name, int accountnumber, string newtype);
void updatestatus(string name, int accountnumber, string newstatus);
void updatephonenumber(string name, int accountnumber, string newnumber);
float checktotalmoney();
void taxonspecificClient(string name, int accountnumber, float percentofTax);
int userinterface();
void name_check(string name);
float clientcurrentBalance();

float transactionamounts[100];
string transactionaccounts[100];
string transactiontypes[100];
string transactiontimes[100];
string requestloanpoeple[100];
float requestloanamounts[100];
int requestloanaccounts[100];
int loanholderaccounts[100];
string loanholders[100];
float givenloanamounts[100];
int givenloandays[100];
string loantime[100];
int trans_count = 0;
int loan_req = 0;
int loan_count = 0;

void storeDatainfile2(float depositAmount, string currenttime, string transactiontype);
void loaddatafromfile2();
void addmoneyinaccount(float depositAmount);
void moneytransfer(float transfer_money);
int checkloginpersonaccountnumber();
float checkloginaccountbalnace();
void withdrawcash(float withdrawAmount);
void requestloans(float loan_amount, string pin, int accountnumber);
void loadloandatafromfile();
void storeloandetailsinfile(float loan_amount);
void updatedatainfile3();
void storedatainfile4();
void loaddatafromfile4();
bool phonenumbercheck(string phone);
bool checkname(string name);
bool checknameandaccount(string name, int accountnumber);
void showloanrequests();
void deleteloanrequest();
void viewloanholders();
bool checkpreviousloanrequest(int accountnumber);
int findrequestedloan(string name, int loanholderaccount);
bool checkvalidityofrequestloan(int accountnumber);
bool checkgivingtorequests(string name, int accountnumber);
bool checkagaingvingofloan(string name, int accountnumber);
void printsubMenu(string submenu);

main()
{
    loadDatafromFile1();
    loaddatafromfile2();
    loadloandatafromfile();
    loaddatafromfile4();
    string option = "";
    while (option != "2")
    {
        header();
        option = firstinterface();
        if (option == "1")
        {
            header();
            cout << "   Login Menu" << endl;
            cout << " ===================================================================" << endl;
            cout << " Enter your name:  ";
            cin.ignore();
            getline(cin, username);
            cout << " Enter your 4-digit security pin: ";
            cin >> password;
            password = pincheck(password);

            bool flag = signIn(username, password); // checking if user the username and password exits in the record
            if (flag == true)
            {
                role = checkRole(username, password); // identifying role of person
                if (role == "admin")
                {
                    string adminchoice = "";
                    while (adminchoice != "12")
                    {
                        header();
                        adminchoice = admininterface();
                        if (adminchoice == "1")
                        {
                            string name, pin, type, phone;
                            float balance;
                            string tempbalance;
                            header();
                            cout << endl;
                            string submenu = "Create Client Account";
                            printsubMenu(submenu);

                            cout << "  Enter name of client: ";
                            cin.ignore();
                            getline(cin, name);
                            name_check(name);
                            bool flagforname = alreadytakename(name);
                            if (flagforname == true)
                            {
                                cout << "  This username is already taken" << endl;
                                while (flagforname != false)
                                {
                                    cout << "  Enter name again: ";
                                    cin.ignore();
                                    getline(cin, name);
                                    name_check(name);
                                    flagforname = alreadytakename(name);
                                }
                            }
                            cout << "  Enter 4-digit pin for account: ";
                            cin >> pin;
                            pin = pincheck(pin);
                            // takevalidpin(pin);
                            bool ispresent = alreadytakenpin(pin);
                            if (ispresent == true)
                            {
                                cout << "  This pin is already taken." << endl;
                                while (ispresent != false)
                                {
                                    cout << "  Enter pin again: ";
                                    cin >> pin;
                                    ispresent = alreadytakenpin(pin);
                                }
                            }
                            cout << "  Enter type of account ( salary/ current): ";
                            cin >> type;
                            type = checkaccounttype(type);
                            cout << "  Enter starting balance of account: ";
                            cin >> tempbalance;
                            bool checkvalidnumber = phonenumbercheck(tempbalance);
                            if (checkvalidnumber == true)
                            {
                                while (checkvalidnumber != false)
                                {
                                    cout << "Enter balance again: ";
                                    cin >> tempbalance;
                                    checkvalidnumber = phonenumbercheck(tempbalance);
                                }
                            }
                            balance = stof(tempbalance);
                            balance = minimum_balance(balance, type);
                            cout << "  Enter phonenumber(without dashes): ";
                            cin >> phone;
                            bool isvalid = phonenumbercheck(phone);
                            if (isvalid == true)
                            {
                                while (isvalid == true)
                                {
                                    cout << "  Enter valid phone number: ";
                                    cin >> phone;
                                    isvalid = phonenumbercheck(phone);
                                }
                            }
                            phone = phone_numbercheck(phone);
                            bool flags = accountAlreadyexists(name, pin);
                            if (flags == false)
                            {
                                storeDatainArray(accountnum, name, pin, type, balance, phone); // storing data in array and creating a client's account
                                storeinFile1(accountnum, name, pin, type, balance, phone);
                                userCount++;
                                cout << endl
                                     << "  Account number " << accountnum << " successfully created! " << endl;
                                accountnum++;
                                cout << "  Press any key to continue..." << endl;
                                getch();
                            }
                            else if (flags == true)
                            {
                                cout << "already exits/ invalid" << endl;
                                cout << "Press any key to continue..." << endl;
                                getch();
                            }
                        }
                        if (adminchoice == "2")
                        {
                            string name, pin, tempaccountnumber;
                            int accountnumber;
                            header();
                            string submenu = "Delete Client Account";
                            printsubMenu(submenu);
                            cout << "  Enter name of account to close: ";
                            cin.ignore();
                            getline(cin, name);
                            cout << "  Enter pin: ";
                            cin >> pin;
                            pin = pincheck(pin);
                            cout << "  Enter account number: ";
                            cin >> tempaccountnumber;
                            bool checkvalid = phonenumbercheck(tempaccountnumber); // checking if account number contains only numbers
                            if (checkvalid == true)
                            {
                                while (checkvalid != false)
                                {
                                    cout << " Enter number again: ";
                                    cin >> tempaccountnumber;
                                    checkvalid = phonenumbercheck(tempaccountnumber);
                                }
                            }
                            accountnumber = stoi(tempaccountnumber);
                            // closing an account
                            bool check = accountAlreadyexists(name, pin);
                            if (check == true)
                            {
                                account_close(accountnumber, name, pin);
                                updatedatainfile1();
                                cout << endl
                                     << "  Account succesfully closed! ";
                            }
                            else
                            {
                                cout << " User does not exists! " << endl;
                                cout << " Press any key to go back..";
                            }
                            getch();
                        }
                        if (adminchoice == "3")
                        {
                            header();
                            string tempaccnumber;
                            int accountnum, days;
                            string pin;
                            string submenu = "Freeze Client Account";
                            printsubMenu(submenu);
                            cout << " Enter account number you want to freeze: ";
                            cin >> tempaccnumber;
                            bool checkvalid = phonenumbercheck(tempaccnumber);
                            if (checkvalid == true)
                            {
                                while (checkvalid != false) // checking if account number contains only numbers
                                {
                                    cout << " Enter number again: ";
                                    cin >> tempaccnumber;
                                    checkvalid = phonenumbercheck(tempaccnumber);
                                }
                            }
                            accountnum = stoi(tempaccnumber);
                            cout << " Enter account pin: ";
                            cin >> pin;
                            pincheck(pin);
                            bool flag = checkaccountPresence(accountnum, pin);
                            if (flag == true)
                            {
                                freezeAccount(accountnum, pin);
                                updatedatainfile1();
                            }
                            else
                            {
                                cout << " Account does not exists.." << endl;
                            }
                            cout << " Press any key to coninue... ";
                            getch();
                        }
                        if (adminchoice == "4")
                        {
                            string name;
                            int accountnumber;
                            header();
                            string submenu = "Search Client Account";
                            printsubMenu(submenu);
                            cout << "  Enter name:  ";
                            cin.ignore();
                            getline(cin, name);
                            cout << "  Enter account number: ";
                            cin >> accountnumber;
                            // searching a user's details
                            searchuserdetails(name, accountnumber);
                            cout << "Press any key to coninue... ";
                            getch();
                        }
                        if (adminchoice == "5")
                        {
                            int accountnumber;
                            string option, name, newname, newpin, newtype, newstatus, newnumber;
                            float newbalance;
                            string tempaccnumber, newtempaccpin, newtempaccbalance;
                            header();
                            string submenu = "Updating Client's Record";
                            printsubMenu(submenu);
                            cout << " Enter name:  ";
                            cin.ignore();
                            getline(cin, name);
                            cout << " Enter account number: ";
                            cin >> tempaccnumber;
                            bool checkvalid = phonenumbercheck(tempaccnumber);
                            if (checkvalid == true)
                            {
                                while (checkvalid != false) // checking if account number contains only numbers
                                {
                                    cout << " Enter number again: ";
                                    cin >> tempaccnumber;
                                    checkvalid = phonenumbercheck(tempaccnumber);
                                }
                            }
                            accountnumber = stoi(tempaccnumber);
                            bool flag = checknameandaccount(name, accountnumber);
                            if (flag == true)
                            {
                                // updating a user's deatils
                                option = updateMenu();
                                if (option == "1")
                                {
                                    cout << " Enter new name: ";
                                    cin.ignore();
                                    getline(cin, newname);
                                    bool flag = checkname(name);
                                    if (flag == false)
                                    {
                                        while (flag != true)
                                        {
                                            cout << " Enter valid name: ";
                                            cin >> name;
                                            flag = checkname(name);
                                        }
                                    }
                                    bool flagforname = alreadytakename(name);
                                    if (flagforname == true)
                                    {
                                        cout << "  This username is already taken" << endl;
                                        while (flagforname != false)
                                        {
                                            cout << "  Enter name again: ";
                                            cin >> name;
                                            flagforname = alreadytakename(name);
                                        }
                                    }
                                    updateName(name, accountnumber, newname);
                                }
                                else if (option == "2")
                                {
                                    cout << " Enter new pin: ";
                                    cin >> newtempaccpin;
                                    bool checkvalid = phonenumbercheck(newtempaccpin);
                                    if (checkvalid == true)
                                    {
                                        while (checkvalid != false) // checking if account number contains only numbers
                                        {
                                            cout << " Enter number again: ";
                                            cin >> newtempaccpin;
                                            checkvalid = phonenumbercheck(newtempaccpin);
                                        }
                                    }
                                    newpin = stoi(newtempaccpin);

                                    pincheck(newpin);
                                    takevalidpin(newpin);
                                    updatePin(name, accountnumber, newpin);
                                }
                                else if (option == "3")
                                {
                                    cout << "enter new account type: ";
                                    cin >> newtype;
                                    updatetype(name, accountnumber, newtype);
                                }
                                else if (option == "4")
                                {
                                    cout << "enter new balance: ";
                                    cin >> newtempaccbalance;
                                    bool checkvalid = phonenumbercheck(newtempaccbalance);
                                    if (checkvalid == true)
                                    {
                                        while (checkvalid != false) // checking if account number contains only numbers
                                        {
                                            cout << " Enter number again: ";
                                            cin >> newtempaccbalance;
                                            checkvalid = phonenumbercheck(newtempaccbalance);
                                        }
                                    }
                                    newbalance = stoi(newtempaccbalance);
                                    updatebalance(name, accountnumber, newbalance);
                                }
                                else if (option == "5")
                                {
                                    cout << "enter new status(freeze/running): ";
                                    cin >> newstatus;
                                    updatestatus(name, accountnumber, newstatus);
                                }
                                else if (option == "6")
                                {
                                    cout << "enter new phonenumber: ";
                                    cin >> newnumber;
                                    bool isvalid = phonenumbercheck(newnumber);
                                    if (isvalid == true)
                                    {
                                        while (isvalid == true)
                                        {
                                            cout << "  Enter valid phone number: ";
                                            cin >> newnumber;
                                            isvalid = phonenumbercheck(newnumber);
                                        }
                                    }
                                    phone_numbercheck(newnumber);
                                    updatephonenumber(name, accountnumber, newnumber);
                                }
                                else if (option == "a")
                                {
                                    cout << "Enter new name: ";
                                    cin.ignore();
                                    getline(cin, newname);
                                    bool flag = checkname(name);
                                    if (flag == false)
                                    {
                                        while (flag != true)
                                        {
                                            cout << " Enter valid name: ";
                                            cin >> name;
                                            flag = checkname(name);
                                        }
                                    }
                                    bool flagforname = alreadytakename(name);
                                    if (flagforname == true)
                                    {
                                        cout << "  This username is already taken" << endl;
                                        while (flagforname != false)
                                        {
                                            cout << "  Enter name again: ";
                                            cin >> name;
                                            flagforname = alreadytakename(name);
                                        }
                                    }
                                    cout << "Enter pin: ";
                                    cin >> newtempaccpin;
                                    pincheck(newpin);
                                    bool checkvalid = phonenumbercheck(newtempaccpin);
                                    if (checkvalid == true)
                                    {
                                        while (checkvalid != false) // checking if account number contains only numbers
                                        {
                                            cout << " Enter number again: ";
                                            cin >> newtempaccpin;
                                            checkvalid = phonenumbercheck(newtempaccpin);
                                        }
                                    }
                                    newpin = stoi(newtempaccpin);
                                    takevalidpin(newpin);
                                    cout << "Enter new account type: ";
                                    cin >> newtype;
                                    cout << "Enter new balance: ";
                                    cin >> newtempaccbalance;
                                    bool checkvalidity = phonenumbercheck(newtempaccbalance);
                                    if (checkvalidity == true)
                                    {
                                        while (checkvalid != false) // checking if account number contains only numbers
                                        {
                                            cout << " Enter number again: ";
                                            cin >> newtempaccbalance;
                                            checkvalidity = phonenumbercheck(newtempaccbalance);
                                        }
                                    }
                                    newbalance = stoi(newtempaccbalance);

                                    cout << "Enter status(freeze/unf): ";
                                    cin >> newstatus;
                                    cout << "Enter new phonenumber: ";
                                    cin >> newnumber;
                                    phone_numbercheck(newnumber);
                                    updatinguserpersonalinfo(name, accountnumber, newname, newpin, newbalance, newtype, newstatus, newnumber);
                                }
                                else
                                {
                                    cout << "Invalid choice!";
                                    getch();
                                    continue;
                                }
                                updatedatainfile1();
                                cout << "UPdated account details.. " << endl;
                                cout << "Press any key to continue...";
                                getch();
                            }
                            else
                            {
                                cout << "  Account doesnot exists!" << endl;
                                cout << "Press any key to continue";
                                getch();
                            }
                        }
                        if (adminchoice == "6")
                        {
                            string name;
                            header();
                            string submenu = "View Clients personal info";
                            printsubMenu(submenu);
                            cout << "Following are details of all clients: " << endl;
                            viewUsers();
                            cout << "Press any key to continue...";
                            getch();
                        }
                        if (adminchoice == "7")
                        {
                            string name, temploanaccnumber;
                            char choice;
                            float loan_amount;
                            int days, loanholderaccount;
                            header();
                            string submenu = "Give loan";
                            printsubMenu(submenu);

                            showloanrequests();
                            cout << "Do you want to give loan?(y/n) ";
                            cin >> choice;
                            if (choice == 'y')
                            {
                                cout << endl
                                     << " Enter account name whom you want to give loan: ";
                                cin.ignore();
                                getline(cin, name);
                                bool flag = checkname(name);
                                if (flag == false)
                                {
                                    while (flag != true)
                                    {
                                        cout << " Enter valid name: ";
                                        cin >> name;
                                        flag = checkname(name);
                                    }
                                }
                                cout << " Enter client's account number: ";
                                cin >> temploanaccnumber;
                                bool checkvalid = phonenumbercheck(temploanaccnumber);
                                if (checkvalid == true)
                                {
                                    while (checkvalid != false) // checking if account number contains only numbers
                                    {
                                        cout << " Enter number again: ";
                                        cin >> temploanaccnumber;
                                        checkvalid = phonenumbercheck(temploanaccnumber);
                                    }
                                }
                                loanholderaccount = stoi(temploanaccnumber);
                                bool valid1 = checkagaingvingofloan(name, loanholderaccount);
                                bool valid2 = checkgivingtorequests(name, loanholderaccount);

                                if (valid2 == true && valid1 == false)
                                {
                                    loan_amount = findrequestedloan(name, loanholderaccount);
                                    cout << " Enter days for which you are giving loan: ";
                                    cin >> days;
                                    for (int index = 0; index < userCount; index++)
                                    {
                                        // giving loan to a specfic account
                                        if (usernames[index] == name && accountnumbers[index] == loanholderaccount)
                                        {
                                            loanholderaccounts[loan_count] = loanholderaccount;
                                            loanholders[loan_count] = name;
                                            givenloanamounts[loan_count] = loan_amount;
                                            givenloandays[loan_count] = days;
                                            time_t ct = time(0);
                                            string currenttime = ctime(&ct);
                                            loantime[loan_count] = currenttime;
                                            loan_count++;
                                            loan_req--;
                                            deleteloanrequest();
                                            updatedatainfile3();
                                            storedatainfile4();
                                            break;
                                        }
                                    }
                                    cout << " Press any key to continue..." << endl;
                                    getch();
                                }
                                else
                                {
                                    cout << " you cannot give loan to this user!";
                                    getch();
                                }
                            }
                            else
                            {
                                cout << "Press any key to continue";
                                getch();
                            }
                        }
                        if (adminchoice == "8")
                        {
                            header();
                            string submenu = "View loan holders";
                            printsubMenu(submenu);
                            viewloanholders();
                            cout << "PRess any key to continue...";
                            getch();
                        }
                        if (adminchoice == "9")
                        {
                            header();
                            string submenu = "View total money";
                            printsubMenu(submenu);
                            float sum = checktotalmoney();
                            cout << "  TOtal money present in bank is : " << sum << endl;
                            cout << "  PRess any key to continue..." << endl;
                            getch();
                        }
                        if (adminchoice == "10")
                        {
                            header();
                            int option;
                            int accountnumber;
                            string name;
                            float percentofTax;
                            string submenu = "Apply tax";
                            printsubMenu(submenu);
                            cout << "  Do you want to implement tax on : " << endl;
                            cout << "   1. specific user." << endl;
                            cout << "   2. All users." << endl;
                            cin >> option;
                            if (option == 1)
                            {
                                header();
                                string submenu = "single user";
                                printsubMenu(submenu);
                                cout << " Enter name of user on which you want to implement tax: ";
                                cin >> name;
                                cout << " Enter account number: ";
                                cin >> accountnumber;
                                bool check = validnumber(accountnum);
                                if (check == true)
                                {
                                    cout << endl
                                         << "  You are implementing tax" << endl;
                                    cout << " -----------------------------------------------------------" << endl;
                                    cout << " Enter percentage of tax to implement: ";
                                    cin >> percentofTax;
                                    taxonspecificClient(name, accountnumber, percentofTax);
                                    updatedatainfile1();
                                    cout << "  TAx hasbeen deducted!" << endl;
                                    cout << "Press any key to continue..." << endl;
                                    getch();
                                }
                                else
                                {
                                    cout << " Invalid account number!" << endl;
                                }
                            }
                            else if (option == 2)
                            {
                                header();
                                string submenu = "all clients";
                                printsubMenu(submenu);
                                cout << " Enter percentage of tax to implement: ";
                                cin >> percentofTax;
                                for (int indx = 1; indx < userCount; indx++)
                                {
                                    // implementing tax on all accounts
                                    balances[indx] = balances[indx] - (balances[indx] * percentofTax / 100);
                                }
                                updatedatainfile1();
                                cout << "TAx hasbeen deducted!" << endl;
                            }
                            cout << "Press any key to continue..." << endl;
                            getch();
                        }
                        if (adminchoice == "11")
                        {
                            header();
                            string submenu = "Transaction details";
                            printsubMenu(submenu);
                            cout << "  Account"
                                 << "\t"
                                 << "Amount"
                                 << "\t"
                                 << "type"
                                 << "\t\t"
                                 << "time" << endl;
                            for (int indx = 0; indx < trans_count; indx++)
                            {
                                cout << "  " << transactionaccounts[indx] << "\t\t" << transactionamounts[indx] << "\t" << transactiontypes[indx] << "\t\t" << transactiontimes[indx] << endl;
                            }
                            cout << "  Press any key to continue...";
                            getch();
                        }
                    }
                }
                else if (role == "client")
                {
                    loginaccountnumber = checkloginpersonaccountnumber();
                    loginaccountbalance = checkloginaccountbalnace();
                    header();
                    int userchoice = 0;
                    while (userchoice != 9)
                    {
                        header();
                        userchoice = userinterface();
                        if (userchoice == 1)
                        {
                            header();
                            string submenu = "View Balance";
                            printsubMenu(submenu);
                            float current_balance = clientcurrentBalance();
                            cout << "  Your current account balance is: " << current_balance << endl;
                            cout << "   Press any key to continue... " << endl;
                            getch();
                        }
                        else if (userchoice == 2)
                        {
                            float depositAmount;
                            string transactiontype = "deposit", tempdeposit;
                            header();
                            string submenu = "Deposit Moeny";
                            printsubMenu(submenu);
                            bool flag = checkstatus(username, loginaccountnumber);
                            if (flag == true)
                            {
                                cout << "  Enter amonut you want to deposit : ";
                                cin >> tempdeposit;
                                bool checkvalidity = phonenumbercheck(tempdeposit);
                                if (checkvalidity == true)
                                {
                                    while (checkvalidity != false) // checking if amount contains only numbers
                                    {
                                        cout << " Enter amount again: ";
                                        cin >> tempdeposit;
                                        checkvalidity = phonenumbercheck(tempdeposit);
                                    }
                                }
                                depositAmount = stof(tempdeposit);
                                addmoneyinaccount(depositAmount);
                                transactionamounts[trans_count] = depositAmount;
                                transactiontypes[trans_count] = transactiontype;
                                transactionaccounts[trans_count] = username;
                                time_t ct = time(0);
                                string currenttime = ctime(&ct);
                                transactiontimes[trans_count] = currenttime;
                                updatedatainfile1();
                                storeDatainfile2(depositAmount, currenttime, transactiontype);
                                trans_count++;
                                cout << "  Money has been deposited" << endl;
                                cout << "  Press any key to coninue... ";
                                getch();
                            }
                            else if (flag == false)
                            {
                                cout << "   You cannot deposit money, your account is blocked" << endl;
                                cout << "   Press any key to continue";
                                getch();
                            }
                        }
                        else if (userchoice == 3)
                        {
                            header();
                            float transfer_money;
                            int someone_account;
                            string submenu = "TRansfer Money", tempaccount;
                            printsubMenu(submenu);
                            bool flag = checkstatus(username, loginaccountnumber);
                            if (flag == true)
                            {
                                cout << "  Enter account number to which you want to transfer money: ";
                                cin >> tempaccount;
                                bool checkvalid = phonenumbercheck(tempaccount);
                                if (checkvalid == true)
                                {
                                    while (checkvalid != false) // checking if account number contains only numbers
                                    {
                                        cout << " Enter number again: ";
                                        cin >> tempaccount;
                                        checkvalid = phonenumbercheck(tempaccount);
                                    }
                                }
                                someone_account = stoi(tempaccount);
                                bool isvalid = validnumber(someone_account);
                                if (isvalid == true)
                                {
                                    for (int index = 0; index < userCount; index++)
                                    {
                                        // finfing index of someones account
                                        if (accountnumbers[index] == someone_account)
                                        {
                                            cout << "  Enter money you want to transfer: ";
                                            cin >> transfer_money;
                                            // checking if balance is sufficent
                                            if (transfer_money > loginaccountbalance)
                                            {
                                                cout << "  Low  account balance!!money cannot be transfered!!";
                                                getch();
                                            }
                                            else
                                            {
                                                // transferring money
                                                moneytransfer(transfer_money);
                                                balances[index] = balances[index] + transfer_money;
                                                updatedatainfile1();
                                                cout << "  MOney has been transfered " << endl;
                                                cout << " Press any key to continue..." << endl;
                                                getch();
                                                break;
                                            }
                                        }
                                    }
                                }
                                else
                                {
                                    cout << " This account number is not valid." << endl;
                                    cout << "Press any key to back" << endl;
                                    getch();
                                }
                            }
                            else if (flag == false)
                            {
                                cout << "   You cannot transfer money, your account is blocked" << endl;
                                cout << "   Press any key to continue";
                                getch();
                            }
                        }
                        else if (userchoice == 4)
                        {
                            float withdrawAmount;
                            string transactiontype = "withdraw", tempwithdraw;
                            header();
                            string submenu = "Withdraw Money";
                            printsubMenu(submenu);
                            bool flag = checkstatus(username, loginaccountnumber);
                            if (flag == true)
                            {
                                cout << "  Enter amonut you want to withdraw : ";
                                cin >> tempwithdraw;
                                bool checkvalidity = phonenumbercheck(tempwithdraw);
                                if (checkvalidity == true)
                                {
                                    while (checkvalidity != false) // checking if amount contains only numbers
                                    {
                                        cout << " Enter amount again: ";
                                        cin >> tempwithdraw;
                                        checkvalidity = phonenumbercheck(tempwithdraw);
                                    }
                                }
                                withdrawAmount = stof(tempwithdraw);
                                for (int index = 0; index < userCount; index++)
                                {
                                    if (usernames[index] == username && passwords[index] == password)
                                    {
                                        // withdrawing  money
                                        if (balances[index] > withdrawAmount)
                                        {
                                            withdrawcash(withdrawAmount);
                                            // saving withdrawl information in parallel arrays
                                            transactionamounts[trans_count] = withdrawAmount;
                                            transactiontypes[trans_count] = transactiontype;
                                            transactionaccounts[trans_count] = username;
                                            time_t ct = time(0);
                                            string currenttime = ctime(&ct);
                                            transactiontimes[trans_count] = currenttime;
                                            updatedatainfile1();
                                            storeDatainfile2(withdrawAmount, currenttime, transactiontype);
                                            trans_count++;
                                            cout << " Money has been withdrawn" << endl;
                                        }
                                        else
                                        {
                                            cout << "  Balance not sufficient!! " << endl;
                                        }
                                        break;
                                    }
                                }
                                cout << "   Press any key to coninue... ";
                                getch();
                            }
                            else if (flag == false)
                            {
                                cout << "   You cannot withdraw money, your account is blocked" << endl;
                                cout << "   Press any key to continue";
                                getch();
                            }
                        }
                        else if (userchoice == 5)
                        {
                            float loan_amount;
                            char confirm;
                            int accountnumber;
                            string pin;
                            header();
                            string submenu = "Request Loan";
                            printsubMenu(submenu);
                            cout << "  Enter your account number: ";
                            cin >> accountnumber;
                            cout << "  Re-Enter your account pin: ";
                            cin >> pin;
                            pin = pincheck(pin);
                            bool presence = checkaccountPresence(accountnumber, pin);
                            if (presence == true)
                            {
                                cout << "  Do you want to request loan(y for yes /n for no): ";
                                cin >> confirm;
                                if (confirm == 'y')
                                {
                                    bool valid = checkvalidityofrequestloan(accountnumber);
                                    bool check = checkpreviousloanrequest(accountnumber);
                                    if (check == false && valid == false)
                                    {
                                        for (int index = 0; index < userCount; index++)
                                        {
                                            if (usernames[index] == username && passwords[index] == password)
                                            {
                                                if (accounttypes[index] == "salary")
                                                {
                                                    cout << "  you cannot request loan as you have salary account!" << endl;
                                                    cout << "  press any key to go back...";
                                                    getch();
                                                }
                                                else if (accounttypes[index] == "current")
                                                {
                                                    // requesting loan
                                                    cout << "  Enter amount of loan you want to take: ";
                                                    cin >> loan_amount;
                                                    requestloans(loan_amount, pin, accountnumber);
                                                    storeloandetailsinfile(loan_amount);
                                                    loan_req++;
                                                    cout << "   YOUR request has beeb submitted" << endl;
                                                    cout << "   Press any key to go back...";
                                                    getch();
                                                }
                                            }
                                        }
                                    }
                                    if (check == true || valid == true)
                                    {
                                        cout << "  you cannot request loan!" << endl;
                                        cout << "  press any key to go back...";
                                        getch();
                                    }
                                }
                                else
                                {
                                    cout << "  Press any key to go back...";
                                    getch();
                                }
                            }
                            else
                            {
                                cout << "  Invlid input" << endl;
                                getch();
                            }
                        }
                        else if (userchoice == 6)
                        {
                            header();
                            string submenu = "Loan info";
                            printsubMenu(submenu);
                            cout << "  Your loan details are given below: " << endl;
                            cout << " amount"
                                 << "\t"
                                 << "Time" << endl;
                            for (int index = 0; index < loan_count; index++)
                            {
                                if (loanholders[index] == username)
                                {
                                    // displaying loan details
                                    cout << " " << givenloanamounts[index] << "  " << loantime[index] << endl;
                                    break;
                                }
                            }
                            cout << " Press any key to continue..." << endl;
                            getch();
                        }
                        else if (userchoice == 7)
                        {
                            header();
                            float return_amount;
                            string submenu = "Return loan";
                            printsubMenu(submenu);
                            cout << "  Enter amount of loan you have taken: ";
                            cin >> return_amount;
                            for (int index = 0; index < userCount; index++)
                            {
                                if (usernames[index] == username && passwords[index] == password)
                                {
                                    // returning loan
                                    loan_count = loan_count - 1;
                                    for (int idx = index; idx <= loan_count; idx++)
                                    {
                                        requestloanaccounts[idx] = requestloanaccounts[idx + 1];
                                        requestloanpoeple[idx] = requestloanpoeple[idx + 1];
                                        requestloanamounts[idx] = requestloanamounts[idx + 1];
                                    }
                                    updatedatainfile3();
                                    loan_req--;
                                    cout << "  You have no loan now!";
                                    cout << "  Press any key to go back";
                                    getch();
                                    break;
                                }
                            }
                        }
                        else if (userchoice == 8)
                        {
                            header();
                            float bill;
                            int recp_accnumber;
                            string submenu = "Pay bills";
                            printsubMenu(submenu);
                            cout << " Enter amount of bill: ";
                            cin >> bill;
                            cout << " ENter recepient account number: ";
                            cin >> recp_accnumber;
                            bool isvalid = validnumber(recp_accnumber);
                            if (isvalid == true)
                            {
                                for (int index = 0; index < userCount; index++)
                                {
                                    // finding account number of recepient
                                    if (accountnumbers[index] == recp_accnumber)
                                    {
                                        for (int idx = 0; idx < userCount; idx++)
                                        {
                                            if (usernames[idx] == username)
                                            {
                                                // checking if users balance is sufficient to pay bill
                                                if (bill > balances[idx])
                                                {
                                                    cout << "  Insufficient account balance!!";
                                                    getch();
                                                    break;
                                                }
                                                else
                                                {
                                                    // paying bill
                                                    balances[index] = balances[index] + bill;
                                                    balances[idx] = balances[idx] - bill;
                                                    updatedatainfile1();
                                                    getch();
                                                    break;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            else
            {
                cout << " Invalid user" << endl;
                cout << " Press any key to go back";
                getch();
            }
        }
    }
}

void header()
{
    system("cls");
    cout << "  ##############################################################" << endl;
    cout << "  ####%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%#####" << endl;
    cout << "  ####                BANK MANAGEMENT SYSTEM               #####" << endl;
    cout << "  ####%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%#####" << endl;
    cout << "  ##############################################################" << endl;
    cout << endl;
}
void printsubMenu(string submenu)
{
    string message = "Main Menu>" + submenu;
    cout << "  " << message << endl;
    cout << "  --------------------------------------------------------------------" << endl;
}
string firstinterface()
{
    string option;
    cout << "  Welcome!!" << endl;
    cout << " ====================================================================" << endl;
    cout << "   1. Sign In" << endl;
    cout << "   2. Exit" << endl;
    cout << "  PLease enter a choice: ";
    cin >> option;
    return option;
}
bool checkname(string name)
{
    bool flag = false;
    for (int i = 0; i < name.length(); i++)
    {
        if ((name[i] > 63 && name[i] < 91) || (name[i] > 96 && name[i] < 123))
        {
            flag = true;
        }
        else
        {
            flag = false;
            break;
        }
    }
    return flag;
}
string checkRole(string username, string password)
{
    string person = "client";
    if (username == usernames[0] && password == passwords[0])
    {
        person = "admin";
    }
    return person;
}
string pincheck(string password)
{
    int check = password.length();
    if (check != 4)
    {
        while (check != 4)
        {
            cout << " invalid pin!" << endl;
            cout << " Enter 4-didgit pin again: ";
            cin >> password;
            check = password.length();
        }
    }
    return password;
}
void name_check(string name)
{
    bool flag = checkname(name);
    if (flag == false)
    {
        while (flag != true)
        {
            cout << " Enter valid name: ";
            cin.ignore();
            getline(cin, name);
            flag = checkname(name);
        }
    }
}
bool alreadytakename(string name)
{
    for (int i = 0; i < userCount; i++)
    {
        if (usernames[i] == name)
        {
            return true;
        }
    }
    return false;
}
bool checkstatus(string name, int accountnumber)
{
    bool statusFlag;
    for (int i = 0; i < userCount; i++)
    {
        if (usernames[i] == name && accountnumbers[i] == accountnumber)
        {
            if (statuses[i] == "running")
            {
                statusFlag = true;
            }
            else if (statuses[i] == "freeze")
            {
                statusFlag = false;
            }
        }
    }
    return statusFlag;
}
bool phonenumbercheck(string phone)
{
    // checking strings for only numbers
    bool ifvalid = false;
    int check = phone.length();
    for (int i = 0; i < check; i++)
    {
        if (phone[i] != '0' && phone[i] != '1' && phone[i] != '2' && phone[i] != '3' && phone[i] != '4' && phone[i] != '5' && phone[i] != '6' && phone[i] != '7' && phone[i] != '8' && phone[i] != '9')
        {
            ifvalid = true;
            break;
        }
    }
    return ifvalid;
}
void loadDatafromFile1()
{
    string line;
    string username, password;
    fstream myFile;
    myFile.open("people.txt", ios::in);
    while (getline(myFile, line))
    {
        accountnumbers[userCount] = stoi(parsedata(line, 1));
        usernames[userCount] = parsedata(line, 2);
        passwords[userCount] = parsedata(line, 3);
        roles[userCount] = parsedata(line, 4);
        accounttypes[userCount] = parsedata(line, 5);
        balances[userCount] = stof(parsedata(line, 6));
        phonenumbers[userCount] = parsedata(line, 7);
        statuses[userCount] = parsedata(line, 8);
        userCount++;
        accountnum = checkNewAccountnumber() + 1;
    }
    myFile.close();
}
string parsedata(string line, int feild)
{
    string item = "";
    int commacount = 1;
    for (int i = 0; i < line.length(); i++)
    {
        if (line[i] == ',')
        {
            commacount++;
        }
        else if (feild == commacount)
        {
            item = item + line[i];
        }
    }
    return item;
}
void viewUsers()
{
    // displaying all user details
    cout << " AccNo "
         << "\t"
         << " Name "
         << "\t\t"
         << "Pin"
         << "\t"
         << "Accounttype"
         << "\t"
         << "Balance"
         << "\t"
         << "Phonenumber"
         << "\t"
         << "status(unf/frz) " << endl;
    for (int idx = 1; idx < userCount; idx++)
    {
        {
            cout << " " << accountnumbers[idx] << "\t" << usernames[idx] << "\t\t" << passwords[idx] << "\t" << accounttypes[idx] << "\t\t" << balances[idx] << "\t" << phonenumbers[idx] << "\t" << statuses[idx] << endl;
        }
    }
}
bool signIn(string username, string password)
{
    bool isPresent = false;
    for (int idx = 0; idx < userCount; idx++)
    {
        if (usernames[idx] == username && passwords[idx] == password)
        {
            isPresent = true;
            break;
        }
    }
    return isPresent;
}
void updatinguserpersonalinfo(string name, int accountnumber, string newname, string newpin, int newbalance, string newtype, string newstatus, string newnumber)
{
    for (int index = 0; index < userCount; index++)
    {
        if (usernames[index] == name && accountnumbers[index] == accountnumber)
        {
            usernames[index] = newname;
            passwords[index] = newpin;
            balances[index] = newbalance;
            accounttypes[index] = newtype;
            statuses[index] = newstatus;
            phonenumbers[index] = newnumber;
            break;
        }
    }
}
void viewloanholders()
{
    cout << "    Following are loan holders details.." << endl;
    cout << endl;
    cout << "    Names"
         << "\t"
         << "amount"
         << "\t"
         << "totaltime(days)"
         << "\t"
         << "granting time" << endl;
    // all people who have taken loan
    for (int index = 0; index < loan_count; index++)
    {
        cout << "    " << loanholders[index] << "\t" << givenloanamounts[index] << "\t" << givenloandays[index] << "\t" << loantime[index] << endl;
    }
}
int checkloginpersonaccountnumber()
{
    int number;
    for (int i = 0; i < userCount; i++)
    {
        if (usernames[i] == username && passwords[i] == password)
        {
            number = accountnumbers[i];
        }
    }
    return number;
}
string admininterface()
{
    string selection;
    cout << "    Welcome as an Admin!" << endl;
    cout << "    ------------------------------------------------------------" << endl;
    cout << "    What do you want to do as admin? " << endl;
    cout << endl;
    cout << "     1. Create a user account." << endl;
    cout << "     2. Close an existing user account." << endl;
    cout << "     3. Temporarily freeze a user's account" << endl;
    cout << "     4. Search a specific user's info." << endl;
    cout << "     5. Update a specific user's info." << endl;
    cout << "     6. View all users personal info. " << endl;
    cout << "     7. Give loan to a user." << endl;
    cout << "     8. See loan holders details." << endl;
    cout << "     9. Check total money present in bank." << endl;
    cout << "    10. Implement tax on user's account." << endl;
    cout << "    11. See total transactions details." << endl;
    cout << "    12. Exit. " << endl;
    cout << endl;
    cout << "    ------------------------------------------------------------" << endl;
    cout << "    Selct an option...." << endl;
    cout << "  ";
    cin >> selection;
    return selection;
}
bool alreadytakenpin(string newpin)
{
    bool flags = false;
    for (int index = 0; index < userCount; index++)
    {
        // checking if the new pin enetered by user is already taken or not
        if (passwords[index] == newpin)
        {
            flags = true;
        }
    }
    return flags;
}
string phone_numbercheck(string number)
{
    int phone = number.length();
    if (phone != 11)
    {
        // checking if phone number is 11 digits
        while (phone != 11)
        {
            cout << "  invalid number!" << endl;
            cout << "  Enter number again: ";
            cin >> number;
            phone = number.length();
        }
    }
    return number;
}
float minimum_balance(float balance, string type)
{
    if (type == "salary" && balance < 500.0)
    {
        // limiting minimum intial balance of a salary account
        while (balance < 500.0)
        {
            cout << "  Enter starting balance greater then 500: ";
            cin >> balance;
        }
    }
    else if (type == "current" && balance < 5000.0)
    {
        // limiting minimum intial balance of a current account
        while (balance < 5000.0)
        {
            cout << "  Enter starting balance greater then 5000: ";
            cin >> balance;
        }
    }
    return balance;
}
string checkaccounttype(string type)
{
    // checking if account type entered by is valid or not
    if (type != "current" && type != "salary")
    {
        while (type != "current" && type != "salary")
        {
            // getting input until user enters a valid account type
            cout << "  Enter valid type: ";
            cin >> type;
        }
    }
    return type;
}
bool accountAlreadyexists(string name, string pin)
{
    bool flag = false;
    for (int index = 0; index < userCount; index++)
    {
        if (usernames[index] == name && passwords[index] == pin)
        {
            flag = true;
        }
    }
    return flag;
}
void storeinFile1(int accountnum, string name, string pin, string type, float balance, string phone)
{
    fstream myFile;
    myFile.open("people.txt", ios::app);
    myFile << endl
           << accountnum << "," << name << "," << pin << ","
           << "client"
           << "," << type << "," << balance << "," << phone << ","
           << "running";
    myFile.close();
}
void storeDatainArray(int accountnum, string name, string pin, string acctype, float balance, string phone)
{
    usernames[userCount] = name;
    passwords[userCount] = pin;
    accounttypes[userCount] = acctype;
    balances[userCount] = balance;
    phonenumbers[userCount] = phone;
    statuses[userCount] = "running";
    accountnumbers[userCount] = accountnum;
}
void account_close(int accountnumber, string name, string pin)
{
    for (int index = 1; index < userCount; index++)
    {
        // finding index where data of user is stored in array
        if (usernames[index] == name && passwords[index] == pin && accountnumbers[index] == accountnumber)
        {
            userCount = userCount - 1;
            for (int idx = index; idx <= userCount; idx++)
            {
                // deleting a user' record
                usernames[idx] = usernames[idx + 1];
                passwords[idx] = passwords[idx + 1];
                accounttypes[idx] = accounttypes[idx + 1];
                balances[idx] = balances[idx + 1];
                statuses[idx] = statuses[idx + 1];
                phonenumbers[idx] = phonenumbers[idx + 1];
                accountnumbers[idx] = accountnumbers[idx + 1];
            }
        }
    }
}
void updatedatainfile1()
{
    fstream myFile;
    myFile.open("people.txt", ios::out);

    myFile << accountnumbers[0] << "," << usernames[0] << "," << passwords[0] << "," << roles[0] << "," << accounttypes[0] << "," << balances[0] << "," << phonenumbers[0] << "," << statuses[0];
    for (int idx = 1; idx < userCount; idx++)
    {
        myFile << endl
               << accountnumbers[idx] << "," << usernames[idx] << "," << passwords[idx] << "," << roles[idx] << "," << accounttypes[idx] << "," << balances[idx] << "," << phonenumbers[idx] << "," << statuses[idx];
    }
    myFile.close();
}
bool validnumber(int accountnum)
{
    bool flags = false;
    for (int index = accountnum; index > 0; index = index / 10)
    {
        index = index % 10;
        // checking if account number enetered contains numbers only
        if (index == 0 || index == 1 || index == 2 || index == 3 || index == 4 || index == 5 || index == 6 || index == 7 || index == 8 || index == 9)
        {
            flags = true;
        }
        else
        {
            break;
        }
    }
    return flags;
}
int checkNewAccountnumber()
{
    int largest = accountnumbers[0];
    for (int index = 1; index < userCount; index++)
    {
        if (largest < accountnumbers[index])
        {
            largest = accountnumbers[index];
        }
    }
    return largest;
}
bool checkaccountPresence(int accountnum, string pin)
{
    bool flag = false;
    for (int index = 0; index < userCount; index++)
    {
        if (accountnumbers[index] == accountnum && passwords[index] == pin)
        {
            flag = true;
        }
    }
    return flag;
}
bool checknameandaccount(string name, int accountnumber)
{
    bool flag = false;
    for (int i = 0; i < userCount; i++)
    {
        if (usernames[i] == name && accountnumbers[i] == accountnumber)
        {
            flag = true;
        }
    }
    return flag;
}
void freezeAccount(int accountnum, string pin)
{
    for (int i = 0; i < userCount; i++)
    {
        // freezing a user's account
        if (accountnumbers[i] == accountnum && passwords[i] == pin)
        {
            statuses[i] = "freeze";
            break;
        }
    }
    cout << "Account has been freezed.." << endl;
}
void searchuserdetails(string name, int accountnumber)
{
    cout << " Accountno"
         << "\t"
         << "Name"
         << "\t"
         << "Pin"
         << "\t"
         << "AccountType"
         << "\t"
         << "Balance"
         << "\t"
         << "Phonenumber"
         << "\t"
         << "Status"
         << "\t" << endl;
    for (int index = 0; index < userCount; index++)
    {
        if (usernames[index] == name && accountnumbers[index] == accountnumber)
        {
            // displaying a specific user's information
            cout << " " << accountnumbers[index] << "\t\t" << usernames[index] << "\t" << passwords[index] << "\t" << accounttypes[index] << "\t\t" << balances[index] << "\t" << phonenumbers[index] << "\t" << statuses[index] << endl;
        }
    }
}
void takevalidpin(string newpin)
{
    bool ispresent = alreadytakenpin(newpin);
    if (ispresent == true)
    {
        cout << "THIs pin is already taken." << endl;
        while (ispresent != false)
        {
            cout << "Enter pin again: ";
            cin >> newpin;
            ispresent = alreadytakenpin(newpin);
        }
    }
}
string updateMenu()
{
    string option;
    cout << "what do you want to update: " << endl;
    cout << " 1. name:" << endl;
    cout << " 2. pin: " << endl;
    cout << " 3. account type: " << endl;
    cout << " 4. balance: " << endl;
    cout << " 5. account Status: " << endl;
    cout << " 6. phone number: " << endl;
    cout << " 7. all of above." << endl;
    cin >> option;
    return option;
}
void updateName(string name, int accountnumber, string newname)
{
    for (int index = 0; index < userCount; index++)
    {
        if (usernames[index] == name && accountnumbers[index] == accountnumber)
        {
            usernames[index] = newname;
            break;
        }
    }
}
void updatePin(string name, int accountnumber, string newpin)
{
    for (int index = 0; index < userCount; index++)
    {
        if (usernames[index] == name && accountnumbers[index] == accountnumber)
        {
            passwords[index] = newpin;
            break;
        }
    }
}
void updatetype(string name, int accountnumber, string newtype)
{
    for (int index = 0; index < userCount; index++)
    {
        if (usernames[index] == name && accountnumbers[index] == accountnumber)
        {
            accounttypes[index] = newtype;
            break;
        }
    }
}
void updatebalance(string name, int accountnumber, float newbalance)
{
    for (int index = 0; index < userCount; index++)
    {
        if (usernames[index] == name && accountnumbers[index] == accountnumber)
        {
            balances[index] = newbalance;
            break;
        }
    }
}
void updatestatus(string name, int accountnumber, string newstatus)
{
    for (int index = 0; index < userCount; index++)
    {
        if (usernames[index] == name && accountnumbers[index] == accountnumber)
        {
            statuses[index] = newstatus;
            break;
        }
    }
}
void updatephonenumber(string name, int accountnumber, string newnumber)
{
    for (int index = 0; index < userCount; index++)
    {
        if (usernames[index] == name && accountnumbers[index] == accountnumber)
        {
            phonenumbers[index] = newnumber;
            break;
        }
    }
}
float checktotalmoney()
{
    float total = 0.0;
    for (int index = 0; index < userCount; index++)
    {
        // adding money present in bank
        total = total + balances[index];
    }
    return total;
}
void taxonspecificClient(string name, int accountnumber, float percentofTax)
{
    for (int indx = 0; indx < userCount; indx++)
    {
        // implementing tax on specific account
        if (usernames[indx] == name && accountnumbers[indx] == accountnumber)
        {
            balances[indx] == (balances[indx]) - ((balances[indx] * percentofTax) / 100);
            break;
        }
    }
}
int userinterface()
{
    int num3;
    cout << "    Welcome as client !" << endl;
    cout << "    ------------------------------------------------------------" << endl;
    cout << "    What do you want to do as client? " << endl;
    cout << endl;
    cout << "    1. View your account balance." << endl;
    cout << "    2. Deposit cash." << endl;
    cout << "    3. Transfer cash to someone from your account." << endl;
    cout << "    4. Withdraw cash from your account." << endl;
    cout << "    5. Request loan." << endl;
    cout << "    6. Veiw your previous loan." << endl;
    cout << "    7. Return loan. " << endl;
    cout << "    8. Pay bills." << endl;
    cout << "    9. Exit. " << endl;
    cout << endl;
    cout << "    ------------------------------------------------------------" << endl;
    cout << "    Selct an option...." << endl;
    cout << "   ";
    cin >> num3;
    return num3;
}
float clientcurrentBalance()
{
    float present = 0;
    for (int index = 0; index < userCount; index++)
    {
        // views current account balance of client
        if (usernames[index] == username && passwords[index] == password)
        {
            present = balances[index];
        }
    }
    return present;
}
void storeDatainfile2(float depositAmount, string currenttime, string transactiontype)
{
    fstream myotherFile;
    myotherFile.open("data.txt", ios::app);
    myotherFile << username << "," << depositAmount << "," << transactiontype << "," << currenttime;
    myotherFile.close();
}
void loaddatafromfile2()
{
    string line;
    string username, password;
    fstream myotherFile;
    myotherFile.open("data.txt", ios::in);
    while (getline(myotherFile, line))
    {
        transactionaccounts[trans_count] = parsedata(line, 1);
        transactionamounts[trans_count] = stof(parsedata(line, 2));
        transactiontypes[trans_count] = parsedata(line, 3);
        transactiontimes[trans_count] = parsedata(line, 4);
        trans_count++;
    }
    myotherFile.close();
}
void addmoneyinaccount(float depositAmount)
{
    for (int index = 0; index < userCount; index++)
    {
        // depositing money in bank
        if (usernames[index] == username && passwords[index] == password)
        {
            balances[index] = balances[index] + depositAmount;
            break;
        }
    }
}
void moneytransfer(float transfer_money)
{
    for (int idx = 0; idx < userCount; idx++)
    {
        // finding index where user name is stored
        if (usernames[idx] == username && accountnumbers[idx] == loginaccountnumber)
        {
            // deducting money from user's account
            balances[idx] = balances[idx] - transfer_money;
        }
    }
}
float checkloginaccountbalnace()
{
    float balance;
    for (int idx = 0; idx < userCount; idx++)
    {
        if (usernames[idx] == username && accountnumbers[idx] == loginaccountnumber)
        {
            // deducting money from user's account
            balance = balances[idx];
        }
    }
    return balance;
}
void withdrawcash(float withdrawAmount)
{
    // finding index where user's data is stored
    for (int index = 0; index < userCount; index++)
    {
        if (usernames[index] == username && passwords[index] == password)
        {
            // withdrawing money from user's account
            balances[index] = balances[index] - withdrawAmount;
            break;
        }
    }
}
void requestloans(float loan_amount, string pin, int accnumber)
{
    for (int index = 0; index < userCount; index++)
    {
        // finding index where user's data is stored
        if (accountnumbers[index] == accnumber && passwords[index] == pin)
        {
            // placing name and loan taken by user in parallel arrays
            requestloanpoeple[loan_req] = username;
            requestloanamounts[loan_req] = loan_amount;
            requestloanaccounts[loan_req] = accnumber;
            // incrementing number of people who have requested for loan
            break;
        }
    }
}
int findrequestedloan(string name, int loanholderaccount)
{
    int amount = 0;
    for (int i = 0; i < loan_req; i++)
    {
        if (requestloanaccounts[i] == loanholderaccount && requestloanpoeple[i] == name)
        {
            amount = requestloanamounts[i];
        }
    }
    return amount;
}
void deleteloanrequest()
{
    for (int i = 0; i < loan_req; i++)
    {
        requestloanaccounts[i] = requestloanaccounts[i + 1];
        requestloanpoeple[i] = requestloanpoeple[i + 1];
        requestloanamounts[i] = requestloanamounts[i + 1];
    }
}
void showloanrequests()
{
    cout << "  Folloing are the people who requested for loan: " << endl;
    cout << " Accountno"
         << "\t"
         << "\t"
         << "Name"
         << "\t"
         << " Amount" << endl;
    for (int index = 0; index < loan_req; index++)
    {
        cout << " " << requestloanaccounts[index] << "\t" << requestloanpoeple[index] << "   " << requestloanamounts[index] << endl;
    }
}
void storeloandetailsinfile(float loan_amount)
{
    fstream loanfile;
    loanfile.open("loan.txt", ios::app);
    loanfile << loginaccountnumber << "," << username << "," << loan_amount << endl;
    loanfile.close();
}
void loadloandatafromfile()
{
    string line;
    string username, password;
    fstream loanfile;
    loanfile.open("loan.txt", ios::in);
    while (getline(loanfile, line))
    {
        requestloanaccounts[loan_req] = stoi(parsedata(line, 1));
        requestloanpoeple[loan_req] = parsedata(line, 2);
        requestloanamounts[loan_req] = stof(parsedata(line, 3));
        loan_req++;
    }
    loanfile.close();
}
void updatedatainfile3()
{
    fstream loanfile;
    loanfile.open("loan.txt", ios::out);
    for (int i = 0; i < loan_req; i++)
    {
        loanfile << requestloanaccounts[i] << "," << requestloanpoeple[i] << "," << requestloanamounts[i] << endl;
    }
    loanfile.close();
}
void storedatainfile4()
{
    fstream otherloanfile;
    otherloanfile.open("loanpeople.txt", ios::out);
    for (int i = 0; i < loan_count; i++)
    {
        otherloanfile << loanholderaccounts[i] << "," << loanholders[i] << "," << givenloanamounts[i] << "," << givenloandays[i] << "," << loantime[i];
    }
    otherloanfile.close();
}
void loaddatafromfile4()
{
    string line;
    string username, password;
    fstream otherloanfile;
    otherloanfile.open("loanpeople.txt", ios::in);
    while (getline(otherloanfile, line))
    {
        loanholderaccounts[loan_count] = stoi(parsedata(line, 1));
        loanholders[loan_count] = parsedata(line, 2);
        givenloanamounts[loan_count] = stof(parsedata(line, 3));
        givenloandays[loan_count] = stoi(parsedata(line, 4));
        loantime[loan_count] = parsedata(line, 5);
        loan_count++;
    }
    otherloanfile.close();
}
bool checkpreviousloanrequest(int accountnumber)
{
    // dont request loan if u have already requested
    for (int i = 0; i < loan_req; i++)
    {
        if (requestloanaccounts[i] == accountnumber)
        {
            return true;
        }
    }
    return false;
}
bool checkvalidityofrequestloan(int accountnumber)
{
    for (int i = 0; i < loan_count; i++)
    {
        if (accountnumber == loanholderaccounts[i])
        {
            return true;
        }
    }
    return false;
}
bool checkagaingvingofloan(string name, int accountnumber)
{
    for (int i = 0; i < loan_count; i++)
    {
        if (name == loanholders[i] && accountnumber == loanholderaccounts[i])
        {
            return true;
        }
    }
    return false;
}
bool checkgivingtorequests(string name, int accountnumber)
{
    for (int i = 0; i < loan_req; i++)
    {
        if (name == requestloanpoeple[i] && accountnumber == requestloanaccounts[i])
        {
            return true;
        }
    }
    return false;
}
