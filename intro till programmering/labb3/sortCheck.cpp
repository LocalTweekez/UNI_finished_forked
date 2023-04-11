#include<iostream>
#include<fstream>
#include<string>
#include "sortCheck.h"


using namespace std;

bool sortCheck(string fileName)
{
    ifstream input;
    input.open(fileName);
    
    int a, b;

    input>>a;

    while (!input.eof())
    {
        input>>b;

        if(a >b)
        {
            
            cout << fileName << "is NOT sorted" << endl;
            input.close();
            return false;
        }
        else
        {
            a = b;
        }
    }
    
    cout << fileName << " is sorted" << endl;
    input.close();
    return true;

}


