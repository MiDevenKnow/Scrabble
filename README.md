# Scrabble

The aim of the game is to spell words more and higher valued words than your opponent. Each letter has a value as shown
below.
A player's score for a word is calculated by using these values. 
The words.txt file is used to validate words. 
The game begins by randomly placing 10 letters on the board. 

SCRABBLE_LETTER_VALUES = {
 'A': 1, 'B': 3, 'C': 3, 'D': 2, 'E': 1, 'F': 4, 'G': 2, 'H': 4, 'I': 1, 'J': 8, 'K': 5, 'L': 1, 'M': 3, 'N': 1, 'O': 1, 'P': 3,
'Q': 10, 'R': 1, 'S': 1, 'T': 1, 'U': 1, 'V': 4, 'W': 4, 'X': 8, 'Y': 4, 'Z': 10
}

# Rules:
1. To get a score for a word, the last letter played should start a word in any direction. This rule is
   included to simplify the game. For example, if the following letters are on the board “tao” and
   “b” is placed after “o” then the word become “boat”. i.e A words is counted if its reversed version is valid.
   
2. The players will take turns in placing a letter on the board. Each player must either place a letter
   on the board or ask to quit the game.
   
3. The game ends when there are no more empty squares on the board, or one of the player types
   'quit'.
