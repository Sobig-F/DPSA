#ifdef _WIN32
#include <windows.h>
#endif

#include "hash.hpp"

#define MAIN "1 - Добавить элемент\n\
2 - Вывести хеш-таблицу\n\
3 - Найти индекс ключа\n\
0 - Выход\n\
Выбор: "

int main() {
	#ifdef _WIN32
        system("chcp 65001 > nul");
        SetConsoleOutputCP(CP_UTF8);
    #endif
	
    int action = 1;
	int index;
    std::string key;

	for (int i = 0; i < SIZE; i++) {
		hashTable[i] = "";
	}

	while (action) {
        std::cout << MAIN;
        std::cin >> action;

        switch (action)
        {
        case 1:
            if (hashFull()) {
				std::cout << "Хеш-таблица заполнена" << std::endl;
				continue;
			}
			std::cout << "Введите ключ:" << std::endl;
			while (true) {
				std::cin >> key;
				if (checkKey(key)) {
					break;
				}
				else {
					std::cout << "Такого ключа нет в списке доступных." << std::endl;
				}
			}
			addElement(key);
            break;
        case 2:
            if (hashEmpty()) {
				std::cout << "Хеш-таблица пуста" << std::endl;
				continue;
			}
			printHash();
            break;
        case 3:
        {
            if (hashEmpty()) {
				std::cout << "Хеш-таблица пуста" << std::endl;
				continue;
			}
			std::cout << "Введите текстовый ключ:" << std::endl;
			std::cin >> key;
			int result = findElement(key);
			if (result == -1) {
				std::cout << "Такого текстового ключа нет в хеш-таблице" << std::endl;
			}
			else {
				std::cout << result << ") " << key << std::endl;
			}
            break;
        }
        default:
            break;
        }
	}
	return 0;
}