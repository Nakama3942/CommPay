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
    void proc(FILE *RedactCoef, int step)
    {
        revision[1] = 0;
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
    //Первое значение - Выбор изменения коэффициента
    //Второе - Выбор диапазона (для электричества)
    int choise[2] = {};
    //Первое значение - Выход из Администрирования
    //Второе - Проверка выбора изменения коэффициента
    //Третье - Проверка выхода из кейса
    //Четвёртое - Проверка выбора диапазона
    bool revision[4] = {0, 0, 0, 0};
    char AdminWork;
    float ZamenZnach;
};

#endif