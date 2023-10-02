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

void listaCliente(listaClientes Lt){
  printf("\n");
  for (int ToDo = 0; ToDo< Lt.quantidade; ToDo++ ){
    printf("Nome: %s\t\n",Lt.cliente[ToDo].nome);
    printf("Cpf: %s",Lt.cliente[ToDo].cpf);
    printf("Saldo: %.2f\t\n",Lt.cliente[ToDo].saldo);
    if(Lt.cliente[ToDo].tipoConta == 0){
      printf("Tipo de Conta: Comum\t\n");
    }
    else{
      printf("Tipo de Conta: Plus\t\n");
    }
    printf("\n");
}
}

int deletarCliente(listaClientes *Lt){
  char cpfDel[11];
  int compara;
    printf("Digite o cpf da conta que deseja deletar: ");
    scanf("%s",cpfDel);
    if (Lt->quantidade == 0){   
        printf("Nenhum cpf encontrado :( \n ");
        return 1;
    }
     for (int search = 0; search< Lt->quantidade; search++ ){
       compara = strcmp(cpfDel,Lt->cliente[search].cpf);
       if(compara == -10){
        strcpy(Lt->cliente[search].cpf, Lt->cliente[search +1].cpf);
        Lt->cliente[search].saldo = Lt->cliente[search +1].saldo;   
        Lt->cliente[search].tipoConta = Lt->cliente[search +1].tipoConta;  
        strcpy(Lt->cliente[search].nome, Lt->cliente[search +1].nome); 
        strcpy(Lt->cliente[search].senha, Lt->cliente[search +1].senha);      
        Lt->quantidade--;
        printf("Deletou com sucesso!\n");
        return 0;
        break;
       }
     }
    printf("Cpf não encontrado");
    return 1;
}