#include"Cuerpo.h"
#include <iostream>
#include <vector>
#include<fstream>
using namespace std;


int main()
{
    fstream archivo;
    Cuerpo cp1={0,-7000,2,0,70,120},cp2={0,0,0,0,70000,300},cp3={4000,5000,-1.6,1.2,25,100}; //definicion de cuerpos del sistema 1

    vector <Cuerpo> sistema={cp1,cp2,cp3};
    int numcuerpos=sistema.size(),i,j,muestreo;


    archivo.open("Simulacion.txt",ios::out);


    for(muestreo=0;muestreo<10000;muestreo++){


        for(i=0;i<numcuerpos;i++){        //CALCULAR ACELERACIONES
            sistema[i].setAx(0);
            sistema[i].setAy(0);

            for(j=0;j<numcuerpos;j++)
                if(j!=i){
                    sistema[i].aceleracion(sistema[j]); //Aceleracion relativas
                }
        }

        //Calcular posicones
        for(i=0;i<numcuerpos;i++){
            sistema[i].posicion();

            archivo<<sistema[i].getX()<<"\t\t"<<sistema[i].getY()<<"\t\t";   //archivo
        }
        archivo<<endl;
    }
    archivo.close();

}
