/**
 * @file
 * @brief Auxiliary stuff for level 2 HAL.
 */

#ifndef L2HAL_INCLUDE_L2HAL_AUX_H_
#define L2HAL_INCLUDE_L2HAL_AUX_H_

#include <stddef.h>
#include <stdint.h>

/**
 * Boolean type and values.
 */
#define bool uint8_t
#define true 0xFF
#define false 0x00

/**
 * Macroses for minimal and maximal values.
 */
#define MIN(x, y) (((x) < (y)) ? (x) : (y))
#define MAX(x, y) (((x) > (y)) ? (x) : (y))

/************************
 * Memory-related stuff *
 ************************/

/**
 * Frees memory and set pointer to NULL.
 * @param ptr Pointer, pointing to memory to be freed.
 */
void AUX_Mem_SafeFree(void* ptr);


/*************************
 * Strings-related stuff *
 *************************/

/**
 * Returns substring of string. Returned value points to newly-allocated memory, so don't forget to free it.
 * @param string Pointer to string.
 * @param start First substring character index in string.
 * @param length Substring length.
 * @return Pointer to substring (points to newly-allocated memory).
 */
char* AUX_Str_Substring(char* string, uint16_t start, uint16_t length);

/**
 * Merges two strings into one, allocating memory for it. Don't forget to free result memory.
 * @param str1 Pointer to first string.
 * @param str2 Pointer to second string
 * @return Pointer to newly-allocated memory, containing merged string.
 */
char* AUX_Str_MergeStrings(char* str1, char* str2);


#endif /* L2HAL_INCLUDE_L2HAL_AUX_H_ */
