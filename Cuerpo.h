#ifndef CUERPO_H
#define CUERPO_H
#include <iostream>
#include <math.h>
#define G 1/*6.67384*pow(10,-11)*/
#endif // CUERPO_H

using namespace std;

class Cuerpo{
    float x, y; //Posición x y y
    float vx, vy; //Velocidad x y y.
    float ax, ay; //Aceleración x y y.
    float masa, radio; //Masa y radio.

public:
    Cuerpo();
    Cuerpo(float _x, float _y, float _masa, float _radio, float _vx, float _vy);
    ~Cuerpo(){}

    //Get
    float getX() const;
    float getY() const;
    float getMasa() const;
    float getRadio() const;
    float getVx() const;
    float getVy() const;
    float getAx() const;
    float getAy() const;

    //Set
    void setX(float value);
    void setY(float value);
    void setMasa(float value);
    void setRadio(float value);
    void setVx(float value);
    void setVy(float value);
    void setAx(float value);
    void setAy(float value);

    void aceleracion(Cuerpo cuerpo);
    float distancia(float x, float y);
    float angulo(float x, float y);
    void posicion();


};
