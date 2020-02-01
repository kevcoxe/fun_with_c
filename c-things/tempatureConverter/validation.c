
#include <stdio.h>

int validateInput(double start, double end, double step) {
  if (end <= start) {
    printf("INVALID: end must be greater than start\n");
    return 1;

  } else if (start < 0) {
    printf("INVALID: start must be greater than equal to 0\n");
    return 1;

  } else if (end > 50000) {
    printf("INVALID: end must be less than equal to 50000\n");
    return 1;

  } else if (step <= 0.00) {
    printf("INVALID: step must be greater than 0.00\n");
    return 1;

  } else if (step > end) {
    printf("INVALID: step must be less than end\n");
    return 1;

  } else {
    return 0;
  };
};

