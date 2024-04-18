#include "../include/libro.h"


Libro::Libro(const std::string& titulo, const std::string& autor, int anioPublicacion)
    : titulo(titulo), autor(autor), anioPublicacion(anioPublicacion) {}



std::string Libro::getTitulo() const {
    return titulo;
}

std::string Libro::getAutor() const {
    return autor;
}


int Libro::getAnioPublicacion() const {
    return anioPublicacion;
}


std::string Libro::EliminarEspacios(const std::string& text) const {
  std::string new_str = text;
  for (unsigned int i{0}; i < new_str.size(); ++i) {
    if (new_str.at(i) == ' ') {
      new_str[i] = '_';
    }
  }
  return new_str;
}
std::string Libro::AgregarEspacios(const std::string& text) const {
  std::string new_str = text;
  for (unsigned int i{0}; i < new_str.size(); ++i) {
    if (new_str.at(i) == '_') {
      new_str[i] = ' ';
    }
  }
  return new_str;
}
