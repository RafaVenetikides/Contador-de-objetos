#include <stdio.h>
#include <stdlib.h>

struct pixel {

    int r;
    int g;
    int b;
};

int main(){

    struct pixel * pilha;
    FILE *file;
    int i, j;
    int teste[32][32];
    int valor;

    file = fopen("D:\\OneDrive - Grupo Marista\\PI\\Contador de objetos\\PjBL2 - Imagens\\01.ppm", "rb");
    // file = fopen("C:\\Users\\rafael.venetikides\\OneDrive - Grupo Marista\\PI\\Contador de objetos\\PjBL2 - Imagens\\01.ppm", "rb");

    if (file == NULL){
        printf("Erro do arquivo\n");
        exit(1);
    }
    else{
        printf("Arquivo aberto\n");
    }

    for (i = 0; i < 1024; i++){
        fscanf(file, "%d   ", &valor);
        if (valor == 0){
            teste[i] = 0; 
        }
        else{
            teste [i] = 1;
        }
    }
    for (i = 0; i > 32; i++){
        for (j = 0; j > 32; j++){
            printf("%d", teste[i][j]);
        }
    }
    fclose(file);

    return 0;
}