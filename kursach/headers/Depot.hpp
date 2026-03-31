#ifndef DEPOT_HPP
#define DEPOT_HPP

#include "Railway.hpp"
#include "StaticQueue.hpp"
#include "Train.hpp"

namespace obj
{
/**
 * @brief Депо (статическая очередь)
 */
class Depot
{
public:
    Depot(int stamp_, int capacity_);
    ~Depot();

    /**
     * @brief Добавить электровоз в депо
     * @param stamp_ Марка
     * @param reg_num_ Регистрационный номер
     */
    bool AddTrain(std::string stamp_, std::string reg_num_);

    /**
     * @brief Удалить электровоз
     * @param reg_num_ Регистрационный номер
     */
    bool DeleteTrain(std::string reg_num_);

    /**
     * @brief Приоритет обработки депо
     */
    int getPriority(){ return _priority; };

    /**
     * @brief Перегрузка оператора для сравнения депо по загруженности
     */
    std::strong_ordering operator<=>(const Depot& other) const;

private:
    /**
     * @brief Железная дорога, которой принадлежит депо
     */
    Railway* _railway;

    /**
     * @brief Номер депо
     */
    int _stamp;

    /**
     * @brief Вместительность
     */
    int _capacity;

    /**
     * @brief Приоритет обработки депо (равен количество электровозов в очереди)
     */
    int _priority;

    /**
     * @brief Статическая очередь электровозов
     */
    types::StaticQueue<Train> _trains_queue;
};
} // namespace obj

#endif