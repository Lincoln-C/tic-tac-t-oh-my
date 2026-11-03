#include <stdio.h>

// Board
char board[3][3];
const char PLAYER_1 = 'X';
const char PLAYER_2 = 'O';

void set_up_board() {
	char place = '1';

	// Iterate on rows then columns
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board[i][j] = place;
			place++; // Add one to char (ascii I think?)
		}
	}
}

void print_board() {
	printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
	printf("---|---|--- \n");
	printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
	printf("---|---|--- \n");
	printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
	printf("\n");
}

// Return 1 if taken
// Return 0 if free
int check_spot_taken(int spot) {
	// Get row and column from spot
	int row = (int) (spot - 1) / 3;
	int col = (int) (spot - 1) % 3;

	if (board[row][col] == PLAYER_1 || board[row][col] == PLAYER_2
		|| spot < 0 || spot > 9) {
		// Spot taken
		return 1;
	} else {
		return 0;
	}
}

void user_move() {
	printf("Choose a spot, any spot... (with a number): ");

	int move_place = 0;
	scanf("%i", &move_place);

	while (check_spot_taken(move_place) != 0) {
		// Bad spot
		if (move_place < 0 || move_place > 9) {
			printf("That is not a valid spot. Try again: ");
		} else {
			printf("Sorry, that spot is taken. Choose another: ");
		}

		scanf("%i", &move_place);
	}
}

// Checks to see if there is a current game winner
// Return 0 if game in play
// Return 1 if computer wins
// Return -1 if draw
// Return 2 if player wins
int check_winner() {
	return 1;
}

int main() {
	printf("Welcome to tic tac toe!\n");
	printf("The computer will go first, because I am evil >:)\n\n");
	
	set_up_board();
	print_board();

	/*while (check_winner() == 0) {
		// Get user input while game not won
		
	}*/

	user_move();
	printf("Current board:\n");
	print_board();
	
	if (check_winner() == 1) {
		printf("You got destroyed by the computer!");
	} else if (check_winner() == -1) {
		printf("It's a tie!");
	} else if (check_winner() == 2) {
		// Should never happen
		printf("Umm... I don't know how you did it, but you won?");
	}

	printf("\n"); // New line at end

	return 0; // Success
}