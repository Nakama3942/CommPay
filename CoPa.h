#ifndef CoPa
#define CoPa
#include <iostream>
using namespace std;

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
class entry
{
public:
    void instruction();
    void rate();
    void ending();

private:
    char ext;
    bool VyhodIzProg = 0;
};
class Admin
{
public:
    void ChangeCurrency(FILE *RedactValut);
    void ChangeRate(FILE *RedactCoef);
    void proc(FILE *RedactCoef, int step);
    void ext();
    void greeting(int mode);

private:
    //Первое значение - Выбор изменения коэффициента
    //Второе - Выбор диапазона (для электричества)
    int choise[2] = {}, newValue;
    //Первое значение - Выход из Администрирования
    //Второе - Проверка выбора изменения коэффициента
    //Третье - Проверка выхода из кейса
    //Четвёртое - Проверка выбора диапазона
    bool revision[4] = {0, 0, 0, 0};
    char AdminWork;
    float ZamenZnach;
};
class payment
{
public:
    void Rent(float Plata, int Valuta);
    void Electricity(float PlataDo, float PlataBolshe, int Valuta);
    void Gas(float Plata, int Valuta);
    void ColdWater(float Plata, int Valuta);
    void HotWater(float Plata, int Valuta);
    void Heating(float Plata, int Valuta);
    void sum(float summa, int Valuta);

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
    void outlet(tariff coef, FILE *Redactor);

private:
    bool ProverVybKoef = 0;
    char ChosenCoef;
};

#endif