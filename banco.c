#include "banco.h"
#include <stdio.h>
#include <string.h>

void menu(){
  printf("1. Novo Cliente\n");
  printf("2. Apaga Cliente\n");
  printf("3. Listar Clientes\n");
  printf("4. Débito\n");
  printf("5. Depósito\n");
  printf("6. Extrato\n");
  printf("7. Transferência entre contas\n");
  printf("8. Sair\n");
}
//strcmp -10 igual(Pelos testes feitos toda vez que a string era igual o valor foi -10, se não o valor dava "aleatorio", de negativo a positivo)


void clearBuffer(){
  int c;
  while ((c = getchar()) != '\n' && c != EOF) { }
}

void criaCliente(listaClientes *Lt){
  char tipo[5];
  int resul1;
  int resul2;

  if (Lt->quantidade < 1000){
    printf("Digite seu nome: ");
    scanf("%s", Lt->cliente[Lt->quantidade].nome);
    clearBuffer();
    printf("Digite seu cpf: ");
    fgets(Lt->cliente[Lt->quantidade].cpf,11,stdin);
    printf("Digite o tipo da sua conta: ");
    scanf("%s",tipo);
    resul1 = strcmp(tipo, "comum");
    resul2 = strcmp(tipo, "plus");
    if (resul1 == 0){
      Lt->cliente[Lt->quantidade].tipoConta = 0;
        }
    else if (resul2 == 0){
      Lt->cliente[Lt->quantidade].tipoConta = 1;
    }
    else{
      printf("Erro\n");
      return;
    }
    printf("Digite seu saldo: ");
    scanf("%f", &Lt->cliente[Lt->quantidade].saldo);
    clearBuffer(); 
    printf("Digite sua senha(maximo 10): ");
    fgets(Lt->cliente[Lt->quantidade].senha,10,stdin);
    //clearBuffer(); #não tava salvando a senha assim na realidade o clearBuffer é no de cima
    Lt -> quantidade = Lt -> quantidade + 1;
    printf("\n");
  }
  else{
    printf("Erro ao criar a conta");
  } 
}