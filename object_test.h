/**
 * @brief It declares the tests for the object module
 *
 * @file object_test.h
 * @author Silvia Tomey
 * @version 1.0
 * @date 09-04-2018
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/object.h"
#include "../include/test.h"

/**number of function tests in object_test*/
#define MAX_TESTS 17

#ifndef OBJECT_TEST_H
#define OBJECT_TEST_H

/**
 * @test Test object creation
 * @pre Object ID
 * @post Output==Non NULL pointer to player
 */
void test1_object_create();

/**
 * @test Test object creation
 * @pre Object ID
 * @post Output==Supplied object Id
 */
void test2_player_create();

/**
 * @test Test object id.
 * @pre Pointer to NULL
 * @post Output==-1
 */
void test1_object_get_id();

/**
 * @test Test function for object_name setting
 * @pre Pointer to object, string with object name
 * @post Ouput==OK
 */
void test1_object_set_name();

/**
 * @test Test function for object_name setting
 * @pre Pointer to NULL, string with name
 * @post Ouput==ERROR
 */
void test2_object_set_name();

/**
 * @test Test function for object_name setting
 * @pre Pointer to object, number 0
 * @post Ouput==ERROR
 */
void test3_object_set_name();

/**
 * @test Test function for object_name getting
 * @pre Pointer to object
 * @post Output==Object name
 */
void test1_object_get_name();

/**
 * @test Test function for object_name getting
 * @pre Pointer to NULL
 * @post Output==NULL
 */
void test2_object_get_name();

/**
 * @test Test function for object_space setting
 * @pre Pointer to object, space Id
 * @post Output==OK
 */
void test1_object_set_space_id();

/**
 * @test Test function for object_space setting
 * @pre Pointer to NULL, space Id
 * @post Output==ERROR
 */
void test2_object_set_space_id();

/**
 * @test Test function for object_description setting
 * @pre Pointer to object, char string
 * @post Output==OK
 */
void test1_object_set_description();

/**
 * @test Test function for object_description setting
 * @pre Pointer to NULL, char string
 * @post Output==ERROR
 */
void test2_object_set_description();

/**
 * @test Test function for object_description setting
 * @pre Pointer to object, NULL string
 * @post Output==ERROR
 */
void test3_object_set_description();

/**
 * @test Test function for object_description getting
 * @pre Pointer to object
 * @post Output==Object description
 */
void test1_object_get_description();

/**
 * @test Test function for object_description getting
 * @pre Pointer to NULL
 * @post Output==NULL
 */
void test2_object_get_description();

/**
 * @test Test function for object_space getting
 * @pre Pointer to object.
 * @post Output==Space Id
 */
void test1_object_get_space_id();

/**
 * @test Test function for object_space getting
 * @pre Pointer to NULL.
 * @post Output==-1
 */
void test2_object_get_space_id();

void test1_object_create();
void test2_player_create();
void test1_object_get_id();
void test1_object_set_name();
void test2_object_set_name();
void test3_object_set_name();
void test1_object_get_name();
void test2_object_get_name();
void test1_object_set_space_id();
void test2_object_set_space_id();
void test1_object_set_description();
void test2_object_set_description();
void test3_object_set_description();
void test1_object_get_description();
void test2_object_get_description();
void test1_object_get_space_id();
void test2_object_get_space_id();

#endif
