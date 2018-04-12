/*
 * @brief It declares the tests for the space module
 *
 * @file space_test.h
 * @author Profesores Pprog
 * @version 2.0
 * @date 19-01-2016
 * @copyright GNU Public License
 */


#include "../include/space_test.h"

/**
 * @brief Main function for SPACE unit tests.
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


    if (all || test == 1) test1_space_create();
    if (all || test == 2) test2_space_create();
    if (all || test == 3) test1_space_set_name();
    if (all || test == 4) test2_space_set_name();
    if (all || test == 5) test3_space_set_name();
    if (all || test == 6) test1_space_set_north();
    if (all || test == 7) test2_space_set_north();
    if (all || test == 8) test1_space_set_south();
    if (all || test == 9) test2_space_set_south();
    if (all || test == 10) test1_space_set_east();
    if (all || test == 11) test2_space_set_east();
    if (all || test == 12) test1_space_set_west();
    if (all || test == 13) test2_space_set_west();
    if (all || test == 14) test1_space_get_name();
    if (all || test == 15) test2_space_get_name();
    if (all || test == 16) test1_space_get_object_set();
    if (all || test == 17) test2_space_get_object_set();
    if (all || test == 18) test3_space_get_object_set();
    if (all || test == 19) test1_space_get_north();
    if (all || test == 20) test2_space_get_north();
    if (all || test == 21) test1_space_get_south();
    if (all || test == 22) test2_space_get_south();
    if (all || test == 23) test1_space_get_east();
    if (all || test == 24) test2_space_get_east();
    if (all || test == 25) test1_space_get_west();
    if (all || test == 26) test2_space_get_west();
    if (all || test == 27) test1_space_get_id();
    if (all || test == 28) test2_space_get_id();
    if (all || test == 29) test1_space_set_gdesc();
    if (all || test == 30) test2_space_set_gdesc();
    if (all || test == 31) test1_space_get_gdesc();
    if (all || test == 32) test2_space_get_gdesc();
    if (all || test == 33) test1_space_set_description();
    if (all || test == 34) test2_space_set_description();
    if (all || test == 35) test1_space_get_description();
    if (all || test == 36) test2_space_get_description();

    PRINT_PASSED_PERCENTAGE;

    return 1;
}

void test1_space_create() {
  int result = space_create(5)!=NULL ;
  PRINT_TEST_RESULT(result);
}

void test2_space_create() {
    Space *s;
    s = space_create(4);
    PRINT_TEST_RESULT(space_get_id(s) == 4);
}

void test1_space_set_name() {
    Space *s;
    s = space_create(5);
    PRINT_TEST_RESULT(space_set_name(s, "hola") == OK);
}

void test2_space_set_name() {
    Space *s = NULL;
    PRINT_TEST_RESULT(space_set_name(s, "hola") == ERROR);
}

void test3_space_set_name() {
    Space *s;
    s = space_create(5);
    PRINT_TEST_RESULT(space_set_name(s, NULL) == ERROR);
}

void test1_space_set_north() {
    Space *s;
    s = space_create(5);
    PRINT_TEST_RESULT(space_set_north(s, 4) == OK);
}

void test2_space_set_north() {
    Space *s = NULL;
    PRINT_TEST_RESULT(space_set_north(s, 4) == ERROR);
}

void test1_space_set_south() {
    Space *s;
    s = space_create(5);
    PRINT_TEST_RESULT(space_set_south(s, 4) == OK);
}

void test2_space_set_south() {
    Space *s = NULL;
    PRINT_TEST_RESULT(space_set_south(s, 4) == ERROR);
}

void test1_space_set_east() {
    Space *s;
    s = space_create(5);
    PRINT_TEST_RESULT(space_set_east(s, 4) == OK);
}

void test2_space_set_east() {
    Space *s = NULL;
    PRINT_TEST_RESULT(space_set_east(s, 4) == ERROR);
}

void test1_space_set_west() {
    Space *s;
    s = space_create(5);
    PRINT_TEST_RESULT(space_set_west(s, 4) == OK);
}

void test2_space_set_west() {
    Space *s = NULL;
    PRINT_TEST_RESULT(space_set_west(s, 4) == ERROR);
}

void test1_space_add_object() {
    Space *s;
    s = space_create(1);
    PRINT_TEST_RESULT(space_add_object(s,1) == OK);
}

void test2_space_add_object() {
    Space *s = NULL;
    PRINT_TEST_RESULT(space_add_object(s,1) == ERROR);
}

void test1_space_get_name() {
    Space *s;
    s = space_create(1);
    space_set_name(s, "adios");
    PRINT_TEST_RESULT(strcmp(space_get_name(s), "adios") == 0);

}

void test2_space_get_name() {
    Space *s = NULL;
    PRINT_TEST_RESULT(space_get_name(s) == NULL);

}

void test1_space_get_object_set() {
    Space *s;
    s = space_create(1);
    PRINT_TEST_RESULT(space_get_object_set(s) != NULL);

}

void test2_space_get_object_set() {
    Space *s;
    s = space_create(1);
    space_add_object(s,1);
    PRINT_TEST_RESULT(set_get_size(space_get_object_set(s)) == 1);

}

void test3_space_get_object_set() {
    Space *s = NULL;
    PRINT_TEST_RESULT(space_get_object_set(s) == NULL);
}

void test1_space_get_north() {
    Space *s;
    s = space_create(5);
    space_set_north(s, 4);
    PRINT_TEST_RESULT(space_get_north(s) == 4);
}

void test2_space_get_north() {
    Space *s = NULL;
    PRINT_TEST_RESULT(space_get_north(s) == NO_ID);
}

void test1_space_get_south() {
    Space *s;
    s = space_create(5);
    space_set_south(s, 2);
    PRINT_TEST_RESULT(space_get_south(s) == 2);
}

void test2_space_get_south() {
    Space *s = NULL;
    PRINT_TEST_RESULT(space_get_south(s) == NO_ID);
}

void test1_space_get_east() {
    Space *s;
    s = space_create(5);
    space_set_east(s, 1);
    PRINT_TEST_RESULT(space_get_east(s) == 1);
}

void test2_space_get_east() {
    Space *s = NULL;
    PRINT_TEST_RESULT(space_get_east(s) == NO_ID);
}

void test1_space_get_west() {
    Space *s;
    s = space_create(5);
    space_set_west(s, 6);
    PRINT_TEST_RESULT(space_get_west(s) == 6);
}

void test2_space_get_west() {
    Space *s = NULL;
    PRINT_TEST_RESULT(space_get_west(s) == NO_ID);
}

void test1_space_get_id() {
    Space *s;
    s = space_create(25);
    PRINT_TEST_RESULT(space_get_id(s) == 25);
}

void test2_space_get_id() {
    Space *s = NULL;
    PRINT_TEST_RESULT(space_get_id(s) == NO_ID);
}

void test1_space_set_gdesc(){
  Space *s;
  char* gdesc[3]={"This","is","a test"};
  s = space_create(5);
  PRINT_TEST_RESULT(space_set_gdesc(s, gdesc) == OK);
}

void test2_space_set_gdesc(){
  Space *s=NULL;
  char* gdesc[3]={"This","is","a test"};
  PRINT_TEST_RESULT(space_set_gdesc(s, gdesc) == ERROR);
}

void test1_space_get_gdesc(){
  Space *s;
  char* gdesc[3]={"This","is","a test"};
  s = space_create(5);
  space_set_gdesc(s, gdesc);
  PRINT_TEST_RESULT(strcmp(space_get_gdesc(s)[0],"This") == 0);
}

void test2_space_get_gdesc(){
  Space *s=NULL;
  PRINT_TEST_RESULT(space_get_gdesc(s)==NULL);
}

void test1_space_set_description(){
  Space *s;
  char* description="This is a test";
  s = space_create(5);
  PRINT_TEST_RESULT(space_set_description(s, description) == OK);
}

void test2_space_set_description(){
  Space *s=NULL;
  char* description="This is a test";
  PRINT_TEST_RESULT(space_set_description(s, description) == ERROR);
}

void test1_space_get_description(){
  Space *s;
  char* description="This is a test";
  s = space_create(5);
  space_set_description(s, description);
  PRINT_TEST_RESULT(strcmp(space_get_description(s),"This is a test") == 0);
}

void test2_space_get_description(){
  Space *s=NULL;
  PRINT_TEST_RESULT(space_get_description(s)==NULL);
}
