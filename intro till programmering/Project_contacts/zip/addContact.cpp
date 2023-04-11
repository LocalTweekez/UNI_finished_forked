#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

void addContact()
{
    string firstname, lastname, email, birthdate, adress, note, phonenumber;
    ofstream output("phonebook", ios::app);//ios::ate

    cout << "You are going to add a contact. \nAll the fields are optional.\nSkip a field by enter.\n" <<endl;
    cout << "First name: ";
    cin >> firstname;
    cout << "Lastname: ";
    cin >> lastname;

    cout << "E-mail: ";
    cin >> email;
    cin.ignore();

    cout << "Phonenumber: ";
    getline(cin, phonenumber);

    cout << "Full Adress: ";
    getline(cin, adress); 
    
    cout << "Birthdate: ";
    getline(cin, birthdate);

    cout << "A Note to remember your contact: ";
    getline(cin, note);
    
    output << "Name: " <<firstname << " "<< lastname <<"\n";
    output << "E-mail: " << email << endl;
    output << "Phone Number: " << phonenumber<<endl;
    output << "Adress: " << adress << endl;
    output << "Birthdate: " << birthdate<< endl;
    output << "Note: " << note << endl;
    output << "---------------------------------------"<<endl;
    output.close();

}