#include <stdio.h>
#include <unistd.h> // Ajoute ceci

void Put_Char(int n){
    printf("%d", n);
}

int main(){
    int number = 1;
    while(number <= 9){
        Put_Char(number);
        number++;
    }
    printf("\n");
    return 0;
}

