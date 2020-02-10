#include <stdio.h>


int fail_case() {

  goto fail;

  fail:
    return 1;

  return 0;
}


/* This is a comment. */
int main(int argc, char *argv[]) {
  int distance = 100;

  // this is also a comment
  printf("You are %d miles away.\n", distance);

  int failed;
  failed = fail_case();

  printf("failed response: %d\n", failed);

  int bugs = 100;
  double bug_rate = 1.2;
  long universe_of_defects = 1L * 1024L * 1024L * 1024L;
  printf("the entire universe has %ld bugs.\n", universe_of_defects);

  double expected_bugs = bugs * bug_rate;
  printf("You are expected to have %f bugs.\n", expected_bugs);

  double part_of_universe = expected_bugs / universe_of_defects;
  printf("That is only a %e portion of the universe\n", part_of_universe);

  char null_byte = '\0';
  int care_percentage = bugs * null_byte;
  printf("Which means you should care %d%%.\n", care_percentage);


  return 0;
}

