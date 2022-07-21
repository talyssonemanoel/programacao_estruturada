#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

//Questão 2 da lista de execícios da disciplina Programação estruturada
//Docente: Lima Junior
//Desenvolvido por Talysson Emanoel Medeiros da Costa

typedef struct item
{
	string name;
	float price;
}item;


//Função para pagamento à Vista
void aVista(item x)
{
	float updatedprice;
	float discount;
	discount=x.price/10;
	updatedprice=x.price-discount;
			   	
	cout<<"Valor do item: R$ "<<x.price<<"\nQuantidade de parcelas: A vista\nDesconto aplicado: R$ -"<<discount<<" (10%)\nJuros aplicado: R$ 0,00\nValor total: R$ "<<updatedprice<<"\n\n";
}

void parcelado1e2X(item x)
{
	float portion[3];
			
	portion[0]=((x.price-fmod(x.price, 3))/3)+(fmod(x.price,3));
	portion[1]=(x.price-fmod(x.price, 3))/3;
	portion[2]=(x.price-fmod(x.price, 3))/3;
					
	cout<<"Valor do item: R$ "<<x.price<<"\nQuantidade de parcelas: 3\n";
	for(int i=0; i<3; i++)
	{
		cout<<"Valor da parcela "<<i+1<<": R$ "<<portion[i]<<"\n";
	}
	cout<<"Desconto do aplicado: R$ 0,00\nJurosaplicado: R$ 0,00\nValor total: RS"<<x.price<<"\n\n";
				
}

void parceladoEm10X(item x)
{
	float fees;
	fees=x.price*0.05;
	float updatedprice=x.price+fees;
	float portion[10];
			
	portion[0]=((updatedprice-fmod(updatedprice, 10))/10)+(fmod(updatedprice,10));
	for (int i=1; i<10; i++)
	{
		portion[i]=(updatedprice-fmod(updatedprice, 10))/10;
	}
	cout<<"Valor do item: R$ "<<x.price<<"\nQuantidade de parcelas: 10\n";
	for(int i=0; i<10; i++)
	{
		cout<<"Valor da parcela "<<i+1<<": R$ "<<portion[i]<<"\n";
	}
	cout<<"Desconto do aplicado: R$ 0,00\nJuros do aplicado: "<<fees<<"\nValor total: RS"<<updatedprice<<"\n\n";
			
}


void payment()
{
	int opt;
	cout << fixed;
	cout.precision(2);
	item bolsa;
	bolsa.name="ADIDAS ORGANIZE";
	bolsa.price=159.99;
	
	cout<<"CARRINHO\nItem: "<<bolsa.name<<"\nPreco: R$ "<<bolsa.price<<"\n\n";
	
	cout<<"Escolha a opcao de pagamento\n1- A vista com 10% de desconto\n2- Parcelado em 1+2 vezes sem desconto\n3- Dividido em 10 vezes com juros de 5% sobre o valor total\n4- Desistir da compra\n";
	cin>>opt;
	
	while(opt!=4)
	{
		cout<<"\n---|CONFIRMACAO DO PAGAMENTO|---\n";
	   	switch(opt)
		{
			case 1:
			{
				aVista(bolsa); //Chamando a função de pagamento a vista
		   	}break;
			case 2:
			{
				parcelado1e2X(bolsa); //Chamando a função de pagamento em 1 + 2x
			}break;
		
			case 3:
			{
				parceladoEm10X(bolsa); //Chamando a função de pagamento em 10x com juros
			}break;
			
			default:
			{
			   	cout<<"Opcao invalida";
		   	}break;
		}
	break;
	}
}

void restauranteSelfService() // Função para calcular o valor proporcional ao peso do alimento
{
	cout<<"Informe o valor em quilos (Kg) do seu pedido: \n";
	float price=23.00;
	float x;
	cout << fixed;
	cout.precision(2);
	
	cin>>x;
	
	cout<<"Valor total a pagar: R$ "<<x*price<<"\n\n";
}

//Definindo a struct do tipo camisa, que terá um tipo de tamanho, valor custo e valor de venda.
typedef struct camisa
{
	char tamanho;
	float valorcusto;
	float valorvenda;
	float quantvendas;
}camisa;


void lojasDeCamisas()
{
	//setando o valor de custo de cada tamanho das camisas
	float custos=0;
	float lucros=0;
	camisa camisas[3];
	camisas[0].tamanho='P';
	camisas[0].valorcusto=15.80;
	camisas[1].tamanho='M';
	camisas[1].valorcusto=16.00;
	camisas[2].tamanho='G';
	camisas[2].valorcusto=16.20;
	
	//Solicitando ao usuario o valor de venda de cada camisa de acordo com seu tamanho e valor de custo
	for (int i=0; i<3; i++)
	{
		cout<<"CAMISA "<<camisas[i].tamanho<<"\nVALOR DE CUSTO: R$ "<<camisas[i].valorcusto<<"\nVALOR DE VENDA: R$ ";
		cin>>camisas[i].valorvenda;
	}
	for(int i=0; i<3; i++)
	{
		cout<<"\nINFORME QUANTAS UNIDADES DE CAMISAS DO TAMANHO "<<camisas[i].tamanho<<" FORAM VENDIDAS NO MES\n";
		cin>>camisas[i].quantvendas;
		custos=custos+(camisas[i].valorcusto*camisas[i].quantvendas);
		lucros=lucros+(((camisas[i].valorvenda*camisas[i].quantvendas))-((camisas[i].valorcusto*camisas[i].quantvendas)));
	}

	cout<<"---------- RESUMO DE VENDA DO MES ----------\nVALOR FINAL DO CUSTO DO MES: R$ "<<custos<<"\nVALOR FINAL DO LUCRO DO MES: R$ "<<lucros;
}

void calculoDaAltura()//Declarando função para calcular o tamanho do predio
{
	float alturaPessoa, alturaPredio, comprimentoSombraPredio, comprimentoSombraPessoa;
	cout << fixed;
	cout.precision(1);
	
	cout<<"\n\n[========== CALCULO DE ALTURA ==========]\n\nINFORME A SUA ALTURA: ";
	cin>>alturaPessoa;
	cout<<"INFORME O COMPRIMENTO DA SUA SOMBRA: ";
	cin>>comprimentoSombraPessoa;
	cout<<"INFORME O COMPRIMENTO DA SOMBRA DO PREDIO: ";
	cin>>comprimentoSombraPredio;
	
	alturaPredio=(alturaPessoa*comprimentoSombraPredio)/comprimentoSombraPessoa;
	
	cout<<"A ALTURA DO PREDIO E: "<<alturaPredio<<"m\n\n";
}

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

void finalize()
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

void removeProduct()
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
	int opc;
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
	
	while (opc!=4)
	{
		cout<<"-------- CAIXA ELETRONICO --------\n1- ADICIONAR PRODUTO\n2- FINALIZAR COMPRA\n3- REMOVER PRODUTO\n4- CANCELAR TODA A COMPRA\n";
		cin>>opc;
		switch(opc)
		{
			case 1:
			{
				insertProduct(); //Chamando a função para inserir produto na lista de compras
			}break;
			
			case 2:
			{	
				finalize();//Chamando a função de finalizar a compra e mostrar a lista final
				opc=4; //Caso finalize a compra, o opt retornará 4 para sair do programa
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