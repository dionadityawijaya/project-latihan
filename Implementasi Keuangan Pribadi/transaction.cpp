#include "transaction.hpp"

Transaction::Transaction(const std::string& d, double j, Tipe t, const Category& c) : deskripsi(d), jumlah(j), tipe(t), kategori(c) {}

double Transaction::getJumlah() const { 
    return jumlah;
}
Transaction::Tipe Transaction::getTipe() const 
{
    return tipe;
}
const std::string& Transaction::getDeskripsi() const 
{
    return deskripsi;
}
const Category& Transaction::getKategori() const 
{
    return kategori;
}
json Transaction::tojson() const {
    return json {
        {"deskripsi", deskripsi},
        {"jumlah", jumlah},
        {"tipe", tipe == Tipe::Pemasukan ? "Pemasukan" : "Pengeluaran"},
        {"kategori", kategori.nama}
    };
}