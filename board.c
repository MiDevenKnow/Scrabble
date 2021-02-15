#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>


int k,j;
int const NUM_RANGE=8;
int player1 =0, player2 =0;
int moves =0;

int main(){

	char *grid[NUM_RANGE][NUM_RANGE];

	char player1_Words[100][30];
	char player2_Words[100][30];
	
	int player1_Words_Score[100];
	int player2_Words_Score[100];

	int player1_count = 0;
	int player2_count = 0;

	// Compares the scores of both players. The outcome of said scores are printed. Returns void
	void winner(){
		printf("\nPlayer 1 points: %d",player1);
		printf("\nPlayer 2 points: %d\n",player2);

		if(player1>player2){
			printf("\n\t====================================");
			printf("\n\t-------PLAYER 1 IS THE WINNER-------");
			printf("\n\t====================================\n\n");
		}

		if(player2>player1){
			printf("\n\t====================================");
			printf("\n\t-------PLAYER 2 IS THE WINNER-------");
			printf("\n\t====================================\n\n");
		}

		if(player2==player1){
			printf("\n\t=========================");
			printf("\n\t-------IT'S A DRAW-------");
			printf("\n\t=========================\n\n");
		}
		printf("Thank you for playing my scrabble game! :v\n");
	}

	// Accepts the x and y coordinates as int and the letter as a string literal. The letter is place within the given location. Returns void
	void makePlay(int x, int y,char *c){
		//Arrays are zero indexed but our grid starts at index 1
		grid[x-1][y-1]=c;
		return;
	}

	// Creates the 8x8 grid. Returns void
	void getNewBoard(){
		for (j = 0; j < NUM_RANGE; j++){
			for (k = 0; k < NUM_RANGE; k++){
					grid[k][j]="   ";
				}
			}
		return;
	}

	// Prints out the board that was passed. Returns void
	void drawBoard(){
		char * const NLINE = "    1    2    3    4    5    6    7    8";
		char * const HLINE = "  +----+----+----+----+----+----+----+----+";
		char * const VLINE = "  |    |    |    |    |    |    |    |    |";

		printf("%s\n",NLINE);
		printf("%s\n",HLINE);
		for (j = 0; j < NUM_RANGE; j++){  
			printf("%s\n",VLINE);
			printf("%d ",j+1);
			for (k = 0; k < NUM_RANGE; k++){
				if(strcmp(grid[k][j],"   ")==0){
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
	}

	// Accepts the x and y coordinates as int. Returns 1 if the given location is empty, 0 otherwise.
	int isEmpty(int x, int y){
		if(strcmp(grid[x-1][y-1],"   ")==0){
			return 1;
		}
		return 0;
	}

	// Accepts a character as char. Returns 1 if the given character is a letter, 0 otherwise.
	int isLetter(char c){
		if(c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z'){
			return 1;
		}
		return 0;
	}

	/* Accepts a word as a char pointer and calculate the score for that word based on the dictionary like structure that holds the letter values.
	   Returns the score for the word as an int */
	int calculateScore(char * word){
		int score = 0;
		int i,x;
		int values[26][2]={{'a',1},{'b',3},{'c',3},{'d',2},{'e',1},{'f',4},{'g',2},{'h',4},
						{'i',1},{'j',8},{'k',5},{'l',1},{'m',3},{'n',1},{'o',1},{'p',3},
						{'q',10},{'r',1},{'s',1},{'t',1},{'u',1},{'v',4},{'w',4},{'x',8},
						{'y',4},{'z',10}};
						
		for(i=0;i<strlen(word);i++){
			for(x=0;x<26;x++){
				if(tolower(word[i])==(char)values[x][0]){
					score+=values[x][1];
					break;
				}
			}
		}
		return score;
	}

	// Accepts the x and y coordinates as char. Returns 1 if both are valid locations on the board, 0 otherwise
	int areDigits(char x, char y){
		if(x >='1' && x<='8' && y>='1' && y<='8'){
			return 1;
		}
		return 0;
	}

	/* Accepts the x and y coordinates as int and the letter as char. 
	   Given the character, its string literal version along with the coordinates is passed into makePlay(int x, int y, char *s).
	   Returns void. */
	void passString(int x,int y,char c){
		if(c=='a'){
			makePlay(x,y,"a");
		}
		if(c=='b'){
			makePlay(x,y,"b");
		}
			if(c=='c'){
			makePlay(x,y,"c");
		}
		if(c=='d'){
			makePlay(x,y,"d");
		}
		if(c=='e'){
			makePlay(x,y,"e");
		}
		if(c=='f'){
			makePlay(x,y,"f");
		}
		if(c=='g'){
			makePlay(x,y,"g");
		}
		if(c=='h'){
			makePlay(x,y,"h");
		}
		if(c=='i'){
			makePlay(x,y,"i");
		}
		if(c=='j'){
			makePlay(x,y,"j");
		}
		if(c=='k'){
			makePlay(x,y,"k");
		}
		if(c=='l'){
			makePlay(x,y,"l");
		}
		if(c=='m'){
			makePlay(x,y,"m");
		}
		if(c=='n'){
			makePlay(x,y,"n");
		}
		if(c=='o'){
			makePlay(x,y,"o");
		}
		if(c=='p'){
			makePlay(x,y,"p");
		}
		if(c=='q'){
			makePlay(x,y,"q");
		}
		if(c=='r'){
			makePlay(x,y,"r");
		}
		if(c=='s'){
			makePlay(x,y,"s");
		}
		if(c=='t'){
			makePlay(x,y,"t");
		}
		if(c=='u'){
			makePlay(x,y,"u");
		}
		if(c=='v'){
			makePlay(x,y,"v");
		}
		if(c=='w'){
			makePlay(x,y,"w");
		}
		if(c=='x'){
			makePlay(x,y,"x");
		}
		if(c=='y'){
			makePlay(x,y,"y");
		}
		if(c=='z'){
			makePlay(x,y,"z");
		}
	}

	/* Implements the players' input functionalities. 
	   This functions request that the user enter a letter or the word 'quit' to exit the game.
	   If a letter is enter, the user is then prompt the enter the x and y coordinates to place their letter.
	   If any erronous data is entered (invalid data type/ invalid location). The user is prompt again until 
	   valid data is entered or a keyboard-interrupt is triggered. Returns void*/
	int* getPlayerMove(){
		char ans[100];
		char coordinates[100];

		do{
			printf("Enter a letter or 'quit' to exit the game\n");
			fgets(ans,100,stdin); //Store every key with an ascii value that is pressed and inputted (<enter> is stored)
			
			if(strcmp(ans,"quit\n")==0){
				system("clear");
				// system("cls"); For windows devices
				winner();
				exit(0);
			}
		}while(strlen(ans)!=2 || isLetter(ans[0])!=1);
		
		do{
			printf("Enter the x and y coordinates, 1-8 inclusive (eg.74)\n");
			fgets(coordinates,100,stdin);	

		}while(strlen(coordinates)!=3 || areDigits(coordinates[0],coordinates[1]) != 1 || isEmpty(coordinates[0] - 48,coordinates[1] - 48)!=1);
		
		int x = coordinates[0] - 48;
		int y = coordinates[1] - 48;

		char lower = tolower(ans[0]);
		passString(x,y,lower); 

		int arr[] = {x,y};
		return (int*){arr};
	}

	// Accepts the x and y coordinates as int. Returns 1 if the given location is on the board, 0 otherwise.
	int isOnBoard(int x, int y){
		if(x>=1 && x<=8 && y>=1 && y<=8){
			return 1;
		}
		return 0;
	}

	// Generates 10 random letters and place them in 10 random locations. Returns void.
	void startBoard(){
		printf("\n\t==================================");
		printf("\n\t-------LET'S PLAY SCRABBLE!-------");
		printf("\n\t==================================\n\n");
		int i,letters[10];
		for(i=0;i<10;i++){
			letters[i] = (rand() % (123-97))+97;
		}

		i=0;
		while(i<=9){
			int x = (rand() % (9-1))+1;
			int y = (rand() % (9-1))+1;

			if(isEmpty(x,y)==1 && isOnBoard(x,y)==1){
				passString(x,y,(char)letters[i]);
				i++;
			}
		}
	}

	// Given a word, Returns 1 if its within words.txt (the word bank), 0 otherwise.
	int isValid(char *txt){
		FILE *words;
		char str[100];
		char str1[100]={'\0'};
		int i;
		int j=0;
		words = fopen("words.txt","r");
		while((fgets(str,100,words))!=NULL){

			for(i=0;i<=strlen(str);i++){
				if(i==strlen(str)-1){	//used to avoid capturing '\n' when using fgets, so we go one less the length
					continue;
				}else{
					if(str[i]>=65 && str[i]<=90){
						str1[i]=str[i]+32;
					}else{
						str1[i]=str[i];
					}
				}
			}

			if(strcmp(str1,txt)==0){
				return 1;
			}
			memset(str1,0,strlen(str1)); //used to empty string
		}
		return 0;
	}

	// Accepts as a string, Returns its reversed version.
	char* strrev(char*s){
		char r[100];
		int count = strlen(s);
		int begin,end;

		end = count-1;
		for(begin=0;begin<count;begin++){
			r[begin]=s[end];
			end--;
		}
		r[begin]='\0';
		return (char*){r};
	}

	/* Accepts the x and y coordinates as int.
	   By comparing positions on the same y-axis, the function finds the letters that are horizontally adjacent
	   to the given location. When a location with an empty space is encountered on either end, the string is built.
	   Returns the horizontal string built with respect to the given location, from left to right.
	   eg. 'b' in position 11, 'o' - 21, 'a' - 31, now if a letter say 't' is placed in position 41
	   The string "boat" is return
	*/
	char* horizontal(int x,int y){
		int x1 = x;
		int y1 = y;
		char str[100]={'\0'};
		int i;
		for(i=0;i<8;i++){ //Forwards
			if(isOnBoard(x1,y1)==0){
				break;
			}
			else if(isEmpty(x1,y1)==1){
				break;
			}else{
				char ch = *grid[x1-1][y1-1];
				x1++;
				strncat(str,&ch,1);
				
			}
		}

		x1 = x-1;
		y1 = y;
		int c;

		for(i=0;i<8;i++){ //Backwards
			if(isOnBoard(x1,y1)==0){
				break;
			}
			else if(isEmpty(x1,y1)==1){
				break;
			}else{
				char ch = *grid[x1-1][y1-1];
				for (c = strlen(str) - 1; c >= 0; c--){
					str[c+1] = str[c];
				}
				str[0] = ch;
				x1--;
			}
		}
		return (char*){str};
	}

	/* Accepts the x and y coordinates as int.
	   By comparing positions on the same x-axis, the function finds the letters that are vertically adjacent
	   to the given location. When a location with an empty space is encountered on either end, the string is built.
	   Returns the vertical string built with respect to the given location, from up to down.
	   eg. 'b' in position 11, 'o' - 12, 'a' - 13, now if a letter say 't' is placed in position 14
	   The string "boat" is return.
	*/
	char* vertical(int x, int y){
		int x1 = x;
		int y1 = y;
		char str[100]={'\0'};
		int i;
		for(i=0;i<8;i++){ //Downwards
			if(isOnBoard(x1,y1)==0){
				break;
			}
			else if(isEmpty(x1,y1)==1){
				break;
			}else{
				char ch = *grid[x1-1][y1-1];
				y1++;
				strncat(str,&ch,1);
				
			}
		}

		x1 = x;
		y1 = y-1;
		int c;

		for(i=0;i<8;i++){ //Backwards
			if(isOnBoard(x1,y1)==0){
				break;
			}
			else if(isEmpty(x1,y1)==1){
				break;
			}else{
				char ch = *grid[x1-1][y1-1];
				for (c = strlen(str) - 1; c >= 0; c--){
					str[c+1] = str[c];
				}
				str[0] = ch;
				y1--;
			}
		}
		return (char*){str};
	}

	/* Implements the scrabble game play. Given 10 letters are placed on the game at the start,
	   only 54 moves are left. The gam ends when the grid is filled i.e all 54 moves are played
	   or a player enters 'quit'. This functions call numerous functions to calculate each player score,
	   to store each word along with their value and prints them, to validate words and to check if a string 
	   is valid reversed. Returns void */
	void playGame(){
		printf("\n====================================");
		printf("\n-------PRESS <ENTER> TO START-------");
		printf("\n====================================");
		getchar();

		while (1){
			if(moves==54){
				system("clear");
				// system("cls"); For windows devices
				drawBoard();
				winner();
				break;
			}
								// Even number symbolizes player 1
			else if(moves%2==0){
				system("clear");
				// system("cls"); For windows devices
				printf("\t==================================");
				printf("\n\t-------PLAYER 1 | SCORE: %d -------",player1);
				printf("\n\n\tWORDS PLAYED: \n\n");
				int j;
				for(j=0;j<player1_count;j++){
					printf("\t%s | %d points\n",player1_Words[j],player1_Words_Score[j]);
				}
				printf("\t==================================\n\n");

				drawBoard();
				printf("\n\n");

				int *pos = getPlayerMove();
				int x = pos[0];
				int y = pos[1];

				char horizontal_for[100];
				char horizontal_rev[100];

				char vertical_for[100];
				char vertical_rev[100];

				strcpy(horizontal_for, (char*){horizontal(x,y)});
				strcpy(horizontal_rev, (char*){strrev(horizontal_for)});

				strcpy(vertical_for, (char*){vertical(x,y)});
				strcpy(vertical_rev, (char*){strrev(vertical_for)});

				if(isValid(horizontal_for)==1){
					strcpy(player1_Words[player1_count], (char*){horizontal_for});

					int score = calculateScore(horizontal_for);

					player1_Words_Score[player1_count] = score;
					player1 += score;
					player1_count++;
				}

				if(isValid(horizontal_rev)==1){
					strcpy(player1_Words[player1_count], (char*){horizontal_rev});

					int score = calculateScore(horizontal_rev);

					player1_Words_Score[player1_count] = score;
					player1 += score;
					player1_count++;
				}

				if(isValid(vertical_for)==1){
					strcpy(player1_Words[player1_count], (char*){vertical_for});

					int score = calculateScore(vertical_for);

					player1_Words_Score[player1_count] = score;
					player1 += score;
					player1_count++;
				}

				if(isValid(vertical_rev)==1){
					strcpy(player1_Words[player1_count], (char*){vertical_rev});

					int score = calculateScore(vertical_rev);

					player1_Words_Score[player1_count] = score;
					player1 += score;
					player1_count++;
				}
				moves++;
			}
					// Odd number symbolizes player 2
			else{
				system("clear");
				// system("cls"); For windows devices
				printf("\t==================================");
				printf("\n\t-------PLAYER 2 | SCORE: %d -------",player2);
				printf("\n\n\tWORDS PLAYED: \n\n");
				int j;
				for(j=0;j<player2_count;j++){
					printf("\t%s | %d points\n",player2_Words[j],player2_Words_Score[j]);
				}
				printf("\t==================================\n\n");

				drawBoard();
				printf("\n\n");

				int *pos = getPlayerMove();
				int x = pos[0];
				int y = pos[1];

				char horizontal_for[100];
				char horizontal_rev[100];

				char vertical_for[100];
				char vertical_rev[100];

				strcpy(horizontal_for, (char*){horizontal(x,y)});
				strcpy(horizontal_rev, (char*){strrev(horizontal_for)});

				strcpy(vertical_for, (char*){vertical(x,y)});
				strcpy(vertical_rev, (char*){strrev(vertical_for)});

				if(isValid(horizontal_for)==1){
					strcpy(player2_Words[player2_count], (char*){horizontal_for});

					int score = calculateScore(horizontal_for);

					player2_Words_Score[player2_count] = score;
					player2 += score;
					player2_count++;
				}

				if(isValid(horizontal_rev)==1){
					strcpy(player2_Words[player2_count], (char*){horizontal_rev});

					int score = calculateScore(horizontal_rev);

					player2_Words_Score[player2_count] = score;
					player2 += score;
					player2_count++;
				}

				if(isValid(vertical_for)==1){
					strcpy(player2_Words[player2_count], (char*){vertical_for});

					int score = calculateScore(vertical_for);

					player2_Words_Score[player2_count] = score;
					player2 += score;
					player2_count++;
				}

				if(isValid(vertical_rev)==1){
					strcpy(player2_Words[player2_count], (char*){vertical_rev});

					int score = calculateScore(vertical_rev);

					player2_Words_Score[player2_count] = score;
					player2 += score;
					player2_count++;
				}
				moves++;
			}
		}
	}

	srand(time(0));

    getNewBoard();

	startBoard();

	drawBoard();

	playGame();

	return 0;
}