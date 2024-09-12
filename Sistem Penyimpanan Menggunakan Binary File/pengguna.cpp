#include <iostream>
#include <fstream>
#include <vector>
#include "pengguna.h"

void tambahPengguna(const std::string& namaFile, const Pengguna& pengguna) {
    std::ofstream file(namaFile, std::ios::binary | std::ios::app);
    if (!file) {
        std::cerr << "Gagal membuka file untuk menulis." << std::endl;
        return;
    }

    size_t namaLength = pengguna.nama.size();
    size_t emailLength = pengguna.email.size();

    file.write(reinterpret_cast<const char*>(&pengguna.id), sizeof(pengguna.id));
    file.write(reinterpret_cast<const char*>(&namaLength), sizeof(namaLength));
    file.write(pengguna.nama.c_str(), namaLength);
    file.write(reinterpret_cast<const char*>(&emailLength), sizeof(emailLength));
    file.write(pengguna.email.c_str(), emailLength);

    std::cout << "Pengguna berhasil ditambahkan." << std::endl;
}

Pengguna cariPengguna(const std::string& namaFile, int id) {
    std::ifstream file(namaFile, std::ios::binary);
    if (!file) {
        std::cerr << "Gagal membuka file untuk membaca." << std::endl;
        return Pengguna{-1, "", ""}; // ID -1 menandakan tidak ditemukan
    }

    Pengguna pengguna;
    size_t namaLength, emailLength;

    while (file.read(reinterpret_cast<char*>(&pengguna.id), sizeof(pengguna.id))) {
        file.read(reinterpret_cast<char*>(&namaLength), sizeof(namaLength));

        // Validasi panjang nama sebelum resize
        if (namaLength > 0 && namaLength < 1000) { // Misalnya: panjang maksimal nama dibatasi hingga 1000 karakter
            pengguna.nama.resize(namaLength);
            file.read(&pengguna.nama[0], namaLength);
        } else {
            std::cerr << "Panjang nama tidak valid." << std::endl;
            return Pengguna{-1, "", ""};
        }

        file.read(reinterpret_cast<char*>(&emailLength), sizeof(emailLength));

        // Validasi panjang email sebelum resize
        if (emailLength > 0 && emailLength < 1000) { // Misalnya: panjang maksimal email dibatasi hingga 1000 karakter
            pengguna.email.resize(emailLength);
            file.read(&pengguna.email[0], emailLength);
        } else {
            std::cerr << "Panjang email tidak valid." << std::endl;
            return Pengguna{-1, "", ""};
        }

        if (pengguna.id == id) {
            return pengguna;
        }
    }

    return Pengguna{-1, "", ""}; // ID -1 menandakan tidak ditemukan
}

void hapusPengguna(const std::string& namaFile, int id) {
    std::vector<Pengguna> penggunaList;
    Pengguna pengguna;
    size_t namaLength, emailLength;

    std::ifstream fileBaca(namaFile, std::ios::binary);
    if (!fileBaca) {
        std::cerr << "Gagal membuka file untuk membaca.\n";
        return;
    }

    while (fileBaca.read(reinterpret_cast<char*>(&pengguna.id), sizeof(pengguna.id))) {
        fileBaca.read(reinterpret_cast<char*>(&namaLength), sizeof(namaLength));
        pengguna.nama.resize(namaLength);
        fileBaca.read(&pengguna.nama[0], namaLength);

        fileBaca.read(reinterpret_cast<char*>(&emailLength), sizeof(emailLength));
        pengguna.email.resize(emailLength);  // Perbaiki dari pengguna.nama ke pengguna.email
        fileBaca.read(&pengguna.email[0], emailLength);

        if (pengguna.id != id) {
            penggunaList.push_back(pengguna);
        }
    }

    fileBaca.close();

    std::ofstream fileTulis(namaFile, std::ios::binary | std::ios::trunc);  // Perbaiki dari std::ios::app ke std::ios::trunc
    if (!fileTulis) {
        std::cerr << "Gagal membuka file untuk menulis." << std::endl;
        return;
    }

    for (const auto& p : penggunaList) {
        // Tambahkan data langsung ke file yang sudah dibuka
        size_t namaLength = p.nama.size();
        size_t emailLength = p.email.size();
        fileTulis.write(reinterpret_cast<const char*>(&p.id), sizeof(p.id));
        fileTulis.write(reinterpret_cast<const char*>(&namaLength), sizeof(namaLength));
        fileTulis.write(p.nama.c_str(), namaLength);
        fileTulis.write(reinterpret_cast<const char*>(&emailLength), sizeof(emailLength));
        fileTulis.write(p.email.c_str(), emailLength);
    }

    std::cout << "Pengguna berhasil dihapus.\n";
}

void updatePengguna(const std::string& namaFile, const Pengguna& penggunaBaru) {
    std::vector<Pengguna> penggunaList;
    Pengguna pengguna;
    size_t namaLength, emailLength;

    std::ifstream fileBaca(namaFile, std::ios::binary);
    if (!fileBaca) {
        std::cerr << "Gagal membuka file untuk membaca.\n";
        return;
    }

    while (fileBaca.read(reinterpret_cast<char*>(&pengguna.id), sizeof(pengguna.id))) {
        fileBaca.read(reinterpret_cast<char*>(&namaLength), sizeof(namaLength));
        pengguna.nama.resize(namaLength);
        fileBaca.read(&pengguna.nama[0], namaLength);

        fileBaca.read(reinterpret_cast<char*>(&emailLength), sizeof(emailLength));
        pengguna.email.resize(emailLength);  // Perbaiki dari pengguna.nama ke pengguna.email
        fileBaca.read(&pengguna.email[0], emailLength);

        if (pengguna.id == penggunaBaru.id) {
            penggunaList.push_back(penggunaBaru);
        } else {
            penggunaList.push_back(pengguna);
        }
    }

    fileBaca.close();

    std::ofstream fileTulis(namaFile, std::ios::binary | std::ios::trunc);  // Perbaiki dari std::ios::app ke std::ios::trunc
    if (!fileTulis) {
        std::cerr << "Gagal membuka file untuk menulis." << std::endl;
        return;
    }

    for (const auto& p : penggunaList) {
        // Tambahkan data langsung ke file yang sudah dibuka
        size_t namaLength = p.nama.size();
        size_t emailLength = p.email.size();
        fileTulis.write(reinterpret_cast<const char*>(&p.id), sizeof(p.id));
        fileTulis.write(reinterpret_cast<const char*>(&namaLength), sizeof(namaLength));
        fileTulis.write(p.nama.c_str(), namaLength);
        fileTulis.write(reinterpret_cast<const char*>(&emailLength), sizeof(emailLength));
        fileTulis.write(p.email.c_str(), emailLength);
    }

    std::cout << "Pengguna berhasil diupdate.\n";
}
