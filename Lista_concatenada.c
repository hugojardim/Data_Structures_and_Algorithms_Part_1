#include <stdio.h>
#include <stdlib.h>


typedef struct lista{

    int valor;
    struct lista *proximo;

}lista;

struct lista *atual = NULL;

void adicionar(int dado){

    //Alocar espaço na memória heap para o novo item da lista
    struct lista *novoValor = (struct lista*) malloc(sizeof(lista));

    //Caso o malloc não funcione dar return
    if(novoValor == NULL) return;

    //Criando o nó
    novoValor->valor = dado;
    novoValor->proximo = NULL;

    //Caso seja o primeiro item adicionado à lista
    if(atual == NULL){
        atual = novoValor;
        return;
    }

    //Cria-se um nó temporário para indicar a posição do novo nó a ser adicionado
    struct lista *ultimo = atual;

    //Caminha-se até o último nó
    while (ultimo->proximo != NULL) ultimo = ultimo->proximo;

    //Adiciona o novo nó em sua posição
    ultimo->proximo = novoValor;

}

void printarLista(void){
    int cont = 0;

    do {
        printf("[%d]=>%d\n", cont, atual->valor);
        cont++;
        atual = atual->proximo;

    } while (atual != NULL);
    printf("\n");
}

void excluirOuAlterar(){
    int opt, posicao, i, dado;

    lista *pontValor = atual;

    if(pontValor == NULL){
        printf("A fila esta vazia.");
        return;
    }

    printf("Escolha uma opcao:\n");
    printf("Alterar valor[1]\n");
    printf("Excluir valor[2]\n");
    scanf("%d", &opt);

    switch (opt) {

        case 1:
            printf("atual: %d\n", atual->valor);
            printf("Qual item deseja alterar (indique a posicao):\n");
            printarLista();
            scanf("%d", &posicao);

            for (i = 0; i < posicao; i++){
                pontValor = pontValor->proximo;
                printf("PontValor depois:%d", &(pontValor->valor));
            }

            printf("%d\n", pontValor->valor);
            printf("Valor pelo qual sera alterado:");
            scanf("%d", &dado);
            pontValor->valor = dado;
            printf("Nova lista:\n");
            printarLista();

            break;

        case 2:

            break;

        default:

            break;
    }


}

int main(){
    int valorEscolhido, opcao, op=1;

    do {
        printf("Qual operacao voce deseja realizar?\n");
        printf("Adicionar valor no final da lista [1]\n");
        printf("Printar lista [2]\n");
        printf("Excluir ou alterar valor da lista [3]\n");

        scanf("%d", &opcao);

        switch (opcao) {

            case 1:
                printf("Valor a ser adicionado:");
                scanf("%d", &valorEscolhido);
                adicionar(valorEscolhido);
                printf("Atual antes:%d", &(atual->valor));
                break;

            case 2:
                printarLista();
                break;

            case 3:
                excluirOuAlterar();

            default:
                printf("Escolha uma opcao valida.");
                scanf("%d", &opcao);
                break;
        }

        printf("Deseja realizar outra operacao?\nSim [1]\nNao [0]");
        scanf("%d", &op);
    } while (op != 0);

    return 0;
}
