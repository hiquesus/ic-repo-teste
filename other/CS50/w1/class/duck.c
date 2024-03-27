#include <stdio.h>

void quack(int n);

int main(void)
{
    quack(5);
}

void quack(int n)
{
    for (int i = 0; i < n; i += 1)
    {
         printf("quack\n");
    }
}


// OU  PARA LOOP (no lugar do "for...")
//
//     int i = 0;
//  while (i < 3)
//  {
//      quack();
//      i += 1;
//  }