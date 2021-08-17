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

#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};
  //print original array
  printf("Original array: \n");
  print_array(test,SIZE);
  //sort array and print the result
  sort_array(test, SIZE);
  printf("Sorted array: \n");
  print_array(test,SIZE);
  //print stats
  print_statistics(test, SIZE);
}

unsigned char find_maximum(unsigned char* data, unsigned int length){
    //return 0 if array is empty
    if (length<1) return 0;   
    unsigned char max_v = data[0]; //initialize with the first element
    // Loop through the elements and find the largest
    for (int i = 1; i < length; i++){
        //compare the current max_v with the current element
        //replace max_v with current element if it is larger
        max_v = (max_v<data[i])?data[i]:max_v;
    }
    return max_v;
}

unsigned char find_minimum(unsigned char* data, unsigned int length){
    //return 0 if array is empty
    if (length<1) return 0;   
    unsigned char min_v = data[0]; //initialize with the first element
    // Loop through the elements and find the largest
    for (int i = 1; i < length; i++){
        //compare the current min_v with the current element
        //replace min_v with current element if it is smaller
        min_v = (min_v>data[i])?data[i]:min_v;
    }
    return min_v;
}

unsigned char find_mean(unsigned char* data, unsigned int length){
    //return 0 if array is empty
    if (length<1) return 0;
    float avg = 0;
    for (int i=0; i<length; i++){
        avg += (float)data[i]/(float)length;
    }
    return (int)avg;//rounded down
}

static void swap(unsigned char *xp, unsigned char *yp){
    unsigned char temp = *xp;
    *xp = *yp;
    *yp = temp;
}

//insertion sort: O(n^2), O(1)
static void insertion_sort(unsigned char* data, unsigned int n){
    //stop if array has 0 or 1 element
    if (n<2) return;
    for (int i=0; i<n-1; i++){
        for (int j=i+1; j<n; j++){
            if (data[i]<data[j]) swap(&data[i], &data[j]);
        }
    }
}

void sort_array(unsigned char* data, unsigned int length){
    insertion_sort(data,length);
}

unsigned char find_median(unsigned char* data, unsigned int length){
    //Assume data is sorted
    int idx = length / 2;
    unsigned int median = 0;

    if ((length%2) == 0)
        median = (data[idx]+data[idx+1])/2;
    else
        median = data[idx];
    
    return median;
}

void print_statistics(unsigned char* data, unsigned int length){
    unsigned char min, max, mean, median;
    min = find_minimum(data, length);
    max = find_maximum(data, length);
    mean = find_mean(data, length);
    median = find_median(data, length);
    printf("*******Statistics Of The Array********\n");
    printf("Maximum Value: %d\n",max);
    printf("Minimum Value: %d\n",min);
    printf("Mean Value: %d\n",mean);
    printf("Median Value: %d\n",median);
}

void print_array(unsigned char* data, unsigned int length){
    int numElementsPerLine = 8;
    int cnt = 0;
    for (int i=0; i<length; i++){
        cnt++;
        printf("%8d", data[i]);
        if (cnt>=numElementsPerLine){
            printf("\n");
            cnt = 0;
        }
    }
}