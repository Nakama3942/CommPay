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
