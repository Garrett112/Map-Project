#include "HashSchedule.h"


int main() {
    HashSchedule s;

    function<size_t(const std::string&)> hashFunction1 = [](const std::string& key) {
        size_t hash = 0;
        for (auto ch : key) {
            hash += ch;
        }
        return hash;
    };

    function<size_t(const std::string&)> hashFunction2 = [](const std::string& key) {
        return key[0] + 27 * key[1] + 729 * key[2];
    };

    function<size_t(const std::string&)> hashFunction3 = [](const std::string& key) {
        size_t hash = 0;
        for (char ch : key) {
            hash = 37 * hash + ch;
        }
        return hash;
    };
    
    function<size_t(const std::string&)> hashFunction4 = [](const std::string& key) {
        size_t hash = 0;
        const int p = 31;
        for (char c : key) {
            hash = (hash * p) + static_cast<size_t>(c);
        }
        return hash;
    };

    function<size_t(const std::string&)> hashFunction5 = [](const std::string& key) {
        size_t hash = 14695981039346656037U;
        const size_t prime = 1099511628211U;
        for (char c : key) {
            hash ^= static_cast<size_t>(c);
            hash *= prime;
        }
        return hash;
    };

    function<size_t(const std::string&)> hashFunction6 = [](const std::string& key) {
        size_t hash = key.length();
        const size_t m = 0x5bd1e995;
        const int r = 24;

        for (char c : key) {
            hash = (hash ^ static_cast<size_t>(c)) * m;
            hash = (hash ^ (hash >> r)) * m;
        }

        hash = hash ^ (hash >> 13);
        hash = hash * 0x5bd1e995;
        hash = hash ^ (hash >> 15);

        return hash;
    };

    int d;
    cout << "Please Select Hash Function." << endl
        << "Enter 0 for Default" << endl
        << "Enter 1 for Hash Function 1" << endl
        << "Enter 2 for Hash Function 2" << endl
        << "Enter 3 for Hash Function 3" << endl
        << "Enter 4 for Custom Hash Function 1" << endl
        << "Enter 5 for Custom Hash Function 2" << endl
        << "Enter 6 for Custom Hash Function 3" << endl
        << endl << "Your Selection: ";
    cin >> d;
    cout << endl << endl;
    if (d == 0) {
        cout << "Using Default Hash Function..." << endl << endl;
    }
    if (d == 1) {
        cout << "Using Hash Function 1..." << endl << endl;
        s.setHashFunction(hashFunction1);
    }
    if (d == 2) {
        cout << "Using Hash Function 2..." << endl << endl;
        s.setHashFunction(hashFunction2);
    }
    if (d == 3) {
        cout << "Using Hash Function 3..." << endl << endl;
        s.setHashFunction(hashFunction3);
    }
    if (d == 4) {
        cout << "Using Custom Hash Function 1..." << endl << endl;
        s.setHashFunction(hashFunction4);
    }
    if (d == 5) {
        cout << "Using Custom Hash Function 2..." << endl << endl;
        s.setHashFunction(hashFunction5);
    }
    if (d == 6) {
        cout << "Using Custom Hash Function 3..." << endl << endl;
        s.setHashFunction(hashFunction6);
    }
    s.menu();
    s.display();



}
