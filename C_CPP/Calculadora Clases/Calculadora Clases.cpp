#include <iostream>
using namespace std;
#define PI 3.14

class RC //Clase en la cual tenemos r, c y fc
{
    private: //atributos privados
        float r, c, fc;
    
    public: //métodos públicos
        void setRC(float, float);
        float get_cuttoff_frequency();
        void cuttoff_frequency();   //A las funciones no le ingresa ningún dato porque están en la misma clase (en mi caso)
};

void RC::setRC(float _r, float _c)
{
    r=_r;
    c=_c;
};

void RC::cuttoff_frequency() //Método para calcular la frecuencia de corte
{
    fc = 1/(2*PI*r*c);
}

float RC::get_cuttoff_frequency() //Método para mostrar la frecuencia de corte
{
    return fc;
}

// Clase pasabajo que hereda los métodos y atributos de RC

class pasabajo: public RC
{
    private:
        float t, f;
    public:
        void setF(float);
        void transfer();
        float get_transfer();
};

void pasabajo::setF(float _f)
{
    f=_f;
}

void pasabajo::transfer()
{
    t = 1/(1+f/get_cuttoff_frequency());
}

float pasabajo::get_transfer()
{
    return t;
}

int main()
{
    cout << "BIENVENIDO A LA CALCULADORA DE TRANSFERENCIAS PARA FILTROS PASABAJOS" << endl;
    float res, cap, u, frec;
    char unidad;
    //  Introducción de valores
    // Resistencia
    cout << "| r para Ω | k para KΩ | m para MΩ |" << endl;
    cout << "Ingrese la unidad del valor de capacitancia a ingresar: ";
    cin >> unidad;
    if (unidad=='r') u = 1.0E+0;
    else if (unidad=='k') u = 1.0E+3;
    else if (unidad=='m') u = 1.0E+6;
    cout << "Ingrese el valor de la resistencia: ";
    cin >> res;
    res = res*u;
    // Capacitancia
    cout << "| m para mili | u para micro | n para nano | p para pico |" << endl; //capacitancia
    cout << "Ingrese la unidad del valor de capacitancia a ingresar: ";
    cin >> unidad;
    if (unidad=='m') u = 1.0E-3;
    else if (unidad=='u') u = 1.0E-6;
    else if (unidad=='n') u = 1.0E-9;
    else if (unidad=='p') u = 1.0E-12;
    cout << "Ingrese el valor de la capacitancia: ";
    cin >> cap;
    cap = cap*u;
    // Frecuencia
    cout << "| h para Hz | k para KHz | m para MHz |" << endl; //frecuencia
    cout << "Ingrese la unidad del valor de frecuencia a ingresar: ";
    cin >> unidad;
    if (unidad=='h') u = 1.0E+0;
    else if (unidad=='k') u = 1.0E+3;
    else if (unidad=='m') u = 1.0E+6;
    cout << "Ingrese el valor de la frecuencia: ";
    cin >> frec;
    frec = frec*u;
    // Main
    pasabajo obj;
    obj.setRC(res, cap);
    obj.cuttoff_frequency();
    //cout << "fc = " << obj.get_cuttoff_frequency() << endl;
    obj.setF(frec);
    obj.transfer();
    cout << "t = " << obj.get_transfer() << endl;
    return 0;
}