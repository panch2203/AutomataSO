// Automata.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "stdio.h"
#include "conio.h"
#include <string>
#include <iostream>

using namespace std;
void automataUno();
void automataTres();
void main()
{
	int num;
	cout << "Introduce 1 para usar el automata 1, 2 para el segundo y 3 para el 3: ";
	cin >> num;

	switch (num)
	{
	case 1:
		automataUno();
		break;
	case 2:
		break;
	case 3:
		automataTres();
		break;
	default:
		break;
	}

	_getch();
	
}

void automataUno()
{
	string evento, estados[5];
	int contador = 0;
	cout << "Introduce ADMIT, DISPATCH, TIMEOUT, EVENTOCCURS, EVENTWAIT, RELEASE para avanzar entre estados \n";
	cout << "Estos eventos seran representados por letras: \n";
	cout << "ADMIT = A, DISPATCH = D, TIMEOUT = T, EVENTOCCURS = E, EVENTWAIT = W Y RELEASE = R \n";	
	estados[0]= "NEW", estados[1]= "READY",estados[2]= "RUNNING",estados[3]= "BLOCKED",estados[4]= "EXIT";
	cout << "El estado actual es: " << estados[contador] << "\n";
	while(estados[contador]!= "EXIT")
	{
		cout << "Introduce el evento: ";
		cin >> evento;
		if(estados[contador]=="NEW" && evento=="A")		
			contador++;		
		else if(estados[contador]=="READY" && evento=="D")
			contador++;
		else if(estados[contador]=="RUNNING")
		{
			if (evento=="R")
				contador+=2;			
			else if(evento=="T")
				contador--;
			else if(evento=="W")
				contador++;
		}
		else if(estados[contador]=="BLOCKED" && evento=="E")
			contador-=2;		

		cout << "El estado actual es: " << estados[contador] << "\n";

	}
	cout << "El estado final es " << estados[contador] << "\n";
			
}

void automataTres()
{
	string evento, estados[7];
	int contador = 0;
	cout << "Introduce ADMIT, ACTIVATE, DISPATCH, TIMEOUT, EVENTOCCURS, EVENTWAIT, SUSPEND, RELEASE para avanzar entre estados \n";
	cout << "Estos eventos seran representados por letras: \n";
	cout << "ADMIT = A, ACTIVATE = C, DISPATCH = D, TIMEOUT = T, EVENTOCCURS = E, EVENTWAIT = W, SUSPEND = S Y RELEASE = R \n";	
	estados[0]= "NEW", estados[1]= "READY/SUSPEND",estados[2]= "READY",estados[3]= "RUNNING",estados[4]= "BLOCKED",estados[5]= "BLOCKED/SUSPEND",estados[6]= "EXIT";
	cout << "El estado actual es: " << estados[contador] << "\n";
	while(estados[contador]!= "EXIT")
	{
		cout << "Introduce el evento: ";
		cin >> evento;
		if(estados[contador]=="NEW" && evento=="A")		
			contador++;		
		else if(estados[contador]=="READY/SUSPEND" && evento=="C")
			contador++;
		else if(estados[contador]=="READY")
		{
			if (evento=="D")
				contador++;
			else if(evento=="S")
				contador--;
		}

		else if(estados[contador]=="RUNNING")
		{
			if (evento=="R")
				contador+=3;			
			else if(evento=="T")
				contador--;
			else if(evento=="W")
				contador++;
			else if(evento=="S")
				contador-=2;
		}	
		else if(estados[contador]=="BLOCKED" )
		{
			if (evento=="E")
				contador-=2;
			else if(evento=="S")
				contador++;
		}
		else if(estados[contador]=="BLOCKED/SUSPEND" )
		{
			if (evento=="C")
				contador--;
			else if(evento=="E")
				contador-=4;
		}

		cout << "El estado actual es: " << estados[contador] << "\n";

	}
	cout << "El estado final es " << estados[contador] << "\n";
			
}


		