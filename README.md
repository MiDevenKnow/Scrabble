# Scrabble

The aim of the game is to spell more and higher valued words than your opponent. Each letter has a value as shown
below.
A player's score for a word is calculated by using these values. 
The words.txt file is used to validate words. 
The game begins by randomly placing 10 letters on the board. 

SCRABBLE_LETTER_VALUES = {
 'A': 1, 'B': 3, 'C': 3, 'D': 2, 'E': 1, 'F': 4, 'G': 2, 'H': 4, 'I': 1, 'J': 8, 'K': 5, 'L': 1, 'M': 3, 'N': 1, 'O': 1, 'P': 3,
'Q': 10, 'R': 1, 'S': 1, 'T': 1, 'U': 1, 'V': 4, 'W': 4, 'X': 8, 'Y': 4, 'Z': 10
}

# Rules:
1. To get a score for a word, the letter played must form a word that is within words.txt. A word reversed version 
   is counted if it is valid. For example, if the following letters are on the board “tao” and
   “b” is placed after “o” then the word become “boat”. Both "toab" & "boat" are checked to see if they are valid words, 
   palindromes are therefore counted twice.
   
2. The players will take turns in placing a letter on the board. Each player must either place a letter
   on the board or ask to quit the game.
   
3. The game ends when there are no more empty squares on the board, or one of the player types
   'quit'.

# Platform

This program was built on Ubuntu 20.04, for windows users uncomment the code to clear the terminal & comment the current code.

# To Play
  **On Linux:**
  
   Navigate to the project folder and type the following commands:
  
   gcc -o board board.c
  
   ./board
  
  **On Windows:**
  
   I recommned installing Dev C++, A free, portable, fast and simple C/C++ IDE.
  
   Once installed, simply open the source code file and compile and run.
  
   Remember to comment the system("clear"); lines and uncomment the system("cls"); lines.
  
   Dev C++ can be downloaded from the link below.
  
   https://sourceforge.net/projects/orwelldevcpp/
