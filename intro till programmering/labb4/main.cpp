#include <iostream>
#include <algorithm>
#include <fstream>
#include <map>
#include <string>
#include <vector>
#include <cctype>

using namespace std;
int störstförst(pair<string, int>X, pair<string, int>Y)
{
    return X.second > Y.second;
}


int main()
{   
    ifstream input;
    input.open("hitchhikersguide.txt");
    string a;
    vector<string> ord;
    map<string,int>ordbok;
    


    while(input >> a)
    {
        
        for(int i = 0; i < a.length(); i++)
        {
            (a[i] = tolower(a[i]));
            
        }   // steg 1
        string temporaryWord;
        for(int i = 0; i < a.length(); i++)
        {   
            if ((a[i] >= 'a' && a[i] <= 'z'))
            {
                temporaryWord = temporaryWord + a[i];//steg 2
            }
        }

                for (int b = 0; b < temporaryWord.length(); b++)
                {
                    ordbok[temporaryWord]++; //Om samma ord uppstår så ökar värdet i ordet
                    break;
                }
            


    }
    input.close();
    int antal;
    cout << "Hur många ord vill du se"<<endl;
    cin >> antal;
    cout << "De "<< antal << " mest använda orden i boken är: " << endl;
    vector<pair<string, int> >sorteradlista(ordbok.begin(), ordbok.end()); //För att sortera mapen gör vi en vector av pair
    sort(sorteradlista.begin(), sorteradlista.end(), störstförst);   //Vi använder oss utav sort och uppdelning för att sortera vår vector
    for (int z = 0; z < antal; z++)
    {
        cout << '"'<< sorteradlista[z].first << '"'<<" har används " << sorteradlista[z].second <<" gånger." <<endl;   //Skriver ut vektorns innehåll, börjar med value och sedan key
    }

    

    return 0;
}