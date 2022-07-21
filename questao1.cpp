#include <iostream>
#include <math.h>
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

int main(int argc, char** argv)
{
	payment();
	return 0;
}

