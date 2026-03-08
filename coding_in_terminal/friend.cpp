

#include <iostream>
using namespace std;

class Job {
private:
    string jobname;
    float salary;
public:
    friend class Person;
    Job() {
        jobname = "Management Trainee";
        salary = 1800.00;
    }
};

class Person {
private:
    string name;
    int age;
public:
    void display(Job);
    void setData(string s, int a) {
        name = s;
        age = a;
    }
};

void Person::display(Job x) {
    cout << "Job name: " << x.jobname << endl;
    cout << "Salary: " << x.salary << endl;
}

int main() {
    Job myJob;
    Person me;
    me.setData("Kathy", 24);
    me.display(myJob);
    return 0;
}
