#include <iostream>
#include <string>
#include <algorithm>

bool palindrome(std:: string ord ,int pos) { // välj dina parametrar
    // din lösning här
    
    std::string reverseord = ord;
    reverse(reverseord.begin(),reverseord.end());
    if (pos==0){
        return 1;
    }
    if(ord[pos] == reverseord[pos]){
        pos--;
        return palindrome(ord,pos);
    }
    
    else{
        return 0;
    }
}   
 
int main() {
    
   std::string str;
    // hämta input från cin
    std::cin>>str;
    
    // anropa din funktion och skicka resultatet till cout
   std::cout<<palindrome(str, str.size()-1);
   

   
    return 0;
}