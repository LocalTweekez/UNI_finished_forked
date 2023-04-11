#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <ctype.h>
#include <iomanip>
#include <sstream>
#include <limits>
#include <clocale>


struct Adress{
    std::string street;
    int zip;
    std::string city;
};

struct Person{
    std:: string name;
    std:: string id;
    Adress location;
};

std:: istream& operator >>(std::istream& in, Person& p){ // overloaded operator >>
    std::string location, city, zip, name; 
    
    getline(in, p.name);
    getline(in, p.id);
    getline(in, location);
    
    int a =location.find_first_of(","); //finding the sepperating comma
    p.location.street= location.substr(0,a);
    
    for (int i = a; i <location.size(); i++) {
        if ((location[i] >= '0' && location[i] <= '9')){ //asigning the values between 1-9 to zip
            zip += location[i];
            zip.erase(std::remove_if(zip.begin(), zip.end(), ::isspace), zip.end()); //Removes whitespace
        }
        
    }
    int b = location.find_last_of(isalpha); //finding the); //finding the
    int c= location.find_last_of(); //finding the
    city = location.substr(b,c);
    int b = location.find_first_of(isalpha);
    int c = location.find_last_of(isalpha);
    city = city.substr(b,c)

    

    std:: istringstream(zip) >> p.location.zip; // converting zip to an int and assigning it to the location zip
    p.location.city = city; //assigning the city

    return in;
}

    std::ostream& operator <<(std::ostream& out, Person& p){ // overloading the operator << to be able to cout a person

    std:: cout << p.id << ", " << p.name <<","<< p.location.zip << ", "<<  p.location.city <<  "\n"<<std:: endl;

    return out;
}

size_t find_in_names(const std::vector<Person>& haystack , std::string name_part){ 

    std:: transform(name_part.begin(), name_part.end(),name_part.begin(),::tolower);
    size_t matchesFound =0;

    for (int i = 0; i < haystack.size(); i++){
        std:: string name = haystack[i].name;
        std:: transform(name.begin(), name.end(),name.begin(),::tolower);
        if (name.find(name_part) != -1){ // if that the operation didn't fail
            matchesFound++;
            continue;
        }
    }
        return matchesFound; 
    

}
std:: vector<Person> find_person_from_city(const std::vector<Person> &haystack, std::string city ){
    
    std:: transform(city.begin(), city.end(),city.begin(),::toupper);
    city.erase(std::remove_if(city.begin(), city.end(), ::isspace), city.end());

    while (city.find("å") != std::string::npos) // making the swedish characters to upper case manually
            city.replace(city.find("å"), 2, "Å");
    while (city.find("ä") != std::string::npos)
            city.replace(city.find("ä"), 2, "Ä");
    while (city.find("ö") != std::string::npos)
        city.replace(city.find("ö"), 2, "Ö");
    
    std:: vector<Person> matchingCities;

    
    for (int i = 0; i < haystack.size(); i++){
        std::string haystack_city = haystack[i].location.city;
        haystack_city.erase(std::remove_if(haystack_city.begin(), haystack_city.end(), ::isspace), haystack_city.end());
        if (city == haystack_city ){
            matchingCities.push_back(haystack[i]);
            continue;
        }
    }
    return matchingCities;
}


std::vector <Person> read_file(std::string filename){
    std::vector<Person> hayStack;
    std:: ifstream input(filename);
    if (input.fail()){
        std::cout << "Error: " << filename << " failed to open!!" << std::endl;
        input.close();
    return hayStack; 
    }     
    else{
        Person temp_p;
        while(input>>temp_p){
            hayStack.push_back(temp_p);
        }


    }
    input.close();
    return hayStack;
}



int main(){
    setlocale(LC_ALL, "sv_SE");
    std::vector<Person> haystack = read_file("names.txt");

    int choice;
    std::string name_part;

    do
    {
        std::cout << "\nVar god och ange ett av alternativen (1-3):" << std::endl;
        std::cout << " _______________________________________________________"<<std:: endl;
        std::cout << "|1. Sök del av personnamn.                             |" << std::endl;
        std::cout << "|2. Sök efter person i stad (endast exakta matchningar)|" << std::endl;
        std::cout << "|3. Avsluta.                                           |" << std::endl;
        std::cout << "|______________________________________________________|" <<std:: endl;
        std::cin >> choice;
        
        if (std::cin.fail())
        {

         // get rid of failure state
         std::cin.clear(); 
         // discard 'bad' character(location) 
         std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        switch(choice)
        {
            case 1:
            {
                std::cout << "Ange del av ett namn för att få antal matchningar: ";
                std::cin >> name_part;
                size_t foundMatches = find_in_names(haystack, name_part);
                std::cout << "\n" << "Antal matchningar: " << foundMatches << "\n"<< std::endl;
                break;
            }

            case 2:
            {
                std::string c;
                std::cout << "Ange en stad för att få varje matchad person tillbaks: \n" << std::endl;
                std::cin.ignore();
                getline(std::cin, c);
                //std::cout << "\n";
                std::vector<Person> cityMatches = find_person_from_city(haystack, c);

                for (int t = 0; t < cityMatches.size();t++) {
                    std::cout << cityMatches[t] << std::endl;
                }
                break;
            }

            case 3: {
                return 0; }
            
            default:
                std:: cout << "\nERROR SKRIV VAL MELLAN 1-3: \n";
                 continue;
        }
    }while(choice!=3);
    
}
