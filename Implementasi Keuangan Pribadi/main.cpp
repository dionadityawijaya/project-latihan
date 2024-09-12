#include "financialReport.hpp"

int main(int argc, char const *argv[])
{
    FinancialReport* laporan = new FinancialReport();


    laporan->tambahTransaksi(Transaction("Makan Siang", 50.0, Transaction::Tipe::Pengeluaran, Category("Makan")));
    laporan->tambahTransaksi(Transaction("Gaji Bulanan", 3000.0, Transaction::Tipe::Pemasukan, Category("Pendapatan")));
    laporan->tambahTransaksi(Transaction("Transportasi", 100.0, Transaction::Tipe::Pengeluaran, Category("Transportasi")));

    laporan->tampilkanLaporan();
    laporan->tampilkanGrafikPengeluaran();
    laporan->simpanTransaksiKeFile("transaksi.json");
    laporan->hapusTransaksi("Makan Siang");
    laporan->tampilkanLaporan();
    laporan->muatTransaksiDariFile("transaksi.json");

    delete laporan;
    
    return 0;
}
