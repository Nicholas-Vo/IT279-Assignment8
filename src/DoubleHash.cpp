//
// Created by nvoss on 4/28/2022.
//

#include "DoubleHash.h"

template<typename HashedObj>
DoubleHash<HashedObj>::DoubleHash(int size) {
    curr_size = size;
}

template<typename HashedObj>
bool DoubleHash<HashedObj>::isFull() {
    return 0;
}

template<typename HashedObj>
int DoubleHash<HashedObj>::hash1(HashedObj key) {
    return 0;
}

template<typename HashedObj>
int DoubleHash<HashedObj>::hash2(HashedObj key) {
    return 0;
}
