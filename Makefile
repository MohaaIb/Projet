NOM=PROJET_IN301

niveau1: clean slider
	./slider niveau_01.slider
	
niveau2: clean slider
	./slider niveau_02.slider
	
niveau3: clean slider
	./slider niveau_03.slider
	

# Edition de liens
slider: slider.o lire_ecrire.o afficher.o deplacement.o
	gcc slider.o lire_ecrire.o afficher.o deplacement.o -o slider -luvsqgraphics `sdl-config --libs` -lm -lSDL_ttf

# Compilation
slider.o: slider.c mes_types.h
	gcc -c -Wall `sdl-config --cflags` slider.c

# Compilation
lire_ecrire.o: lire_ecrire.c mes_types.h
	gcc -c -Wall `sdl-config --cflags` lire_ecrire.c

# Compilation
afficher.o: afficher.c mes_types.h
#	gcc -c -Wall   -I/usr/include/SDL -D_GNU_SOURCE=1 -D_REENTRANT  afficher.c
	gcc -c -Wall `sdl-config --cflags` afficher.c

# Compilation
deplacement.o: deplacement.c mes_types.h
#	gcc -c -Wall   -I/usr/include/SDL -D_GNU_SOURCE=1 -D_REENTRANT  afficher.c
	gcc -c -Wall `sdl-config --cflags` deplacement.c


editeur:
	geany Makefile mes_types.h slider.c afficher.c afficher.h &

# Pour creer le zip a deposer sur e-campus
zip:
	rm -fr $(NOM)
	rm -f $(NOM).zip
	mkdir $(NOM)
	cp *.c $(NOM)
	cp *.h $(NOM)
	cp Makefile $(NOM)
#	cp -f *.slider $(NOM)
	zip $(NOM).zip $(NOM)/*
#	rm -fr $(NOM)



clean:
	rm -rf $(NOM)
	rm -f $(NOM).zip
	rm -f lire_ecrire.o
	rm -f afficher.o
	rm -f slider.o
	rm -f slider
