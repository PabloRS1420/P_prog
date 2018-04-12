/**
 * @brief Implements all the tests of previous iterations,
      those are executed by execute_tests.c
 *
 * @file tests.h
 * @author Frederik Mayer
 * @version 1.0
 * @date 03-04-18
 * @copyright GNU Public License
 */

#ifndef TESTS_H
#define TESTS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "set.h"
#include "dice.h"
#include "inventory.h"
#include "link.h"
#include "types.h"

/**maximum number of tests from previous iterations*/
#define MAX_TEST 2


STATUS test1_set_test();
STATUS test2_dice_test();

#endif
