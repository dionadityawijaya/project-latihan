#include "kasir.h"
#include <iostream>

int main() {
    Kasir kasir;

    kasir.tambahBarang("Buku C++", 150.00);
    kasir.tambahBarang("Buku Java", 200.00);
    kasir.tambahBarang("Keyboard", 50.00);

    kasir.setDiskon(std::make_unique<DiskonPersentase>(10));

    std::cout << "Total harga setelah diskon: " << kasir.hitungTotal() << std::endl;

    kasir.simpanTransaksi("transaksi.txt");

    kasir.hapusBarang("Keyboard");

    kasir.setDiskon(std::make_unique<DiskonLangsung>(20));

    std::cout << "Total harga setelah diskon baru: " << kasir.hitungTotal() << std::endl;

    kasir.simpanTransaksi("transaksi.txt");

    Kasir::tampilkanLaporanHarian("transaksi.txt");

    return 0;
}
