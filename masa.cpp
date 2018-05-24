#include <iostream>
#include <math.h>
#define G 1/*6.67384*pow(10,-11)*/
#include "Cuerpo.h"

using namespace std;

//Métodos de asignación de valores a las variables.
float Cuerpo::getX() const
{
    return x;
}

void Cuerpo::setX(float value)
{
    x = value;
}

float Cuerpo::getY() const
{
    return y;
}

void Cuerpo::setY(float value)
{
    y = value;
}

float Cuerpo::getAx() const
{
    return ax;
}

void Cuerpo::setAx(float value)
{
    ax = value;
}

float Cuerpo::getAy() const
{
    return ay;
}

void Cuerpo::setAy(float value)
{
    ay = value;
}

float Cuerpo::getVx() const
{
    return vx;
}

void Cuerpo::setVx(float value)
{
    vx = value;
}

float Cuerpo::getVy() const
{
    return vy;
}

void Cuerpo::setVy(float value)
{
    vy = value;
}

float Cuerpo::getMasa() const
{
    return masa;
}

void Cuerpo::setMasa(float value)
{
    masa = value;
}

float Cuerpo::getRadio() const
{
    return radio;
}

void Cuerpo::setRadio(float value)
{
    radio = value;
}

void Cuerpo::aceleracion(Cuerpo cuerpo){ //Método de acelaración, distancia y ángulo.
    float Distancia, Aceleracion, Angulo;

    Distancia = distancia(cuerpo.getX(), cuerpo.getY());
    Angulo = angulo(cuerpo.getX(), cuerpo.getY());
    Aceleracion = G*cuerpo.getMasa()/Distancia;
    ax = Aceleracion*cos(Angulo);
    ay = Aceleracion*sin(Angulo);
}

float Cuerpo::distancia(float xi, float yi){ //Método de distancia.
    float Distancia;

    Distancia = pow((xi - x), 2) + pow((yi - y), 2);
    return Distancia;

}

float Cuerpo::angulo(float xi, float yi){ //Método de angulo.
    float Angulo;

    Angulo = (yi - y)/(xi - x);
    Angulo = atan2((yi-y), (xi-x));
    return Angulo;

}

void Cuerpo::posicion(){ //Posición.
    x = x + vx + 0.5 * ax;
    y = y + vy + 0.5 * ay;
    vx = ax;
    vy = ay;

}

Cuerpo::Cuerpo():x(0),y(0),vx(0),vy(0),masa(0){
    masa = 0;
    ax = 0;
    ay = 0;
}

Cuerpo::Cuerpo(float _x, float _y, float _vx, float _vy, float _masa, float _radio): x(_x),y(_y),vx(_vx),vy(_vy),masa(_masa){
    radio=_radio;
}
