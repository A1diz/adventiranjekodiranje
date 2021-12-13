#include<stdio.h>
#define DIM 12
#define FILE_NAME "input.txt"
int binToInt(char s[]);

int main(){
	int rateO, rateCO2;
	int num1, num2, i, j, valid1, valid2, count2;
	char s[DIM+1], check1[DIM+1], check2[DIM+2];
	FILE*fp;

	fp = fopen(FILE_NAME, "r");

	for(i=0; i<DIM; i++){
		check1[i]=0;
		check2[i]=0;
	}
	check1[i]='\0';
	check2[i]='\0';

	if(fp){
	
		for(i=0; i<DIM; i++){
			num1 = 0;
			num2 = 0;
			count2=0;
			while(fscanf(fp, "%s ", s) > 0){
				valid1 = 1;
				valid2 = 1;
				for(j=0; j<i && (valid1 || valid2); j++){
					if(s[j]!=check1[j])
						valid1=0;
					if(s[j]!=check2[j])
						valid2=0;
				}

				if(valid1){
					if(s[i]=='1'){
						num1++;
					}else{
						num1--;
					}
				}
				if(valid2){
					count2++;
					if(s[i]=='1'){
						num2--;
					}else{
						num2++;
					}
				}
			}
			
			if(num1 >= 0){
				check1[i]='1';
			}else{
				check1[i]='0';
			}
			if(count2!=1){
				if(num2 > 0){
					check2[i]='1';
				}else{
					check2[i]='0';
				}
			}else{
				if(num2==-1)
					check2[i]='1';
				else
					check2[i]='0';
			}
			
			rewind(fp);
			}	
			rateO = binToInt(check1);
			rateCO2 = binToInt(check2);
			
			printf("ispane: Ox R8 (%d) * CO2 (%d) = %d \n", rateO, rateCO2, (rateO * rateCO2));
			
		}
	else{
		printf("...\n");
	}

	return 0;
}

int binToInt(char s[]){
	int ris, i;
	ris = 0;
	for(i=0; s[i]!='\0'; i++){
		ris*=2;
		ris += s[i]-'0';
	}
	return ris;
}
