/**
 * @brief It defines common types
 *
 * @file types.h
 * @author Profesores PPROG
 * @version 1.0
 * @date 13-01-2015
 * @copyright GNU Public License
 */


#ifndef TYPES_H
#define TYPES_H

/**maximum size of a word*/
#define WORD_SIZE 1000
/**length of a line on the board between the '|'*/
#define LINE_SIZE 11
/**default value for variables of type Id*/
#define NO_ID -1

/**if check space is typed by the user, the id variable gets set to SPACE_CHECK,
  the description of the current space is printed.*/
#define SPACE_CHECK -2

/**whole number identifying objects of an ADT*/
typedef long Id;

/**Boolean values*/
typedef enum {
  FALSE, TRUE
} BOOL;

/**used for various functions and tests*/
typedef enum {
  ERROR, OK
} STATUS;

/**Movements on the game board (North, South, East, West)*/
typedef enum {
  N, S, E, W
} DIRECTION;

/**used to tell graphic_engine_paint_space where the space is to be painted on the screen.*/
typedef enum {
  TOP, MIDDLE, BOTTOM
} POS;

/**links can be either closed or open in the game.*/
typedef enum {
  OPEN, CLOSED
} LINK_STATUS;


#endif
