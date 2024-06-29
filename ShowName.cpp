#include "Header.h"

string ShowNameSort(string nameSort)
{
      string s = "\0";
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
      if(nameSort == "binary-insertion-sort")
      {
            s = "Binary Insertion Sort";
      }
      if(nameSort == "flash-sort")
      {
            s = "Flash Sort";
      }
      if(nameSort == "shaker-sort")
      {
            s = "Shaker Sort";
      }
        
      return s;
}


int ShowIntDataType(string dataType)
{
      if(dataType == "-rand")	
		return 0;
	if(dataType == "-nsorted")	
	      return 3;
	if(dataType == "-sorted")	
		return 1;
      else	
		return 2;
}

string ShowStringNameDataType(int DataType)
{
      string s = "\0";
      if(DataType == 0)
      {
            s = "Randomize";
            return s;   
      }
      if(DataType == 3)
      {
            s = "Nearly Sorted";
            return s;
      }
      if(DataType == 1)
      {
            s = "Sorted";
            return s;
      }
      if(DataType == 2)
      {
            s = "Reversed";
            return s;
      }
      return s;
}

