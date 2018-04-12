/*
 * @brief It tests player module
 *
 * @file player_test.c
 * @author Silvia Tomey
 * @version 1.0
 * @date 09-04-2018
 * @copyright GNU Public License
 */


#include "../include/player_test.h"

/**
 * @brief Main function for PLAYER unit tests.
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

    if (all || test ==1) test1_player_create();
    if (all || test ==2) test2_player_create();
    if (all || test ==3) test1_player_get_id();
    if (all || test ==4) test1_player_set_name();
    if (all || test ==5) test2_player_set_name();
    if (all || test ==6) test3_player_set_name();
    if (all || test ==7) test1_player_get_name();
    if (all || test ==8) test2_player_get_name();
    if (all || test ==9) test1_player_set_space_id();
    if (all || test ==10) test2_player_set_space_id();
    if (all || test ==11) test1_player_add_newobject();
    if (all || test ==12) test2_player_add_newobject();
    if (all || test ==13) test3_player_add_newobject();
    if (all || test ==14) test1_player_get_space_id();
    if (all || test ==15) test2_player_get_space_id();

    PRINT_PASSED_PERCENTAGE;

    return 1;
}

void test1_player_create() {
  int result = player_create(5)!=NULL ;
  PRINT_TEST_RESULT(result);
}

void test2_player_create() {
    Player *p;
    p = player_create(4);
    PRINT_TEST_RESULT(player_get_id(p) == 4);
}

void test1_player_get_id() {
    Player *p = NULL;
    PRINT_TEST_RESULT(player_get_id(p) == -1);
}

void test1_player_set_name() {
    Player *p;
    p = player_create(5);
    PRINT_TEST_RESULT(player_set_name(p, "hola") == OK);
}

void test2_player_set_name() {
    Player *p = NULL;
    PRINT_TEST_RESULT(player_set_name(p, "hola") == ERROR);
}

void test3_player_set_name() {
    Player *p;
    p = player_create(5);
    PRINT_TEST_RESULT(player_set_name(p, NULL) == ERROR);
}

void test1_player_get_name() {
    Player *p;
    p = player_create(1);
    player_set_name(p, "adios");
    PRINT_TEST_RESULT(strcmp(player_get_name(p), "adios") == 0);
}

void test2_player_get_name() {
    Player *p = NULL;
    PRINT_TEST_RESULT(player_get_name(p) == NULL);
}

void test1_player_set_space_id() {
    Player *p;
    p = player_create(5);
    PRINT_TEST_RESULT(player_set_space_id(p, 8) == OK);
}

void test2_player_set_space_id() {
    Player *p = NULL;
    PRINT_TEST_RESULT(player_set_space_id(p, 8) == ERROR);
}

void test1_player_get_space_id() {
    Player *p;
    p = player_create(1);
    player_set_space_id(p, 2);
    PRINT_TEST_RESULT(player_get_space_id(p) == 2);
}

void test2_player_get_space_id() {
    Player *p = NULL;
    PRINT_TEST_RESULT(player_get_space_id(p) == -1);
}

void test1_player_add_newobject() {
    Player *p;
    p = player_create(1);
    PRINT_TEST_RESULT(player_add_newobject(p, 2) == OK);
}

void test2_player_add_newobject() {
    Player *p = NULL;
    PRINT_TEST_RESULT(player_add_newobject(p, 2) == ERROR);
}

void test3_player_add_newobject() {
    Player *p;
    p = player_create(1);
    PRINT_TEST_RESULT(player_add_newobject(p, -1) == ERROR);
}
