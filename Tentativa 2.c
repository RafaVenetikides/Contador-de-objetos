#include <stdio.h>
#include <stdlib.h>

//void examinaCabecalho(FILE *, char [2], int, int, int);

typedef struct sPixel{
    int fundo;
    int visto;
} sPixel;

int main(){

    char magic_number[2];
    int height, length, valormax, **matriz, i, j;
    FILE *file;

    file = fopen("PjBL2 - Imagens\\01.ppm", "rb");

    if (file == NULL){
        printf("Falha ao abrir o arquivo!\n");
        exit(1);
    }
    else{
        printf("Arquivo Aberto!\n");
    }

    //examinaCabecalho(file, magic_number, height, length, valormax);

    fscanf(file, "%s", magic_number);
    fscanf(file, "%d %d", &height, &length);
    fscanf(file, "%d", &valormax);
    printf("%s\n%d %d\nvalor máximo: %d\n",magic_number, height, length, valormax);
    
    matriz = (int **)calloc((height), sizeof(int));
    matriz[0] = calloc((length * 3), sizeof(int));
    
    printf("i  = %d, height = %d, length = %d\n", i, height, length);

    for(i = 1; i < height;i++){
        printf("%d", i);
        matriz[i] =  matriz [0] + i * (length *3);
    }
    printf("\n");

    for(i = 0; i < height; i++){
        for(j = 0; j < (length*3); j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    

    fclose(file);
    free(matriz[0]);
    free(matriz);

    return 0;
}

/*void examinaCabecalho(FILE *file, char magic_number[2], int height, int length, int valormax){

}*/