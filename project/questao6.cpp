#include <iostream>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "recursividade.h"
using namespace std;

int main()
{
	int opt=0;
	
	
	while(opt!=6){
	cout<<"\n\n|----- ESCOLHA UMA DAS OPCOES NO MENU -----|\n1- Formas de Compra\n2- Restaurente Self Service\n3- Loja de camisas\n4- Calculo da Altura\n5- Pagamento no Caixa\n6- Sair do Programa\n";
	cin>>opt;

		switch(opt){
			case 1:{
				payment();
			}break;
			
			case 2:{
				restauranteSelfService();
			}break;
			
			case 3:{
			   	lojasDeCamisas();
			}break;
			
			case 4:{
				calculoDaAltura();
		   	}break;
			case 5:{
				pagamentoCaixa();
		   	}break;
		   	case 6:{
				cout<<"FINALIZANDO O PROGRAMA!!!";
		   	}break;
			default:{
				cout<<"OPCAO NAO ENCONTRADA. POR FAVOR ESCOLHA UMA DAS OPCOES DO MENU";
			}break;
		}
	}
	return 0; 
}