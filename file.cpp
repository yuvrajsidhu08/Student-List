/*
Yuvraj Sidhu
10/24/25
This program creates a student list
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <cstring>
using namespace std;

struct Student { char first[50], last[50]; int id; float gpa; };

// function prototypes
void addStudent(vector<Student*>& v);
void printStudents(const vector<Student*>& v);
void deleteStudent(vector<Student*>& v);
void quitProgram(vector<Student*>& v);

int main() {

  // stores student pointers
    vector<Student*> v; char cmd[10];
    while (true) {
        cout << "Command (ADD, PRINT, DELETE, QUIT): ";
        cin >> cmd;

        // Add a new student
        if (!strcmp(cmd, "ADD")) addStudent(v);

        // Print all students
        else if (!strcmp(cmd, "PRINT")) printStudents(v);

        // delete by the ID
        else if (!strcmp(cmd, "DELETE")) deleteStudent(v);

        // Free memory and then quit
        else if (!strcmp(cmd, "QUIT")) { quitProgram(v); break; }
    }
}

// Add a new student
void addStudent(vector<Student*>& v) {
    Student* s = new Student;
    cout << "First Last ID GPA: ";
    cin >> s->first >> s->last >> s->id >> s->gpa;
    v.push_back(s);
}

// Print all students
void printStudents(const vector<Student*>& v) {
    cout << fixed << setprecision(2);
    for (auto* s : v)
        cout << s->first << " " << s->last << ", " << s->id << ", " << s->gpa << endl;
}

// delete by the ID
void deleteStudent(vector<Student*>& v) {
    int id; cout << "ID: "; cin >> id;
    for (auto it = v.begin(); it != v.end(); ++it)
        if ((*it)->id == id) { delete *it; v.erase(it); break; }
}

// Free memory and then quit
void quitProgram(vector<Student*>& v) {
    for (auto* s : v) delete s;
}
