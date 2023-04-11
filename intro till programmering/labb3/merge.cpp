#include "merge.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string merge(string fileName, string fileName2 , string sortedFile)
{
    
    
    ifstream input1;
    ifstream input2;
    ofstream output;

    input1.open(fileName);
    input2.open(fileName2);
    output.open(sortedFile);

    int a, b;

    input1 >> a;
    input2 >> b;

    while (!input1.eof() && !input2.eof()) 
    {
       if(a <b )
        {
            output<<a << " ";
            input1 >> a;
        }

        else
        {
            output<<b << " ";
            input2 >> b;
        }
    
    }
    
    while(!input1.eof())
    {
        output<< a << " ";
        input1 >> a;
    }

    while(!input2.eof())
    {
        output<< b << " ";
        input2>>b;

    }
    string finished = "Files are now sorted ";
    input1.close();
    input2.close();
    output.close();
    return finished;
}