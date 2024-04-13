#ifndef LIBRO_H
#define LIBRO_H

#include <string>

class Libro {
private:
    std::string titulo;
    std::string autor;
    int añoPublicacion;

public:
    Libro(const std::string& titulo, const std::string& autor, int añoPublicacion);
    std::string getTitulo() const;
    std::string getAutor() const;
    int getAñoPublicacion() const;
};

#endif // LIBRO_H
