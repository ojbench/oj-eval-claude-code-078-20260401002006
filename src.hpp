#ifndef SRC_HPP
#define SRC_HPP

#include <iostream>
using namespace std;

class Evil{
private:
	int st, ed, val;
	int *data;

public:
    // Default constructor
    Evil() : st(0), ed(0), val(0) {
        data = new int[1];
        data[0] = 0;
    }

    // Parameterized constructor
    Evil(int st, int ed, int val) : st(st), ed(ed), val(val) {
        int size = ed - st + 1;
        data = new int[size];
        for (int i = 0; i < size; ++i) {
            data[i] = 0;
        }
    }

    // Copy constructor
    Evil(const Evil& other) : st(other.st), ed(other.ed), val(other.val) {
        int size = ed - st + 1;
        data = new int[size];
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    // Assignment operator overload
    Evil& operator=(const Evil& other) {
        if (this != &other) {
            // Delete old data
            delete[] data;

            // Copy values
            st = other.st;
            ed = other.ed;
            val = other.val;

            // Allocate new data
            int size = ed - st + 1;
            data = new int[size];
            for (int i = 0; i < size; ++i) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    // Subscript operator overload (returns reference for both read and write)
    int& operator[](int i) {
        if (i < st || i > ed) {
            return data[0]; // Return first element if out of bounds
        }
        return data[i - st];
    }

    // Prefix ++ operator
    Evil& operator++() {
        ++val;
        return *this;
    }

    // Postfix ++ operator
    Evil operator++(int) {
        Evil temp(*this);
        ++val;
        return temp;
    }

    // Output operator overload
    friend ostream& operator<<(ostream& os, const Evil& e) {
        os << e.val << " ";
        for (int i = 0; i < e.ed - e.st + 1; ++i) {
            os << e.data[i] << " ";
        }
        os << endl;
        return os;
    }

    // Destructor
    ~Evil() {
        delete[] data;
    }

    void Print(){
	    cout << val << " ";
	    for(int i = 0;i < ed-st+1;++i)
	        cout << data[i] <<" ";
	    cout << endl;
	}
};

#endif//SRC_HPP
