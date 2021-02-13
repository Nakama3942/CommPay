//Библиотека, которая контролирует пользовательский выбор и поток информации из памяти в управляющие методы и обратно для вывода пользователю
#include "CoPa.h"

void check::outlet(tariff coef, FILE *Redactor)
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