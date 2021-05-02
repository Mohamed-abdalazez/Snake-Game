#include <bits/stdc++.h>
#include <ctime>
//#include "conio.h"

using namespace std;

/**
 *
 * Project : Snake Game
 * author  : Mohamed Abdalazez Abdallah Mohamed
 *
**/

enum Direction
{
  top,
  bottom,
  Right,
  Left,
  Nu
};

struct gameStructue
{
  struct Grid
  {
    int height, width, targetX, targetY;
  };
  Grid g;
  struct Sanke
  {
    int topX, topY, size;
    Direction direction;
  };
  Sanke S;

  struct Player
  {
    int score;
    bool status;
  };
  Player P;
};

struct functions
{
  gameStructue opj;
  void generateMatrix()
  {
    opj.g.height = 30;
    opj.g.width = 50;
  }
  void generateTarget()
  {
    srand(time(NULL));
    opj.g.targetX = rand() % (opj.g.width - 2) + 1;
    opj.g.targetY = rand() % (opj.g.height - 2) + 1;
  }
  void generateSnake()
  {
    opj.S.topX = opj.g.width / 2;
    opj.S.topY = opj.g.height / 2;
  }
  void generatePlayer()
  {
    opj.P.score = 0;
    opj.P.status = false;
  }
  void Default()
  {
    generateMatrix();
    generateTarget();
    generateSnake();
    generatePlayer();
  }
  void draw()
  {
    system("clear");
    for (int i = 0; i < opj.g.height; i++)
    {
      for (int j = 0; j < opj.g.width; j++)
      {
        if ((i == 0 || i == opj.g.height - 1) || (j == 0 || j == opj.g.width - 1))
          printf("#");
        else if (i == opj.S.topY && j == opj.S.topX)
          printf("@");
        else if (i == opj.g.targetY && j == opj.g.targetX)
          printf("$");
        else
          printf(" ");
      }
      printf("\n");
    }
    cout << "score : " << opj.P.score << endl;
  }
  void input()
  {
    char c;
    scanf("%c", &c);
    if (c == 'w' || c == 's' || c == 'a' || c == 'd' || c == 'b')
    {
      switch (c)
      {
      case 'w':
        opj.S.direction = top;
        break;
      case 's':
        opj.S.direction = bottom;
        break;
      case 'a':
        opj.S.direction = Left;
        break;
      case 'd':
        opj.S.direction = Right;
        break;
      case 'b':
        exit(0);
      }
    }
    else
      opj.S.direction = Nu;
  }
  void movement()
  {
    switch (opj.S.direction)
    {
    case top:
      opj.S.topY--;
      break;
    case bottom:
      opj.S.topY++;
      break;
    case Left:
      opj.S.topX--;
      break;
    case Right:
      opj.S.topX++;
      break;
    }
    if (opj.S.topY >= opj.g.height || opj.S.topY <= 0 || opj.S.topX >= opj.g.width || opj.S.topX <= 0)
      exit(0);
    if (opj.S.topX == opj.g.targetX && opj.S.topY == opj.g.targetY)
    {
      generateTarget();
      opj.P.score++;
      opj.S.size++;
    }
  }
};

int main()
{
  gameStructue opj;
  functions play;
  play.Default();
  while (!opj.P.status)
  {
    play.draw();
    play.input();
    play.movement();
  }
  return 0;
}
