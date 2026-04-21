#ifndef FS_OPERATIONS_HPP
#define FS_OPERATIONS_HPP

#include "Railway.hpp"

Railway* Extract(std::string filepath_);
bool Save(std::string filepath_, std::string filename_);

#endif