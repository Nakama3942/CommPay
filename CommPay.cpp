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
class payment
{
public:
    void Rent(float Plata, int Valuta)
    {
        cout << "\r\nКвартплата\r\n\r\nПлощадь квартиры: ";
        cin >> KvartPlat;
        cout << "\r\nКоличество проживающих: ";
        cin >> Zhylci;
        float PlatKvart = Zhylci * KvartPlat * Plata;
        sum(PlatKvart, Valuta);
    }
    void Electricity(float PlataDo, float PlataBolshe, int Valuta)
    {
        cout << "\r\nЭлектричество\r\n\r\nКоличество кВт/час, использованных за месяц: ";
        cin >> Electro;
        if (Electro < 100)
        {
            Electro *= PlataDo;
            sum(Electro, Valuta);
        }
        else if (Electro >= 100)
        {
            Electro *= PlataBolshe;
            sum(Electro, Valuta);
        }
    }
    void Gas(float Plata, int Valuta)
    {
        cout << "\r\nГаз\r\n\r\nКоличество кубометров, использованных за месяц: ";
        cin >> Gaz;
        Gaz *= Plata;
        sum(Gaz, Valuta);
    }
    void ColdWater(float Plata, int Valuta)
    {
        cout << "\r\nХолодная вода\r\n\r\nКоличество кубометров, использованных за месяц: ";
        cin >> HolVoda;
        HolVoda *= Plata;
        sum(HolVoda, Valuta);
    }
    void HotWater(float Plata, int Valuta)
    {
        cout << "\r\nГорячая вода\r\n\r\nКоличество кубометров, использованных за месяц: ";
        cin >> GarVoda;
        GarVoda = GarVoda * Plata;
        sum(GarVoda, Valuta);
    }
    void Heating(float Plata, int Valuta)
    {
        cout << "\r\nОтопление\r\n\r\nОбщая площадь квартиры: ";
        cin >> Otopl;
        Otopl *= Plata;
        sum(Otopl, Valuta);
    }
    void sum(float summa, int Valuta)
    {
        switch (Valuta)
        {
        case 100:
            cout << "\nСумма к оплате - " << summa << " RUB.\n\n";
            break;
        case 101:
            cout << "\nСумма к оплате - " << summa << " UAH.\n\n";
            break;
        case 102:
            cout << "\nСумма к оплате - " << summa << " BYN.\n\n";
            break;
        }
    }

private:
    int Zhylci;
    float KvartPlat, Electro, Gaz, GarVoda, HolVoda, Otopl;
};
class entry
{
public:
    void instruction()
    {
        cout << "\r\n\r\n_ИНСТРУКЦИЯ_\r\n\r\n";
        cout << "Для выбора нажимайте соответствующие клавиши от 1 до 9.\n";
        cout << "Для согласия нажмите 1, для отказа нажмите 0.\n\r\n\r\n";
    }
    void rate()
    {
        cout << "\r\n\r\nРасчёт комунальных платежей\r\n";
        cout << "___________________________\r\n";
        cout << "   1   Квартплата   \r\n";
        cout << "   2   Электричество   \r\n";
        cout << "   3   Газ   \r\n";
        cout << "   4   Холодная вода   \r\n";
        cout << "   5   Гарячая вода   \r\n";
        cout << "   6   Отопление   \r\n";
        cout << "___________________________\r\n";
        cout << "   9   Изменить валюту   \r\n";
        cout << "___________________________\r\n";
        cout << "Выберите форму расчёта   \r\n";
        cout << "___________________________\r\n";
    }
    void ending()
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

private:
    char ext;
    bool VyhodIzProg = 0;
};
class IzmenValut
{
public:
    void IzmenValue(FILE *RedactValut)
    {
        int RValut;
        cout << "RUB = 100; UAH = 101; BYN = 102";
        cout << "\nУкажите новую валюту: ";
        cin >> RValut;
        fseek(RedactValut, 42, SEEK_SET);
        fprintf(RedactValut, "%i", RValut);
        cout << "\r\n\r\nВалюта изменена! Для сохранения настроек приложение нужно перезагрузить.";
        cout << "\r\nПосле закрытия заново откройте приложение.\n\n";
        cin.get();
        //?Я заметил, что у меня после изменения валюты само содержимое файла вообще не меняется (я проверял через шестнадцатеричный редактор), однако несмотря на это программа всё равно ведёт себя так, словно содержимое файла изменилось. Значит, всё работает правильно, однако моя система неправильно отображает содержимое файла-хранилища
    }
};
class check
{
public:
    void outlet(tariff coef, FILE *RedactValut)
    {
        payment pay;
        IzmenValut NewValut;
        do
        {
            cin >> ChosenCoef;
            switch (ChosenCoef)
            {
            case 'a':
                ProverVybKoef = 0;
                //!Admin();
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
                NewValut.IzmenValue(RedactValut);
                exit(0);
                break;
            default:
                ProverVybKoef = 1;
                cout << "Задано неправильное значение. Повторите попытку: ";
                break;
            }
        } while (ProverVybKoef == 1);
    }

private:
    bool ProverVybKoef = 0;
    char ChosenCoef;
};
/*
void Admin()
{
    cout << "---";
}
*/
int main()
{
    entry intro;
    check provka;
    tariff tarcoef;
    FILE *coef;
    coef = fopen("Options.txt", "r+");
    fscanf(coef, "%f %f %f %f %f %f %f %i", &tarcoef.coefficient[0], &tarcoef.coefficient[1], &tarcoef.coefficient[2], &tarcoef.coefficient[3], &tarcoef.coefficient[4], &tarcoef.coefficient[5], &tarcoef.coefficient[6], &tarcoef.KodValut);
    for (;;)
    {
        intro.instruction();
        intro.rate();
        provka.outlet(tarcoef, coef);
        intro.ending();
    }
    fclose(coef);
    return 0;
}
