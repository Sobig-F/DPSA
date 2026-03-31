#ifndef TRAIN_HPP
#define TRAIN_HPP

#include <string>

namespace obj
{
/**
 * @brief Электровоз
 */
class Train
{
public:
    Train();
    Train(std::string stamp_, std::string reg_num_);
    ~Train();

    /**
     * @return Марка
     */
    std::string getStamp();

    /**
     * @return Регистрационный номер
     */
    std::string getRegNum();
    
private:
    /**
     * @return Марка
     */
    std::string _stamp;

    /**
     * @return Регистрационный номер
     */
    std::string _reg_num;
};
} // namespace obj

#endif