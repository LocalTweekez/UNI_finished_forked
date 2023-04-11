#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "addContact.h"
#include "remove.h"
#include "search.h"

using namespace std;


int main()
{
    int choice;
   do 
   {    
        cout << "\nPHONEBOOK MENU;"<<endl;
        cout << "1. Add a contact" << endl;
        cout << "2. Remove a contact" << endl;
        cout << "3. search for a contact" << endl;
        cout << "4. EXIT"<<endl;
        cout << "\nYour choice: ";
        cin >> choice;
        if (cin.fail())
        {

         // get rid of failure state
         cin.clear(); 
         // discard 'bad' character(s) 
         cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        switch(choice)
        {
            case 1:
                addContact();
                break;
            case 2:
                cout << "Remove a contact" << endl;
                remove();
                break;
            case 3:
                cout << "Search for a contact" <<endl;
                search();
                break;
            case 4:
                cout << "Have a great day!!!"<<endl;
                break;
            default:
                cout << "invalid selection!! Try again!"<<endl;
                


        }

    }while(choice != 4);

    return 0;
}