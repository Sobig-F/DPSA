#ifndef RAILWAY_HPP
#define RAILWAY_HPP

#include <string>

#include "PriorityQueue.hpp"
#include "Depot.hpp"

namespace obj
{
/**
 * @brief Железная дорога (динамическая приоритетная очередь)
 */
class Railway
{
public:
    Railway(std::string name_);
    ~Railway();

    /**
     * @brief Добавление нового депо
     * @param stamp_ Номер добавляемого депо
     * @param capacity_ Кол-во вмещающихся электровозов (размер массива статической очереди)
     * @retval True - депо добавлено
     * @retval False - депо не добавлено
     */
    bool AddDepot(int stamp_, int capacity_);

    /**
     * @brief Удаление депо
     * @retval True - депо удалено
     * @retval False - депо не удалено
     */
    bool DeleteDepot(int stamp_);

private:
    /**
     * @brief Название дороги
     */
    std::string _name;

    /**
     * @brief Приоритетная очередь депо
     */
    types::PriorityQueue<Depot> _depots_queue;
};
} // namespace obj

#endif