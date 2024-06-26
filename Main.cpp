#include "Header.h"

// Function to find and execute the appropriate sorting algorithm
void FindSort(int *arr, int n, string nameSort, long long &time, long long &comp)
{
      if(nameSort == "selection-sort")
      {
            auto start = high_resolution_clock::now();
            SelectionSort(arr, n, comp);
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(end - start);
            time = duration.count();
      }
      else if(nameSort == "insertion-sort")
      {
            auto start = high_resolution_clock::now();
            InsertionSort(arr, n, comp);
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(end - start);
            time = duration.count();
      }
      else if(nameSort == "shell-sort")
      {
            auto start = high_resolution_clock::now();
            ShellSort(arr, n, comp);
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(end - start);
            time = duration.count();
      }
      else if(nameSort == "bubble-sort")
      {
            auto start = high_resolution_clock::now();
            BubbleSort(arr, n, comp);
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(end - start);
            time = duration.count();
      }
      else if(nameSort == "heap-sort")
      {
            auto start = high_resolution_clock::now();
            HeapSort(arr, n, comp);
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(end - start);
            time = duration.count();
      }
      else if(nameSort == "merge-sort")
      {
            auto start = high_resolution_clock::now();
            MergeSort(arr, n, 0, n - 1, comp);
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(end - start);
            time = duration.count();
      }
      else if(nameSort == "quick-sort")
      {
            auto start = high_resolution_clock::now();
            QuickSort(arr, n, 0, n - 1, comp);
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(end - start);
            time = duration.count();
      }
      else if(nameSort == "radix-sort")
      {
            auto start = high_resolution_clock::now();
            RadixSort(arr, n, comp);
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(end - start);
            time = duration.count();
      }
      else if(nameSort == "counting-sort")
      {
            auto start = high_resolution_clock::now();
            CountingSort(arr, n, comp);
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(end - start);
            time = duration.count();
      }
      else if(nameSort == "flash-sort")
      {
            auto start = high_resolution_clock::now();
            FlashSort(arr, n, comp);
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(end - start);
            time = duration.count();
      }
      else if(nameSort == "shaker-sort")
      {
            auto start = high_resolution_clock::now();
            ShakerSort(arr, n, comp);
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(end - start);
            time = duration.count();
      }
      else if(nameSort == "binary-insertion-sort")
      {
            auto start = high_resolution_clock::now();
            BinaryInsertionSort(arr, n, comp);
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(end - start);
            time = duration.count();
      }
}


void WriteGeneratedInput(int a[], int n, int i)
{
      if(i == 1) 
      {
            string s = "input_1.txt";
            Write_File(a, n, s);
      }
      else if(i == 2)
      {
            string s = "input_2.txt";
            Write_File(a, n, s);
      }
      else if(i == 3)
      {
            string s = "input_3.txt";
            Write_File(a, n, s);
      }
      else if(i == 4)
      {
            string s = "input_4.txt";
            Write_File(a, n, s);
      }
}


void OutTimeAndComp(long long time, long long comp, string parameter)
{
      if (parameter == "-time" || parameter == "-both"){
            cout << "Running time: " << fixed << time << setprecision(7) << " microseconds" << endl;
      }
      if (parameter == "-comp" || parameter == "-both"){
            cout << "Comparisons: " << comp << endl;
      }
}


bool Write_File(int a[], int n, string output)
{
      ofstream out(output);
      if(!out.is_open()) return 0;
      out << n << endl;


      for(int i = 0; i < n; i++)
      {
            out << a[i] << " ";
      }


      out.close();
      return 1;
}

bool Read_File(int *&a, int &n, string input)
{
      ifstream in(input);

      if(!in.is_open()) return 0;
      in >> n;
      a = new int[n];
      for(int i = 0; i < n; i++)
      {
            in >> a[i];
      }
      in.close(); 
      return 1;     
}

//Command 1
//Example: a.exe -a selection-sort input.txt -both
void Command_1(char* arrayStr[])
{
      cout << "ALGORITHM MODE" << endl;
      int *a = NULL;
      int n, data = 0;
      long long time = 0;
      long long comp;


      if(Read_File(a, n, arrayStr[3]) == 0)
      {
            cout << "Don't open File";
            return;
      }


      FindSort(a, n, arrayStr[2], time, comp);
      cout << "Algorithm: " << ShowNameSort(arrayStr[2]) << endl;
      cout << "Input file" << arrayStr[3] << endl;
      cout << "Input size" << n << endl;
      cout << "---------------------------" << endl;


      OutTimeAndComp(time, comp, arrayStr[4]);
      Write_File(a, n, "output.txt");


      delete []a;
}

//Command 2
//Example: a.exe -a insertion-sort 50000 -rand -both
void Command_2(char* arrayStr[])
{
      cout << "ALGORITHM MODE" << endl;


      int *a = NULL;
      int n = stoi(arrayStr[3]);
      a = new int[n];
      long long time;
      long long comp;
      int dataType = ShowIntDataType(arrayStr[3]);
      GenerateData(a, n, dataType);


      Write_File(a, n, "input.txt");
      cout << "Algorithm: " << ShowNameSort(arrayStr[2]) << endl;
      FindSort(a, n, arrayStr[2], time, comp);
      cout << "Input size: " << n << endl;
      cout << "Input order: " << arrayStr[4] << endl;
      cout << "_______________________" << endl;
      OutTimeAndComp(time, comp, arrayStr[5]);


      Write_File(a, n, "output.txt");
      delete []a;
}

//Command 3
//Example: a.exe -a quick-sort 1000 -both
void Command_3(char* arrayStr[])
{
      cout << "ALGORITHM MODE" << endl;

      int n = stoi(arrayStr[3]);


      cout << "Algorithm: " << ShowNameSort(arrayStr[2]) << endl;
      cout << "Input size: " << n << endl << endl;


      for(int i = 1; i <= 4; i++)
      {
            int *a = NULL;
            a = new int[n];
            long long time;
            long long comp;
            GenerateData(a, n, i);
            WriteGeneratedInput(a, n, i);

            FindSort(a, n, arrayStr[2], time, comp);

            cout << "Input order: " << ShowStringNameDataType(i) << endl;
            cout << "_______________________" << endl;
            OutTimeAndComp(time, comp, arrayStr[4]);


            delete []a; 
            cout << endl;
      } 
}

 //Command 4
 //Example: a.exe -c selection-sort selection-sort input.txt
void Command_4(char* arrayStr[])
{
      cout << 1;
      cout << "COMPARE MODE" << endl;

      int* array_1;
      int* array_2;
      long long comp_1, comp_2;
      long long time_1, time_2;
      int n;

      Read_File(array_1, n, arrayStr[4]);
      Read_File(array_2, n, arrayStr[4]);


      cout << "Algorithm: " << ShowNameSort(arrayStr[2]) << "|" << ShowNameSort(arrayStr[3]) << endl;
      cout << "Input file: " << arrayStr[4] << endl;
      cout << "Input size: " << n << endl;
      cout << "----------------------------" << endl;


      FindSort(array_1, n, arrayStr[2], time_1, comp_1);
      FindSort(array_2, n, arrayStr[3], time_2, comp_2);


      cout << "Running time: ";
      cout << setw(15) << left << fixed << time_1 << setprecision(7);
      cout << setw(3) << left << "|";
      cout << fixed << time_2 << setprecision(7) << ("    (measured in seconds)") << endl;
      cout << "Comparisions: ";
      cout << setw(15) << left << comp_1;
      cout << setw(3) << left << "|";
      cout << fixed << comp_2;

      delete []array_1;
      delete []array_2;
}

//Command 5
//Example: a.exe -c flash-sort  flash-sort 500000 -nsorted
void Command_5(char* arrayStr[])
{
      cout << "COMPARE MODE" << endl;

      int* array_1;
      int* array_2;
      long long comp_1, comp_2;
      long long time_1, time_2;
      int n = stoi(arrayStr[4]);
      array_1 = new int[n];
      array_2 = new int[n];


      int dataType = ShowIntDataType(arrayStr[5]);
      GenerateData(array_1, n, dataType);
      for(int i = 0; i < n; i++)
      {
            array_2[i] = array_1[i];
      }


      cout << "Algorithm: " << ShowNameSort(arrayStr[2]) << "|" << ShowNameSort(arrayStr[3]) << endl;
      cout << "Input size: " << n << endl;
      cout << "----------------------------" << endl;


      FindSort(array_1, n, arrayStr[2], time_1, comp_1);
      FindSort(array_2, n, arrayStr[3], time_2, comp_2);


      cout << "Running time: ";
      cout << setw(15) << left << fixed << time_1 << setprecision(7);
      cout << setw(3) << left << "|";
      cout << fixed << time_2 << setprecision(7) << ("    (measured in seconds)") << endl;
      cout << "Comparisions: ";
      cout << setw(15) << left << comp_1;
      cout << setw(3) << left << "|";
      cout << fixed << comp_2;

      delete []array_1;
      delete []array_2;
}


//Number of element in input string: numStr.
//Element in input string: arrayStr[].
//Ex: a.exe -a radix-sort input.txt -both
//numStr = 5.
//arrayStr[] = {a.exe, -a, radix-sort, input.txt, -both};
int main(int numStr, char* arrayStr[])
{
      string  mode = arrayStr[1];
      if(mode == "-a") 
      {
            if(numStr == 5)
            {
                  if(arrayStr[4][0] <= '9' && arrayStr[4][0] >= '0')
                  {
                        Command_3(arrayStr);
                  }
                  else 
                        Command_1(arrayStr);

            }
            else if(numStr == 6)
            {
                  Command_2(arrayStr);
            }
      }
      else if(mode == "-c")
      {
            if(numStr == 5)
            {
                  Command_4(arrayStr);
            }
            else if(numStr == 6)
            {
                  Command_5(arrayStr);
            }
      }
      return 0;
}




