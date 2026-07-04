#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
  cout << "MAGIC 8-BALL:\n\n";
  srand(time(NULL));
  int answer = rand() % 10; //to randomise num from 0-9
  cout << answer;
  if(answer==0){
    cout << "It is certain.\n";
  }
  else{
    cout << "Very doubtful.\n";
  }
}
