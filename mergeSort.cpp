#include <iostream>

using namespace std;

class Sort {
    public:
    
	// CREATE MERGE HELPER FUNCTION HERE //
	void merge(int arr[], int leftIndex, int midIndex, int rightIndex){
	    int leftArraySize = midIndex - leftIndex + 1;
	    int rightArraySize = rightIndex - midIndex;
	    
	    int leftArray[leftArraySize];
	    int rightArray[rightArraySize];
	    
	    //int i=0, int j=0;
	    
	    for(int i=0; i<leftArraySize; i++){
	        leftArray[i] = arr[leftIndex + i];
	    }
	    
	    for(int j=0; j<rightArraySize; j++){
	        rightArray[j] = arr[midIndex + 1 + j];
	    }
	    
	    int index = leftIndex; 
	    int i = 0, j = 0;
	    
	    while(i< leftArraySize &&  j< rightArraySize){
	        if(leftArray[i] <= rightArray[j]){
	            arr[index] = leftArray[i];
	            index++;
	            i++;
	        } else {
	            arr[index] = rightArray[j];
	            index++;
	            j++;
	        }
	    }
	    while(i<leftArraySize){
	        arr[index++] = leftArray[i++];
	    }
	    while(j<rightArraySize){
	        arr[index++] = rightArray[j++];
	    }
	}

    void mergeSort(int arr[], int leftIndex, int rightIndex){
        if(leftIndex>=rightIndex)
            return;
        int midIndex = leftIndex + (rightIndex - leftIndex)/2;
        mergeSort(arr, leftIndex, midIndex);
        mergeSort(arr, midIndex+1, rightIndex);
        merge(arr, leftIndex, midIndex, rightIndex);
    }

    void printArray(int arr[], int size){
        for(int i=0; i<size; i++){
            cout<<" "<<arr[i];
        }
        cout<<endl;
    }
	
};

int main(){

    int arr[] = {9,6,2,5,0,12,4,13,8,7};

    Sort obj;
    int n = sizeof(arr)/sizeof(arr[0]);
    obj.mergeSort(arr,0,n-1);

    obj.printArray(arr, n);

    return 0;
}