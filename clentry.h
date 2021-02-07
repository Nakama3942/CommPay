#ifndef clentry
#define clentry
#include <iostream>
using namespace std;

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

#endif