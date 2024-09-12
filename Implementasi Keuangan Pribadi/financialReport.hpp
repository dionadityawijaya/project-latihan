#ifndef FR_H
#define FR_H

#include <string>
#include <map>
#include <iostream>
#include <vector>

#include "transaction.hpp"

class FinancialReport {
    private:
        std::vector<Transaction> transaksi;

    public:
        void tambahTransaksi(const Transaction& t);
        void hapusTransaksi(const std::string& deskripsi);
        void tampilkanLaporan(const std::string& bulan = "") const;
        void tampilkanGrafikPengeluaran() const;
        void simpanTransaksiKeFile(const std::string& namaFile) const;
        void muatTransaksiDariFile(const std::string& namaFile);
};

#endif