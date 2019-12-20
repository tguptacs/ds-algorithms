#include <stdio.h>

int rotate (int* arr, int size, int shift){
    for (int i = 0; i < size; i++)
        printf ("%d \t", arr[i]);
    printf ("size: %d\t shift: %d", size, shift);
    
    int count = 0;
    int start = 0, end, temp;
    while (count < size){
        end = start;
        temp = arr [start];
        do{
            end = end - shift;
            if (end < 0)
                end = (size + end);
            
            int temp1 = arr [end];
            arr [end] = temp;
            temp = temp1;
            count ++;            
        }while (start != end);
        start ++;
    }
}

int rotateRight (int* arr, int size, int shift){
    for (int i = 0; i < size; i++)
        printf ("%d \t", arr[i]);
    printf ("size: %d\t shift: %d", size, shift);
    
    int count = 0;
    int start = 0, end, temp;
    while (count < size){
        end = start;
        temp = arr [start];
        do{
            end = end + shift;
            if (end > (size - 1))
                end = -(size - end);
            
            int temp1 = arr [end];
            arr [end] = temp;
            temp = temp1;
            count ++;            
        }while (start != end);
        start ++;
    }
}


int main(void) {
	int arr [] = {1,2,3,4};
	int size = sizeof(arr)/sizeof(arr[0]);
	
	rotateRight (arr, size, 2);
	printf ("\nAfter rotation:\n");
	for (int i = 0; i < size; i++)
        printf ("%d \t", arr[i]);
	
	return 0;
}

