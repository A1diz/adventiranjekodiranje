
#include<stdio.h>
#include<string.h>
#define DIM 10
int main(){
	int n, x, y;
	char s[DIM];
	FILE*fp;
	fp=fopen("input.txt", "r");
	x=0;
	y=0;
	if(fp){
		while(fscanf(fp, "%s %d", s, &n)>0){
			if(strcmp(s, "forward")==0){
				x+=n;
			}else if(strcmp(s, "up")==0){
				y-=n;
			}else if(strcmp(s, "down")==0){
				y+=n;
			}
		
		}
		fclose(fp);


	}else{
		printf("nece \n");
	}
	
	printf("x. %d, y: %d\n putaputa: %d\n", x, y, (x*y));
	return 0;
}
