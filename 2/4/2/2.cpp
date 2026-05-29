#include <time.h>

#ifdef _WIN32
#include <windows.h>
#endif

#define MAIN "1 - Добавить элемент\n\
2 - Вывести хеш-таблицу\n\
3 - Найти индекс ключа\n\
4 - Сделать тест с разными размерами хеш-таблиц\n\
0 - Выход\n\
Выбор: "

#include "hash.hpp"

int main()
{
	#ifdef _WIN32
        system("chcp 65001 > nul");
        SetConsoleOutputCP(CP_UTF8);
    #endif
	
    int action = 1;
	int index;
    std::string key;

	while (action) {
        std::cout << MAIN;
        std::cin >> action;

        switch (action)
        {
        case 1:
            if (hashFull()) {
				std::cout << "Хеш-таблица заполнена" << std::endl;
				break;
			}
			std::cout << "Введите ключ:" << std::endl;
			while (true) {
				std::cin >> key;
				if (key != "") {
					break;
				}
				else {
					std::cout << "Получена пустая строка." << std::endl;
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
			std::cout << "Введите ключ:" << std::endl;
			std::cin >> key;
			int result = findElement(key, 1, SIZE, hashTable);
			if (result == -1) {
				std::cout << "Такого ключа нет в хеш-таблице" << std::endl;
			}
            break;
        }
        case 4:
            std::cout << "Делаем тест..." << std::endl;
			std::cout << "-----------------------" << std::endl;
			testHash();
            break;
        default:
            break;
        }
	}
    
	return 0;
}