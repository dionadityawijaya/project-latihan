// pengguna.h
#ifndef PENGGUNA_H
#define PENGGUNA_H

#include <string>

struct Pengguna {
    int id;
    std::string nama;
    std::string email;
};

void tambahPengguna(const std::string& namaFile, const Pengguna& pengguna);
Pengguna cariPengguna(const std::string& namaFile, int id);
void hapusPengguna(const std::string& namaFile, int id);
void updatePengguna(const std::string& namaFile, const Pengguna& penggunaBaru);

#endif // PENGGUNA_H
