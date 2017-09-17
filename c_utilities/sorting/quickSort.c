/*
 * quickSort.c
 *
 *  Created on: 17 sept. 2017
 *      Author: ateffal
 */

#include <stdio.h>
#include <stdlib.h>

long int nb=0;

/**
    Returns the minimum of two integers

    @param a the first integer.
    @param b the second integer.
    @return the minimum of a and b.
*/
int minimum(int a, int b) {
	if(a<b) {
		return a;

	} else {
		return b;
	}
}

/**
    Returns the maximum of two integers

    @param a the first integer.
    @param b the second integer.
    @return the maximum of a and b.
*/
int maximum(int a, int b) {
	if(a<b) {
		return b;
	} else {
		return a;
	}
}

/**
    Returns the median of a table

    @param tableau the table of values.
    @param debut the first indice of the table.
    @param fin the last indice of the table.
    @return the indice corresponding to median of :
			the first value of the table , the value at the middle and the last value.
*/
int mediane(int tableau[][2], int debut, int fin) {
	int first, last, middle, med;

	//if the table has two elements return the indice corresponding to the smallest value
	if((fin-debut)==2) {
		if(tableau[debut][0]<tableau[fin-1][0]) {
			return debut;
		} else {
			return (fin-1);
		}
	}

	first = tableau[debut][0];
	last = tableau[fin-1][0];


	if(((fin-debut)%2)==0) {
		middle = tableau[debut+((fin-debut)/2)-1][0];
	} else {
		middle = tableau[debut+(fin-debut)/2][0];
	}

	if(minimum(first,last) < middle && middle <maximum(first,last)) {

		if(((fin-debut)%2)==0) {
			med = debut+((fin-debut)/2)-1;
		} else {
			med = debut+(fin-debut)/2;
		}
	}

	if(first > minimum(last,middle) && first <maximum(last,middle)) {
		med = debut;
	}

	if(minimum(middle,first) < last && last < maximum(middle,first) ) {
		med = fin-1;
	}

	return med;
}

//Swaps two integers
void swap(int *a, int *b) {
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

/**
    Returns the correct position (ascending order) of
	the element at the position I (the pivot).

    @param I the low index of the table.
    @param r the hight index of the table.
    @return the correct position of the pivot:
            every element to the left is smaller than the pivot,
            every element to the right of the pivot is gretter than
            the pivot.
*/
int Partition(int tableau[][2], int I, int r) {

	int i, j;
	int pivot;
	int temp;

	pivot=tableau[I][0];

	//Base case
	if((r== I)) {
		return I;
	}
	i=I+1;
	for(j=I+1; j<r; j++) {
		if(tableau[j][0]<pivot) {
			swap(&tableau[i][0],&tableau[j][0]);
			swap(&tableau[i][1],&tableau[j][1]);
			i=i+1;
		}
	}

	//Swap of tableau[I] and tableau[i-1]
	swap(&tableau[I][0],&tableau[i-1][0]);
	swap(&tableau[I][1],&tableau[i-1][1]);
	return (i-1);
}

unsigned long int QuickSort(int tableau[][2], int debut, int fin, int type_pivot) {

	if((fin-debut)==1) {
		return 0;
	}
	int i;
	unsigned long int NC=0, NC_l=0, NC_r=0;
	NC = fin-debut-1;



	//type pivot : 1 - first; 2 - median, 3 - last
	if(type_pivot==3) {
		swap(&tableau[debut][0],&tableau[fin-1][0]);
		swap(&tableau[debut][1],&tableau[fin-1][1]);
	}

	if(type_pivot==2) {
		int med;
		med = mediane(tableau,debut,fin);
		swap(&tableau[debut][0],&tableau[med][0]);
		swap(&tableau[debut][1],&tableau[med][1]);
	}

	i = Partition(tableau,debut,fin);
	nb=nb+fin-debut-1;

	if(i>debut) {
		NC_l=QuickSort(tableau,debut,i,type_pivot);
	}

	if(i<(fin-1)) {
		NC_r=QuickSort(tableau,i+1,fin,type_pivot);
	}


	return(NC+NC_l+NC_r);
}

/*int main(int argc, char* argv[]) {
	unsigned long int N = 0;
	int test[7][2];
	test[0][0] = 12;
	test[1][0] = 3;
	test[2][0] = 9;
	test[3][0] = 13;
	test[4][0] = 12;
	test[5][0] = 11;
	test[6][0] = 8;

	test[0][1] = 0;
	test[1][1] = 1;
	test[2][1] = 2;
	test[3][1] = 3;
	test[4][1] = 4;
	test[5][1] = 5;
	test[6][1] = 6;

	N= QuickSort(test,0,7,1);
	int i;

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
