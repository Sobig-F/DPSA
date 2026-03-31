#include "Train.hpp"

namespace obj
{

Train::Train()
{
    _stamp = "";
    _reg_num = "";
}

Train::Train(std::string stamp_, std::string reg_num_)
    :   _stamp{stamp_},
        _reg_num{reg_num_}{}

Train::~Train(){}

std::string Train::getStamp(){ return _stamp; }
std::string Train::getRegNum(){ return _reg_num; }

} // namespace obj