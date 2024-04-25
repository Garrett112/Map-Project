#pragma once
#include "scheduleItem.h"
#include <vector>
#include <fstream>
#include <iomanip>
#include <map>
#include <iterator>
#include <utility>

class schedule {
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
            addEntry(key, newItem);
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

    void addEntry(string k, scheduleItem i) {
        classes[k] = i;
    }

    void print() {
        for (auto it = classes.begin(); it != classes.end(); ++it) {
            ((scheduleItem&)it->second).print();
        }
    }

    void findSub(string sub) {
        for (auto it = classes.begin(); it != classes.end(); ++it) {
            if (it->first.find(sub) != string::npos) {
                it->second.print();
            }
        }
    }

    void findSubCat(string sub, string cat) {
        for (auto it = classes.begin(); it != classes.end(); ++it) {
            if (it->first.find(sub) && it->first.find(cat) != string::npos) {
                it->second.print();
            }
        }
    }

    void findIns(string ins) {
        for (auto it = classes.begin(); it != classes.end(); ++it) {

            if (it->second.getIns().find(ins) != string::npos) {
                it->second.print();
            }
        }
    }

private:
    map<string, scheduleItem> classes;
};

