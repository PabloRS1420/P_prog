/*
 * @brief It declares the tests for the inventory module
 *
 * @file inventory_test.h
 * @author Profesores Pprog
 * @version 2.0
 * @date 19-01-2016
 * @copyright GNU Public License
 */

#include "../include/inventory_test.h"

/**
 * @brief Main function for inventory unit tests.
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
        printf("Running all test for module inventory:\n");
    } else {
        test = atoi(argv[1]);
        all = 0;
        printf("Running test %d:\t", test);
	if (test < 1 && test > MAX_TESTS) {
	  printf("Error: unknown test %d\t", test);
	  exit(EXIT_SUCCESS);
        }
    }


    if (all || test == 1) test1_inventory_create();
    if (all || test == 2) test2_inventory_create();
    if (all || test == 3) test1_inventory_add_object();
    if (all || test == 4) test2_inventory_add_object();
    if (all || test == 5) test1_inventory_set_nmax();
    if (all || test == 6) test2_inventory_set_nmax();
    if (all || test == 7) test1_inventory_get_nmax();
    if (all || test == 8) test2_inventory_get_nmax();
    if (all || test == 9) test1_inventory_get_object_set();
    if (all || test == 10) test2_inventory_get_object_set();
    if (all || test == 11) test1_inventory_is_full();
    if (all || test == 12) test2_inventory_is_full();
    if (all || test == 13) test1_inventory_print();
    if (all || test == 14) test2_inventory_print();

    PRINT_PASSED_PERCENTAGE;

    return 1;
}

void test1_inventory_create(){
  Inventory *inv;
  inv = inventory_create();
  PRINT_TEST_RESULT(inv!=NULL);
  inventory_destroy(inv);
}

void test2_inventory_create(){
  Inventory *inv;
  inv = inventory_create();
  PRINT_TEST_RESULT(inventory_get_nmax(inv) == DIM);
  inventory_destroy(inv);
}

void test1_inventory_add_object(){
  Inventory *inv;
  inv = inventory_create();
  PRINT_TEST_RESULT(inventory_add_object(inv, 5) == OK);
  inventory_destroy(inv);
}

void test2_inventory_add_object(){
  Inventory *inv=NULL;
  PRINT_TEST_RESULT(inventory_add_object(inv, 5) == ERROR);
}

void test1_inventory_set_nmax(){
  Inventory *inv;
  inv = inventory_create();
  PRINT_TEST_RESULT(inventory_set_nmax(inv, 5) == OK);
  inventory_destroy(inv);
}

void test2_inventory_set_nmax(){
  Inventory *inv=NULL;
  PRINT_TEST_RESULT(inventory_set_nmax(inv, 5) == ERROR);
}

void test1_inventory_get_nmax(){
  Inventory *inv;
  inv = inventory_create();
  inventory_set_nmax(inv, 5);
  PRINT_TEST_RESULT(inventory_get_nmax(inv) == 5);
  inventory_destroy(inv);
}

void test2_inventory_get_nmax(){
  Inventory *inv=NULL;
  PRINT_TEST_RESULT(inventory_get_nmax(inv) == -1);
}

void test1_inventory_get_object_set(){
  Inventory *inv;
  inv = inventory_create();
  PRINT_TEST_RESULT(inventory_get_object_set(inv)!=NULL);
  inventory_destroy(inv);
}

void test2_inventory_get_object_set(){
  Inventory *inv=NULL;
  PRINT_TEST_RESULT(inventory_get_object_set(inv) == NULL);
}

void test1_inventory_is_full(){
  Inventory *inv;
  inv = inventory_create();
  PRINT_TEST_RESULT(inventory_is_full(inv)==FALSE);
  inventory_destroy(inv);
}

void test2_inventory_is_full(){
  Inventory *inv;
  inv = inventory_create();
  inventory_set_nmax(inv, 1);
  inventory_add_object(inv,1);
  PRINT_TEST_RESULT(inventory_is_full(inv)==TRUE);
  inventory_destroy(inv);
}

void test1_inventory_print(){
  Inventory *inv;
  inv = inventory_create();
  inventory_set_nmax(inv, 1);
  inventory_add_object(inv, 1);
  PRINT_TEST_RESULT(inventory_print(NULL,inv)==ERROR);
  inventory_destroy(inv);
}

void test2_inventory_print(){
  Inventory *inv=NULL;
  PRINT_TEST_RESULT(inventory_print(stdout,inv) == ERROR);
}
