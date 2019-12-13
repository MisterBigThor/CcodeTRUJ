#include <stdio.h>
#include <math.h>
#include <string.h>

//types y defines:
#include "defines"

//UTILITYS
int charToInt(char c){
    if(c >= '0' &&  c <= '9'){
        return c - '0';
    }
    else return -1;
}
int valorAbsolut(int n){
	if(n <= 0) return n * -1;
	else return n;
}

void printOpcions() {
	printf("\n");
	printf("*************************************************\n");
	printf("*                                               *\n");
	printf("*    Benvingut a LS Strategist!                 *\n");
	printf("*                                               *\n");
	printf("*    Si us plau, tria una opcio del menu:       *\n");
	printf("*                                               *\n");
	printf("*    1. Estrategia de pneumatics.               *\n");
	printf("*    2. Obtencio del codi de radio.             *\n");
	printf("*    3. Comunicar−se amb el pilot.              *\n");
	printf("*    4. Simular carrera.                        *\n");
	printf("*    5. Sortir.                                 *\n");
	printf("*                                               *\n");
	printf("*************************************************\n");

}

//OPCIO 1:
void stratPneumatics(){
	char plou, pneumatics;
	int nd, v, paradas;
	do{
		printf("Esta plovent sobre la pista? (S / N): ");
		scanf("\n%c", &plou);
	}while(!(plou == 's' || plou == 'S' || plou == 'n' || plou == 'N'));

	
	printf("Quin nivell de degradacio provoca la pista sobre el pneumatic? (0−4): ");
	scanf("%d", &nd);

	while(nd<0 || nd>4){
		printf("ERROR: Si us plau, introduiu un valor entre 0 i 4\n");
		printf("Quin nivell de degradacio provoca la pista sobre el pneumatic? (0−4): ");
		scanf("%d", &nd);
	}

	do{
		printf("Com es vol prioritzar la velocitat del pneumatic sobre la durabilitat? (1−5): ");
		scanf("%d", &v);
	}while(v<1 || v>5);

	pneumatics = valorAbsolut(v-nd);
	if(v < 3) paradas = 1;
	if(v == 3) paradas = 2;
	else paradas = 3;
	if(plou == 'n' || plou == 'N'){
		printf("El compost adecuat es el C%d i haureu de realitzar %d parada a boxes", pneumatics, paradas);	
	}

	if(plou == 's' || plou == 'S'){
		if(pneumatics < 3){
			printf("El compost adecuat es el W i haureu de realitzar %d parada a boxes", paradas);	
		}

		if(pneumatics >= 3){
			printf("El compost adecuat es el I i haureu de realitzar %d parada a boxes", paradas);
			
		}
	}
}

//OPCIO 2:
void printCodiRadio(codiRadio c){
	printf("CODI GENERAT: %c%d%d\n", c.lletra, c.dig1, c.dig2);
}


codiRadio genCodiRadio(){
	codiRadio ret;
	int dorsal, cursa;
	char lletra, dig_lletra;
	printf("Quin es el nombre de dorsal del pilot amb qui es vol comunicar? ");
	scanf("%d", &dorsal);
	while(dorsal < 1 || dorsal > 99){
		printf("ERROR: Has introduit un valor invalid.\n");
		printf("Quin es el nombre de dorsal del pilot amb qui es vol comunicar?");
		scanf("%d", &dorsal);
	}
	printf("Quin es el nombre de la cursa en el calendari? ");
	scanf("%d", &cursa);
	while(cursa < 1 || cursa > 21){
 		printf("ERROR: Has introduit un valor invalid.\n");
		printf("Quin es el nombre de la cursa en el calendari? ");
		scanf("%d", &cursa);
	}
	ret.dig1 = dorsal/cursa;
	ret.dig2 = dorsal/26;
	lletra = dorsal % 26;
	dig_lletra = 'A' + lletra - 1;
	ret.lletra = dig_lletra;
	ret.numCarrera = cursa;
	ret.dorsalPilot = dorsal;
	return ret;
}

//OPCION 3:
//0 si son diferentes, 1 si son iguals.
int comparaCodiRadio(codiRadio c1, String50 c2){
    if(strlen(c2) == 4){
        if(c2[0] != c1.lletra) return 0;
        if(charToInt(c2[1]) != (int)((c1.dig1)/10)) return 0;
        if(charToInt(c2[2]) != (c1.dig1)%10) return 0;
        if(charToInt(c2[3]) != c1.dig2) return 0;
    }
	else if(strlen(c2) == 3){
        if(c2[0] != c1.lletra) return 0;
        if(charToInt(c2[1]) != (c1.dig1)%10) return 0;
        if(charToInt(c2[2]) != (c1.dig2)) return 0;
    }
	return 1;
}

//MAIN:
int main(){
	int opcio = 0;
	char plou, pneumatics, lletra, dig_lletra;
	char resultat [MAX_CHARS], codi_generat [MAX_CHARS];
	codiRadio codiRadioGen; //codigo generado opc2
	int i;
	int nd, v, dorsal, cursa, dig1, dig2, o1, o2;
	String50 codiRadioEnt;
	while (opcio != 5) {
		printOpcions();
		printf("Opcio seleccionada: ");
		scanf("%d", &opcio);
	    switch (opcio) {
			case 1:
				stratPneumatics();
				o1 = 1;
				break;
			case 2:
				codiRadioGen = genCodiRadio();
				o2 = 1;
				printCodiRadio(codiRadioGen);
				break;
			case 3:
				if(o1 != 1 && o2 != 1) printf("ERROR: Encara no s'ha generat cap codi de xifrat per a la radio");
				else {
					printf("Introduiu el codi de radio: ");
					scanf("%s", codiRadioEnt);

					if(comparaCodiRadio(codiRadioGen, codiRadioEnt) == 0) 
						printf("ERROR: Aquest codi de radio no existeix.\n");
					else {
						printf("Codi correcte.\n");
						printf("comunicant amb el pilot # %d en la carrera # %d ...\n", codiRadioGen.dorsalPilot, codiRadioGen.numCarrera);
						
					}
				}
				break;
			case 4:
				break;
			case 5:
				//sortir
				break;
			default:
				printf("ERROR: Els valors admesos es troben entre l’1 i el 5.\n");
				printf("Si us plau, torneu a introduir la opcio: ");
				scanf("\n%d", &opcio);
				break;
	    }
	}
}
