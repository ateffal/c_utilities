#include <stdio.h>
#include <stdlib.h>





int Find_2(int t[], int n, int x) {
	
	if(x>=n) {
		printf("Find failed ! x must be smaller than n ! \n");
		return -1;
	}
	int i;
	i=x;
	while(i!=t[i] && i<n) {
		i=t[i];
		if(i>=n) {
			break;
		}
	}
	
	if(i>=n) {
		printf("Find failed ! An element of the table is greater than n!\n");
		return -1;
	}
	
	return i;
}

int Union_2(int t[], int n, int x, int y) {
	
	if(x>=n || y>=n) {
		printf("Union failed ! x and y must be smaller than n ! \n");
		return 0;
	}
	
	int x_parent;
	int y_parent;
	
	x_parent=Find_2(t,n,x);
	y_parent=Find_2(t,n,y);
	
	t[x_parent] = y_parent;
	
	return 1;
}

void display_2(int t[],int n) {
	int i;
	printf("-----------------------------------\n");
	for(i=0;i<5;i++) {
		printf("t[%d] = %d\n",i,t[i]);
	}
	
	printf("-----------------------------------\n");
}

/*int main(int argc, char* argv[]) {
	
	int t1[5];
	int i;
	for(i=0;i<5;i++) {
		t1[i]=i;
	}
	
	display(t1,5);
	
	Union(t1,5,1,0);
	
	Union(t1,5,0,4);
	
	display(t1,5);
	
	printf("cluster of 1 = %d",Find(t1,5,1));
	
}*/
