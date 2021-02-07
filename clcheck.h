//Для этой библиотеки необходимо объявить перед ней библиотеку clAdmin, которая отвечает за Администрирование: изменение тарифов и валюты. Без неё программа при компилировании будет выдавать ошибку!
#ifndef clcheck
#define clcheck
#include <iostream>
using namespace std;

class payment
{
public:
    void Rent(float Plata, int Valuta)
    {
        cout << "\r\nКвартплата\r\n\r\nПлощадь квартиры: ";
        cin >> render[0];
        cout << "\r\nКоличество проживающих: ";
        cin >> Zhylci;
        float PlatKvart = Zhylci * render[0] * Plata;
        sum(PlatKvart, Valuta);
    }
    void Electricity(float PlataDo, float PlataBolshe, int Valuta)
    {
        cout << "\r\nЭлектричество\r\n\r\nКоличество кВт/час, использованных за месяц: ";
        cin >> render[1];
        if (render[1] < 100)
        {
            render[1] *= PlataDo;
            sum(render[1], Valuta);
        }
        else if (render[1] >= 100)
        {
            render[1] *= PlataBolshe;
            sum(render[1], Valuta);
        }
    }
    void Gas(float Plata, int Valuta)
    {
        cout << "\r\nГаз\r\n\r\nКоличество кубометров, использованных за месяц: ";
        cin >> render[2];
        render[2] *= Plata;
        sum(render[2], Valuta);
    }
    void ColdWater(float Plata, int Valuta)
    {
        cout << "\r\nХолодная вода\r\n\r\nКоличество кубометров, использованных за месяц: ";
        cin >> render[3];
        render[3] *= Plata;
        sum(render[3], Valuta);
    }
    void HotWater(float Plata, int Valuta)
    {
        cout << "\r\nГорячая вода\r\n\r\nКоличество кубометров, использованных за месяц: ";
        cin >> render[4];
        render[4] *= Plata;
        sum(render[4], Valuta);
    }
    void Heating(float Plata, int Valuta)
    {
        cout << "\r\nОтопление\r\n\r\nОбщая площадь квартиры: ";
        cin >> render[5];
        render[5] *= Plata;
        sum(render[5], Valuta);
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
    //Первое значение - Квартплата
    //Второе - Плата за электричество
    //Третье - За газ
    //Четвёртое - За холодную воду
    //Пятое - За гарячую воду
    //Шестое - За отопление
    float render[6] = {};
    int Zhylci;
};
class check
{
public:
    void outlet(tariff coef, FILE *Redactor)
    {
        payment pay;
        Admin dmn;
        do
        {
            cin >> ChosenCoef;
            switch (ChosenCoef)
            {
            case 'a':
                ProverVybKoef = 0;
                dmn.greeting(1);
                dmn.ChangeRate(Redactor);
                dmn.greeting(0);
                exit(0);
                break;
            case '0':
                ProverVybKoef = 0;
                cout << "\n\nПриложение закрывается. ";
                cin.get();
                exit(0);
                break;
            case '1':
                ProverVybKoef = 0;
                pay.Rent(coef.coefficient[0], coef.KodValut);
                break;
            case '2':
                ProverVybKoef = 0;
                pay.Electricity(coef.coefficient[1], coef.coefficient[2], coef.KodValut);
                break;
            case '3':
                ProverVybKoef = 0;
                pay.Gas(coef.coefficient[3], coef.KodValut);
                break;
            case '4':
                ProverVybKoef = 0;
                pay.ColdWater(coef.coefficient[4], coef.KodValut);
                break;
            case '5':
                ProverVybKoef = 0;
                pay.HotWater(coef.coefficient[5], coef.KodValut);
                break;
            case '6':
                ProverVybKoef = 0;
                pay.Heating(coef.coefficient[6], coef.KodValut);
                break;
            case '9':
                ProverVybKoef = 0;
                dmn.ChangeCurrency(Redactor);
                exit(0);
                break;
            default:
                ProverVybKoef = 1;
                cout << "Задано неправильное значение. Повторите попытку: ";
                break;
            }
        } while (ProverVybKoef == 1);
    }

private:
    bool ProverVybKoef = 0;
    char ChosenCoef;
};

#endif