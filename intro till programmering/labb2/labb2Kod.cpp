//Taha Khudher
//2021-12-03
//data teknik introduktion till programerimng
//laboraion 2


#include<iostream>
#include<fstream>
#include<string>

using namespace std;



int main()
{
    string Förnamn, Efternamn, adress, personNum;
    char sex; 
    ifstream input;
    ofstream output;

    input.open("names.txt");
    output.open("info.txt");

    if(input.fail())
    {   
        cout << "Error, could not open file" << endl;
        
         return 0;
    }

    while (!input.eof()) 
    {
        input>>Förnamn>>Efternamn;
        input.ignore();
        getline(input, personNum);
        getline(input, adress);

        if (input.eof())
        {
            return 0;
        }

        int idd = stoi(personNum.substr(8, 1));
        if (idd %2 ==0)
        {
            sex = 'K'; 
        }
        else
            sex = 'M';

        
        output<<Efternamn<< ' ' <<Förnamn<< ' '<< ", "<< '['<< sex << ']'<< endl;
        output<< adress<< "\n"<<endl;

        
    }




    input.close();
    output.close();
    cout << "end of file" << endl;

    return 0;
}