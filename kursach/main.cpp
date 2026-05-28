#ifdef _WIN32
#include <windows.h>
#ifdef max
#undef max
#endif
#endif

#include <limits>
#include <string>

#include "Railway.hpp"

#define DEFAULT_FILEPATH "./struct.txt"

#define MAIN_MENU "\
1 - Добавить дорогу\n\
2 - Удалить дорогу\n\
3 - Добавить депо\n\
4 - Удалить депо\n\
5 - Добавить электровоз\n\
6 - Извлечь электровоз\n\
7 - Посмотреть электровоз\n\
8 - Найти поезд на дороге\n\
9 - Найти поезд в депо\n\
10 - Найти депо на дороге\n\
11 - Вывести состояние структуры\n\
12 - Сохранить структуру\n\
13 - Загрузить структуру\n\
0 - Завершить работу\n\
"
Railway* railway = nullptr;

void createRailway();
void deleteRailway();
void addDepot();
void deleteDepot();
void addTrain();
void popTrain();
void checkTrain();
void findTrainInRailway();
void findTrainInDepot();
void findDepot();
void show();
void save();
void extract();

int main()
{
    #ifdef _WIN32
        system("chcp 65001 > nul");
        SetConsoleOutputCP(CP_UTF8);
    #endif

    int action = 1;
    while (action != 0)
    {
        std::cout << MAIN_MENU << "Выбор: ";
        std::cin >> action;
    
        switch (action)
        {
        case 1:     createRailway();        break;
        case 2:     deleteRailway();        break;
        case 3:     addDepot();             break;
        case 4:     deleteDepot();          break;
        case 5:     addTrain();             break;
        case 6:     popTrain();             break;
        case 7:     checkTrain();           break;
        case 8:     findTrainInRailway();   break;
        case 9:     findTrainInDepot();     break;
        case 10:    findDepot();            break;
        case 11:    show();                 break;
        case 12:    save();                 break;
        case 13:    extract();              break;
        default:                            break;
        }
    }

    if (railway != nullptr)
    {
        delete railway;
        railway = nullptr;
    }

    return 0;
}

void createRailway()
{
    std::string railway_name;
    std::cout << "Название дороги: ";
    std::cin >> railway_name;
    
    deleteRailway();

    railway = new Railway(railway_name);
    std::cout << "Дорога " << railway_name << " создана" << std::endl;
}

void deleteRailway()
{
    if (railway != nullptr)
    {
        delete railway;
        railway = nullptr;
    }
}

void addDepot()
{
    if (railway == nullptr)
    {
        std::cout << "Дороги не существует" << std::endl;
        return;
    }
    
    int depot_num;
    int depot_capacity;

    std::cout << "Введите номер нового депо: ";
    std::cin >> depot_num;
    std::cout << "Введите вместимость депо: ";
    std::cin >> depot_capacity;

    if (railway->addDepot(depot_num, depot_capacity))
    {
        std::cout << "Депо добавлено" << std::endl;
    } else
    {
        std::cout << "Депо не добавлено" << std::endl;
    }
}

void deleteDepot()
{
    if (railway == nullptr)
    {
        std::cout << "Дороги не существует" << std::endl;
        return;
    }

    Depot* depot = railway->deleteDepot();

    if (depot != nullptr)
    {
        std::cout   << "Номер депо: "               << depot->getNumber()   << '\n'
                    << "Вместимость: "              << depot->getCapacity() << '\n'
                    << "Количество элетровозов: "   << depot->getCount()    << std::endl;
        
        delete depot;
        std::cout << "Депо удалено" << std::endl;
    } else
    {
        std::cout << "Депо не удалено" << std::endl;
    }
}

void addTrain()
{
    if (railway == nullptr)
    {
        std::cout << "Дороги не существует" << std::endl;
        return;
    }

    int depot_number;
    std::string train_stamp;
    std::string train_reg_num;

    std::cout << "Марка электровоза: ";
    std::cin >> train_stamp;

    std::cout << "Регистрационный номер поезда: ";
    std::cin >> train_reg_num;

    std::cout << "В какое депо добавить электровоз: ";
    std::cin >> depot_number;

    if (railway->addTrain(depot_number, new Train(train_stamp, train_reg_num)))
    {
        std::cout << "Электровоз добавлен" << std::endl;
    } else
    {
        std::cout << "Электровоз не добавлен" << std::endl;
    }
}

void popTrain()
{
    if (railway == nullptr)
    {
        std::cout << "Дороги не существует" << std::endl;
        return;
    }

    int depot_number;

    std::cout << "Номер депо для удаления электровоза: ";
    std::cin >> depot_number;

    Train* train = railway->popTrain(depot_number);
    if (train != nullptr)
    {
        std::cout   << "Марка электровоза: " << train->getStamp() << '\n'
                    << "Регистрационный номер: " << train->getRegNum() << std::endl;
        delete train;
    } else 
    {
        std::cout << "Ни в одном депо нет электровозов" << std::endl;
    }
}

void checkTrain()
{
    if (railway == nullptr)
    {
        std::cout << "Нет дороги" << std::endl;
        return;
    }

    int depot_number;

    std::cout << "Номер депо для просмотра электровоза: ";
    std::cin >> depot_number;

    const Train* train = railway->checkTrain(depot_number);

    if (train == nullptr)
    {
        std::cout << "Нет поездов" << std::endl;
        return;
    }

    std::cout   << "Марка электровоза: " << train->getStamp() << '\n'
                << "Регистрационный номер: " << train->getRegNum() << std::endl;
}

void findTrainInRailway()
{
    if (railway == nullptr)
    {
        std::cout << "Дороги не существует" << std::endl;
        return;
    }

    std::string train_reg_num;

    std::cout << "Регистрационный номер поезда: ";
    std::cin >> train_reg_num;

    TrainInfo train = railway->findTrainInRailway(train_reg_num);

    if (train._stamp != "")
    {
        std::cout   << "Марка электровоза: " << train._stamp << '\n'
                    << "Регистрационный номер: " << train._reg_num << '\n'
                    << "Номер депо: " << train._depot_number << std::endl;
    } else 
    {
        std::cout << "Электровоз с таким регистрационным номером не найден" << std::endl;
    }
}

void findTrainInDepot()
{
    if (railway == nullptr)
    {
        std::cout << "Дороги не существует" << std::endl;
        return;
    }

    std::string train_reg_num;
    int depot_number;

    std::cout << "Номер депо: ";
    std::cin >> depot_number;

    std::cout << "Регистрационный номер поезда: ";
    std::cin >> train_reg_num;

    TrainInfo train = railway->findTrainInDepot(train_reg_num, depot_number);

    if (train._stamp != "")
    {
        std::cout   << "Марка электровоза: " << train._stamp << "\n"
                    << "Регистрационный номер: " << train._reg_num << "\n"
                    << "Номер депо: " << train._depot_number << std::endl;
    } else 
    {
        std::cout << "Электровоз с таким регистрационным номером не найден" << std::endl;
    }
}

void findDepot()
{
    if (railway == nullptr)
    {
        std::cout << "Дороги не существует" << std::endl;
        return;
    }

    int depot_number;

    std::cout << "Номер депо: ";
    std::cin >> depot_number;

    Depot* depot = railway->findDepot(depot_number);

    if (depot != nullptr)
    {
        std::cout   << "Номер депо: " << depot->getNumber() << '\n'
                    << "Количество электровозов: " << depot->getCount() << '\n'
                    << "Вместимость: " << depot->getCapacity() << std::endl;
    } else
    {
        std::cout << "Депо с такими номером не найдено" << std::endl;
    }
}

void show()
{
    if (railway != nullptr)
    {
        railway->show();
    } else
    {
        std::cout << "Нет дороги для отображения" << std::endl;
    }
}

void save()
{
    if (railway == nullptr)
    {
        std::cout << "Пустая структура" << std::endl;
        return;
    }

    std::string filepath = DEFAULT_FILEPATH;
    
    std::string user_input;

    std::cout << "Путь к файлу (default: " << DEFAULT_FILEPATH << "): ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, user_input);

    if (!user_input.empty())
    {
        filepath = user_input;
    }
    
    bool result = railway->Save(filepath);

    if (result)
    {
        std::cout << "Сохранено" << std::endl;
    } else
    {
        std::cout << "Ошибка сохранения" << std::endl;
    }
}

void extract()
{
    std::string filepath = DEFAULT_FILEPATH;
    std::string user_input;
    std::cout << "Путь к файлу (default: " << DEFAULT_FILEPATH << "): " << std::flush;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, user_input);

    if (!user_input.empty())
    {
        filepath = user_input;
    }

    railway = Railway::Extract(filepath);

    if (railway == nullptr)
    {
        std::cout << "Ошибка" << std::endl;
    } else
    {
        std::cout << "Загружено" << std::endl;
    }
}