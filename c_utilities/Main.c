/*
 * Main.c
 *
 *  Created on: 17 sept. 2017
 *      Author: ateffal
 */
#include "/home/ateffal/git/c_utilities/c_utilities/read_csv.c"

int main(int argc, char* argv[]) {

	const char* infile = "edges.txt";

	long int i;

	//Example using read_csv
	/*

	 char** data1;

	 data1 = read_csv(infile);

	 printf("Entête : %s\n",data1[0]);
	 for(i=1;i<11;i++) {
	 printf("Ligne %d : ",i);
	 printf("%s\n",data1[i]);
	 }

	 */

	//Example using read_csv_0
	CSV_File *csvf1;

	csvf1 = read_csv_0(infile);
	printf("Nombre de ligne = %ld\n", csvf1->n);
	printf("Entête = %s\n", csvf1->header);
	for (i = 0; i < 10; i++) {
		printf("Ligne %d : ", i);
		printf("%s\n", csvf1->data[i]);
	}

	/*
	 //Example using quickSort.c
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
	 */

	return 0;
}
