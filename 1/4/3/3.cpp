#include <iostream>

#include "List.hpp"

#define MENU "1 - Print\n\
2 - Exist\n\
3 - PushListBefore\n\
4 - PushListAfter\n\
5 - PushElemBefore\n\
6 - PushElemAfter\n\
7 - DeleteList\n\
8 - DeleteElem\n\
9 - exit\n\
Choise: "

int Get(std::string value_)
{
    int result = 0;

    std::cout << value_ << ": ";
    std::cin >> result;

    return result;
}

int main()
{
    Node* List = nullptr;
    int head, target, data;
    int action = 0;
    
    while (true)
    {
        std::cout << MENU;
        std::cin >> action;
        switch (action)
        {
        case 1:
            Print(List);
            break;

        case 2:
            data = Get("Data");
            if (Exist(List, data))
            {
                std::cout << "Yes";
            } else
            {
                std::cout << "No";
            }
            std::cout << std::endl;
            break;

        case 3:
            target = Get("Target");
            data = Get("Data");
            List = PushListBefore(List, target, data);
            break;

        case 4:
            target = Get("Target");
            data = Get("Data");
            List = PushListAfter(List, target, data);
            break;

        case 5:
            head = Get("Head");
            target = Get("Target");
            data = Get("Data");
            PushElemBefore(List, head, target, data);
            break;

        case 6:
            head = Get("Head");
            target = Get("Target");
            data = Get("Data");
            PushElemAfter(List, head, target, data);
            break;

        case 7:
            target = Get("Target");
            List = DeleteList(List, target);
            break;

        case 8:
            head = Get("Head");
            target = Get("Target");
            DeleteElem(List, head, target);
            break;

        case 9:
            return 0;

        default:
            break;
        }
    }
}