#include <stdio.h>

void push(int *stack, int *up){

    ++*up;

    printf("Entre com o valor a ser adicionado na pilha (stack):");

    scanf("%d", &*(stack+*up));

}

void pop(int *stack, int *up){

    printf("O item excluido da pilha foi:%d\n", *(stack+*up));
    *(stack+*up) = 0;
    --*up;

}

void print(int *stack, int *up){
    int i;

    if(*up>=0){

        for (i = 0; i <= *up; i++){
            printf("[%d] = %d\n", i, *(stack+i));
        }


    }else printf("A pilha esta vazia. ");



}

int main(){
    int TAM = 5;
    int stack[TAM];
    int *pontDaStack = stack;
    int op = 1;
    int up = -1;
    int *pontDoUp = &up;
    int funcao;

    do {
        printf("Escolha a funcao:\n");
        printf("Adicionar valor na pilha [1]\n");
        printf("Printar a fila [2]\n");
        printf("Excluir ultimo item da pilha [3]\n");
        scanf("%d", &funcao);

        switch (funcao) {
            case 1:
                if(up<TAM) push(pontDaStack, pontDoUp);
                else printf("A pilha esta cheia.");
                break;

            case 2:
                if(up>=0) print(pontDaStack, pontDoUp);
                else printf("A fila esta vazia.");
                break;

            case 3:
                if(up>0) pop(pontDaStack, pontDoUp);
                else printf("A pilha esta vazia, adicione pelo menos um elemento para poder utilizar esta opcao.\n");
                break;

            default:
                printf("Adicionar valor na pilha [1]\n");
                printf("Printar a fila [2]\n");
                printf("Excluir ultimo item da pilha [3]\n");
                scanf("%d", &funcao);
                scanf("%d", &funcao);

        }
        printf("Deseja realizar mais uma operacao?\nSIM[1]\nNAO[0]\n");
        scanf("%d", &op);
    } while (op == 1);

}

