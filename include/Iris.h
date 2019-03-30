//
// Created by Gabriel on 27.03.2019.
//

#ifndef UNTITLED4IAD_ZAD1_IRIS_H
#define UNTITLED4IAD_ZAD1_IRIS_H

#include "string"
class Iris
{
private:
    double sl;
    double sw;
    double pl;
    double pw;
    int species;
    double distance;
public:
    double getDistance() const;

    void setDistance(double distance);

public:
    double getSl() const;

    double getSw() const;

    double getPl() const;

    double getPw() const;

    int getSpecies() const;

public:
    Iris(double sl,double sw,double pl,double pw,int species);
    ~Iris();
    std::string toString();
};

#endif //UNTITLED4IAD_ZAD1_IRIS_H
