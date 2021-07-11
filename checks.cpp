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
            pay.sum(pay.Rent(coef.coefficient[0]), coef.LettKeyVal);
            break;
        case '2':
            ProverVybKoef = 0;
            pay.sum(pay.Electricity(coef.coefficient[1], coef.coefficient[2]), coef.LettKeyVal);
            break;
        case '3':
            ProverVybKoef = 0;
            pay.sum(pay.Gas(coef.coefficient[3]), coef.LettKeyVal);
            break;
        case '4':
            ProverVybKoef = 0;
            pay.sum(pay.ColdWater(coef.coefficient[4]), coef.LettKeyVal);
            break;
        case '5':
            ProverVybKoef = 0;
            pay.sum(pay.HotWater(coef.coefficient[5]), coef.LettKeyVal);
            break;
        case '6':
            ProverVybKoef = 0;
            pay.sum(pay.Heating(coef.coefficient[6]), coef.LettKeyVal);
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
