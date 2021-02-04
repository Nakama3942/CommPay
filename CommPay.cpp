#include <iostream>
#include <cstdio>
using namespace std;

/*class tariff
{
public:
    
};*/
class payment
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
    void Rent()
    {
        cout << "\r\nКвартплата\r\n\r\nПлощадь квартиры: ";
        cin >> KvartPlat;
        cout << "\r\nКоличество проживающих: ";
        cin >> Zhylci;
        float PlatKvart = Zhylci * KvartPlat * coefficient[0];
        sum(PlatKvart);
    }
    void Electricity()
    {
        cout << "\r\nЭлектричество\r\n\r\nКоличество кВт/час, использованных за месяц: ";
        cin >> Electro;
        if (Electro < 100)
        {
            Electro *= coefficient[1];
            sum(Electro);
        }
        else if (Electro >= 100)
        {
            Electro *= coefficient[2];
            sum(Electro);
        }
    }
    void Gas()
    {
        cout << "\r\nГаз\r\n\r\nКоличество кубометров, использованных за месяц: ";
        cin >> Gaz;
        Gaz *= coefficient[3];
        sum(Gaz);
    }
    void ColdWater()
    {
        cout << "\r\nХолодная вода\r\n\r\nКоличество кубометров, использованных за месяц: ";
        cin >> HolVoda;
        HolVoda *= coefficient[4];
        sum(HolVoda);
    }
    void HotWater()
    {
        cout << "\r\nГорячая вода\r\n\r\nКоличество кубометров, использованных за месяц: ";
        cin >> GarVoda;
        GarVoda = GarVoda * coefficient[5];
        sum(GarVoda);
    }
    void Heating()
    {
        cout << "\r\nОтопление\r\n\r\nОбщая площадь квартиры: ";
        cin >> Otopl;
        Otopl *= coefficient[6];
        sum(Otopl);
    }
    void sum(float summa)
    {
        cout << "\nСумма к оплате - " << summa << " UAH.\n";
        /*if (tarcoef.KodValut == 100)
            cout << "\nСумма к оплате - " << summa << " RUB.\n";
        else if (tarcoef.KodValut == 101)
            cout << "\nСумма к оплате - " << summa << " UAH.\n";
        else if (tarcoef.KodValut == 102)
            cout << "\nСумма к оплате - " << summa << " BYN.\n";*/
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
};
class check
{
public:
    void outlet(payment pay)
    {
        bool ProverVybKoef = 0;
        do
        {
            cin >> VybKoef;
            switch (VybKoef)
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
                pay.Rent();
                break;
            case '2':
                ProverVybKoef = 0;
                pay.Electricity();
                break;
            case '3':
                ProverVybKoef = 0;
                pay.Gas();
                break;
            case '4':
                ProverVybKoef = 0;
                pay.ColdWater();
                break;
            case '5':
                ProverVybKoef = 0;
                pay.HotWater();
                break;
            case '6':
                ProverVybKoef = 0;
                pay.Heating();
                break;
            case '9':
                ProverVybKoef = 0;
                //!IzmenValut();
                exit(0);
                break;
            default:
                ProverVybKoef = 1;
                cout << "Задано неправильное значение. Повторите попытку: ";
                break;
            }
        } while (ProverVybKoef == 1);
    }
    void ending()
    {
        bool VyhodIzProg = 0;
        do
        {
            cout << "Будете продолжать расчёты (1/0) ?\r\n";
            cin >> Vyh;
            switch (Vyh)
            {
            case '1':
                VyhodIzProg = 0;
                break;
            case '0':
                cout << "\n\nПриложение закрывается. ";
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
    char VybKoef, Vyh;
};
/*
void IzmenValut()
{
    cout << "---";
}

void Admin()
{
    cout << "---";
}
*/
int main()
{
    entry intro;
    payment pay;
    check provka;
    intro.instruction();
    intro.rate();
    FILE *coef;
    coef = fopen("Options.txt", "r");
    fscanf(coef, "%f %f %f %f %f %f %f %i", &pay.coefficient[0], &pay.coefficient[1], &pay.coefficient[2], &pay.coefficient[3], &pay.coefficient[4], &pay.coefficient[5], &pay.coefficient[6], &pay.KodValut);
    provka.outlet(pay);
    return 0;
}
