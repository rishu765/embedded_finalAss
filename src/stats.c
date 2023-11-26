/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c
 * @brief The implementation file of the c1m1 assignment
 *
 * This file includes all the required functions implementations in the c1m1 assignment
 *
 * @author Rishabh Gupta
 * @date 26/11/2023
 *
 */



#include <stdio.h>
#include "../include/common/stats.h"
#include "../include/common/platform.h"

/* Size of the Dataset */
#define SIZE (40)



void print_statistics (unsigned char minimum, unsigned char maximum, float mean, unsigned char median){
  printf("The minimum is %d \n", minimum);
  printf("The maximum is %d \n", maximum);
  printf("The mean is %f \n", mean);
  printf("The median is %d \n", median);
}


void print_array (unsigned char *array, unsigned int counter){
  
}


unsigned char find_median (unsigned char *array, unsigned int counter){
  unsigned char median = 0;
  median = *(array + (counter / 2) -1);
  return median;
}

float find_mean (unsigned char *array, unsigned int counter){
  unsigned int accumulator = 0; // variable to store the accumulator value throughout the mean finding process
  float mean = 0;
  for (int i=0; i<counter; i++){
    accumulator = accumulator + array[i] /* *(array + i) */;
  }
  printf("acc = %d \n", accumulator);
  mean = accumulator / ((float) counter); //must type cast one of the two integers to float for accurate calculation.
  return mean;
}

unsigned char find_maximum (unsigned char *array, unsigned int counter){
  unsigned char maximum = *array; // initalize the maximum variable with the value of the first array element
  for (int i=1; i<counter; i++){ // start the loop from the second elemnt
    if (*(array + i) > maximum){
      maximum = *(array + i);
    }
    else {} // do nothing.
  }
  return maximum;
}

unsigned char find_minimum (unsigned char *array, unsigned int counter){
  unsigned char minimum = *array; // initalize the minimum variable with the value of the first array element
  for (int i=1; i<counter; i++){ // start the loop from the second elemnt
    if (*(array + i) < minimum){
      minimum = *(array + i);
    }
    else {} // do nothing.
  }
  return minimum;
}

void sort_array (unsigned char *array, unsigned int counter){
  char flag = 0; //this flag is to indicate if a swap process has occurred at least once in the loop
  unsigned char temp;
  do {
    flag =0; //set flag to default at every new 'do' operation
    for (int index=0; index<counter; index++){
      if (array[index] > array[index +1] || array[index] == array[index +1]) {
        continue;
      }
      else if (array[index] < array[index +1]) {
        //swap elements//
        temp = array[index];
        array[index] = array[index+1];
        array[index+1] = temp;

        flag = 1; // a swap process has occurred at least once in this loop
      }
    }
  }
  while (flag ==1); // the array is not sorted as long as a swap operation is occurred at least once
}
