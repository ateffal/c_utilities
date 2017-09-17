/*
 * read_csv.c
 *
 *  Created on: 17 sept. 2017
 *      Author: ateffal
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_COL 64
#define MAX_WORD 100
#define MAX_LINES 1000000


typedef struct CSV_File {
	int n;              //Number of rows excluding header
	int m;              //Number of columns
	char header[MAX_COL*MAX_WORD];       //Header
	char* data[];    //Data - Each pointer points to a line of data (m columns separated with ";"

} CSV_File;


CSV_File* read_csv_0(const char* file ) {

	//open input file
    FILE* inptr;

    int taille_ligne;
    int n,i, j;


    if (( inptr = fopen ( file , "r")) == NULL )
	{
		printf (" File not found ! \n");
		return NULL;
	}

	j=0;
	char ligne_1[MAX_COL*MAX_WORD];
	char temp[MAX_COL*MAX_WORD];

	//Read and store the header
	if(fgets(ligne_1,MAX_COL*MAX_WORD, inptr) != NULL) {
		strcpy(temp,ligne_1);
	}

	n=0;
	//Counting number of lines (excluding header
	while(fgets(ligne_1,MAX_COL*MAX_WORD, inptr) != NULL) {
		n = n + 1;
	}

	fclose(inptr);

	CSV_File *csv_file1;
	csv_file1 = malloc(sizeof(CSV_File)+n*sizeof(char*));

	//Store the header in the struct
	strcpy(csv_file1->header,temp);

	//Store the number of lines in the struct
	csv_file1->n = n;

	if (( inptr = fopen ( file , "r")) == NULL )
	{
		printf (" File not found ! \n");
		return NULL;
	}

	int l=0;

	char* ligne_2;
	ligne_2 = malloc(MAX_COL*MAX_WORD*sizeof(char*));
	while(fgets(ligne_2,MAX_COL*MAX_WORD, inptr) != NULL  ) {
		if(l!=0) {
			csv_file1->data[l-1]=ligne_2;
		}

		l=l+1;
		ligne_2 = malloc(MAX_COL*MAX_WORD*sizeof(char*));
	}

	printf("File read succesfuly ! \n%ld lines read.\n",l);

	fclose(inptr);
	return csv_file1;

}



char** read_csv(const char* file ) {

	//open input file
    FILE* inptr;
    if (( inptr = fopen ( file , "r")) == NULL )
	{
		printf (" File not found ! \n");
		return NULL;
	}

	//Char pointer of the line read from the file
	char* ligne;

	//Number of lines read
	int l=0;

	//Allocation of memory of line pointer
	ligne = malloc(MAX_COL*MAX_WORD*sizeof(char*));

	//Counting number of lines
	while(fgets(ligne,MAX_COL*MAX_WORD, inptr) != NULL  ) {
		l=l+1;
	}

	//Close the file
	fclose(inptr);


	static char** data;
	data = (char**)malloc(l*sizeof(char*));


	if (( inptr = fopen ( file , "r")) == NULL )
	{
		printf (" File not found ! \n");
		return NULL;
	}

	//Reading lines
	l=0;
	while(fgets(ligne,MAX_COL*MAX_WORD, inptr) != NULL ) {
		data[l]=ligne;
		l=l+1;
		ligne = malloc(MAX_COL*MAX_WORD*sizeof(char*));
	}

	printf("File read succesfuly ! \n%ld lines read.\n",l);

	//Close the file
	fclose(inptr);

	return data;

}







