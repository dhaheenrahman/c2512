#include <iostream>
#include <string>
#include <cstring>
#include <memory>

using namespace std;

class Employee
{
private:
    int *id;
    int *age;
    char *name;

public:
    Employee();
    Employee(int id, int age, const char *name);
    Employee(Employee &&other);
    Employee &operator=(Employee &&other);
    virtual ~Employee();
    virtual void swp(Employee &other);
    friend ostream &operator<<(ostream &out, const Employee &employee);
    friend istream &operator>>(istream &in, Employee &employee);
};

class Programmer : public Employee
{
private:
    string *tasks;
    int *taskCount;

public:
    Programmer();
    Programmer(int v_id, int v_age, const char *v_name, string *v_tasks, int v_taskCount);
    Programmer(Programmer &&other);
    Programmer &operator=(Programmer &&other);
    ~Programmer();
    void swp(Employee &other) override;
    friend ostream &operator<<(ostream &out, const Programmer &programmer);
    friend istream &operator>>(istream &in, Programmer &programmer);

};

int main()
{
    Programmer programmers[2];
    cin >> programmers[0];
    cin >> programmers[1];

    cout << programmers[0] << endl;
    cout << programmers[1] << endl;
    
    return 0;
}

Employee::Employee()
{
    id = nullptr;
    age = nullptr;
    name = nullptr;
}

Employee::Employee(int id, int age, const char *name)
{
    this->id = new int{id};
    this->age = new int{age};
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

Employee::Employee(Employee&& other)
{
    this->id = other.id;
    this->age = other.age;
    this->name = other.name;
    other.id = nullptr;
    other.age = nullptr;
    other.name = nullptr;
}

Employee& Employee::operator=(Employee&& other)
{
    if (this != &other)
    {
        delete this->id;
        delete this->age;
        delete[] this->name;
        this->id = other.id;
        this->age = other.age;
        this->name = other.name;
        other.id = nullptr;
        other.age = nullptr;
        other.name = nullptr;
    }
    return *this;
}

Employee::~Employee()
{
    delete this->id;
    delete this->age;
    delete[] this->name;
}

void Employee::swp(Employee& other)
{
    Employee temp(move(*this));
    *this = move(other);
    other = move(temp);
}

ostream &operator<<(ostream &out, const Employee &employee)
{
    out << "ID: " << *(employee.id) << ", Name: " << employee.name << ", Age: " << *(employee.age);
    return out;
}

istream &operator>>(istream &in, Employee &employee)
{
    int tempId, tempAge;
    string tempName;

    cout << "Enter ID: ";
    in >> tempId;

    cout << "Enter Age: ";
    in >> tempAge;

    cout << "Enter Name: ";
    in.ignore();
    getline(in, tempName);

    delete employee.id;
    delete employee.age;
    delete[] employee.name;

    employee.id = new int(tempId);
    employee.age = new int(tempAge);
    employee.name = new char[tempName.length() + 1];
    strcpy(employee.name, tempName.c_str());

    return in;
}


Programmer::Programmer() : Employee()
{
    taskCount = nullptr;
    tasks = nullptr;
}

Programmer::Programmer(int v_id, int v_age, const char *v_name, string *v_tasks, int v_taskCount) : Employee(v_id, v_age, v_name){
    this->taskCount = new int{v_taskCount};
    this->tasks = new string[v_taskCount];
    
    for (int i = 0; i < v_taskCount; i++)
    {
        this->tasks[i] = v_tasks[i];
    }
}

Programmer::Programmer(Programmer &&other) : Employee(move(other)){
    this->taskCount = other.taskCount;
    this->tasks = other.tasks;
    other.taskCount = nullptr;
    other.tasks = nullptr;
}

Programmer& Programmer::operator=(Programmer &&other){
    if (this != &other)
    {
        Employee::operator=(move(other));
        delete this->taskCount;
        delete[] this->tasks;
        this->taskCount = other.taskCount;
        this->tasks = other.tasks;
        other.taskCount = nullptr;
        other.tasks = nullptr;
    }
    return *this;
}

Programmer::~Programmer(){
    delete taskCount;
    delete[] tasks;
}

void Programmer::swp(Employee &other) {
    Programmer *pOther = dynamic_cast<Programmer *>(&other);
    Programmer temp(move(*this));
    *this = move(*pOther);
    *pOther = move(temp);
}
    
ostream &operator<<(ostream &out, const Programmer& programmer){
    out << static_cast<const Employee &>(programmer);
    out << ", Task Count: " << *(programmer.taskCount) << ", Tasks: [";
    for (int i = 0; i < *(programmer.taskCount); i++)
    {
        out << programmer.tasks[i];
        if (i < *(programmer.taskCount) - 1)
            out << ", ";
    }
    out << "]";
    return out;
}
    
istream &operator>>(istream &in, Programmer &programmer)
{
    in >> static_cast<Employee &>(programmer);

    int tempTaskCount;
    cout << "Enter Task Count: ";
    in >> tempTaskCount;

    delete programmer.taskCount;
    delete[] programmer.tasks;

    programmer.taskCount = new int(tempTaskCount);
    programmer.tasks = new string[tempTaskCount];

    cout << "Enter Tasks:\n";
    in.ignore();
    for (int i = 0; i < tempTaskCount; ++i)
    {
        cout << "Task " << (i + 1) << ": ";
        getline(in, programmer.tasks[i]);
    }

    return in;
}
