#ifndef clpayment
#define clpayment
#include <iostream>
using namespace std;

class payment
{
public:
    void Rent(float Plata, int Valuta)
    {
        cout << "\r\nКвартплата\r\n\r\nПлощадь квартиры: ";
        cin >> KvartPlat;
        cout << "\r\nКоличество проживающих: ";
        cin >> Zhylci;
        float PlatKvart = Zhylci * KvartPlat * Plata;
        sum(PlatKvart, Valuta);
    }
    void Electricity(float PlataDo, float PlataBolshe, int Valuta)
    {
        cout << "\r\nЭлектричество\r\n\r\nКоличество кВт/час, использованных за месяц: ";
        cin >> Electro;
        if (Electro < 100)
        {
            Electro *= PlataDo;
            sum(Electro, Valuta);
        }
        else if (Electro >= 100)
        {
            Electro *= PlataBolshe;
            sum(Electro, Valuta);
        }
    }
    void Gas(float Plata, int Valuta)
    {
        cout << "\r\nГаз\r\n\r\nКоличество кубометров, использованных за месяц: ";
        cin >> Gaz;
        Gaz *= Plata;
        sum(Gaz, Valuta);
    }
    void ColdWater(float Plata, int Valuta)
    {
        cout << "\r\nХолодная вода\r\n\r\nКоличество кубометров, использованных за месяц: ";
        cin >> HolVoda;
        HolVoda *= Plata;
        sum(HolVoda, Valuta);
    }
    void HotWater(float Plata, int Valuta)
    {
        cout << "\r\nГорячая вода\r\n\r\nКоличество кубометров, использованных за месяц: ";
        cin >> GarVoda;
        GarVoda = GarVoda * Plata;
        sum(GarVoda, Valuta);
    }
    void Heating(float Plata, int Valuta)
    {
        cout << "\r\nОтопление\r\n\r\nОбщая площадь квартиры: ";
        cin >> Otopl;
        Otopl *= Plata;
        sum(Otopl, Valuta);
    }
    void sum(float summa, int Valuta)
    {
        switch (Valuta)
        {
        case 100:
            cout << "\nСумма к оплате - " << summa << " RUB.\n\n";
            break;
        case 101:
            cout << "\nСумма к оплате - " << summa << " UAH.\n\n";
            break;
        case 102:
            cout << "\nСумма к оплате - " << summa << " BYN.\n\n";
            break;
        }
    }

private:
    int Zhylci;
    float KvartPlat, Electro, Gaz, GarVoda, HolVoda, Otopl;
};

#endif