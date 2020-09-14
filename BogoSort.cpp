/*
File: BogoSort.cpp
Name: Richard Hutcheson
Date: 9/12/2020

Contains the bogosort algorithm

*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
//takes in the array, the size of the array, and returns the amount of permutations it took
int bogoSort(int arr[], const int size){
    bool sorted = true;
    int permutations = 1;
    
    //check if arr is sorted
    for (int i =  0; i < size; i++){
        if (i < size - 1){
            if (arr[i] > arr[i+1]){
                sorted = false;
                break;
            }
        }
    }

    //evaluate permuations of array until one of the permutations happens to be sorted
    while (!sorted){
        
        //shuffle array
        for (int i =  0; i < size; i++){
            swap(arr[i], arr[rand()%size]);
        }
        permutations++;

        //check if arr is sorted
        for (int i =  0; i < size; i++){
            if (i < size - 1){
                sorted = true;
                if (arr[i] > arr[i+1]){
                    sorted = false;
                    break;
                }
            }
        }


    }
    return permutations;
}
int factorial(int n){
    int fact = n;
    while (n > 1){
        --n;
        fact *= n;
    }
    return fact;
}

int main()
{
    const int SIZE = 10;
    int arr[SIZE];
    srand(time(0)); //initialize seed

    //create input for the array
    for (int i = 0; i < SIZE; i++){
        arr[i] = (rand()%50)-20;
    }
    //Print the array before sorting
    cout << "-ARRAY BEFORE SORTING-" << endl;
    for (int i = 0; i < SIZE; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    int final = bogoSort(arr, SIZE);
    cout << "-TOTAL AMOUNT OF DIFFERENT PERMUTATIONS-\n" << factorial(SIZE) << endl;    
    cout << "-AMOUNT OF PERMUTATIONS IT TOOK-\n" << final << endl;

    cout << "-ARRAY AFTER SORTING-" << endl;
    for (int i = 0; i < SIZE; i++){
        cout << arr[i] << " ";
    }   
}