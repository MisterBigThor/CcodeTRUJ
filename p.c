
#include "defines"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


/*
numCarrera|nivellDegradacio|Plou|numVoltes|numPilots|<pilot1>|...|<pilotN>
int         int             s/n  int[1,10] int[2,20]    
dorsal-nom-dataNaixement-compost-numParadas-numVoltaP1 / ... / numVoltaParadaN
*/
void printCarrera(carrera* c){
    printf("DADES DE LA CARRERA: %d\n, amb nivell de degradacio %d\n, voltes %d\n, pilots %d\n, Plou: %c\n", c->numero, c->degradacio, c->voltes, c->numPilots, c->plou);
}
void printCarrera2(carrera c){
     printf("DADES DE LA CARRERA: %d, amb nivell de degradacio %d, voltes %d, pilots %d \nPlou: %c \n", c.numero, c.degradacio, c.voltes, c.numPilots, c.plou);
}
void printPilot(pilot p){
    printf("dorsal %d", p.dorsal);
}
void leerDatosCarrera(String500 entrada, carrera * c){
    int index = 0;
    int j = 0;
    for(int i = 0; i < strlen(entrada); ++i){
        if(entrada[i] == '|' && index == 0){
            c->numero = charToInt2(entrada[j], entrada[i-1]);
            index++;
            j = i+1;
        }
        else if(entrada[i] == '|' && index == 1){
            c->degradacio = charToInt(entrada[i-1]);
            index++;
            j = i+1;
        }
        else if(entrada[i] == '|' && index == 2){
            c->plou = entrada[i-1];
            index++;
            j = i+1;
        }
        else if(entrada[i] == '|' && index == 3){
            c->voltes = charToInt2(entrada[j], entrada[i-1]);
            index++;
            j = i+1;
        }
        else if(entrada[i] == '|' && index == 4){
            c->numPilots = charToInt2(entrada[j], entrada[i-1]);
            index++;
            j = i+1;
        }
    }
}
pilot leerPilotos(String500 entrada, int * i){
    //contar 5 |
    int c = 0;
    pilot p;
    p.dorsal = 50;
    //for(int i = 0; i < strlen(entrada); ++i){
    //    if(c < 5 && entrada[i] == '|') ++c; 
    //    else{
//
    //    }
    //}
    return p;
}


int main(){
   
    String500 entrada;
    printf("introud informacio: \n");
    fgets(entrada, MAX_STR, stdin);
    carrera ret;
    leerDatosCarrera(entrada, &ret);
    printCarrera(&ret);
    pilot pilotosCarrera [ret.numPilots];
    pilot p = leerPilotos(entrada, 0);
    printPilot(p);
    

}