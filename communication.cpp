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

//Библиотека общения с пользователем
#include "CoPa.h"

//Функция приветствия
void entry::instruction()
{
    cout << "\r\n\r\n_ИНСТРУКЦИЯ_\r\n\r\nДля выбора нажимайте соответствующие клавиши от 1 до 9.\nДля согласия нажмите 1, для отказа нажмите 0.\n\r\n\r\n";
}
//Информационная функция
void entry::rate()
{
    cout << "\r\n\r\nРасчёт комунальных платежей\r\n___________________________\r\n   1   Квартплата   \r\n   2   Электричество   \r\n   3   Газ   \r\n   4   Холодная вода   \r\n   5   Гарячая вода   \r\n   6   Отопление   \r\n___________________________\r\n   9   Изменить валюту   \r\n___________________________\r\nВыберите форму расчёта   \r\n___________________________\r\n";
}
//Функция, контролирующая выход из программы
void entry::ending()
{
    do
    {
        cout << "Будете продолжать расчёты (1/0) ?\r\n";
        cin >> ext;
        switch (ext)
        {
        case '1':
            VyhodIzProg = 0;
            break;
        case '0':
            cout << "\n\nПриложение закрывается.\n\n";
            cin.get();
            cin.get();
            exit(0);
        default:
            VyhodIzProg = 1;
            cout << "\r\nОшибка в ответе. Повторите попытку: ";
            break;
        }
    } while (VyhodIzProg == 1);
}
