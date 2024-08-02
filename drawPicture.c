#include <stdio.h>

int main()
{
  for (int row = 0; row < 6; row++)
  {
    for (int col = 0; col < 8; col++) {
      // at first row
      if (row == 0) {
        if (col == 7) {
          printf("*");
        } else {
          printf(" ");
        }
      }
      // at second row
      if (row == 1) {
        if(col == 6) {
          printf("*");
        } else {
          printf(" ");
        }
      }
      // at third row
      if (row == 2) {
        if(col == 5) {
          printf("*");
        } else {
          printf(" ");
        }
      }
      // at fourth row
      if (row == 3) {
        if(col == 4 || col == 0) {
          printf("*");
        } else {
          printf(" ");
        }
      }
      // at fifth row
      if (row == 4) {
        if(col == 3 || col == 1) {
          printf("*");
        } else {
          printf(" ");
        }
      }
      // at sixth row
      if (row == 5) {
        if(col == 2) {
          printf("*");
        } else {
          printf(" ");
        }
      }
    }
    printf("\n");
  }
  
  return 0;
}