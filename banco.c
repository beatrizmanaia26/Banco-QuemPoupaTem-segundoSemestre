#include "banco.h"
#include <stdio.h>
#include <string.h>
// strcmp -10 igual(Pelos testes feitos toda vez que a string era igual o valor
// foi -10, se não o valor dava "aleatorio", de negativo a positivo) // na
// verdade ela consede esse valor pois esta considerando o /n das strings, mas
// de todo jeito mudaremos o cpf e a senha para numeros por erro de falta de
// memória strcnp Tira o /n e o /0
void menu() {
  printf("\n");
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

void clearBuffer() { // para limpar o buffer
  int c;
  while ((c = getchar()) != '\n' && c != EOF) {
  }
}

void criaCliente(listaClientes *Lc) {
  char tipo[5];
  int resulComum;
  int resulPlus;
  long comparaCpf;
  //&Lc->cliente[Lc->quantidade].cpf
  if (Lc->quantidade < 1000) {
    printf("Digite seu nome: ");
    scanf("%s", Lc->cliente[Lc->quantidade].nome);
    clearBuffer();
    printf("Digite seu cpf: ");
    scanf("%ld", &comparaCpf);
    for (int indice = 0; indice < Lc->quantidade; indice++) {
      if (comparaCpf == Lc->cliente[indice].cpf) {
        printf("CPF já cadastrado\n");
        return;
      }
    }
    Lc->cliente[Lc->quantidade].cpf = comparaCpf;
    printf("Digite o tipo da sua conta: ");
    scanf("%s", tipo);
    resulComum = strcmp(tipo, "comum");
    resulPlus = strcmp(tipo, "plus");
    if (resulComum == 0) {
      Lc->cliente[Lc->quantidade].tipoConta = 0;
    } else if (resulPlus == 0) {
      Lc->cliente[Lc->quantidade].tipoConta = 1;
    } else {
      printf("Erro ao criar conta, apenas aceitamos tipo de conta plus ou "
             "comum!\n"); // USAR ENUM
      return;
    }
    printf("Digite seu saldo: ");
    scanf("%f", &Lc->cliente[Lc->quantidade].saldo);
    clearBuffer();
    printf("Digite sua senha(maximo 10): ");
    scanf("%d", &Lc->cliente[Lc->quantidade].senha);
    Lc->quantidade = Lc->quantidade + 1;
    printf("\n");
  } else {
    printf("Erro ao criar a conta");
  }
}
void listaCliente(listaClientes Lc) {
  printf("\n");
  if (Lc.quantidade == 0) {
    printf("Não há clientes cadastrados\n");
    return;
  }
  for (int indice = 0; indice < Lc.quantidade; indice++) {
    printf("\n");
    printf("Nome: %s\t\n", Lc.cliente[indice].nome);
    printf("Cpf: %ld\n", Lc.cliente[indice].cpf);
    printf("Saldo: %.2f\t\n", Lc.cliente[indice].saldo);
    // printf("Indice do cliente: %d\t\n",indice);
    if (Lc.cliente[indice].tipoConta == 0) {
      printf("Tipo de Conta: Comum\t\n");
    } else {
      printf("Tipo de Conta: Plus\t\n");
    }
  }
}

void deletarCliente(listaClientes *Lc) {
  long cpfDel;
  char arquivo[30];
  printf("Digite o cpf da conta que deseja deletar: ");
  scanf("%ld", &cpfDel);
  if (Lc->quantidade == 0) {
    printf("Nenhum cpf encontrado :( \n ");
    return;
  }
  for (int indiceCpf = 0; indiceCpf < Lc->quantidade; indiceCpf++) {
    if (cpfDel == Lc->cliente[indiceCpf].cpf) {
      for (int indice = indiceCpf; indice < Lc->quantidade; indice++) {
        Lc->cliente[indice].cpf = Lc->cliente[indice + 1].cpf;
        Lc->cliente[indice].saldo = Lc->cliente[indice + 1].saldo;
        Lc->cliente[indice].tipoConta = Lc->cliente[indice + 1].tipoConta;
        strcpy(Lc->cliente[indice].nome, Lc->cliente[indice + 1].nome);
        Lc->cliente[indice].senha = Lc->cliente[indice + 1].senha;
        strcpy(Lc->cliente[indice].extrato->texto,
               Lc->cliente[indice + 1].extrato->texto);
        Lc->cliente[indice].quant_extrato =
            Lc->cliente[indice + 1].quant_extrato;
      }
      Lc->quantidade--;
      sprintf(arquivo, "extratoCpf:%ld.txt", cpfDel);
      remove(arquivo);

      printf("Deletou com sucesso!\n");
      return;
    }
  }
  printf("Cpf não encontrado");
  return;
}

void debito(listaClientes *Lc) {
  long cpf;  // o que sera digitado pelo usuario
  int senha; // o que sera digitado pelo usuario
  float valorDeb;
  printf("Digite seu cpf: ");
  scanf("%ld", &cpf);
  printf("Digite sua senha: ");
  scanf("%d", &senha);
  printf("Valor que deseja ser retirado: ");
  scanf("%f", &valorDeb);
  float tarifa = 0;
  for (int indice = 0; indice < Lc->quantidade; indice++) {
    if (cpf == Lc->cliente[indice].cpf) {
      if (senha == Lc->cliente[indice].senha) {
        if (Lc->cliente[indice].tipoConta == 0) { // conta comum
          tarifa = valorDeb * 0.05;
          valorDeb = valorDeb + tarifa;
          int conf = Lc->cliente[indice].saldo - valorDeb;
          if (conf >= -1000) {
            Lc->cliente[indice].saldo = Lc->cliente[indice].saldo - valorDeb;
            // adicionando contas do débito no struct de extrato
            sprintf(Lc->cliente[indice]
                        .extrato[Lc->cliente[indice].quant_extrato]
                        .texto,
                    "Valor débito:  %.2lf, tarifa: %.2f, saldo: %.2lf ",
                    valorDeb - tarifa, tarifa,
                    Lc->cliente[indice].saldo); // salva textos
            Lc->cliente[indice].quant_extrato =
                Lc->cliente[indice].quant_extrato + 1;

            printf("Débito feito com sucesso!\n");
            return;
          } else {
            printf("Débito recusado, valor excedeu o limite(-1000)\n");
            return;
          }
        } else { // Conta plus
          tarifa = valorDeb * 0.03;
          valorDeb = valorDeb + tarifa;
          int conf = Lc->cliente[indice].saldo - valorDeb;
          if (conf >= -5000) {
            Lc->cliente[indice].saldo = Lc->cliente[indice].saldo - valorDeb;
            sprintf(Lc->cliente[indice]
                        .extrato[Lc->cliente[indice].quant_extrato]
                        .texto,
                    "Valor débito: %.2lf,tarifa: %.2f, saldo: %.2lf ",
                    valorDeb - tarifa, tarifa, Lc->cliente[indice].saldo);
            Lc->cliente[indice].quant_extrato =
                Lc->cliente[indice].quant_extrato + 1;
            printf("Débito feito com sucesso!\n");
            return;
          } else {
            printf("Débito recusado, valor excedeu o limite(-5000)\n");
            return;
          }
        }
      }
    }
  }
  printf("Cpf ou senha incorretos\n");
  return;
}

void deposito(listaClientes *Lc) {
  float novoSaldo_dest = 0;
  float valorDeposito;
  long cpfDest; // digitado pelo usuario
  printf("Digite valor do cpf do destinatário: ");
  scanf("%ld", &cpfDest);
  printf("Digite o valor do depósito: ");
  scanf("%f", &valorDeposito);
  for (int indice = 0; indice < Lc->quantidade; indice++) {
    if (cpfDest == Lc->cliente[indice].cpf) {
      novoSaldo_dest = Lc->cliente[indice].saldo + valorDeposito;
      Lc->cliente[indice].saldo = novoSaldo_dest;
      // adicionando contas do depósito no struct de extrato
      sprintf(
          Lc->cliente[indice].extrato[Lc->cliente[indice].quant_extrato].texto,
          "Valor depósito: %.2lf, saldo: %.2lf ", valorDeposito,
          Lc->cliente[indice].saldo); // salva textos
      Lc->cliente[indice].quant_extrato = Lc->cliente[indice].quant_extrato + 1;
      printf("Deposito feito com sucesso!\n");
      return;
    }
  }
  printf("Cpf não encontrado :(\n");
  return;
}

void extrato(listaClientes Lc, char arquivoExtrato[]) {
  long cpf;  // o que sera digitado pelo usuario
  int senha; // o que sera digitado pelo usuario
  int clienteEncontrado = 0;
  char arquivo[30];
  printf("Digite seu cpf: ");
  scanf("%ld", &cpf);
  printf("Digite sua senha: ");
  scanf("%d", &senha);
  for (int indice = 0; indice < Lc.quantidade;
       indice++) { // Procurando o cliente
    if (cpf == Lc.cliente[indice].cpf) {
      if (senha == Lc.cliente[indice].senha) {
        sprintf(arquivo, "extratoCpf:%ld.txt", cpf);
        FILE *f = fopen(arquivo, "w");
        if (f == NULL) { // vê se valor do ponteiro ta apontando pra NULL
          printf("Falha ao abrir o arquivo");
        }
        // Pegando todos os extratos para colocar no arquivo
        for (int indiceExtrato = 0;
             indiceExtrato < Lc.cliente[indice].quant_extrato;
             indiceExtrato++) {
          fprintf(f, "%s\n", Lc.cliente[indice].extrato[indiceExtrato].texto);
          // printf("%s\n",Lc.cliente[indice].extrato[indiceExtrato].texto);
        }
        fclose(f);
        return;
      }
    }
  }
  printf("Cpf ou senha incorretos\n");
  printf("\n");
  return;
}

void transferencia(listaClientes *Lc) {
  long cpfOri;  // o que sera digitado pelo usuario
  long cpfDest; // digitado pelo usuario
  int senha;    // o que sera digitado pelo usuario
  float valor;
  float novoSaldo_dest = 0;
  float tarifa = 0;
  int valorTotal;
  printf("Digite seu cpf: ");
  scanf("%ld", &cpfOri);
  printf("Digite sua senha: ");
  scanf("%d", &senha);
  printf("Digite o cpf do destinatário: ");
  scanf("%ld", &cpfDest);
  printf("Digite o valor a ser transferido: ");
  scanf("%f", &valor);
  // Procura e verifica o cpf e senha de quem vai transferir
  for (int indice = 0; indice < Lc->quantidade; indice++) {
    if (cpfOri == Lc->cliente[indice].cpf) {
      if (senha == Lc->cliente[indice].senha) {
        // Procura e verifica o cpf e senha de quem vai receber
        for (int indiceDest = 0; indiceDest < Lc->quantidade; indiceDest++) {
          if (cpfDest == Lc->cliente[indiceDest].cpf) {
            if (Lc->cliente[indice].tipoConta == 0) { // conta comum
              tarifa = valor * 0.05;
              valorTotal = valor + tarifa;
              int conf = Lc->cliente[indice].saldo - valorTotal;
              if (conf >= -1000) {
                Lc->cliente[indice].saldo =
                    Lc->cliente[indice].saldo - valorTotal;
                novoSaldo_dest = Lc->cliente[indiceDest].saldo + valor;
                Lc->cliente[indiceDest].saldo = novoSaldo_dest;
                // adicionando contas da transferência, para a pessoa que
                // depositou, no struct de extrato
                sprintf(
                    Lc->cliente[indice]
                        .extrato[Lc->cliente[indice].quant_extrato]
                        .texto,
                    "Valor transferência: %.2lf, tarifa: %.2f saldo: %.2lf ",
                    valor, tarifa, Lc->cliente[indice].saldo); // salva textos
                sprintf(Lc->cliente[indiceDest]
                            .extrato[Lc->cliente[indiceDest].quant_extrato]
                            .texto,
                        "Transferência feita pelo cpf %ld no valor de %.2lf, "
                        "saldo final de %.2lf ",
                        cpfOri, valor, novoSaldo_dest); // salva textos
                Lc->cliente[indice].quant_extrato =
                    Lc->cliente[indice].quant_extrato + 1;
                Lc->cliente[indiceDest].quant_extrato =
                    Lc->cliente[indiceDest].quant_extrato + 1;
                printf("Transferência feita com sucesso! :) \n");
                return;
              } else {
                printf(
                    "Transferência recusada, valor excedeu o limite(-1000)\n");
                return;
              }
            } else { // Conta plus
              tarifa = valor * 0.03;
              valorTotal = valor + tarifa;
              int conf = Lc->cliente[indice].saldo - valorTotal;
              if (conf >= -5000) {
                Lc->cliente[indice].saldo =
                    Lc->cliente[indice].saldo - valorTotal;
                novoSaldo_dest = Lc->cliente[indiceDest].saldo + valor;
                Lc->cliente[indiceDest].saldo = novoSaldo_dest;
                // adicionando contas da transferência, para a pessoa que
                // depositou, no struct de extrato
                sprintf(Lc->cliente[indice]
                            .extrato[Lc->cliente[indice].quant_extrato]
                            .texto,
                        "Valor transferência: %.2lf,tarifa: %.2f saldo: %.2lf ",
                        valor, tarifa,
                        Lc->cliente[indice].saldo); // salva textos
                sprintf(Lc->cliente[indiceDest]
                            .extrato[Lc->cliente[indiceDest].quant_extrato]
                            .texto,
                        "Transferência feita pelo cpf %ld no valor de %.2lf, "
                        "saldo final de %.2lf ",
                        cpfOri, valor, novoSaldo_dest); // salva textos
                Lc->cliente[indice].quant_extrato =
                    Lc->cliente[indice].quant_extrato + 1;
                Lc->cliente[indiceDest].quant_extrato =
                    Lc->cliente[indiceDest].quant_extrato + 1;
                printf("Transferência feita com sucesso!\n");
                return;
              } else {
                printf(
                    "Transferência recusado, valor excedeu o limite(-5000)\n");
                return;
              }
            }
          }
        }
        printf("Transferência recusada, cpf do destinatário não encontrado\n");
        return;
      }
    }
  }
  printf("Cpf ou senha incorretos\n");
  return;
}

int salva_clientes(listaClientes Lc, char nomeArquivo[]) {
  FILE *f = fopen(nomeArquivo, "wb");
  if (f == NULL) { // vê se valor do ponteiro ta apontando pra NULL
    printf("Falha ao abrir o arquivo");
    return 1;
  }
  fwrite(&Lc, sizeof(listaClientes), 1, f);
  fclose(f);
  return 0;
}

int ler(listaClientes *Lc, char nomeArquivo[]) {
  FILE *f = fopen(nomeArquivo, "rb");
  if (f == NULL) {
    printf("Falha ao abrir o arquivo");
    return 1;
  }
  fread(Lc, sizeof(listaClientes), 1,
        f); // 1 pq é 1 struct (se fosse o tarefa seria 100 em quantidade)
  fclose(f);
  return 0;
}
