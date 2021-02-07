#ifndef clAdmin
#define clAdmin
#include <iostream>
using namespace std;

class Admin
{
public:
    void method(FILE *RedactCoef)
    {
        do
        {
            do
            {
                cout << "\nВыберите, какой коэффициент исправить: \n";
                cin >> VyborIzmenKoef;
                switch (VyborIzmenKoef)
                {
                case 1:
                    proc(RedactCoef, 0);
                    ext();
                    break;
                case 2:
                    cout << "\nУкажите - изменение коэффициента какого диапазоне будет происходить: до 100 (укажите 99) или больше (укажите 999): ";
                    do
                    {
                        cin >> VyborDiapazon;
                        switch (VyborDiapazon)
                        {
                        case 99:
                            ProverVyborDiapazon = 0;
                            proc(RedactCoef, 6);
                            ext();
                            break;
                        case 999:
                            ProverVyborDiapazon = 0;
                            proc(RedactCoef, 12);
                            ext();
                            break;
                        default:
                            ProverVyborDiapazon = 1;
                            cout << "\r\nОшибка в ответе. Повторите попытку: ";
                            break;
                        }
                    } while (ProverVyborDiapazon == 1);
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
                    ProverVyborIzmenKoef = 1;
                    cout << "\r\nОшибка в ответе. Повторите попытку.";
                    break;
                }
            } while (ProverVyborIzmenKoef == 1);
        } while (VyhodIzAdmin == 1);
    }
    void proc(FILE *RedactCoef, int step)
    {
        ProverVyborIzmenKoef = 0;
        cout << "\nУкажите новый коэффициент: ";
        cin >> ZamenZnach;
        fseek(RedactCoef, step, SEEK_SET);        //Сносит курсор на первый символ в файле
        fprintf(RedactCoef, "%5.2f", ZamenZnach); //Записывает считанное значение в файл на указанную позицию
    }
    void ext()
    {
        cout << "Значение изменено! Хотите продолжить редактирование?";
        do
        {
            cin >> AdminWork;
            switch (AdminWork)
            {
            case '1':
                ProverVyhodIzCase1 = 0;
                VyhodIzAdmin = 1;
                break;
            case '0':
                ProverVyhodIzCase1 = 0;
                VyhodIzAdmin = 0;
                break;
            default:
                ProverVyhodIzCase1 = 1;
                cout << "\r\nОшибка в ответе. Повторите попытку: ";
                break;
            }
        } while (ProverVyhodIzCase1 == 1);
    }
    void greeting(int mode)
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

private:
    int VyborIzmenKoef, VyborDiapazon;
    float ZamenZnach;
    bool VyhodIzAdmin = 0, ProverVyborIzmenKoef = 0, ProverVyhodIzCase1 = 0, ProverVyborDiapazon = 0;
    char AdminWork;
};

#endif