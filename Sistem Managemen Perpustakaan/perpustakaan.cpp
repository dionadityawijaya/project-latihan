#include <iostream>
#include <string>
#include <algorithm>
#include "perpustakaan.h"


void Perpustakaan::tambahBuku(int id, const std::string& judul, const std::string& penulis){
    daftarBuku.push_back(Buku(id, judul, penulis, true));
    std::cout << "Buku Berhasil ditambahakan " << judul << "\n";
}

void Perpustakaan::hapusBuku(int id) {
    auto it = remove_if(daftarBuku.begin(), daftarBuku.end(),
    [id](const Buku& buku) {return buku.id == id;});
    

    if (it != daftarBuku.end()) {
        std::cout << "Buku dengan ID: " << id << "Telah dihapus.\n";
        daftarBuku.erase(it, daftarBuku.end());
    } else {
        std::cout << "Buku dengan ID: " << id << "Tidak ditemukan.\n";
    }
}

void Perpustakaan::cariBuku(int id) const {
     auto it = find_if(daftarBuku.begin(), daftarBuku.end(),
    [id](const Buku& buku) {return buku.id == id;});

    if (it != daftarBuku.end()) {
        tampilkanBuku(*it);
    } else {
        std::cout << "Buku dengan ID: " << id << "Tidak ditemukan.\n";
    }
}

void Perpustakaan::cariBuku(const std::string& judul) const {
     auto it = find_if(daftarBuku.begin(), daftarBuku.end(),
    [&judul](const Buku& buku) {return buku.judul == judul;});

    if (it != daftarBuku.end()) {
        tampilkanBuku(*it);
    } else {
        std::cout << "Buku dengan ID: " << judul << "Tidak ditemukan.\n";
    }

    
}

void Perpustakaan::pinjamBuku(int id) {
     auto it = find_if(daftarBuku.begin(), daftarBuku.end(),
    [id](const Buku& buku) {return buku.id == id;});

    if (it != daftarBuku.end() && it->tersedia) {
        it->tersedia = false;
        std::cout << "Buku dengan ID: " << it->judul << "Berhasil dipinjam.\n";
    } else if (it != daftarBuku.end() && !it->tersedia) {
        std::cout << "Buku dengan ID: " << it->judul << "sudah dipinjam.\n";
    } else {
        std::cout << "Buku dengan ID: " << id << "Tidak ditemukan.\n";
    }
}

void Perpustakaan::kembalikanBuku(int id) {
    auto it = find_if(daftarBuku.begin(), daftarBuku.end(),
    [id](const Buku& buku) {return buku.id == id;});

    if (it != daftarBuku.end() && !it->tersedia) {
        it->tersedia = true;
        std::cout << "Buku dengan ID: " << it->judul << "Berhasil dikembalikan.\n";
    } else if (it != daftarBuku.end() && it->tersedia) {
        std::cout << "Buku dengan ID: " << it->judul << "sudah dikembalikan.\n";
    } else {
        std::cout << "Buku dengan ID: " << id << "Tidak ditemukan.\n";
    }
}

void Perpustakaan::tampilkanSemuaBuku() const {
    if (daftarBuku.empty()) {
        std::cout << "Tidak ada buku di Perpustakaan.\n";
    } else {
        std::cout << "Daftar Buku di Perpustakaan:\n";
        for (const auto& buku : daftarBuku) {
            tampilkanBuku(buku);
        }
    }
}

void Perpustakaan::tampilkanBuku(const Buku& buku) const {
    std::cout << "ID: " << buku.id << "\n"
              << "Judul: " << buku.judul << "\n"
              << "Penulis: " << buku.penulis << "\n"
              << "Status: " << (buku.tersedia ? "Tersedia" : "Dipinjam") << "\n\n";
}