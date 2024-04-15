#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include "usuario.h"
#include "libro.h"
#include <vector>
#include <fstream>
#include <iostream>

class Biblioteca {
private:
    std::vector<Libro> catalogo;

public:
    void agregarLibro(const Libro& libro);
    void mostrarCatalogo() const;
};

#endif // BIBLIOTECA_H
