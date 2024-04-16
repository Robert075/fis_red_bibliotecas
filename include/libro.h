#ifndef LIBRO_H
#define LIBRO_H

#include <exception>
#include <istream>
#include <stdexcept>
#include <string>

class Libro {
private:
    std::string EliminarEspacios(const std::string&) const;
    std::string AgregarEspacios(const std::string&) const;
    std::string titulo;
    std::string autor;
    int añoPublicacion;
    bool disponible;

public:
    Libro() = default;
    Libro(const std::string& titulo, const std::string& autor, int añoPublicacion, bool disponible);
    friend std::istream& operator>>(std::istream& is, Libro& libro) {
      std::string temp_str;
      is >> temp_str;
      libro.titulo = libro.AgregarEspacios(temp_str);
      is >> temp_str;
      libro.autor = libro.AgregarEspacios(temp_str);
      is >> temp_str;
      try {
        libro.añoPublicacion = std::stoi(temp_str);
        is >> temp_str;
        libro.disponible = std::stoi(temp_str);
      } catch (std::exception& exception) {
        throw std::logic_error("Excepcion al leer año de publicacion de libro. NaN");
      }
      return is;
    }

    friend std::ostream& operator<<(std::ostream& os, const Libro& libro) {
      os << libro.EliminarEspacios(libro.getTitulo()) << " ";
      os << libro.EliminarEspacios(libro.getAutor()) << " ";
      os << libro.getAñoPublicacion() << " ";
      os << libro.getDisponibilidad();
      return os;
    }
    std::string getTitulo() const;
    std::string getAutor() const;
    int getAñoPublicacion() const;
    bool getDisponibilidad() const;
};

#endif // LIBRO_H
