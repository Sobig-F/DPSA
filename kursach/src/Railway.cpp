#include "Railway.hpp"

#include <filesystem>
#include <fstream>
#include <string>

Railway::~Railway()
{
    _name = "";
    Node* current = _queue->_next;

    while (current != nullptr)
    {
        delete _queue->_depot;
        _queue->_depot = nullptr;
        _queue->_prev = nullptr;
        _queue->_next = nullptr;
        delete _queue;
        _queue = current;
        current = current->_next;
    }
    delete _queue->_depot;
    _queue->_depot = nullptr;
    _queue->_prev = nullptr;
    _queue->_next = nullptr;
    delete _queue;
    _tail = nullptr;
}

bool Railway::addDepot(std::string number_, int capacity_)
{
    if (_queue == nullptr)
    {
        _queue = new Node(new Depot(number_, capacity_));
        _tail = _queue;

        return true;
    }

    _tail->_next = new Node(new Depot(number_, capacity_));
    _tail->_next->_prev = _tail;
    _tail = _tail->_next;

    return true;
}

bool Railway::deleteDepot(std::string number_)
{
    Node* current = _queue;
    while (current != nullptr && current->_depot->getNumber() != number_)
    {
        current = current->_next;
    }

    if (current == nullptr)
    {
        return false;
    }

    if (current == _queue && _queue == _tail)
    {
        delete current;
        _queue = nullptr;
        _tail = nullptr;
        return true;
    }

    if (current == _queue)
    {
        _queue = _queue->_next;
        _queue->_prev = nullptr;
        delete current;
        return true;
    }

    if (current == _tail)
    {
        _tail = _tail->_prev;
        _tail->_next = nullptr;
        delete current;
        return true;
    }

    current->_prev->_next = current->_next;
    current->_next->_prev = current->_prev;
    delete current;
    return true;
}

bool Railway::addTrain(std::string depot_number_, Train* train_)
{
    Node* target_node = _queue;

    while (target_node != nullptr && target_node->_depot->getNumber() != depot_number_)
    {
        target_node = target_node->_next;
    }

    if (target_node == nullptr)
    {
        return false;
    }

    bool result = target_node->_depot->addTrain(train_);

    if (!result || target_node == _queue ||
        (target_node->_prev != nullptr && target_node->_depot->getCount() <= target_node->_prev->_depot->getCount()))
    {
        return result;
    }

    Node* current_node = target_node->_prev;
    int target_count = target_node->_depot->getCount();
    while (current_node != nullptr && target_count > current_node->_depot->getCount())
    {
        current_node = current_node->_prev;
    }

    target_node->_prev->_next = target_node->_next;
    if (target_node->_next != nullptr)
    {
        target_node->_next->_prev = target_node->_prev;
    }

    if (current_node == nullptr)
    {
        _queue->_prev = target_node;
        target_node->_next = _queue;
        target_node->_prev = nullptr;
        _queue = target_node;
        return result;
    }

    if (_tail == target_node)
    {
        _tail = target_node->_prev;
    }
    target_node->_next = current_node->_next;
    current_node->_next->_prev = target_node;
    target_node->_prev = current_node;
    current_node->_next = target_node;

    return result;
}

Train* Railway::popTrain()
{
    Train* result = _queue->_depot->popTrain();

    if (_queue->_next == nullptr || _queue->_depot->getCount() >= _queue->_next->_depot->getCount())
    {
        return result;
    }

    Node* current_node = _queue->_next;
    int head_count = _queue->_depot->getCount();
    while (current_node != nullptr && head_count <= current_node->_depot->getCount())
    {
        current_node = current_node->_next;
    }

    Node* target_node = _queue;
    _queue = _queue->_next;
    _queue->_prev = nullptr;

    target_node->_next = current_node;
    if (current_node == nullptr)
    {
        target_node->_prev = _tail;
        _tail = target_node;
    } else
    {
        target_node->_prev = current_node->_prev;
        target_node->_next->_prev = target_node;
    }
    target_node->_prev->_next = target_node;

    return result;
}

const Train* Railway::checkTrain() const { return _queue->_depot->checkTrain(); }

TrainInfo Railway::findTrainInRailway(std::string reg_num_)
{
    Train* result = nullptr;
    for (Node* current = _queue; current != nullptr; current = current->_next)
    {
        result = current->_depot->findTrain(reg_num_);
        if (result != nullptr)
        {
            return TrainInfo(
                result->getStamp(),
                result->getRegNum(),
                current->_depot->getNumber()
            );
        }
    }

    return TrainInfo();
}

TrainInfo Railway::findTrainInDepot(std::string reg_num_, std::string depot_number_)
{
    Depot* depot = findDepot(depot_number_);

    if (depot == nullptr)
    {
        return TrainInfo();
    }

    Train* result = depot->findTrain(reg_num_);

    if (result != nullptr)
    {
        return TrainInfo(
                    result->getStamp(),
                    result->getRegNum(),
                    depot->getNumber()
                );
    }

    return TrainInfo();
}

Depot* Railway::findDepot(std::string depot_number_)
{
    Node* current = _queue;
    while (current != nullptr && current->_depot->getNumber() != depot_number_)
    {
        current = current->_next;
    }

    if (current == nullptr)
    {
        return nullptr;
    }

    return current->_depot;
}

void Railway::show(int tab_count_)
{
    for (int i = 0; i < tab_count_; ++i)
    {
        std::cout << '\t';
    }
    std::cout << "Name: " << _name << std::endl;
    
    if (_queue == nullptr)
    {
        for (int i = 0; i < tab_count_ + 1; ++i)
        {
            std::cout << '\t';
        }
        std::cout << "Empty" << std::endl;
        return;
    }

    for (Node* i = _queue; i != nullptr; i = i->_next)
    {
        i->_depot->show(tab_count_ + 1);
    }

    std::cout << std::endl;
}

bool Railway::Save(std::string filepath_)
{
    std::filesystem::path filepath(filepath_);

    if (filepath.has_parent_path())
    {
        std::filesystem::create_directories(filepath.parent_path());
    }

    std::ofstream file(filepath_);

    if (!file.is_open()) { return false; }

    file << _name << '\n';

    for (Node* node = _queue; node != nullptr; node = node->_next)
    {
        file << '\n' << node->_depot->getNumber()    << ' '
                     << node->_depot->getCapacity()  << ' ' 
                     << node->_depot->getCount()     << '\n';

        int count = node->_depot->getCount();
        int capacity = node->_depot->getCapacity();
        const Train* const* trains = node->_depot->getQueue();
        const Train* train = nullptr;
        int head = node->_depot->getHead();

        for (int index = 0; index < count; ++index)
        {
            train = trains[(head + index) % capacity];

            file    << train->getStamp()    << ' '
                    << train->getRegNum()   << '\n';
        }
    }

    file.close();

    return true;
}

Railway* Railway::Extract(std::string filepath_)
{
    std::ifstream file(filepath_);

    if (!file.is_open()) { return nullptr; }

    std::string railway_name;

    if (!std::getline(file, railway_name)) { return nullptr; }
    if (railway_name.empty()) { return nullptr; }

    Railway* railway = new Railway(railway_name);

    while (true)
    {
        std::string depotNum;
        int capacity = 0;
        int count = -1;

        if (!(file >> depotNum)) { break; }

        if (!(file >> capacity >> count) || file.fail() || depotNum.empty() || capacity == 0 || count < 0)
        {
            delete railway;
            return nullptr;
        }

        railway->addDepot(depotNum, capacity);

        std::string stamp;
        std::string regNum;

        for (int i = 0; i < count; ++i)
        {
            if (!(file >> stamp >> regNum) ||
                 (stamp.empty() || regNum.empty()))
            {
                delete railway;
                return nullptr;
            }

            Train* train = new Train(stamp, regNum);
            railway->addTrain(depotNum, train);
        }
    }

    file.close();

    return railway;
}