# CommPay
## Описание
CommPay (полн. "Communal Payment", рус. - "Коммунальный платёж") - программа, которая, исходя из названия, будет считать Вам сумму к оплате коммунальных платежей. Эта программа учитывает все коэфициенты, которые высчитываются коммунальными службами. Если нужно - Вы всегда сможете изменить, как тариф (если он изменился), так и сам коэфициент (если он в Вашем регионе отличается). [_Пока реализованы только тарифы как коэффициенты, но скоро я доработаю эту функцию._]
## Для кого нужна эта программa?
Для тех, кто не доверяет своим коммунальным службам и хочет сам убетиться - платит он положенную сумму или нет.
## Как собрать программу?
Отмечу главное: программа, её библиотеку и необходимые файлы у станавливаются в директорию пользовательских программ по адрессу /usr/locale (у автора, кстати, она была поделена не необходимые поддиректории, которые были пусты), и если человек устанавливает эту программу, как написанную самостоятельно (что, впринципе, так и есть), то сначала нужно открыть постоянный доступ к этой директории, для чего нужно прописать команду:
> user@user:~/Downloads/CommPay$ chown user:user /usr/locale

Так как изначально эта директория принадлежит пользователю root, нужно эту команду прописывать под рутом. Остался один шаг: директория, куда устанавливаются библиотеки, должна быть установлена в LD_LIBRARY_PATH. Советую проверить. Для этого введите команду:
> user@user:~/Downloads/CommPay$ echo $LD_LIBRARY_PATH

Если там нет директории /usr/locale/lib, тогда добавьте её командой:
> user@user:~/Downloads/CommPay$ LD_LIBRARY_PATH=/usr/locale/lib

Теперь после установки программа не будет ругаться на отсутствие библиотек. Теперь можно присутпать к установке. Для этого в проект добавлен makefile, в котором всё уже готово. Достаточно прописать команды в следующем порядке:
> user@user:~/Downloads/CommPay$ make

> user@user:~/Downloads/CommPay$ make install

> user@user:~/Downloads/CommPay$ make clean

Первой командой Вы собираете программу, второй устанавливаете, третьей очищаете свой диск от посредних файлов, которые нужны только на момент сборки.
## Как удалить программу?
После установки программы Вы можете удалить и исходники, однако в makefile прописаны все файлы, которые используются для работы программы, поэтому его удалять не рекомендуется. Поэтому Вы можете где-нибудь сохранить этот файл и когда нужно будет удалить эту программу просто вернуться в директорию этого файла и прописать команду:
> user@user:~/Downloads/CommPay$ make uninstall

После этого можно и этот файл. Если у Вас есть хранилище для хранения makefiles разных программ, то достаточно будет просто найти нужный: если у Вас makefiles переименованы, то просто запустить в терминале команду make для нужного файла; а если нет, то в самом файле прописано, к какой программе он принадлежит и нужно запустить его из той директории, где он находится.
## Немного документации по библиотекам
Для этого проекта я написал несколько своих библиотек. Однако, их можно использовать и в других проектах. Давайте рассмотрим библиотеки:
### Adminictration.cpp
#### Подключение
Исходник библиотеки администрирования, которая контролирует изменения тарифов и валюты. Для её использования необходимо её сначала объявить. Чтобы не морочить голову, лучше вместе с библиотекой испольвать готовый хидер и в основном коде программы просто подключить хидер _"classes.h"_. После просто компилируем библиотеку в объектный файл (_*.o_) и на моменте компиляции программы указываем этот объектный файл вместе с основмным кодом.
#### Классы
Вы будете испольовать эту библиотеку, только если будете использовать мой файл хранения информации. Сначала Вы объявляете _объект_ класса *Admin*, после чего можете использовать следующие методы: 1)_объект_.greating(1) - выводится инфо о начале администрирования; 2)_объект_.greating(0) - аналогично первому о конце; 3)_объект_.ChangeRate(_файл_) - передача файла на редактирование тарифов; 4)_объект_.ChangeCurrency(_файл_) - передача файла на редактирование валюты пользователя.
### CalculationFormulas.cpp
#### Подключение
Исходник библиотеки, которая принимает пользовательскую информацию и по формулам считает и выводит ответ. Подключение аналогично первой библиотеки.
#### Классы
Для этой бибиотеки уже не обязательны другие файла: можно организовать всю работу по своему, а этой библиотеке передавать просто необходимую информацию. Сначала Вы объявляете _объект_ класса *payment*, после чего можете использовать следующие методы: 1)_объект_.Rent(_Тариф_, _КодВалюты_) - считает квартплату; 2)_объект_.Electricity(_Тариф_, _КодВалюты_) - считает плату за электричество; 3)_объект_.Gas(_Тариф_, _КодВалюты_) - считает плату за газ; 4)_объект_.ColdWater(_Тариф_, _КодВалюты_) - считает плату за холодную воду; 1)_объект_.HotWater(_Тариф_, _КодВалюты_) - считает плату за гарячую воду; 1)_объект_.Heating(_Тариф_, _КодВалюты_) - считает плату за отопление. Как видно, туда можно просто указать свои значения (предварительно дописав своих валют в библиотеку) типа "_plt.Electricity(16.39, 160)_" и т.д.
### checks.cpp
#### Описание
Исходник библиотеки, которая контролирует пользовательский выбор и поток информации из памяти в управляющие методы и обратно для вывода пользователю.
#### Подключение
Эта библиотека расчитана только на использование в моём проекте.
### communication.cpp
#### Подключение
Библиотека для общения с пользователем. Можно использовать почти в любом проекте. Подключение аналогично первой библиотеке.
#### Классы
Первые два метода расчитаны на использование только в этом проекте, однако последний пожно использовать в любом. Этот метод не принимает никаких значений и вызывается так: _объект_.ending(). Этот метод спрашивает у пользователя, хочет ли он выйти из программы, и если пользователь отвечает *1* - программа повторяется, *0* - программа завершается, на любой другой символ метод будет бесконечно повторятся, пока пользовательне введёт *1* или *0*.
***
## Послесловие
Эта программа написана на основе моего старого (_и, кстати, самого первого_) проекта. Он был написан на языке С, в нём было всего четыре функции, был написан в одном файле, функция изменения валют не работала (_как выяснилось во время переписи программы, там просто не было указано формат записи в файл, поэтому запись не происходила_). Потом я забросил этот проект до лучших времён, но недавно я опять взялся за него: переписал на С++, разбил на кучу классов, которые разнесены по разным библиотекам и все ошибки исправлены. В общем я применил все свои новые знания и технолгии в этом проекте и хочу его дальше развивать вместе с увеличениме моих опыта и знаний.