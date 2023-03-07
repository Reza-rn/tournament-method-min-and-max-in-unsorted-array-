//
//  main.cpp
//  max_min_tournament_method
//
//  Created by Reza Roofegari nejad
//

/* *************************************************
Libraries and header files
*****************************************************/

#include "List.h"

/* *************************************************
struct which contains min and max
*****************************************************/
typedef struct _Pair
{
	int min;
	int max;
} Pair;

/* ************************************************************************************************
Helper function to find min and max of the given array

 @param arr[]       Given array to find min and max
 @param size        Size of the given array
 @param min_max     Pointer to the min and max struct
 *********************************************************************************************** */
void get_min_max_get(int arr[], int size, Pair *min_max)
{
	List min_list;
	List max_list;

	// create two min and max list
	for (int index = 0; index < size; index += 2)
	{
		if (arr[index] <= arr[index + 1])
		{
			min_list.insert(arr[index]);
			max_list.insert(arr[index + 1]);
		}
		else
		{
			min_list.insert(arr[index + 1]);
			max_list.insert(arr[index]);
		}
	}

	// find min in the min_list
	min_max->min = min_list.find_min();

	// find max in the max_list
	min_max->max = max_list.find_max();
}


/* ************************************************************************************************
Main function to find min and max of the given array

 @param arr[]       Given array to find min and max
 @param size        Size of the given array
 @param min_max     Pointer to the min and max struct
 *********************************************************************************************** */
void get_min_max(int arr[], int size, Pair *min_max)
{
	// check if the array is even or odd
	if (size % 2 == 0)
	{
		// If it is even just use given array

		// call helper function to find max and min
		get_min_max_get(arr, size, min_max);
	}
	// If it is odd, we should remove one element and work on the remaining elements.
	// At the end, we should compare the excluded element with the found max and min elements.
	else
	{
		int *new_arr = new int[size - 1];

		for (int i = 1; i < size; i++)
		{
			new_arr[i - 1] = arr[i];
		}

		// call helper function to find max and min
		get_min_max_get(new_arr, size-1, min_max);

		// compare found max and min with the excluded one
		// check min
		if (arr[0] < min_max->min)
		{
			min_max->min = arr[0];
		}

		//check max
		if (min_max->max < arr[0])
		{
			min_max->max = arr[0];
		}

		delete[] new_arr;
	}
}


/* ************************************************************************************************
Main function
 *********************************************************************************************** */
int main()
{
	int arr[] = { 1000, 1, 569 , 387, 4, 98, 300, 4567, 10000, 11346, 4, 24, 1333 };
	int size = sizeof(arr) / sizeof(arr[0]);

	Pair MinMax = {0 , 0};

	// Call main function to find min and max
	get_min_max(arr, size, &MinMax);

	cout << "Minimum element is: " << MinMax.min << endl;
	cout << "Maximum element is: " << MinMax.max << endl;

	return 0;
}



