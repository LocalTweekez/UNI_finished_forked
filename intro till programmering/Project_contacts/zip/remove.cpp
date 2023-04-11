#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <iterator>
using namespace std;

int remove()
{
    ifstream input;
    input.open("phonebook");
    string name, email,phoneNumber, adress, birthdate, note, line;
    int a=0, choice=0, confirm=0, choicerange=0;
    vector<string>information;
    while (!input.eof())
    {   
        
        
        
        getline(input, name);
        if (name.empty())
        {
            continue;
        }
        getline(input, email);  
        getline(input, phoneNumber);          
        getline(input, adress);
        getline(input, birthdate);
        getline(input, note);
        getline(input, line);

        
        
        a++;

        information.push_back(name);
        information.push_back(email);
        information.push_back(phoneNumber);
        information.push_back(adress);
        information.push_back(birthdate);
        information.push_back(note);
        
        cout << "\n"<< a<< ". " << name <<endl;
    }
    
    cout <<"\nWrite the number assigned to the name you want to remove;\nWrite '0' to exit: ";
    cin >>choice;
    if (choice == 0)
    {
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
        choicerange = choice +6;
        
        for(int i = choice; i <choicerange; i++)
        {
            cout << information[i]<< endl;
            
        }

        cout<<"\nDo you wish to remove the following information)\n1= yes, 2= no: ";
        cin >> confirm;
        cout << "\n";

        switch(confirm)
        {
            case 1:
                information.erase(information.begin()+choice, information.begin()+choicerange);
                break;
            case 2:
                cout << "Contact will remain in the phonebook"<<endl;
                break;
            default: 
                cout << "Invalid selection!!! Try again!"<< endl;
        
        }
        
        ofstream output;
        output.open("phonebook");
        for(int i= 0; i < information.size(); i++)
        {
            output << information[i]<< endl;
            if((i+1)% 6 == 0)
            {
                output << line << endl;
            }

        }
        
        output.close();
    }
    return 0;
}