#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main (){
	int pvDps = 100;
	int pvTank =150;
	int pvHeal = 80;
	
	int attDps = 10;
	int attTank = 5;
	int attHeal = 8;
	
	int pmDps = 10;
	int pmTank = 6;
	int pmHeal = 20;
	
	int pvMonstre = 100;
	int attMonstre = 30;
	int pmMonstre = 10;
	int cibleMonstre = 0;
	
	int decisionDps = 0;
	int decisionTank = 0;
	int decisionHeal = 0;
	int decisionSoin = 0;
	int decisionM = 0;
	
	
	int poisonDps = 0;
	int antidote = 0;
	int provocation = 0;
	
	srand(time(NULL));

	while(pvMonstre>0 && pvDps>0 && pvHeal>0 && pvTank>0){
		
		// -------------------------------------- TOUR DU DPS --------------------------------------------------------
		printf ("C'est le tour du Dps\n");
		printf ("Attaquer (1)\n");
		printf ("Defendre (2)\n");
		printf ("Empoisonner (3)\n");
		
		scanf("%d",&decisionDps);
		
		//	Si le dps fait le choix 3, il empoisonne sa cible
		if (decisionDps == 3 && pmDps>=3){
				printf("Vous avez empoisonne l'ennemi.\n");
				poisonDps ++;
				pmDps = pmDps -3;
		}	
		// Si le mana est insufisant il choisit entre 1 et 2 	
		else if(decisionDps == 3 && pmDps<3){
				printf ("Vous n'avez plus de mana\n");
				printf ("Attaquer (1)\n");
				printf ("Defendre (2)\n");
			
				scanf("%d",&decisionDps);
		
		}
		
		// Si le dps fait le choix 2, il se défend
		if (decisionDps == 2){
			printf("Vous decidez de vous defendre.\n");
			attMonstre = attMonstre/2;
			
		}
		
		// Si le dps fait le choix 1, il attaque
		if(decisionDps == 1){
			printf("Vous decidez de l'attaquer.\n");
			pvMonstre = pvMonstre - attDps;
			
			}
		
		
		
		// -------------------------------------- TOUR DU TANK --------------------------------------------------------
		
		
		printf ("C'est le tour du Tank\n");
		printf("%d",pmTank);
		printf ("Attaquer (1)\n");
		printf ("Defendre (2)\n");
		printf ("Provoquer (3)\n");
		
		scanf("%d",&decisionTank);
		
		
		// Si le tank fait le choix 3, il provoque sa cible		
		if (decisionTank == 3 && pmTank>=3){
			printf("Vous provoquez l'ennemi.\n");
			provocation = 1;
			pmTank = pmTank -3;
			printf("%d",pmTank);
		}
		// Si le mana est insufisant il choisit entre 1 et 2 		
		else if(decisionTank == 3 && pmTank<3){
				printf ("Vous n'avez plus de mana\n");
				printf ("Attaquer (1)\n");
				printf ("Defendre (2)\n");
				printf("%d",pmTank);
			
				scanf("%d",&decisionTank);	
		
		}
		
		// Si le tank fait le choix 2, il se défend
		if (decisionTank == 2){
			printf("Vous decidez de vous defendre.\n");
			attMonstre = attMonstre/4;
			
		}
		
		// Si le tank fait le choix 1, il attaque	
		if(decisionTank == 1){
			printf("Vous decidez de l'attaquer.\n");
			pvMonstre = pvMonstre - attTank;
			
		}
		
		
		// -------------------------------------- TOUR DU HEAL --------------------------------------------------------
		
		printf ("C'est le tour du Heal\n");
		printf ("Attaquer (1)\n");
		printf ("Defendre (2)\n");
		printf ("Soigner (3)\n");
		
		scanf("%d",&decisionHeal);
		
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
		
		// Si le tank fait le choix 2, il se défend
		if (decisionHeal == 2){
			printf("Vous decidez de vous defendre.\n");
			attMonstre = attMonstre/2;
			
		}
		
		// Si le tank fait le choix 1, il attaque
		if(decisionHeal == 1){
			printf("Vous decidez de l'attaquer.\n");
			pvMonstre = pvMonstre - attHeal;
			
			}
		
		// -------------------------------------- TOUR DES MONSTRES --------------------------------------------------------
		
		// Si le tank a utiliser sa provocation, le monstre l'attaque obligatoirement
		if(provocation == 1){
			printf("Le monstre attaque le Tank.\n");
			pvTank = pvTank - attMonstre;
		}
		// Sinon il prend une decision aléatoire sur une cible aléatoire
		else{
			decisionM =((rand()%3)+1);
			cibleMonstre = ((rand()%3)+1);
			
		// Il attaque le dps
			if(decisionM == 1 && cibleMonstre == 1){
				printf("Le monstre attaque le Dps.\n");
				pvDps = pvDps - attMonstre;
			}
			
		// Il attaque le tank
			if(decisionM == 1 && cibleMonstre == 2){
				printf("Le monstre attaque le Tank.\n");
				pvTank = pvTank - attMonstre;
			}
			
		// Il attaque le heal
			if(decisionM == 1 && cibleMonstre == 3){
				printf("Le monstre attaque le Heal.\n");
				pvHeal = pvHeal - attMonstre;
			}
			
			
			
		// Il augmente ses dégats et s'enlève le poison	
			if (decisionM == 3 && pmMonstre>=3){
				printf("Le monstre s'enrage. Il augmente ses degats et dissipe le poison.\n");
				pmMonstre = pmMonstre -5;
				attMonstre = attMonstre + 10;
				antidote = 1;
				
		// Si le mana est insufisant il choisit entre 1 et 2		
				if(decisionM == 3 && pmMonstre<3){
					decisionM =((rand()%2)+1);
					cibleMonstre = ((rand()%3)+1);
				}
			}
			
		// Il se soigne	
			if (decisionM == 2){
				printf("Le monstre se soigne.\n");
				pvMonstre = pvMonstre + 10;
					
			}
		}
		
		
		
		
		
		
		// -------------------------------------- FIN DU TOUR --------------------------------------------------------
	
	// Si il y a du poison, enlève de la vie au monstre
	if(poisonDps >= 1){
		pvMonstre = pvMonstre - poisonDps;
	}
	
	// Si il a fait son sort 3, il enlève son poison
	if(antidote == 1){
		poisonDps = 0;
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
	
	if (pmMonstre<10){
		pmMonstre++;
	}
	
	printf ("Le monstre a %d points de vie.\n", pvMonstre);
	printf (" \n");
	printf ("Le Dps a %d points de vie.\n", pvDps);
	printf ("Le Tank a %d points de vie.\n", pvTank);
	printf ("Le Heal a %d points de vie.\n", pvHeal);
	
	attDps = 10;
	attHeal = 8;
	attTank = 5;
	provocation = 0;
		
	}	
	
	
	


	return 0;
}