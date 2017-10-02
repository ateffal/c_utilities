/*
 * mergeSort.c
 *
 *  Created on: 29 sept. 2017
 *      Author: a.teffal
 */

#include <stdio.h>
#include <stdlib.h>

void  Merge(int tableau[][2], int debut, int milieu , int fin) {

	int i = 0, j = 0, k = 0;
	int taille, taille1, taille2;
	taille1 = milieu-debut;
	taille2 = fin-milieu;
	int half1[taille1][2];
	int half2[taille2][2];


	for(i=0;i<taille1;i++) {
		half1[i][0]=tableau[debut+i][0];
		half1[i][1]=tableau[debut+i][1];
	}

	for(i=0;i<taille2;i++) {
		half2[i][0]=tableau[milieu+i][0];
		half2[i][1]=tableau[milieu+i][1];
	}

	taille = fin - debut;
	i = 0 ;
	j = 0;
	for(k=0;k<taille;k++) {
		if( (i< taille1 ) && (j < taille2 )) {
			if(half1[i][0]<=half2[j][0]) {
				tableau[debut + k][0]=half1[i][0];
				tableau[debut + k][1]=half1[i][1];
				i=i+1;
			} else {
				tableau[debut + k][0]=half2[j][0];
				tableau[debut + k][1]=half2[j][1];
				j=j+1;
			}
		} else {
			if(j >= taille2) {
				tableau[debut + k][0]=half1[i][0];
				tableau[debut + k][1]=half1[i][1];
				i = i+1;
			} else {
				tableau[debut + k][0]=half2[j][0];
				tableau[debut + k][1]=half2[j][1];
				j = j+1;
			}
		}
	}
}


void MergeSort(int tableau[][2], int debut, int fin) {

	if((fin-debut)==1) {
		return ;
	}
	/* Calculate middle of the array*/
	int milieu=debut+(fin-debut)/2;


	MergeSort(tableau,debut, milieu);
	MergeSort(tableau,milieu,fin);
	Merge(tableau, debut, milieu, fin);

}



/*int main(int argc, char* argv[]) {

	int test[7][2];
	int i;

	test[0][0] = 12;
	test[1][0] = 3;
	test[2][0] = 9;
	test[3][0] = 13;
	test[4][0] = 12;
	test[5][0] = 11;
	test[6][0] = 8;

	for(i=0; i<7; i++) {
		test[i][1]=i;
	}


	MergeSort(test,0,7,1);


	printf("N = %d\n",N);
	for(i=0; i<7; i++) {
		printf(" test[%d][0] = %d \n",i,test[i][0]);
	}

	printf("-------------- indices -------------------------\n");
	for(i=0; i<7; i++) {
		printf(" test[%d][1] = %d \n",i,test[i][1]);
	}
}

*/

