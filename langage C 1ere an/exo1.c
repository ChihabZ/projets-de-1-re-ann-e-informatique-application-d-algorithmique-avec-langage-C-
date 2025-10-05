#include<stdio.h>
#include<stdlib.h>
int main(int argc , char *argv[])
{
int m [3][2] = { {10,15}, {-5,17}, {11, -9}};
int i,j;



for (i=0 ; i<3 ; i++){
    printf("the adress of row %d is : %p\n",i,m[i]);
}
//writing the addresses
for (i=0 ; i<3 ; i++){
for (j=0 ; j<2 ; j++){

    printf("the adress of m[%d][%d] is : %p \n",i,j,m[i][j]);
}

}//done!
for (i=0 ; i<3 ; i++){
    for (j=0 ; j<2 ; j++){
printf("m[%d][%d] = %d\n",i,j,m[i][j]);
    }
}


    return 0;
}