#include <iostream>
#include <string>
using namespace std;

class StudentList{
    string name;
    int age,score;
    char grade;

public:
    StudentList() : name(""), grade('F'), age(0), score(0) {} //create a baseline (to allow array allocation)

    StudentList(string std_name,char std_grade,int std_age,int std_score)
    :name(std_name), grade(std_grade), age(std_age), score(std_score){}
    void display(){
        cout << endl << "Student Name: " <<name<<endl;
        cout << "Age: " <<age<<endl;
        cout << "Grade: " <<grade<<endl;
        cout << "Score: " <<score<<"\n\n\n";
    }
};

void grade(int &score,char &grade){
    if (score >= 80 && score <= 100){
        grade = 'A';
    }
    else if(score < 80 && score >= 70){
        grade = 'B';
    }
    else if(score < 70 && score >= 60){
        grade = 'C';
    }
    else if(score < 60 && score >= 50){
        grade = 'D';
    }
    else if(score < 50 && score >= 40){
        grade = 'E';
    }
    else{
        grade = 'F';
    }
}
int main(){
    int age1,score1,num_students;
    string name1;
    char grade1;

    cout <<"Number of students :";
    cin >> num_students;
    cin.ignore();

    StudentList students[100]; //sets boundary to 100

    for (int i = 0; i<num_students ; i++){
        cout << "State your full name: ";
        getline(cin,name1);
        cout << "State age: ";
        cin >>age1;
        cout << "State your average score: ";
        cin >> score1;

        cin.ignore();

        grade(score1,grade1);

        students[i] = StudentList(name1, grade1, age1, score1);
    }

    for(int i = 0; i < num_students; i++) {
        students[i].display();
    }

    return 0;  
}
