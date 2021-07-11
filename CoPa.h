/* ****************************************************************************
 * -------------------------------------------------------------------------- *
 *                                                                            *
 * Copyright © 2021 Kalynovsky Valentin. All rights reserved.                 *
 * Licensed under the Apache License, Version 2.0                             *
 *                                                                            *
 * Licensed under the Apache License, Version 2.0 (the "License");            *
 * you may not use this file except in compliance with the License.           *
 * You may obtain a copy of the License at                                    *
 *                                                                            *
 *     http://www.apache.org/licenses/LICENSE-2.0                             *
 *                                                                            *
 * Unless required by applicable law or agreed to in writing, software        *
 * distributed under the License is distributed on an "AS IS" BASIS,          *
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.   *
 * See the License for the specific language governing permissions and        *
 * limitations under the License.                                             *
 *                                                                            *
 * -------------------------------------------------------------------------- *
 * ************************************************************************** */

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
    float coefficient[7] = {};                  //Хранит коэффициенты тарифов
    char LettKeyVal[3] = {};                    //Хранит буквенную кодировку валюты пользователся
    void WorkStorage(FILE *Coef, FILE *Valuta); //Метод, запускающий запоминание

private:
    int KeyValuta;                                                 //Хранит чисельную кодировку валюты пользователя
    int NumeralKeyValuta[134] = {};                                //Хранит чисельную кодировку валют из ISO4217-modified
    char LetterKeyValuta[3][134] = {};                             //Хранит буквенную кодировку валют из ISO4217-modified
    void SearchVal();                                              //Метод запоминания буквенной кодировки пользователя
    void JobsWithMemory(FILE *Coef, FILE *Valuta);                 //Метод, организовывающий запоминание
    void memfsfsC(FILE *Coef, int i);                              //Метод запоминания тарифов в coefficient
    void memkeyC(FILE *Coef, int i);                               //Метод запоминания валюты пользователся
    void memfsfsNV(FILE *Valuta, int i);                           //Метод запоминания числовой кодировки
    void memfsfsLV(FILE *Valuta, int i, int massone, int masstwo); //Метод запоминания буквенной кодировки
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
    float Rent(float Plata);
    float Electricity(float PlataDo, float PlataBolshe);
    float Gas(float Plata);
    float ColdWater(float Plata);
    float HotWater(float Plata);
    float Heating(float Plata);
    void sum(float summa, char LettKeyVal[3]);

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
