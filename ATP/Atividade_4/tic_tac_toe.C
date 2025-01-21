#include <stdio.h>

void display_matrix(int board[3][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j ++) {
      printf("%d ", board[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

void display_board(int board[3][3]) {
  printf("\n     0 | 1 | 2\n\n");
  for (int i = 0; i < 3; i++) {
    printf("%d   ", i);

    for (int j = 0; j < 3; j++) {

      switch (board[i][j]) {
        case 0: printf("   "); break;
        case 1: printf(" X "); break;
        case 2: printf(" O "); break;
      }
      if (j < 2) printf("|");
    }
    if (i < 2) printf("\n--  ---|---|---\n");
  }
  printf("\n\n");
}

void swapTurn(int *turn) {
  if (*turn == 1) *turn = 2;
  else *turn = 1;
}

int play_is_valid(int board[3][3], int i, int j) {
  if (i < 0 || i > 3) return 0;
  if (j < 0 || j > 3) return 0;
  if (board[i][j] != 0) return 0;

  return 1;
}

int is_win(int board[3][3], int turn) {
  // display_matrix(board);

  for (int n = 0; n < 3; n++) {
    // verifica as linhas
    if (board[n][0] == board[n][1] && board[n][1] == board[n][2] && board[n][2] == turn) return 1;
    
    // verifica as colunas
    if (board[0][n] == board[1][n] && board[1][n] == board[2][n] && board[2][n] == turn) return 1;
  }

  // diagonal 1
  if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == turn) return 1;

  // diagonal 2
  if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0] == turn) return 1;

  return 0;
}

int is_draw(int board[3][3]) {
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      if (board[i][j] == 0) return 0;
  
  return 1;
}

int init_game(int board[3][3]) {
  int winner = 0,
      turn = 1,
      i, j;

  while (winner == 0) {
    printf("\nVez do jogador %d\n", turn);
    display_board(board);

    printf("\nOnde deseja jogar? ");
    scanf("%d %d", &i, &j);

    if (play_is_valid(board, i, j) == 0)
      printf("\n\nJogada invalida.\n\n");

    else {
      board[i][j] = turn;

      if (is_win(board, turn) == 1) {
        display_board(board);
        printf("\nJogador %d venceu o jogo.\n", turn);
        winner = turn;
      }

      if (is_draw(board) == 1) {
        display_board(board);
        printf("Jogo empatou.");
        winner = turn;
      };

      swapTurn(&turn);
    }
  }

  return winner;
}

int main() {
  int board[3][3] = {
    { 0, 0, 0 },
    { 0, 0, 0 },
    { 0, 0, 0 },
  };

  init_game(board);
  
  return 0;
}
