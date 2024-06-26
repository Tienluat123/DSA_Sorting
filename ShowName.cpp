#include "Header.h"

string ShowNameSort(string nameSort)
{
      string s;
      if(nameSort == "selection-sort")
      {
            s = "Selection Sort";
            return s;
      }
      if(nameSort == "insertion-sort")
      {
            s = "Insertion Sort";
            return s;
      }
      if(nameSort == "shell-sort")
      {
            s = "Shell Sort";
            return s;
      }
      if(nameSort == "bubble-sort")
      {
            s = "Bubble Sort";
            return s;
      }
      if(nameSort == "heap-sort")
      {
            s = "Heap Sort";
            return s;
      }
      if(nameSort == "merge-sort")
      {
            s = "Merge Sort";
            return s;
      }
      if(nameSort == "quick-sort")
      {
            s = "Quick Sort";
            return s;
      }
      if(nameSort == "radix-sort")
      {
            s = "Radix Sort";
            return s;
      }
      if(nameSort == "counting-sort")
      {
            s = "Counting Sort";
            return s;
      }
}

int ShowIntDataType(string dataType)
{
      if(dataType == "-rand")	
		return 1;
	if(dataType == "-nsorted")	
	      return 2;
	if(dataType =="-sorted")	
		return 3;
      if(dataType == "-rev")	
		return 4;
}

string ShowStringNameDataType(int DataType)
{
      string s;
      if(DataType == 1)
      {
            s = "Randomize";
            return s;   
      }
      if(DataType == 2)
      {
            s = "Nearly Sorted";
            return s;
      }
      if(DataType == 3)
      {
            s = "Sorted";
            return s;
      }
      if(DataType == 4)
      {
            s = "Reversed";
            return s;
      }
}

