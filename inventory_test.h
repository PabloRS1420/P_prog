/**
 * @brief It declares the tests for the inventory module
 *
 * @file inventory_test.h
 * @author Profesores Pprog
 * @version 2.0
 * @date 19-01-2016
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inventory.h"
#include "test.h"

/**number of function tests in inventory_test*/
#define MAX_TESTS 14

#ifndef INVENTORY_TEST_H
#define INVENTORY_TEST_H

/**
 * @test Test inventory creation
 * @pre inventory ID
 * @post Non NULL pointer to inventory
 */
void test1_inventory_create();

/**
 * @test Test inventory creation
 * @pre inventory ID
 * @post inventory_ID == Supplied inventory Id
 */
void test2_inventory_create();

/**
 * @test Test function for inventory_object adding
 * @pre Pointer to Inventory, object Id
 * @post Output==OK
 */
void test1_inventory_add_object();

/**
 * @test Test function for inventory_object adding
 * @pre Pointer to NULL, object Id
 * @post Output==ERROR
 */
void test2_inventory_add_object();

/**
 * @test Test function for Inventory_object maximum setting
 * @pre Pointer to Inventory, integer number
 * @post Output==OK
 */
void test1_inventory_set_nmax();

/**
 * @test Test function for Inventory_object maximum setting
 * @pre Pointer to NULL, integer number
 * @post Output==ERROR
 */
void test2_inventory_set_nmax();

/**
 * @test Test function for Inventory_object maximum getting
 * @pre Pointer to Inventory
 * @post Output==Maximum number
 */
void test1_inventory_get_nmax();

/**
 * @test Test function for Inventory_object maximum getting
 * @pre Pointer to NULL
 * @post Output==ERROR
 */
void test2_inventory_get_nmax();

/**
 * @test Test function to inventory_object set getting
 * @pre Pointer to Inventory
 * @post Non NULL pointer to inventory
 */
void test1_inventory_get_object_set();

/**
 * @test Test function to inventory_object set getting
 * @pre Pointer to NULL
 * @post Output==NULL
 */
void test2_inventory_get_object_set();

/**
 * @test Test function to check in inventory is full
 * @pre Pointer to Inventory
 * @post Output==FALSE
 */
void test1_inventory_is_full();

/**
 * @test Test function to check in inventory is full
 * @pre Pointer to Inventory
 * @post Output==TRUE
 */
void test2_inventory_is_full();

/**
 * @test Test function to print inventory
 * @pre Pointer to NULL, pointer to Inventory
 * @post Output==ERROR
 */
void test1_inventory_print();

/**
 * @test Test function to print inventory
 * @pre Pointer to FILE, pointer to NULL
 * @post Output==ERROR
 */
void test2_inventory_print();

#endif
