#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXWORDS 256
#define MAXLEN 256

char** split_str(char* str, char sep) {

	int i,l;
	int n_words;

	//number of chars in str
	int n = strlen(str);

	static char* str_split[MAXWORDS];
	char temp[MAXLEN];
	temp[0]='\0';
	for(i=0; i<MAXWORDS; i++) {
		str_split[i]=NULL;
	}
	i=0;
	l=0;
	n_words=0;
	while(i<n) {
		if(str[i]!=sep && i!=(n-1)) {
			temp[l]=str[i];
			l++;
		}

		if(str[i]==sep) {
			temp[l]='\0';

			str_split[n_words] = malloc(l*sizeof(char));
			strcpy(str_split[n_words],temp);
			n_words++;

			l=0;
		}
		if(i==(n-1) && str[i]!=sep) {
			temp[l]=str[i];
			l=l+1;
			temp[l]='\0';

			str_split[n_words] = malloc(l*sizeof(char));
			strcpy(str_split[n_words],temp);
			n_words++;

			l=0;

		}
		i++;
	}



	return str_split;
}

int main(int argc, char* argv[]) {

	char* s = "amine;abdou;khaoula;bilal;kshhh";
	char sep=';';
	char** test;

	test = split_str(s,sep);

	int i;
	while(test[i]!=NULL) {
		printf("%s\n",test[i]);
		i++;
	}
	
	return 0;
}


