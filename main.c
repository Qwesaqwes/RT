#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main (int argc, char **argv)
{
    FILE        *fichier;

    time_t      timestamp;
    struct tm   *t;

    fichier = NULL;




    timestamp = time(NULL);
    t = localtime(&timestamp);
    while (1)
    {
        timestamp = time(NULL);
        t = localtime(&timestamp);
        system("clear");
        printf("sauvegarde du %d-%d-%d a %dh%dm%ds\n", t->tm_mday, t->tm_mon + 1, t->tm_year+1900,t->tm_hour, t->tm_min, t->tm_sec);
    }
    if (argv[1])
    {
        fichier = fopen(argv[1], "w");
        if (fichier != NULL)
        {
            fputs("ficier de sauvegarde\n", fichier);
            fputs("ficier de sauvegarde\n", fichier);
            fputs("ficier de sauvegarde\n", fichier);
            fputs("ficier de sauvegarde\n", fichier);
            fclose(fichier);
        }
    }
    return (0);
}
