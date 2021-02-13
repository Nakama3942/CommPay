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

clean:
	@rm CommPay *.o

CommPay: libCoPa.so CommPay.o
	@ln -s $(LIBRARY) $(LINK)
	@$(CC) -no-pie -o CommPay CommPay.o -lCoPa -Wl,-rpath,.
	@cp Value.txt $(CONF)

libCoPa.so: $(SOURCE)
	@$(CC) $(CFLAGS) -fPIC $(SOURCE)
	@$(CC) -shared -o $(LIBRARY) -Wl,-soname,libCoPa.so.0.1 *.o

CommPay.o: CommPay.cpp
	@$(CC) $(CFLAGS) CommPay.cpp

install:
	@install ./CommPay /usr/local/bin

uninstall:
	@rm -rf $(CONF) $(LIBRARY) $(LINK) $(EXECUTIVE)