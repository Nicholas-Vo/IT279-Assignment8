#include "Student.h"

using namespace std;

template<typename Comparable>
Comparable Student<Comparable>::getFirstName() {
    return fname;
}

template<typename Comparable>
Comparable Student<Comparable>::getLastName() {
    return lname;
}

template<typename Comparable>
Comparable Student<Comparable>::getDepartment() {
    return department;
}

template<typename Comparable>
Comparable Student<Comparable>::getGPA() {
    return gpa;
}

template<typename Comparable>
void Student<Comparable>::setFirstName(Comparable name) {
    fname = name;
}

template<typename Comparable>
void Student<Comparable>::setLastName(Comparable name) {
    lname = name;
}

template<typename Comparable>
void Student<Comparable>::setDepartment(Comparable dept) {
    department = dept;
}

template<typename Comparable>
void Student<Comparable>::setGPA(Comparable val) {
    gpa = val;
}

template<typename Comparable>
void Student<Comparable>::setId(int val) {
    id = val;
}

template<typename Comparable>
void Student<Comparable>::setBucketId(int val) {
    bucketId = val;
}

template<typename Comparable>
int Student<Comparable>::getBucketId() {
    return bucketId;
}

template<typename Comparable>
int Student<Comparable>::getId() {
    return id;
}

//template<typename Comparable>
//Student<Comparable>::Student() {
//
//}



