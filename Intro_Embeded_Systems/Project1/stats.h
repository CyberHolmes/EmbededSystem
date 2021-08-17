/******************************************************************************
 * Copyright (C) 2021 by Hailin Archer
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Hailin Archer not liable for any misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.h 
 * @brief Functions to analyze an array of unsigned char data items
 *
 * This file contains functions that takes an input of an array of unsigned
 * char data items. Those functions calculate maximum, mean, and median of the
 * data set, reorder this data set from large to small, and print the result
 * to the screen in nicely formatted presentation.
 *
 * @author Hailin Archer
 * @date 8/15/2021
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 

/**
 * @brief Find the maximum element of the input array of unsigned char data items
 *
 * This function takes as an input an array of unsigned char data items and its
 * length. It returns an unsigned char that is the maximum element of the input.
 *
 * @param data an array of unsigned char
 * @param length length of data, the input array
 *
 * @return The maximum element of data
 */
unsigned char find_maximum(unsigned char* data, unsigned int length);

/**
 * @brief Find the minimum element of the input array of unsigned char data items
 *
 * This function takes as an input an array of unsigned char data items and its
 * length. It returns an unsigned char that is the minimum element of the input.
 *
 * @param data an array of unsigned char
 * @param length length of data, the input array
 *
 * @return The minimum element of data
 */
unsigned char find_minimum(unsigned char* data, unsigned int length);

/**
 * @brief Find the mean of the input array of unsigned char data items
 *
 * This function takes as an input an array of unsigned char data items and its
 * length. It returns an unsigned char that is the mean of the input. The mean
 * is rounded down to the nearest integer.
 *
 * @param data an array of unsigned char
 * @param length length of data, the input array
 *
 * @return The mean of data (rounded down to the nearest integer)
 */
unsigned char find_mean(unsigned char* data, unsigned int length);

/**
 * @brief Find the median of the input array of unsigned char data items
 *
 * This function takes as an input an array of unsigned char data items and its
 * length. It returns an unsigned char that is median element of the input.
 *
 * @param data an array of unsigned char
 * @param length length of data, the input array
 *
 * @return The median element of data
 */
unsigned char find_median(unsigned char* data, unsigned int length);

/**
 * @brief Swap the value of two unsigned chars
 * 
 * This function takes two pointers to unsigned chars and swap them.
 * This is a helper function for sorting.
 * 
 * @param xp pointer to an unsigned char
 * @param yp pointer to an unsigned char
 * 
 * @return void
 */
 static void swap(unsigned char *xp, unsigned char *yp);

/**
 * @brief Sort the elements of the input array of unsigned char data items from
 * the largest to the smallest
 *
 * This function takes as an input an array of unsigned char data items and its
 * length. It sorts the array from the largest to the smallest.
 *
 * @param data_in an array of unsigned char
 * @param length length of data, the input array
 *
 * @return
 */
void sort_array(unsigned char* data_in, unsigned int length);

/**
 * @brief Print the elements of the input array of unsigned char data items
 *
 * This function takes as an input an array of unsigned char data items and its
 * length. It prints the array to the screen.
 *
 * @param data an array of unsigned char
 * @param length length of data, the input array
 *
 * @return
 */
void print_array(unsigned char* data, unsigned int length);

/**
 * @brief Print the statistics of the input array of unsigned char data items
 *
 * This function takes as an input an array of unsigned char data items and its
 * length. It prints the statistics to the screen.
 *
 * @param data an array of unsigned char
 * @param length length of data, the input array
 *
 * @return
 */
void print_statistics(unsigned char* data, unsigned int length);

#endif /* __STATS_H__ */