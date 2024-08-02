#include <stdio.h>

/**
 * using the formula v=4/3π(r^3)
 * find the volume of a sphere given a radius value
 */

int main() {
  float* radius;
  
  printf("Enter sphere radius:\n");
  
  scanf("%f", radius);

  float pie = 3.142f;

  // represent numerator and denominator as floats
  float volume = (4.0f/3.0f) * (pie) * ((*radius) * (*radius) * (*radius));

  printf("volume of sphere: %.2f\n", volume);

  return 0;
}