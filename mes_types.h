#include <uvsqgraphics.h>
#define TAILLE_CASE 50
#ifndef _MES_TYPESH

struct slider {
	int L,H; // Largeur et hauteur de la grille
	POINT p; // La balle et origine du mur
	POINT p1; // La sortie 
	int N; // Nombre de Mur
	int Mur[300][3]; // Tableau 
	
};

typedef struct slider SLIDER;

#endif
	

