#include<iostream>

using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i; j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

void selectionSort(int arr[], int n){
    for(int i=0; i<n; i++){
        int minIndex = i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
            if(minIndex != i)
                swap(&arr[i], &arr[minIndex]);
        }
    }
}

void insertionSort(int arr[], int n){
    for(int i=1; i<n; i++){
        int temp = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>temp){
            arr[j+1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
}

void print(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<" "<<arr[i];
    }
}

int main(){
    int arr[] = {7,6,2,8,1,12,43,23,54,26,9};
    int size = sizeof(arr)/sizeof(arr[0]);
    //bubbleSort(arr, size);
    //selectionSort(arr, size);
    insertionSort(arr, size);
    print(arr, size);
    
    return 0;
}