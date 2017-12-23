#include "mes_types.h"
#include "deplacement.h"

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
			
			S.mur.x = S.Mur[i][0];
			S.mur.y = S.Mur[i][1];
		
			if(S.Mur[i][2]==0){
			
				p1.x=S.mur.x+3;
				p1.y=S.mur.y+50;
				draw_fill_rectangle(S.mur,p1,bleu);
			}
				
			if(S.Mur[i][2]==3){
			
				p1.x=S.mur.x+50;
				p1.y=S.mur.y+3;
				draw_fill_rectangle(S.mur,p1,bleu);
			}
				
			if(S.Mur[i][2]==6){
			
				p1.x=S.mur.x+3;
				p1.y=S.mur.y-50;
				draw_fill_rectangle(S.mur,p1,bleu);
			}
				
			if(S.Mur[i][2]==9){
			
				p1.x=S.mur.x-50;
				p1.y=S.mur.y+3;
				draw_fill_rectangle(S.mur,p1,bleu);

		}
	}		
}	

void afficher_le_slider(SLIDER S) {
	
		draw_fill_circle(S.p,25,bleu);
		deplace_balle(S);
}

void afficher_sortie(SLIDER S) {
	
	POINT p1;
	
	p1.x = S.sortie.x + 50;
	p1.y = S.sortie.y - 50;
	draw_fill_rectangle(S.sortie,p1,rouge);

}

void Affichage(SLIDER S){
	
	initialiser_affichage(S);
	afficher_grille(S);
	afficher_murs(S);
	afficher_sortie(S);
	afficher_le_slider(S);
	
}

void RechargerEcran(SLIDER S){
	
			fill_screen(noir);
			initialiser_affichage(S);
			afficher_grille(S);
			afficher_murs(S);
			afficher_sortie(S);
			draw_fill_circle(S.p,25,bleu);
			
		}
		
void TerminerPartie(SLIDER S){
	
			POINT centre;
			centre.x = 250;
			centre.y = 250;
			fill_screen(noir);
			aff_pol_centre(" Partie Terminee ", 20, centre, rouge);
			wait_escape();
			
			
		}
		
void ArretBalleMurDroit(SLIDER S){
	
	int i;
	
	for(i=0;i<S.N;i++){
		
		if(((S.p.x + 25) == (S.Mur[i][0])) && ((S.p.y - 25) == (S.Mur[i][1])) && ((S.Mur[i][2]) == 0 )){
			
			printf("Il y a un mur a droite");
			deplace_balle(S);
			
			}
			
			else if(((S.p.x+25) == (S.Mur[i][0])) && ((S.p.y+25) == (S.Mur[i][1])) && ((S.Mur[i][2])==6)){	
				
				printf("Il y a un mur a droite");
				deplace_balle(S);
		}
	}
}

void ArretBalleMurGauche(SLIDER S){
	
	int i;
	
	for(i=0;i<S.N;i++){
		
		if(((S.p.x - 25) == (S.Mur[i][0])) && ((S.p.y - 25) == (S.Mur[i][1])) && ((S.Mur[i][2]) == 0 )){
			
			printf("Il y a un mur a gauche");
			deplace_balle(S);
			
			}
			
			else if(((S.p.x-25) == (S.Mur[i][0])) && ((S.p.y+25) == (S.Mur[i][1])) && ((S.Mur[i][2])==6)){	
				
				printf("Il y a un mur a gauche");
				deplace_balle(S);
		}
	}
}


void ArretBalleMurBas(SLIDER S){
	
	int i;
	
	for(i=0;i<S.N;i++){
		
		if(((S.p.x - 25) == (S.Mur[i][0])) && ((S.p.y - 25) == (S.Mur[i][1])) && ((S.Mur[i][2]) == 3 )){
			
			printf("Il y a un mur en bas");
			deplace_balle(S);
			
			}
			
			else if(((S.p.x+25) == (S.Mur[i][0])) && ((S.p.y-25) == (S.Mur[i][1])) && ((S.Mur[i][2])==9)){	
				
				printf("Il y a un mur en bas");
				deplace_balle(S);
		}
	}
}


void ArretBalleMurHaut(SLIDER S){
	
	int i;
	
	for(i=0;i<S.N;i++){
		
		if(((S.p.x - 25) == (S.Mur[i][0])) && ((S.p.y + 25) == (S.Mur[i][1])) && ((S.Mur[i][2]) == 3 )){
			
			printf("Il y a un mur en haut");
			deplace_balle(S);
			
			}
			
			else if(((S.p.x+25) == (S.Mur[i][0])) && ((S.p.y+25) == (S.Mur[i][1])) && ((S.Mur[i][2])==9)){	
				
				printf("Il y a un mur en haut");
				deplace_balle(S);
		}
	}
}


void Arrive(SLIDER S){
	
	if((S.p.x==S.sortie.x+25)&&(S.p.y==S.sortie.y-25)){
			
			printf("Bien Joué !");
			TerminerPartie(S);
			exit(0);
			
		}

}

void finir_affichage(SLIDER S) {
	wait_escape();
}
