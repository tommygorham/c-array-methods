#include <iostream> 
using std::cout; 
#include <algorithm>
using std::copy; 
#include <iomanip> 
using std::setw; 

// method to print array 
void printArr(const int* values, const std::size_t size){
	// traverse 
	for (int i = 0; i<(int)size; i++){
        cout << setw(4) <<  values[i];
        }
		cout << "\n" ; 
}

// Swap first and last element in c-style array 
void swapFirstLast(const int* values, const std::size_t size){
	int arr[size] {};  // array to print, copy in original values   
	//   src, elements, dest
	copy(values, values+size, arr); // values +size means &values[size] 
	// setting temp var to last element in array
	int temp = arr[size-1]; 
	// setting last element to first element 
	arr[size-1] = arr[0]; 
	arr[0] = temp; // first to temp 
    printArr(arr, size);
}; 	

// Shift elements to the right, last element becomes first
void shiftRight(const int* values, const std::size_t size){ 
    int arr[size] {}; 
	copy(values, values+size, arr); 
	// making temp last element 
	int temp = arr[size-1]; 
	// reverse iteration
	for (int i = (int)size-1; i >= 0; --i){
	    if (i == 0){
			arr[0] = temp;
	    }  
		else {
		arr[i] = arr[i-1]; 
	   }
	}
	printArr(arr, size); 	
}; 

// Replace even elements with zero
void replaceEvens(const int* values, const std::size_t size){ 
	int arr[size] {};  
    copy(values, values+size, arr); 
	for (int i = 0; i<(int)size-1; i++){
		if (arr[i] % 2 == 0){
		   arr[i] = 0; 
        }
    }
	printArr(arr, size); 
}; 

// Replace with larger of adjacent neighbors 
void replaceWithLargestNeighbor(const int* values, const std::size_t size){
	int arr[size] {}; 
    copy(values, values+size, arr); 
	int temp = arr[1]; // middle element
	int posLeft = arr[0]; // left of middle
	int posRight = arr[2]; // right of element 
	// traverse array, starting with second element, 4 is length 
	for (int i = 1; i<=(int)size-1; i++){
		if (posLeft < posRight){
			arr[i] = posRight; 
		}
		else{
			arr[i] = posLeft; 
		}
		// update pos left
		posLeft = temp; 
		if (i+2 <= (int)size-1){
			posRight=arr[i+2]; // if we can still move right without over stepping
		}
		// update temp 
		temp = arr[i+1]; 
	}
	printArr(arr, 5); 
};

// method e: remove middle element
void removeMiddleElement(const int* values, const std::size_t size){
	// since array length is odd  
	int arr[size] {}; 
    copy(values, values+size, arr); 
	int arr2[size] {};// new array to copy elements
        for (int i = 0; i <= (int)size-1; i++){
		if (i >= 2){
			arr2[i] = arr[i+1]; 
		}
		else{
			arr2[i] = arr[i]; // copy elements
		}
	}	
	printArr(arr2,size-1); // passing size 4 instead of 5 since i removed one
};

// Move even elements to front
 void shiftEvenFront(const int* values, const std::size_t size){
	int arr[size] {};
    copy(values, values+size, arr); 
	int pos = size-1; // pos = last element
	int temp; // always good to have 
	// traverse backwards again 
	for (int i = size-1; i >= 0; i--){
		if (arr[i] % 2 != 0){
			temp = arr[pos]; 
			arr[pos] = arr[i]; 
			arr[i] = temp; 
			--pos;
		 }	
	}
	printArr(arr, size); 
};

// Return Ssecond largest value in array
int retSecondLargest(const int* values, const std::size_t size){
	int arr[size] {}; 
	copy(values, values+size, arr); 
	int largest = arr[0]; 
	int second_largest = arr[0]; // start both at first element for testing 
	for (int i = 0; i < (int)size; i++){
		if (arr[i] > largest){
			second_largest=largest; 
			largest = arr[i];
		}
		else if(arr[i] > second_largest && arr[i] != largest){
		second_largest = arr[i]; 
		}
	}
		return second_largest; 	
};

// method h: return true if array in increasing order
bool isIncreasing(const int* values, const std::size_t size){
	int arr[size] {}; 
	copy(values, values+size, arr); 
	for (int i = 0; i < (int)size; i++){
		if (arr[i] < arr[i+1]){
			return true; 
		} 
	} 
    return false; 
}; 

// Return true if two adjacent duplicate elements 
bool adjDuplicates(const int* values, const std::size_t size){
       //bool adjacent = false; 	
	int arr[size] {}; 
	copy(values, values+size, arr); 
	for (int i = 0; i < (int)size; i++){
		if (arr[i] == arr[i+1]){ // if adjacent duplicates
			return true; 
		}
	}
	return false;  
}; 	

// Return true if duplicate elements exist
bool anyDuplicates(const int* values, const std::size_t size){
	int arr[size] {}; 
	copy(values, values+size, arr); 
        // regular traverse	
	for (int i = 0; i < (int)size; i++){
		// nested traverse to comapre i to all elements in array.. not just adj
		for (int j = 0; j < (int)size; j++){
			// test for duplicates
			if (i != j &&  arr[i] == arr[j]){
				return true;
			}
		}
	} 
	return false; 
};
 

int main(){
	const int values[] = {1,4,9,16,25};	
	const std::size_t size = sizeof(values)/sizeof(values[0]); 
	
	cout << "\nOriginal Test Array:      ";  
	printArr(values, size); 
	cout << "Swap first/last element:  "; 
	swapFirstLast(values, size);  
    
	cout << "\nOriginal Test Array:      ";  
	printArr(values, size); 
	cout << "Shift each element right: "; 
    shiftRight(values, size);  
    
	cout << "\nOriginal Test Array:      ";  
	printArr(values, size); 
	cout << "Replace evens with zero:  "; 
	replaceEvens(values, size); 
    
	cout << "\nOriginal Test Array:      ";  
	printArr(values, size); 
	cout << "Replace w/largest adj:    "; 
	replaceWithLargestNeighbor(values, size); // excluding first and last, aka no wrapping  
    
	cout << "\nOriginal Test Array:      ";  
	printArr(values, size); 
	cout << "Remove middle element:    "; 
	removeMiddleElement(values, size); 	
	
	cout << "\nOriginal Test Array:      ";  
	printArr(values, size); 	
	cout << "Move even vals to front:  "; 
	shiftEvenFront(values, size);
	 
	int element = retSecondLargest(values, size);  
    cout << "\nThe second largest element is:              " << element << std::endl;  
    
	cout << "Sorted in increasing order?                 "; 
	bool check = isIncreasing(values, size);
    cout << std::boolalpha <<  check << std::endl; 	
	
	cout << "i) Array contains adjacent duplicates?      "; 
	bool check2 = adjDuplicates(values, size); 
	cout << std::boolalpha << check2 << std::endl;  
	   	
	cout << "Array contains duplicate elements?          "; 
	bool check3 = anyDuplicates(values, size); 
	cout << std::boolalpha << check3 << std::endl; 
	
	return 0;
}	
