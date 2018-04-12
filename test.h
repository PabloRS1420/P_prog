/**
 * @brief Defines macros to print the result of tests
 *
 * @file test.h
 * @author Profesores PProg
 * @version 1.0
 * @copyright GNU Public License
 */

#ifndef _TEST_H
#define _TEST_H

#pragma GCC diagnostic ignored "-Wpedantic"

#ifndef NOCOLOR
/**color red*/
#define KRED  "\x1B[31m"
/**color green*/
#define KGRN  "\x1B[32m"
/**color yellow*/
#define KYEL  "\x1B[33m"
/**color cyan*/
#define KCYN  "\x1B[36m"
/**reset color*/
#define RESET "\033[0m"
#else
/**color red*/
#define KRED
/**color green*/
#define KGRN
/**color yellow*/
#define KYEL
/**color cyan*/
#define KCYN
#define RESET
#endif

/**
 * @brief macro that prints the result of a test in colors.
 * @param 0 for test passed, !=0 for test not __test_passed
 */
#define PRINT_TEST_RESULT(x) do{\
    __test_counter++;\
    __pass = (x);\
    __test_passed = (__pass)? __test_passed + 1 : __test_passed;\
    printf(KYEL "%s" RESET " line "  "%d " KCYN "%s" RESET ": %s\n", \
	   __FILE__, __LINE__ , __FUNCTION__, \
	   ((!__pass) ? KRED "NOT PASS" RESET : KGRN "PASS" RESET));	\
  } while (0)

/**prints the percentage of test passed succesfully*/
#define PRINT_PASSED_PERCENTAGE printf("Tests passed %d%%\n", ((__test_passed * 100) / __test_counter))

/**counts the total number of tests*/
static int __test_counter = 0;
/**counts the number of passed tests*/
static int __test_passed  = 0;
/**is 0 if the test was passed, !=0 otherwise*/
static int __pass = 0;

#endif
