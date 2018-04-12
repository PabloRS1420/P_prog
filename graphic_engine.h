/**
 * @brief It defines a textual graphic engine
 *
 * @file graphic_engine.h
 * @author Profesores PPROG
 * @version 1.0
 * @date 18-01-2017
 * @copyright GNU Public License
 */

#ifndef __GRAPHIC_ENGINE__
#define __GRAPHIC_ENGINE__

#include "game.h"
#include "screen.h"

/**in the current GUI, there is only space for 4 objects per line,
  (could be changed for future versions if needed)*/
#define MAX_OBJ_PER_SP  4

/**defines a graphic engine to display the content of the game*/
typedef struct _Graphic_engine Graphic_engine;

/**
 * @brief Creates a GraphicEngine
 * @param None
 * @return Graphic_engine*
 * @author Profesores PPROG
 */
Graphic_engine* graphic_engine_create();

/**
 * @brief Destroys the GraphicEngine
 * @param Graphic_engine*
 * @return None
 * @author Profesores PPROG
 */
void graphic_engine_destroy(Graphic_engine *ge);

/**
 * @brief Paints the game.
 * @param Game*, Graphic_engine*
 * @return None
 * @author Profesores PPROG
 */
void graphic_engine_paint_game(Graphic_engine *ge, Game *game);

/**
 * @brief Writes a command.
 * @param Graphic_engine*, string
 * @return None
 * @author Profesores PPROG
 */
void graphic_engine_write_command(Graphic_engine *ge, char *str);

#endif
