#include <stdio.h>
#include "banco.h"

int main(void) {
  char arquivo[]= "clientes";
  listaClientes Lc;
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
    }
    
  }while(opcao != 0);
  
  
  return 0;
}