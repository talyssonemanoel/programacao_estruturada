#include <iostream>
#include <math.h>
using namespace std;

//Questão 2 da lista de execícios da disciplina Programação estruturada
//Docente: Lima Junior
//Desenvolvido por Talysson Emanoel Medeiros da Costa

typedef struct product //estrutura para estabelecer o tipo de produto
{
	int cod;
	float price;
	int quantity;
}product;

product produto[4]; //Declarando um vetor de 4 item, do tipo produto, de forma global

void insertProduct()
{
	cout << fixed;
	cout.precision(2); //FUNCAO PARA DETERMINAR A PRECISAO DE CASA DECIMAL APÓS A VÍGULA QUE SERÁ EXIBIDA
	int code;
	int quant;
	cout<<"INSIRA O CODIGO DO PRODUTO: ";
	cin>>code;
	for (int i=0; i<4; i++)
	{
		if (code==produto[i].cod)
		{
			cout<<"PRECO DO PRODUTO: R$ "<<produto[i].price<<"\nQUANTIDADE: ";
			cin>>quant;
			produto[i].quantity=produto[i].quantity+quant;
			break;
		}
  		if (i==3)
		{
			cout<<"PRODUTO NAO ENCONTRADO, INSIRA UM CODIDO VALIDO\n\n";
		}
	}
}

void finalize() //Função criada para finalizar a compra e mostrar a lista final
{
	float total=0;
	cout << fixed;
	cout.precision(2); //FUNCAO PARA DETERMINAR A PRECISAO DE CASA DECIMAL APÓS A VÍGULA QUE SERÁ EXIBIDA
	cout<<"\n\n-------- RESUMO DA COMPRA --------\n\n";
	for (int i=0; i<4; i++)
	{
		if (produto[i].quantity>0)
		{
			cout<<"CODIGO DO PRODUTO: "<<produto[i].cod<<"\nVALOR DA UNIDADE: R$ "<<produto[i].price<<"\nQUANTIDADE: "<<produto[i].quantity;
			cout.precision(1); /*ANTERANDO A PRECISÃO PARA 1, POIS QUEREMOS A PRECISÃO DE 1 CASA DECIMAL 
									APÓS A VÍRGULA, ASSIM COMO DETERMINA A QUESTÃO DA LISTA*/
			cout<<" (R$ "<<produto[i].price*produto[i].quantity<<")\n\n";
			total=total+(produto[i].price*produto[i].quantity);
		}
	}
	cout.precision(1);
	cout<<"TOTAL A PAGAR: R$ "<<total<<"\n\n";
}

void removeProduct() //Função criada para remover produto
{
	int code;
	int quant;
	cout<<"\n-------- REMOVER PRODUTO --------\n\n";
	cout<<"INSIRA O CODIGO DO PRODUTO: ";
	cin>>code;
	for (int i=0; i<4; i++)
	{
		if (code==produto[i].cod && produto[i].quantity>0)
		{
			cout<<"CODIGO DO PRODUTO: "<<produto[i].cod<<"\nPRECO DO PRODUTO: R$ "<<produto[i].price<<"\nQUANTIDADE: "<<produto[i].quantity<<"\n\nQUANTIDADE A SER REMOVIDA: ";
			cin>>quant;
			produto[i].quantity=produto[i].quantity-quant;
 		   				 
			if (produto[i].quantity<0)
			{
				produto[i].quantity=0;
			}
			break;
		}
		if (i==3)
		{
			cout<<"PRODUTO NAO ENCONTRADO NA LISTA DE COMPRAS\n\n";
		}
	}
}

void pagamentoCaixa()
{
	cout << fixed;
	cout.precision(2); //FUNCAO PARA DETERMINAR A PRECISAO DE CASA DECIMAL APÓS A VÍGULA QUE SERÁ EXIBIDA
	int opt;
	//Setando os valores de cada código de item
	produto[0].cod=100;
	produto[0].price=2.20;
	produto[0].quantity=0;
	produto[1].cod=101;
	produto[1].price=1.52;
	produto[1].quantity=0;
	produto[2].cod=200;
	produto[2].price=5.00;
	produto[2].quantity=0;
	produto[3].cod=201;
	produto[3].price=0.57;
	produto[3].quantity=0;
	
	while (opt!=4)
	{
		cout<<"-------- CAIXA ELETRONICO --------\n1- ADICIONAR PRODUTO\n2- FINALIZAR COMPRA\n3- REMOVER PRODUTO\n4- CANCELAR TODA A COMPRA\n";
		cin>>opt;
		switch(opt)
		{
			case 1:
			{
				insertProduct(); //Chamando a função para inserir produto na lista de compras
			}break;
			
			case 2:
			{	
				finalize();//Chamando a função de finalizar a compra e mostrar a lista final
				opt=4; //Caso finalize a compra, o opt retornará 4 para sair do programa
			}break;

			case 3:
			{
				removeProduct();//Chamando a função para remover produtos, caso necessário
			}break;

			default:
			{
				cout<<"OPCAO NAO ENCONTRADA, POR FAVOR ESCOLHER UMA DAS OPCOES DO MENU";
		   	}break;
		}
	}
}

int main()
{
	pagamentoCaixa();
	return 0;
}