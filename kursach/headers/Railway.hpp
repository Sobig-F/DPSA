#ifndef RAILWAY_HPP
#define RAILWAY_HPP

#include <iostream>

#include "Depot.hpp"

struct TrainInfo
{
    std::string _stamp;
    std::string _reg_num;
    std::string _depot_number;

    TrainInfo( 
        std::string stamp_ = "",
        std::string reg_num_ = "",
        std::string depot_number_ = ""
    ) :
        _stamp{stamp_},
        _reg_num{reg_num_},
        _depot_number{depot_number_}
    {}
};

class Railway
{
private:
    std::string _name;

    struct Node
    {
        Depot* _depot;
        Node* _prev;
        Node* _next;

        Node(Depot* depot_) : _depot{depot_}, _next{nullptr}, _prev{nullptr}{};
    };
    
    Node* _queue;
    Node* _tail;
public:
    Railway(std::string name_) : _name{name_}, _queue{nullptr}, _tail{nullptr}{};
    ~Railway();

    bool addDepot(std::string number_, int capacity_);
    bool deleteDepot(std::string number_);
    bool addTrain(std::string depot_number_, Train* train_);
    Train* popTrain();
    const Train* checkTrain() const;

    Depot* findDepot(std::string depot_number_);
    TrainInfo findTrainInRailway(std::string reg_num_);
    TrainInfo findTrainInDepot(std::string reg_num_, std::string depot_number_);

    void show(int tab_count_ = 0);

    bool Save(std::string filepath_);
    static Railway* Extract(std::string filepath_);
};

#endif