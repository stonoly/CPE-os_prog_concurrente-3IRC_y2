/* Fichier: ex1.c
* First factor decomposition
* auteur: Pierre MOLY
* Exercice 1
*/

#include <stdio.h>


int smallestDivisor (int num_to_divide){
    int i = 2;

    while(num_to_divide % i != 0){
        if (i == 2){
            i = 3;
        } else {
            i += 2;
        }
    }
    
    return i;

}

int main (void){
    int num;
    int lastest_smallest_divisor = 1;

    puts("Rentrez un nombre");
    scanf("%d", &num);

    do {
        num = num/lastest_smallest_divisor;
        lastest_smallest_divisor = smallestDivisor(num);
        printf("%d ", lastest_smallest_divisor);
    } while (num != lastest_smallest_divisor);
    
    printf("\n");

    return 0;
}