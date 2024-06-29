#include "Header.h"

//1
// Function to perform selection sort on an array
void SelectionSort(int *arr, int n, long long &comp) {
    // Perform n-1 passes through the array
    for (int i = 0; ++comp && i < n - 1; i++) {
        int minIndex = i;
        
        // Find the minimum element in the unsorted part of the array
        for (int j = i + 1; ++comp && j < n; j++) {
            if (++comp && arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        
        // Swap the found minimum element with the first element
        if (++comp && minIndex != i) {
            Swap(arr[minIndex], arr[i]);
        }
    }
}

//2
// Function to perform insertion sort on an array
void InsertionSort (int *arr, int n, long long &comp) 
{
	int key, j;
    
    // Iterate through each element of the array
    for (int i = 1; ++comp && i < n; i++) 
    {
        key = arr[i];
        j = i - 1;
        
        // Move elements of arr[0..i-1] that are greater than key
        // to one position ahead of their current position
        while ((++comp && key <= arr[j]) && 
			   (++comp && j >= 0)) 
               {
			   	
            arr[j + 1] = arr[j];
            j--;
        }
        
        // Place key at the correct position
        arr[j + 1] = key;
    }
}


//3
// Function to perform shell sort on an array
void ShellSort(int *arr, int n, long long &comp) 
{
    // Start with a big gap, then reduce the gap
    for (int gap = n/2; ++comp && gap > 0; gap /= 2) 
    {
        // Perform a gapped insertion sort for this gap size
        for (int i = gap; ++comp && i < n; i++) 
        {       
			int temp = arr[i];
            int j;
            
            // Shift elements of arr[0..i-gap] that are greater than temp
            // to one position ahead of their current position
            for (j = i; (++comp && j >= gap) && (++comp && arr[j - gap] > temp); j -= gap) 
            {
                arr[j] = arr[j - gap];
            }
            
            // Place temp at the correct position
            arr[j] = temp;
        }
    }
}


//4
// Function to perform bubble sort on an array
void BubbleSort(int *arr, int n, long long &comp) 
{
    // Perform n-1 passes through the array
    for (int i = n - 1; ++comp && i > 0; i--) 
    {
        bool swaped = 0;	
        // Swap adjacent elements if they are in the wrong order
        for (int j = 0; ++comp && j < i; j++) 
        {
            if (++comp && arr[j] > arr[j + 1]) 
            {
                Swap (arr[j], arr[j + 1]);
                swaped = 1;
            }
        }
        if(comp++ && swaped == 0)
            break;
    }
}


// Function to rebuild the heap
void HeapRebuild(int pos, int *arr, int n, long long &comp) 
{
    int k = pos;
    bool isHeap = false;
    int num = 2*k + 1;
    
    // Rebuild the heap from the given position
    while ((++comp && !isHeap) && 
		   (++comp && num < n)) 
           {
				
        int j = num;
        
        // Find the larger of the two children
        if (++comp && j < n - 1) 
        {
            if (++comp && arr[j] < arr[j + 1]) 
            {
                j++;
            }
        }
        
        // If the parent is larger than or equal to the largest child, stop
        if (++comp && arr[k] >= arr[j]) 
        {
            isHeap = true;
        } 
		
		else 
        {
            // Otherwise, swap the parent with the largest child
            Swap(arr[k], arr[j]);
            k = j;
            num = 2*k + 1;
        }
    }
}

// Function to construct a heap from an array
void HeapConstruct(int *arr, int n, long long &comp) 
{
    int index = n/2 - 1;
    
    // Build the heap from the bottom up
    while (++comp && index >= 0) 
    {
        HeapRebuild (index, arr, n, comp);
        index--;
    }
}

//5
// Function to perform heap sort on an array
void HeapSort (int *arr, int n, long long &comp) 
{
    // First, build the heap
    HeapConstruct (arr, n, comp);
    
    int r = n - 1;
    
    // Extract elements from the heap one by one
    while (++comp && r > 0) 
    {
        // Move the current root to the end
        Swap (arr[0], arr[r]);
        // Rebuild the heap for the reduced array
        HeapRebuild (0, arr, r, comp);
        r--;
    }
}


//6
// Function to merge two halves of an array
void Merge(int *arr, int left, int mid, int right, long long &comp) 
{
    // Size of temporary arrays
    int leftSize = mid - left + 1;
    int rightSize = right - mid;
    
    // Initiate temporary arrays
    int* leftArr = new int[leftSize];
    int* rightArr = new int[rightSize];
    
    // Copy to temporary arrays
    for (int i = 0; ++comp && i < leftSize; i++) 
    {
        leftArr[i] = arr[left + i];
    }
    
    for (int j = 0; ++comp && j < rightSize; j++) 
    {    	
        rightArr[j] = arr[mid + 1 + j];
    }
    
    // Merge temporary arrays back to original arrays
    int leftPos = 0; // Index of left subarray
    int rightPos = 0; // Index of right subarray
    int pos = left; // Index of merged array
    
    while ((++comp && leftPos < leftSize) && 
		   (++comp && rightPos < rightSize)) 
           {
		   	
        if (++comp && leftArr[leftPos] <= rightArr[rightPos]) 
        {
            arr[pos] = leftArr[leftPos];
            pos++;
            leftPos++;
        } 
		
		else {
            arr[pos] = rightArr[rightPos];
            pos++;
            rightPos++;
        }
    }
    
    // Copy the remains of left subarray and right subarray
    while (++comp && leftPos < leftSize) 
    {
        arr[pos] = leftArr[leftPos];
        pos++;
        leftPos++; 
    }
    
    while (++comp && rightPos < rightSize) 
    {
        arr[pos] = rightArr[rightPos];
        pos++;
        rightPos++;
    }
    
    // Free up the temporary arrays
    delete [] leftArr;
    delete [] rightArr;
}

// Function to perform merge sort on an array
void MergeSort(int *arr, int n, int left, int right, long long &comp) 
{
    if (++comp && left < right) 
    {
        int mid = left + (right - left) / 2;
        // Recursively sort the first half
        MergeSort (arr, n, left, mid, comp);
        // Recursively sort the second half
        MergeSort (arr, n, mid + 1, right, comp);
        // Merge the two halves
        Merge (arr, left, mid, right, comp);
    }
}

//7

// Function to select pivot using Median of Three method
int medianOfThree(int arr[], int low, int high, long long &comp) {
    // Calculate the middle index
    int mid = low + (high - low) / 2;

    // Sort arr[low], arr[mid], arr[high] to ensure arr[low] <= arr[mid] <= arr[high]
    if (++comp && arr[low] > arr[mid]) {
        swap(arr[low], arr[mid]);
    }
    if (++comp && arr[low] > arr[high]) {
        swap(arr[low], arr[high]);
    }
    if (++comp && arr[mid] > arr[high]) {
        swap(arr[mid], arr[high]);
    }

    // Swap arr[mid] (now the median) with arr[high] to set arr[high] as the pivot
    swap(arr[mid], arr[high]);

    // Return the pivot value (which is now arr[high])
    return arr[high];
}

// Function to partition the array around the pivot
int Partition(int arr[], int low, int high, long long &comp) {
    // Select pivot using medianOfThree function
    int pivot = medianOfThree(arr, low, high, comp);

    // Initialize index i to point to the end of the lower part of the array
    int i = low - 1;

    // Iterate through each element from low to high - 1
    for (int j = low; ++comp && j < high; j++) {
        // If element at j is less than pivot, swap it with element at i+1 and move i forward
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    // Finally, swap the pivot (currently at arr[high]) with the element next to i
    swap(arr[i + 1], arr[high]);

    // Return the index of the pivot element
    return i + 1;
}


// Function to perform quick sort on an array
void QuickSort(int *arr, int n, int low, int high, long long &comp) 
{
    if (++comp && low < high) 
    {
        int pi = Partition (arr, low, high, comp);
        // Recursively sort elements before partition and after partition
        QuickSort (arr, n, low, pi - 1, comp);
        QuickSort (arr, n, pi + 1, high, comp);
    }
}

//8
int getMax(int *arr, int n, long long &comp) 
{
    int max = arr[0];

    for (int i = 1; ++comp && i < n; i++) 
    {
        if (++comp && arr[i] > max) 
        {
            max = arr[i];
        }
    }

    return max;
}

int getDigit(int number, long long &comp) 
{
    int digit = 0;

    while (++comp && number > 0) 
    {
        number /= 10;
        digit++;
    }

    return digit;
}

// Function to perform radix sort on an array
void RadixSort(int *arr, int n, long long &comp) 
{
    int maxValue = getMax(arr, n, comp);
    int digit = getDigit(maxValue, comp);

    for (int i = 0; ++comp && i < digit; i++) 
    {
        int *count = new int[10] {0};
        int *output = new int[n] {0};
        
        int exp = 1;
        
        // Calculate the current digit position
        for (int j = 0; ++comp && j < i; j++) 
        {
            exp *= 10;
        }
        
        // Count the occurrences of each digit
        for (int j = 0; ++comp && j < n; j++) 
        {
            int d = (arr[j] / exp) % 10;
            count[d]++;
        }
        
        // Accumulate the counts
        for (int j = 1; ++comp && j < 10; j++) 
        {
            count[j] += count[j - 1];
        }
        
        // Build the output array
        for (int j = n - 1; ++comp && j >= 0; j--) 
        {
            int d = (arr[j] / exp) % 10;
            output[count[d] - 1] = arr[j];
            count[d]--;
        }
        
        // Copy the sorted values back to the original array
        for (int j = 0; ++comp && j < n; j++) 
        {
            arr[j] = output[j];
        }
        
        delete [] count;
        delete [] output;
    }
}


//9
// Function to perform counting sort on an array
void CountingSort (int *arr, int n, long long &comp) 
{
    if (++comp && n < 1) 
    {
        return;
    }
    
    int maxValue = arr[0];
    
    // Find the maximum value in the array
    for (int i = 1; ++comp && i < n; i++) 
    {
        if (++comp && arr[i] > maxValue) 
        {
            maxValue = arr[i];
        }
    }
    
    int *count = new int[maxValue + 1]{0};
    int *output = new int[n]{0};
    
    // Count the occurrences of each value
    for (int i = 0; ++comp && i < n; i++) 
    {
        count[arr[i]]++;
    }
    
    // Accumulate the counts
    for (int i = 1; ++comp && i <= maxValue; i++) 
    {
        count[i] += count[i - 1];
    }
    
    // Build the output array
    for (int i = n - 1; ++comp && i >= 0; i--) 
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    
    // Copy the sorted values back to the original array
    for (int i = 0; ++comp && i < n; i++) 
    {
        arr[i] = output[i];
    }
    
    delete [] count;
    delete [] output;
}


//11
// Function to perform shaker sort (cocktail sort) on an array
void ShakerSort (int *arr, int n, long long &comp) 
{
    bool swapped = true;
    int start = 0;
    int end = n - 1;
    
    while (++comp && swapped) 
    {
        swapped = false;
        
        // Bubble sort from left to right
        for (int i = start; ++comp && i < end; i++) 
        {
            if (++comp && arr[i] > arr[i + 1]) {
                Swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
        
        if (++comp && !swapped) 
        {
            break;
        }
        
        end--;
        swapped = false;
        
        // Bubble sort from right to left
        for (int i = end - 1; ++comp && i >= start; i--)
        {
            if (++comp && arr[i] > arr[i + 1]) 
            {
                Swap (arr[i], arr[i + 1]);
                swapped = true;
            }
        }
        
        start++;
    }
}

//12
// Function to perform flash sort on an array
void FlashSort (int *arr, int n, long long &comp) {
    if (++comp && n <= 1) 
    {
        return;
    }
    
    int minValue = arr[0];
    int maxValue = arr[0];
    int maxIndex = 0;
    
    // Find the min and max values in the array
    for (int i = 1; ++comp && i < n; i++) 
    {
        if (++comp && arr[i] < minValue) 
        {
            minValue = arr[i];
        }
        
        if (++comp && arr[i] > maxValue) 
        {
            maxValue = arr[i];
            maxIndex = i;
        }
    }
    
    int group = int (0.45 * n);
    int *temp = new int[group]{0};
    double constant = (double) (group - 1) / (maxValue - minValue);
    
    // Count the number of elements in each group
    for (int i = 0; ++comp && i < n; i++) 
    {
        int pos = int (constant * (arr[i] - minValue));
        temp[pos]++;
    }
    
    // Accumulate the counts
    for (int i = 1; ++comp && i < group; i++) 
    {
        temp[i] += temp[i - 1];
    }
    
    // Swap the first element with the maximum element
    Swap (arr[0], arr[maxIndex]);
    
    int move = 0, j = 0, pos = group - 1;
    int flash;
    
    // Perform the flash sort
    while (++comp && move < n - 1) {
        while (++comp && j >= temp[pos]) 
        {
            j++;
            pos = int (constant * (arr[j] - minValue));
        }
        
        flash = arr[j];
    
        while (++comp && j != temp[pos]) 
        {
            pos = int (constant * (flash - minValue));
            int hold = arr[--temp[pos]];
            
            arr[temp[pos]] = flash;
            flash = hold;
            move++;
        }
    }
    
    delete [] temp;
    
    // Final insertion sort to complete the process
    InsertionSort (arr, n, comp);
}

//11
int BinarySearch (int *arr, int key, int low, int high, long long &comp) 
{	
	if (low >= high) {
		return (key > arr[low]) ? (low + 1) : low;
	}
	
	int mid = (low + high) / 2;
	
	if (key == arr[mid]) 
    {
		return mid + 1;
	}
	
	if (key > arr[mid]) 
    {
		return BinarySearch (arr, key, mid + 1, high, comp);
	}
	
	return BinarySearch (arr, key, low, mid - 1, comp);
}

void BinaryInsertionSort (int *arr, int n, long long &comp) 
{
	int j, key, pos;
	
	for (int i = 1; i < n; i++) 
    {
		key = arr[i];
		j = i - 1;
		
		pos = BinarySearch (arr, key, 0, j, comp);
		
		while (j >= pos) 
        {
			arr[j + 1] = arr[j];
			j--;
		}
		
		arr[j + 1] = key;
	}
}





