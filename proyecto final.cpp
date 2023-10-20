// PROYECTO FINAL CAJERO AUTOMATICO C++
//YOSHIO GEOVANNI GARCIA LOPEZ
//MATRICULA: 8079920

#include <iostream>
#include <fstream>

using namespace std;

using std::ofstream;

struct clientes
{
	string nombre;
	double sueldo;
	
};


struct tarjetas
{
	
	int pin;
	
	struct clientes user;
	
};

struct tarjetas visa[1];

int v1;
double retiro, saldo, agregar2, anterior, ret2, ag2;

void titulo(string);
void cargar();
bool buscar(int, bool);
void menu();

void consultar();
void retirar();
void verificar(double);
void menuretiro();
void agregar();
void agregarsaldo(double);
void menuagregar();
void imprimir();

main()
{
	int contra;

	cargar();	
	titulo("bienvenido a tu banco virtual");
	
		cout << "INGRESA TU PIN  :  ";
		cin >> contra;
		 
		if(buscar(contra, false))
		{
			
			if(visa[v1].pin == contra)
			{
				menu();
			}
			else
			{
				system("cls");
				titulo("BIENVENIDO AL CAJERO AUTOMATICO");
				
				cout << "\n \n EL USUARIO Y EL PIN NO COINCIDEN INTENTA DE NUEVO  \n \n";
				system("pause");
				return main();
			}
			
		}
		else
		{
			cout << "\n \n EL PIN ES INVALIDO  \n \n";
			system("pause");
			return main();
		}
	}
void menu()
{
	string op;
	
	
	system("cls");
	titulo("MENU DE CAJERO AUTOMATICO ");
	
	
	while(true)
	{
		cout << "1.  CONSULTAR SALDO \n";
		cout << "2.  RETIRAR SALDO   \n";
		cout << "3.  INGRESAR SALDO  \n";
		cout << "4.  IMPRIMIR        \n";
		cout << "5.  SALIR ";
		cout << "\n \n \n";	
		cout << "Elegir una Opcion  :   ";
		cin >> op;
		
		if (op == "1")
		{
			consultar();
			break;
		}
		else if(op == "2")
		{
			retirar();
			break;
		}
		else if(op == "3")
		{
			agregar();
			break;
		}
		else if(op == "4")
		{
			imprimir();
			break;
		}
		else if(op == "5")
		{
			main();
			break;
		}
		else
		{
		
			break;
		}
			
	
	}
	
}

void consultar()
{
	system("cls");
	titulo("CONSULTA DE SALDO ");
	
	cout << "-----------------------------------------------------------------------\n \n";
	cout << "  Nombre   :  " << visa[v1].user.nombre << "\n \n";
	cout << "  Saldo    :  " << visa[v1].user.sueldo << "\n \n";
	cout << "-----------------------------------------------------------------------\n \n";
	
	system("pause");
	menu();
	
}


void retirar()
{
	retiro = 0;
	
	string op2;
	
	system("cls");
	titulo("OPCIONES DE RETIRO ");
	
	while(true)
	{
		cout<< "1.  500 \n \n";
		cout<< "2.  1000\n \n";
		cout<< "3.  2500\n \n";
		cout<< "4.  7000 \n \n";
		cout<< "5.  Cancelar \n \n";
		
		
		cout << "\n \n \n";
		cout << "Elegir Opcio de Retiro  :  ";
		cin >> op2;
		
		if(op2=="1")
		{
			retiro = 500;
			
			verificar(retiro);
			break;
		}
		else if(op2=="2")
		{
			retiro = 1000;
			verificar(retiro);
			break;
		}
		else if(op2=="3")
		{
			retiro = 2500;
			verificar(retiro);
			break;
		}
		else if(op2=="4")
		{
			retiro = 7000;
			verificar(retiro);
			break;
		}
		else if(op2=="5")
		{
			menu();
		}
		else
		{
		
			break;
			
		}
	}	
	
}

void verificar(double rt)
{
	saldo = visa[v1].user.sueldo;
	anterior = saldo;
	
	if (saldo >= rt)
	{
		saldo = saldo - rt;
		visa[v1].user.sueldo = saldo;
		ret2 = rt;
		system("cls");
		titulo("RETIRO DE SALDO ");
		cout << "SU SALDO DE " << rt << " FUE RETIRADO CON EXITO \n \n";
		cout << "SU NUEVO SALDO ES " << saldo << "\n \n \n";
		system("pause");
		menuretiro();		
		
	}
	else
	{
		system("cls");
		titulo("OPCIONES DE RETIRO ");
		cout << "SALDO INSUFICIENTE PARA EL RETIRO  \n \n \n";
		system("pause");
		retirar();
		
	}
	
}

void menuretiro()
{
	string op3;
	
	system("cls");
	titulo("OPCIONES DE RETIRO ");
	cout << "1. REALIZAR OTRO RETIRO   \n \n \n";
	cout << "2. IR AL MENU   \n \n \n";
	cout << "Elegir una Opcion  :   ";
	cin >> op3;
	
	
	if(op3== "1")
	{
		retirar();
	}
	else if(op3=="2")
	{
		menu();
	}
	else
	{
		menuretiro();
	}
		
}

void agregar()
{
	agregar2 = 0;
	
	string op4;
	
	system("cls");
	titulo("OPCIONES PARA AGREGAR SALDO ");
	
	while(true)
	{
		cout<< "1.  100\n \n";
		cout<< "2.  250\n \n";
		cout<< "3.  500 \n \n";
		cout<< "4.  1000 \n \n";
		cout<< "5.  Cancelar \n \n";
		
		
		cout << "\n \n \n";
		cout << "Elegir Opcion de Retiro  :  ";
		cin >> op4;
		
		if(op4=="1")
		{
			agregar2 = 100;
			agregarsaldo(agregar2);
			break;
		}
		else if(op4=="2")
		{
			agregar2 = 250;
			agregarsaldo(agregar2);
			break;
		}
		else if(op4=="3")
		{
			agregar2 = 500;
			agregarsaldo(agregar2);
			break;
		}
		else if(op4=="4")
		{
			agregar2 = 1000;
			agregarsaldo(agregar2);
			break;
		}
		else if(op4=="5")
		{
			menu();
		}
		else
		{
			break;
			
		}
	}	
	
}

void agregarsaldo(double as)
{
	saldo = visa[v1].user.sueldo;
	saldo = saldo + as;
	visa[v1].user.sueldo = saldo;
	
		ag2 = as;
		system("cls");
		titulo("AGREGADO DE SALDO ");
		cout << "SU SALDO DE " << as << " FUE AGREGADO CON EXITO \n \n";
		cout << "SU NUEVO SALDO ES " << saldo << "\n \n \n";
		system("pause");
		menuagregar();		

}

void menuagregar()
{
	string op5;
	
	system("cls");
	titulo("OPCIONES DE AGREGAR SALDO ");
	cout << "1. REALIZAR OTRO AGREGADO DE SALDO   \n \n \n";
	cout << "2. IR AL MENU   \n \n \n";
	cout << "Elegir una Opcion  :   ";
	cin >> op5;
	
	if(op5== "1")
	{
		agregar();
	}
	else if(op5=="2")
	{
		menu();
	}
	else
	{
		menuagregar();
	}
	
	
}

void imprimir()
{
	
	system("cls");
	titulo("IMPRIMIR TRANSANCION ");
	
	ofstream imp("cliente.txt");
	
	
	cout << "NOMBRE         :   " << visa[v1].user.nombre << "\n \n";
	
	cout << "SALDO ANTERIOR :   " << anterior << "\n \n";
	
	cout << "SALDO RETIRO   :   " << ret2 << "\n \n";
	
	cout << "SALDO AGREGADO :   " << ag2 << "\n \n";
	
	cout << "SALDO ACTUAL   :   " << visa[v1].user.sueldo << "\n \n";
	
		
	imp  << "NOMBRE         :   " << visa[v1].user.nombre << "\n \n";	
	imp  << "SALDO ANTERIOR :   " << anterior << "\n \n";	
	imp  << "SALDO RETIRO   :   " << ret2 << "\n \n";	
	imp  << "SALDO AGREGADO :   " << ag2 << "\n \n";	
	imp  << "SALDO ACTUAL   :   " << visa[v1].user.sueldo << "\n \n";
	
	imp.close();
		
	cout << "\n \n DATOS IMPRESOS CORRECTAMENTE QUE TENGAS EXCELENTE DIA :D \n \n \n";
	system("pause");
	menu();
		
}

void error()
{
	system("cls");
	titulo("OPCIONES INVALIDAS DEL CAJERO AUTOMATICO ");
	cout << "LA OPCION INGRESADO NO EXISTE \n \n ";
	system("pause");
	menu();
}


void titulo(string title)
{
	int i;
	int val;
	
	val = title.length() ;
	
	val = val + 20;
	
	
	for(i=0; i<= val; i++)
	{
		cout << "*";
	}
	
	cout << "\n \n";
	
	for(i=0; i<= val; i++)
	{
		cout << " ";
		if(i==4 )
		{
			cout << title;
		}
		
		cout << " ";
		
	}
	
	cout << "\n";
	
	for(i=0; i<= val; i++)
	{
		cout << "*";
	}
	
	cout << "\n \n \n";
	
}

void cargar()
{
	
	visa[0].pin	= 1725;
	visa[0].user.nombre = "YOSHIO GEOVANNI GARCIA LOPEZ";
	visa[0].user.sueldo = 5000;
	
}

bool buscar(int bs, bool up)
{
	int i=0;

	
	if(up == true)
	{
		for(i=0; i<= 3; i++)
		{
			
			{
				v1 = i;
				return true;
			}
			
		}
	}
	else
	{
		for(i=0; i<= 3; i++)
		{
			if(visa[i].pin == bs)
			{
			
				return true;
			}
		
		
		}
	}

}
