typedef struct{
  char texto[100];//string para todas as palavras (conta, tarifa e saldo)
}operacao;

//Colocar quant de extrato dentro de cliente
typedef struct{
  operacao extrato[100]; //informações das ultimas 100 operações
  int quant_extrato;
  long cpf;//número grande
  float saldo;
  int tipoConta;
  char nome[20];
  int senha; 
}cliente;

typedef struct{
  cliente cliente[1000]; //diminuimos para 10 nos testes pois o replit não tem memória o suficiente para rodar com o tamanho pedido(1000)
  int quantidade;
}listaClientes;

typedef enum{COMUM, PLUS} tipoConta; //comparação com enum é mais fácil  COMUM = 0, PLUS = 1

void menu();

void criaCliente(listaClientes *Lc);
void deletarCliente(listaClientes *Lc);
void listaCliente(listaClientes Lc);
void debito(listaClientes *Lc);
void deposito(listaClientes *Lc);
void transferencia(listaClientes *Lc);
void extrato(listaClientes Lc, char arquivoExtrato[]); 
int salva_clientes(listaClientes Lc, char nomeArquivo[]);
int ler(listaClientes *Lc, char nomeArquivo[]);

void clearBuffer();


