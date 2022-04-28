#include "Student.h"
#include "Student.cpp"
#include "DisjSet.h"
#include "DisjSet.cpp"

#include "DoubleHash.h"
#include "DoubleHash.cpp"
#include "utilities.h"
#include <vector>
#include "MergeSort.h"
#include "QuickSort.h"
#include "ShellSort.h"

void printStudent(int i, Student<string> student) {
    string lineStr;
    if (i < 10) {
        lineStr = " ----------------> ";
    } else {
        lineStr = " ---------------> ";
    }

    cout << i << lineStr << to_string(student.getId()) << "   " << student.getFirstName()
         << " " << student.getLastName() << "   " << student.getDepartment() << "   "
         << student.getGPA() << endl;
}

// Test program
int main() {
    cout << "--------------------------------------------------------------------" << endl;
    cout << "Assignment 08, Question 01 Nick Voss:" << endl;
    return 0;
}