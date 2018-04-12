/**
 * @brief It defines a screen
 *
 * @file screen.h
 * @author Profesores PPROG
 * @version 1.0
 * @date 11-01-2017
 * @copyright GNU Public License
 */

#ifndef __SCREEN__
#define __SCREEN__

/**Maximum width of the screen in letter widths*/
#define SCREEN_MAX_STR 80


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**ADT defining an Area on the screen*/
typedef struct _Area Area;

/**
 * @brief Initializes the screen.
 * @param None
 * @return None
 * @author Profesores PPROG
 */
void  screen_init();

/**
 * @brief Destroys the screen.
 * @param None
 * @return None
 * @author Profesores PPROG
 */
void  screen_destroy();

/**
 * @brief Paints the screen.
 * @param None
 * @return None
 * @author Profesores PPROG
 */
void  screen_paint();

/**
 * @brief Reads a line of input from the screen's input prompt.
 * @param None
 * @return None
 * @author Profesores PPROG
 */
void  screen_gets(char *str);

/**
 * @brief Initializes an Area on the screen
 * @param x, y value of left higher corner, width, height of the area
 * @return Area*
 * @author Profesores PPROG
 */
Area* screen_area_init(int x, int y, int width, int height);

/**
 * @brief Destroys an Area on the screen
 * @param Area*
 * @return None
 * @author Profesores PPROG
 */
void  screen_area_destroy(Area* area);

/**
 * @brief Deletes the content that was printed in the given area.
 * @param Area*
 * @return None
 * @author Profesores PPROG
 */
void  screen_area_clear(Area* area);

/**
 * @brief Resets the cursor.
 * @param Area*
 * @return None
 * @author Profesores PPROG
 */
void  screen_area_reset_cursor(Area* area);

/**
 * @brief Prints a string into an area on the screen
 * @param Area*, string to be printed
 * @return None
 * @author Profesores PPROG
 */
void  screen_area_puts(Area* area, char *str);

#endif
