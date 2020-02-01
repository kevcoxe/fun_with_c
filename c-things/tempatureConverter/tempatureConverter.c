
#include <stdio.h>
#include "validation.h"


double cToF(double input) {
  input = input * 9;
  input = input / 5;
  input = input + 32;
  return input;
};


double fToC(double input) {
  input = input - 32;
  input = input * 5;
  input = input / 9;
  return input;
};


int convertFtoC(double start, double end, double step) {
  if (validateInput(start, end, step) == 0) {
    printf("\nCelsius\t\t\tFahrenheit\n");
    printf("-------\t\t\t----------\n");
    for (double i = start; i <= end; i = i + step) {
      printf("%5.6f\t\t%5.6f\n", i, fToC(i));
    };
    return 0;

  } else {
    return 1;
  }
};


int convertCtoF(double start, double end, double step) {
  if (validateInput(start, end, step) == 0) {
    printf("\nCelsius\t\t\tFahrenheit\n");
    printf("-------\t\t\t----------\n");
    for (double i = start; i <= end; i = i + step) {
      printf("%5.6f\t\t%5.6f\n", i, cToF(i));
    };
    return 0;

  } else {
    return 1;
  }
};


void checkPassed(int input) {
  if (input == 0) {
    printf("PASSED\n");
  } else {
    printf("FAILED\n");
  }
};


void runTests() {
  int _start = 0;
  int _end = 0;
  int _step = 1;

  double start = (double)_start;
  double end = (double)_end;
  double step = (double)_step;

  // failure, end < start
  start = 2.00;
  end = 1.00;
  checkPassed(convertCtoF(start, end, step));

  // failure, end = start
  start = 1.00;
  end = 1.00;
  checkPassed(convertCtoF(start, end, step));

  // failure, start < 0
  start = -1.00;
  end = 2.00;
  checkPassed(convertCtoF(start, end, step));

  // failure, end > 50000
  start = 0.00;
  end = 50001.00;
  checkPassed(convertCtoF(start, end, step));

  // failure, step <= 0
  start = 0.00;
  end = 50.00;
  step = 0.00;
  checkPassed(convertCtoF(start, end, step));

  // failure, step >= end
  start = 0.00;
  end = 5.00;
  step = 5.00;
  checkPassed(convertCtoF(start, end, step));

  // success case
  start = 0.00;
  end = 10.00;
  step = 2.00;
  checkPassed(convertCtoF(start, end, step));

  // success
  start = 0.00;
  end = 5.00;
  step = 1.00;
  checkPassed(convertCtoF(start, end, step));
};


int main() {

  printf("Please give in a lower limit, limit >= 0: ");
  int _start;
  scanf("%d", &_start);

  printf("Please give in a higher limit, %d > limit <= 50000: ", _start);
  int _end;
  scanf("%d", &_end);

  printf("Please give in a step, 0 < step <= %d: ", _end);
  int _step;
  scanf("%d", &_step);

  double start = (double)_start;
  double end = (double)_end;
  double step = (double)_step;

  checkPassed(convertCtoF(start, end, step));

  return 0;
};
