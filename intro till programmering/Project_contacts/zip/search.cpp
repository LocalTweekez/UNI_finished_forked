#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

int search()
{
    ifstream input;
    input.open("phonebook");
    int a=0, choice, choicerange;
    string name, email,phonenumber, adress, birthdate, note, line;
    vector<string>information;
    while (!input.eof())
    {   
        if (input.eof())
        {
            return 0;
        }
        
        
        getline(input, name);
        if (name.empty())
        {
            continue;
        }
        getline(input, email);  
        getline(input,phonenumber);          
        getline(input, adress);
        getline(input, birthdate);
        getline(input, note);
        getline(input, line);

        a++;
        
        information.push_back(name);
        information.push_back(email);
        information.push_back(phonenumber);
        information.push_back(adress);
        information.push_back(birthdate);
        information.push_back(note);

       
        
        cout << "\n"<<a<< ". "<<   name <<endl;
        
        
    }

    cout <<"\nWrite the number assigned to the contact: "<<endl;
    cout << "Write '0' to quit the program: ";
    cin >>choice;
    

    if (choice == 0) {        // error check for non-standard input
        return 0;
    }
    if (choice > (a))
    {
        cout << "Not a valid choice!"<<endl;
        return 0;
    }
    else
    {
        cout << "\n";
        choice = (choice-1)*6;
        choicerange = choice + 6;
    }

    for(int i =choice; i <choicerange; i++)
        {
            cout << information[i]<< endl;
            
        }


    return 0;
}