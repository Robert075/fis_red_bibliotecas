#ifndef SANCION_H
#define SANCION_H

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>

#include "Fecha.h"

class Sancion {
private:
    // Métodos privados
    std::string EliminarBarras(const std::string&) const;
    // Atributos privados
    Fecha limiteSancion_{};

public:
    Sancion() {}
    Sancion(const Fecha& fecha) : limiteSancion_{fecha} {}
    Sancion(const std::string& fecha);

    Fecha getLimiteSancion() const { return limiteSancion_; }
    
    friend std::ostream& operator<<(std::ostream& os, const Sancion& sancion);
    friend std::istream& operator>>(std::istream& is, Sancion& sancion);
};

#endif // SANCION_H
