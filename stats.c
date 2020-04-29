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
 * @brief this program will print a given array and some basic stats 
 *
 * this program will print some basic stats: median, mean, max, min of the 
 * given array it will sort the array in place to find median. Some basic
 * error checking in the functions 
 *
 * @author Craig Goble 
 * @date 4/28/2020 
 *
 */


#include <stdbool.h>
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

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */
  print_array(test,SIZE);
  print_statistics(test,SIZE);
}

/* Add other Implementation File Code Here */
void print_array(unsigned char *values,int n){
  for(int i=0;i<n;i++){
    if(i%9 == 0 && i > 0) printf("\n");
    if( i < n-1) printf("%3d,",values[i]);
    else printf("%3d\n",values[i]);
  }
}

void print_statistics(unsigned char *values,int n){
 printf("Maximum: %-3d\nMinimum: %-3d\nMean:    %-3d\nMedian:  %-3d\n",
        find_maximum(values,n),
        find_minimum(values,n),
        find_mean(values,n),
        find_median(values,n));
}

void sort_array(unsigned char *values,int n){
 sort_array_recursive( values,0,n-1);
}

void sort_array_recursive(unsigned char *values, int left, int right){
  if(left == right) return;
  int end = right;
  int start = left;
  while(start < end) {
    if (values[end] > values[end-1]) {
      swap_values(values,end,end-1);
      end--;
    } else {
      swap_values(values,start,end-1);
      start++;
    } 
  }
  //start and end are the same value
  if(start > left) sort_array_recursive(values,left,start-1);
  if(right > end ) sort_array_recursive(values,end+1,right);
}

void swap_values(unsigned char *values,int posA,int posB){
  unsigned char temp = values[posA];
  values[posA] = values[posB];
  values[posB] = temp;
}

unsigned char find_median(unsigned char *values,int n){
  // pretty ineffecian to sort it could use two queues instead
  if( n == 0) return 0;
  if( !is_array_in_order(values,n) ) sort_array( values,n);
  if(n%2 == 1) return values[n/2];
  return (values[n/2]+values[n/2-1])/2;
}


unsigned char find_mean(unsigned char *values,int n){
  if( n == 0) return 0;
  int sum = 0;
  for(int i=0;i<n;i++) sum += values[i];
  return sum/n;
}

unsigned char find_maximum(unsigned char *values,int n){
  if( n == 0) return 0;
  int max = values[0];
  for(int i=1;i<n;i++)
    if(values[i] > max) max = values[i];
  return max;
}

unsigned char find_minimum(unsigned char *values,int n){
  if( n == 0) return 0;
    int min = values[0];
    for(int i=1;i<n;i++)
    if(values[i] < min ) min = values[i];
  return min;
}

bool is_array_in_order(unsigned char *values,int n){
  if( n<2) return 1;
  for(int i=1;i<n;i++){
    if(values[i] > values[i-1]) return 0;   
  }  
  return 1;
}
