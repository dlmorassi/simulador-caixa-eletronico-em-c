#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>

//declaração saldo do usuário
float saldo = 306.44;

//bloco de código do menu
void Menu(){
    int opcao;
    do{
        system("cls");//limpa o console
		system("color DF");//muda cor de fundo e da letra
    	system("date /t");//exibe data relacionada ao computador
    	system("time /t");//exibe hora
		printf("------------------MENU------------------\n");
		printf("SALDO ATUAL: R$ %.2f \n\ndigite a funcao desejada: \n0 para ver rendimento na poupanca \n1 para saque \n2 para deposito \n3 para sair \n", saldo);
        printf("----------------------------------------\n");
        scanf("%d", &opcao);
        
        switch(opcao){
        	//redireciona para o rendimento
        	case 0:
        		Rendimento();
        		break;
        	//redireciona para o saque
            case 1:
            	Saque();
                break;
            //redireciona para o deposito
            case 2:
            	Deposito();
                break;
            //redireciona para a saída
			case 3:
				break;
			//opção inválida
		    default:
                printf("opcao invalida");
                for(int i=0; i<3; i++){
                	printf(".");
                	Sleep(500);
				}
				break;
        }
    }while(opcao != 3);
    printf("obrigado, volte sempre!");//encerramento do programa
}

//menu inicial de cadastro e login, em breve melhorado
int main() {
	char cadastro[50], usuario[50];
    int senha1, senha2;
    //menu de cadastro
    system("date /t"), system("time/t");
    system("color DF");
    printf("\n--------------CADASTRO--------------\n\n");
    printf("digite um nome de usuario: ");
    scanf("%s", cadastro);
    printf("digite uma senha numerica: ");
    scanf("%d", &senha1);
    printf("\ncadastro realizado com sucesso! \n");
    printf("\n------------------------------------\n");
	Sleep(1000);
	//menu de login
    system("cls");
    system("color DF");
    system("date /t"), system("time/t");
	printf("\n--------------LOGIN---------------");
	printf("\ndigite seu usuario: \n");
    scanf("%s", usuario);
    printf("digite sua senha: \n");
    scanf("%d", &senha2);
    //caso usuario ou senha estejam errados
    while(strcmp(cadastro, usuario) != 0 || senha1 != senha2){
        printf("usuario ou senha incorretos.\ndigite o usuario:\n");
        scanf("%s", usuario);
        printf("digite sua senha \n");
        scanf("%d", &senha2);
    }
    //caso usuario e senha estejam corretos
    if(strcmp(cadastro, usuario) == 0 && senha1 == senha2){
        printf("bem-vindo %s! inicializando sistema", usuario);
        for(int i=0; i<3; i++){
        	printf(".");
        	Sleep(500);
		}
        Sleep(500);
        Menu();//redireciona para menu principal
    }

    return 0;
}

//menu de saque
void Saque(){
	float saque;
	printf("quanto deseja sacar? \nR$ ");
    scanf("%f", &saque);
	if(saque > saldo){
		printf("saldo inuficiente, digite novamente: \nR$ ");
        scanf("%f", &saque);
    }
    if(saque <= saldo){
        saldo = saldo - saque;
		printf("saque realizado! imprimindo %.2f reais", saque);
		for(int i=0; i<3; i++){
			printf(".");
			Sleep(500);
		}
    }
    Sleep(1000);
}

//menu de deposito
void Deposito(){
    float deposito;
	printf("quanto deseja depositar? \nR$ ");
    scanf("%f", &deposito);
    saldo = saldo + deposito;
    printf("\n%.2f reais sendo depositados", deposito);
    for(int i=0; i<3; i++){
		printf(".");
		Sleep(500);
    }
	Sleep(1000);
}

//menu de rendimento
void Rendimento(){
	float quantia, rendimento, tempo;
    printf("qual seria a quantia investida?  R$ ");
    scanf("%f", &quantia);
    printf("por quantos meses gostaria de deixar rendendo?  ");
    scanf("%f", &tempo);
    rendimento = quantia * (1 + (0.05 * tempo));
    printf("seu dinheiro ao final do periodo de investimento seria:  R$ %.2f", rendimento);
    Sleep(2000);
	
}
