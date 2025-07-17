#include <unistd.h>

void put_char(char c){

    write(1, &c, 1);

}

int main(void){

    char lettre = 'a';
    while (lettre <= 'z'){
        put_char(lettre);
        lettre++;
    }
    write(1, "\n", 1);
    return 0;
}