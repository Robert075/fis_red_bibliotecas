#include "libro.h"

Libro::Libro(const std::string& titulo, const std::string& autor, int añoPublicacion)
    : titulo(titulo), autor(autor), añoPublicacion(añoPublicacion) {}

std::string Libro::getTitulo() const {
    return titulo;
}

std::string Libro::getAutor() const {
    return autor;
}

int Libro::getAñoPublicacion() const {
    return añoPublicacion;
}
