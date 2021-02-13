//Библиотека, которая принимает пользовательскую информацию и по формулам считает и выводит ответ
#include "CoPa.h"

//Считает плату за квартиру
void payment::Rent(float Plata, int Valuta)
{
    cout << "\r\nКвартплата\r\n\r\nПлощадь квартиры: ";
    cin >> render[0];
    cout << "\r\nКоличество проживающих: ";
    cin >> Zhylci;
    float PlatKvart = Zhylci * render[0] * Plata;
    sum(PlatKvart, Valuta);
}
//Считает плату за электричество
void payment::Electricity(float PlataDo, float PlataBolshe, int Valuta)
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
//Считает плату за газ
void payment::Gas(float Plata, int Valuta)
{
    cout << "\r\nГаз\r\n\r\nКоличество кубометров, использованных за месяц: ";
    cin >> render[2];
    render[2] *= Plata;
    sum(render[2], Valuta);
}
//Считает плату за холодную воду
void payment::ColdWater(float Plata, int Valuta)
{
    cout << "\r\nХолодная вода\r\n\r\nКоличество кубометров, использованных за месяц: ";
    cin >> render[3];
    render[3] *= Plata;
    sum(render[3], Valuta);
}
//Считает плату за гарячую воду
void payment::HotWater(float Plata, int Valuta)
{
    cout << "\r\nГорячая вода\r\n\r\nКоличество кубометров, использованных за месяц: ";
    cin >> render[4];
    render[4] *= Plata;
    sum(render[4], Valuta);
}
//Считает плату за отопление
void payment::Heating(float Plata, int Valuta)
{
    cout << "\r\nОтопление\r\n\r\nОбщая площадь квартиры: ";
    cin >> render[5];
    render[5] *= Plata;
    sum(render[5], Valuta);
}
//Функция выводт результат
void payment::sum(float summa, int Valuta)
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
    default:
        cout << "\nСумма к оплате - " << summa << " \aother currency.\n\n";
        break;
    }
}