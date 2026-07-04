#include <iostream>
using namespace std;

void selection(char &choice1){
    while(choice1 != 'A' && choice1 != 'B' && 
        choice1 != 'C' && choice1 != 'a' &&
        choice1 != 'b' && choice1 != 'c'){
          cout << "Enter A if you ask the Gryphon next to you what the jurors are doing.\n";
          cout << "Enter B if you sneak a tart.\n";
          cout << "Enter C if you sit and wait for the trial to begin.\n";
          cin >> choice1;
          cin.ignore();
    }
}

void introduction(){
    cout << "It's been a strange day indeed. You've fallen down a rabbit hole, happened across a strange tea party, and had many other absurd adventures.\n";
    cout << "But now, you are called to a trial of some sort, ushered in by a Gryphon.\n";
    cout << "The King and Queen of Hearts are seated on their throne when you arrive, with a great crowd assembled about them — all sorts of little birds and beasts, as well as the whole pack of cards.\n";
    cout << "The White Rabbit is standing near the King, with a trumpet in one hand, and a scroll of parchment in the other.\n";
    cout << "In the very middle of the court is a table, with a large dish of tarts upon it. They look really good, making you feel quite hungry.\n";
    cout << "You see twelve jurors writing busily on slates. You wonder how they have anything to write down before the trial's begun.\n";
    cout << "*      *      *\n";
    cout << "What do you do?\n";

}

int main() {
    introduction();
    char choice = ' ';
    for(int i = 0; i < 3; i++){
        selection(choice);
        if(choice == 'a' || choice == 'A'){
            cout << "Excellent option!\n";
        }
        else if(choice == 'b' || choice == 'B'){
            cout << "You shall pass for now.\n";
        }
        else {
            cout << "You shall not pass.\n";
            return 0; 
        }
        choice = ' ';
    }
    cout << "You survived the trial!\n";
    return 0;
}
