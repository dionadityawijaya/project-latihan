#ifndef KASIR_H
#define KASIR_H

#include <vector>
#include <string>
#include <memory>
#include "barang.h"
#include "diskon.h"

class Kasir {
    private:
        std::vector<Barang> daftarBarang;
        std::unique_ptr<Diskon> diskon;
    public:
        void tambahBarang(const std::string& nama, double harga);
    void hapusBarang(const std::string& nama);
    double hitungTotal() const;
    void setDiskon(std::unique_ptr<Diskon> d);
    void simpanTransaksi(const std::string& namaFile) const;
    static void tampilkanLaporanHarian(const std::string& namaFile);
};



#endif