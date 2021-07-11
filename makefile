# ########################################################################## #
# -------------------------------------------------------------------------- #
#                                                                            #
# Copyright © 2021 Kalynovsky Valentin. All rights reserved.                 #
# Licensed under the Apache License, Version 2.0                             #
#                                                                            #
# Licensed under the Apache License, Version 2.0 (the "License");            #
# you may not use this file except in compliance with the License.           #
# You may obtain a copy of the License at                                    #
#                                                                            #
#     http://www.apache.org/licenses/LICENSE-2.0                             #
#                                                                            #
# Unless required by applicable law or agreed to in writing, software        #
# distributed under the License is distributed on an "AS IS" BASIS,          #
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.   #
# See the License for the specific language governing permissions and        #
# limitations under the License.                                             #
#                                                                            #
# -------------------------------------------------------------------------- #
# ########################################################################## #

#
#   CommPay
#

CC=g++
FLAGS=-Wall -c
EXECUTIVE=/usr/local/bin/CommPay

LIBRARYMEMORY=/usr/local/lib/libMemory.so.0.1
LIBRARYENTRY=/usr/local/lib/libEntry.so.0.2
LIBRARYADMIN=/usr/local/lib/libAdmin.so.0.2
LIBRARYCALC=/usr/local/lib/libCalc.so.0.2
LIBRARYCHECK=/usr/local/lib/libChecks.so.0.2

LINKMEMORY=/usr/local/lib/libMemory.so
LINKENTRY=/usr/local/lib/libEntry.so
LINKADMIN=/usr/local/lib/libAdmin.so
LINKCALC=/usr/local/lib/libCalc.so
LINKCHECK=/usr/local/lib/libChecks.so

CONF=/usr/local/share/Options.conf
ISO=/usr/local/share/Valuta.conf

.PHONY: all clean install uninstall

all: CommPay

CommPay: libWorkStorage.so libEntry.so libAdministration.so libCalculation.so libChecks.so CommPay.o
	@$(CC) -no-pie -o CommPay CommPay.o -L/usr/local/lib -lMemory -lEntry -lChecks -lAdmin -lCalc -Wl,-rpath,.
	@echo Программа скомпилирована!
	@cp Value.txt $(CONF)
	@cp ISO4217-modified.txt $(ISO)
	@echo Настроены предустановки!

libWorkStorage.so: WorkStorage.cpp
	@$(CC) $(FLAGS) -fPIC WorkStorage.cpp
	@$(CC) -shared -o $(LIBRARYMEMORY) -Wl,-soname,libMemory.so.0.1 WorkStorage.o
	@ln -s $(LIBRARYMEMORY) $(LINKMEMORY)
	@echo Собрана библиотека Memory.so!

libEntry.so: communication.cpp
	@$(CC) $(FLAGS) -fPIC communication.cpp
	@$(CC) -shared -o $(LIBRARYENTRY) -Wl,-soname,libEntry.so.0.2 communication.o
	@ln -s $(LIBRARYENTRY) $(LINKENTRY)
	@echo Собрана библиотека Entry.so!

libAdministration.so: Administration.cpp
	@$(CC) $(FLAGS) -fPIC Administration.cpp
	@$(CC) -shared -o $(LIBRARYADMIN) -Wl,-soname,libAdmin.so.0.2 Administration.o
	@ln -s $(LIBRARYADMIN) $(LINKADMIN)
	@echo Собрана библиотека Admin.so!

libCalculation.so: CalculationFormulas.cpp
	@$(CC) $(FLAGS) -fPIC CalculationFormulas.cpp
	@$(CC) -shared -o $(LIBRARYCALC) -Wl,-soname,libCalc.so.0.2 CalculationFormulas.o
	@ln -s $(LIBRARYCALC) $(LINKCALC)
	@echo Собрана библиотека Calc.so!

libChecks.so: checks.cpp
	@$(CC) $(FLAGS) -fPIC checks.cpp
	@$(CC) -shared -o $(LIBRARYCHECK) -Wl,-soname,libChecks.so.0.2 checks.o
	@ln -s $(LIBRARYCHECK) $(LINKCHECK)
	@echo Собрана библиотека Checks.so!

CommPay.o: CommPay.cpp
	@$(CC) $(CFLAGS) CommPay.cpp
	@echo Собран исполняемый файл программы!

install:
	@install ./CommPay /usr/local/bin
	@echo Программа установлена!

clean:
	@rm -rf CommPay *.o
	@echo Посредники очищены!

uninstall:
	@rm -rf $(EXECUTIVE) $(CONF) $(ISO)
	@rm -rf $(LIBRARYMEMORY) $(LIBRARYENTRY) $(LIBRARYADMIN) $(LIBRARYCALC) $(LIBRARYCHECK)
	@rm -rf $(LINKMEMORY) $(LINKENTRY) $(LINKADMIN) $(LINKCALC) $(LINKCHECK)
	@echo программа удалена!
