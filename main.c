#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct pixel {

    int x;
    int y;
};

int main(){

    struct pixel * pilha;
    FILE *file;
    char buffer[1000];
    bool keep_reading = true;
    int current_line = 1;
    int read_line = 4;

    file = fopen("PjBL2 - Imagens\\01.ppm", "rb");
    // file = fopen("C:\\Users\\rafael.venetikides\\OneDrive - Grupo Marista\\PI\\Contador de objetos\\PjBL2 - Imagens\\01.ppm", "rb");

    if (file == NULL){
        printf("Erro do arquivo\n");
        exit(1);
    }
    else{
        printf("Arquivo aberto\n");
    }

    do{
        fgets(buffer, 1000, file);
        if (feof(file)){
            keep_reading = false;
            printf("File %c lines\n", current_line - 1);
            printf("Couldnt find line");
        }
        else if(current_line == read_line){
            keep_reading = false;
            printf("line :\n %d", buffer);
        }
        current_line++;

    }while (keep_reading);

    fclose(file);

    return 0;
}