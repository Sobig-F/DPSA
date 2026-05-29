#include <iostream>

#define SIZE 10

extern int count_hash;
extern int switch_count;
extern std::string hashTable[SIZE];
extern std::string random_words[50];

bool hashEmpty();
bool hashFull();
int hashFunction(std::string value_, int hashSize_);
void addElement(std::string value_);
int findElement(std::string value_, int mode, int hashSize_, std::string hashTable_[]);
void printHash();
int addElementsTest(std::string hashTableTest_[], std::string testWords_[], int hashSize_, std::string randomWord_);
void testHash();
