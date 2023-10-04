#include <stdio.h>
#include "banco.h"

int main(void) {
  char arquivo[]= "clientes";
  listaClientes Lc;
  int codigo;
  //codigo = ler_arquivo(&Lc, arquivo);  l
  int opcao;
  do{
    menu();
    printf("Digite o número de sua escolha: ");
    scanf("%d",&opcao);
    switch(opcao){
      case 1 :
        criaCliente(&Lc);
        break;
      case 2 :
        deletarCliente(&Lc);
        break;
      case 3 :
        listaCliente(Lc);
        break;
      case 4 :
        debito(&Lc);
        break;
      case 5 :
        deposito(&Lc);
        break;
      case 7 :
        transferencia(&Lc);
        break;
    }
    
  }while(opcao != 0);

  codigo = salva_clientes(Lc, arquivo);
  if(codigo != 0){
        printf("Erro ao salvar as tarefas\n");
    }

}