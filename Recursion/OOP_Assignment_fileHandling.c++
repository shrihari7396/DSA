//============================================================================
// Name        : Assignment_4.cpp
// Author      : Shrihari Kulkarni
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Student {
private:
public:
    int roll_no;
    string Name;
    Student() {
        roll_no = -1;
        Name = "";
    }
    friend istream& operator>> (istream& in, Student& s);
    friend ostream& operator<< (ostream& out, const Student& s);
};

istream& operator>> (istream& in, Student& s) {
    in >> s.roll_no >> s.Name;
    return in;
}

ostream& operator<< (ostream& out, Student& s) {
    out << s.roll_no << " " << s.Name << endl;
    return out;
}

int main() {
    
    ofstream fileWrite("Shrihari.txt");
    if(!fileWrite) {
        cerr << "File creation Error" << endl;
        return -1;
    }

    Student s1;
    int count = 1;
    string ch ;
    do {
        cout << "Enter Roll_no and Name of the "<< count << "th student: " << endl;
        cin >> s1;
        fileWrite << s1;
        cout << "If you want to add one more student details in the file press 'y' and hit Enter." << endl;
        cin >> ch ;
        count ++;
    } while(ch == "y");
    fileWrite.close();

    cout << "Students Readed from file " << endl;

    ifstream fileRead("Shrihari.txt");
    if(!fileRead) {
        cerr << "File Does not exit" << endl;
        return -1;
    }
    Student s2;

    while(!fileRead.eof()) {
        fileRead >> s2;

        if(fileRead.eof()) {
            break;
        }
        
        cout << s2;
    }

    fileRead.close();

    cout << s2;
    fileRead.close();
    
    return 0;
}