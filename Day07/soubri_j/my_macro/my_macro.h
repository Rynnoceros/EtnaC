/*                                                                                                               
** ETNA PROJECT, 15/10/2018 by soubri_j                                                                          
** my_macro.h                                                                                                
** File description:                                                                                             
**      File containing macros.
*/
#ifndef _MY_MACRO_H_
#define _MY_MACRO_H_

#define MY_ABS(x) (x < 0 ? x * -1 : x)

#define MY_ISNEG(x) (x < 0 ? 1 : 0)

#define MY_MAX(x, y) (x < y ? y : x)

#define MY_MIN(x, y) (x < y ? x : y)

#define MY_IS_PRINTABLE(c) (((c >= 0 && c < 32) || c == 127) ? 0 : 1)

#define MY_IS_ALPHA(c)(((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) ? 1 : 0)

#define MY_IS_NUM(c) ((c >= '0' && c <= '9') ? 1 : 0)

#define MY_IS_ALPHANUM(c) ((MY_IS_ALPHA(c) || MY_IS_NUM(c)) ? 1 : 0)

#define MY_IS_LOWCASE(c) ((c >= 'a' && c <= 'z') ? 1 : 0)

#define MY_IS_UPPERCASE(c) ((c >= 'A' && c <= 'Z') ? 1 : 0)

#endif
