#include "hash.hpp"

int count_hash = 0;
int switch_count = 0;
std::string hashTable[SIZE];
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
	int switch_count = 0;
	for (int i = 0; i <= SIZE - 1; i++) {
		if (hashTable[index] == "") {
			hashTable[index] = value_;
			count_hash++;
			std::cout << "Ключ " << value_ << " добавлен в индекс: " << index << std::endl;
			break;
		}
		else if (hashTable[index] == value_) {
			std::cout << "Ключ " << value_ << " уже есть в хеш-таблице" << std::endl;
			return;
		}
		index = ((index + 1) % SIZE);
		switch_count++;
	}
	std::cout << "Было произведено " << switch_count << " сравнений ключа при добавлении элемента" << std::endl;
}

int findElement(std::string value_, int mode, int hashSize_, std::string hashTable_[])
{
    int index = hashFunction(value_, hashSize_);
	int switch_count = 0;
	for (int i = 0; i <= hashSize_ - 1; i++) {
		switch_count++;
		if (hashTable_[index] == "") {
			return -1;
		}
		else if (hashTable_[index] == value_) {
			if (mode) {
				std::cout << "Было произведено " << switch_count << " сравнений ключа при поиске элемента" << std::endl;
			}
			return index;
		}
		index = ((index + 1) % hashSize_);
	}
	return -1;
}

void printHash()
{
    for (int i = 0; i < SIZE; i++) {
		if (hashTable[i] != "") {
			std::cout << i << ") " << hashTable[i] << std::endl;
		}
	}
}

int addElementsTest(std::string hashTableTest_[], std::string testWords_[], int hashSize_, std::string randomWord_) {
	int switch_count = 0;
	for (int j = 0; j < 10; j++) {
		int index = hashFunction(testWords_[j], hashSize_);
		for (int i = 0; i <= hashSize_ - 1; i++) {
			switch_count++;
			if (hashTableTest_[index] == "") {
				hashTableTest_[index] = testWords_[j];
				break;
			}
			index = ((index + 1) % hashSize_);
		}
	}
	findElement(randomWord_, 1, hashSize_, hashTableTest_);
	for (int j = 0; j < hashSize_; j++) {
		hashTableTest_[j] = "";
	}
	return switch_count;
}

void testHash() {
	std::string hashTable11[11];
	std::string hashTable13[13];
	std::string hashTable17[17];
	std::string words[10];
	int random, switch_count;
	bool ctn;
	std::cout << "Набор из 10 случайных добавляемых слов:" << std::endl;
	for (int i = 0; i < 10; i++) {
		while (true) {
			ctn = false;
			random = rand() % 40;
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
	}
	std::cout << std::endl << "-----------------------" << std::endl;
	random = rand() % 10;
	std::cout << "Будем искать слово: " << words[random] << std::endl;
	std::cout << "-----------------------" << std::endl;
	std::cout << "Хеш-таблица с размером 11" << std::endl;
	switch_count = addElementsTest(hashTable11, words, 11, words[random]);
	std::cout << "Общее количество сравнений при добавлении: " << switch_count << std::endl;
	std::cout << "-----------------------" << std::endl;
	std::cout << "Хеш-таблица с размером 13" << std::endl;
	switch_count = addElementsTest(hashTable13, words, 13, words[random]);
	std::cout << "Общее количество сравнений при добавлении: " << switch_count << std::endl;
	std::cout << "-----------------------" << std::endl;
	std::cout << "Хеш-таблица с размером 17" << std::endl;
	switch_count = addElementsTest(hashTable17, words, 17, words[random]);
	std::cout << "Общее количество сравнений при добавлении: " << switch_count << std::endl;
}
