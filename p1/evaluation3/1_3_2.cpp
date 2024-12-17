#include <iostream>
#include <cstring>
using namespace std;

class Employee{
    protected:
        int* id;
        int* age;
        char* name;
    
    public:
        Employee(int id, int age, const char* name);
        Employee(Employee&& other);
        Employee& operator=(Employee&& other);
        virtual ~Employee();
        virtual void swp(Employee& other);
        friend ostream& operator<<(ostream& out,const Employee& employee);
        
        
};

class Programmer : public Employee{
    private:
        string* tasks;
        int taskCount;
        
    public:
        Programmer(int id, int age, const char* name, string* tasks, int taskCount); 
        Programmer(Programmer&& other);
        Programmer& operator=(Programmer&& other);
        void swp(Employee& other) override; 
        friend ostream& operator<<(ostream& out, const Programmer& programmer);
        ~Programmer();
        
};

int main(){
    string tasks1[] = {"task1", "task2", "task3"};
    Employee *p1 = new Programmer(101, 22, "Athira", tasks1, 3);

    string tasks2[] = {"task4", "task5", "task6"};
    Employee *p2 = new Programmer(102, 23, "Bhagya", tasks2, 3);

    cout << "Before Swap:" << endl;
    cout << *p1 << endl;
    cout << *p2 << endl;
    
    p1->swp(*p2);

    cout << "\nAfter Swap:" << endl;
    cout << *p1 << endl;
    cout << *p2 << endl;

    delete p1;
    delete p2;

    return 0;
}


Employee::Employee(int id, int age, const char* name){
    this -> id = new int {id};
    this -> age = new int {age};
    this -> name = new char[strlen(name) + 1];
    strcpy(this -> name, name);
}

Employee::Employee(Employee&& other){
    this -> id = other.id;
    this -> age = other.age;
    this -> name = other.name;
    other.id = nullptr;
    other.age = nullptr;
    other.name = nullptr;
}

Employee& Employee::operator=(Employee&& other){
    delete this -> id;
    delete this -> age;
    delete[] this -> name;
    this -> id = other.id;
    this -> age = other.age;
    this -> name = other.name;
    other.id = nullptr;
    other.age = nullptr;
    other.name = nullptr;
    return *this;
}

Employee::~Employee(){
    delete this -> id;
    delete this -> age;
    delete[] this -> name;
}

void Employee::swp(Employee& other){
    Employee temp(move(*this));
    *this = move(other);
    other = move(temp);
}

ostream& operator<<(ostream& out, const Employee& employee){
    out << "ID: " << *(employee.id) << ", name: " << employee.name << ", age: " << *(employee.age);
    return out;
}

Programmer::Programmer(int id, int age, const char* name, string* tasks, int taskCount) : Employee(id, age, name), taskCount(taskCount){
    this -> tasks = new string[taskCount];
    for(int i = 0; i < taskCount; i++){
        this -> tasks[i] = tasks[i];
    }
}

Programmer::Programmer(Programmer&& other): Employee(move(other)) {
            this -> tasks = other.tasks;
            this -> taskCount = other.taskCount;
            other.tasks = nullptr;
            other.taskCount = 0; 
        }
        
Programmer& Programmer::operator=(Programmer&& other){
    Employee::operator=(move(other));
    delete[] this -> tasks;
    this -> tasks = other.tasks;
    this -> taskCount = other.taskCount;
    other.tasks = nullptr;
    other.taskCount = 0; 
    return *this;
}


Programmer::~Programmer(){
    delete[] tasks;
}

void Programmer::swp(Employee& other){
    // swp()
    Programmer* pOther = dynamic_cast<Programmer *>(&other);
    Programmer temp(move(*this));
    *this = move(*pOther);
    *pOther = move(temp);
}

ostream& operator<<(ostream& out, const Programmer& programmer){
    out << "ID: " << *(programmer.id) << ", name: " << programmer.name << ", age: " << *(programmer.age)
    << ", Tasks: " << programmer.taskCount << endl;
    
    for (int i = 0; i < programmer.taskCount; i++){
        out << programmer.tasks[i] << endl;
    }
    
    return out;
}