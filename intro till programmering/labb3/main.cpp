//Taha Khudher
//2021-12-08
//data teknik introduktion till programerimng
//laboraion 3


#include<iostream>
#include<fstream> 
#include"merge.h"
#include "sortCheck.h"
#include <string>

using namespace std;


int main()
{
    
    
    if(sortCheck("A.txt") && sortCheck("B.txt") == true)

    {

        merge("A.txt","b.txt","sorted.txt");
        sortCheck("sorted.txt");
    }
    
    else
    {
         cout<<"Error the files are not sorted correctly"<<endl;
    }

    



    return 0;
}
