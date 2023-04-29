#include <bits/stdc++.h>
using namespace std;

//just print the array...
void printArr(int arr[], int n) {
    for(int i=0; i<n; i++) cout<<arr[i]<<" ";
    cout<<endl;
}

//using forLoop...
void selectionSort1(int arr[], int n) {
    
    for(int i=0;i<n-1;i++) {
        for(int j=i+1; j<n;j++) {
            if(arr[j]< arr[i]) swap(arr[j], arr[i]);
        }
    }
    printArr(arr, n);
}

//using Recursion
void selectionSort2(int arr[], int n) {
    
    //baseCase:
    if(n==1) return;  //If there is just 1 element in the arr.
    
    //solving for 1 case:
    //we will swap with any small val ahead of arr.
    for(int i=1; i<n;i++) {
        if(*(arr+i) < *arr) swap(*arr, *(arr+i));
    }
    
    //Recursion will handle the rest...
    return selectionSort2(arr+1, n-1); //updating the params for the recursion.
}


int main()
{
    int arr[] = {4,5,2,7,1,3,6};
    int brr[] = {7,2,8,5,9,1,6};
    int n = sizeof(brr)/sizeof(int);
    selectionSort2(brr, n);
    printArr(brr, n);
    cout<<"Selection Sort"<<endl;
    return 0;
}
