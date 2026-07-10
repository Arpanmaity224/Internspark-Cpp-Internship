#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;

class Student {
public:
    int id;
    string name;
    float marks;
};

vector<Student> students;

// Load data from file
void loadStudents() {
    ifstream file("student.txt");

    Student s;
    while (file >> s.id >> s.name >> s.marks) {
        students.push_back(s);
    }

    file.close();
}

// Save data to file
void saveStudents() {
    ofstream file("student.txt");

    for (Student s : students) {
        file << s.id << " "
             << s.name << " "
             << s.marks << endl;
    }

    file.close();
}

// Add Student
void addStudent() {
    Student s;

    cout << "\nEnter Student ID: ";
    cin >> s.id;

    cout << "Enter Student Name: ";
    cin >> s.name;

    cout << "Enter Marks: ";
    cin >> s.marks;

    students.push_back(s);

    cout << "\nStudent Added Successfully!\n";
}
// View Students
void viewStudents() {

    if (students.empty()) {
        cout << "\nNo Student Records Found!\n";
        return;
    }

    cout << "\n---------------------------------------------\n";
    cout << left << setw(10) << "ID"
         << setw(20) << "Name"
         << setw(10) << "Marks" << endl;
    cout << "---------------------------------------------\n";

    for (Student s : students) {
        cout << left << setw(10) << s.id
             << setw(20) << s.name
             << setw(10) << s.marks << endl;
    }
}

// Search Student
void searchStudent() {

    int searchId;
    cout << "\nEnter Student ID to Search: ";
    cin >> searchId;

    for (Student s : students) {

        if (s.id == searchId) {

            cout << "\nStudent Found\n";
            cout << "ID    : " << s.id << endl;
            cout << "Name  : " << s.name << endl;
            cout << "Marks : " << s.marks << endl;

            return;
        }
    }

    cout << "\nStudent Not Found!\n";
}
// Delete Student
void deleteStudent() {

    int deleteId;
    cout << "\nEnter Student ID to Delete: ";
    cin >> deleteId;

    bool found = false;

    for (int i = 0; i < students.size(); i++) {

        if (students[i].id == deleteId) {

            students.erase(students.begin() + i);

            cout << "\nStudent Deleted Successfully!\n";

            found = true;
            break;
        }
    }

    if (!found) {
        cout << "\nStudent Not Found!\n";
    }
}

int main() {

    loadStudents();

    int choice;

    do {

        cout << "\n======================================";
        cout << "\n   Student Management System";
        cout << "\n======================================";
        cout << "\n1. Add Student";
        cout << "\n2. View Students";
        cout << "\n3. Search Student";
        cout << "\n4. Delete Student";
        cout << "\n5. Save Data";
        cout << "\n6. Exit";
        cout << "\nEnter Your Choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            addStudent();
            break;

        case 2:
            viewStudents();
            break;

        case 3:
            searchStudent();
            break;

        case 4:
            deleteStudent();
            break;

        case 5:
            saveStudents();
            cout << "\nData Saved Successfully!\n";
            break;

        case 6:
            saveStudents();
            cout << "\nThank You!\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while (choice != 6);

    return 0;
}