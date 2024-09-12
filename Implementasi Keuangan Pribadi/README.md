# Sistem Keuangan Pribadi dengan OOP

Aplikasi ini memungkinkan pengguna untuk mengelola keuangan pribadi dengan fitur pencatatan pemasukan dan pengeluaran serta menampilkan laporan keuangan.

## Fitur

- **Tambah Transaksi**: Menambah transaksi keuangan dengan kategori.
- **Hapus Transaksi**: Menghapus transaksi yang sudah ada.
- **Tampilkan Laporan**: Menampilkan laporan berdasarkan bulan atau kategori.
- **Grafik Pengeluaran**: Menampilkan grafik pengeluaran bulanan (menggunakan ASCII art).

## Tantangan Tambahan

- Menggunakan konsep OOP (class `Transaction`, `Category`, `FinancialReport`).
- Menyimpan dan memuat data transaksi dari file JSON.

## Cara Menjalankan

1. Buka terminal dan navigasikan ke folder `Personal_Finance_System`.
2. Kompilasi program dengan perintah: `g++ -o finance finance.cpp -ljson`.
3. Jalankan program dengan perintah: `./finance`.

## Lisensi

Proyek ini bersifat open-source dan dapat digunakan sesuai dengan [MIT License](../LICENSE).
