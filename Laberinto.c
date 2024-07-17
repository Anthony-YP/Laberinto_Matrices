#include <stdio.h>
#include <stdlib.h> //para system

int main()
{

    int r, c; // variables para renglon y columna
    int p = 7;
    int h = 0;
    int pc = 7;
    int hc = 0;
    char direc;
    int difi;
    int conti;

    FILE *pnt_mapafacil;
    pnt_mapafacil = fopen("mapafacil.txt", "rt");

    FILE *pnt_mapanormal;
    pnt_mapanormal = fopen("mapanormal.txt", "rt");

    FILE *pnt_mapadificil;
    pnt_mapadificil = fopen("mapadificil.txt", "rt");

    FILE *pnt_prueba;                           // Apuntador o direccion del documento
    pnt_prueba = fopen("mapaprueba.txt", "rt"); // direccion fisica

    char tu[21][41]; // personaje
    printf("\t\t\t¡Bienvenido al mundo de los laberintos!");
    printf("\nSeleccione la dificultad: ");
    printf("\n1) Facil \n2) Normal \n3) Dificil \n4)Solo prueba \n ");
    scanf(" %i", &difi);

    if (difi == 1)
    {
        for (r = 0; r < 21; ++r)
        {
            for (c = 0; c < 41; ++c)
            {
                fscanf(pnt_mapafacil, "%c", &tu[r][c]);
            }
            fgetc(pnt_mapafacil); // leer el salto de linea
        }
        fclose(pnt_mapafacil);
    }
    else if (difi == 2)
    {
        for (r = 0; r < 21; ++r)
        {
            for (c = 0; c < 41; ++c)
            {
                fscanf(pnt_mapanormal, "%c", &tu[r][c]);
            }
            fgetc(pnt_mapanormal); // leer el salto de linea
        }
        fclose(pnt_mapanormal);
    }
    else if (difi == 3)
    {
        for (r = 0; r < 21; ++r)
        {
            for (c = 0; c < 41; ++c)
            {
                fscanf(pnt_mapadificil, "%c", &tu[r][c]);
            }
            fgetc(pnt_mapadificil); // leer el salto de linea
        }
        fclose(pnt_mapadificil);
    }
    else if (difi == 4)
    {
        for (r = 0; r < 21; ++r)
        {
            for (c = 0; c < 41; ++c)
            {
                fscanf(pnt_prueba, "%c", &tu[r][c]);
            }
            fgetc(pnt_prueba); // leer el salto de linea
        }
        fclose(pnt_prueba);
    }

    // Matriz
    /*for(r=0;r<20;++r){
        for(c=0;c<40;++c){
            fscanf(pnt_prueba,"%c",&tu[r][c]);
        }
        fgetc(pnt_prueba); //leer el salto de linea
    }
    fclose(pnt_prueba);*/

    do
    {
        tu[p][h] = 'o';
        // mostrar matriz
        for (r = 0; r < 21; ++r)
        {
            for (c = 0; c < 41; ++c)
            {
                printf("%c", tu[r][c]);
            }
            printf("\n");
        }
        printf("¿Hacia donde?  ");
        scanf(" %c", &direc);

        // u up,d down,r right,l left

        if (direc == 'u')
        {
            if (tu[--pc][hc] == ' ')
            {
                tu[p][h] = ' ';
                --p;
            }
            else
            {
                printf("Movimiento invalido\n");
                ++pc;
            }
        }
        else if (direc == 'd')
        {
            if (tu[++pc][hc] == ' ')
            {
                tu[p][h] = ' ';
                ++p;
            }
            else
            {
                printf("Movimiento invalido\n");
                --pc;
            }
        }
        else if (direc == 'r')
        {
            if (tu[pc][++hc] == ' ')
            {
                tu[p][h] = ' ';
                ++h;
            }
            else
            {
                --hc;
                printf("Movimiento invalido\n");
            }
        }
        else if (direc == 'l')
        {
            if (tu[pc][--hc] == ' ')
            {
                tu[p][h] = ' ';
                --h;
            }
            else
            {
                ++hc;
                printf("Movimiento invalido\n");
            }
        }
        if (p == 20 || h == 40)
        {
            printf("ganasteee");
            conti = 5;
        }
    } while (conti != 5);
    return 0;
}
