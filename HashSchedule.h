#pragma once
#include "HashTable.h"
#include "scheduleItem.h"
#include <fstream>
#include <iomanip>

using namespace std;

class HashSchedule {
private:
    HashTable<string, scheduleItem> schedule;
public:
    void initSchedule() {
        ifstream file("Text.txt");                           //Opens file

        int subjectNum = 0;
        int catalogNum = 0;
        int sectionNum = 0;
        int componentNum = 0;
        int sessionNum = 0;
        int unitNum = 0;
        int totNum = 0;
        int capNum = 0;
        int instructNum = 0;

        string line;
        getline(file, line);                                //gets the first line of the file
        int l = line.length();                              //finds the length of the line
        char* ex = new char[l + 1];                         //creates a character array for the line
        strcpy(ex, line.c_str());                           //turns the line into an array of characters
        int entryNum = 1;                                   //sets entry counter to 1
        string temp = "";                                   //creates a string value "temp"
        for (int i = 0; i < l; ++i) {                       //for each character in the array
            if (ex[i] == ',') {                                 //if it is a comma
                if (temp == "Subject") {                            //if temp is "Subject"
                    subjectNum = entryNum;                              //set the placement of Subject to the current entry
                }
                else if (temp == "Catalog") {                       //if temp is "Catalog"
                    catalogNum = entryNum;                              //set the placement of Catalog to the current entry
                }
                else if (temp == "Section") {                       //if temp is "Section"
                    sectionNum = entryNum;                              //set the placement of Section to the current entry
                }
                else if (temp == "Component") {                     //if temp is "Component"
                    componentNum = entryNum;                            //set the placement of Component to the current entry
                }
                else if (temp == "Session") {                       //if temp is "Session"
                    sessionNum = entryNum;                              //set the placement of Session to the current entry
                }
                else if (temp == "Units") {                         //if temp is "Units"
                    unitNum = entryNum;                                 //set the placement of Units to the current entry
                }
                else if (temp == "TotEnrl") {                       //if temp is "TotEnrl"
                    totNum = entryNum;                                  //set the placement of TotEnrl to the current entry
                }
                else if (temp == "CapEnrl") {                       //if temp is "CapEnrl"
                    capNum = entryNum;                                  //set the placement of CapEnrl to the current entry
                }
                else if (temp == "Instructor") {                    //if temp is "Instructor"
                    instructNum = entryNum;                             //set the placement of Instructor to the current entry
                }
                else {                                              //else do nothing
                }
                i++;                                                //moves to the next character
                temp = ex[i];                                       //sets temp equal to the character
                entryNum++;                                         //increases entry number counter by one
            }
            else {                                              //else
                temp.push_back(ex[i]);                              //add the current character to the end of temp
            }
        }

        while (getline(file, line)) {                       //While there are lines to be read
            scheduleItem newItem;                               //Create a new scheduleItem
            temp = "";                                          //set temp equal to ""
            entryNum = 1;                                       //set entry counter to 1
            strcpy(ex, line.c_str());                           //turn the line into a character array
            for (int i = 0; i < l; ++i) {                       //for each character
                if (ex[i] == ',') {                                 //if the character is a comma
                    if (entryNum == subjectNum) {                       //if the entry number matches where the subject should be
                        newItem.setSub(temp);                               //set the new subject to temp
                    }
                    else if (entryNum == catalogNum) {                  //if the entry number matches where the catalog should be
                        newItem.setCat(temp);                               //set the new catalog to temp
                    }
                    else if (entryNum == sectionNum) {                  //if the entry number matches where the section should be
                        newItem.setSec(temp);                               //set the new section to temp
                    }
                    else if (entryNum == componentNum) {                //if the entry number matches where the component should be
                        newItem.setCom(temp);                               //set the new component to temp
                    }
                    else if (entryNum == sessionNum) {                  //if the entry number matches where the session should be
                        newItem.setSes(temp);                               //set the new session to temp
                    }
                    else if (entryNum == unitNum) {                     //if the entry number matches where the units should be
                        newItem.setUni(stoi(temp));                         //set the new units to temp
                    }
                    else if (entryNum == totNum) {                      //if the entry number matches where the totenrl should be
                        newItem.setTot(stoi(temp));                         //set the new totenrl to temp
                    }
                    else if (entryNum == capNum) {                      //if the entry number matches where the capenrl should be
                        newItem.setCap(stoi(temp));                         //set the new capenrl to temp
                    }
                    else if (entryNum == instructNum) {                 //if the entry number matches where the instructor should be
                        newItem.setIns(temp);                               //set the new instructor to temp
                    }
                    entryNum++;                                         //increases entry counter by 1
                    i++;                                                //moves to the next character
                    if (ex[i] == '"') {                                 //if the next character is a quotation
                        i++;                                                //move to the next character again
                        temp = ex[i];                                       //set temp equal to the character
                        i++;                                                //move to the next character again
                        while (ex[i] != '"') {                              //while the character is not a quotation
                            temp.push_back(ex[i]);                              //add the character to the end of temp
                            i++;                                                //move to the next character
                        }
                    }
                    else {                                              //else
                        temp = ex[i];                                       //set temp equal to the character
                    }
                }
                else {                                              //else
                    temp.push_back(ex[i]);                              //add the character to the end of temp
                }
            }
            string key = newItem.getSub() + "_" + newItem.getCat() + "_" + newItem.getSec();
            schedule.insert(key, newItem);
        }
        file.close();
    }
    void printHeader() {
        cout << setw(10) << left << "Subject" <<
            setw(10) << left << "Catalog" <<
            setw(10) << left << "Section" <<
            setw(12) << left << "Component" <<
            setw(10) << left << "Session" <<
            setw(8) << left << "Units" <<
            setw(10) << left << "TotEnrl" <<
            setw(10) << left << "CapEnrl" <<
            setw(10) << left << "Instructor" << endl;
    }
    void print() {
        for (size_t i = 0; i < schedule.getSize(); i++) {
            vector<scheduleItem> v = schedule.getByIndex(i);
            for (auto& it : v) {
                it.print();
            }
        }
    }
    void findSub(string sub) {
        for (size_t i = 0; i < schedule.getSize(); i++) {
            vector<scheduleItem> v = schedule.getByIndex(i);
            for (auto& it : v) {
                if (it.getSub() == sub) {
                    it.print();
                }
            }
        }
    }
    void findSubCat(string sub, string cat) {
        for (size_t i = 0; i < schedule.getSize(); i++) {
            vector<scheduleItem> v = schedule.getByIndex(i);
            for (auto& it : v) {
                if (it.getSub() == sub && it.getCat() == cat) {
                    it.print();
                }
            }
        }
    }
    void findIns(string ins) {
        for (size_t i = 0; i < schedule.getSize(); i++) {
            vector<scheduleItem> v = schedule.getByIndex(i);
            for (auto& it : v) {
                string temp = it.getIns();
                if (temp.find(ins) != string::npos) {
                    it.print();
                }
            }
        }
    }
    void statistics() {
        cout << "Hash Table Statistics:" << endl;
        cout << "Size: " << schedule.getSize() << endl;
        cout << "Number of Buckets: " << schedule.getBuckets() << endl;
        cout << "Load Factor: " << schedule.getLoadFactor() << endl;
        cout << "Number of Collisions: " << schedule.countCollisions() << endl;
        cout << "Length of Longest Chain: " << schedule.maxBucketSize() << endl;
    }
    void setHashFunction(function<size_t(const string&)> hashFunc) {
        schedule.setHashFunction(hashFunc);
    }
    size_t hash(const string& key) {
        return schedule.hash(key);
    }
    void menu() {
        initSchedule();
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
                << "Enter 5 to Display Hash Statistics" << endl
                << "Enter 6 to Quit" << endl << endl
                << "Your Input: ";
            cin >> c;
            cout << endl << endl;
            if (c == 1) {
                printHeader();
                print();
            }
            else if (c == 2) {
                cout << "Enter Subject: ";
                cin >> sub;
                cout << endl << endl;
                findSub(sub);
            }
            else if (c == 3) {
                cout << "Enter Subject: ";
                cin >> sub;
                cout << endl << "Enter Catalog: ";
                cin >> cat;
                cout << endl << endl;
                findSubCat(sub, cat);
            }
            else if (c == 4) {
                cout << "Enter Instructor: ";
                cin >> ins;
                cout << endl << endl;
                findIns(ins);
            }
            else if (c == 5) {
                statistics();
            }
            else if (c == 6) {
                cout << "Exiting...";
                w = 0;
            }
            else {
                cout << "Invalid Choice, Please Enter a Number 1-6." << endl;
            }
            cout << endl;
        }
    }
    void display() {
        schedule.display();
    }
};

