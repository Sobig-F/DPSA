#include "Depot.hpp"

namespace obj
{
Depot::Depot(int stamp_, int capacity_)
    :   _stamp{stamp_},
        _capacity{capacity_},
        _trains_queue(capacity_)
{}

Depot::~Depot(){}

bool AddTrain(std::string stamp_, std::string reg_num_){}
bool DeleteTrain(std::string reg_num_){}
} // namespace obj
