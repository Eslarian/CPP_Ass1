/******************************************************************************
 * COSC1254 - Programming Using C++
 * Semester 2 2016 - Assignment #1
 * Full Name        : Emile Antognetti
 * Student Number   : s3488934
 * Course Code      : COSC1254_1650
 * Program Code     : BP094
 *****************************************************************************/

FUNCTIONALITY
*******************************************************************************

The assigment is missing the following functionality:

--multiple commands (e.g. --g --g 10 5 --sv file.svg)
--checking malformed input files


All other functionality should be operational as per spec. 
Note, svg colors have been switched for visibility:
White is for background, black is used for walls.

CODING PRACTICE
*******************************************************************************
Variable names are camel cased
Function names are underscored
Xterm screen character limit (almost)always respected


BUGS
*******************************************************************************
Maze generation seems imperfect, but after inspection seems to be a limitation
of the generation algorithm. Still unsure. 
Entrance and exits are denoted by a missing wall along an edge, although if
they on a coner it seems it will break both corner walls