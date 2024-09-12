#ifndef PERPUSTAKAAN_H
#define PERPUSTAKAAN_H

#include "buku.h"
#include <vector>

class Perpustakaan {
    private:
        std::vector<Buku> daftarBuku;

    public:
        void tambahBuku(int id, const std::string& judul, const std::string& penulis);
        void hapusBuku(int id);
        void cariBuku(int id) const;
        void cariBuku(const std::string& judul) const;
        void pinjamBuku(int id);
        void kembalikanBuku(int id);
        void tampilkanSemuaBuku() const;
    private:
        void tampilkanBuku(const Buku& buku) const;
};

#endif