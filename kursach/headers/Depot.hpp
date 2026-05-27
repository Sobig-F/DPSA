#ifndef DEPOT_HPP
#define DEPOT_HPP

#include <iostream>

#include "Train.hpp"

class Depot
{
private:
    std::string _number;
    int _capacity;
    int _count;

    Train** _queue;
    int _head;
    int _tail;
    
public:
    Depot(std::string number_, int capacity_)
        :   _number{number_},
            _capacity{capacity_},
            _queue{new Train*[_capacity]},
            _head{0},
            _tail{0},
            _count{0}
    {};

    ~Depot();

    bool addTrain(Train* elem_);
    Train* popTrain();
    const Train* checkTrain() const;

    std::string getNumber() const;
    int getCapacity() const;
    int getCount() const;
    int getHead() const;
    const Train* const* getQueue() const;

    Train* findTrain(std::string reg_num_);

    void show(int tab_count_);
};

#endif