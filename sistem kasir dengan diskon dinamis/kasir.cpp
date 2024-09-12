#include "kasir.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <algorithm>

void Kasir::tambahBarang(const std::string& nama, double harga) {
    daftarBarang.emplace_back(nama, harga);
}
void Kasir::hapusBarang(const std::string& nama) {
    auto it = std::remove_if(daftarBarang.begin(), daftarBarang.end(),
    [&nama](const Barang& barang){return barang.nama == nama;});


    if (it != daftarBarang.end()) {
        daftarBarang.erase(it, daftarBarang.end());
        std::cout << "Barang " << nama << "Berhasil dihapus.\n";
    } else {
        std::cout << "Barang " << nama << "Tidak ditemukan.\n";
    }
}
double Kasir::hitungTotal() const {
    double total = 0;
    for (const auto& barang : daftarBarang) {
        total += barang.harga;
    }

    if (diskon) {
        total -= diskon->hitungDiskon(total);
    }

    return total;
}
void Kasir::setDiskon(std::unique_ptr<Diskon> d) {
    diskon = std::move(d);
}
void Kasir::simpanTransaksi(const std::string& namaFile) const {
    std::ofstream file (namaFile, std::ios::app);

    if (!file) {
        std::cerr << "Tidak dapat membuka file untuk menulis.\n";
        return;
    }

    std::time_t waktuSekarang = std::time(nullptr);
    char waktuStr[100];
    std::strftime(waktuStr, sizeof(waktuStr), "%Y-%m-%d %H:%M:%S", std::localtime(&waktuSekarang));

    file << "Transaksi pada: " << waktuStr << std::endl;

    for (const auto& barang : daftarBarang) {
        file << "Barang: " << barang.nama << ", Harga: " << barang.harga << std::endl;
    }

    file << "Total harga: " << hitungTotal() << std::endl;
    file << "----------------------------" << std::endl;
}
void Kasir::tampilkanLaporanHarian(const std::string& namaFile) {
    std::ifstream file(namaFile);

    if (!file ) {
        std::cerr << "Tidak dapat membuka file untuk membaca.\n";
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }
}