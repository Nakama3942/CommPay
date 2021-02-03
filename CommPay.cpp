#include <iostream>
using namespace std;

class payment
{
public:
    void Rent()
    {
        cout << "\r\nКвартплата\r\n\r\nПлощадь квартиры: ";
        cin >> KvartPlat;
        cout << "\r\nКоличество проживающих: ";
        cin >> Zhylci;
        //?float PlatKvart = Zhylci * KvartPlat * g_KoefKvartPlat;
        //?cout << "\r\nСумма к оплате - " << PlatKvart << "UAH. \r\n";
        /*if (g_KodValut == 100)
        {
            printf("\r\nСумма к оплате - %f RUB. \r\n", PlatKvart);
        }
        else if (g_KodValut == 101)
        {
            printf("\r\nСумма к оплате - %f UAH. \r\n", PlatKvart);
        }
        else if (g_KodValut == 102)
        {
            printf("\r\nСумма к оплате - %f BYN. \r\n", PlatKvart);
        }*/
    }
    void Electricity()
    {
        cout << "---";
    }
    void Gas()
    {
        cout << "---";
    }
    void HotWater()
    {
        cout << "---";
    }
    void ColdWater()
    {
        cout << "---";
    }
    void Heating()
    {
        cout << "---";
    }

private:
    int Zhylci;
    float KvartPlat, Electro, Gaz, GarVoda, HolVoda, Otopl;
};
class tariff
{
public:
    float coefficient[7] = {};
    /*float g_KoefKvartPlat;
    float g_KoefElectroMensh;
    float g_KoefElectroBolsh;
    float g_KoefGaz;
    float g_KoefGarVoda;
    float g_KoefHolVoda;
    float g_KoefOtopl;
    int g_KodValut;*/
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
        cout << "   4   Горячая вода   \r\n";
        cout << "   5   Холодная вода   \r\n";
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
    void outlet()
    {
        bool ProverVybKoef = 0;
        do
        {
            cin >> VybKoef;
            switch (VybKoef)
            {
            case 'a':
                ProverVybKoef = 0;
                Admin();
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
                //!catager(VybKoef);
                break;
            case '2':
                ProverVybKoef = 0;
                //!catager(VybKoef);
                break;
            case '3':
                ProverVybKoef = 0;
                //!catager(VybKoef);
                break;
            case '4':
                ProverVybKoef = 0;
                //!catager(VybKoef);
                break;
            case '5':
                ProverVybKoef = 0;
                //!catager(VybKoef);
                break;
            case '6':
                ProverVybKoef = 0;
                //!catager(VybKoef);
                break;
            case '9':
                ProverVybKoef = 0;
                IzmenValut();
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
void catager()
{
    cout << "---";
}
*/
void IzmenValut()
{
    cout << "---";
}

void Admin()
{
    cout << "---";
}

int main()
{
    entry intro;
    intro.instruction();
    intro.rate();
    return 0;
}
