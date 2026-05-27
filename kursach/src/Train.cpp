#include "Train.hpp"

Train::Train(std::string stamp_, std::string reg_num_)
    :   _stamp{stamp_},
        _reg_num{reg_num_}{}

Train::~Train()
{
    _stamp = "";
    _reg_num = "";
}

std::string Train::getStamp() const { return _stamp; }
std::string Train::getRegNum() const { return _reg_num; }

void Train::show(int tab_count_)
{
    for (int i = 0; i < tab_count_; ++i)
    {
        std::cout << '\t';
    }
    std::cout << "Name: " << _stamp << " / RegNum: " << _reg_num << std::endl;
}