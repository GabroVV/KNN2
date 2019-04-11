//
// Created by Gabriel on 27.03.2019.
//

#ifndef UNTITLED4IAD_ZAD1_IRIS_H
#define UNTITLED4IAD_ZAD1_IRIS_H

#include "string"

enum iris
{
    setosa,
    versicolor,
    virginica
};
class Iris
{
private:
    double sl;   // Sepal Lenght
    double sw;   // Sepal Width
    double pl;   // Petal Lenght
    double pw;   // Petal Width
    int species;
    double distance;    // Euclidean distance from test Iris
public:
    double getDistance() const;

    void setDistance(double distance);

    double getSl() const;

    double getSw() const;

    double getPl() const;

    double getPw() const;

    int getSpecies() const;

public:
    Iris(double sl,double sw,double pl,double pw,int species);
    ~Iris();
};

#endif //UNTITLED4IAD_ZAD1_IRIS_H
