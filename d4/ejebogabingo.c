#include<stdio.h>
#include<stdlib.h>
#define DIM 5
#define FILE_NAME "input.txt"

typedef struct{
	int num[DIM][DIM];
	int isCalled[DIM][DIM];
} bingoTable_t;

void boardWin(bingoTable_t a, int numbers[], int num, int *lastNum, int *res);
int checkWin(bingoTable_t table);

int main(){
	bingoTable_t table;
	int i, count, j, *numbers, result, numPos, ris, min;
	char tmp;
	FILE *fp;
	fp=fopen(FILE_NAME, "r");
	tmp=' ';
	numbers=NULL;
	count=0;
	if(fp){
		while(fscanf(fp, "%d%c", &j, &tmp)>0 && tmp!='\n'){
			count++;
		}
		count++;
		numbers=malloc(sizeof(int) * (count+1));
		rewind(fp);
		count=0;
		ris=0;
		min=1000;
		if(numbers){
			while(fscanf(fp, "%d%c", (numbers+count), &tmp)>0 && tmp!='\n'){
				count++;
			}
			count++;

			i=0;
			j=0;
			while(fscanf(fp, "%d%c", &table.num[i][j], &tmp)>0){
				table.isCalled[i][j]=0;
				j++;
				if(!(j<DIM)){
					j=0;
					i++;
				}                                                                                       //koje pravio stringove ovdi bukvalnbo umrimrs
				if(i==5 && tmp=='\n'){
					boardWin(table, numbers, count, &numPos, &result);
					if(min > numPos && numPos!=0){
						ris=result;
						min=numPos;
					}
					i=0;
					j=0;
				}
			}
			printf("Result: %d\n", ris);

		}else
			printf("Error Malloc...");

	}
	return 0;
}

void boardWin(bingoTable_t a, int numbers[], int num, int *lastNum, int *res){
	int i, j, count;
	*res=0;
//pravilapravila
	for(count=0; count<num && !*res; count++){
		for(i=0; i<DIM; i++){
			for(j=0; j<DIM; j++){
				if(a.num[i][j]==numbers[count])
					a.isCalled[i][j]=1;
			}
		}
		*res = checkWin(a);
		if(*res)
			count--;
	}

	if(*res){
		*lastNum = count;
		*res=0;
		for(i=0; i<DIM; i++){
			for(j=0; j<DIM; j++){
				if(a.isCalled[i][j]==0){
					*res+=a.num[i][j];
				}
			}
		}
		(*res)*=numbers[count];
	}
	return;
}

int checkWin(bingoTable_t table){ //jebogabingogajeboga mrs 
	int ris, i, j;
	ris=0;

	for(i=0; i<DIM && !ris; i++){
		for(j=0; j<DIM && !ris; j++){
			if(table.isCalled[i][0]==1 && table.isCalled[i][1]==1 && table.isCalled[i][2]==1 && table.isCalled[i][3]==1 
					&& table.isCalled[i][4]==1){
				ris=1;
			}
			
			if(table.isCalled[0][j]==1 && table.isCalled[1][j]==1 && table.isCalled[2][j]==1 && table.isCalled[3][j]==1
					&& table.isCalled[4][j]==1)
				ris=1;
		}
	}

	return ris;
} //necu vise mrs upucaitese
