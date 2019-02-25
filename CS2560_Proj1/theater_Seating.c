/*
 * theater_Seating.c
 *
 *  Created on: Feb 18, 2019
 *      Author: jianchaosun
 */


#include <stdio.h>

float earn =0;
int numSold =0;
int totalSeat = 450;
int seatsInRow[16];
float price[16];
void printSeat(char x[16][31]){
	printf("        ");
	for(int n=0;n<3;n++){
	for(int i=1;i<10;i++){
		printf("%d ",i);
	}
	printf("%d ",0);
	}
	printf("\n");
	for(int i=1;i<16;i++){
		if(i<10){
			printf("Row %d   ",i);
		}else{
		printf("Row %d  ",i);
		}
		for(int j =1;j<31;j++){

			printf("%c ", x[i][j]);
		}
	printf("\n");
	}

}

int isAvailable(char x[16][31],int row,int col){
	if(x[row][col] =='#'){
		return 1;
	}
		return 0;
}
void displayData(char x[16][31]){
	int choice =0;
	int c2;
	int stop =0;
	while(!stop){
	printf("1.how many seats have been sold\n 2.how many seats are available in each row\n 3.and how many seats are available in the entire auditorium.\n4.Show seats graph\n5Quit viewing data");
	scanf("%d",&choice);
	switch(choice){
	case 1:
		printf("Number of seats being sold: %d\n",numSold);
		break;
	case 2:
		printf("Enter row you are looking for: \n");
		scanf("%d",&c2);
		printf("The number of available seats on selected row is: %d\n ",seatsInRow[c2]);
		break;
	case 3:
		printf("The seats are available is: %d\n",totalSeat);
		break;
	case 4:
		printSeat(x);
		break;
	case 5:
		stop = 1;
		break;
	}
	}
}


void Sold(char x[16][31]){
	int row =0;
	int col =0;
	int true = 1;
	while(true){

		printf("Enter row and column of your desire seat: (Enter 0 to quit)");
		scanf("%d %d",&row,&col);
		if(row == 0){
			true = 0;
		}
		if(row>=16||col>=31){
			printf("Input row should be less than 16, Input column should be less than 31");
		}
		if(isAvailable(x,row,col)){
			x[row][col] = '*';
			numSold++;
			totalSeat--;
			earn +=price[row];
			seatsInRow[row]--;
			printf("Current total Price is: %0.1f\n",earn);
		}else{
			printf("the seat is taken\n");
		}
		int c=0;
		printf("Do you want to see Data of theater? 1.Yes 2.No\n");
		scanf("%d",&c);
		if(c == 1){
			displayData(x);
		}

	}
}

int main(){
	static char seats[16][31]; //skip 0 row and 0 column,will be used to notate the number of row or column
	for(int i=1;i<16;i++){
		seatsInRow[i] = 30;
	}
	for(int i =1;i<16;i++){
		for(int j =1;j<31;j++){
			seats[i][j] = '#';
		}
	}
	for(int i=1;i<16;i++){
	printf("Enter price for each row %d\n",i);
	scanf("%f",&price[i]);
	}
	printSeat(seats);
    Sold(seats);
	printSeat(seats);

}
