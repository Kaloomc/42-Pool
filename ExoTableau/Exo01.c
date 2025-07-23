#include <unistd.h>

int main(void)
{
    int i = 0;
    char c;
    char *str;
    str = "Salut les Amis";
    

    while (str[i] != '\0'){
        c = str[i];
        write(1,&c,1);
        i++;
    }
    write(1, "\n", 1);
    return 0;
}
