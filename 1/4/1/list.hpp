#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>

class List
{
public:
    List(){};
    ~List();

    /**
     * \brief Добавление элемента перед заданным
     */
    void AddBefore(int data_, int target_) noexcept;

    /**
     * \brief Добавление элемента после заданного
     */
    void AddAfter(int data_, int target_) noexcept;

    /**
     * \brief Просмотр в прямом направлении
     */
    void ForwardView() const noexcept;

    /**
     * \brief Просмотр в обратном направлении
     */
    void OppositeView() const noexcept;
    
    /**
     * \brief Поиск в прямом направлении
     */
    int ForwardFind(int data_) const noexcept;

    /**
     * \brief Поиск в обратном направлении
     */
    int OppositeFind(int data_) const noexcept;

    /**
     * \brief Удаление элемента
     */
    void del(int data_) noexcept;

    /**
     * \brief Возвращает Head==nullptr
     */
    bool Empty() const noexcept { return _head == nullptr; };
private:
    class Node
    {
    public:
        Node(int data_, Node* prev_, Node* next_);
        
        ~Node();

        int _data = 0;
        Node* _next = nullptr;
        Node* _prev = nullptr;
    };

    /**
     * \brief Поиск Node
     */
    std::pair<int, List::Node*> Find(int data_) const noexcept;

    Node* _head = nullptr;
};

#endif