#ifndef BASE_DE_DATOS_LIBROS_H
#define BASE_DE_DATOS_LIBROS_H

#include "libro.h"

#include <map>

typedef std::string Biblioteca;
class BaseDeDatosLibros {

  BaseDeDatosLibros();
  ~BaseDeDatosLibros();

  private:
    bool modified_;
    std::map<unsigned int, std::pair<Libro, Biblioteca>> libros_;
};


#endif
