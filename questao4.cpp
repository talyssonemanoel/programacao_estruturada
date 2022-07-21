#include <iostream>
using namespace std;

//Questão 2 da lista de execícios da disciplina Programação estruturada
//Docente: Lima Junior
//Desenvolvido por Talysson Emanoel Medeiros da Costa

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

int main(int argc, char** argv)
{
	calculoDaAltura(); //chamando a função
	return 0;
}