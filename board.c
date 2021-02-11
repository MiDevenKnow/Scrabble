#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(){

int k,j;
int const NUM_RANGE=8;
//global declaration structure grid
char *grid[NUM_RANGE][NUM_RANGE];

void getNewBoard(){
    //creates a brand new blank board. Returns a pointer to the array 
    for (j = 0; j < NUM_RANGE; j++){
        for (k = 0; k < NUM_RANGE; k++){
                grid[k][j]="   ";
            }//Endfor
        }//Endfor
    return;
}//EndFunction getNewBoard

void drawBoard(){
    //This function prints out the board that was passed. Returns void
    char * const NLINE = "    1    2    3    4    5    6    7    8";
    char * const HLINE = "  +----+----+----+----+----+----+----+----+";
    char * const VLINE = "  |    |    |    |    |    |    |    |    |";

    printf("%s\n",NLINE);
    printf("%s\n",HLINE);
    for (j = 0; j < NUM_RANGE; j++)
    {  
        printf("%s\n",VLINE);
        printf("%d ",j+1);
        for (k = 0; k < NUM_RANGE; k++)
        {  if(strcmp(grid[k][j],"   ")==0){
                printf("| %s",grid[k][j]);
            }else{
                printf("| %s  ",grid[k][j]);
            }
        }
        printf("%s","|");
        printf("\n");
        printf("%s\n",VLINE);
        printf("%s\n",HLINE);
    }
    return;
}//EndFunction drawBoard

   
void makePlay(int x, int y, char *c){
   //Arrays are zero indexed but our grid starts at index 1
   grid[x-1][y-1]=c;
   return;
}

int isEmpty(int x, int y){
	if(strcmp(grid[x-1][y-1],"   ")==0){
		return 1;
	}
	return 0;
}

//Paramter takes in string
//cast it as a character to compare
int isLetter(char c){

	if(c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z'){
		return 1;
	}
	return 0;
}

int calculateScore(char * word){
	int score = 0;
	int i,x;
	int values[26][2]={{'a',1},{'b',3},{'c',3},{'d',2},{'e',1},{'f',4},{'g',2},{'h',4},
					   {'i',1},{'j',8},{'k',5},{'l',1},{'m',3},{'n',1},{'o',1},{'p',3},
					   {'q',10},{'r',1},{'s',1},{'t',1},{'u',1},{'v',4},{'w',4},{'x',8},
					   {'y',4},{'z',10}};
					   
	for(i=0;i<strlen(word);i++){
		for(x=0;x<26;x++){
			if(word[i]==(char)values[x][0]){
				score+=values[x][1];
				break;
			}
		}
	}
	return score;
}

int areDigits(char x, char y){
	if(x >='1' && x<='8' && y>='1' && y<='8'){
		return 1;
	}
	return 0;
}
void getPlayerMove(){
	char ans[100];
	char coordinates[100];
	
	do{
		printf("Enter a letter or 'quit' to exit the game\n");
		fgets(ans,100,stdin); //Store every key with an ascii value that is pressed and inputted (<enter> is stored)
        
		if(strcmp(ans,"quit\n")==0){
			printf("Thank you for playing my scrabble game");
			exit(0);
		}
	}while(strlen(ans)!=2 || isLetter(ans[0])!=1);
	
	do{
		printf("Enter the x and y coordinates, 1-8 inclusive (eg.74)\n");
		fgets(coordinates,100,stdin);	
	}while(strlen(coordinates)!=3 || areDigits(coordinates[0],coordinates[1]) != 1);
	
	int x = coordinates[0] - 48;
	int y = coordinates[1] - 48;
	char letter[2] = {ans[0]};
	printf("PAUL WAS HERE %s",letter);
	makePlay(x,y,letter);
}
	
    getNewBoard();
    drawBoard();
    //notice the use of spaces
    makePlay(3,7,"a");    
    makePlay(4,5,"b"); 
	getPlayerMove();
    drawBoard();

    



    return 0;
}
