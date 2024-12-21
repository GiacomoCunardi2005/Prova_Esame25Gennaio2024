//
// Created by Giacomo Cunardi on 20/12/2024.
//

#ifndef COMPITO_H
#define COMPITO_H
#include "iostream"
#include "cstring"

using namespace std;

struct mensa{
    bool occupata;
    char* desc = NULL;
};

class Mensa {
    mensa* arr_mensa;
    mutable int n_posti;
public:
    Mensa(int n_sedia);
    friend ostream& operator<<(ostream&, const Mensa&);
    bool occupa(char* id);
    bool libera(int i);
    ~Mensa();
    Mensa(const Mensa& p);
    bool occupaGruppo(char* id,int n);
    bool ordina();
};



#endif //COMPITO_H
