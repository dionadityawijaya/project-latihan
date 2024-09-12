# Sistem Kasir dengan Diskon Dinamis

Program ini mengimplementasikan sistem kasir yang dapat menghitung total harga barang yang dibeli oleh pelanggan dengan berbagai jenis diskon dinamis.

## Fitur

- **Tambah Barang**: Menambahkan barang dengan harga ke dalam sistem.
- **Hapus Barang**: Menghapus barang dari daftar belanja.
- **Hitung Total**: Menghitung total harga dengan diskon (diskon persentase, diskon langsung, diskon berbasis kuantitas).
- **Simpan Transaksi**: Menyimpan transaksi ke dalam file untuk pencatatan.

## Tantangan Tambahan

- Menggunakan pattern `Strategy` untuk implementasi diskon.
- Mengoptimalkan performa untuk transaksi besar.
- Membaca transaksi dari file dan menampilkan laporan harian.

## Cara Menjalankan

1. Buka terminal dan navigasikan ke folder `Cashier_System`.
2. Kompilasi program dengan perintah: `g++ -o cashier cashier.cpp`.
3. Jalankan program dengan perintah: `./cashier`.

## Lisensi

Proyek ini bersifat open-source dan dapat digunakan sesuai dengan [MIT License](../LICENSE).
