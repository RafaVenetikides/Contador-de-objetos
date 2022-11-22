#include <stdio.h>
#include <stdlib.h>  

typedef struct sPixel{
    int fundo;
    int visto;
} sPixel;

typedef struct no{
    struct No *prox;  //aponta para o próximo elemento da pilha
    int i;
    int j;  //guarda os valores da posição xy do pixel
}No;


typedef struct{
    int qnt; //define a quantidade de elementos dentro da pilha
    No *topo;   //aponta para o primeiro elemento da pilha
}Pilha;

void criaPilha(Pilha *pilha){
    pilha->topo = NULL;
    pilha->qnt = 0;
}

void push(Pilha *pilha, int i, int j){

    No *novo = (No *)malloc(sizeof(No));
    
    novo->i = i;
    novo->j = j;    
    if (pilha->topo == NULL){
        novo->prox = NULL;
        pilha->topo = novo;
    }
    else{
        novo->prox = pilha->topo;
        pilha->topo = novo;
    }
    pilha->qnt++;
}

No *pop(Pilha *pilha){
    No *no;
    if (pilha->topo!= NULL){
        no = pilha->topo;
        pilha->topo = pilha->topo->prox;
        pilha->qnt--;
        return no;
    }
    else{ 
        return NULL;
    }
}

void printPilha(Pilha pilha){
   No *aux = pilha.topo; 
   printf("Pilha (topo->base): ");
   if (aux == NULL)
      printf("vazia.");
   else 
      while(aux!=NULL){ 
         printf(" %d %d", aux->i, aux->j); 
         aux= aux->prox;
         printf("\n");
      };
   printf("\n");
}

void leVizinhos(Pilha *pilha, int i, int j, sPixel **matriz, int linhas, int colunas){
    int c, l;
    matriz[i][j].visto = 1;
    for (l = (i-1); l <= (i + 1); l++){
        if (l > 0 && l < linhas){
            if (matriz[l][j].fundo != 0 && matriz[l][j].visto == 0){
                push(pilha, l, j);
                matriz[l][j].visto = 1;
            }
        }
    }
    for (c = (j-1); c <= (j + 1); c++){
        if (c > 0 && c < colunas){
            if (matriz[i][c].fundo != 0 && matriz[i][c].visto == 0){
                push(pilha, i, c);
                matriz[i][c].visto = 1;
            }
        }
    }
}

int main() {
    char arq[] ="PjBL2-Imagens\\01.ppm";  
    FILE *fp;  

    char id[3];
    int colunas, linhas, maximo;
    unsigned char r, g, b;
    unsigned char rf, gf, bf;
    int i, j, k;
    struct sPixel **matriz;
    int posicao, objetos;
    Pilha p;

    fp = fopen(arq, "rb"); 
    if (fp == NULL) {  
        printf("Erro na abertura do arquivo <%s>", arq);
        exit(EXIT_FAILURE);  
    }

    fscanf (fp, "%s", id);        
    fscanf (fp, "%d", &colunas);  
    fscanf (fp, "%d", &linhas);   
    fscanf (fp, "%d", &maximo);  
    fscanf (fp, "%c", &r);       

    printf("Tipo do arquivo <%s>: %s\n", arq, id);
    printf("Maximo: %d\n", maximo);
    printf("Imagem tem %d x %d pixels\n", linhas, colunas);

    posicao = ftell(fp); 
    
    fscanf (fp, "%c%c%c", &rf, &gf, &bf);
    fseek(fp, posicao, SEEK_SET); 

    matriz = (sPixel **) calloc((linhas), sizeof(sPixel *));
    
    for(i = 0; i < linhas;i++){
        matriz[i] = (sPixel *)calloc((colunas), sizeof(sPixel));
    }
   
    for (i=0; i<linhas; i++) {
        for (j=0; j<colunas; j++) {
            fscanf (fp, "%c%c%c", &r, &g, &b);
            if ((r!=rf) || (g!=gf)  || (b!=bf)  ){  
                matriz[i][j].fundo = 1;
                printf("1"); 
            } else {  
                printf("0");
            }
        }
        printf("\n");
    }

    criaPilha(&p);

    objetos = 0;
    k = 0;

    for (i = 0; i < linhas; i++){
        for (j = 0; j < colunas; j++){
            if (matriz[i][j].fundo != 0 && matriz[i][j].visto != 1){
                push(&p, i, j);
                while(p.topo != NULL){
                    No *temp = pop(&p);
                    leVizinhos(&p, temp->i, temp->j, matriz, linhas, colunas);
                }
                objetos++;
            }
        }
    }

    printf("\n numero de objetos: %d", objetos);

    fclose(fp);

    return 0;
}