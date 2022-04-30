########################################################################
####################### Makefile Template ##############################
########################################################################

# Compiler settings - Can be customized.
CC = g++
CXXFLAGS = -std=c++11 -Wall
LDFLAGS = 

# Makefile settings - Can be customized.
APPNAME = a08_q1_```c++
// Zach DeRose 4/25/22 IT279 A8
#include <iostream>
#include "DoubleHash.h"
using namespace std;
#define TABLE_SIZE 10  //default size
#define PRIME 5
template <typename Comparable>
DoubleHash<Comparable>::DoubleHash(Comparable size){ //done
    TABLE_SIZE = size; //take in input size (to be determined by amt of students)
    hashTable = new int[TABLE_SIZE]; // make a hashtable using this size
    curr_size = 0;
    for (int i = 0; i < TABLE_SIZE; i++){
        hashTable[i] = -1;
    }
}

template <typename Comparable>
bool DoubleHash<Comparable>::isFull(){ //done
    return (curr_size == TABLE_SIZE); //inserting vals results in this poss being true
}

template <typename Comparable> 
int DoubleHash<Comparable>::hash1(Comparable key){ //done
    return (key % TABLE_SIZE);
}

template <typename Comparable>
int DoubleHash<Comparable>::hash2(Comparable key){ //done
    return (PRIME - (key % PRIME));
}

template <typename Comparable>
void DoubleHash<Comparable>::insertHash(Student<Comparable> &val){//done
    if (isFull()){return;}
    int index = hash1(val);
    if (hashTable[index] != -1){
        int index2 = hash2(val);
        int i = 1;
        while (1){
            int newIndex = (index + i * index2) % TABLE_SIZE;
            if (hashTable[newIndex] == -1){
                hashTable[newIndex] = val;
                break;
            }
            i++;
        }
    }  
    else{hashTable[index] = key;}
    curr_size++;
}
template <typename Comparable>
bool DoubleHash<Comparable>::search(Comparable key, Comparable bucketId, Student<Comparable> &val){
    int i1 = hash1(key);
    int i2 = hash2(key);
    int i = 0;
    while (hashTable[(i1 + i * i2) % TABLE_SIZE] != key){
        if (hashTable[(i1 + i * i2) % TABLE_SIZE] == -1){
            cout << "Key not found: " << key <<  endl;
            return false;
        }
        i++;
    }
    cout << "Key found: " << key << endl;
    return true;
}

template <typename Comparable>
bool DoubleHash<Comparable>::search(Comparable bucketId, Student<Comparable> &val){
    int i1 = hash1(key);
    int i2 = hash2(key);
    int i = 0;
    while (hashTable[(i1 + i * i2) % TABLE_SIZE] != key){
        if (hashTable[(i1 + i * i2) % TABLE_SIZE] == -1){
            cout << "Key not found: " << key <<  endl;
            return false;
        }
        i++;
    }
    cout << "Key found: " << key << endl;
    return true;
}

template <typename Comparable>
bool DoubleHash<Comparable>::update(Student<Comparable>  &val){
    
}

template <typename Comparable>
void DoubleHash<Comparable>::displayHash(){
    for (int i = 0; i < TABLE_SIZE; i++){
        if (hashTable[i] != -1){cout << i << " --> " << hashTable[i] << endl;}
        else{cout << i << endl;}  
    }
}

template <typename Comparable>
bool DoubleHash<Comparable>::isSameDept(Student<Comparable> std1, Student<Comparable> std2){

}

template <typename Comparable>
Student<Comparable>::getStudent(Comparable bucketId){
    
}
```nickvoss
EXT = .cpp
SRCDIR = src
OBJDIR = obj

############## Do not change anything from here downwards! #############
SRC = $(wildcard $(SRCDIR)/*$(EXT))
OBJ = $(SRC:$(SRCDIR)/%$(EXT)=$(OBJDIR)/%.o)
DEP = $(OBJ:$(OBJDIR)/%.o=%.d)
# UNIX-based OS variables & settings
RM = rm
DELOBJ = $(OBJ)
# Windows OS variables & settings
DEL = del
EXE = .exe
WDELOBJ = $(SRC:$(SRCDIR)/%$(EXT)=$(OBJDIR)\\%.o)

########################################################################
####################### Targets beginning here #########################
########################################################################

all: $(APPNAME)

# Builds the app
$(APPNAME): $(OBJ)
	$(CC) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Creates the dependecy rules
%.d: $(SRCDIR)/%$(EXT)
	@$(CPP) $(CFLAGS) $< -MM -MT $(@:%.d=$(OBJDIR)/%.o) >$@

# Includes all .h files
-include $(DEP)

# Building rule for .o files and its .c/.cpp in combination with all .h
$(OBJDIR)/%.o: $(SRCDIR)/%$(EXT)
	$(CC) $(CXXFLAGS) -o $@ -c $<

################### Cleaning rules for Unix-based OS ###################
# Cleans complete project
.PHONY: clean
clean:
	$(RM) $(DELOBJ) $(DEP) $(APPNAME)

# Cleans only all files with the extension .d
.PHONY: cleandep
cleandep:
	$(RM) $(DEP)

#################### Cleaning rules for Windows OS #####################
# Cleans complete project
.PHONY: cleanw
cleanw:
	$(DEL) $(WDELOBJ) $(DEP) $(APPNAME)$(EXE)

# Cleans only all files with the extension .d
.PHONY: cleandepw
cleandepw:
	$(DEL) $(DEP)