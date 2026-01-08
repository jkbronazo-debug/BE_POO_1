// gauchard@laas.fr
// contacte prof en cas de probleme

/*#include <iostream>
#include <list>
#include <algorithm>
#include <typeinfo>*/
#include <Arduino.h>



// "C:\Users\eloua\Documents\PlatformIO\Projects\Projet_4A-C\platformio.ini"
using namespace std;

//----------------------------------


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
        try{
            if (mes_distance < limite_inf){
                throw(mes_distance);
            }
            if (mes_distance > limite_sup){
                throw(mes_distance);
            }
            if (mes_distance < seuil){      //Condition de détection
                result = true;
            }
        }catch(float mes_distance){
            deactivate();
            Serial.print("Erreur : valeurs hors limites. Capteur ultrason no. ");
            Serial.print(getID());
            Serial.print(" désactivé.\n\n");
        }
        return result;
    }

    void setTrigPin(int new_pin){
        trigpin = new_pin;
    }

    int getTrigPin(){
        return trigpin;
    }

    void setEchoPin(int new_pin){
        echopin = new_pin;
    }

    int getEchoPin(){
        return echopin;
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
    float seuil;
    float limite_inf = 0;  //Je mets 0 au hasard, il faudra voir ce qui est cohérent
    float limite_sup = 1000; //Je mets 1000 au hasard, il faudra voir ce qui est cohérent
    int pin1; //check s'il faut bien seulement deux pins ou plus.
    int pin2;

public:
    void update() override {
        //cette fonction change la valeur de "mes_distance": mes_distance <- la nouvelle valeur mesurée par le capteur.
    }

    bool detect_event() override{
        int result = false;
        update();
        try{
            if (mes_lum < limite_inf){
                throw(mes_lum);
            }
            if (mes_lum > limite_sup){
                throw(mes_lum);
            }
            if (mes_lum > seuil){     //Condition de détection
                result = true;
            }
        }catch(float mes_lum){
            deactivate();
            Serial.print("Erreur : valeurs hors limites. Capteur de luminosite no. ");
            Serial.print(getID());
            Serial.print(" désactivé.\n\n");
        }
        return result;
    }

    void setPin1(int new_pin){
        pin1 = new_pin;
    }

    int getPin1(){
        return pin1;
    }

    void setPin2(int new_pin){
        pin1 = new_pin;
    }

    int getPin2(){
        return pin1;
    }


};





class Son_capteur : public Capteur {
protected:
    float mes_son;
    float seuil;
    float limite_inf = 0;  //Je mets 0 au hasard, il faudra voir ce qui est cohérent
    float limite_sup = 1000; //Je mets 1000 au hasard, il faudra voir ce qui est cohérent
    int pin1; //check s'il faut bien seulement deux pins ou plus.
    int pin2;

public:
    void update() override {
        //cette fonction change la valeur de "mes_son": mes_son <- la nouvelle valeur mesurée par le capteur.
    }

    bool detect_event() override{
        int result = false;
        update();
        try{
            if (mes_son < limite_inf){
                throw(mes_son);
            }
            if (mes_son > limite_sup){
                throw(mes_son);
            }
            if (mes_son > seuil){    //Condition de détection
                result = true;
            }
        }catch(float mes_son){
            deactivate();
            Serial.print("Erreur : valeurs hors limites. Capteur de son no. ");
            Serial.print(getID());
            Serial.print(" désactivé.\n\n");
        }
        return result;
    }

    void setPin1(int new_pin){
        pin1 = new_pin;
    }

    int getPin1(){
        return pin1;
    }

    void setPin2(int new_pin){
        pin1 = new_pin;
    }

    int getPin2(){
        return pin1;
    }


};




class Ang_capteur : public Capteur {
protected:
    float mes_ang;
    float seuil;
    float limite_inf = 0;  //Je mets 0 au hasard, il faudra voir ce qui est cohérent
    float limite_sup = 1000; //Je mets 1000 au hasard, il faudra voir ce qui est cohérent
    int pin1; //check s'il faut bien seulement deux pins ou plus.
    int pin2;

public:
    void update() override {
        //cette fonction change la valeur de "mes_son": mes_son <- la nouvelle valeur mesurée par le capteur.
    }

    bool detect_event() override{
        int result = false;
        update();
        try{
            if (mes_ang < limite_inf){
                throw(mes_ang);
            }
            if (mes_ang > limite_sup){
                throw(mes_ang);
            }
            if (mes_ang > seuil){    //Condition de détection
                result = true;
            }
        }catch(float mes_ang){
            deactivate();
            Serial.print("Erreur : valeurs hors limites. Capteur d'angle no.");
            Serial.print(getID());
            Serial.print(" désactivé.\n\n");
        }
        return result;
    }

    void setPin1(int new_pin){
        pin1 = new_pin;
    }

    int getPin1(){
        return pin1;
    }

    void setPin2(int new_pin){
        pin1 = new_pin;
    }

    int getPin2(){
        return pin1;
    }


};



















/*
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
        int result = int pin1; //check s'il faut bien seulement deux pins ou plus.
    int pin2;
 false;
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

};*/
    Button_capteur B1 ;

    void setup(){
       Serial.begin(9600);  
        B1.setPin(2);
       
    }
    

 
   
void loop(){
    int pin_button_press = B1.getPin();
    Serial.println(pin_button_press);

}




