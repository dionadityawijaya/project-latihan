#include "diskon.h"

DiskonPersentase::DiskonPersentase(double p) : persentase(p) {}

double DiskonPersentase::hitungDiskon(double total) const {
    return total * (persentase / 100);
}

DiskonLangsung::DiskonLangsung(double j) : jumlahDiskon(j) {}

double DiskonLangsung::hitungDiskon(double total) const {
    return jumlahDiskon;
}

DiskonKuantitas::DiskonKuantitas(int k, double d) : kuantitasTreshold(k), diskonPerItem(d) {}

double DiskonKuantitas::hitungDiskon(double total) const {
    return total > kuantitasTreshold ? diskonPerItem * kuantitasTreshold : 0;
}