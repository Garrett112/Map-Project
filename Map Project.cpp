#include "schedule.h"

using namespace std;

int main() {
    schedule s;
    s.initSchedule();
    int w = 1;
    int c;
    string sub;
    string cat;
    string ins;
    while (w == 1) {
        cout << "Class Schedule Menu: " << endl
            << "Enter 1 to Print Schedule" << endl
            << "Enter 2 to Search by Subject" << endl
            << "Enter 3 to Search by Subject and Catalog" << endl
            << "Enter 4 to Search by Instructor" << endl
            << "Enter 5 to Quit" << endl << endl
            << "Your Input: ";
        cin >> c;
        cout << endl << endl;
        if (c == 1) {
            s.printHeader();
            s.print();
        }
        else if (c == 2) {
            cout << "Enter Subject: ";
            cin >> sub;
            cout << endl << endl;
            s.findSub(sub);
        }
        else if (c == 3) {
            cout << "Enter Subject: ";
            cin >> sub;
            cout << endl << "Enter Catalog: ";
            cin >> cat;
            cout << endl << endl;
            s.findSubCat(sub, cat);
        }
        else if (c == 4) {
            cout << "Enter Instructor: ";
            cin >> ins;
            cout << endl << endl;
            s.findIns(ins);
        }
        else if (c == 5) {
            cout << "Exiting...";
            w = 0;
        }
        else {
            cout << "Invalid Choice, Please Enter a Number 1-5." << endl;
        }
        cout << endl;
    }
}
