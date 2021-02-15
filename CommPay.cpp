#include <iostream>
#include "CoPa.h"
using namespace std;

int main()
{
    entry intro;
    check provka;
    tariff tarcoef;
    FILE *Coef;   //Открываю Value.txt
    FILE *Valuta; //Открываю ISO4217-modified
    Coef = fopen("/usr/local/share/Options.conf", "r+");
    Valuta = fopen("/usr/local/share/Valuta.conf", "r");
    for (;;)
    {
        tarcoef.WorkStorage(Coef, Valuta); //Вызываю метод запоминания
        intro.instruction();               //Вызываю метод, инструктирующий пользователя
        intro.rate();                      //Вызываю метод сетки КоммПлатежей
        provka.outlet(tarcoef, Coef);      //Начинаю работу
        intro.ending();                    //Завершаю работу
    }
    fclose(Coef);
    fclose(Valuta);
    return 0;
}
