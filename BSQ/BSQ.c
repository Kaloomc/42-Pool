#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1000

#include <string.h>

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}



int test_square(char **map, int offset_x, int offset_y, int size, char vide, int nb_lignes) {
    for (int y = 0; y < size; y++) {
        if (offset_y + y >= nb_lignes) return 1;
        for (int x = 0; x < size; x++) {
            if (map[offset_y + y][offset_x + x] != vide)
                return 1;
        }
    }
    return 0; // OK
}

void find_biggest_square(char **map, int nb_lignes, char vide,char remplissage, int *result) {
    int max_x = 0;
    int max_y = 0;
    int max_size = 0;

    int line_len = strlen(map[0]); // suppose que toutes les lignes ont même taille

    for (int y = 0; y < nb_lignes; y++) {
        for (int x = 0; x < line_len; x++) {
            int size = 1;
            while (!test_square(map, x, y, size, vide, nb_lignes) && x + size <= line_len)
                size++;
            if (size - 1 > max_size) {
                max_size = size - 1;
                max_x = x;
                max_y = y;
            }
        }
    }

    result[0] = max_x;
    result[1] = max_y;
    result[2] = max_size;

    for (int y = 0; y < result[2]; y++) {
        for (int x = 0; x < result[2]; x++) {
            map[result[1] + y][result[0] + x] = remplissage;
    }
}

}


void read_file(FILE *fp)
{
    char header[MAX_BUFFER_SIZE];
    fgets(header, MAX_BUFFER_SIZE, fp); // lis la 1re ligne (ex: "9.ox\n")

    // Récupération des infos
    int nb_ligne = atoi(header); // lis les premiers chiffres (ex: "9")
    int len = 0;
    while (header[len] >= '0' && header[len] <= '9')
        len++;

    char vide = header[len];
    char obstacle = header[len + 1];
    char remplissage = header[len + 2];

    // Allocation du tableau de lignes
    char **map = malloc(sizeof(char *) * nb_ligne);

    for (int i = 0; i < nb_ligne; i++) {
        map[i] = malloc(MAX_BUFFER_SIZE);
        fgets(map[i], MAX_BUFFER_SIZE, fp);
    }

    // Test affichage d'une ligne
    int result[3]; // x, y, taille
    find_biggest_square(map, nb_ligne, vide, remplissage,result);
    for(int i = 0; i < nb_ligne;i++){

        printf("%s", map[i]);

    }

    // Libération mémoire
    for (int i = 0; i < nb_ligne; i++) {
        free(map[i]);
    }
    free(map);



}

int main()
{
    FILE *fp = fopen("Carte", "r");
    if (fp == NULL) {
        perror("Erreur d'ouverture");
        return 1;
    }

    read_file(fp);

    fclose(fp);
    return 0;
}
