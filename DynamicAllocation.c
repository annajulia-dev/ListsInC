#include <stdio.h>
#include <stdlib.h>

void scanArray(int* array, int size){
    for (int i = 0; i < size;i++){
        printf("Number %d:",i+1);
        scanf("%d",&array[i]);
    }
}

void printArray(int* array, int size){
    for (int i = 0; i < size;i++)
        printf("%d\n",array[i]);
}


int main()
{
    int size;
    printf("Array size: ");
    scanf("%d",&size);
    
    int* array = (int*) malloc(size * sizeof(int)); // calloc (how many, size) Ex: calloc(size ,sizeof(int));
    if (array == NULL)
        return 0;

    printf("Array size: ");
    scanf("%d",&size); 
    
    int* temp = realloc(array, size * sizeof(int));
    if (temp == NULL) // you need temp, if realloc fails you will lose the pointer
        return 0;
    else array = temp;
    
    
        
    scanArray(array, size);
    
    printArray(array, size);
    
    free(array);

    return 0;
}
