//Библиотека, которая принимает пользовательскую информацию и по формулам считает и выводит ответ
#include "CoPa.h"

//Считает плату за квартиру
float payment::Rent(float Plata)
{
    cout << "\r\nКвартплата\r\n\r\nПлощадь квартиры: ";
    cin >> render[0];
    cout << "\r\nКоличество проживающих: ";
    cin >> Zhylci;
    float PlatKvart = Zhylci * render[0] * Plata;
    return PlatKvart;
}
//Считает плату за электричество
float payment::Electricity(float PlataDo, float PlataBolshe)
{
    cout << "\r\nЭлектричество\r\n\r\nКоличество кВт/час, использованных за месяц: ";
    cin >> render[1];
    if (render[1] < 100)
        render[1] *= PlataDo;
    else
        render[1] *= PlataBolshe;
    return render[1];
}
//Считает плату за газ
float payment::Gas(float Plata)
{
    cout << "\r\nГаз\r\n\r\nКоличество кубометров, использованных за месяц: ";
    cin >> render[2];
    render[2] *= Plata;
    return render[2];
}
//Считает плату за холодную воду
float payment::ColdWater(float Plata)
{
    cout << "\r\nХолодная вода\r\n\r\nКоличество кубометров, использованных за месяц: ";
    cin >> render[3];
    render[3] *= Plata;
    return render[3];
}
//Считает плату за гарячую воду
float payment::HotWater(float Plata)
{
    cout << "\r\nГорячая вода\r\n\r\nКоличество кубометров, использованных за месяц: ";
    cin >> render[4];
    render[4] *= Plata;
    return render[4];
}
//Считает плату за отопление
float payment::Heating(float Plata)
{
    cout << "\r\nОтопление\r\n\r\nОбщая площадь квартиры: ";
    cin >> render[5];
    render[5] *= Plata;
    return render[5];
}
//Функция выводт результат
void payment::sum(float summa, char LettKeyVal[3])
{
    cout << "\nСумма к оплате - " << summa << " " << LettKeyVal[0] << LettKeyVal[1] << LettKeyVal[2] << ".\n\n";
}