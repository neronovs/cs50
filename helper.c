/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool normSearch(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    for (int i = 0; i < n; i++) {
        if (value < 0) return false;
        if (values[i] == value) return true;
    }
    return false;
}

int binary_search(int x, int a[], int l ,int r)
{
    int mid = 0;
    
    while(r - l > 3)
        //while the result is not actual
        {
        mid = (l + r) / 2;
        //get the middle val of [l,r]
        if(a[mid] < x)
        //check the way where we are looking for a val
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    //the cycle to check the needle
    //[l,r]
    for (int i = l; i <= r; i++)
        if(a[i] == x)
            return i; //found the needle
            
    return -1;// return that we did not finf the needle

}

bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    //if (normSearch(value, values, n)) return true;
    
    if (binary_search(value, values, 0, n-1) != -1) return true;
    
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    int buffer = 0;
    // TODO: implement an O(n^2) sorting algorithm
    for (int i = 0; i < n; i++) {
        for (int o = 0; o < i; o++) {
            if (values[o] < values[i]) {
                buffer = values[i];
                values[i] = values[o];
                values[o] = buffer;
            }
        }
    }
    return;
}
