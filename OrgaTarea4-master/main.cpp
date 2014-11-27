// queue::push/pop
#include "Evaluador.h"
#include <iostream>
#include "tinyxml2.h"
#include <iostream>
#include <list>
#include <string>
using namespace std;
using namespace tinyxml2;

//Fuente del XML:
//http://openweathermap.org/current

//Sugerencia: investigar sobre la funcion atof para convertir string a float

//Dado el formato xml en el ejemplo clima.xml realizar los siguientes ejercicios:
//Devuelve el attributo value del tag temperature
float getTemperature(string nombre_archivo)
{
    XMLDocument doc;
    doc.LoadFile(nombre_archivo.c_str());
    XMLElement* elemento = doc.FirstChildElement("current"); //creamos un apuntador de tipo XML para poder buscar dentro del archivo en el tag current
    XMLElement* temperature = elemento->FirstChildElement("temperature"); ////creamos un apuntador de tipo XML para poder buscar dentro del apuntador anterior la temperatura

    float temp = atof(temperature->Attribute("value")); //creamos una variable para guardar y convertir de char a flotante la temperatura
    return temp; //retornamos la temperatura
}

//Devuelve el attributo value del tag humidity
int getHumidity(string nombre_archivo)
{
    XMLDocument doc;
    doc.LoadFile(nombre_archivo.c_str());
    XMLElement* elemento = doc.FirstChildElement("current"); //creamos un apuntador de tipo XML para poder buscar dentro del archivo
    XMLElement* humidity = elemento->FirstChildElement("humidity"); //creamos un apuntador de tipo XML para poder buscar dentro del anterior apuntador la humedad

    int hum = atol(humidity->Attribute("value")); //creamos una variable entera para guardar y convertir de char a entero la humedad
    return hum; //retornamos la humedad
}

//Devuelve el attributo value del tag pressure
int getPressure(string nombre_archivo)
{
    XMLDocument doc;
    doc.LoadFile(nombre_archivo.c_str()); //abrimos el archivo xml
    XMLElement* elemento = doc.FirstChildElement("current"); //creamos un apuntador de tipo XML para poder buscar dentro del archivo en el tag current
    XMLElement* pressure = elemento->FirstChildElement("pressure");//creamos un apuntador de tipo XML para poder buscar dentro del apuntador anterior la presion

    int press = atol(pressure->Attribute("value")); //creamos una variable entera para guardar y convertir de char a entero la presion
    return press; //retornamos la presion
}

//Devuelve el attributo value del tag speed dentro del tag wind
float getWindSpeed(string nombre_archivo)
{
    XMLDocument doc;
    doc.LoadFile(nombre_archivo.c_str()); //abrimos el archivo xml
    XMLElement* elemento = doc.FirstChildElement("current"); //creamos un apuntador de tipo XML para poder buscar dentro del archivo en el tag current
    XMLElement* wind = elemento->FirstChildElement("wind");//creamos un apuntador XML para buscar dentro del apuntador anterior del archivo xml, y el tag wind
    XMLElement* speed = wind->FirstChildElement("speed");//creamos un apuntador XML para buscar dentro del apuntador anterior del archivo xml para poder sacar la velocidad

    float viento = atof(speed->Attribute("value")); //creamos una variable flotante para guardar el viento y lo convertimos de char a flotante mediante la funcion atof
    return viento; //retornamos el viento
}

//Devuelve el attributo name del tag city
string getCityName(string nombre_archivo)
{
    XMLDocument doc;
    doc.LoadFile(nombre_archivo.c_str()); //abrimos el archivo xml
    XMLElement* elemento = doc.FirstChildElement("current"); //creamos un apuntador de tipo XML para poder buscar dentro del archivo y el tag current
    XMLElement* city = elemento->FirstChildElement("city"); //creamos un apuntador XML para buscar dentro del apuntador anterior del archivo xml

    string ciudad = city->Attribute("name"); //creamos una variable tipo string para guardar el atributo o nombre de la ciudad
    return ciudad; //retornamos la ciudad
}

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 0;
}
