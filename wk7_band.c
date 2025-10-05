#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main ()
{
    char color[100], snack [100], animal[100];
    char bandname1[200], bandname2[200], bandname3[200];

    printf("Enter your favorite color: ");
    fgets(color, sizeof(color), stdin);
    color[strcspn(color, "\n")] = 0;

    printf("Enter your favorite snack: ");
    fgets(snack, sizeof(snack), stdin);
    snack[strcspn(snack, "\n")] = 0;

    printf("Enter your favorite animal: ");
    fgets(animal, sizeof(animal), stdin);
    animal[strcspn(animal, "\n")] = 0;

    strcpy(bandname1, "The ");
    strcat(bandname1, color);
    strcat(bandname1, " ");
    strcat(bandname1, snack);

    strcpy(bandname2, "The ");
    strcat(bandname2, color);
    strcat(bandname2, " ");
    strcat(bandname2, animal);

    strncpy(bandname3, snack, 3);
    bandname3[3] = '\0';
    strncat(bandname3, animal, 2);
    strcat(bandname3, "s");

    printf("Presenting ... %s!\n", bandname1);
    printf("Tonight only ... %s!\n", bandname2);
    printf("Get ready for ... %s!\n", bandname3);
}