#include<stdio.h>
#include<stdlib.h>
int main (){
	
	FILE *fp;
	int r, prev, n;
	fp = fopen("input.txt", "r");
	r = 0;
	if (fp) {
		fscanf(fp, "%d", &prev);
		while(fscanf(fp, "%d", &n)>0){
			if (n > prev){
			r++;
			}
			prev = n;
	}
		printf("%d ", r);
		fclose(fp);
	}else {
		printf("ne radi dokmunnetnt \n");

	}
	
	return 0;
}
