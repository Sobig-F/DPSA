#ifndef QUEUE_HPP
#define QUEUE_HPP

namespace types
{
/**
 * @brief Статическая очередь
 */
template <typename T>
class StaticQueue
{
public:
    StaticQueue(int capacity_);
    ~StaticQueue();

    /**
     * @brief Добавление
     */
    bool push(T* elem_);

    /**
     * @brief Удаление
     * @return Ссылка на память удаленного объекта
     */
    T* pop();

    /**
     * @return Кол-во элементов в очереди
     */
    int getCount();

    /**
     * @return Вместительность очереди
     */
    int getCapacity();
    
private:
    /**
     * @brief Вместительность очереди
     */
    int _capacity;

    /**
     * @brief Кол-во элементов в очереди
     */
    int _count;

    /**
     * @brief Массив объектов
     */
    T** _queue;

    /**
     * @brief Индекс первого элемента
     */
    int _head;

    /**
     * @brief Индекс последнего элемента
     */
    int _tail;
};

} // namespace types


#endif