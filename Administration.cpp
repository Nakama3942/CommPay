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

//Библиотека, контролирующая администрирование - изменение тарифов и валюты
#include "CoPa.h"

//Функция, меняющая валюту
void Admin::ChangeCurrency(FILE *RedactValut)
{
    cout << "\nВ связи с методами хранения информации, её чтения и обработки, Вы можете изменить этот указатель только указава его соответствующий числовой код. Буквенный может сломать программу до нужды её переустановки. Просмотрите таблицу ISO4217-modified и укажите числовой код вашей валюты. Международный стандарт был немного изменён в связи с особеностями работы программы.";
    cout << "\nУкажите новую валюту: ";
    cin >> newValue;
    fseek(RedactValut, 42, SEEK_SET);
    fprintf(RedactValut, "%i", newValue);
    cout << "\r\n\r\nВалюта изменена! Для сохранения настроек приложение нужно перезагрузить.";
    cout << "\r\nПосле закрытия заново откройте приложение.\n\n";
    cin.get();
    //?Я заметил, что у меня после изменения валюты само содержимое файла вообще не меняется (я проверял через шестнадцатеричный редактор), однако несмотря на это программа всё равно ведёт себя так, словно содержимое файла изменилось. Значит, всё работает правильно, однако моя система неправильно отображает содержимое файла-хранилища
}
//Функция, контролирующая изменения тарифов
void Admin::ChangeRate(FILE *RedactCoef)
{
    do
    {
        do
        {
            cout << "\nВыберите, какой коэффициент исправить: \n";
            cin >> choise[0];
            switch (choise[0])
            {
            case 1:
                proc(RedactCoef, 0);
                ext();
                break;
            case 2:
                cout << "\nУкажите - изменение коэффициента какого диапазоне будет происходить: до 100 (укажите 99) или больше (укажите 999): ";
                do
                {
                    cin >> choise[1];
                    switch (choise[1])
                    {
                    case 99:
                        revision[3] = 0;
                        proc(RedactCoef, 6);
                        ext();
                        break;
                    case 999:
                        revision[3] = 0;
                        proc(RedactCoef, 12);
                        ext();
                        break;
                    default:
                        revision[3] = 1;
                        cout << "\r\nОшибка в ответе. Повторите попытку: ";
                        break;
                    }
                } while (revision[3] == 1);
                break;
            case 3:
                proc(RedactCoef, 18);
                ext();
                break;
            case 4:
                proc(RedactCoef, 24);
                ext();
                break;
            case 5:
                proc(RedactCoef, 30);
                ext();
                break;
            case 6:
                proc(RedactCoef, 36);
                ext();
                break;
            default:
                revision[1] = 1;
                cout << "\r\nОшибка в ответе. Повторите попытку.";
                break;
            }
        } while (revision[1] == 1);
    } while (revision[0] == 1);
}
//Функция, меняющая тарифы
void Admin::proc(FILE *RedactCoef, int step)
{
    revision[1] = 0;
    cout << "\nУкажите новый коэффициент: ";
    cin >> ZamenZnach;
    fseek(RedactCoef, step, SEEK_SET);        //Сносит курсор на первый символ в файле
    fprintf(RedactCoef, "%5.2f", ZamenZnach); //Записывает считанное значение в файл на указанную позицию
}
//Функция, отвечающая за выход из режима администрирования
void Admin::ext()
{
    cout << "Значение изменено! Хотите продолжить редактирование?";
    do
    {
        cin >> AdminWork;
        switch (AdminWork)
        {
        case '1':
            revision[2] = 0;
            revision[0] = 1;
            break;
        case '0':
            revision[2] = 0;
            revision[0] = 0;
            break;
        default:
            revision[2] = 1;
            cout << "\r\nОшибка в ответе. Повторите попытку: ";
            break;
        }
    } while (revision[2] == 1);
}
//Информационный блок, где "1" - приветствие, "0" - завершение
void Admin::greeting(int mode)
{
    switch (mode)
    {
    case 1:
        cout << "\r\n\r\n\r\n   _Режим Администратора_   \r\n\r\n\r\n";
        break;
    case 0:
        cout << "\r\nДля того, чтобы изменения вступили в силу - нужна перезагрузка приложения.\r\nПосле завершиние редактирования приложение закроется. Для работы заново откройте его.\r\n\r\n\r\nРабота Администратора завершена!\r\n\r\n\r\n";
        cin.get();
        break;
    }
}
