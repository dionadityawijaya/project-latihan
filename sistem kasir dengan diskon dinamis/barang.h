#ifndef BARANG_H
#define BARANG_H

#include <string>

class Barang {
    public:
        std::string nama;
        double harga;


        Barang(const std::string& n, double h);
};

#endif