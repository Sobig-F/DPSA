#include <iostream>

#define SIZE 10

struct Node {
	Node* next = nullptr;
	Node* back = nullptr;
	std::string value = "";
};

struct hashElement {
	Node* first = nullptr;
	Node* last = nullptr;
	int elCount = 0;
};

extern int count_hash;
extern int switch_count;
extern hashElement hashTable[SIZE];
extern std::string random_words[50];

bool hashEmpty();
bool hashFull();
int hashFunction(std::string value_, int hashSize_);
void addElement(std::string value_);
void removeElement(std::string value_);
int findElement(std::string value_, int mode, int hashSize_, hashElement hashTable_[]);
void printHash();
int addAndFindElementsTest(hashElement hashTableTest_[], std::string testWords_[], int hashSize_, std::string randomWord_);
void testHash();
void clearHash();
