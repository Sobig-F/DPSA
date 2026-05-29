#include <iostream>

#define SIZE 10

extern std::string words[SIZE];
extern std::string hashTable[SIZE];
extern int count_hash;

bool hashEmpty();
bool hashFull();
int hashFunction(std::string value_);
void addElement(std::string value_);
int findElement(std::string value_);
void printHash();
bool checkKey(std::string value_);