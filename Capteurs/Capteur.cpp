#include <iostream>
#include <list>
#include <algorithm>
#include <typeinfo>

using namespace std;

//----------------------------------

class Capteur {
protected:
    static int compteur_capteurs; 
    int ID_capteur;
    bool active;

public:
    Capteur(){
        compteur_capteurs++;
    }

    static int getCompteur(){
        return compteur_capteurs;
    }

    void activate(){
        active = 1;
    }

    void deactivate(){
        active = 0;
    }

    int getID(){
        return ID_capteur;
    }

    void setID(int newID){
        ID_capteur = newID;
    }

    virtual void update();
    virtual void print_value();
    virtual bool detectEvent() = 0;
    
};





class US_capteur : public Capteur {
protected:
    float mes_distance;
    float seuil;
    int trigpin; //check s'il faut bien seulement deux pins ou plus.
    int echopin;

public:
    void update() override {
        //cette fonction change la valeur de "mes_distance": mes_distance <- la nouvelle valeur mesurée par le capteur.
    }

    bool detectEvent() override{
        int result = false;
        update();
        if (mes_distance < seuil){
            result = true;
        }
        else{
            result = false;
        }
        return result;
    }
};


class Button_capteur : public Capteur {
protected:
    bool pressed;
    int pin_button; //check s'il faut bien un seul pin (pour le bouton, prends un pin digital je pense)

public:

    bool detect_event() override{
        //rajoute ici la lecture du pin_button et actualise la variable "pressed" (pressed <- lecture du pin-button)
        return pressed; //renvoie 1 si le bouton est appuyé, 0 s'il n'est pas appuyé.
    }
};


class Lum_capteur : public Capteur {
protected:
    float mes_lum;
    float seuil;
    int pin1; //check combien il faut de pins.
    int pin2;

public:
    void update() override {
        //cette fonction change la valeur de "mes_lum": mes_lum <- la nouvelle valeur mesurée par le capteur.
    }

    bool detect_event() override{
        int result = false;
        update();
        if (mes_lum > seuil){
            result = true;
        }
        else{
            result = false;
        }
        return result;
    }
};



class Son_capteur : public Capteur {
protected:
    float mes_son;
    float seuil;
    int pin1; //check combien il faut de pins.
    int pin2;

public:
    void update() override {
        //cette fonction change la valeur de "mes_son": mes_son <- la nouvelle valeur mesurée par le capteur.
    }

    bool detect_event() override{
        int result = false;
        update();
        if (mes_son > seuil){
            result = true;
        }
        else{
            result = false;
        }
        return result;
    }
};



class Angle_capteur : public Capteur {
protected:
    float mes_angle;
    float seuil;
    int pin1; //check combien il faut de pins.
    int pin2;

public:
    void update() override {
        //cette fonction change la valeur de "mes_angle": mes_angle <- la nouvelle valeur mesurée par le capteur.
    }

    bool detect_event() override{
        int result = false;
        update();
        if (mes_angle > seuil){
            result = true;
        }
        else{
            result = false;
        }
        return result;
    }
};

