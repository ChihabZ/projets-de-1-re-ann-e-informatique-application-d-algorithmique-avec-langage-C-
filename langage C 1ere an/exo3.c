#include<stdio.h>
#include<stdlib.h>
    int main(int argc , char *argv){
//for starters we want to dynam allocate a vector of ints V of size n
int n;
printf("enter the vector size");
scanf("%d",&n);
int *V = (int*)malloc(n * sizeof(int));

printf("Enter %d integer(s):\n", n);
for (int i = 0; i < n; i++) {
    printf("V[%d] = ", i);
    scanf("%d", &V[i]);
}


printf("\nVector elements:\n");
for (int i = 0; i < n; i++) {
    printf("V[%d] = %d\n", i, V[i]);
}
    int max = V[0];
    for (int i = 1; i < n; i++) {
        if (V[i] > max) {
            max = V[i];
        }
    }

    printf("\nThe largest element is: %d\n", max);

        return 0;
    }
    //doneeee