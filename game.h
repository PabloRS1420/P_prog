/**
 * @brief It defines the game interface
 * for each command
 *
 * @file game.h
 * @author Profesores PPROG
 * @version 1.0
 * @date 13-01-2015
 * @copyright GNU Public License
 */

#ifndef GAME_H
#define GAME_H

#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <unistd.h>

#include "command.h"
#include "dice.h"
#include "object.h"
#include "player.h"
#include "set.h"
#include "space.h"
#include "types.h"
#include "link.h"

/*ADT that represents a game instance.*/
typedef struct _Game Game;

/**
 * @brief It adds a new space to the given Game*.
 * @param Game*, Space*
 * @return OK if everything went well or ERROR if not.
 * @author Profesores PPROG
 */
STATUS game_add_space(Game* game, Space* space);

/**
 * @brief It adds a new object to the given Game*.
 * @param Game*, Object*
 * @return OK if everything went well or ERROR if not.
 * @author Frederik Mayer
 */
STATUS game_add_object(Game* game, Object* object);

/**
 * @brief It adds a new link to the given Game*.
 * @param Game*, Object*
 * @return OK if everything went well or ERROR if not.
 * @author Oriana Pastor
 */
STATUS game_add_link(Game* game, Link* link);

/**
 * @brief It reserves memory for a Game* initialising the struct.
 * @param Game*
 * @return OK if everything went well or ERROR if not.
 * @author Profesores PPROG
 */
STATUS game_create(Game* game);

/**
 * @brief Initializes the given Game* with data given by an input file.
 * Main functionality outsourced to GameReader module.
 * @param Game*, name of the input file.
 * @return OK if everything went well or ERROR if not.
 * @author Profesores PPROG
 */
STATUS game_create_from_file(Game* game, char* filename);


/**
 * @brief Is called after every input by the gameloop (main program)
 *        Redirects the given Commands to the corresponding callback functions and
 *        writes the Command followed by it's executing status in a logfile, if make_log_file is true.
 * @param Game*, Command*, BOOL that tells program to make a logfile or not,
          pointer to the logfile (ignored if make_log_file==FALSE)
 * @return OK if everything went well or ERROR if not.
 * @author Frederik Mayer
 */
STATUS game_update(Game* game, Command* cmd, BOOL make_log_file, FILE* logfile);


/**
 * @brief It frees all the memory reserved.
 * @param Game*
 * @return OK if everything went well or ERROR if not.
 * @author Profesores PPROG
 */
STATUS game_destroy(Game* game);

/**
 * @brief It checks if the game is over
 * @param Game*
 * @return TRUE if it's over or FALSE if not.
 * @author Profesores PPROG
 */
BOOL game_is_over(Game* game);

/**
 * @brief Prints the GUI of the game to the terminal.
 * @param Game*
 * @return None
 * @author Profesores PPROG
 */
void game_print_screen(Game* game);

/**
 * @brief Prints the relevant data of the game.
 * @param Game*
 * @return None
 * @author Profesores PPROG
 */
void game_print_data(Game* game);

/**
 * @brief Returns the Space* with the given Id.
 * @param Game*, Id of the Space* to be returned
 * @return Space* with entered Id
 * @author Oriana Nicole Pastor Sánchez
 */
Space* game_get_space(Game* game, Id id);

/**
 * @brief Returns the location of the player in the given Game*.
 * @param Game*
 * @return Space Id of the player
 * @author Frederik Mayer
 */
Id game_get_player_location(Game* game);

/**
 * @brief Returns a Set* with the space ids of all the objects of the given Game*.
 * warning: Object set is not a member variable -> allocating memory that has to be freed outside!
 * @param Game*
 * @return Set* with the object locations
 * @author Frederik Mayer
 */
Set* game_get_object_location_set(Game* game);

/**
 * @brief Returns the player of the given Game*.
 * @param Game*
 * @return Player*
 * @author Oriana Nicole Pastor Sánchez
 */
Player* game_get_player(Game* game);

/**
 * @brief Returns all the Object*s of the given Game*.
 * @param Game*
 * @return Returns an array of Object pointers!
 * @author Frederik Mayer
 */
Object** game_get_objects(Game* game);

/**
 * @brief Returns the Object* with the given object id.
 * @param Game*, object id
 * @return Object*
 * @author Frederik Mayer
 */
Object* game_get_object_with_id(Game* game, Id obj_id);

/**
 * @brief Returns all the Link*s of the given Game*.
 * @param Game*
 * @return Returns an array of Link pointers!
 * @author Frederik Mayer
 */
Link** game_get_links(Game* game);

/**
 * @brief Returns the Link* with the given object id.
 * @param Game*, link id
 * @return Link*
 * @author Frederik Mayer
 */
Link* game_get_link_with_id(Game* game, Id link_id);

/**
 * @brief Returns the dice of the given Game*.
 * @param Game*
 * @return Dice*
 * @author Oriana Nicole Pastor Sánchez
 */
Dice* game_get_dice(Game* game);

/**
 * @brief Returns the last command entered by the user as a struct.
 * @param Game*
 * @return Command*
 * @author Oriana Nicole Pastor Sánchez
 */
Command* game_get_last_command(Game* game);

/**
 * @brief Returns the description that is to be displayed at the moment.
 * @param Game*
 * @return description (String)
 * @author Frederik Mayer
 */
char* game_get_last_message(Game* game);

/**
 * @brief Returns the dice_failed variable.
 * @param Game*
 * @return TRUE if the result of the last dice throw was to high for the play ground
 *         FALSE if not
 * @author Frederik Mayer
 */
 BOOL game_get_dice_failed (Game* game);

 /**
 * @brief Returns the execution status of the last command entered by the user.
 * @param Game*
 * @return OK if everything went well or ERROR if not.
 * @author Frederik Mayer
 */
 STATUS game_get_last_status (Game* game);

 /* Dice_failed variable:
 * If the last dice roll led to an exceedance of the play ground,
 * an error message should be displayed in the feedback area.
 * This is told to the graphic engine by the variable dice_failed.*/
/**
 * @brief Sets the dice_failed variable.
 * @param Game*, BOOL
 * @return OK if everything went well or ERROR if not.
 * @author Frederik Mayer
 */
STATUS game_set_dice_failed (Game* game, BOOL dice_failed);

/**
 * @brief It sets the execution status of the last command entered by the user.
 *              Like dice_failed, this variable is used for communication between the
 *              modules Game and GraphicEngine.
 * @param Game*, STATUS
 * @return OK if everything went well or ERROR if not.
 * @author Frederik Mayer
 */
STATUS game_set_last_status (Game* game, STATUS status);

/**
 * @brief Sets the description that is to be displayed at the moment.
 * @param Game*
 * @return OK if everything went well or ERROR if not.
 * @author Frederik Mayer
 */
STATUS game_set_last_message(Game* game, const char* des);

/**
 * @brief Initializes the Game*.
 * @param None
 * @return Game*
 * @author Profesores PPROG
 */
Game* game_ini();

#endif
