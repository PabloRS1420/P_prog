/**
 * @brief Module reads the data necessary to initialize a game from a given
 *        date file
 *
 * @file game_reader.h
 * @author Frederik Mayer
 * @version 1.0: Module outsourced from module game
 * @date 15-02-2018
 * @copyright GNU Public License
 */

#ifndef GAME_READER_H
#define GAME_READER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"

/**
 * @brief Loads the initial data about the spaces from a data file
 * and writes it in the given Game* struct.
 * @param Game to be initiialized, Name of the data file with space information.
 * @return OK if everything went well or ERROR if not.
 * @author Frederik Mayer
 */
 STATUS game_reader_load_spaces(Game *game, char* filename);

/**
  * @brief Loads the initial data about the objects from a data file
  * and writes it in the given Game* struct.
  * @param Game to be initiialized, Name of the data file with object information.
  * @return OK if everything went well or ERROR if not.
  * @author Frederik Mayer
  */
  STATUS game_reader_load_objects(Game *game, char* filename);

/**
  * @brief Loads the initial data about the links from a data file
  * and writes it in the given Game* struct.
  * @param Game to be initiialized, Name of the data file with link information.
  * @return OK if everything went well or ERROR if not.
  * @author Frederik Mayer
  */
  STATUS game_reader_load_links(Game *game, char* filename);

#endif
