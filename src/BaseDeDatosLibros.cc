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
