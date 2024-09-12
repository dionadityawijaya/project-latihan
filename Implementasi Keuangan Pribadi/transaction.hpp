#include <string>
#include "category.hpp"
#include "json.hpp"


using json = nlohmann::json;

class Transaction {
    public:
        enum class Tipe {Pemasukan, Pengeluaran};

    private:
        std::string deskripsi;
        double jumlah;
        Tipe tipe;
        Category kategori;
    public:
        Transaction(const std::string& d, double j, Tipe t, const Category& c);
        double getJumlah() const;
        Tipe getTipe() const;
        const std::string& getDeskripsi() const;
        const Category& getKategori() const;
        json tojson() const;
};