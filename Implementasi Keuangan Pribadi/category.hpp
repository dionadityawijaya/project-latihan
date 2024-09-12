#ifndef KATEGORY_H
#define KATEGORY_H

#include <string>

class Category {
    public:
        std::string nama;
        Category() = default;
        Category(const std::string& n);
};

#endif