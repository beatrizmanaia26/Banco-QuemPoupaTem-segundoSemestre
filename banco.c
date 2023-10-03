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
  printf("0. Sair\n");
  printf("\n");
}

//strcmp -10 igual(Pelos testes feitos toda vez que a string era igual o valor foi -10, se não o valor dava "aleatorio", de negativo a positivo)

void clearBuffer(){  //para limpar o buffer
  int c;
  while ((c = getchar()) != '\n' && c != EOF) { }
}

void criaCliente(listaClientes *Lc){
  char tipo[5];
  int resulComum;
  int resulPlus;

  if (Lc->quantidade < 1000){
    printf("Digite seu nome: ");
    scanf("%s", Lc->cliente[Lc->quantidade].nome);
    clearBuffer();
    printf("Digite seu cpf: ");
    fgets(Lc->cliente[Lc->quantidade].cpf,11,stdin);
    printf("Digite o tipo da sua conta: ");
    scanf("%s",tipo);
    resulComum = strcmp(tipo, "comum");
    resulPlus = strcmp(tipo, "plus");
    if (resulComum == 0){
      Lc->cliente[Lc->quantidade].tipoConta = 0;
        }
    else if (resulPlus == 0){
      Lc->cliente[Lc->quantidade].tipoConta = 1;
    }
    else{
      printf("Erro\n");
      return;
    }
    printf("Digite seu saldo: ");
    scanf("%f", &Lc->cliente[Lc->quantidade].saldo);
    clearBuffer(); 
    printf("Digite sua senha(maximo 10): ");
    fgets(Lc->cliente[Lc->quantidade].senha,10,stdin);
    Lc -> quantidade = Lc -> quantidade + 1;
    printf("\n");
  }
  else{
    printf("Erro ao criar a conta");
  } 
}

void listaCliente(listaClientes Lc){
  printf("\n");
  for (int indice = 0; indice< Lc.quantidade; indice++ ){
    printf("\n");
    printf("Nome: %s\t\n",Lc.cliente[indice].nome);
    printf("Cpf: %s",Lc.cliente[indice].cpf);
    printf("Saldo: %.2f\t\n",Lc.cliente[indice].saldo);
    if(Lc.cliente[indice].tipoConta == 0){
      printf("Tipo de Conta: Comum\t\n");
    }
    else{
      printf("Tipo de Conta: Plus\t\n");
    }
  }
}

void deletarCliente(listaClientes *Lc){
  char cpfDel[11];
  int compara;
    printf("Digite o cpf da conta que deseja deletar: ");
    scanf("%s",cpfDel);
    if (Lc->quantidade == 0){   
        printf("Nenhum cpf encontrado :( \n ");
        return;
    }
     for (int indice = 0; indice< Lc->quantidade; indice++ ){
       compara = strcmp(cpfDel,Lc->cliente[indice].cpf);
       if(compara == -10){
         strcpy(Lc->cliente[indice].cpf, Lc->cliente[indice +1].cpf);
         Lc->cliente[indice].saldo = Lc->cliente[indice +1].saldo;   
         Lc->cliente[indice].tipoConta = Lc->cliente[indice +1].tipoConta;  
         strcpy(Lc->cliente[indice].nome, Lc->cliente[indice +1].nome); 
         strcpy(Lc->cliente[indice].senha, Lc->cliente[indice +1].senha);      
         Lc->quantidade--;
         printf("Deletou com sucesso!\n");
         return;
         break;
       }
     }
    printf("Cpf não encontrado");
    return;
}

 void debito(listaClientes *Lc){
   char cpf[11]; //o que sera digitado pelo usuario
   char senha[10]; //o que sera digitado pelo usuario
   float valorDeb;
   printf("Digite seu cpf: ");
   scanf("%s", cpf);
   printf("Digite sua senha: ");
   scanf("%s",senha);
   printf("Valor que deseja ser retirado: ");
   scanf("%f",&valorDeb);
   int cpfCompara;
   int senhaCompara;
   float tarifa =0;
   for (int indice = 0; indice< Lc->quantidade; indice++ ){
   cpfCompara = strcmp(cpf,Lc->cliente[indice].cpf);
   senhaCompara = strcmp(senha,Lc->cliente[indice].senha);
     if( cpfCompara == -10){ //Número da -10 que quando a string é igual
       if(senhaCompara == -10){
         if(Lc->cliente[indice].tipoConta == 0){ //conta comum
           tarifa = valorDeb*0.05;
           valorDeb = valorDeb + tarifa;
           int conf = Lc->cliente[indice].saldo - valorDeb;
           if(conf >= -1000){
             Lc->cliente[indice].saldo = Lc->cliente[indice].saldo - valorDeb;
             printf("Debito feito com sucesso!\n");
             return;
           }
           else{
             printf("Debito recusado, valor excedeu o limite(-1000)\n");
           }
         }
         else{ //Conta plus
           tarifa = valorDeb*0.03;
           valorDeb = valorDeb + tarifa;
           int conf = Lc->cliente[indice].saldo - valorDeb;
           if(conf >= -5000){
             Lc->cliente[indice].saldo = Lc->cliente[indice].saldo - valorDeb;
             printf("Debito feito com sucesso!\n");
           }
           else{
             printf("Debito recusado, valor excedeu o limite(-5000)\n");
           } 
         }
       }    
     }
   }
   printf("Erro ao debitar ):");
 }

void deposito(listaClientes *Lc){
  int numero = 0;
  float novoSaldo_dest = 0;
  float valorDeposito;
  char cpfDest[11];//digitado pelo usuario
  printf("Digite valor do cpf do destinatário: ");
  scanf("%s", cpfDest);
  printf("Digite o valor do depósito: ");
  scanf("%f", &valorDeposito);
  for (int indice = 0; indice< Lc->quantidade; indice++ ){
   numero = strcmp(cpfDest,Lc->cliente[indice].cpf); //strcmp retorna um numero
     if( numero == -10){ //Número da -10 que quando a string é igual
       novoSaldo_dest = Lc->cliente[indice].saldo + valorDeposito;
       Lc->cliente[indice].saldo = novoSaldo_dest; 
       printf("Deposito feito com sucesso!\n");
       return;
      }
   }
  printf("Erro ao depositar ):" );
  printf("\n");
}

void transferencia(listaClientes *Lc){
  char cpfOri[11]; //o que sera digitado pelo usuario
  char cpfDest[11];//digitado pelo usuario
  char senha[10]; //o que sera digitado pelo usuario
  float valor;
  float novoSaldo_dest = 0;
  float tarifa =0;
  int numero = 0;
  int cpfOriCompara;
  int cpfDestCompara;
  int senhaCompara;
  int valorTotal;
  printf("Digite seu cpf: ");
  scanf("%s", cpfOri);
  printf("Digite sua senha: ");
  scanf("%s",senha);
  printf("Digite o cpf do destinatário: ");
  scanf("%s", cpfDest);
  printf("Digite o valor a ser transferido: ");
  scanf("%f", &valor);
//Procura e verifica o cpf e senha de quem vai transferir
  for (int indice = 0; indice< Lc->quantidade; indice++ ){
   cpfOriCompara = strcmp(cpfOri,Lc->cliente[indice].cpf); //Cpf de origem, compara se der -10 o cpf foi encontrado
   senhaCompara = strcmp(senha,Lc->cliente[indice].senha);
     if(cpfOriCompara == -10){ 
       if(senhaCompara == -10){
         for (int indiceDest = 0; indiceDest< Lc->quantidade; indiceDest++ ){
           if(Lc->cliente[indice].tipoConta == 0){ //conta comum
             tarifa = valor*0.05;
             valorTotal = valor + tarifa;
             int conf = Lc->cliente[indice].saldo - valorTotal;
             if(conf >= -1000){
               Lc->cliente[indice].saldo = Lc->cliente[indice].saldo - valorTotal;
               novoSaldo_dest = Lc->cliente[indiceDest].saldo + valor;
               Lc->cliente[indiceDest].saldo = novoSaldo_dest;  
               printf("Transferência feita com sucesso! :) \n");
               return;
             }
             else{
               printf("Transferência recusada, valor excedeu o limite(-1000)\n");
             }
           }
           else{ //Conta plus
             tarifa = valor*0.03;
             valorTotal = valor + tarifa;
             int conf = Lc->cliente[indice].saldo - valorTotal;
             if(conf >= -5000){
               Lc->cliente[indice].saldo = Lc->cliente[indice].saldo - valorTotal;
               novoSaldo_dest = Lc->cliente[indiceDest].saldo + valor;
               Lc->cliente[indiceDest].saldo = novoSaldo_dest;
               printf("Transferência feita com sucesso!\n");
             }
             else{
               printf("Transferência recusado, valor excedeu o limite(-5000)\n");
             } 
           }
         }    
       }
     }
   }
 }
  