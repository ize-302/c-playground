#include <stdio.h>

/**
 * Given a dollars-and-cents amount
 * Calculate the new amount including tax
 * tax is at 5%
 */

int main() {
  float* amount;

  float taxPercent = 0.05f; // representing 5% i.e 5/100 in float

  printf("Enter an amount: ");

  scanf("%f", amount);

  float taxAmount = ((taxPercent) * (*amount));

  float amountWithTax = taxAmount + (*amount);

  printf("Original amount $%.2f \n", *amount);

  printf("Tax is %.0f percent of amount which is $%.2f \n", taxPercent * 100, taxAmount);

  printf("Amount with tax included: $%.2f \n", amountWithTax);
  
  return 0;
}