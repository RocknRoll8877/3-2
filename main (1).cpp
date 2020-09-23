#include <iostream>
#include <string>

using namespace std;



class Student{
private:
    string name;
    int missed;
    int id;
public:
    Student(): name ("Ivan Ivanov"), id(rand()%1000), missed(0){} 
    Student(string n, int m, int i){
    name = n;
    missed = m;
    id = i;
    }
    ~Student(){}
    friend void printStudent(Student obj);
    friend class Teacher;
    void rename(string& word){
        name = word;
    }
};


class Teacher{
public:
    void setMissed(Student& obj, int miss){
        obj.missed = miss;
    }
};

void printStudent(Student obj){
    cout << obj.id << ". " << obj.name << " - missed: " << obj.missed << endl;

}

int main(){
    Teacher teacher;
    Student obj1;
    printStudent(obj1);
    Student obj2("Petr Petrov", 5, 5);
    printStudent(obj2);
    int miss ,id;
    string name;
    cout << "Enter the name" << endl;
    cin >> name;
    cout << "Enter the id"<< endl;
    cin >> id;
    cout << "Enter the missings"<< endl;
    cin >> miss;
    if(miss < 0 || id < 0){
        cout << "Bad input"<< endl;
        return 0;
    }
    Student obj3(name, miss, id);
    printStudent(obj3);
    teacher.setMissed(obj1, 5);
    teacher.setMissed(obj2, 6);
    teacher.setMissed(obj3, 7);
    printStudent(obj1);
    printStudent(obj2);
    printStudent(obj3);
    Student arr[5];
    for(int i = 0; i < 5; i++){
        printStudent(arr[i]);
        teacher.setMissed(arr[i], i + 4);
        printStudent(arr[i]);
    }
    return 0;
}