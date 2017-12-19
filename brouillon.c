void afficher_murs(SLIDER S) {

	POINT p1;
	int i;
		
		for(i=0;i<S.N;i++){
			
		S.p.x = S.Mur[i][0];
		S.p.y = S.Mur[i][1];
		
			if(S.Mur[i][2]==0){
			
				p1.x=S.p.x;
				p1.y=S.p.y+50;
				draw_line(S.p,p1,bleu);
			
		}
	}		
}





aff_pol("Score :",50,p,rouge);








void afficher_murs(SLIDER S) {

	POINT p1;
		
		S.p.x = S.Mur[0][0];
		S.p.y = S.Mur[0][1];
		
		if(S.Mur[0][2]==0){
			
			p1.x=S.p.x;
			p1.y=S.p.y+50;
			draw_line(S.p,p1,bleu);
			
		}
	}	
	
	
	
	
void ArretBalle(SLIDER S){
	
	for(i=0;i<S.N;i++){
		
		if(((S.Mur[i][0]==S.p.x+25)&&(S.Mur[i][1]==S.p.y-25)&&(S.Mur[i][2]==0))||(S.Mur[i][1]==S.p.y+25)&&(S.Mur[i][2]==6)){
			
			RechargerEcran(S);
	
}}}




















void deplace_balle(SLIDER S){
	
	printf(" entree dans deplace balle \n");
	int reception = 0;
	char touche = {0};
	int fleche=0;
	POINT clic;
	int i;
	
	clic.x = 0;	clic.y = 0;	
	
	while( (S.p.x>=25) && (S.p.x<=475) && (S.p.y>=25) && (S.p.y<=475) ){
		
	printf(" entree dans while 1 \n");
	
	reception = wait_key_arrow_clic(&touche,&fleche,&clic);
	
	if(reception == 1){
		
		//for(i=0;i<S.N;i++){
			
		if(fleche == FLECHE_DROITE){
			
			printf(" Fleche droite \n");
			
			if((S.p.x<=475)&&(ArretBalle(S)==0)){//&&(((S.Mur[i][0]!=S.p.x+25)&&(S.Mur[i][1]!=S.p.y-25)&&(S.Mur[i][2]!=0))||((S.Mur[i][1]!=S.p.y+25)&&(S.Mur[i][2]!=6)))){
			
			S.p.x = S.p.x + 50;
			RechargerEcran(S);
			
			}
		}
	
		else if(fleche == FLECHE_GAUCHE){
				
				printf(" Fleche gauche \n");
				
				if(S.p.x>=25){
				
				S.p.x = S.p.x - 50;
				RechargerEcran(S);
				
			}
		}
		else if(fleche == FLECHE_HAUT){
				
				printf(" Fleche haut \n");
				
				if((S.p.y<=475)&&(S.p.y>=375)){
				
				S.p.y = S.p.y + 50;
				RechargerEcran(S);
			}
		}
			
		else if(fleche == FLECHE_BAS){
				printf(" Fleche bas \n");
				
				if(S.p.y>=25){
				
				S.p.y = S.p.y - 50;
				RechargerEcran(S);
				
			}
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
	
	
	
	
	
	
	

