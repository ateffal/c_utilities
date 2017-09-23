/*
 * c_utilities.h
 *
 *  Created on: 17 sept. 2017
 *      Author: ateffal
 */

#ifndef C_UTILITIES_H_
#define C_UTILITIES_H_

#define MAX_COL 64
#define MAX_WORD 100
#define MAX_LINES 1000000

typedef struct CSV_File {
	int n;              //Number of rows excluding header
	int m;              //Number of columns
	char header[MAX_COL*MAX_WORD];       //Header
	char* data[];    //Data - Each pointer points to a line of data (m columns separated with ";"

} CSV_File;

//CSV_File* read_csv_0(const char* file );
//char** read_csv(const char* file );


#endif /* C_UTILITIES_H_ */




