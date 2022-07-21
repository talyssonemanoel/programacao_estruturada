#include <iostream>
#include <stdlib.h>

using namespace std;
//Questão 2 da lista de execícios da disciplina Programação estruturada
//Docente: Lima Junior
//Desenvolvido por Talysson Emanoel Medeiros da Costa


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


int main()
{
	lojasDeCamisas();
	return 0;
}
