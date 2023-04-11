//Taha Khudher
//2021-11-29
//data teknik introduktion till programerimng
//laboraion 1 

#include <iostream>
using namespace std;


int main()
{

int max, min, antal = 0, sum = 0;
int tal;
double medel;

cout << "skriv talen för att beräkna max, min och medelvärdet: " << endl;
while (cin >> tal)
{

    if (antal == 0)
    {
        max = tal;
        min = tal;
        sum = tal;
    }
    else
    {
        sum = sum + tal;
    }
    antal++; 

    if (max < tal) 
    {
        max = tal;
    }
    if (min > tal) 
    {
        min = tal;
    }
}

    cout << "max : " << max << '\n'
    << "min : " << min << '\n'
    << "tal insatta : " << antal  << '\n'
    << "summan: " << sum << '\n'
    << "medelvärdet : " << (double)sum / (double)antal << endl;

    return 0;
}



