// main.cpp
#include <iostream>
#include "pengguna.h"

int main() {
    const std::string namaFile = "pengguna.dat";

    // Tambah pengguna
    Pengguna p1 = {1, "John Doe", "john@example.com"};
    tambahPengguna(namaFile, p1);

    // Cari pengguna
    int idCari = 1;
    Pengguna ditemukan = cariPengguna(namaFile, idCari);
    if (ditemukan.id != -1) {
        std::cout << "Pengguna ditemukan: " << ditemukan.nama << " (" << ditemukan.email << ")" << std::endl;
    } else {
        std::cout << "Pengguna dengan ID " << idCari << " tidak ditemukan." << std::endl;
    }

    // Update pengguna
    Pengguna pBaru = {1, "Jane Doe", "jane@example.com"};
    updatePengguna(namaFile, pBaru);

    // Hapus pengguna
    hapusPengguna(namaFile, 1);

    return 0;
}
