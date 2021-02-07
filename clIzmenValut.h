#ifndef clIzmenValut
#define clIzmenValut
#include <iostream>
using namespace std;

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

#endif