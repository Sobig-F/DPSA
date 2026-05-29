#include "hash.hpp"

std::string words[SIZE] = { "begin", "type", "function", "procedure", "then", "case", "repeat", "while", "do", "exit" };
std::string hashTable[SIZE];
int count_hash = 0;

bool hashEmpty() { return (count_hash == 0); }

bool hashFull() { return (count_hash == SIZE); }

int hashFunction(std::string value_)
{
    int sum = 0;
	for (int i = 0; i < value_.length(); i++) {
		sum += static_cast<int>(value_[i]);
	}
	return sum % 10;
}

void addElement(std::string value_)
{
    std::cout << "Хеш-значение исходного текстового ключа: " << hashFunction(value_) << std::endl;
	while (true) {
		int index = hashFunction(value_);
		if (hashTable[index] == "") {
			hashTable[index] = value_;
			count_hash++;
			std::cout << "Текстовый ключ " << value_ << " добавлен в индекс: " << index << std::endl;
			break;
		}
		else {
			std::cout << "Произошёл конфликт текстовых ключей с " << hashTable[index] << " , меняем исходный текстовый ключ:" << std::endl;
			value_ = value_ + ")";
			std::cout << "> " << value_ << std::endl;
			std::cout << "-----" << std::endl;
		}
	}
}

int findElement(std::string value_)
{
    int index = hashFunction(value_);
	if (hashTable[index] == value_) {
		return index;
	}
	else {
		return -1;
	}
}

void printHash()
{
    for (int i = 0; i < SIZE; i++) {
		if (hashTable[i] != "") {
			std::cout << i << ") " << hashTable[i] << std::endl;
		}
	}
}

bool checkKey(std::string value_)
{
    for (int i = 0; i < SIZE; i++) {
		if (words[i] == value_) {
			return true;
		}
	}
	return false;
}
