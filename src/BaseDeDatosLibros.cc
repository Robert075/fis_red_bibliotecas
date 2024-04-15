#include "../include/BaseDeDatosLibros.h"
#include <exception>
#include <fstream>
#include <stdexcept>


BaseDeDatosLibros::BaseDeDatosLibros() {
  std::fstream book_catalog("../information/library_catalog.txt");

  Libro libro;
  while (book_catalog >> libro) {
    std::string book_id_str;
    book_catalog >> book_id_str;
    unsigned int book_id;
    try {
      book_id = std::stoi(book_id_str);
    } catch (std::exception& exception) {
      throw std::logic_error("Excepción al leer el book_id. Nan");
    }
    std::string library_name;
    book_catalog >> library_name;
    this->libros_[book_id] = {libro, library_name};
  }
  this->modified_ = false;
}

BaseDeDatosLibros::~BaseDeDatosLibros() {
  if (!this->modified_) {
    return;
  }
  std::ofstream catalog("../information/library_catalog.txt", std::ios::trunc);
  for (auto& book_entry: this->libros_) {
    catalog << book_entry.second.first << " "; // Titulo, autor y fecha
    catalog << book_entry.first << " "; // Id de libro
    catalog << book_entry.second.second << "\n"; // Biblioteca
  }
}
