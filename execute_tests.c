/**
 * @brief Main program to execute the tests of previous iterations, defined in tests.h
 *
 * @file execute_tests.c
 * @author Frederik Mayer
 * @version 1.0
 * @date 04-04-18
 * @copyright GNU Public License
 */

#include "../include/tests.h"


int main (int argc, char** argv) {
  int test = 0;
  int all = 1;
  if (argc < 2) {
    printf("Executing all tests:\n");
  }
  else{
    test = atoi(argv[1]);
    all = 0;
    printf("Passing test %d:\n", test);
    if(test < 1 || test > MAX_TEST) {
      printf("Error: not recognized test.\n");
      exit(EXIT_SUCCESS);
    }
  }

  if (all || test == 1) test1_set_test();
  if (all || test == 2) test2_dice_test();

  return 0;
}
