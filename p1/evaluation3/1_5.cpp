#include <iostream>
#include <string>
#include <memory>
#include <cstring>

using namespace std;

class Employee
{
private:
    unique_ptr<int> id;
    unique_ptr<int> age;
    unique_ptr<char[]> name;

public:
    Employee(int id = 0, int age = 0, const char *name = "") // Default constructor
    {
        this->id = make_unique<int>(id);
        this->age = make_unique<int>(age);
        this->name = make_unique<char[]>(strlen(name) + 1);
        strcpy(this->name.get(), name);
    }

    Employee(Employee &&other) noexcept
        : id(move(other.id)), age(move(other.age)), name(move(other.name)) {}

    Employee &operator=(Employee &&other) noexcept
    {
        if (this != &other)
        {
            id = move(other.id);
            age = move(other.age);
            name = move(other.name);
        }
        return *this;
    }

    virtual ~Employee() = default;

    virtual void swp(Employee &other)
    {
        Employee temp(move(*this));
        *this = move(other);
        other = move(temp);
    }

    friend ostream &operator<<(ostream &out, const Employee &employee)
    {
        out << "ID: " << *(employee.id) << ", Name: " << employee.name.get() << ", Age: " << *(employee.age);
        return out;
    }

    friend istream &operator>>(istream &in, Employee &employee);
};

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

    employee.id = make_unique<int>(tempId);
    employee.age = make_unique<int>(tempAge);
    employee.name = make_unique<char[]>(tempName.length() + 1);
    strcpy(employee.name.get(), tempName.c_str());

    return in;
}

class Programmer : public Employee
{
private:
    unique_ptr<string[]> tasks;
    unique_ptr<int> taskCount;

public:
    Programmer(int id = 0, int age = 0, const char *name = "", string *v_tasks = nullptr, int v_taskCount = 0)
        : Employee(id, age, name)
    {
        taskCount = make_unique<int>(v_taskCount);
        tasks = make_unique<string[]>(v_taskCount);
        for (int i = 0; i < v_taskCount; i++)
        {
            tasks[i] = v_tasks[i];
        }
    }

    Programmer(Programmer &&other) noexcept
        : Employee(move(other)), tasks(move(other.tasks)), taskCount(move(other.taskCount)) {}

    Programmer &operator=(Programmer &&other) noexcept
    {
        if (this != &other)
        {
            Employee::operator=(move(other));
            tasks = move(other.tasks);
            taskCount = move(other.taskCount);
        }
        return *this;
    }

    void swp(Employee &other) override
    {
        if (Programmer *pOther = dynamic_cast<Programmer *>(&other))
        {
            Programmer temp(move(*this));
            *this = move(*pOther);
            *pOther = move(temp);
        }
        else
        {
            throw runtime_error("Incompatible types for swapping.");
        }
    }

    friend ostream &operator<<(ostream &out, const Programmer &programmer)
    {
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

    friend istream &operator>>(istream &in, Programmer &programmer);
};

istream &operator>>(istream &in, Programmer &programmer)
{
    in >> static_cast<Employee &>(programmer);

    int tempTaskCount;
    cout << "Enter Task Count: ";
    in >> tempTaskCount;

    unique_ptr<string[]> tempTasks = make_unique<string[]>(tempTaskCount);
    cout << "Enter Tasks:\n";
    in.ignore();
    for (int i = 0; i < tempTaskCount; ++i)
    {
        cout << "Task " << (i + 1) << ": ";
        getline(in, tempTasks[i]);
    }

    programmer.taskCount = make_unique<int>(tempTaskCount);
    programmer.tasks = move(tempTasks);

    return in;
}

int main()
{
    Programmer programmers[2];

    cout << "Enter details for Programmer 1:\n";
    cin >> programmers[0];

    cout << "\nEnter details for Programmer 2:\n";
    cin >> programmers[1];

    cout << "\nProgrammer 1 Details:\n" << programmers[0] << endl;
    cout << "\nProgrammer 2 Details:\n" << programmers[1] << endl;

    return 0;
}
