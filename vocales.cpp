#include <iostream>
using namespace std;

struct Nodo1{
	char letra;
	Nodo1 *SIG;
} 
*cabeza1, *p1, *q1, *r1, *fin1;

struct Nodo2{
	char letra;
	Nodo2 *SIG;
}
*cabeza2, *p2, *q2, *r2, *fin2;

void registrar_letras(),mostrar_lista1(),agregar_vocal_a_lista(char&),mostrar_lista2(),borrar_vocales_lista1(),mostrar_lista1_final();

void registrar_letras(){
	char seguir='S';
	
	while(seguir=='S'){
		
		//Pido un nodo
		Nodo1* p1 = new Nodo1();
		
		if(p1==NULL){
			cout<<"No hay memoria disponible en el sistema...."<<endl;
		}else{
			//Llenamos el nodo
			cout<<"******REGISTRAR VOCAL******"<<endl;
				
			cout<<"Introduzca una letra: ";
			cin>>p1->letra;
			
			if(cabeza1==NULL){
				cabeza1=p1;
				fin1=p1;
			}else{
				fin1->SIG=p1;
				fin1=p1;
			}
			
			cout<<"Desea agregar otra vocal a la lista? s/n: ";
			cin>>seguir;
		}
	}
}

void mostrar_lista1(){
	cout<<""<<endl;
	cout<<"*****Lista Enlazada Simple #1*****"<<endl;
	if(cabeza1!=NULL){
		for	(p1=cabeza1; p1!=NULL; p1=p1->SIG){
			cout<<p1->letra<<"->";
		}
	}else{
		cout<<"La lista 1 esta vacia"<<endl;
		system("pause");
	}
	/*p1=cabeza1;
	while(p1!=NULL){
			
			cout<<p1->letra<<"-->";
			p1=p1->SIG;
	}*/	
}

void mostrar_lista1_final(){
	cout<<""<<endl;
	cout<<"*****Lista Enlazada Simple #1 Final*****"<<endl;
	if(cabeza1!=NULL){
		for	(p1=cabeza1; p1!=NULL; p1=p1->SIG){
			cout<<p1->letra<<"->";
		}
	}else{
		cout<<"La lista 1 final esta vacia"<<endl;
		system("pause");
	}
	/*p1=cabeza1;
	while(p1!=NULL){
			
			cout<<p1->letra<<"-->";
			p1=p1->SIG;
	}*/	
}

void buscar_vocales(){
	cout<<""<<endl;
	char vocal;
	if(cabeza1!=NULL){
		for	(p1=cabeza1; p1!=NULL; p1=p1->SIG){
			if(p1->letra=='A' || p1->letra=='E' || p1->letra=='I' || p1->letra=='O' || p1->letra=='U'){
				vocal=p1->letra;
				agregar_vocal_a_lista(vocal);
			}
		}
	}else{
		cout<<"La lista 1 esta vacia"<<endl;
		system("pause");
	}
}

void agregar_vocal_a_lista(char& vocal){
	//Pido un nodo
	Nodo2* p2 = new Nodo2();
		
	if(p2==NULL){
		cout<<"No hay memoria disponible en el sistema...."<<endl;
	}else{
		//Llenamos el nodo
		p2->letra=vocal;
			
		if(cabeza2==NULL){
			cabeza2=p2;
			fin2=p2;
		}else{
			fin2->SIG=p2;
			fin2=p2;
		}
	}
}

void mostrar_lista2(){
	cout<<""<<endl;
	cout<<"*****Lista Enlazada Simple #2*****"<<endl;
	if(cabeza2!=NULL){
		for	(p2=cabeza2; p2!=NULL; p2=p2->SIG){
			cout<<p2->letra<<"->";
		}
	}else{
		cout<<"La lista 2 esta vacia"<<endl;
		system("pause");
	}
	cout<<""<<endl;
	cout<<""<<endl;
}

void borrar_vocales_lista1(){
	//A->Y->O->S->
	if(cabeza1!=NULL){
		
		for	(q1=cabeza1; q1!=NULL; q1=q1->SIG){
			
			if(q1->letra=='A' || q1->letra=='E' || q1->letra=='I' || q1->letra=='O' || q1->letra=='U'){
				if(q1==cabeza1 && q1->SIG==NULL){
					cabeza1=NULL;
					//delete p1;
				}else{
					if(q1==cabeza1){
						cabeza1=cabeza1->SIG;
						//delete p1;
					}else{
						r1=cabeza1;
						while(r1->SIG!=q1){
							r1=r1->SIG;
						}
						r1->SIG=q1->SIG;
						//delete q1;
					}
				}						
			}			
		}				
	}else{
		cout<<"La lista 1 esta vacia"<<endl;
		system("pause");
	}	
}

int main(){
	
	registrar_letras();
	mostrar_lista1();
	buscar_vocales();
	mostrar_lista2();
	borrar_vocales_lista1();
	mostrar_lista1_final();
	
	return 0;
}
