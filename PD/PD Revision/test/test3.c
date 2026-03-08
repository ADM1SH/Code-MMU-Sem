#include <stdio.h>

void printAge(int *pAge){
    printf("you are %d years old\n", *pAge);
}

int main(){
    int age = 21;
    int *pAge = &age;

    printf("the address of age is: %p\n", &age);
    printf("the address of pAge is: %p\n\n", pAge);

    printf("size of age: %d bytes\n", sizeof(age));
    printf("size of pAge: %d bytes\n\n", sizeof(pAge));
    
    printf("the value of age is: %d\n", age);
    printf("the value at stored address: %d\n\n", *pAge);

    printAge(pAge);

    return 0;
}