#pragma once

#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>
#include <math.h>
#include <fstream>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <string>
#include <chrono>

using namespace std;
using namespace std::chrono;

template <class T>
void Swap(T &a, T &b);


//-------------------------------------------------

// This function generates a random array
void GenerateRandomData(int a[], int n);

// This function generates a sorted array (ascending order)
void GenerateSortedData(int a[], int n);

// This function generates a reverse-sorted array (descending order)
void GenerateReverseData(int a[], int n);

// This function generates a nearly-sorted array
void GenerateNearlySortedData(int a[], int n);

void GenerateData(int a[], int n, int dataType);

//-------------------------------------------------
// Sort functions
void SelectionSort(int *arr, int n, long long &comp);
void InsertionSort(int *arr, int n, long long &comp);
void BubbleSort(int *arr, int n, long long &comp);
void MergeSort(int *arr, int n, int left, int right, long long &comp);
void QuickSort(int *arr, int n, int left, int right, long long &comp);
void ShakerSort(int *arr, int n, long long &comp);
void RadixSort(int *arr, int n, long long &comp);
void HeapSort(int *arr, int n, long long &comp);
void ShellSort(int *arr, int n, long long &comp);
void CountingSort(int *arr, int n, long long &comp);
void FlashSort(int *arr, int n, long long &comp);
void BinaryInsertionSort(int *arr, int n, long long &comp);
//-------------------------------------------------
// Main functions
std::string ShowNameSort(std::string nameSort);
int ShowIntDataType(std::string dataType);
std::string ShowStringNameDataType(int DataType);
bool Write_File(int a[], int n, std::string output);
bool Read_File(int *&a, int &n, std::string input);

#endif // HEADER_H_INCLUDED


