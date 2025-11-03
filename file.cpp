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

int main() {
    vector<Student*> v; char cmd[10];
    while (true) {
        cout << "Command (ADD, PRINT, DELETE, QUIT): ";
        cin >> cmd;
	if (!strcmp(cmd, "ADD")) {
            auto* s = new Student;
            cout << "First Last ID GPA: ";
            cin >> s->first >> s->last >> s->id >> s->gpa;
            v.push_back(s);
        } 
        else if (!strcmp(cmd, "PRINT")) {
            cout << fixed << setprecision(2);
            for (auto* s : v)
                cout << s->first << " " << s->last << ", " << s->id << ", " << s->gpa << endl;
        }
	else if (!strcmp(cmd, "DELETE")) {
            int id; cout << "ID: "; cin >> id;
            for (auto it = v.begin(); it != v.end(); ++it)
                if ((*it)->id == id) { delete *it; v.erase(it); break; }
        } 
        else if (!strcmp(cmd, "QUIT")) {
            for (auto* s : v) delete s;
            break;
        }
    }
}


