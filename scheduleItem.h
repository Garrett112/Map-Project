#pragma once
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class scheduleItem {
public:
	scheduleItem() {
		subject = "";
		catalog = "";
		section = "";
		component = "";
		session = "";
		units = 0;
		totenrl = 0;
		capenrl = 0;
		instructor = "";
	}
	void print() {
		cout << setw(10) << left << subject <<
			setw(10) << left << catalog <<
			setw(10) << left << section <<
			setw(12) << left << component <<
			setw(10) << left << session <<
			setw(8) << left << units <<
			setw(10) << left << totenrl <<
			setw(10) << left << capenrl <<
			setw(10) << left << instructor << endl;
	}

	void setSub(string s) {
		subject = s;
	}
	string getSub() {
		return subject;
	}
	void setCat(string c) {
		catalog = c;
	}
	string getCat() {
		return catalog;
	}
	void setSec(string s) {
		section = s;
	}
	string getSec() {
		return section;
	}
	void setCom(string c) {
		component = c;
	}
	string getCom() {
		return component;
	}
	void setSes(string s) {
		session = s;
	}
	string getSes() {
		return session;
	}
	void setUni(int u) {
		units = u;
	}
	int getUni() {
		return units;
	}
	void setTot(int t) {
		totenrl = t;
	}
	int getTot() {
		return totenrl;
	}
	void setCap(int c) {
		capenrl = c;
	}
	int getCap() {
		return capenrl;
	}
	void setIns(string i) {
		instructor = i;
	}
	string getIns() {
		return instructor;
	}

	bool operator==(const scheduleItem& other) {
		return (subject == other.subject && catalog == other.catalog && section == other.section);
	}

	bool operator!=(const scheduleItem& other) {
		return !(*this == other);
	}

	bool operator>=(const scheduleItem& other) {
		return (subject >= other.subject && catalog >= other.catalog && section >= other.section);
	}

private:
	string subject;
	string catalog;
	string section;
	string component;
	string session;
	int units;
	int totenrl;
	int capenrl;
	string instructor;
};

