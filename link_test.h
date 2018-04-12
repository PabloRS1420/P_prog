/**
 * @brief It declares the tests for the link module
 *
 * @file link_test.h
 * @author Profesores Pprog
 * @version 2.0
 * @date 19-01-2016
 * @copyright GNU Public License
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include "link.h"
 #include "test.h"

 /**maximum number of tests*/
 #define MAX_TESTS 22

#ifndef LINK_TEST_H
#define LINK_TEST_H

/**
 * @test Test link creation
 * @pre link ID
 * @post Non NULL pointer to link
 */
void test1_link_create();

/**
 * @test Test space creation
 * @pre Space ID
 * @post Space_ID == Supplied Space Id
 */
void test2_link_create();

/**
 * @test Test function for link_name setting
 * @pre Pointer to link, string with link name
 * @post Ouput==OK
 */
void test1_link_set_name();

/**
 * @test Test function for link_name setting
 * @pre Pointer to NULL, string with name
 * @post Ouput==ERROR
 */

void test2_link_set_name();

/**
 * @test Test function to set first linked space
 * @pre Pointer to link, space Id
 * @post Output==OK
 */
void test1_link_set_spaceL1();

/**
 * @test Test function to set first linked space
 * @pre Pointer to NULL, space Id
 * @post Output==ERROR
 */
void test2_link_set_spaceL1();

/**
 * @test Test function to set second linked space
 * @pre Pointer to link, space Id
 * @post Output==OK
 */
void test1_link_set_spaceL2();

/**
 * @test Test function to set second linked space
 * @pre Pointer to NULL, space Id
 * @post Output==ERROR
 */
void test2_link_set_spaceL2();

/**
 * @test Test function to set link availability
 * @pre Pointer to link, STATUS
 * @post Output==OK
 */
void test1_link_set_statusL();

/**
 * @test Test function to set link availability
 * @pre Pointer to NULL, STATUS
 * @post Output==ERROR
 */
void test2_link_set_statusL();

/**
 * @test Test function for link_name getting
 * @pre Pointer to link
 * @post Output==Link name
 */
void test1_link_get_name();

/**
 * @test Test function for link_name getting
 * @pre Pointer to NULL
 * @post Output==NULL
 */
void test2_link_get_name();

/**
 * @test Test function for link_id getting
 * @pre Pointer to link
 * @post Output==Link Id
 */
void test1_link_get_id();

/**
 * @test Test function for link_id getting
 * @pre Pointer to NULL
 * @post Output==NULL
 */
void test2_link_get_id();

/**
 * @test Test function to get first linked space
 * @pre Pointer to link
 * @post Output==OK
 */
void test1_link_get_spaceL1();

/**
 * @test Test function to get first linked space
 * @pre Pointer to NULL
 * @post Output==ERROR
 */
void test2_link_get_spaceL1();

/**
 * @test Test function to get second linked space
 * @pre Pointer to link
 * @post Output==OK
 */
void test1_link_get_spaceL2();

/**
 * @test Test function to get second linked space
 * @pre Pointer to NULL
 * @post Output==ERROR
 */
void test2_link_get_spaceL2();

/**
 * @test Test function to get link availability
 * @pre Pointer to link
 * @post Output==OK
 */
void test1_link_get_statusL();

/**
 * @test Test function to get link availability
 * @pre Pointer to NULL
 * @post Output==ERROR
 */
void test2_link_get_statusL();

/**
 * @test Test function to print links
 * @pre Pointer to NULL, pointer to link
 * @post Output==ERROR
 */
void test1_link_print();

/**
 * @test Test function to print links
 * @pre Pointer to FILE, pointer to NULL
 * @post Output==ERROR
 */
void test2_link_print();

#endif
