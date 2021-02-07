#ifndef cltariff
#define cltariff

class tariff
{
public:
    /*
    1 коэффициент - тариф за квартплату
    2 - за электричество до 100 кВт
    3 - за электричество от 100 кВт
    4 - за газ
    5 - за холодную воду
    6 - за гарячую воду
    7 - за отопление
    */
    float coefficient[7] = {};
    int KodValut;
};

#endif