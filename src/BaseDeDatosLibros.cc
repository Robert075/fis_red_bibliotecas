#include "../include/BaseDeDatosLibros.h"
#include <exception>
#include <fstream>
#include <stdexcept>

BaseDeDatosLibros::BaseDeDatosLibros() {
    std::string filename = "information/library_catalog.txt";
    std::ifstream book_catalog(filename);
    if (!book_catalog) {
      throw std::runtime_error("No se pudo abrir el archivo del catálogo de libros: " + filename);
    }

    Libro libro;
    while (book_catalog >> libro) {
        std::string book_id_str;
        book_catalog >> book_id_str;
        unsigned int book_id;
        try {
            book_id = std::stoi(book_id_str);
        } catch (std::exception& exception) {
            throw std::logic_error("Excepción al leer el book_id. Nan -> " + book_id_str);
        }
        std::string library_name;
        book_catalog >> library_name;
        bool disponible;
        book_catalog >> disponible;

        this->libros_[book_id] = {libro, library_name, disponible};
    }
    this->modified_ = false;
}

const std::map<unsigned int, std::tuple<Libro, Biblioteca, bool>>& BaseDeDatosLibros::getLibros() const {
  return libros_;
}

bool BaseDeDatosLibros::consultarDisponibilidad(unsigned int idLibro) const{
    auto it = libros_.find(idLibro); // Buscar el libro por su ID
    if (it != libros_.end()) { // Si se encontró el libro
        const auto& libroInfo = it->second;
        bool disponible = std::get<2>(libroInfo); 
        // Obtener la disponibilidad del libro
        return disponible;
    } else {
        return false; // El libro no está en la base de datos
    }
}

bool BaseDeDatosLibros::existeLibro(unsigned int idLibro) const {
    // Buscar el libro por su ID
    auto it = libros_.find(idLibro);
    // Verificar si se encontró el libro
    if (it != libros_.end()) {
        return true; // El libro existe
    } else {
        return false; // El libro no existe
    }
}

BaseDeDatosLibros::~BaseDeDatosLibros() {
    if (!this->modified_) {
        return;
    }
    std::ofstream catalog("../information/library_catalog.txt", std::ios::trunc);
    for (const auto& book_entry : this->libros_) {
        const Libro& libro = std::get<0>(book_entry.second);
        catalog << libro << " "; // Titulo, autor y fecha
        catalog << book_entry.first << " "; // Id de libro
        catalog << std::get<1>(book_entry.second) << " "; // Biblioteca
        catalog << std::get<2>(book_entry.second) << "\n"; // Disponibilidad
    }
}

void BaseDeDatosLibros::actualizarDisponibilidad(unsigned int idLibro, bool nuevaDisponibilidad) {
    // Buscar el libro por su ID
    auto it = libros_.find(idLibro);
    // Verificar si se encontró el libro
    if (it != libros_.end()) {
        // Modificar la disponibilidad del libro
        std::get<2>(it->second) = nuevaDisponibilidad;
        // Indicar que la base de datos ha sido modificada
        this->modified_ = true;
    }
}
