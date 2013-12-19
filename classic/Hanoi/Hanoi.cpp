/* Hanoi
 * Author : zhitong.zhang
 * Desc   : Towers of Hanoi, A,B and C. input n, output the step number
 * Time   : 2013-12-19
 */

#include<stdio.h>
#define Move(n, from, to) {printf("Move dish %d from %c to %c\n", n, from, to);}
static int count = 0;
void Hanoi(int n, char A, char B, char C) {
  if (n == 1) {
    //printf("Move dish %d from %c to %c\n", n, A, C);
    Move(n, A, C);
    ++count;
  } else {
    Hanoi(n - 1, A, C, B);
    //printf("Move dish %d from %c to %c\n", n - 1, A, C);
    Move(n, A, C);
    ++count;
    Hanoi(n - 1, B, A, C);
  }
}
int main() {
  int n;
  printf("Input a integer : ");
  scanf("%d", &n);
  Hanoi(n, 'A', 'B', 'C');
  printf("Total step number : %d\n", count);
  return 0;
}
