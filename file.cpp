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
