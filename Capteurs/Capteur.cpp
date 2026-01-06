#include <iostream>
#include <list>
#include <algorithm>
#include <typeinfo>
#include <Arduino.h>

using namespace std;

//----------------------------------
void setup(){


}


void loop(){
class Capteur {
protected:
     int compteur_capteurs; 
    int ID_capteur;
    bool active;

public:
    Capteur(){
        compteur_capteurs++;
    }

     int getCompteur(){
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
    virtual bool detect_event() = 0;
    
};





class US_capteur : public Capteur {
protected:
    float mes_distance;
    float seuil;
    float limite_inf = 0;  //0 car la distance mesurée ne peut pas être négative
    float limite_sup = 1000; //Je mets 1000 au hasard, il faudra voir ce qui est cohérent
    int trigpin; //check s'il faut bien seulement deux pins ou plus.
    int echopin;

public:
    void update() override {
        //cette fonction change la valeur de "mes_distance": mes_distance <- la nouvelle valeur mesurée par le capteur.
    }

    bool detect_event() override{
        int result = false;
        update();
        if (mes_distance < seuil){
            result = true;
        }
        else{
            result = false;
        }
        if (mes_distance < limite_inf){
            deactivate();
        }else if (mes_distance > limite_sup){
            deactivate();
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
        pressed = digitalRead(pin_button) ; //rajoute ici la lecture du pin_button et actualise la variable "pressed" (pressed <- lecture du pin-button)
        return pressed; //renvoie 1 si le bouton est appuyé, 0 s'il n'est pas appuyé.
    }

    void setPin(int new_pin){
        pin_button = new_pin;
    }

    int getPin(){
        return pin_button;
    }
};





class Lum_capteur : public Capteur {
protected:
    float mes_lum;
    float limite_inf = 0;  //Je mets 0 au hasard, il faudra voir ce qui est cohérent
    float limite_sup = 1000; //Je mets 1000 au hasard, il faudra voir ce qui est cohérent
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
             bool detect_event() override{
        int result = false;        
        return result;
        }
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
}



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
<<<<<<< HEAD

    
}


    Button_capteur B1 ; 
    B1.pin_button = 2;
    Serial.print(pressed);

}

=======
>>>>>>> fde32331f61d4fc844632afc0175091fd4f6153e
