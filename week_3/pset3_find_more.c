/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */

#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    bool result = false;

    if(n <= 0){
        return false;
    }
    int left = 0;
    int right = n - 1;

    while(left <= right){
        int middle = (int)((left + right) / 2);
        if(value == values[middle]){
            return true;
        }else if(value < values[middle]){
            right = middle - 1;
        }else{
            left = middle + 1;
        }
    }
    return result;
}

/**
 * Sorts array of n values.
 */
//  n is the size of the array
void sort(int values[], int n)
{
    // TODO: implement a sorting algorithm
    //counting sort
    int copy[n];
    //make a duplicate of the values
    int current = 0;

    for (int i = 0; i < n; ++i)
    {
    	copy[i] = values[i];
    }
    //find the maximum in the values[]
    int max = 0;
    for (int i = 0; i < n; ++i)
    {
    	if (max < values[i])
    	{
    		max = values[i];
    	}
    }
    //create the counting array and initialize it
    int count[max];
    for (int i = 0; i < max; ++i)
    {
    	count[i] = 0;
    }

    //count how many times occured for each integer
    for (int i = 0; i < n; ++i)
    {
    	count[values[i]] += 1;
    }

    //sorting
    current = 0;
    for (int i = 0; i < max; ++i)
    {
    	if (count[i] > 0)
    	{
    		for (int k = 0; k < count[i]; ++k)
    		{
    			copy[current] = i;
    			current += 1;
    		}
    	}
    }

    //return sorted
    for (int i = 0; i < n; ++i)
    {
    	values[i] = copy[i];
    }
    return;
}