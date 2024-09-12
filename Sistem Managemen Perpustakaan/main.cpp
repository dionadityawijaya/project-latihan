#include "perpustakaan.h"


int main(int argc, char const *argv[])
{
    Perpustakaan* perpustakaan = new Perpustakaan();
    perpustakaan->tambahBuku(1, "C++ Programming", "Bjarne Stroustrup");
    perpustakaan->tambahBuku(2, "Effective Modern C++", "Scott Meyers");
    perpustakaan->tambahBuku(3, "Clean Code", "Robert C. Martin");

    perpustakaan->cariBuku(2);
    perpustakaan->pinjamBuku(2);

    perpustakaan->pinjamBuku(2);
    perpustakaan->kembalikanBuku(2);

    perpustakaan->hapusBuku(3);
    perpustakaan->tampilkanSemuaBuku();

    delete perpustakaan;

    return 0;
}

