#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct {
  int x;
  int y;
} point_t;

#define IS_VALID(x, y) ((x) >= 0 && (y) >= 0 \
			 && (x) <= boardRowSize - 1 \
			 && (y) <= boardColSize - 1 \
			 && board[(x)][(y)] == 'O'  \
			 && !crawled[(x)][(y)])

point_t dir[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
point_t *queue;
int head, tail;

void crawl(point_t curr,
	   char **board, int boardRowSize, int boardColSize,
	   bool (*crawled)[boardColSize])
{
  point_t next;

  head = 0;
  tail = 0;
  queue[tail++] = curr;
  
  while (head != tail) {
    curr = queue[head++];
    for (int i = 0; i < 4; ++i) {
      next = (point_t){curr.x + dir[i].x, curr.y + dir[i].y};
      if (IS_VALID(next.x, next.y)) {
	crawled[next.x][next.y] = true;
	queue[tail++] = next;
      }
    }
  }
  
}

void solve(char** board, int boardRowSize, int boardColSize)
{
  bool (*crawled)[boardColSize] = calloc(boardRowSize*boardColSize,
					 sizeof(bool));
  queue = malloc(boardRowSize*boardColSize*sizeof(point_t)+1);

  for (int i = 0; i < boardRowSize; ++i) {
    if (board[i][0] == 'O' && !crawled[i][0]) {
      crawled[i][0] = true;
      crawl((point_t){i, 0}, board, boardRowSize, boardColSize, crawled);
    }
    if (board[i][boardColSize-1] == 'O' && !crawled[i][boardColSize-1]) {
      crawled[i][boardColSize-1] = true;
      crawl((point_t){i, boardColSize-1},
	    board, boardRowSize, boardColSize, crawled);
    }
  }

  for (int j = 0; j < boardColSize; ++j) {
    if (board[0][j] == 'O' && !crawled[0][j]) {
      crawled[0][j] = true;
      crawl((point_t){0, j}, board, boardRowSize, boardColSize, crawled);
    }
    if (board[boardRowSize-1][j] == 'O' && !crawled[boardRowSize-1][j]) {
      crawled[boardRowSize-1][j] = true;
      crawl((point_t){boardRowSize-1, j},
	    board, boardRowSize, boardColSize, crawled);
    }
  }

  for (int i = 0; i < boardRowSize; ++i) { 
    for (int j = 0; j < boardColSize; ++j) {
      if (board[i][j] == 'O' && !crawled[i][j])
    	  board[i][j] = 'X';
    }
  }

  free(crawled);
  free(queue);
}

int main(void)
{
  char s1[] = "OXXOX";
  char s2[] = "XOOXO";
  char s3[] = "XOXOX";
  char s4[] = "OXOOO";
  char s5[] = "XXOXO";

  char *s[] = {s1, s2, s3, s4, s5};
  solve(s, 5, 5);
    for (int i = 0; i < 5; ++i)
      puts(s[i]);
  return 0;
}

