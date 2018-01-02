
#ifndef __SLIDERH


struct slider {
	int L,H; // Largeur et hauteur de la grille
	POINT p; // La balle
	POINT mur; // Origine du mur
	//char * nomFichier; // nom du fichier à jouer
	POINT sortie; // La sortie 
	int N; // Nombre de Mur
	int Mur[900][3]; // Tableau[Nb de Mur][ 0=Position x; 1=Position y; 2=Direction Mur]
	
};

typedef struct slider SLIDER;

#endif
