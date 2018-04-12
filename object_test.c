/*
 * @brief It tests object module
 *
 * @file object_test.c
 * @author Silvia Tomey
 * @version 1.0
 * @date 09-04-2018
 * @copyright GNU Public License
 */

#include "../include/object_test.h"

/**
 * @brief Main function for OBJECT unit tests.
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
        printf("Running all test for module Space:\n");
    } else {
        test = atoi(argv[1]);
        all = 0;
        printf("Running test %d:\t", test);
	if (test < 1 && test > MAX_TESTS) {
	  printf("Error: unknown test %d\t", test);
	  exit(EXIT_SUCCESS);
        }
    }

    if (all || test ==1) test1_object_create();
    if (all || test ==2) test2_player_create();
    if (all || test ==3) test1_object_get_id();
    if (all || test ==4) test1_object_set_name();
    if (all || test ==5) test2_object_set_name();
    if (all || test ==6) test3_object_set_name();
    if (all || test ==7) test1_object_get_name();
    if (all || test ==8) test2_object_get_name();
    if (all || test ==9) test1_object_set_space_id();
    if (all || test ==10) test2_object_set_space_id();
    if (all || test ==11) test1_object_set_description();
    if (all || test ==12) test2_object_set_description();
    if (all || test ==13) test3_object_set_description();
    if (all || test ==14) test1_object_get_description();
    if (all || test ==15) test2_object_get_description();
    if (all || test ==16) test1_object_get_space_id();
    if (all || test ==17) test2_object_get_space_id();

    PRINT_PASSED_PERCENTAGE;

    return 1;
}

void test1_object_create() {
  int result = object_create(5)!=NULL ;
  PRINT_TEST_RESULT(result);
}

void test2_player_create() {
    Object *o;
    o = object_create(4);
    PRINT_TEST_RESULT(object_get_id(o) == 4);
}

void test1_object_get_id() {
    Object *o = NULL;
    PRINT_TEST_RESULT(object_get_id(o) == -1);
}

void test1_object_set_name() {
    Object *o;
    o = object_create(5);
    PRINT_TEST_RESULT(object_set_name(o, "hola") == OK);
}

void test2_object_set_name() {
    Object *o = NULL;
    PRINT_TEST_RESULT(object_set_name(o, "hola") == ERROR);
}

void test3_object_set_name() {
    Object *o;
    o = object_create(5);
    PRINT_TEST_RESULT(object_set_name(o, NULL) == ERROR);
}

void test1_object_get_name() {
    Object *o;
    o = object_create(1);
    object_set_name(o, "adios");
    PRINT_TEST_RESULT(strcmp(object_get_name(o), "adios") == 0);
}

void test2_object_get_name() {
    Object *o = NULL;
    PRINT_TEST_RESULT(object_get_name(o) == NULL);
}

void test1_object_set_space_id() {
    Object *o;
    o = object_create(5);
    PRINT_TEST_RESULT(object_set_space_id(o, 8) == OK);
}

void test2_object_set_space_id() {
    Object *o = NULL;
    PRINT_TEST_RESULT(object_set_space_id(o, 8) == ERROR);
}


void test1_object_set_description() {
    Object *o;
    o = object_create(5);
    PRINT_TEST_RESULT(object_set_description(o, "powerful") == OK);
}

void test2_object_set_description() {
    Object *o = NULL;
    PRINT_TEST_RESULT(object_set_description(o, "good for nothing") == ERROR);
}

void test3_object_set_description() {
    Object *o;
    o = object_create(5);
    PRINT_TEST_RESULT(object_set_name(o, NULL) == ERROR);
}

void test1_object_get_description() {
    Object *o;
    o = object_create(1);
    object_set_description(o, "kawaii");
    PRINT_TEST_RESULT(strcmp(object_get_description(o), "kawaii") == 0);
}

void test2_object_get_description() {
    Object *o = NULL;
    PRINT_TEST_RESULT(object_get_name(o) == NULL);
}

void test1_object_get_space_id() {
    Object *o;
    o = object_create(5);
    PRINT_TEST_RESULT(object_set_space_id(o, 8) == OK);
}

void test2_object_get_space_id() {
    Object *o = NULL;
    PRINT_TEST_RESULT(object_get_space_id(o) == -1);
}
