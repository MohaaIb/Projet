#include "mes_types.h"
//~ #include "graphics.h"
//~ #include <uvsqgraphics.h>


void initialiser_affichage(SLIDER S) {
	init_graphics (50*S.L,50*S.H);
}

void afficher_grille(SLIDER S) {
	
	POINT p1,p2;
	
	p1.x = 0; p1.y = 0;
	p2.x = 0; p2.y = 50*S.H;
	
	while(p1.x<=50*S.L && p2.x<=50*S.L){
		
		draw_line(p1,p2,vert);
		p1.x = p1.x + 50;
		p2.x = p2.x + 50;
		
	}
	
	p1.x = 0; p1.y = 0;
	p2.x = 50*S.L; p2.y = 0;
	
		while(p1.y<=50*S.H && p2.y<=50*S.H){
		
		draw_line(p1,p2,vert);
		p1.y = p1.y + 50;
		p2.y = p2.y + 50;
		
	}

}

void afficher_murs(SLIDER S) {

	POINT p1;
	int i;
		
		for(i=0;i<S.N;i++){
			
			S.p.x = S.Mur[i][0];
			S.p.y = S.Mur[i][1];
		
			if(S.Mur[i][2]==0){
			
				p1.x=S.p.x+3;
				p1.y=S.p.y+50;
				draw_fill_rectangle(S.p,p1,bleu);
			}
				
			if(S.Mur[i][2]==3){
			
				p1.x=S.p.x+50;
				p1.y=S.p.y+3;
				draw_fill_rectangle(S.p,p1,bleu);
			}
				
			if(S.Mur[i][2]==6){
			
				p1.x=S.p.x+3;
				p1.y=S.p.y-50;
				draw_fill_rectangle(S.p,p1,bleu);
			}
				
			if(S.Mur[i][2]==9){
			
				p1.x=S.p.x-50;
				p1.y=S.p.y+3;
				draw_fill_rectangle(S.p,p1,bleu);

		}
	}		
}	

void afficher_le_slider(SLIDER S) {
	
	draw_fill_circle(S.p,25,bleu);
		deplace_balle(S);

	
}

void afficher_sortie(SLIDER S) {
	
	POINT p1;
	
	p1.x = 500;
	p1.y = 0;
	draw_fill_rectangle(S.p1,p1,rouge);

}

void RechargerEcran(SLIDER S){
	
			fill_screen(noir);
			initialiser_affichage(S);
			afficher_grille(S);
			afficher_murs(S);
			afficher_sortie(S);
			draw_fill_circle(S.p,25,bleu);
			
		}
		
/*int ArretBalle(SLIDER S){
	
	int i;
	int arret=1;
	
	for(i=0;i<S.N;i++){
		
		while(arret==1){
			
		if(((S.p.x+25==S.Mur[i][0])&&(S.p.y-25))==((S.Mur[i][1])&&(S.Mur[i][2]==0))||((S.p.x+25==S.Mur[i][0])&&((S.p.y+25)==(S.Mur[i][1]))&&(S.Mur[i][2]==6))){
			
			arret = 0;
			return arret;
			printf("Il y a un mur a droite");
			}	
		}
	}
}*/

/*int Arrive(SLIDER S){
	
	int arrive = 0;
		
	if((S.p.x==S.p1.x)&&(S.p.y==S.p1.y)){
		
		printf("ARRIVE !");
		arrive = 1;
		return arrive;
		}	
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
	
	if(reception == 1){
		
		//if(Arrive(S)==0){
		if((S.p.x!=475)&&(S.p.y!=25)){
		
		printf(" Entré dans le if \n");
				
			if(fleche == FLECHE_DROITE){
				
				printf(" Fleche droite \n");
				
				if(S.p.x<475){
						
					//if(ArretBalle(S)==0){
					
					S.p.x = S.p.x + 50;
					RechargerEcran(S);
					
					}
				}
	
		else if(fleche == FLECHE_GAUCHE){
				
				printf(" Fleche gauche \n");
				
				if(S.p.x>25){
				
					S.p.x = S.p.x - 50;
					RechargerEcran(S);
				
				}
			}
		else if(fleche == FLECHE_HAUT){
				
				printf(" Fleche haut \n");
				
				if(S.p.y<475){
				
					S.p.y = S.p.y + 50;
					RechargerEcran(S);
				}
			}
			
		else if(fleche == FLECHE_BAS){
				printf(" Fleche bas \n");
				
				if(S.p.y>25){
				
					S.p.y = S.p.y - 50;
					RechargerEcran(S);
				
				}
			}
		}
		
		else{
			
			printf("Arrivé !");
			//RechargerEcran(S);
		}
	}

		else if (reception == 2) {
			
			
			printf(" Touche \n");
		}
			else if (reception == 3) {
				
				printf(" Clic \n");
			}
		
				else 
				
				{
					
				printf(" Aucunne touche \n");	
					
						}
	
				}
		}
	

void finir_affichage(SLIDER S) {
	wait_escape();
}
