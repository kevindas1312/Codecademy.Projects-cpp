#include <iostream>
#include <limits> //to use numeric_limits<streamsize>::max()
#include <vector> //using vector to store the elements of the class
#include <string> //to store string data types

using namespace std;

class Profile{ //use class so that we can store the data of multiple individuals without creating new variables
private: //inaccesible
    string name, city, country, pronouns, hobbies;
    int age;

public: //accessible
    Profile() : name(" "), city(" "), country(" "), pronouns(" "), hobbies(" "), age(0){}

    Profile(string new_name, string new_city, string new_country, string new_pronouns, string new_hobbies ,int new_age)
    : name(new_name), city(new_city), country(new_country), pronouns(new_pronouns), hobbies(new_hobbies), age(new_age)
    {}

    void display(){ //function used to display each profile
        cout << endl << "Name: " << name <<endl;
        cout << "Age: " << age <<endl;
        cout << "City: " << city <<endl;
        cout << "Country: " << country <<endl;
        cout << "Pronouns: " << pronouns <<endl;
        cout << "Hobbies: " << hobbies<< "\n\n\n";
    }
};

void storing(string &name1,string &city1, string &country1, string &pronouns1, string &hobbies1, int &age1){ //using call-by-reference function to input data without making the code inside main() function to look messy
    cout << "\nName: ";
    getline(cin,name1); //getline used to ensure spaces are still stored in the string variable
    cout << "\nCity: ";
    getline(cin,city1);
    cout << "\nCountry: ";
    getline(cin,country1);
    cout << "\nPronouns: ";
    getline(cin,pronouns1);
    cout << "\nHobbies: ";
    getline(cin,hobbies1);
    cout << "\nAge: ";
    cin >> age1;
}

int main(){
    int num;
    cout << "How many profiles would you like to store (rec. less than 5): ";
    cin >> num;

    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    string name1, city1, country1, pronouns1, hobbies1;
    int age1;

    vector<Profile> persons; //using a vector for dynamic memory allocation
    for(int i=0; i<num; i++){
        cout << "Profile no. " << i+1 << ": ";
        storing(name1,city1,country1,pronouns1,hobbies1,age1);

        cin.ignore(numeric_limits<streamsize>::max(),'\n');

        persons.push_back(Profile(name1, city1, country1, pronouns1, hobbies1, age1)); //input data inside vector/class
    }

    for(int j=0; j<num;j++){
        persons[j].display();
    }

    return 0;
}
