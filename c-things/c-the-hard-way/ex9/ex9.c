#include <stdio.h>
#include <stdlib.h>

void char_vs_string() {

  char name[6] = { 'k', 'e', 'v', '\0', 'c'};

  printf("name as string: [%s]\n", name);
  printf("name as each character: \n");
  for (int i = 0; i < sizeof(name); i++) {
    printf("name[%d] -> %c\n", i, name[i]);
  }

  return;
}


void sizes_of_arrays() {
  int areas[] = { 10, 12, 13, 15, 19 };
  long int len_areas = sizeof(areas) / sizeof(int);

  int nums[5] = { 0 };
  long int len_nums = sizeof(nums) / sizeof(int);

  printf("size of int: %lu\n", sizeof(int));

  printf("size of areas: %lu\n", sizeof(areas));
  printf("length of areas: %ld\n", len_areas);

  printf("size of nums: %lu\n", sizeof(nums));
  printf("length of nums: %ld\n", len_nums);

  return;
}


int main() {

  // char_vs_string();
  sizes_of_arrays();

  return 0;
}
