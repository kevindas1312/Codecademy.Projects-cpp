#include <iostream>
#include <vector>
using namespace std;

void greet(){ //introduction OR greet function
    cout <<"=============\n";
    cout << "UFO: The Game\n";
    cout << "=============\n";
    cout << "Instructions: save your friend from alien abduction by guessing the letters in the codeword.\n\n";
}

void end_game(string answer, string codeword){ //function that has IF selection to determine if the user was able to determine the characters in keyword
    if (answer == codeword) {
        cout << "Hooray! You saved your friend and earned a medal of honor!\n";
    } 
    else {
        cout << "Oh no! The UFO just flew away with another person!\n";
    }
}

void display_status(vector <char> incorrect, string answer){ //function used to return the characters of incorrect guesses
    cout << "Incorrect guesses: \t";
    for(int i=0; i<incorrect.size();i++){
        cout << incorrect[i] << " ";
    }

    cout << "Codeword: \t";
    for(int j=0; j<answer.length();j++){
        cout << answer[j] << " ";
    }
}

void display_misses(int misses){ //tried to use ASCII art to display number of misses(abit stuck here)
    cout<< "\n__    __                          __                                             ______                       __                                         \n";
    cout<<"|  |  |  |                       |  |                                           /      |                     |  |                                        \n";
    cout<<"| $$| | $$ __    __  ______ ____  | $$____    ______    ______          ______  |  $$$$$$|      ______ ____   |$$  _______   _______   ______    _______ \n";
    cout<<"| $$$|| $$|  |  |  ||      |   || $$    | /      |  /      |        /      | | $$_  |$$      |      |    | |  | /       | /       | /      |  /       \n";
    cout<<"| $$$$| $$| $$  | $$| $$$$$$|$$$$|| $$$$$$$| |$$$$$$||  $$$$$$|      |  $$$$$$|| $$ |          | $$$$$$|$$$$|| $$|  $$$$$$$|  $$$$$$$|  $$$$$$||  $$$$$$$\n";
    cout<<"| $$|$$ $$| $$  | $$| $$ | $$ | $$| $$  | $$| $$    $$| $$   |$$      | $$  | $$| $$$$          | $$ | $$ | $$| $$ |$$    |  |$$    | | $$    $$ |$$    | \n";
    cout<<"| $$ |$$$$| $$__/ $$| $$ | $$ | $$| $$__/ $$| $$$$$$$$| $$            | $$__/ $$| $$            | $$ | $$ | $$| $$ _|$$$$$$| _|$$$$$$|| $$$$$$$$ _|$$$$$$\n";
    cout<<"| $$  |$$$ |$$    $$| $$ | $$ | $$| $$    $$ $$     || $$             |$$    $$| $$            | $$ | $$ | $$| $$|       $$|       $$ |$$     ||       $$\n";
    cout<<" |$$   |$$  |$$$$$$  |$$  |$$  |$$ |$$$$$$$   |$$$$$$$ |$$              |$$$$$$  |$$             |$$  |$$  |$$ |$$ |$$$$$$$  |$$$$$$$   |$$$$$$$ |$$$$$$$ \n";
                                                                                                                                                          
    cout << misses ;                                                                                                                                                                                                                                                                                                   
}

int main(){
    string codeword = "codecademy";
    string answer = "__________";
    int misses = 0;
    vector <char> incorrect;
    bool guess = false;
    char letter;

    greet();

    while(misses < 7 && answer != codeword){
        display_misses(misses);
        display_status(incorrect,answer);

        cout << "\n\nPlease enter your guess: ";
        cin >> letter;

        for (int k = 0; k < codeword.length(); k++) {
            if(letter == codeword[k]){
                answer = letter;
                guess = true;
            }
        }

        if (guess) {
            cout << "\nCorrect! You're closer to cracking the codeword.\n";
        } else {
            cout << "\nIncorrect! The tractor beam pulls the person in further.\n";
            incorrect.push_back(letter);
            misses++;
        }

        guess = false;
    }

    end_game(answer,codeword);

}
