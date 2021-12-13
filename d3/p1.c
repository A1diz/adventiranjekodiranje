#include<stdio.h>
#define DIM 12
int pretvori(long numBin);

int main(){
	long gammaRate, epsilonRate; //?
	int num1[DIM], num0[DIM], i;
	char s[DIM+1];
	FILE *fp;
	fp = fopen("input.txt", "r");
	
	for(i=0; i<DIM; i++){
		num1[i]=0;
		num0[i]=0;
	}
	gammaRate=0;  //valjda
	epsilonRate=0;

	if(fp){
		while(fscanf(fp, "%s ", s) > 0){
			for(i=0; s[i]!='\0'; i++){
				if(s[i] == '1')
					num1[i]++;
				else
					num0[i]++;
			}		
		}

		for(i=0; i<DIM; i++){
			if(num1[i]>num0[i]){
				gammaRate+=1;
			}else{
				epsilonRate+=1;
			}
			epsilonRate*=10;
			gammaRate*=10;
			printf("Gamma: %ld \n num1 %d -- num0 %d\n", gammaRate, num1[i], num0[i]);
		}
		printf("\n\nS\n\n");
		gammaRate = pretvori(gammaRate);
		epsilonRate = pretvori(epsilonRate);
		printf("Gamma: %ld, Epsilon: %ld \n", gammaRate, epsilonRate);
		printf("ispane: %ld \n", (gammaRate * epsilonRate));
		fclose(fp);
	}else{
		printf("nece \n");
	}

	return 0;
}

int pretvori(long numBin){ //fala kriptopalu
	int ris, p;
	ris = 0;
	p = 1;
	printf("binarno %ld \n", numBin);
	while(numBin>0){
		ris += (numBin - (numBin/10 * 10)) * p;
		p*=2;
		numBin/=10;
	}
	
	return ris/2;
}
