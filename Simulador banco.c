#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>

void menu(){
    float saldo = 194.57, saque, deposito, quantia, rendimento, tempo;
    int opcao;
    char continuidade
	;
    do{
        system("cls");
		system("color DF");
    	system("date /t"), system("time/t");
		printf("\n	          MENU\n");
		printf("---------------------------------------\n");
		printf("SALDO ATUAL: R$ %.2f \ndigite a funcao desejada: \n0 para ver rendimento na poupanca \n1 para saque \n2 para deposito \n3 para sair \n", saldo);
        printf("---------------------------------------\n");
        scanf("%d", &opcao);
        
        switch(opcao){
        	case 0:
        		printf("qual seria a quantia investida?  R$ ");
        		scanf("%f", &quantia);
        		printf("por quantos meses gostaria de deixar rendendo?  ");
        		scanf("%f", &tempo);
        		rendimento = quantia * (1 + (0.05 * tempo));
        		printf("seu dinheiro ao final do periodo de investimento seria:  R$ %.2f", rendimento);
        		Sleep(2000);
        		break;
            case 1:
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
                break;
            case 2:
                printf("quanto deseja depositar? \nR$ ");
                scanf("%f", &deposito);
                saldo = saldo + deposito;
                printf("\n%.2f reais sendo depositados", deposito);
                for(int i=0; i<3; i++){
						printf(".");
						Sleep(500);
                }
                Sleep(1000);
                break;
			case 3:
				break;
		    default:
                printf("opcao invalida");
                for(int i=0; i<3; i++){
                	printf(".");
                	Sleep(500);
				}
				break;
        }
    }while(opcao != 3);
    printf("obrigado, volte sempre!");
}

int main() {
	char cadastro[50], usuario[50];
    int senha1, senha2;
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
    system("cls");
    system("color DF");
    system("date /t"), system("time/t");
	printf("\n--------------LOGIN---------------");
	printf("\ndigite seu usuario: \n");
    scanf("%s", usuario);
    printf("digite sua senha: \n");
    scanf("%d", &senha2);
    while(strcmp(cadastro, usuario) != 0 || senha1 != senha2){
        printf("usuario ou senha incorretos.\ndigite o usuario:\n");
        scanf("%s", usuario);
        printf("digite sua senha \n");
        scanf("%d", &senha2);
    }
    if(strcmp(cadastro, usuario) == 0 && senha1 == senha2){
        printf("bem-vindo %s! inicializando sistema", usuario);
        for(int i=0; i<3; i++){
        	printf(".");
        	Sleep(500);
		}
        Sleep(500);
        menu();
    }

    return 0;
}
