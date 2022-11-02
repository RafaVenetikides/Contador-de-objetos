#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE *file, *pFile;
    int i, s, filesize, *buffer;
    char line[3072];
    char img[3072];
    i = 1;
    file = fopen("D:\\OneDrive - Grupo Marista\\PI\\Contador de objetos\\PjBL2 - Imagens\\01.ppm", "r");
    pFile = fopen ("D:\\OneDrive - Grupo Marista\\PI\\Contador de objetos\\teste.txt","w+");
    fseek(file, 0, SEEK_END);
    filesize = ftell(file);
    rewind(file);

    buffer = malloc(filesize + 1);

    fread(buffer, filesize, 1, file);
    fscanf(file, "%d", buffer);
    printf("%s", buffer);
    

   while(!feof(file)){
        fgets(line, 3072, file);
        printf("%s", line);
    }

    printf("\nImagem: \n");
    rewind(file);

    while(!feof(file)){
        fscanf(file, "%s", img);
        printf("%s \n", img);
    }

    /*
    fscanf(file, "%s", img);
    printf("%s \n", img);

    fscanf(file, "%s", img);
    printf("%s \n", img);

    fscanf(file, "%s", img);
    printf("%s \n", img);

    fscanf(file, "%s", img);
    fprintf(pFile, "%s", img);
    printf("%s \n", img);*/
    
    



    fclose(file);
    
    return 0;
}