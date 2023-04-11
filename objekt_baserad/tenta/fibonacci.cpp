#include <iostream>
unsigned int fibonacci(unsigned int n) { // din lösning här
if(n == 0){return 0;}
if (n==1){return 1;}

return fibonacci(n-1) + fibonacci(n-2);
}
int main() {
    int a;
    std::cin >> a;
    std::cout<<fibonacci(a)<<std::endl;
// hämta input från cin
// anropa din funktion och skicka resultatet till cout
return 0;
}