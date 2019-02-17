/*
 * l2hal_aux.h
 * Auxiliary stuff for Level 2 HAL.
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

/************************
 * Memory-related stuff *
 ************************/

/**
 * Frees memory and set pointer to NULL.
 */
void AUX_Mem_SafeFree(void* ptr);

/*******************************
 * End of memory-related stuff *
 *******************************/

/*************************
 * Strings-related stuff *
 *************************/

/**
 * Returns substring of string. Returned value points to newly-allocated memory, so don't forget to free it.
 */
char* AUX_Str_Substring(char* string, uint16_t start, uint16_t length);

/**
 * Merges two strings into one, allocating memory for it. Don't forget to free result memory.
 */
char* AUX_Str_MergeStrings(char* str1, char* str2);

/********************************
 * End of strings-related stuff *
 ********************************/

#endif /* L2HAL_INCLUDE_L2HAL_AUX_H_ */
