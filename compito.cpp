//
// Created by Giacomo Cunardi on 20/12/2024.
//

#include "compito.h"

using namespace std;

Mensa::Mensa(int n_sedia) {
    for (int i = 0; i < n_sedia; i++) {
        this->arr_mensa[i].occupata = false;
    }
    this->n_posti = n_sedia;
}

ostream& operator<<(ostream& juj, const Mensa& m) {
    int k = 0;
    for (int i = 0; i < m.n_posti ; i++) {
        cout << "sedia " << i + 1 << ": ";
        if (m.arr_mensa[i].occupata) {
            while (m.arr_mensa[i].desc[k] != 0) {
                k++;
            }
            for (int j = 0; j < k; j++) {
                cout << m.arr_mensa[i].desc[j];
            }
        }
        else {
            cout << "(non occupata)";
        }
        cout << endl;
    }
    return juj;
}

bool Mensa::occupa(char* id) {
    for(int i = 0; i < n_posti; i++) {
        if(this->arr_mensa[i].desc == id) {
            cout << "Gia presente" << endl;
            return false;
        }
        else {
            if(this->arr_mensa[i].occupata == false) {
                this->arr_mensa[i].occupata = true;
                this->arr_mensa[i].desc = id;
                return true;
            }
        }
    }
    cout << "mensa piena" << endl;
    return false;
}

bool Mensa::libera(int i) {
    if(i >= n_posti) {
        arr_mensa[i].occupata = false;
        strcpy(arr_mensa[i].desc, NULL);
        return true;
    }
    return false;
}

Mensa::~Mensa() {
    delete[] this->arr_mensa;
}

Mensa::Mensa(const Mensa& p){
    int l = 0;
    p.n_posti = n_posti;
    for (int i = 0; i < p.n_posti; i++) {
        p.arr_mensa[i].occupata = arr_mensa[i].occupata;
        while (p.arr_mensa[i].desc[l] != 0) {
            p.arr_mensa[i].desc[l] = arr_mensa[i].desc[l];
            l++;
        }
    }
}
bool Mensa::occupaGruppo(char *id, int n) {
    int counter = 0;
    for(int i = 0; i < n_posti; i++) {
        if(this->arr_mensa[i].desc == id) {
            cout << "Gia presente" << endl;
            return false;
        }
        else {
            if(this->arr_mensa[i].occupata == false) {
                ++counter;
            }else {
                counter = 0;
            }
            if(counter == n) {
                for(int j = n-1; j >= 0; j--) {
                    arr_mensa[j].occupata = true;
                    strcpy(arr_mensa[j].desc, id);
                }
                return true;
            }
        }
    }
    cout << "mensa piena" << endl;
    return false;
}

bool Mensa::ordina() {
    bool valore_transizione_bool;
    char* valore_transizione_char;
    for(int i = 0; i < n_posti - 1; i++) {
        if (strcmp(arr_mensa[i].desc, arr_mensa[i+1].desc) > 0 || arr_mensa[i+1].desc == nullptr) {

            valore_transizione_bool = arr_mensa[i].occupata;
            strcpy(valore_transizione_char, arr_mensa[i].desc);

            arr_mensa[i].occupata = arr_mensa[i+1].occupata;
            strcpy(arr_mensa[i].desc, arr_mensa[i+1].desc);


            arr_mensa[i+1].occupata = valore_transizione_bool;
            strcpy(arr_mensa[i + 1].desc, valore_transizione_char);

            i = 0;
        }
    }
    return true;
}
