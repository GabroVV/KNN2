//
// Created by Gabriel on 27.03.2019.
//
using namespace std;
#include "../include/Iris.h"
#include <sstream>

double Iris::getSl() const {
    return sl;
}

double Iris::getSw() const {
    return sw;
}

double Iris::getPl() const {
    return pl;
}

double Iris::getPw() const {
    return pw;
}

int Iris::getSpecies() const {
    return species;
}

Iris::~Iris() {

}

Iris::Iris(double sl, double sw, double pl, double pw, int species):sl(sl),sw(sw),pl(pl),pw(pw),species(species)
{
    distance = 0;
}

string Iris::toString()
{
    stringstream text;
    text<<sl<<","<<sw<<","<<pl<<","<<"pw"<<","<<species;
    return text.str();
}

double Iris::getDistance() const {
    return distance;
}

void Iris::setDistance(double distance) {
    Iris::distance = distance;
}
