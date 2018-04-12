/**
 * @brief It implements the command interpreter
 *
 * @file command.h
 * @author Oriana Pastor
 * @version 1.0
 * @date 20-03-18
 * @copyright GNU Public License
 */

#ifndef COMMAND_H
#define COMMAND_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

#include "types.h"

/**Maximum length of a command*/
#define CMD_LENGHT 30

/**number of valid commmands, each of them corresponding to a callback function
  (NO_CMD doesn't have a callback, MOVE calls following, etc.)*/
#define N_CMD 12

/**valid commands for the user to influence the game*/
typedef enum enum_Command {
  NO_CMD = -1,
  UNKNOWN,
  EXIT,
  FOLLOWING,
  PREVIOUS,
  GRAB,
  LEAVE,
  ROLLDICE,
  LEFT,
  RIGHT,
  CHECK,
  MOVE} T_Command;

/** ADT that contains a command and an id*/
typedef struct _Command Command;

 /**
  * @brief Reads the command entered by the player
  * @param None
  * @return Command*
  * @author Oriana Nicole Pastor Sánchez
  */
Command* command_get_user_input();

 /**
 * @brief Reserves memory for a Command* initialising the struct.
 * @param None
 * @return New Command*
 * @author Oriana Nicole Pastor Sánchez
 */
Command* command_create();

/**
 * @brief Frees all the memory reserved.
 * @param Command* to be destroyed.
 * @return OK if everything went well or ERROR if not.
 * @author Oriana Nicole Pastor Sánchez
 */
STATUS command_destroy(Command* c);

/**
 * @brief Sets the T_Command variable of the Command struct.
 * @param Command*, T_Command
 * @return OK if everything went well or ERROR if not.
 * @author Oriana Nicole Pastor Sánchez
 */
STATUS command_set_command(Command* c, T_Command tc);

/**
 * @brief Sets the Id variable of the Command struct
 * (object id for grab, NO_ID for other commands).
 * @param Command*, Id of the object to be grasped.
 * @return OK if everything went well or ERROR if not.
 * @author Oriana Nicole Pastor Sánchez
 */
STATUS command_set_id(Command* c, Id id);

/**
 * @brief Returns the T_Command variable of the Command struct.
 * @param Command*
 * @return T_Command
 * @author Oriana Nicole Pastor Sánchez
 */
T_Command command_get_command(Command* c);

/**
 * @brief Returns the Id variable of the Command struct
 * (object id for grab, NO_ID for other commands).
 * @param Command*
 * @return Id
 * @author Oriana Nicole Pastor Sánchez
 */
Id command_get_id(Command* c);

#endif
