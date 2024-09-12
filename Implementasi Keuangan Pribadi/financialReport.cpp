#include <fstream>
#include <algorithm>
#include "financialReport.hpp"
#include "json.hpp"

using json = nlohmann::json;

void FinancialReport::tambahTransaksi(const Transaction& t) {
    transaksi.push_back(t);
}


void FinancialReport::hapusTransaksi(const std::string& deskripsi) {
    auto it = std::remove_if(transaksi.begin(), transaksi.end(),
    [&deskripsi](const Transaction& t) {return t.getDeskripsi() == deskripsi; });

    if (it != transaksi.end()) {
        transaksi.erase(it, transaksi.end());
        std::cout << "Transaksi " << deskripsi << "Berhasil dihapus.\n";
    } else {
        std::cout << "Transaksi " << deskripsi << "tidak ditemukan.\n";
    }
}


void FinancialReport::tampilkanLaporan(const std::string& bulan) const {
    double totalPemasukan = 0;
    double totalPengeluaran = 0;

    for (const auto& t : transaksi) {
        if (bulan.empty() || t.getKategori().nama == bulan) {
            if (t.getTipe() == Transaction::Tipe::Pemasukan) {
                totalPemasukan += t.getJumlah();
            } else {
                totalPengeluaran += t.getJumlah();
            }
        }
    }

    std::cout << "Laporan Keuangan" << std::endl;
    std::cout << "Total Pemasukan: " << totalPemasukan << std::endl;
    std::cout << "Total Pengeluaran: " << totalPengeluaran << std::endl;
    std::cout << "Saldo: " << (totalPemasukan - totalPengeluaran) << std::endl;
}


void FinancialReport::tampilkanGrafikPengeluaran() const {
    std::map<std::string, double> kategoriPengeluaran;

    for (const auto& t : transaksi) {
        if (t.getTipe() == Transaction::Tipe::Pengeluaran) {
            kategoriPengeluaran[t.getKategori().nama] += t.getJumlah();
        }
    }
    std::cout << "Grafik Pengeluaran Bulanan (dalam ASCII Art)" << std::endl;
    for (const auto& [kategori, jumlah] : 
    kategoriPengeluaran) {
        std::cout << kategori << ": ";
        int panjang = static_cast<int>(jumlah /10);
        for (int i = 0; i < panjang; ++i) {
            std::cout << "#";
        }
        std::cout << "( " << jumlah << ")" << std::endl;
    }
}


void FinancialReport::simpanTransaksiKeFile(const std::string& namaFile) const {
    json j;
    for (const auto& t : transaksi) {
        j.push_back(t.tojson());
    }

    std::ofstream file(namaFile);
    if (file.is_open()) {
        file << j.dump(4);
        file.close();
    } else {
        std::cerr << "Tidak dapat Membuka file untuk menulis.\n";
    }
}


void FinancialReport::muatTransaksiDariFile(const std::string& namaFile) {
    std::ifstream file(namaFile);
    if (file.is_open()) {
        json j;
        file >> j;

        for (const auto& item : j) {
            std::string deskripsi = item["deskripsi"];
            double jumlah = item["jumlah"];
            std::string tipeStr = item["tipe"];
            Transaction::Tipe tipe = (tipeStr == "Pemasukan") ? Transaction::Tipe::Pemasukan : Transaction::Tipe::Pengeluaran;
            Category kategori(item["kategori"]);

            tambahTransaksi(Transaction(deskripsi, jumlah, tipe, kategori));
        }
    } else {
        std::cerr << "tidak dapat membuka file untuk membaca.\n";
    }
}

