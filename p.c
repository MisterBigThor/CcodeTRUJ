
#include "defines"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int charToInt(char c){
    if(c >= '0' &&  c <= '9'){
        return c - '0';
    }
    else return -1;
}
//printf("c2[1]= %d  dig1 =%d\n", i, ((c1.dig1)/10));

void printCodiRadio(codiRadio c){
	printf("CODI GENERAT: %c%d%d\n", c.lletra, c.dig1, c.dig2);
}

int main(){
    String50 s = "R181";
    codiRadio r;
    r.lletra = 'R';
    r.dig1 = 18;
    r.dig2 = 1;
    printCodiRadio(r);
    printf("salida %d", comparaCodiRadio(r, s));
}