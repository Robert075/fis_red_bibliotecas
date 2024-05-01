#ifndef SANCION_H
#define SANCION_H

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>

#include "Fecha.h"

static const std::string kDefaultMotivo{"No especificado"};

class Sancion {
private:
    // Atributos privados
    Fecha limiteSancion_{};
    int IDSancion_{};
    std::string motivoSancion_{};

public:
    Sancion() {}
    Sancion(const Fecha& fecha, const int id, const std::string& motivo = kDefaultMotivo) : 
        limiteSancion_{fecha}, IDSancion_{id}, motivoSancion_{motivo} {}
    Sancion(const std::string& fecha, const int id, const std::string& motivo = kDefaultMotivo);

    Fecha getLimiteSancion() const { return limiteSancion_; }
    int getIDSancion() const { return IDSancion_; }
    std::string const& getMotivo() const { return motivoSancion_; }
    
    friend std::ostream& operator<<(std::ostream& os, const Sancion& sancion);
    friend std::istream& operator>>(std::istream& is, Sancion& sancion);
};

#endif // SANCION_H
