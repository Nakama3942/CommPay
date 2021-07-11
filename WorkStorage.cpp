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

//Библиотека, которая хранит важную информацию и обрабатывает её
#include "CoPa.h"

//Метод, запускающий запоминание
void tariff::WorkStorage(FILE *Coef, FILE *Valuta)
{
    JobsWithMemory(Coef, Valuta);
    SearchVal();
}
//Метод запоминания буквенной кодировки пользователя
void tariff::SearchVal()
{
    for (int i = 0; i < 134; i++)
        if (NumeralKeyValuta[i] == KeyValuta)
            for (int j = 0; j < 3; j++)
                LettKeyVal[j] = LetterKeyValuta[j][i];
}
//Метод, организовывающий запоминание
void tariff::JobsWithMemory(FILE *Coef, FILE *Valuta)
{
    //Запоминаю тарифы в coefficient
    for (int i = 0; i < 6; i++)
        memfsfsC(Coef, i * 6);
    //Запоминаю валюту пользователя
    memkeyC(Coef, 42);
    //Запоминаю валюты в числовой кодировке
    for (int i = 0; i < 134; i++)
        memfsfsNV(Valuta, i * 8);
    //Запоминаю валюты в буквенной кодировке
    for (int i = 0; i < 134; i++)
    {
        if (i == 0)
        {
            memfsfsLV(Valuta, i + 4, 0, i);
            memfsfsLV(Valuta, i + 5, 1, i);
            memfsfsLV(Valuta, i + 6, 2, i);
        }
        else
        {
            memfsfsLV(Valuta, i * 8 + 4, 0, i);
            memfsfsLV(Valuta, i * 8 + 5, 1, i);
            memfsfsLV(Valuta, i * 8 + 6, 2, i);
        }
    }
}
//Метод запоминания тарифов в coefficient
void tariff::memfsfsC(FILE *Coef, int i)
{
    fseek(Coef, i, SEEK_SET);
    if (i == 0)
        fscanf(Coef, "%f", &coefficient[i]);
    else
        fscanf(Coef, "%f", &coefficient[i / 6]);
}
//Метод запоминания валюты пользователся
void tariff::memkeyC(FILE *Coef, int i)
{
    fseek(Coef, i, SEEK_SET);
    fscanf(Coef, "%i", &KeyValuta);
}
//Метод запоминания числовой кодировки
void tariff::memfsfsNV(FILE *Valuta, int i)
{
    fseek(Valuta, i, SEEK_SET);
    if (i == 0)
        fscanf(Valuta, "%i", &NumeralKeyValuta[i]);
    else
        fscanf(Valuta, "%i", &NumeralKeyValuta[i / 8]);
}
//Метод запоминания буквенной кодировки
void tariff::memfsfsLV(FILE *Valuta, int i, int massone, int masstwo)
{
    fseek(Valuta, i, SEEK_SET);
    fscanf(Valuta, "%c", &LetterKeyValuta[massone][masstwo]);
}
