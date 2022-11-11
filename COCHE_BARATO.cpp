#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

using namespace std;

void gotoxy(int x, int y)
{
	HANDLE hcon =  GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);	
}

class Vehiculo{
    private:
        string Modelo, Marca;
        int Precio;

    public:
        Vehiculo(string Modelo, string Marca, int Precio);    
        Vehiculo(){}
        ~Vehiculo(){}
        float getPrecio();
        static int indiceBarato(Vehiculo Coche[], int n);
        void mostrarDatos();
};

Vehiculo::Vehiculo(string Modelo, string Marca, int Precio){
    this ->Modelo = Modelo;
    this ->Marca = Marca;
    this ->Precio = Precio;
}

float Vehiculo::getPrecio(){
    return Precio;
}

int Vehiculo::indiceBarato(Vehiculo Coche[], int n){
    int Indice =0, precio;
    precio = Coche[0].getPrecio();

    for(int i=0; i<n; i++){

        if(Coche[i].getPrecio() < precio){
            precio = Coche[i].getPrecio();
            Indice = i;
        }
    }

    return Indice;
}

void Vehiculo::mostrarDatos(){
    cout <<"Los datos del vehiculo son: " <<endl;
    cout <<"El modelo del coche es: "<<Modelo<<endl;
    cout <<"La marca del coche es: "<<Marca <<endl;
    cout <<"El precio del vehiculo es: "<<Precio <<endl;
}

int main(){
    Vehiculo *Coche;
    string modelo, marca;
    int precio, no_Coches, indiceBarato;

    cout <<".:Escribe cuantos vehiculos quieres comparar:. "<<endl;
    cin >>no_Coches;
  
    Coche = new Vehiculo[no_Coches];

    if(no_Coches >=1 && no_Coches <=10){

        for(int i=0; i<no_Coches; i++){

          cin.ignore();  
          cout <<"Escribe el modelo del vehiculo: "<<(i+1) <<endl; 
          getline(cin, modelo);
          cout <<"Escribe la marca: " <<endl;
          getline(cin, marca);
          cout <<"Escribe su precio: " <<endl;
          cin >>precio;

          *(Coche +i) = Vehiculo(modelo, marca, precio);
        }

        cout <<"El coche mas barato es: " <<endl;
        indiceBarato = Vehiculo::indiceBarato(Coche, no_Coches);

        (Coche +indiceBarato)->mostrarDatos();
    }

    else{
        cout <<"Parametros incorrectos!" <<endl;
    }

    delete[] Coche;

    getch();
    return 0;
}