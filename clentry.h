#ifndef clentry
#define clentry
#include <iostream>
using namespace std;

class entry
{
public:
    void instruction()
    {
        cout << "\r\n\r\n_ИНСТРУКЦИЯ_\r\n\r\nДля выбора нажимайте соответствующие клавиши от 1 до 9.\nДля согласия нажмите 1, для отказа нажмите 0.\n\r\n\r\n";
    }
    void rate()
    {
        cout << "\r\n\r\nРасчёт комунальных платежей\r\n___________________________\r\n   1   Квартплата   \r\n   2   Электричество   \r\n   3   Газ   \r\n   4   Холодная вода   \r\n   5   Гарячая вода   \r\n   6   Отопление   \r\n___________________________\r\n   9   Изменить валюту   \r\n___________________________\r\nВыберите форму расчёта   \r\n___________________________\r\n";
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

#endif