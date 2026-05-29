#include "hash.hpp"

int count_hash = 0;
int switch_count = 0;
hashElement hashTable[SIZE];
std::string random_words[50] = { "Apple", "Butterfly", "Cloud", "Diamond", "Eagle", "Forest", "Galaxy", "Harmony", "Iceberg", "Jungle",
						 "Kingdom", "Lightning", "Mountain", "Nebula", "Ocean", "Phoenix", "Quartz", "Rainbow", "Shadow", "Thunder",
						 "Universe", "Volcano", "Waterfall", "Xenon", "Yellow", "Zenith", "Anchor", "Blizzard", "Crystal", "Dragon",
						 "Echo", "Flame", "Glacier", "Horizon", "Illusion", "Journey", "Knight", "Legend", "Mystic", "Nova",
						 "Oracle", "Puzzle", "Quest", "Riddle", "Sapphire", "Tornado", "Umbrella", "Vortex", "Whisper", "Zephyr" };

bool hashEmpty() { return (count_hash == 0); }

bool hashFull() { return (count_hash == SIZE); }

int hashFunction(std::string value_, int hashSize_)
{
    int sum = 0;
	for (int i = 0; i < value_.length(); i++) {
		sum += static_cast<int>(value_[i]);
	}
	return sum % hashSize_;
}

void addElement(std::string value_)
{
    int index = hashFunction(value_, SIZE);
	Node* current_check = hashTable[index].first;
	while (current_check != nullptr) {
		if (current_check->value == value_) {
			std::cout << "Такой ключ уже есть в хеш-таблице" << std::endl;
			return;
		}
		current_check = current_check->next;
	}
	switch_count = 0;
	Node* new_node = new Node();
	new_node->value = value_;
	hashTable[index].elCount++;

	if (hashTable[index].first == nullptr) {

		hashTable[index].first = new_node;
		hashTable[index].last = new_node;

		count_hash++;
		std::cout << "Ключ " << value_ << " добавлен в индекс: " << index << std::endl;
	}
	else {
		Node* current = hashTable[index].last;
		current->next = new_node;
		new_node->back = current;
		hashTable[index].last = new_node;
		std::cout << "Ключ " << value_ << " добавлен в конец списка находяшегося в индексе: " << index << std::endl;
		std::cout << "Количество сравнений: " << hashTable[index].elCount << std::endl;
	}
}

void removeElement(std::string value_)
{
    int index = hashFunction(value_, SIZE);
	int switch_count = 0;
	Node* current = hashTable[index].first;

	switch_count++;
	while (current->value != value_) {
		switch_count++;
		current = current->next;
	}

	if (hashTable[index].first == hashTable[index].last) {
		hashTable[index].first = nullptr;
		hashTable[index].last = nullptr;
		count_hash--;
	}

	else if (current == hashTable[index].first) {
		hashTable[index].first = current->next;
		(hashTable[index].first)->back = nullptr;

	}

	else if (current == hashTable[index].last) {
		hashTable[index].last = current->back;
		(hashTable[index].last)->next = nullptr;
	}

	else {
		Node* back_current = current->back;
		back_current->next->back = back_current;
		back_current->next = current->next;
	}
	hashTable[index].elCount--;
	std::cout << "Ключ " << value_ << " удалён из хеш-таблицы" << std::endl;
	std::cout << "Было произведено " << switch_count << " сравнений по списку при удалении элемента" << std::endl;

	delete current;
}

int findElement(std::string value_, int mode, int hashSize_, hashElement hashTable_[])
{
    int index = hashFunction(value_, hashSize_);
	switch_count = 0;
	Node* current = hashTable_[index].first;
	switch_count++;
	while (current != nullptr) {
		if (current->value == value_) {
			break;
		}
		current = current->next;
		switch_count++;
	}
	if (current == nullptr) {
		return -1;
	}
	else {
		if (mode) {
			std::cout << "Ключ " << value_ << " находится в списке #" << index << " под индексом " << switch_count - 1 << std::endl;
			std::cout << "Количество сравнений при поиске: " << switch_count << std::endl;
		}
		return index;
	}
}

void printHash()
{
    for (int i = 0; i < SIZE; i++) {
		if (hashTable[i].first != nullptr) {
			std::cout << i << ") ";
			Node* current = hashTable[i].first;
			while (current != nullptr) {
				std::cout << current->value << " | ";
				current = current->next;
			}
			std::cout << std::endl;
		}
	}
}

int addAndFindElementsTest(hashElement hashTableTest_[], std::string testWords_[], int hashSize_, std::string randomWord_)
{
    switch_count = 0;
	int switch_count_add = 0;
	for (int j = 0; j < 20; j++) {
		int index = hashFunction(testWords_[j], hashSize_);
		Node* new_node = new Node();
		new_node->value = testWords_[j];
		if (hashTableTest_[index].first == nullptr) {
			hashTableTest_[index].first = new_node;
			hashTableTest_[index].last = new_node;
		}
		else {
			Node* current = hashTableTest_[index].last;
			current->next = new_node;
			new_node->back = current;
			hashTableTest_[index].last = new_node;
		}
		hashTableTest_[index].elCount += 1;
		switch_count_add += hashTableTest_[index].elCount;
	}
	findElement(randomWord_, 0, hashSize_, hashTableTest_);
	for (int j = 0; j < hashSize_; j++) {
		Node* current = hashTableTest_[j].first;
		Node* temp;
		while (current != nullptr) {
			temp = current;
			current = current->next;
			delete temp;
		}
		hashTableTest_[j].first = nullptr;
		hashTableTest_[j].last = nullptr;
	}
	return switch_count_add;
}

void testHash()
{
    hashElement hashTable9[9];
	hashElement hashTable17[17];
	hashElement hashTable23[23];

	std::string words[20];
	int random, switch_count_test;
	bool ctn;
	std::cout << "Набор из 20 случайных добавляемых слов:" << std::endl;
	for (int i = 0; i < 20; i++) {
		while (true) {
			ctn = false;
			random = rand() % 50;
			for (int j = 0; j < i + 1; j++) {
				if (random_words[random] == words[j]) {
					ctn = true;
					break;
				}

			}
			if (!ctn) {
				break;
			}
		}
		words[i] = random_words[random];
		std::cout << random_words[random] << " | ";
		if (i == 9) { std::cout << std::endl; }
	}
	std::cout << std::endl << "-----------------------" << std::endl;
	random = rand() % 20;
	std::cout << "Будем искать слово: " << words[random] << std::endl;
	std::cout << "-----------------------" << std::endl;
	std::cout << "Хеш-таблица с размером 9" << std::endl;
	switch_count_test = addAndFindElementsTest(hashTable9, words, 9, words[random]);
	std::cout << "Общее количество сравнений при добавлении: " << switch_count_test << std::endl;
	std::cout << "Количество сравнений при поиске: " << switch_count << std::endl;
	std::cout << "-----------------------" << std::endl;
	std::cout << "Хеш-таблица с размером 17" << std::endl;
	switch_count_test = addAndFindElementsTest(hashTable17, words, 17, words[random]);
	std::cout << "Общее количество сравнений при добавлении: " << switch_count_test << std::endl;
	std::cout << "Количество сравнений при поиске: " << switch_count << std::endl;
	std::cout << "-----------------------" << std::endl;
	std::cout << "Хеш-таблица с размером 23" << std::endl;
	switch_count_test = addAndFindElementsTest(hashTable23, words, 23, words[random]);
	std::cout << "Общее количество сравнений при добавлении: " << switch_count_test << std::endl;
	std::cout << "Количество сравнений при поиске: " << switch_count << std::endl;
}

void clearHash()
{
    for (int j = 0; j < SIZE; j++) {
		Node* current = hashTable[j].first;
		Node* temp;
		while (current != nullptr) {
			temp = current;
			current = current->next;
			delete temp;
		}
		hashTable[j].first = nullptr;
		hashTable[j].last = nullptr;
	}
}
