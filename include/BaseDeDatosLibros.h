#ifndef BASE_DE_DATOS_LIBROS_H
#define BASE_DE_DATOS_LIBROS_H

#include "libro.h"

#include <map>
#include <tuple>

typedef std::string Biblioteca;
class BaseDeDatosLibros {

  public:
  BaseDeDatosLibros();
  ~BaseDeDatosLibros();
  const std::map<unsigned int, std::tuple<Libro, Biblioteca, bool>>& getLibros() const;

  private:
    bool modified_;
    std::map<unsigned int, std::tuple<Libro, Biblioteca, bool>> libros_; // Guarda el libro, su bibliteca y si está disponible o no
};


#endif
