#include<stdio.h>
#include<string.h>
#define DIM 10
int main(){
	int n, x, y, aim;
	char s[DIM];
	FILE*fp;
	fp=fopen("input.txt", "r");
	x=0;
	y=0;
	aim = 0;
	if(fp){
		while(fscanf(fp, "%s %d", s, &n)>0){
			if(strcmp(s, "forward")==0){
				x+=n;
				y+=(n*aim); // valjda 
			}else if(strcmp(s, "up")==0){
				aim-=n;
			}else if(strcmp(s, "down")==0){
				aim+=n;
			}
			printf("y: %d\n", y);
		
		}
		fclose(fp);


	}else{
		printf("bukvalno zasto pisem ovaj dio \n");
	}
	
	printf("x. %d, y: %d\n hehehehehe: %d\n", x, y, (x*y));
	return 0;
}
