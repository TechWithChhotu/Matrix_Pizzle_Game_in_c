#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void rules();
void winingsituation();
void ramdom_no_in_matrix(char name[]);
int main()
{
	system("cls");//clear screen
	system("color 0E");//color 0 means black background and E means yellow text
		rules();
return 0;
}

void ramdom_no_in_matrix(char name[]){
	int mat[4][4];

		int fillrandnum[16],i,j,temp,R,moves=50;
		srand(time(0));

		for(i=0;i<16;){
			temp=rand()%16;//genrate random number and fill unique number
			for (j = 0; j < i;j++){
				if(temp==fillrandnum[j])
				break;
				}
			if(i==j){
				fillrandnum[i]=temp;
				i++;
			}

		}

		temp=0;
		for(i=0;i<4;i++){//assinge array elements in matrix 4*4
			for(j=0;j<4;j++){
				mat[i][j]=fillrandnum[temp];
				temp++;
			}
		}

    system("color 0D");

		printf("\n---------------------------------\n");
		for(i=0;i<4;i++){
			for(j=0;j<4;j++){
				if(mat[i][j]==0)
				printf("|   %c\t",mat[i][j]);
				else
				printf("|   %d\t",mat[i][j]);
			}
			printf("|\n");
		}
		printf("---------------------------------\n\n\n");


		//swap 0 to other number and after swaping print
	while(1){
		for(i=0;i<4;i++){
			for(j=0;j<4;j++){
				if(mat[i][j]==0)
				break;
			}
			if(j!=4)
			break;
		}

		char check;
		fflush(stdin);
		check=getch();

        if(check=='E'||check=='e')
            exit(0);
		if(i==3||i==2||i==1)
			if(check==80){
				mat[i][j]=mat[i-1][j];
				mat[i-1][j]=0;
				//down to top
		}

		if(i==0||i==2||i==1)
		if(check==72){
			mat[i][j]=mat[i+1][j];
			mat[i+1][j]=0;
			//top to down
		}

		if(j==0||j==1||j==2)
			if(check==75){
				mat[i][j]=mat[i][j+1];
				mat[i][j+1]=0;
				//left to right
		}

		 if(j==3||j==1||j==2)
			if(check==77){
			mat[i][j]=mat[i][j-1];
			mat[i][j-1]=0;
			//right to left
		}
		if(check==72||check==75||check==77||check==80)//press only arrow key then decrease remaining times
			moves--;

		system("cls");
		printf("hello %sremaining moves %d\n",name,moves);

		//print after swapping
		printf("\n---------------------------------\n");
		for(i=0;i<4;i++){
			for(j=0;j<4;j++){
				if(mat[i][j]==0)
				printf("|   %c\t",mat[i][j]);
				else
				printf("|   %d\t",mat[i][j]);
			}
			printf("|\n");
		}

	printf("---------------------------------\n\n\n");

		temp=1;
		for(i=0;i<4;i++){//check matrix sort or not if sort then print and exit
			for(j=0;j<4;j++){
				if(mat[i][j]==temp)
				temp++;
			}
		}

		if(temp==15){//print and exit
			printf("congratulations you are winner\n");
			exit(0);
		}
		if(moves==0){//use all remaining moves then print and exit
			printf("you are loser, try next time\n\n");
			exit(0);
		}

	}

}

void rules(){

	char name[50],choice;
	//int moves=8;
	system("cls");
	printf("Player name: ");
	fgets(name,50,stdin);
	system("cls");
	printf("\t\t\t   -:MATRIX PIZZLE:-\n\n");
	printf("\t\t\t-:RULES OF THIS GAME:-\n\n");
	printf("1. You can move only 1 step at a time by arrow key.");
	printf("\n\tMove Up  \t:\tby Up arrow key");
	printf("\n\tMove Down\t:\tby Down arrow key");
	printf("\n\tMove Left\t:\tby left arrow key");
	printf("\n\tMove Right\t:\tby Right arrow key\n");
	printf("2. You can move number at empty position only\n");
	printf("3. For each valid move: you total number of move will decreased by 1\n");
	printf("4. Wining situation : number in 4*4 matrix should be in order from 1 to 15\n");
	printf("\n\t\t\t---:Wining situation:--- ");
		winingsituation();
		    system("color 0A");
	printf("\n5. press E or e to exit.\n");
	printf("6. you can do the total number of moves 50.\n");
	printf("so try to win in minimum number of move\n\n");
	printf("press any key to start.................");
		choice=getch();
		if(choice=='E'||choice=='e')
			exit(0);
			system("cls");
				//printf(");
				printf("hello %sremaining moves 30\n",name);
			ramdom_no_in_matrix(name);//pass player name in calling function

}

void winingsituation(){

	int i;
	printf("\n---------------------------------\n");
	for( i=1;i<=15;i++){
		printf("|  %3d\t",i);
		if(i==4||i==8||i==12||i==15){
			if(i==15)
			printf("\t|\n---------------------------------\n");
			else
			printf("|\n---------------------------------\n");

		}

	}
}
