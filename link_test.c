/*
 * @brief It declares the tests for the link module
 *
 * @file link_test.h
 * @author Profesores Pprog
 * @version 2.0
 * @date 19-01-2016
 * @copyright GNU Public License
 */

#include "../include/link_test.h"


/**
 * @brief Main function for link unit tests.
 *
 * You may execute ALL or a SINGLE test
 *   1.- No parameter -> ALL test are executed
 *   2.- A number means a particular test (the one identified by that number)
 *       is executed
 *
 */
int main(int argc, char** argv) {

    int test = 0;
    int all = 1;

    if (argc < 2) {
        printf("Running all test for module link:\n");
    } else {
        test = atoi(argv[1]);
        all = 0;
        printf("Running test %d:\t", test);
	if (test < 1 && test > MAX_TESTS) {
	  printf("Error: unknown test %d\t", test);
	  exit(EXIT_SUCCESS);
        }
    }


    if (all || test == 1) test1_link_create();
    if (all || test == 2) test2_link_create();
    if (all || test == 3) test1_link_set_name();
    if (all || test == 4) test2_link_set_name();
    if (all || test == 5) test1_link_set_spaceL1();
    if (all || test == 6) test2_link_set_spaceL1();
    if (all || test == 7) test1_link_set_spaceL2();
    if (all || test == 8) test2_link_set_spaceL2();
    if (all || test == 9) test1_link_set_statusL();
    if (all || test == 10) test2_link_set_statusL();
    if (all || test == 11) test1_link_get_name();
    if (all || test == 12) test2_link_get_name();
    if (all || test == 13) test1_link_get_id();
    if (all || test == 14) test2_link_get_id();
    if (all || test == 15) test1_link_get_spaceL1();
    if (all || test == 16) test2_link_get_spaceL1();
    if (all || test == 17) test1_link_get_spaceL2();
    if (all || test == 18) test2_link_get_spaceL2();
    if (all || test == 19) test1_link_get_statusL();
    if (all || test == 20) test2_link_get_statusL();
    if (all || test == 21) test1_link_print();
    if (all || test == 22) test2_link_print();


    PRINT_PASSED_PERCENTAGE;

    return 1;
}

void test1_link_create(){
  Link *l;
  l = link_create(5);
  PRINT_TEST_RESULT(l!=NULL);
  link_destroy(l);
}

void test2_link_create(){
  Link *l;
  l = link_create(5);
  PRINT_TEST_RESULT(link_get_id(l)==5);
  link_destroy(l);
}

void test1_link_set_name(){
  Link *l;
  l = link_create(5);
  PRINT_TEST_RESULT(link_set_name(l, "test")==OK);
  link_destroy(l);
}

void test2_link_set_name(){
  Link* l=NULL;
  PRINT_TEST_RESULT(link_set_name(l, "test")==ERROR);
}

void test1_link_set_spaceL1(){
  Link *l;
  l = link_create(5);
  PRINT_TEST_RESULT(link_set_spaceL1(l, 1)==OK);
  link_destroy(l);
}

void test2_link_set_spaceL1(){
  Link* l=NULL;
  PRINT_TEST_RESULT(link_set_spaceL1(l, 1)==ERROR);
}

void test1_link_set_spaceL2(){
  Link *l;
  l = link_create(5);
  PRINT_TEST_RESULT(link_set_spaceL2(l, 1)==OK);
  link_destroy(l);
}

void test2_link_set_spaceL2(){
  Link* l=NULL;
  PRINT_TEST_RESULT(link_set_spaceL2(l, 1)==ERROR);
}

void test1_link_set_statusL(){
  Link *l;
  l = link_create(5);
  PRINT_TEST_RESULT(link_set_statusL(l, OPEN)==OK);
  link_destroy(l);
}

void test2_link_set_statusL(){
  Link* l=NULL;
  PRINT_TEST_RESULT(link_set_statusL(l, OPEN)==ERROR);
}

void test1_link_get_name(){
  Link *l;
  l = link_create(5);
  link_set_name(l, "test");
  PRINT_TEST_RESULT(strcmp(link_get_name(l), "test") == 0);
  link_destroy(l);
}

void test2_link_get_name(){
  Link* l=NULL;
  PRINT_TEST_RESULT(link_get_name(l)==NULL);
}

void test1_link_get_id(){
  Link *l;
  l = link_create(5);
  PRINT_TEST_RESULT(link_get_id(l)==5);
  link_destroy(l);
}

void test2_link_get_id(){
  Link* l=NULL;
  PRINT_TEST_RESULT(link_get_id(l)==NO_ID);
}

void test1_link_get_spaceL1(){
  Link *l;
  l = link_create(5);
  link_set_spaceL1(l, 1);
  PRINT_TEST_RESULT(link_get_spaceL1(l)==1);
  link_destroy(l);
}

void test2_link_get_spaceL1(){
  Link* l=NULL;
  PRINT_TEST_RESULT(link_get_spaceL1(l)==NO_ID);
}

void test1_link_get_spaceL2(){
  Link *l;
  l = link_create(5);
  link_set_spaceL2(l, 1);
  PRINT_TEST_RESULT(link_get_spaceL2(l)==1);
  link_destroy(l);
}

void test2_link_get_spaceL2(){
  Link* l=NULL;
  PRINT_TEST_RESULT(link_get_spaceL2(l)==NO_ID);
}

void test1_link_get_statusL(){
  Link *l;
  l = link_create(5);
  link_set_statusL(l, OPEN);
  PRINT_TEST_RESULT(link_get_statusL(l)==OPEN);
  link_destroy(l);
}

void test2_link_get_statusL(){
  Link* l=NULL;
  PRINT_TEST_RESULT(link_get_statusL(l)==NO_STATUS);
}

void test1_link_print(){
  Link* l;
  l = link_create(5);
  PRINT_TEST_RESULT(link_print(NULL, l)==ERROR);
  link_destroy(l);
}

void test2_link_print(){
  Link* l=NULL;
  PRINT_TEST_RESULT(link_print(stdout,l) == ERROR);
}
