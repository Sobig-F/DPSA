#ifndef PRIRITY_QUEUE_HPP
#define PRIRITY_QUEUE_HPP

#include <concepts>

namespace types
{

// /**
//  * @brief Концепт для условия применимости класса
//  */
// template <typename T>
// concept HasPriority = requires(T t) {
//     { t.getPriority() } -> std::convertible_to<int>;
// } || requires(T t) {
//     { t._priority } -> std::convertible_to<int>;
// };

/**
 * @brief Приоритетная очередь
 */
template <std::totally_ordered T>
class PriorityQueue
{
public:
    PriorityQueue();
    ~PriorityQueue();

    /**
     * @brief Добавление
     * @param elem_ Добавляемый объект
     */
    bool push(T* elem_);

    /**
     * @brief Удаление
     * @return Ссылка на память удаленного объекта
     */
    T* pop();

private:
    struct Node
    {
        /**
         * @brief Объект
         */
        T* _data;

        /**
         * @brief Ссылка на следующий объект
         */
        Node* _next;
    };
    
    /**
     * @brief Ссылка на начало очереди
     */
    Node* _head = nullptr;
    Node* _tail = nullptr;
};
} // namespace types

#endif