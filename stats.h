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
 * @file stats.h
 * @brief fuctions that return common stats  
 *
 * code will have fuctions for sort,median,mean,maximum,minimum, and sort.
 *
 * @author Craig Goble 
 * @date 4/28/2020 
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/**
 * @brief prints basics stats about an array
 *
 * the print_statistics fuctions takes in an unsigned
 * char char array and prints the minimum,maximum,mean 
 * and median values. 
 *
 * @param values is a unsigned char array
 * @param n is the size of the array
 *
 * @return void this prints the values to stdout
 */
void print_statistics(unsigned char *values,int n);

/**
 * @brief prints the elements in an array
 *
 * the print_array fuction takes prints each element
 * of an unsigned char array to stdout. It prints
 * 10 elements per line.
 *
 * @param values is a unsigned char array
 * @param n is the size of the array
 * 
 * @return void this prints the values to stdout
 */
void print_array(unsigned char *values,int n);

/**
 * @brief sorts the array in desending order
 *
 * sorts the array using quick sort
 *
 * @param values is a unsigned char array
 * @param n is the size of the array
 * 
 * @return void this simply modifies the array in place
 */
void sort_array(unsigned char *values,int n);

/**
 * @brief recursive fuction for sort_array 
 *
 * sorts the array in sections using quick sort
 *
 * @param values is a unsigned char array
 * @param n is the size of the array
 * @param left starting element
 * @param right last element
 * 
 * @return void this simply modifies the array in place
 */
void sort_array_recursive(unsigned char *values,int left, int right);

/**
 * @brief swap two values in an arary 
 *
 * given two indexs of elements swap them by reference 
 * in an a given array
 *
 * @param values is a unsigned char array
 * @param posA position of the element
 * @param posB position of the second element 
 * 
 * @return void this simply modifies the array in place
 */
void swap_values(unsigned char *values,int posA,int posB);

/**
 * @brief return s the median of an array
 *
 * this function either returns the middle element
 * if array size is odd or the the aveage of 
 * the middle two elements if even. It will round
 * down the answer if its not a whole number 
 *
 *
 * @param values is a unsigned char array
 * @param n is the size of the array
 * 
 * @return unsigned char median value
 */
unsigned char find_median(unsigned char *values,int n);

/**
 * @brief returns the average value of an array
 * 
 * this function returns the average value if
 * the size is 0 then in returns 0. It will round
 * down the answer if its not a whole number
 *
 *
 * @param values is a unsigned char array
 * @param n is the size of the array
 * 
 * @return unsigned char mean value
 */
unsigned char find_mean(unsigned char *values,int n);

/**
 * @brief return the maximum value in the array
 *
 * this funcion goes  through the whole arary
 * and find the largest value. it does not
 * presume the array is sorted in any way
 *
 * @param values is a unsigned char array
 * @param n is the size of the array
 * 
 * @return unsigned char maximum value 
 */
unsigned char find_maximum(unsigned char *values,int n);

/**
 * @brief return the minimum value in the array
 *
 * this funcion goes  through the whole arary
 * and find the smallest value. it does not
 * presume the array is sorted in any way 
 *
 * @param values is a unsigned char array
 * @param n is the size of the array
 * 
 * @return unsigned char minimum value
 */
unsigned char find_minimum(unsigned char *values,int n);

/**
 * @brief return true if the array is in order 
 *
 * this funcion goes  through the whole arary
 * comparing the digit to the one before it
 *
 * @param values is a unsigned char array
 * @param n is the size of the array
 * 
 * @return bool true if in order 
 */
bool is_array_in_order(unsigned char *values,int n);

#endif /* __STATS_H__ */
