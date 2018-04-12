/*
 * @brief Provides the functionalities to throw a dice in the game
 * @file dice.h
 * @author Oriana Pastor
 * @version 1.0
 * @date 20-03-18
 * @copyright GNU Public License
 */

#include "../include/../include/dice.h"

/** ADT that represents the Dice of the game.*/
struct _Dice {
    Id id;
    int result;
};

Dice * dice_create(Id id){
  Dice *new_dice = NULL;

  if (id == NO_ID)
    return NULL;

  new_dice = (Dice *) malloc(sizeof (Dice));

  if (new_dice == NULL) {
    return NULL;
  }

   new_dice->id = id;
   new_dice->result=0;

   srand(time(NULL));   /*initializes a random number generator*/

   return new_dice;
}

STATUS dice_destroy(Dice *dice){
  if (!dice) {
      return ERROR;
  }

  free(dice);
  dice = NULL;

  return OK;
}


STATUS dice_roll(Dice *dice){
    if (!dice){
      return ERROR;
    }
    dice->result = (rand() % 6)+1;
    return OK;
}

Id dice_get_id(Dice* dice){
  if (!dice){
    return NO_ID;
  }
  return dice->id;
}

int dice_get_result(Dice* dice){
  if (!dice){
    return -1;
  }
  return dice->result;
}

STATUS dice_print(FILE *f, Dice *dice){
  if (!dice || !f) {
    return ERROR;
  }

  fprintf(stdout, "--> Dice (Id: %ld; Result %d)\n", dice->id, dice->result);

	return OK;
}
