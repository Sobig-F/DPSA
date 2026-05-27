#ifndef TRAIN_HPP
#define TRAIN_HPP

#include <iostream>

class Train
{
public:
    Train();
    Train(std::string stamp_, std::string reg_num_);
    ~Train();

    std::string getStamp() const;
    std::string getRegNum() const;
    void show(int tab_count_);
    
private:
    std::string _stamp;
    std::string _reg_num;
};

#endif