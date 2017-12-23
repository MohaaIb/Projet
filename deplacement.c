#include "mes_types.h"

/*void lancerPartie (...) {
	

		affichge
		deplacement
		exit 0

}*/

void deplace_balle(SLIDER S){
	
	printf(" entree dans deplace balle \n");
	int reception = 0;
	char touche = {0};
	int fleche=0;
	POINT clic;
	int i;
	
	clic.x = 0;	clic.y = 0;	
	
	while( (S.p.x>=25) && (S.p.x<=475) && (S.p.y>=25) && (S.p.y<=475) ) {
		
		printf(" entree dans while \n");
		
		reception = wait_key_arrow_clic(&touche,&fleche,&clic);
			
		Arrive(S);
	
		if(reception == 1){
				
			if(fleche == FLECHE_DROITE){
				
				for(i=0;i<10;i++){
					
				ArretBalleMurDroit(S);
				printf(" Fleche droite \n");	
					
				if(S.p.x + 50 == S.sortie.x+25){
				
					S.p.x = S.p.x + 50;
					RechargerEcran(S);
					Arrive(S);
		
				}
				
				else if(S.p.x<475){
					
					S.p.x = S.p.x + 50;
					RechargerEcran(S);
					
					}
				}
			}
	
		else if(fleche == FLECHE_GAUCHE){
				
				for(i=0;i<10;i++){
					
				ArretBalleMurGauche(S);
				printf(" Fleche gauche \n");
				
				if(S.p.x>25){
				
					S.p.x = S.p.x - 50;
					RechargerEcran(S);
				
				}
			}
		}
		else if(fleche == FLECHE_HAUT){
				
				for(i=0;i<10;i++){
					
				ArretBalleMurHaut(S);
				printf(" Fleche haut \n");
				
				if(S.p.y<475){
				
					S.p.y = S.p.y + 50;
					RechargerEcran(S);
				}
			}
		}
			
		else if(fleche == FLECHE_BAS){
				
				for(i=0;i<10;i++){
					
				ArretBalleMurBas(S);
				printf(" Fleche bas \n");
				
				if(S.p.y - 50 == S.sortie.y-25){
				
					S.p.y = S.p.y - 50;
					RechargerEcran(S);
					Arrive(S);
		
				}
				else if(S.p.y>25){
					
					S.p.y = S.p.y -50;
					RechargerEcran(S);
					
					}
				}
			}
		}
	

		else if (reception == 2) {
			
			
			if (touche == 'Q')
				exit(0);
				
			
		}
			else if (reception == 3) {
				
				printf(" Clic \n");
			}
		
				else 
				
				{
					
				printf(" Aucune touche \n");	
					
						}
	
				}
		}
