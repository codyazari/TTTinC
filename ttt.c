#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#define WIDTH 3
#define HEIGHT 3

bool board[WIDTH][HEIGHT];

/*
** Create a an array or struct with the win conditions as coordinates.
** I can then use the win conditions to check for the same mark in each square
** then game loop will be (while != win_condition {...})
*/

typedef struct {
    bool move; // x is true, o is false
    int x_coord;
    int y_coord;
} Player;

void show_board(void)
{
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            printf("%d ", board[i][j]);
            if (j == (HEIGHT - 1)) {
                printf("\n");
            }
        }
    }
}

void place_mark(Player turn)
{
    if (turn.move == true) {
        board[turn.x_coord][turn.y_coord] = true;
    } else if (turn.move == false) {
        board[turn.x_coord][turn.y_coord] = false;
    }
}

void player_turn(Player turn)
{
    if (turn.move == true) {
        printf("Place your x somewhere on the board (x, y): \n");
        scanf("%d %d", &turn.x_coord, &turn.y_coord);
        assert(turn.x_coord >= 0 && turn.y_coord >= 0);
        assert(turn.x_coord <= (WIDTH - 1) && turn.y_coord <= (HEIGHT - 1));
        place_mark(turn);
    } else if (turn.move == false) {
        printf("Place your o somewhere on the board (x, y): ");
        scanf("%d %d", &turn.x_coord, &turn.y_coord);
        assert(turn.x_coord >= 0 && turn.y_coord >= 0);
        assert(turn.x_coord <= (WIDTH - 1) && turn.y_coord <= (HEIGHT - 1));
        place_mark(turn);
    }
}

int main (void)
{
    Player x = {true, 0, 0};
    Player o = {false, 0, 0};

    player_turn(x);
    player_turn(o);

    show_board();

    return 0;
}
