#include <iostream>
#include <math.h>
using namespace std;

//Questão 2 da lista de execícios da disciplina Programação estruturada
//Docente: Lima Junior
//Desenvolvido por Talysson Emanoel Medeiros da Costa

float restauranteSelfService() // Função para calcular o valor proporcional ao peso do alimento
{
	cout<<"Informe o valor em quilos (Kg) do seu pedido: \n";
	float price=23.00;
	float x;
	cout << fixed;
	cout.precision(2);
	
	cin>>x;
	
	cout<<"Valor total a pagar: R$ "<<x*price<<"\n\n";
}



int main(int argc, char** argv)
{	
	restauranteSelfService();//chamando a função weight
	
	return 0;
}