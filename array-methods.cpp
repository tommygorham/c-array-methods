#include <iostream> 
using namespace std; 
// method to print array 
void printArr(int values[], int size){
	// traverse 
	for (int i = 0; i<size; i++){
        cout << values[i] << " ";
        }
};

// newline  
void nl(){
	cout << "\n"; 
};

// method a: switch first and last element
void a(){
	// O(n) time complexity.. will start all methods this way 
	int arr[] = {1,4,9,16,25};
	// setting temp var to last element in array
	int temp = arr[4]; 
	// setting last element to first element 
	arr[4] = arr[0]; 
	arr[0] = temp; // first to temp 
        printArr(arr, 5);
}; 	
// method b: shift elements to the right, last element becomes first
void b(){ 
	int arr[] = {1,4,9,16,25}; 
	// making temp last element 
	int temp = arr[4]; 
	// reverse iteration
	for (int i = 4; i >= 0; i--){
	       if (i == 0){
			arr[0] = temp;
	       }
	       // else shift
	       else 
	       {
		arr[i] = arr[i-1]; 
	       }
	}
	printArr(arr, 5); 	
}; 
// method c: replace even elements wiht zero
void c(){ 
	int arr[] = {1,4,9,16,25}; 
	// loop thru and replace
	for (int i = 0; i<4; i++){
	// you will use loops a lot
	// look up "mod" 
		if (arr[i] % 2 == 0){
		arr[i] = 0; 
         	}
        }
	printArr(arr, 5); 
}; 
// method d: larger of adjacents 
void d(){
	int arr[] = {1,4,9,16,25}; 
	int temp = arr[1]; // middle element
	int posLeft = arr[0]; // left of middle
	int posRight = arr[2]; // right of element 
	// traverse array, starting with second element, 4 is length 
	for (int i = 1; i<=4; i++){
		if (posLeft < posRight){
			arr[i] = posRight; 
		}
		else{
			arr[i] = posLeft; 
		}
		// update pos left
		posLeft = temp; 
		if (i+2 <= 4){
			posRight=arr[i+2]; // if we can still move right without over stepping
		}
		// update temp 
		temp = arr[i+1]; 
	}
	printArr(arr, 5); 
};

// method e: remove middle element
void e(){
	// since array length is odd  
	int arr[] = {1,4,9,16,25}; 
	int arr2[3];// new array to copy elements
        for (int i = 0; i <=4; i++){
		if (i >= 2){
			arr2[i] = arr[i+1]; 
		}
		else{
			arr2[i] = arr[i]; // copy elements
		}
	}	
	printArr(arr2,4); // passing size 4 instead of 5 since i removed one
};

// method f: move even elements to front
void f(){
	int arr[] = {1,4,9,16,25}; 
	// move even to front = move odd to back (also) 
	int pos = 4; // pos = last element
	int temp; // always good to have 
	// traverse backwards again 
	for (int i = 4; i >= 0; i--){
		if (arr[i] % 2 != 0){
			temp = arr[pos]; 
			arr[pos] = arr[i]; 
			arr[i] = temp; 
			--pos;
		 }	
	}
	printArr(arr, 5); 
};

// method g: second largest value in array
int g(){
	int arr[] = {1,4,9,16,25};
        int largest = arr[0]; 
	int second_largest = arr[0]; // start both at first element for testing 
	for (int i = 0; i < 5; i++){
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
bool h(){
	int arr[] = {1,4,9,16,25}; 
	for (int i = 0; i < 5; i++){
		if (arr[i] < arr[i+1]){
			return true; 
		} 
	}return false; 
	 
}; 

// method i: return true if two adjacent duplicate elements 
bool i(){
       //bool adjacent = false; 	
	int arr[] = {1,4,9,16,25}; 
	for (int i = 0; i < 5; i++){
		if (arr[i] == arr[i+1]){ // if adjacent duplicates
			return true; 
		}
	}
	return false;  
}; 	

// method j: return true if duplicate elements at all
bool j(){
	int arr[] = {1,4,9,16,25};
        // regular traverse	
	for (int i = 0; i <5; i++){
		// nested traverse to comapre i to all elements in array.. not just adj
		for (int j = 0; j < 5; j++){
			// test for duplicates
			if (i != j &&  arr[i] == arr[j])
			{
				return true;
			}
		}
	} 
	return false; 
};

int main(){
	int arr[] = {1,4,9,16,25};
        int size = 5; 	
	cout << "Original Test Array: "; 
	printArr(arr, size);
	nl(); //newline
	cout << "a) swap first and last elements: "; 
	a();  
	nl(); 
	cout << "b) shift elements one to the right, last becomes first: "; 
	b(); 
	nl(); 
	cout << "c) replace even elements with zero: "; 
	c(); 
	nl(); 
	cout << "d) replace each element with the largest of its neighbors (excluding first and last): "; 
	d();
       	nl(); 
	cout << "e) remove middle element: "; 
	e(); 	
	nl(); 
	cout << "f) move even elements to the front: "; 
	f();
	nl(); 
	cout << "g) second largest element in array: "; 
	int second_L = g(); 
	cout << second_L; 
	nl(); 
	cout << "h) array sorted in increasing order? (1=true, 0=false): "; 
	bool increasing = h();
        cout << increasing;	
	nl(); 
	cout << "i) array contains two adjacent duplicates? (1=true, 0=false): "; 
	bool ans = i(); 
	cout << ans; 
	bool duplicate = j();
        nl(); 	
	cout << "j) array contains duplicate elements? (1=true, 0=false): "; 
	cout << duplicate << endl; 
		
	return 0;
}	
