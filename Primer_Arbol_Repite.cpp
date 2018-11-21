#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;

struct Nodo{
	int dato;
	Nodo *derecha;
	Nodo *izquierda;
};

//PROTOTIPOS DE FUNCION
Nodo *crearNodo(int);
void insertarNodo(Nodo *&, int);
void menu();

Nodo *arbol=NULL;

int main()
{
	menu();
	
	getch();
	return 0;
}

//FUNCION DE MENU
void menu(){
	int dato, opcion;
	
	do{
		cout<<"\t.:MENU:."<<endl;
		cout<<"1.- Insertar un nuevo nodo"<<endl;
		cout<<"2.- Salir"<<endl;
		cout<<"Opcion: ";
		cin>>opcion;
		
		switch(opcion){
			case 1: cout<<"\nIntroduce un numero: ";
			cin>>dato;
			insertarNodo(arbol,dato);
			cout<<"\n";
			system("pause");
			break;
		}
		system("cls");
	}while(opcion !=2);
}
//FUNCION PARA CREAR UN NUEVO NODO
Nodo *crearNodo(int n){
	Nodo *nuevo_nodo=new Nodo();
	
	nuevo_nodo->dato=n;
	nuevo_nodo->derecha=NULL;
	nuevo_nodo->izquierda=NULL;
	
	return nuevo_nodo;
}
void insertar(Nodo *&arbol, int n){
	if(arbol==NULL){
		Nodo *nuevo_nodo=crearNodo(n);
		arbol=nuevo_nodo;
	}else{
		int valorRaiz=arbol->dato;
		if(n<valorRaiz){
			insertar(arbol->izquierda,n);
		}else{
			insertar(arbol->derecha,n);
		}
	}
}

//FUNCION PARA INSERTAR ELEMENTOS EN EL ARBOL
void insertarNodo(Nodo *&arbol, int n){
	if(arbol==NULL){//si el arbol esta vacio
		Nodo *nuevo_nodo=crearNodo(n);
	}else{//si el arbol tiene un nodo o mas
	      int valorRaiz=arbol->dato;//obtenemos el valor de la raiz
	      if(n<valorRaiz){//si el elemento es menor a la raiz, insertamos en izquierda
	          insertarNodo(arbol->izquierda,n);
		  }else{//si el elemento es mayor a la raiz, insertamos en derecha
		        insertarNodo(arbol->derecha,n);
		  }
	}
	
	
}
