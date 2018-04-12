/**
 * @brief Provides the functionalities to throw a dice in the game
 * @file dice.h
 * @author Oriana Pastor
 * @version 1.0
 * @date 20-03-18
 * @copyright GNU Public License
 */

#ifndef DICE_H
#define DICE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "types.h"

/** ADT that represents the Dice of the game.*/
typedef struct _Dice Dice;

/**
* @brief Reserves memory for a Dice* initialising the struct.
* @param None
* @return Dice*
* @author Oriana Nicole Pastor Sánchez
*/
Dice* dice_create(Id id);

/**
 * @brief Frees all the memory reserved.
 * @param Dice*
 * @return OK if everything went well or ERROR if not.
 * @author Oriana Nicole Pastor Sánchez
 */
STATUS dice_destroy(Dice *dice);
/**
 * @brief Generates a random number between 1 and 6 and assigns it to
 * the value variable of the given Dice* struct.
 * @param Dice*
 * @return OK if everything went well or ERROR if not.
 * @author Oriana Nicole Pastor Sánchez
 */
STATUS dice_roll(Dice *dice);

/**
 * @brief Returns the Id of the dice.
 * @param Dice*
 * @return Id of the dice
 * @author Oriana Nicole Pastor Sánchez
 */
Id dice_get_id(Dice *dice);

/**
 * @brief Return the result of the last dice throw.
 * @param Dice*
 * @return int, result of the last dice throw
 * @author Oriana Nicole Pastor Sánchez
 */
int dice_get_result (Dice *dice);

/**
 * @brief Prints the relevant data of a given dice to a file.
 * @param Output file, Dice*
 * @return OK if everything went well or ERROR if not.
 * @author Oriana Nicole Pastor Sánchez
 */
 STATUS dice_print(FILE *f, Dice *dice);

#endif
