
  #include <stdio.h>
#include "banco.h"

int main(void) {
  char arquivo[]= "tarefa";
  listaClientes Lt;
  int opcao;
  do{
    menu();
    printf("Digite o número de sua escolha: ");
    scanf("%d",&opcao);
    switch(opcao){
      case 1 :
        criaCliente(&Lt);
        break;
      case 2 :
        deletarCliente(&Lt);
        break;
      case 3 :
        listaCliente(Lt);
        break;
      case 4 :
        debito(&Lt);
        break;
      case 5 :
        deposito(&Lt);
        break;
    }
    
  }while(opcao != 0);
  
  
  return 0;
}


// from datetime import datetime
//
// arquivo_banco = open("banco.txt", "a")

// def novocliente(salva):#1.
//     listaadiciona=[]
//     extrato=[]
//     razaosoc = input("Razão Social: ")
//     cnpj = input("CNPJ: ")
//     tipoconta = input("Tipo de conta: ")  
//     if (tipoconta=="comum") or (tipoconta=="plus"):
//         vinicial = float(input("Valor inicial da conta: "))
//         senhausuario = input("Senha: ")
//         listaadiciona.append(razaosoc) #0
//         listaadiciona.append(cnpj) #1
//         listaadiciona.append(tipoconta) #2
//         listaadiciona.append(vinicial) #3
//         listaadiciona.append(senhausuario) #4
//         listaadiciona.append(extrato) #5  (adiciona nessa lista tudo que vai ser printado no extrado)

//         salva.append(listaadiciona)
//     else:
//         print("Tipo de conta inválido")
//         return
   
// def apagacliente():#2.
//     cnpj = input("CNPJ: ")
//     indice=0
//     for x in range(len(salva)):
//         if salva[x][1] == cnpj:
//             indice=x
//             break
//     salva.pop(indice)


// def listarclientes(clientes):#3. #clientes é um parametro criado só para essa funcao
//     for x in range (len(clientes)):
//         print()
//         print("Razão Social: ", clientes[x][0])
//         print("CNPJ: ",clientes[x][1])
//         print("Tipo de conta: ",clientes[x][2])
//         print("Valor: ",clientes[x][3])
//         print()


// def debito(salva):#4.
//     cnpj = input("CNPJ: ")
//     senha = input("Senha: ")
//     valordeb = float(input("Valor a ser debitado: "))
//     for clientedeb in salva:
//         if (clientedeb[1]==cnpj) and (clientedeb[4]==senha): #3  
//             if clientedeb[2]=="plus":
//                 tarifa=valordeb*0.03
//                 valordeb= valordeb*0.03 + valordeb
//                 efetuadodeb= clientedeb[3] - valordeb
//                 if efetuadodeb<=-5000.00:
//                     print("Não é permitido retirar mais dinheiro, saldo atingiu -5000")
//                     break
//                 else:
//                     resultadodeb=efetuadodeb
//                     mensagem = "Data: "+ str(tempo)
//                     mensagem = mensagem + " - " + str(valordeb)
//                     mensagem = mensagem + " Tarifa: " + str(tarifa)
//                     mensagem = mensagem + " Saldo: " + str(efetuadodeb)
                   
//                 clientedeb[5].append(mensagem)
                               
                       
//             if clientedeb[2]=="comum":
//                 tarifa=valordeb*0.05
//                 valordeb= valordeb*0.05 + valordeb
//                 efetuadodeb= clientedeb[3] - valordeb
//                 if efetuadodeb<=-1000.00:
//                     print("Não é permitido retirar mais dinheiro, saldo atingiu -1000")
//                     break
//                 else:
//                     resultadodeb=efetuadodeb
//                     mensagem = "Data: "+ str(tempo)
//                     mensagem = mensagem + " - " + str(valordeb)
//                     mensagem = mensagem + " Tarifa: " + str(tarifa)
//                     mensagem = mensagem + " Saldo: " + str(efetuadodeb)
               
//                 clientedeb[5].append(mensagem)
                     
//             clientedeb[3]=resultadodeb
//             return 
   
//     print("O cnpj ou a senha está errado!")
           
   
// def deposito(salva):#5.
//     cnpj = input("CNPJ: ")
//     valordep = int(input("Valor: "))
//     for clientedep in salva:
//         if clientedep[1]==cnpj:
//             efetuadodep = clientedep[3] + valordep
//             clientedep[3]=efetuadodep
           
//             mensagem = "Data: "+ str(tempo)
//             mensagem = mensagem + " + " + str(valordep)
//             mensagem = mensagem + " Tarifa: " + str(0.00)
//             mensagem = mensagem + " Saldo: " + str(efetuadodep)
               
//             clientedep[5].append(mensagem)
//             return   #return para a funcao
//     print("Cnpj não encontrado!")    
             
           
// def extrato(salva):#6 ('printa' data, hora,tarifa,saldo, valor debitado, valor depositado)
//     extrato=[]
//     cnpj = input("CNPJ: ")
//     senha = input("Senha: ")
//     for cliente in salva:
//         if (cliente[1]==cnpj) and (cliente[4]==senha):
//             for mensagem in cliente[5] :
//                 print(mensagem)
                           

// def transferencia(salva):#7.
//     cnpjori = input("CNPJ: ")
//     senha = input("Senha: ")
//     cnpjdest = input("CNPJ do Destinatário: ")
//     valor = int(input("Valor: "))#primeiro somamos o valor na conta do destinatario(cnpjdest)
//     indiceorig = None #assume que nao existe)
//     indicedest = None 
   
//     for indice in range(len(salva)):
       
//         if (salva[indice][1] == cnpjori):
//             indiceorig = indice
           
//         if (salva[indice][1] == cnpjdest):
//             indicedest = indice
//     if (indiceorig == None or indicedest == None):
//         print("Algum cnpj colocado não existe")
   
//     else:
                   
//         for clienteorig in salva:#b é qualquer outro indice da lista salva
           
//             if (clienteorig[1]==cnpjori) and (clienteorig[4]==senha):
               
//                 if clienteorig[2]=="plus":
//                     tarifa = valor*0.03
//                     limite = -5000.00
//                 elif clienteorig[2]=="comum":
//                     tarifa = valor*0.05
//                     limite = -1000.00
                   
//                 valor = tarifa + valor
//                 efetuadoori= clienteorig[3] - valor
//                 if efetuadoori<=limite:
//                     print("Não é permitido retirar mais dinheiro, saldo atingiu %d" %limite)
//                     break
//                 else:
                   
//                     resultadoori=efetuadoori
   
//                     mensagem = "Data: "+ str(tempo)
//                     mensagem = mensagem + " - " + str(valor)
//                     mensagem = mensagem + " Tarifa: " + str(0.00)
//                     mensagem = mensagem + " Saldo: " + str(efetuadoori)
               
//                     clienteorig[5].append(mensagem) #5 é extrato
//                     clienteorig[3]=resultadoori
               
//         for clientedest in salva:
//             if clientedest[1]==cnpjdest:
       
//                 efetuadodest= clientedest[3] + valor
//                 clientedest[3]=efetuadodest
//                 mensagem = "Data: "+ str(tempo)
//                 mensagem = mensagem + " + " + str(valor)
//                 mensagem = mensagem + " Tarifa: " + str(0.00)
//                 mensagem = mensagem + " Saldo: " + str(efetuadodest)
               
//                 clientedest[5].append(mensagem) #5 é extrato
//                 return 
           
//         print("O cnpj ou a senha está errado!")
               
           
// while True:
//     numero = menu()
//     if numero==1:
//        novocliente(salva)

//     elif numero==2:
//         apagacliente()

//     elif numero==3:
//         listarclientes(salva)

//     elif numero==4:
//         debito(salva)

//     elif numero==5:
//         deposito(salva)

//     elif numero==6:
//         extrato(salva)

//     elif numero==7:
//         transferencia(salva)
     
//     elif numero==8:
//         cadastroclientes()

//     elif numero==9:
//         salvar() #Só salva se sair do programa
//         print("Até mais!")
//         break