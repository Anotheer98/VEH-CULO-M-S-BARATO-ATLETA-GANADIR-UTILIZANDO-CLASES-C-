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


class Atleta{
    private: 
        int numero_Atleta;
        float Tiempo;
        string Nombre;

    public:
        Atleta(int numero_Atleta, float Tiempo, string Nombre);
        Atleta();
        ~Atleta();
        float getTiempo();
        static int indice_Ganador(Atleta Jugador[], int n);
        void mostrar_Datos();
};

Atleta::Atleta(int numero_Atleta, float Tiempo, string Nombre){
    this ->numero_Atleta = numero_Atleta;
    this ->Tiempo = Tiempo;
    this ->Nombre = Nombre;
}

Atleta::Atleta(){} //CONSTRUCTOR POR DEFECTO
Atleta::~Atleta(){} //DESTRUCTOR

float Atleta::getTiempo(){
    return Tiempo;
}

int Atleta::indice_Ganador(Atleta Jugador[], int n){
    float tiempo_Recorrido;
    int Indice =0;
    tiempo_Recorrido = Jugador[0].getTiempo();

    for(int i=1; i<n; i++){

        if(Jugador[i].getTiempo() < tiempo_Recorrido){
            tiempo_Recorrido = Jugador[i].getTiempo();
            Indice = i;
        }
    }

    return Indice;
}

void Atleta::mostrar_Datos(){
   gotoxy(34, 0); cout <<".: LOS DATOS DEL ATLETA GANADOR ES: ";
   gotoxy(34, 2); cout <<"SU NOMBRE ES: " <<Nombre;
   gotoxy(34, 3); cout <<"FUE EL NUMERO: " <<numero_Atleta;
   gotoxy(34, 4); cout <<"EL TIEMPO EN QUE TERMINO LA CARRERA FUE: " <<Tiempo;
}

int main(){
    Atleta *Jugador;
    int no_Atleta, no_Jugadores, Ganador;
    float tiempo;
    string nombre;
    bool Band = false;

    gotoxy(34, 0); cout <<"ESCRIBE LA CANTIDAD DE JUGADORES QUE PARTICIPARON: ";
    gotoxy(34, 1); cin >>no_Jugadores;
    system("cls");

    while((no_Jugadores <0) && (Band == false)){

        gotoxy(34, 2); cout <<"Escribe un parametro valido!";
        gotoxy(34, 3); cin >>no_Jugadores;
        system("cls");
    }

    if(no_Jugadores >=1){

        Band = true;
        Jugador = new Atleta[no_Jugadores];
        for(int i=0; i<no_Jugadores; i++){

        cin.ignore();
        gotoxy(34, 1); cout <<"Escribe el nombre del jugador ["<<i+1<<"]";
        gotoxy(34, 2); getline(cin, nombre);
        gotoxy(34, 3); cout <<"Escribe su numero de jugador: ";
        gotoxy(34, 4); cin >>no_Atleta;
        gotoxy(34, 5); cout <<"Escribe el tiempo en el que termino la carrera (minutos): ";
        gotoxy(34, 6); cin >>tiempo;
        system("cls");

        *(Jugador +i) = Atleta(no_Atleta, tiempo, nombre);
        }

        Ganador = Atleta::indice_Ganador(Jugador, no_Jugadores);
        (Jugador + Ganador)->mostrar_Datos();
    }

    delete[] Jugador;

    getch();
    return 0;
}