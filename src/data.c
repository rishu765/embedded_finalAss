/**
 * @file data.c
 * @brief Abstraction of the basic data manipulation operations
 *
 * This implementation file provides an abstraction of the basic data manipulation operations
 * like converting integer to string and vice versa via function calls.
 * 
 * @author Rishabh Gupta
 * @date 26/11/2023
 *
 */


#include "../include/common/memory.h"
#include "../include/common/data.h"
#include "../include/common/platform.h"
#include <stdint.h>
#include <stddef.h>

uint8 my_itoa(int32 data, uint8 * ptr, uint32 base)
{
  uint8 isNegative= 0;
  uint8 digitCounter= 0;
  uint8 remainder= 0;  

  // Check if data is zero
  if (data == 0)
  {
    *(ptr) = '0';
    *(ptr + 1) = '\0';
    return 2;
  }
  
  // Check if data is negative
  if (data < 0)
  {
    isNegative = 1;
    data = data*-1;
  }  
  // Convert int to ASCII for all bases
  while (data != 0)
  {
    remainder = data % base;
    *(ptr + digitCounter)= ( remainder > 9 ) ? ( remainder - 10 ) + 'a' : remainder + '0';
    digitCounter++;
    data= data / base;
  }  
  // Add -ve sign if negative data
  if (isNegative)
  {
    *(ptr + digitCounter) = '-';
    digitCounter++;
  }  
  digitCounter++;
  *(ptr + digitCounter) = '\0';

  // Reverse the string index order  
  my_reverse(ptr, (digitCounter - 1));
  
  return digitCounter;
}


