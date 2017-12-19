#include <stdio.h>
#include "mes_types.h"


SLIDER lire_fichier(char *nom) {

	printf("nom = %s\n",nom);
	SLIDER S;
	int i;
	
	
	FILE *F = fopen(nom,"r");
	fscanf(F,"%d%d",&S.L,&S.H); // Hauteur et Largeur
	fscanf(F,"%d%d",&S.p.x,&S.p.y); // Position Balle
	fscanf(F,"%d%d",&S.p1.x,&S.p1.y); // Position Sortie
	
	fscanf(F,"%d",&S.N);
	for(i=0;i<S.N;i++){
	fscanf(F,"%d%d%d",&S.Mur[i][0],&S.Mur[i][1],&S.Mur[i][2]); // Position Murs
	}
	return S;
}


void ecrire_fichier(SLIDER S, char*nom) {
}
