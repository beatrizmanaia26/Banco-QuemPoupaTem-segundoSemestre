# Banco-QuemPoupaTem-segundoSemestre
My friend @LuaBortko and I created, in the second period of college.
Here are how you can run the code:
Ao rodar o código do repositório “Banco-QuemPoupaTem-segundoSemestre” aparecerá 8 opções:  
![image](https://github.com/beatrizmanaia26/Banco-QuemPoupaTem-segundoSemestre/assets/130764598/0098d31f-adf2-4fb0-a16f-9c70ba82c92f)
A primeira (1. Novo Cliente) cria um novo cliente com base nas informações pedidas ao usuário (nome, CPF, tipo de conta, valor inicial e senha). Todavia, o código só roda se, em “tipo de conta”, o usuário digitar “comum” ou “plus”, com letra minúscula e se o CPF digitado não estiver cadastrado.
![image](https://github.com/beatrizmanaia26/Banco-QuemPoupaTem-segundoSemestre/assets/130764598/88d91848-1696-48a0-aeb7-fcc19873e7bc)
A segunda (2. Apaga Cliente) apaga um cliente após o usuário informar o CPF do cliente que deseja apagar. 
A terceira (3. Listar clientes) lista todas as informações dos clientes cadastrados menos a senha, e se o valor é modificado (por meio de depósito, débito ou transferência) aparece o valor após a modificação. 
![image](https://github.com/beatrizmanaia26/Banco-QuemPoupaTem-segundoSemestre/assets/130764598/2176661b-6667-44f6-9456-44424b906700)
A quarta (4. Débito) o usuário informa o CPF, senha e o valor que deseja retirar da conta. 
![image](https://github.com/beatrizmanaia26/Banco-QuemPoupaTem-segundoSemestre/assets/130764598/5c1f97a4-d4e5-4983-b44a-91d1f0aeb31d)
A quinta (5. Depósito) pede ao usuário o CPF e o valor a ser depositado. 
![image](https://github.com/beatrizmanaia26/Banco-QuemPoupaTem-segundoSemestre/assets/130764598/268c91ac-bb46-4ef1-a513-868774131b3b)
A sexta (6. Extrato) pede ao usuário o CPF e a senha do cliente que deseja ver o extrato e aparece a movimentação monetária que foi realizada em um arquivo txt chamado “arquivoExtrato.txt”, além da tarifa e do saldo. Nesse exemplo criamos o cliente: 
![image](https://github.com/beatrizmanaia26/Banco-QuemPoupaTem-segundoSemestre/assets/130764598/c5bafa8c-7ac5-4ce0-a933-6c66a8e9d25b)
A sétima (7. Transferência entre contas) é necessário que já existam no mínimo duas contas e, para a transferência, é preciso colocar corretamente o CPF e senha da conta que doará o dinheiro e o CPF correto da conta que receberá o dinheiro, e o valor a ser transferido, caso isso ocorra, aparecerá dessa forma:  
![image](https://github.com/beatrizmanaia26/Banco-QuemPoupaTem-segundoSemestre/assets/130764598/1af3e56f-c676-452f-a14f-86c1a613584d)
Assim, para ver como as contas ficaram após essa transferência é só listar clientes ou ver o extrato delas.  
A nona (0. Sair) faz com que o loop de perguntar qual opção o usuário quer (1. Novo Cliente, 2. Apagar Cliente....) encerre. As informações são salvas no arquivo binário “clientes” sempre que o cliente realiza qualquer ação no nosso banco. 
![image](https://github.com/beatrizmanaia26/Banco-QuemPoupaTem-segundoSemestre/assets/130764598/50595e4e-92cb-413e-b310-d045190fb594)
