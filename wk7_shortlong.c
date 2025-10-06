#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        fprintf(stderr, "Usage: %s <input_file> <short_file> <long_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *input_filename = argv[1];
    char *short_filename = argv[2];
    char *long_filename = argv[3];

    FILE *input_file = fopen(input_filename, "r");

    if(input_file == NULL)
    {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    FILE *short_file = fopen(short_filename, "w");

    if(short_file == NULL)
    {
        perror("Error opening short file");
        fclose(input_file);
        exit(EXIT_FAILURE);
    }

    FILE *long_file = fopen(long_filename, "w");

    if(long_file == NULL)
    {
        perror("Error opening long file");
        fclose(input_file);
        fclose(short_file);
        exit(EXIT_FAILURE);
    }
    char line[2000];
    int short_count = 0;
    int long_count = 0;

    while (fgets(line, sizeof(line), input_file) != NULL)
    {
        size_t len = strlen(line);
        if (len > 0 && line[len -1 ] == '\n')
        {
            line[len - 1] = '\0';
            len--;
        }
        if (len < 20)
        {
            for(int i = 0; i < len; i++)
            {
                line[i] = toupper(line[i]);
            }
            fprintf(short_file, "%s\n", line);
            short_count++;
        }
        else
        {
            for(int i = 0; i < len; i++)
            {
                line[i] = tolower(line[i]);
            }
            fprintf(long_file, "%s\n", line);
            long_count++;
        }
    }

    fclose(input_file);
    fclose(short_file);
    fclose(long_file);

    printf("%d lines written to %s\n", short_count, short_filename);
    printf("%d lines written to %s\n", long_count, long_filename);

    return 0;
}