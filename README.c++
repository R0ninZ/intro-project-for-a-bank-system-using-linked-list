#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <fstream>
using namespace std;
class customer
{
public:
    string name;
    string phone_number;
    long double cash;
    customer* next;
};
class BankSystem
{
public:
    customer* head =NULL;
    customer* tail = NULL;
    void AddCustomer(string n, string p, long double c)
    {
        customer* nc = new customer;
        nc->name = n;
        nc->phone_number = p;
        nc->cash = c;
        nc->next = NULL;
        if(head == NULL && tail == NULL)
        {
            head = nc;
            tail = nc;
        }
        else
        {
            tail->next = nc;
            tail = nc;
        }
        //system("cls");
        //cout << head->name << " " << head->phone_number << " " << head->cash << endl;
        //cout << tail->name << " " << tail->phone_number << " " << tail->cash << endl;
    }
    void addMoney(long double value, string phone)
    {
        customer* i= head;
        while(i != NULL)
        {
            if(i->phone_number == phone)
            {
                i->cash += value;
               // cout << i->name << " " << i->phone_number << " " << i->cash << endl;
                return;
            }
            else
            {
                i= i->next;
            }
        }


    }
    void print_customer(string phone)
    {
        system("cls");
        customer* i= head;
        while(i!= NULL)
        {
            //cout << i->name << " " << i->cash << " " << i->phone_number << endl;
            if(i-> phone_number == phone)
            {
                cout << "Customer name " << i->name << endl;
                cout << "Customer cash " << i->cash << endl;
                return;
            }
            else
            {
                i= i->next;
            }
        }
    }
    void withdraw(long double value, string phone)
    {
        customer* i= head;
        while(i != NULL)
        {
            if(i->phone_number == phone)
            {
                if(i->cash < value)
                {
                    cout << "Not enough cash\n";
                    return;
                }
                i->cash -= value;
               // cout << i->name << " " << i->phone_number << " " << i->cash << endl;
                return;
            }

            else
            {
                i= i->next;
            }
        }


    }
    void transfer(string ph1, string ph2, long double value)
    {
        customer* i = head;
        while(i != NULL)
        {
            if(ph1 == i->phone_number)
            {
                if(i->cash >= value)
                {
                    i->cash -= value;
                    break;
                }
                else
                {
                    cout << "Not enough cash\n";
                    return;
                }
            }
            else
            {
                i = i->next;
            }
        }
        i = head;
        while(i != NULL)
        {
            if(ph2 == i->phone_number)
            {
                i->cash += value;
                return;
            }
            else
            {
                i = i->next;
            }
        }
    }
    void delete_customer(string ph)
    {
        customer* i = head;
        if(head->phone_number == ph)
        {
            customer* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        else
        {
            customer* c = head->next;
            customer* p = head;
            while(c!=NULL)
            {
                if(c->phone_number == ph)
                {
                    p->next = c->next;
                    delete c;
                    return;
                }
                else
                {
                    c= c->next;
                    p= p->next;
                }
            }
        }
    }
    void print_all()
    {
        customer* i= head;
        while(i != NULL)
        {
            cout << "Customer name "<< i->name << endl;
            cout << "Customer phone " << i->phone_number << endl;
            cout << "Customer cash " << i->cash << endl;
            cout << "********************************\n";
            cout << "\n\n\n\n";
            i= i->next;
        }
        return;
    }
};

int main()
{
    BankSystem QNB;
    ofstream file("data.txt");
    while(1)
    {
        int choice;
        cout << "Enter 0 to close\n";
        cout << "Enter 1 to add new customer\n";
        cout << "Enter 2 to add money to account\n";
        cout << "Enter 3 to print customer \n";
        cout << "Enter 4 to withdraw\n";
        cout << "Enter 5 to transfer from customer to another\n";
        cout << "Enter 6 to delete customer \n";
        cout << "Enter 7 to print report for all customers\n";
        cin >> choice;
        if(choice == 0)
            break;
        switch(choice)
        {
            case 1:
                {
                cout << "Enter name, phone, cash\n";
                cin.ignore();
                string name;
                getline(cin , name);
                cin.ignore();
                string phone;
                cin >> phone;
                cin.ignore();
                long double cash; cin >> cash;
                QNB.AddCustomer(name, phone, cash);
                file << name << " " << phone << " " << cash << "\n";
                file.close();
                break;
                }
            case 2:
                {
                cout << "Enter amount of money\n";
                long double money;
                cin >> money;
                cout << "Enter your phone number\n";
                string phone;
                cin >> phone;
                QNB.addMoney(money, phone);
                break;
                }
            case 3:
                {
                 cout << "Enter customer phone\n";
                 string phone;
                 cin >> phone;
                 QNB.print_customer(phone);
                 break;
                }
            case 4:
                {
                cout << "Enter amount of money\n";
                long double money;
                cin >> money;
                cout << "Enter your phone number\n";
                string phone;
                cin >> phone;
                QNB.withdraw(money, phone);
                break;
                }
            case 5:
                {
                 cout << "Enter phone number 1 (person who transfer)\n";
                 string ph1; cin >> ph1;
                 cout << "Enter phone number 2 (person who recieve)\n";
                 string ph2; cin >> ph2;
                 cout << "Enter amount of money\n";
                 long double cash;
                 cin >> cash;
                 QNB.transfer(ph1,ph2,cash);
                 break;
                }
            case 6:
                {
                cout << "Enter phone to delete customer\n";
                string ph;
                cin >> ph;
                QNB.delete_customer(ph);
                break;
                }
            case 7:
                {
                    QNB.print_all();
                    break;
                }

        }

    }
    return 0;
}
