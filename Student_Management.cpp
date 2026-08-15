#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Student
{
    int id;
    string name;
    int age;
    string department;
};

void addStudent(vector<Student>& students)
{
    Student student;

    cout << "\n===== ADD STUDENT =====\n";

    cout << "Enter student ID: ";
    cin >> student.id;

    cin.ignore();

    cout << "Enter student name: ";
    getline(cin, student.name);

    cout << "Enter age: ";
    cin >> student.age;

    cin.ignore();

    cout << "Enter department: ";
    getline(cin, student.department);

    students.push_back(student);

    cout << "\nStudent added successfully!\n";
}

void viewStudents(const vector<Student>& students)
{
    cout << "\n===== STUDENT LIST =====\n";

    if (students.empty())
    {
        cout << "No students available.\n";
        return;
    }

    for (const Student& student : students)
    {
        cout << "\nID: " << student.id << endl;
        cout << "Name: " << student.name << endl;
        cout << "Age: " << student.age << endl;
        cout << "Department: " << student.department << endl;
        cout << "-------------------------\n";
    }
}

void searchStudent(const vector<Student>& students)
{
    int id;

    cout << "\n===== SEARCH STUDENT =====\n";

    cout << "Enter student ID: ";
    cin >> id;

    for (const Student& student : students)
    {
        if (student.id == id)
        {
            cout << "\nStudent Found!\n";
            cout << "ID: " << student.id << endl;
            cout << "Name: " << student.name << endl;
            cout << "Age: " << student.age << endl;
            cout << "Department: " << student.department << endl;

            return;
        }
    }

    cout << "\nStudent not found!\n";
}

void deleteStudent(vector<Student>& students)
{
    int id;

    cout << "\n===== DELETE STUDENT =====\n";

    cout << "Enter student ID: ";
    cin >> id;

    for (auto it = students.begin();
         it != students.end();
         ++it)
    {
        if (it->id == id)
        {
            students.erase(it);

            cout << "\nStudent deleted successfully!\n";

            return;
        }
    }

    cout << "\nStudent not found!\n";
}

int main()
{
    vector<Student> students;

    int choice;

    cout << "==============================\n";
    cout << "    STUDENT MANAGEMENT SYSTEM \n";
    cout << "==============================\n";

    do
    {
        cout << "\n1. Add Student";
        cout << "\n2. View Students";
        cout << "\n3. Search Student";
        cout << "\n4. Delete Student";
        cout << "\n5. Exit";

        cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                addStudent(students);
                break;

            case 2:
                viewStudents(students);
                break;

            case 3:
                searchStudent(students);
                break;

            case 4:
                deleteStudent(students);
                break;

            case 5:
                cout << "\nGoodbye!\n";
                break;

            default:
                cout << "\nInvalid choice! Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}