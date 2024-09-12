#ifndef DISKON_H
#define DISKON_H

class Diskon {
    public:
        virtual double hitungDiskon(double total) const = 0;
        virtual ~Diskon() = default;
};


class DiskonPersentase : public Diskon {
    private:
        double persentase;
    public:
        DiskonPersentase(double p);
        double hitungDiskon(double total) const override;

};

class DiskonLangsung : public Diskon {
    private:
        double jumlahDiskon;
    public:
        DiskonLangsung(double j);
        double hitungDiskon(double total) const override;
};

class DiskonKuantitas : public Diskon {
    private:
        int kuantitasTreshold;
        double diskonPerItem;
    public:
        DiskonKuantitas(int k, double d);
        double hitungDiskon(double total) const override;
};



#endif