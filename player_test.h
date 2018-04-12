/**
 * @brief It declares the tests for the player module
 *
 * @file player_test.h
 * @author Silvia Tomey
 * @version 1.0
 * @date 09-04-2018
 * @copyright GNU Public License
 */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"
#include "test.h"

/**number of function tests in player_test*/
#define MAX_TESTS 15

#ifndef PLAYER_TEST_H
#define PLAYER_TEST_H

/**
 * @test Test player creation
 * @pre Player ID
 * @post Output==Non NULL pointer to player
 */
void test1_player_create();

/**
 * @test Test player creation
 * @pre Player ID
 * @post Output==Supplied Player Id
 */
void test2_player_create();

/**
 * @test Test player id.
 * @pre Pointer to NULL
 * @post Output==-1
 */
void test1_player_get_id();

/**
 * @test Test function for player_name setting
 * @pre Pointer to player, string with player name
 * @post Ouput==OK
 */

void test1_player_set_name();

/**
 * @test Test function for player_name setting
 * @pre Pointer to NULL, string with name
 * @post Ouput==ERROR
 */

void test2_player_set_name();

/**
 * @test Test function for player_name setting
 * @pre Pointer to player, NULL string
 * @post Ouput==ERROR
 */

void test3_player_set_name();


/**
 * @test Test function for player_name getting
 * @pre Pointer to player
 * @post Output==Player name
 */

void test1_player_get_name();

/**
 * @test Test function for player_name getting
 * @pre Pointer to NULL
 * @post Output==NULL
 */

void test2_player_get_name();

/**
 * @test Test function for player_space setting
 * @pre Pointer to player, space Id
 * @post Ouput==OK
 */
void test1_player_set_space_id();

/**
 * @test Test function for player_space setting
 * @pre Pointer to NULL, space Id
 * @post Ouput==ERROR
 */
void test2_player_set_space_id();

/**
 * @test Test function for player_object adding
 * @pre Pointer to player, command Id.
 * @post Ouput==OK
 */
void test1_player_add_newobject();

/**
 * @test Test function for player_object adding
 * @pre Pointer to NULL, command Id.
 * @post Ouput==ERROR
 */
void test2_player_add_newobject();

/**
 * @test Test function for player_object adding
 * @pre Pointer to player, NO_ID.
 * @post Ouput==ERROR
 */
void test3_player_add_newobject();

/**
 * @test Test function for player_space getting
 * @pre Pointer to player.
 * @post Ouput==Space Id
 */
void test1_player_get_space_id();

/**
 * @test Test function for player_space getting
 * @pre Pointer to NULL.
 * @post Ouput==NO_ID
 */
void test2_player_get_space_id();


void test1_player_create();
void test2_player_create();
void test1_player_get_id();
void test2_player_get_id();
void test3_player_get_id();
void test1_player_set_name();
void test2_player_set_name();
void test3_player_set_name();
void test1_player_get_name();
void test2_player_get_name();
void test1_player_set_space_id();
void test2_player_set_space_id();
void test1_player_add_newobject();
void test2_player_add_newobject();
void test3_player_add_newobject();
void test1_player_get_space_id();
void test2_player_get_space_id();

#endif
