
#include "mes_types.h"


int main (int argc, char*argv[]) {
	printf("Debut slider\n");

	SLIDER S;
	S = lire_fichier(argv[1]);
	
	Affichage(S);

	printf("Fin slider\n");
	
	finir_affichage(S);
	exit(0);
}
