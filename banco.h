typedef struct{
  float valor;
  char texto[20]; //palavra pequena
}operacao;

typedef struct{
  operacao extrato[100];
  char cpf[11];//número grande
  float saldo;
  int tipoConta;
  char nome[300];
  char senha[10]; //limite do tamanho da senha
}cliente;

typedef struct{
  cliente cliente[1000];
  int quantidade;
}listaClientes;

typedef enum{COMUM, PLUS} tipoConta; //comparação com enum é mais fácil  COMUM = 0, PLUS = 1
typedef enum{err_cria,err_del,err_tipo,err_valor,err_saldo_comum}erros;
void menu();

void criaCliente(listaClientes *Lt);
int deletarCliente(listaClientes *Lt);
void listaCliente(listaClientes Lt);

void clearBuffer();

//Tudo deve ser armazenado em arquivo binario, e o extrato tem que gerar um txt com todas as informações(data, tarifa,valor adicionado ou removido da conta, e saldo final)
