#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main (){

	int monstres = 1;
	int groupe = 1;

	int pvDps = 100;
	int pvTank =150;
	int pvHeal = 80;
	
	int attDps = 10;
	int attTank = 5;
	int attHeal = 8;
	
	int pmDps = 10;
	int pmTank = 6;
	int pmHeal = 20;

	int cibleDps =0;
	int cibleTank =0;
	int cibleHeal =0;
	
	int pvMonstre1 = 100;
	int attMonstre1 = 30;
	int pmMonstre1 = 10;
	int cibleMonstre1 = 0;

	int pvMonstre2 = 100;
	int attMonstre2 = 30;
	int pmMonstre2 = 10;
	int cibleMonstre2 = 0;
	
	int decisionDps = 0;
	int decisionTank = 0;
	int decisionHeal = 0;
	int decisionSoin = 0;
	int decisionM1 = 0;
	int decisionM2 = 0;
	
	
	int poisonDps1 = 0;
	int poisonDps2 = 0;
	int antidote1 = 0;
	int antidote2 = 0;
	int provocation1 = 0;
	int provocation2 = 0;
	
	srand(time(NULL));

	while( groupe>0 || monstres>0) {
		
		// -------------------------------------- TOUR DU DPS --------------------------------------------------------
		printf ("C'est le tour du Dps\n");
		printf ("Attaquer (1)\n");
		printf ("Defendre (2)\n");
		printf ("Empoisonner (3)\n");
		
		scanf("%d",&decisionDps);

		printf ("qui veux tu cibler ?\n");
		printf ("Monstre 1 (1) ou Monstre 2 (2) ?");

		scanf("%d",&cibleDps);
		
		//	Si le dps fait le choix 3, il empoisonne sa cible
		if (decisionDps == 3 && pmDps>=3 && cibleDps == 1){
				printf("Vous avez empoisonne le monstre 1.\n");
				poisonDps1 ++;
				pmDps = pmDps -3;
		}	
		// Si le mana est insufisant il choisit entre 1 et 2 	
		else if(decisionDps == 3 && pmDps<3 && cibleDps == 1){
				printf ("Vous n'avez plus de mana\n");
				printf ("Attaquer (1)\n");
				printf ("Defendre (2)\n");
			
				scanf("%d",&decisionDps);
		
		}

		// Si le dps fait le choix 2, il se défend
		if (decisionDps == 2 && cibleDps == 1){
			printf("Vous decidez de vous defendre.\n");
			attMonstre1 = attMonstre1/2;
			
		}
		
		// Si le dps fait le choix 1, il attaque
		if(decisionDps == 1 && cibleDps == 1){
			printf("Vous decidez de l'attaquer.\n");
			pvMonstre1 = pvMonstre1 - attDps;
			
			}

		//---------------------------------------------- monstre 2

		//	Si le dps fait le choix 3, il empoisonne sa cible
		if (decisionDps == 3 && pmDps>=3 && cibleDps == 2){
				printf("Vous avez empoisonne le monstre 2.\n");
				poisonDps2 ++;
				pmDps = pmDps -3;
		}	
		// Si le mana est insufisant il choisit entre 1 et 2 	
		else if(decisionDps == 3 && pmDps<3 && cibleDps == 2){
				printf ("Vous n'avez plus de mana\n");
				printf ("Attaquer (1)\n");
				printf ("Defendre (2)\n");
			
				scanf("%d",&decisionDps);
		
		}
		
		// Si le dps fait le choix 2, il se défend
		if (decisionDps == 2 && cibleDps == 2){
			printf("Vous decidez de vous defendre.\n");
			attMonstre2 = attMonstre2/2;
			
		}
		
		// Si le dps fait le choix 1, il attaque
		if(decisionDps == 1 && cibleDps == 2){
			printf("Vous decidez de l'attaquer.\n");
			pvMonstre2 = pvMonstre2 - attDps;
			
			}
		
		
		
		// -------------------------------------- TOUR DU TANK --------------------------------------------------------
		
		
		printf ("C'est le tour du Tank\n");
		printf ("Attaquer (1)\n");
		printf ("Defendre (2)\n");
		printf ("Provoquer (3)\n");
		
		scanf("%d",&decisionTank);

		printf ("qui veux tu cibler ?\n");
		printf ("Monstre 1 (1) ou Monstre 2 (2) ?");

		scanf("%d",&cibleTank);
		
		
		
		// Si le tank fait le choix 3, il provoque sa cible		
		if (decisionTank == 3 && pmTank>=3 && cibleTank == 1){
			printf("Vous provoquez monstre 1.\n");
			provocation1 = 1;
			pmTank = pmTank -3;
		}
		// Si le mana est insufisant il choisit entre 1 et 2 		
		else if(decisionTank == 3 && pmTank<3 && cibleTank == 1){
				printf ("Vous n'avez plus de mana\n");
				printf ("Attaquer (1)\n");
				printf ("Defendre (2)\n");

				scanf("%d",&decisionTank);	
		
		}
		
		// Si le tank fait le choix 2, il se défend
		if (decisionTank == 2 && cibleTank == 1){
			printf("Vous decidez de vous defendre.\n");
			attMonstre1 = attMonstre1/4;
			
		}
		
		// Si le tank fait le choix 1, il attaque	
		if(decisionTank == 1 && cibleTank == 1){
			printf("Vous decidez de l'attaquer.\n");
			pvMonstre1 = pvMonstre1 - attTank;
			
		}

		//---------------------------------------------- monstre 2

		//	Si le dps fait le choix 3, il empoisonne sa cible
		if (decisionTank == 3 && pmTank>=3 && cibleTank == 2){
				printf("Vous avez provoque monstre 2.\n");
				provocation2 = 1;
				pmTank = pmTank -3;
		}	
		// Si le mana est insufisant il choisit entre 1 et 2 	
		else if(decisionTank == 3 && pmTank<3 && cibleTank == 2){
				printf ("Vous n'avez plus de mana\n");
				printf ("Attaquer (1)\n");
				printf ("Defendre (2)\n");
			
				scanf("%d",&decisionDps);
		
		}
		
		// Si le dps fait le choix 2, il se défend
		if (decisionTank == 2 && cibleTank == 2){
			printf("Vous decidez de vous defendre.\n");
			attMonstre2 = attMonstre2/2;
			
		}
		
		// Si le dps fait le choix 1, il attaque
		if(decisionTank == 1 && cibleTank == 2){
			printf("Vous decidez de l'attaquer.\n");
			pvMonstre2 = pvMonstre2 - attTank;
			
			}
		
		// -------------------------------------- TOUR DU HEAL --------------------------------------------------------
		
		printf ("C'est le tour du Heal\n");
		printf ("Attaquer (1)\n");
		printf ("Defendre (2)\n");
		printf ("Soigner (3)\n");
		
		scanf("%d",&decisionHeal);

		printf ("qui veux tu cibler ?\n");
		printf ("Monstre 1 (1) ou Monstre 2 (2) ?");

		scanf("%d",&cibleHeal);
		
		
		// Si le heal fait le choix 3, il soigne une cible
			if (decisionHeal == 3 && pmHeal>=3){
				printf("Qui voulez vous soigner ?.\n");
				printf ("Dps (1)\n");
				printf ("Tank (2)\n");
				printf ("Heal (3)\n");
				
				scanf("%d",&decisionSoin);
				
				if (decisionSoin == 1){
					pvDps = pvDps + 20;
				}
				if (decisionSoin == 2){
					pvTank = pvTank + 20;
				}
				if (decisionSoin == 3){
					pvHeal = pvHeal + 20;
				}
				
				pmDps = pmDps -3;
			}
			
			// Si le mana est insufisant il choisit entre 1 et 2 
			else if(decisionHeal == 3 && pmDps<3){
			printf ("Vous n'avez plus de mana\n");
			printf ("Attaquer (1)\n");
			printf ("Defendre (2)\n");
			
			scanf("%d",&decisionHeal);
			
			}
		
		// Si le heal fait le choix 2, il se défend
		if (decisionHeal == 2 && cibleHeal == 1){
			printf("Vous decidez de vous defendre.\n");
			attMonstre1 = attMonstre1/2;
			
		}
		
		// Si le heal fait le choix 1, il attaque
		if(decisionHeal == 1 && cibleHeal == 1){
			printf("Vous decidez de l'attaquer.\n");
			pvMonstre1 = pvMonstre1 - attHeal;
			
			}
		
		// Si le heal fait le choix 2, il se défend
		if (decisionHeal == 2 && cibleHeal == 2){
			printf("Vous decidez de vous defendre.\n");
			attMonstre2 = attMonstre2/2;
			
		}
		
		// Si le heal fait le choix 1, il attaque
		if(decisionHeal == 1 && cibleHeal == 2){
			printf("Vous decidez de l'attaquer.\n");
			pvMonstre2 = pvMonstre2 - attHeal;
			
			}
		
		// -------------------------------------- TOUR DES MONSTRES --------------------------------------------------------
		
		// Si le tank a utiliser sa provocation, le monstre l'attaque obligatoirement
		if(provocation1 == 1){
			printf("Le monstre attaque le Tank.\n");
			pvTank = pvTank - attMonstre1;
		}
		// Sinon il prend une decision aléatoire sur une cible aléatoire
		else{
			decisionM1 =((rand()%3)+1);
			cibleMonstre1 = ((rand()%3)+1);
			
		// Il attaque le dps
			if(decisionM1 == 1 && cibleMonstre1 == 1){
				printf("Le monstre attaque le Dps.\n");
				pvDps = pvDps - attMonstre1;
			}
			
		// Il attaque le tank
			if(decisionM1 == 1 && cibleMonstre1 == 2){
				printf("Le monstre attaque le Tank.\n");
				pvTank = pvTank - attMonstre1;
			}
			
		// Il attaque le heal
			if(decisionM1 == 1 && cibleMonstre1 == 3){
				printf("Le monstre attaque le Heal.\n");
				pvHeal = pvHeal - attMonstre1;
			}
			
			
			
		// Il augmente ses dégats et s'enlève le poison	
			if (decisionM1 == 3 && pmMonstre1>=3){
				printf("Le monstre s'enrage. Il augmente ses degats et dissipe le poison.\n");
				pmMonstre1 = pmMonstre1 -5;
				attMonstre1 = attMonstre1 + 10;
				antidote1 = 1;
				
		// Si le mana est insufisant il choisit entre 1 et 2		
				if(decisionM1 == 3 && pmMonstre1<3){
					decisionM1 =((rand()%2)+1);
					cibleMonstre1 = ((rand()%3)+1);
				}
			}
			
		// Il se soigne	
			if (decisionM1 == 2){
				printf("Le monstre se soigne.\n");
				pvMonstre1 = pvMonstre1 + 10;
					
			}
		}
		
		//----------------------------------------------MONSTRE 2

		// Si le tank a utiliser sa provocation, le monstre l'attaque obligatoirement
		if(provocation2 == 1){
			printf("Le monstre attaque le Tank.\n");
			pvTank = pvTank - attMonstre2;
		}
		// Sinon il prend une decision aléatoire sur une cible aléatoire
		else{
			decisionM2 =((rand()%3)+1);
			cibleMonstre2 = ((rand()%3)+1);
			
		// Il attaque le dps
			if(decisionM2 == 1 && cibleMonstre2 == 1){
				printf("Le monstre attaque le Dps.\n");
				pvDps = pvDps - attMonstre2;
			}
			
		// Il attaque le tank
			if(decisionM2 == 1 && cibleMonstre2 == 2){
				printf("Le monstre attaque le Tank.\n");
				pvTank = pvTank - attMonstre2;
			}
			
		// Il attaque le heal
			if(decisionM2 == 1 && cibleMonstre2 == 3){
				printf("Le monstre attaque le Heal.\n");
				pvHeal = pvHeal - attMonstre2;
			}
			
			
			
		// Il augmente ses dégats et s'enlève le poison	
			if (decisionM2 == 3 && pmMonstre2>=3){
				printf("Le monstre s'enrage. Il augmente ses degats et dissipe le poison.\n");
				pmMonstre2 = pmMonstre2 -5;
				attMonstre2 = attMonstre2 + 10;
				antidote2 = 1;
				
		// Si le mana est insufisant il choisit entre 1 et 2		
				if(decisionM2 == 3 && pmMonstre2<3){
					decisionM2 =((rand()%2)+1);
					cibleMonstre2 = ((rand()%3)+1);
				}
			}
			
		// Il se soigne	
			if (decisionM2 == 2){
				printf("Le monstre se soigne.\n");
				pvMonstre2 = pvMonstre2 + 10;
					
			}
		}
		
		
		
		
		
		
		// -------------------------------------- FIN DU TOUR --------------------------------------------------------
	
	// Si il y a du poison, enlève de la vie au monstre
	if(poisonDps1 >= 1){
		pvMonstre1 = pvMonstre1 - poisonDps1;
	}

	if(poisonDps2 >= 1){
		pvMonstre2 = pvMonstre2 - poisonDps2;
	}
	
	// Si il a fait son sort 3, il enlève son poison
	if(antidote1 >= 1){
		poisonDps1 = 0;
	}

	if(antidote2 >= 1){
		poisonDps2 = 0;
	}
	
	// Recharger le mana à la fin de chaque tour
	if (pmDps<10){
		pmDps++;
	}
	if (pmTank<6){
		pmTank++;
	}
	if (pmHeal<20){
		pmHeal++;
	}
	
	if (pmMonstre1<10){
		pmMonstre1++;
	}

	if (pmMonstre2<10){
		pmMonstre2++;
	}

	if (pvDps <=0 && pvTank <=0 && pvHeal <=0){
		groupe = 0;
	}

	if (pvMonstre1 <=0 && pvMonstre2 <=0){
		monstres = 0;
	}
	
	printf ("Le monstre 1 a %d points de vie.\n", pvMonstre1);
	printf ("Le monstre 2 a %d points de vie.\n", pvMonstre2);
	printf (" \n");
	printf ("Le Dps a %d points de vie.\n", pvDps);
	printf ("Le Tank a %d points de vie.\n", pvTank);
	printf ("Le Heal a %d points de vie.\n", pvHeal);
	
	attDps = 10;
	attHeal = 8;
	attTank = 5;
	provocation1 = 0;
	provocation2 = 0;
		
	}	
	
	
	


	return 0;
}