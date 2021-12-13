#include<stdio.h>
#include<stdlib.h>
#define N 3
int main(){
	FILE *fp;
	int r, prev, sum, n[N], j;
	fp = fopen("input.txt", "r");
	r=0;
	if(fp){
		prev=0;
		for(j=0; j<N; j++){
			fscanf(fp, "%d ", &n[j]);
			prev+=n[j];
		}
		j=0;
		while(fscanf(fp, "%d ", &n[j])>0){
			sum=n[0]+n[1]+n[2];
			if(sum>prev)
				r++;
			prev=sum;
			j++;
			if(j>2)
				j=0;
		}
		printf("%d ", r);
		fclose(fp);
	}else{
		printf("nradi sniadmnet\n");
	}
	return 0;
}
//c je proklet c
