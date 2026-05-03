#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int capacity;
    int size;
} Vector;

void init(Vector* v) {
    v->capacity = 2;
    v->size = 0;
    v->data = (int*)malloc(v->capacity*sizeof(int));
    if(v->data == NULL) {
        printf("\nMemory allocation failed\n");
        exit(1);
            }
        }

void push_back(Vector* v, int value) {
    if(v->size == v->capacity) {
        int new_capacity=v->capacity*2;
        int *temp = (int*)realloc(v->data, new_capacity*sizeof(int));
        if(temp == NULL) {
            printf("\nMemory Re-allocation failed\n");
            exit(1);
        }
        else if(temp != NULL){             
            v->data = temp;
            v->capacity = new_capacity;
        }
    } 
        v->data[v->size] = value;
        v->size++;
}

void pop_back(Vector* v) {//uses lazy deletion

    if(v->size == 0){
        printf("Vector is empty\n");
        exit(1);}
    v->size--;
    
    if(v->size < (int)v->capacity/4) {    //commonly used threshold
        int new_capacity;
        if (v->capacity>1) new_capacity = v->capacity/2;    
        int *temp = (int*)realloc(v->data,new_capacity*sizeof(int));
        if(temp == NULL) {
            printf("\nMemory Re-allocation failed\n");
            exit(1);
        }
        else if(temp != NULL) {
            v->data = temp;
            v->capacity = new_capacity;
        }
    }
}

                                                                                                          
    
