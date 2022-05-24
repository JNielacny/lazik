APP=sterowanie-lazikiem


__start__: obj dat  pliki_do_rysowania ./${APP}
	rm -f core.* core; ./${APP}

# Tworzy katalog "obj" gdy go nie ma
# 
obj:
	mkdir obj

dat:
	mkdir dat

pliki_do_rysowania:
	mkdir pliki_do_rysowania


./${APP}: obj/main.o obj/lacze_do_gnuplota.o obj/PowierzchniaMarsa.o obj/ObiektGeom.o
	g++ -o ./${APP} obj/main.o obj/lacze_do_gnuplota.o obj/PowierzchniaMarsa.o\
                        obj/ObiektGeom.o


obj/main.o: src/main.cpp inc/lacze_do_gnuplota.hh inc/ObiektGeom.hh inc/PowierzchniaMarsa.hh\
            inc/Kolory.hh
	g++  -Iinc -W -Wall -pedantic -c -o obj/main.o src/main.cpp

obj/lacze_do_gnuplota.o: src/lacze_do_gnuplota.cpp inc/lacze_do_gnuplota.hh
	g++  -Iinc -W -Wall -pedantic -c -o obj/lacze_do_gnuplota.o src/lacze_do_gnuplota.cpp

obj/PowierzchniaMarsa.o: src/PowierzchniaMarsa.cpp inc/PowierzchniaMarsa.hh inc/lacze_do_gnuplota.hh
	g++  -Iinc -W -Wall -pedantic -c -o obj/PowierzchniaMarsa.o src/PowierzchniaMarsa.cpp

obj/ObiektGeom.o: src/ObiektGeom.cpp inc/ObiektGeom.hh inc/lacze_do_gnuplota.hh
	g++  -Iinc -W -Wall -pedantic -c -o obj/ObiektGeom.o src/ObiektGeom.cpp


clean:
	rm -f obj/* ./${APP} core.* core liki_do_rysowania/*



help:
	@echo
	@echo " make        - tworzenie i uruchomienie aplikacji"
	@echo " make clean  - usuniecie produktow kompilacji i konsolidacji"
	@echo " make help   - wyswietla niniejsza informacje"
	@echo
