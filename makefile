#
#   CommPay
#

CC=g++
CFLAGS=-Wall -c
SOURCE=Administration.cpp CalculationFormulas.cpp checks.cpp communication.cpp
EXECUTIVE=/usr/local/bin/CommPay
LIBRARY=/usr/local/lib/libCoPa.so.0.1
LINK=/usr/local/lib/libCoPa.so
CONF=/usr/local/share/Options.conf

.PHONY: all clean install uninstall

all: CommPay

CommPay: libCoPa.so CommPay.o
	@ln -s $(LIBRARY) $(LINK)
	@$(CC) -no-pie -o CommPay CommPay.o -lCoPa -Wl,-rpath,.
	@echo Программа скомпилирована!
	@cp Value.txt $(CONF)
	@echo Настроены предустановки!

libCoPa.so: $(SOURCE)
	@$(CC) $(CFLAGS) -fPIC $(SOURCE)
	@$(CC) -shared -o $(LIBRARY) -Wl,-soname,libCoPa.so.0.1 *.o
	@echo Собрана библиотека CoPa.so!

CommPay.o: CommPay.cpp
	@$(CC) $(CFLAGS) CommPay.cpp
	@echo Собран исполняемый файл программы!

install:
	@install ./CommPay /usr/local/bin
	@echo Программа установлена!

clean:
	@rm CommPay *.o
	@echo Посредники очищены!

uninstall:
	@rm -rf $(CONF) $(LIBRARY) $(LINK) $(EXECUTIVE)
	@echo программа удалена!