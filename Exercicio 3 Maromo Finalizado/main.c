#include <stdio.h>


struct Cliente {
    char nome[256];
    double cpf;
};

struct Conta{
    int numeroconta;
    struct Cliente;
    double saldo;
    int operacao;

};

struct Transacao {
    int numeroconta;
    int operacao;
    double valor;
    double saldo;
};

int main(){
    struct Conta result[10];
    double cpf;
    int numeroconta;
    double saldo;
    char nome[256];
    int linha = 0;
    double valorinicial;
    struct Transacao vettransacao[50];

    printf("Campos: CPF, Nome do Usuario, Deposito Inicial\n");
    printf("\nDados para abertura da conta\n");
    printf("Digite seu CPF, somente numeros:\n");
    scanf(" %lf", &cpf);
    printf("Digite seu Nome Completo:\n");
    fflush(stdin);
    gets(nome);
    printf("Digite um numero para sua conta:\n");
    scanf(" %d", &numeroconta);
    printf("Qual seu deposito inicial:\n");
    scanf("%lf", &valorinicial);
    saldo = valorinicial;

    printf("\nNumero da conta: %d \nCliente: %s \nSaldo inicial: %.2lf\n", numeroconta,nome, saldo);

    int operacao;
    long num_conta;
    double valor;
    int i = 0;
    int tr[4];

    while (operacao != 4){

    printf("\nInforme a operacao desejada:\n 1 - Saque\n 2 - Deposito\n 3 - Mostrar Saldo\n 4 - Sair:\n");
    scanf("%d", &operacao);

    switch( operacao )
    {
    case 1:
    system("cls");
    printf("Operacao Saque\n");
    printf("Informe o Valor:\n");
    scanf(" %lf", &valor);
        if(saldo >= valor){
    printf("\n Operacao aceita\n", valor);
    saldo = saldo - valor;
    vettransacao[linha].numeroconta = numeroconta;
    vettransacao[linha].operacao = operacao;
    vettransacao[linha].valor = valor;
    vettransacao[linha].saldo = saldo;
    linha++;
    printf("Saldo atual: %.2lf\n", saldo);
    }
        else{
    printf("Operacao Invalida\n");
    }

        break;
    case 2:
    system("cls");
    printf("Operacao Deposito\n");
    printf("Informe o Valor:\n");
    scanf(" %lf", &valor);
        if(valor >0){
    printf("\nOperacao aceita\n", valor);
    saldo = saldo + valor;
    vettransacao[linha].numeroconta = numeroconta;
    vettransacao[linha].operacao = operacao;
    vettransacao[linha].valor = valor;
    vettransacao[linha].saldo = saldo;
    linha++;
    printf("Saldo atual: %.2lf\n", saldo);
        }
        else{
    printf("Operacao Invalida\n");
        break;

    case 3:
    system("cls");
    printf("Operacao Mostrar saldo\n");
    printf("Saldo atual: %.2lf\n", saldo);
        break;

    case 4:
    system("cls");
    printf("Obrigado e volte sempre\n");
        break;

    }


    }
}

    getch();
    system("cls");
    printf(" Arquivo gerado com sucesso\n");
    printf(" Verifique a pasta do projeto\n");

    FILE *resultado;
    resultado = fopen("Resultado.txt", "a");
    fprintf(resultado,"Nome do Cliente: %s\n", nome);
    fprintf(resultado,"Numero do CPF: %.lf\n", cpf);
    fprintf(resultado,"Numero da conta: %d\n", numeroconta);
    fprintf(resultado,"Valor Inicial da Conta: R$ %.2lf\n\n", valorinicial);
    fprintf(resultado,"Operacao 1 = Saque -- Operacao 2 = Deposito\n\n");

    for(i=0;i<linha;i++){
        fprintf(resultado,"Transacao Numero :%d\n R$ %.2lf\n Operacao: %d\n Saldo Atual: R$ %.2lf\n\n",i+1, vettransacao[i].valor, vettransacao[i].operacao, vettransacao[i].saldo);
    }



    fclose(resultado);

    system("pause");
    return 0;
}

