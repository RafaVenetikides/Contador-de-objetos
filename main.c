#include <stdio.h>
#include <stdlib.h>

int main(){

    char * buffer;
    FILE *file;
    long filesize;
    size_t resultado;
    int i;

    file = fopen("C:\\Users\\rafael.venetikides\\OneDrive - Grupo Marista\\PI\\Contador de objetos\\PjBL2 - Imagens\\01.ppm", "rb");

    if (file == NULL){
        printf("Erro do arquivo");
        exit(1);
    }
    else{
        printf("Arquivo aberto");
    }

    fseek(file, 0, SEEK_END);
    filesize = ftell(file);
    rewind(file);

    buffer = (char*) malloc(sizeof(char)*filesize);

    if (buffer == NULL){
        printf("Erro de memória");
        exit(2);
    }

    resultado = fread(buffer, 1, filesize, file);
    if (resultado != filesize){
        printf("Erro de Leitura");
        exit(3);
    }

    for (i = 0; i < filesize; i++){
        printf("%c", buffer);
        printf(" local: (%x) i: (%d)\n", *buffer, i);
        buffer++;
    }
    
    fclose(file);
    free(buffer);

    return 0;
}