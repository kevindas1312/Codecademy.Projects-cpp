#include <iostream>
#include <limits>
using namespace std;

class Profile{
private:
    string name, city, country, pronouns, hobbies;
    int age;

public:
    Profile() : name(" "), city(" "), country(" "), pronouns(" "), hobbies(" "), age(0){}

    Profile(string new_name, string new_city, string new_country, string new_pronouns, string new_hobbies ,int new_age)
    : name(new_name), city(new_city), country(new_country), pronouns(new_pronouns), hobbies(new_hobbies), age(new_age)
    {}

    void display(){
        cout << endl << "Name: " << name <<endl;
        cout << "Age: " << age <<endl;
        cout << "Country: " << country <<endl;
        cout << "Pronouns: " << pronouns <<endl;
        cout << "Hobbies: " << hobbies<< "\n\n\n";
    }
};

int main(){
    int num;
    cout << "How many profiles would you like to store (rec. less than 5): ";
    cin >> num;

    string name1, city1, country1, pronouns1, hobbies1;
    int age1;

    Profile persons[num];
    for(int i=0; i<num; i++){
        cout << "\nName: ";
        cin >> name1;
        cout << "\nCity: ";
        cin >> city1;
        cout << "\nCountry: ";
        cin >> country1;
        cout << "\nPronouns: ";
        cin >> pronouns1;
        cout << "\nHobbies: ";
        cin >> hobbies1;
        cout << "\nAge: ";
        cin >> age1;

        cin.ignore(numeric_limits<streamsize>::max(),'\n');

        persons[i] = Profile(name1, city1, country1, pronouns1, hobbies1, age1);
    }

    for(int j=0; j<num;j++){
        persons[j].display();
    }

    return 0;
}
