#ifndef BUKU_H
#define BUKU_H

#include <string>

struct Buku {
    int id;
    std::string judul;
    std::string penulis;
    bool tersedia;

    Buku(int i, const std::string& j, const std::string p, bool t);

};

#endif