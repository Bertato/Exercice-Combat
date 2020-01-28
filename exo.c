#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main (){

//Caractéristiques PV
	int pvDps = 100;
	int pvTank =150;
	int pvHeal = 80;
	int pvMage = 90;

//Caractéristiques Attaque
	int attDps = 10;
	int attTank = 5;
	int attHeal = 8;
	int attMage = 11;
	
//Caractéristiques Mana
	int pmDps = 10;
	int pmTank = 6;
	int pmHeal = 20;
	int pmMage = 12;

//Caractéristiques cible des joueurs 
	int cibleDps =0;
	int cibleTank =0;
	int cibleHeal =0;
	int cibleMage = 0;

//Caractéristiques du monstre 1
	int pvMonstre1 = 150;
	int attMonstre1 = 30;
	int pmMonstre1 = 10;
	int cibleMonstre1 = 0;

//Caractéristiques du monstre 2
	int pvMonstre2 = 150;
	int attMonstre2 = 30;
	int pmMonstre2 = 10;
	int cibleMonstre2 = 0;
	
//Caractéristiques decision des tout le monde
	int decisionDps = 0;
	int decisionTank = 0;
	int decisionHeal = 0;
	int decisionSoin = 0;
	int decisionMage = 0;
	int decisionM1 = 0;
	int decisionM2 = 0;

//Caractéristiques mort de tout le monde 
	int mortDps = 0;
	int mortTank =0;
	int mortHeal = 0;
	int mortMage = 0;
	int mortM1 = 0;
	int mortM2= 0;
	
//Caractéristiques xp et lvl
	int xp = 0;
	int lvl = 1;
	
//Caractéristiques attaques spéciales
	int poisonDps1 = 0;
	int poisonDps2 = 0;
	int antidote1 = 0;
	int antidote2 = 0;
	int feu = 20;
	int provocation1 = 0;
	int provocation2 = 0;
	
	srand(time(NULL));


		
	while( (mortDps == 0 || mortHeal == 0 || mortTank ==0 || mortMage == 0) && (pvMonstre1 >=0 || pvMonstre2 >=0) ){
		
		// ---------------------------------------------------------------------------------------------- TOUR DU DPS --------------------------------------------------------
		if (pvDps <= 0){
			mortDps = 1;
			printf ("Le dps est mort\n");
		}
		
		else{
			printf (" \n");
			printf ("C'est le tour du Dps\n");
			printf ("Attaquer (1)\n");
			printf ("Defendre (2)\n");
			printf ("Empoisonner (3)\n");
			printf (" \n");
			
			scanf("%d",&decisionDps);
			printf (" \n");

			printf ("qui veux tu cibler ?\n");
			printf ("Monstre 1 (1) ou Monstre 2 (2) ?");
			printf (" \n");

			scanf("%d",&cibleDps);
			
			//	Si le dps fait le choix 3, il empoisonne sa cible
			if (decisionDps == 3 && pmDps>=3 && cibleDps == 1){
					printf("Vous avez empoisonne le monstre 1.\n");
					printf (" \n");
					poisonDps1 ++;
					pmDps = pmDps -3;
			}	
			// Si le mana est insufisant il choisit entre 1 et 2 	
			else if(decisionDps == 3 && pmDps<3 && cibleDps == 1){
					printf ("Vous n'avez plus de mana\n");
					printf (" \n");
					printf ("Attaquer (1)\n");
					printf ("Defendre (2)\n");
				
					scanf("%d",&decisionDps);
			
			}

			// Si le dps fait le choix 2, il se défend
			if (decisionDps == 2 && cibleDps == 1){
				printf("Vous decidez de vous defendre.\n");
				printf (" \n");
				attMonstre1 = attMonstre1/2;
				
			}
			
			// Si le dps fait le choix 1, il attaque
			if(decisionDps == 1 && cibleDps == 1){
				printf("Vous decidez de l'attaquer.\n");
				printf (" \n");
				pvMonstre1 = pvMonstre1 - attDps;
				
				}

			//------------------------------------------------------- monstre 2 ------------------------------------------------------------

			//	Si le dps fait le choix 3, il empoisonne sa cible
			if (decisionDps == 3 && pmDps>=3 && cibleDps == 2){
					printf("Vous avez empoisonne le monstre 2.\n");
					printf (" \n");
					poisonDps2 ++;
					pmDps = pmDps -3;
			}	
			// Si le mana est insufisant il choisit entre 1 et 2 	
			else if(decisionDps == 3 && pmDps<3 && cibleDps == 2){
					printf ("Vous n'avez plus de mana\n");
					printf (" \n");
					printf ("Attaquer (1)\n");
					printf ("Defendre (2)\n");
				
					scanf("%d",&decisionDps);
			
			}
			
			// Si le dps fait le choix 2, il se défend
			if (decisionDps == 2 && cibleDps == 2){
				printf("Vous decidez de vous defendre.\n");
				printf (" \n");
				attMonstre2 = attMonstre2/2;
				
			}
			
			// Si le dps fait le choix 1, il attaque
			if(decisionDps == 1 && cibleDps == 2){
				printf("Vous decidez de l'attaquer.\n");
				printf (" \n");
				pvMonstre2 = pvMonstre2 - attDps;
				
				}
		}
			
			
			// ----------------------------------------------------------------------------------------------- TOUR DU TANK --------------------------------------------------------
			
			if (pvTank <= 0){
				mortTank = 1;
				printf ("Le Tank est mort\n");
			}
			
			else{
				printf ("C'est le tour du Tank\n");
				printf (" \n");
				printf ("Attaquer (1)\n");
				printf ("Defendre (2)\n");
				printf ("Provoquer (3)\n");
				
				scanf("%d",&decisionTank);

				printf ("qui veux tu cibler ?\n");
				printf ("Monstre 1 (1) ou Monstre 2 (2) ?");
				printf (" \n");

				scanf("%d",&cibleTank);
				
				
				
				// Si le tank fait le choix 3, il provoque sa cible		
				if (decisionTank == 3 && pmTank>=3 && cibleTank == 1){
					printf("Vous provoquez monstre 1.\n");
					printf (" \n");
					provocation1 = 1;
					pmTank = pmTank -3;
				}
				// Si le mana est insufisant il choisit entre 1 et 2 		
				else if(decisionTank == 3 && pmTank<3 && cibleTank == 1){
						printf ("Vous n'avez plus de mana\n");
						printf ("Attaquer (1)\n");
						printf ("Defendre (2)\n");
						printf (" \n");

						scanf("%d",&decisionTank);	
			
				}
				
				// Si le tank fait le choix 2, il se défend
				if (decisionTank == 2 && cibleTank == 1){
					printf("Vous decidez de vous defendre.\n");
					printf (" \n");
					attMonstre1 = attMonstre1/4;
					
				}
				
				// Si le tank fait le choix 1, il attaque	
				if(decisionTank == 1 && cibleTank == 1){
					printf("Vous decidez de l'attaquer.\n");
					printf (" \n");
					pvMonstre1 = pvMonstre1 - attTank;
					
				}

				//------------------------------------------------------- monstre 2 ------------------------------------------------------------

				//	Si le dps fait le choix 3, il empoisonne sa cible
				if (decisionTank == 3 && pmTank>=3 && cibleTank == 2){
						printf("Vous avez provoque monstre 2.\n");
						printf (" \n");
						provocation2 = 1;
						pmTank = pmTank -3;
				}	
				// Si le mana est insufisant il choisit entre 1 et 2 	
				else if(decisionTank == 3 && pmTank<3 && cibleTank == 2){
						printf ("Vous n'avez plus de mana\n");
						printf ("Attaquer (1)\n");
						printf ("Defendre (2)\n");
						printf (" \n");
					
						scanf("%d",&decisionDps);
				
				}
				
				// Si le dps fait le choix 2, il se défend
				if (decisionTank == 2 && cibleTank == 2){
					printf("Vous decidez de vous defendre.\n");
					printf (" \n");
					attMonstre2 = attMonstre2/2;
					
				}
				
				// Si le dps fait le choix 1, il attaque
				if(decisionTank == 1 && cibleTank == 2){
					printf("Vous decidez de l'attaquer.\n");
					printf (" \n");
					pvMonstre2 = pvMonstre2 - attTank;
					
					}
			}
			
		// ---------------------------------------------------------------------------------------------- TOUR DU MAGE --------------------------------------------------------
		
		if (pvMage <= 0){
			mortMage = 1;
			printf ("Le Mage est mort\n");
		}
		
		else{
			printf (" \n");
			printf ("C'est le tour du Mage\n");
			printf ("Attaquer (1)\n");
			printf ("Defendre (2)\n");
			printf ("Boule de feu (3)\n");
			printf (" \n");
			
			scanf("%d",&decisionMage);
			printf (" \n");

			printf ("qui veux tu cibler ?\n");
			printf ("Monstre 1 (1) ou Monstre 2 (2) ?");
			printf (" \n");

			scanf("%d",&cibleMage);
			
			//	Si le dps fait le choix 3, il empoisonne sa cible
			if (decisionMage == 3 && pmMage>=3 && cibleMage == 1){
					printf("Vous avez empoisonne le monstre 1.\n");
					printf (" \n");
					pvMonstre1 = pvMonstre1 -feu ;
					pmDps = pmDps -3;
			}	
			// Si le mana est insufisant il choisit entre 1 et 2 	
			else if(decisionMage == 3 && pmMage<3 && cibleMage == 1){
					printf ("Vous n'avez plus de mana\n");
					printf (" \n");
					printf ("Attaquer (1)\n");
					printf ("Defendre (2)\n");
				
					scanf("%d",&decisionDps);
			
			}

			// Si le dps fait le choix 2, il se défend
			if (decisionMage == 2 && cibleMage == 1){
				printf("Vous decidez de vous defendre.\n");
				printf (" \n");
				attMonstre1 = attMonstre1/2;
				
			}
			
			// Si le dps fait le choix 1, il attaque
			if(decisionMage == 1 && cibleMage == 1){
				printf("Vous decidez de l'attaquer.\n");
				printf (" \n");
				pvMonstre1 = pvMonstre1 - attMage;
				
				}

			//------------------------------------------------------- monstre 2 ------------------------------------------------------------

			//	Si le dps fait le choix 3, il empoisonne sa cible
			if (decisionMage == 3 && pmMage>=3 && cibleMage == 2){
					printf("Vous envoyez une boule de feu le monstre 2.\n");
					printf (" \n");
					pvMonstre2 = pvMonstre2 - feu;
					pmDps = pmDps -3;
			}	
			// Si le mana est insufisant il choisit entre 1 et 2 	
			else if(decisionMage == 3 && pmMage<3 && cibleMage == 2){
					printf ("Vous n'avez plus de mana\n");
					printf (" \n");
					printf ("Attaquer (1)\n");
					printf ("Defendre (2)\n");
				
					scanf("%d",&decisionMage);
			
			}
			
			// Si le dps fait le choix 2, il se défend
			if (decisionMage == 2 && cibleMage == 2){
				printf("Vous decidez de vous defendre.\n");
				printf (" \n");
				attMonstre2 = attMonstre2/2;
				
			}
			
			// Si le dps fait le choix 1, il attaque
			if(decisionMage == 1 && cibleMage == 2){
				printf("Vous decidez de l'attaquer.\n");
				printf (" \n");
				pvMonstre2 = pvMonstre2 - attMage;
				
				}
		}
		
		
		
		
		
		
		
		
		
		
	
		// ---------------------------------------------------------------------------------------------- TOUR DU HEAL --------------------------------------------------------
		
		if (pvHeal <= 0){
				mortHeal = 1;
				printf ("Le Heal est mort\n");
			}
			
		else{
			printf ("C'est le tour du Heal\n");
			printf ("Attaquer (1)\n");
			printf ("Defendre (2)\n");
			printf ("Soigner (3)\n");
			printf (" \n");
			
			scanf("%d",&decisionHeal);

			printf ("qui veux tu cibler ?\n");
			printf ("Monstre 1 (1) ou Monstre 2 (2) ?");
			printf (" \n");

			scanf("%d",&cibleHeal);
			
			
			// Si le heal fait le choix 3, il soigne une cible
				if (decisionHeal == 3 && pmHeal>=3){
					printf("Qui voulez vous soigner ?.\n");
					printf ("Dps (1)\n");
					printf ("Tank (2)\n");
					printf ("Heal (3)\n");
					printf (" \n");
					
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
				printf (" \n");
				
				scanf("%d",&decisionHeal);
				
				}
			
			// Si le heal fait le choix 2, il se défend
			if (decisionHeal == 2 && cibleHeal == 1){
				printf("Vous decidez de vous defendre.\n");
				printf (" \n");
				attMonstre1 = attMonstre1/2;
				
			}
			
			// Si le heal fait le choix 1, il attaque
			if(decisionHeal == 1 && cibleHeal == 1){
				printf("Vous decidez de l'attaquer.\n");
				printf (" \n");
				pvMonstre1 = pvMonstre1 - attHeal;
				
				}
				
				
			//------------------------------------------------------- monstre 2 ------------------------------------------------------------

			
			// Si le heal fait le choix 2, il se défend
			if (decisionHeal == 2 && cibleHeal == 2){
				printf("Vous decidez de vous defendre.\n");
				printf (" \n");
				attMonstre2 = attMonstre2/2;
				
			}
			
			// Si le heal fait le choix 1, il attaque
			if(decisionHeal == 1 && cibleHeal == 2){
				printf("Vous decidez de l'attaquer.\n");
				printf (" \n");
				pvMonstre2 = pvMonstre2 - attHeal;
				
				}
		}
		// ------------------------------------------------------------------------------------------------------ TOUR DES MONSTRES --------------------------------------------------------
		
		
		
		if (pvMonstre1 <= 0){
				mortM1 = 1;
				printf ("Le monstre 1 est mort\n");
			}
		
		else{
			
			// Si le tank a utiliser sa provocation, le monstre l'attaque obligatoirement
			if(provocation1 == 1){
				printf("Le monstre 1 attaque le Tank.\n");
				pvTank = pvTank - attMonstre1;
			}
			// Sinon il prend une decision aléatoire sur une cible aléatoire
			else{
				decisionM1 =((rand()%3)+1);
				cibleMonstre1 = ((rand()%3)+1);
				
			// Il attaque le dps
				if(decisionM1 == 1 && cibleMonstre1 == 1){
					printf("Le monstre 1 attaque le Dps.\n");
					pvDps = pvDps - attMonstre1;
				}
				
			// Il attaque le tank
				if(decisionM1 == 1 && cibleMonstre1 == 2){
					printf("Le monstre 1 attaque le Tank.\n");
					pvTank = pvTank - attMonstre1;
				}
				
			// Il attaque le heal
				if(decisionM1 == 1 && cibleMonstre1 == 3){
					printf("Le monstre 1 attaque le Heal.\n");
					pvHeal = pvHeal - attMonstre1;
				}
				
				
				
			// Il augmente ses dégats et s'enlève le poison	
				if (decisionM1 == 3 && pmMonstre1>=3){
					printf("Le monstre 1 s'enrage. Il augmente ses degats et dissipe le poison.\n");
					pmMonstre1 = pmMonstre1 -5;
					attMonstre1 = attMonstre1 + 10;
					antidote1 = 1;
				}
					
			// Si le mana est insufisant il choisit entre 1 et 2		
				else if(decisionM1 == 3 && pmMonstre1<3){
					decisionM1 =((rand()%2)+1);
					cibleMonstre1 = ((rand()%3)+1);
				}
				
				
			// Il se soigne	
				if (decisionM1 == 2){
					printf("Le monstre 1 se soigne.\n");
					pvMonstre1 = pvMonstre1 + 10;
						
				}
			}
		}


		
		//--------------------------------------------------------------------------------------MONSTRE 2------------------------------------------------------------------------

		if (pvMonstre2 <= 0){
				mortM2 = 1;
				printf ("Le monstre 2 est mort\n");
			}
			
		else{


			// Si le tank a utiliser sa provocation, le monstre l'attaque obligatoirement
			if(provocation2 == 1){
				printf("Le monstre 2 attaque le Tank.\n");
				printf (" \n");
				pvTank = pvTank - attMonstre2;
			}
			// Sinon il prend une decision aléatoire sur une cible aléatoire
			else{
				decisionM2 =((rand()%3)+1);
				cibleMonstre2 = ((rand()%3)+1);
				
			// Il attaque le dps
				if(decisionM2 == 1 && cibleMonstre2 == 1){
					printf("Le monstre 2 attaque le Dps.\n");
					printf (" \n");
					pvDps = pvDps - attMonstre2;
				}
				
			// Il attaque le tank
				if(decisionM2 == 1 && cibleMonstre2 == 2){
					printf("Le monstre 2 attaque le Tank.\n");
					printf (" \n");
					pvTank = pvTank - attMonstre2;
				}
				
			// Il attaque le heal
				if(decisionM2 == 1 && cibleMonstre2 == 3){
					printf("Le monstre 2 attaque le Heal.\n");
					printf (" \n");
					pvHeal = pvHeal - attMonstre2;
				}
				
				
				
			// Il augmente ses dégats et s'enlève le poison	
				if (decisionM2 == 3 && pmMonstre2>=3){
					printf("Le monstre 2 s'enrage. Il augmente ses degats et dissipe le poison.\n");
					printf (" \n");
					pmMonstre2 = pmMonstre2 -5;
					attMonstre2 = attMonstre2 + 10;
					antidote2 = 1;
				}
					
			// Si le mana est insufisant il choisit entre 1 et 2		
				else if(decisionM2 == 3 && pmMonstre2<3){
						decisionM2 =((rand()%2)+1);
						cibleMonstre2 = ((rand()%3)+1);
				}
				
				
			// Il se soigne	
				if (decisionM2 == 2){
					printf("Le monstre 2 se soigne.\n");
					printf (" \n");
					pvMonstre2 = pvMonstre2 + 10;
						
				}
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

	
		printf ("Le monstre 1 a %d points de vie.\n", pvMonstre1);
		printf ("Le monstre 2 a %d points de vie.\n", pvMonstre2);
		printf (" \n");
		printf ("Le Dps a %d points de vie.\n", pvDps);
		printf ("Le Mage a %d points de vie.\n", pvMage);
		printf ("Le Tank a %d points de vie.\n", pvTank);
		printf ("Le Heal a %d points de vie.\n", pvHeal);
		printf (" \n");
		
		attDps = 10;
		attHeal = 8;
		attTank = 5;
		attMage = 11;
		provocation1 = 0;
		provocation2 = 0;
		
		if (mortM1 == 1 && mortM2 == 1){
			printf("Bravo vous avez battu les deux monstres\n");
		}
		
		if (mortM1 == 1) {
			printf("Un nouveau monstre 1 apparait.\n");
			pvMonstre1 = 150;
			mortM1 = 0;
			
			printf("Vous gagnez 25 d'exp\n");
			xp = xp +25;
		}
		
		if (mortM2 == 1) {
			printf("Un nouveau monstre 2 apparait.\n");
			pvMonstre2 = 150;
			mortM2 = 0;
			
			printf("Vous gagnez 25 d'exp\n");
			xp = xp +25;
		}
		
		if ( xp == 50){
			lvl = lvl +1;
			xp = 0;
		}
		
		if (mortDps == 1 && mortHeal == 1 && mortTank ==1 && mortMage == 1){
			printf("Votre groupe est mort\n");
		}	
	}	
	
	
	
	
	
	


	return 0;
}