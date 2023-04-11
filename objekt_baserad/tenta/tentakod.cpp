
#include <iostream>
class MyInt;
int main() {
int a, b, c;
std::cin >> a >> b >> c;
// skapa ett objekt av MyInt genom att anropa konstruktorn med a som argument // anropa get på objektet och skriv ut till cout, inkl. ny rad
MyInt integer(a);
std::cout << integer.get() << std::endl;
// anropa set på objektet med b som argument
// anropa get på objektet och skriv ut till cout, inkl. ny rad
// skapa ett till objekt av MyInt genom att anropa konstruktorn med c som argument
// använd tilldelningsoperatorn för att tilldela din gamla MyInt värdet från din nya M // anropa get på din >gamla< MyInt och skriv ut till cout, inkl. ny rad
return 0; 
}

class MyInt{
    private:
       int *ptr;
       int num;
    public:
        MyInt(int num){
            ptr = new int(num);       
        }

        ~MyInt(){
            delete ptr;
            ptr = nullptr;
        }

        /*MyInt operator = (const MyInt &src) {

        }*/
        void set(int num){

           ptr = new int(num); 
           
        }
        int get(){
            return *ptr;
        }
};