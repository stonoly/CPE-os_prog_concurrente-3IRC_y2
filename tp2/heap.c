/* Fichier: heap.c
* Heap and Heap Sort
* auteur: Pierre MOLY
* Exercice 1
*/

#include "heap.h"


bool isPair(int value){
    if (value % 2 == 0){
        return true;
    }
    return false;
}

void heapPush(int tab[], int value, int *index){
    tab[*index] = value;
    int index_actual_value = *index;

    int parent_offset = isPair(index_actual_value) ? 2 : 1;
    *index += 1;
    
    while(index_actual_value != 0 && tab[(index_actual_value - parent_offset) / 2] > value){
        tab[index_actual_value] = tab[(index_actual_value - parent_offset) / 2];
        tab[(index_actual_value - parent_offset) / 2] = value;
        index_actual_value = (index_actual_value - parent_offset) / 2;
    }
}

void heapExtract(int tab[], int *index){
    tab[0] = tab[*index - 1];
    *index -= 1; 
}

void display(int tab[], int *index){
    puts("-----Heap-----");
    int compt = 0;
    while (compt < *index){
        printf("tab[%d] : %d\n", compt, tab[compt]);
        compt += 1;
    }
    puts("-------------");
}

int main(){
    int tab[50];
    int index = 0;

    heapPush(tab, 16, &index);
    heapPush(tab, 12, &index);
    heapPush(tab, 13, &index);
    heapPush(tab, 15, &index);
    heapPush(tab, 14, &index);
    heapPush(tab, 22, &index);
    heapPush(tab, 10, &index);

    display(tab, &index);

    heapExtract(tab, &index);

    display(tab, &index);
    return 0;
}