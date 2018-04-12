/**
 * @brief It declares the tests for the space module
 *
 * @file space_test.h
 * @author Profesores Pprog
 * @version 2.0
 * @date 19-01-2016
 * @copyright GNU Public License
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include "../include/space.h"
 #include "../include/test.h"

 /**number of function tests in space_test*/
 #define MAX_TESTS 36

#ifndef SPACE_TEST_H
#define SPACE_TEST_H

/**
 * @test Test space creation
 * @pre Space ID
 * @post Non NULL pointer to space
 */
void test1_space_create();

/**
 * @test Test space creation
 * @pre Space ID
 * @post Space_ID == Supplied Space Id
 */
void test2_space_create();

/**
 * @test Test function for space_name setting
 * @pre String with space name
 * @post Ouput==OK
 */
void test1_space_set_name();

/**
 * @test Test function for space_name setting
 * @pre pointer to space = NULL
 * @post Output==ERROR
 */
void test2_space_set_name();

/**
 * @test Test function for space_name setting
 * @pre pointer to space_name = NULL (point to space = NON NULL)
 * @post Output==ERROR
 */
void test3_space_set_name();

/**
 * @test Test function for space_north setting
 * @pre pointer to space, pointer to ID
 * @post Output==OK
 */
void test1_space_set_north();

/**
 * @test Test function for space_north setting
 * @pre pointer to NULL, pointer to ID
 * @post Output==ERROR
 */
void test2_space_set_north();

/**
 * @test Test function for space_south setting
 * @pre pointer to space, pointer to ID
 * @post Output==OK
 */
void test1_space_set_south();

/**
 * @test Test function for space_south setting
 * @pre pointer to NULL, pointer to ID
 * @post Output==ERROR
 */
void test2_space_set_south();

/**
 * @test Test function for space_east setting
 * @pre pointer to space, pointer to ID
 * @post Output==OK
 */
void test1_space_set_east();

/**
 * @test Test function for space_east setting
 * @pre pointer to NULL, pointer to ID
 * @post Output==ERROR
 */
void test2_space_set_east();

/**
 * @test Test function for space_west setting
 * @pre pointer to space, pointer to ID
 * @post Output==OK
 */
void test1_space_set_west();

/**
 * @test Test function for space_west setting
 * @pre pointer to NULL, pointer to ID
 * @post Output==ERROR
 */
void test2_space_set_west();

/**
 * @test Test function for space_id getting
 * @pre Pointer to Space
 * @post Output==Space Id
 */
void test1_space_get_id();

/**
 * @test Test function for space_id getting
 * @pre Pointer to NULL
 * @post Output==NULL
 */
void test2_space_get_id();

/**
 * @test Test function to space_object adding
 * @pre Pointer to space, Object Id
 * @post Output==OK
 */
void test1_space_add_object();

/**
 * @test Test function to space_object adding
 * @pre Pointer to NULL, Object Id
 * @post Output==ERROR
 */
void test2_space_add_object();

/**
 * @test Test function to space_name getting
 * @pre Pointer to Space
 * @post Output==Space name
 */
void test1_space_get_name();

/**
 * @test Test function to space_name getting
 * @pre Pointer to NULL
 * @post Output==NULL
 */
void test2_space_get_name();

/**
 * @test Test function to space_north getting
 * @pre Pointer to space
 * @post Output==North Id
 */
void test1_space_get_north();

/**
 * @test Test function to space_north getting
 * @pre Pointer to NULL
 * @post Output==NULL
 */
void test2_space_get_north();

/**
 * @test Test function to space_south getting
 * @pre Pointer to space
 * @post Output==South Id
 */
void test1_space_get_south();

/**
 * @test Test function to space_south getting
 * @pre Pointer to NULL
 * @post Output==NULL
 */
void test2_space_get_south();

/**
 * @test Test function to space_east getting
 * @pre Pointer to space
 * @post Output==East Id
 */
void test1_space_get_east();

/**
 * @test Test function to space_east getting
 * @pre Pointer to NULL
 * @post Output==NULL
 */
void test2_space_get_east();

/**
 * @test Test function to space_west getting
 * @pre Pointer to space
 * @post Output==West Id
 */
void test1_space_get_west();

/**
 * @test Test function to space_west getting
 * @pre Pointer to NULL
 * @post Output==NULL
 */
void test2_space_get_west();

/**
 * @test Test function to space_object getting
 * @pre Pointer to space
 * @post Output==Non NULL pointer to set
 */
void test1_space_get_object_set();

/**
 * @test Test function to space_object getting
 * @pre Pointer to space
 * @post Output==Supplied Set Id
 */
void test2_space_get_object_set();

/**
 * @test Test function to space_object getting
 * @pre Pointer to NULL
 * @post Output==NULL
 */
void test3_space_get_object_set();

/**
 * @test Test function for space_gdesc setting
 * @pre Pointer to Space, pointer to char
 * @post Output==OK
 */
void test1_space_set_gdesc();

/**
 * @test Test function for space_gdesc setting
 * @pre Pointer to NULL, pointer to char
 * @post Output==ERROR
 */
void test2_space_set_gdesc();

/**
 * @test Test function for space_gdesc getting
 * @pre Pointer to Space
 * @post Output==Pointer to char
 */
void test1_space_get_gdesc();

/**
 * @test Test function for space_gdesc getting
 * @pre Pointer to NULL
 * @post Output==NULL
 */
void test2_space_get_gdesc();

/**
 * @test Test function for space_set description setting
 * @pre Pointer to Space, pointer to char
 * @post Output==OK
 */
void test1_space_set_description();

/**
 * @test Test function for space_set description setting
 * @pre Pointer to NULL, pointer to char
 * @post Output==NULL
 */
void test2_space_set_description();

/**
 * @test Test function for space_set description getting
 * @pre Pointer to Space
 * @post Output==Set description
 */
void test1_space_get_description();

/**
 * @test Test function for space_set description getting
 * @pre Pointer to NULL
 * @post Output==NULL
 */
void test2_space_get_description();

#endif
