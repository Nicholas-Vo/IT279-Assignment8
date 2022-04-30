//
// Created by nvoss on 4/28/2022.
//

#include "DoubleHash.h"

template<typename HashedObj>
DoubleHash<HashedObj>::DoubleHash(int size) {
    hashTable = new int[size]; // make a hashtable using this size
    tableSize = size;
    curr_size = 0;

    for (int i = 0; i < size; i++) {
        hashTable[i] = -1;
    }
}

template<typename HashedObj>
bool DoubleHash<HashedObj>::isFull() {
    return curr_size == tableSize;
}

template<typename HashedObj>
int DoubleHash<HashedObj>::hash1(HashedObj key) {
    return key % tableSize;
}

template<typename HashedObj>
int DoubleHash<HashedObj>::hash2(HashedObj key) {
    return prime - (key % prime);
}

template<typename HashedObj>
void DoubleHash<HashedObj>::insertHash(Student<string> &val) {
    if (isFull()) {
        return;
    }

    int index = hash1(val);
    if (hashTable[index] != -1) {
        int index2 = hash2(val);
        curr_size++;

        int i = 1;
        while (true) {
            int place = (index + i * index2) % tableSize;
            if (hashTable[place] == -1) {
                hashTable[place] = val;
                break;
            }
            i++;
        }
        return;
    }

    hashTable[index] = val;
    curr_size++;
}

template<typename HashedObj>
bool DoubleHash<HashedObj>::search(HashedObj key, HashedObj &bucketId, Student<string> &val) {
    int i1 = hash1(key);
    int i2 = hash2(key);
    int i = 0;

    while (hashTable[(i1 + i * i2) % tableSize] != key) {
        if (hashTable[(i1 + i * i2) % tableSize] == -1) {
            cout << "Key not found in hash: " << key << endl;
            return false;
        }
        i++;
    }
    cout << "Key found in hash: " << key << endl;
    return true;
}

template<typename HashedObj>
bool DoubleHash<HashedObj>::search(HashedObj bucketId, Student<string> &val) {

}

template<typename HashedObj>
Student<string> DoubleHash<HashedObj>::getStudent(HashedObj bucketId) {
    return hashTable[hash1(bucketId)];
}

template<typename HashedObj>
bool DoubleHash<HashedObj>::update(Student<string> &val) {
}

template<typename HashedObj>
void DoubleHash<HashedObj>::displayHash() {
    for (int i = 0; i < tableSize; i++) {
        if (hashTable[i] != -1) {
            cout << i << " -> " << hashTable[i] << endl;
        } else {
            cout << i << endl;
        }
    }
}

template<typename HashedObj>
bool DoubleHash<HashedObj>::isSameDept(Student<string> std1, Student<string> std2) {
    return false;
}
