// biblioteca.cc
#include "biblioteca.h"
#include <iostream>
#include <fstream>
#include <sstream>

std::vector<Libro> catalogo;

Libro::Libro(std::string t, std::string a, int año) : titulo(t), autor(a), año(año), prestado(false) {}

void cargarCatalogoDesdeArchivo(std::string nombreArchivo) {
  std::ifstream archivo(nombreArchivo);
  if (archivo.is_open()) {
    std::string linea;
    while (std::getline(archivo, linea)) {
      std::istringstream iss(linea);
      std::string titulo, autor, anio_str;
      if (std::getline(iss, titulo, ',') && std::getline(iss, autor, ',') && std::getline(iss, anio_str)) {
        int anio = std::stoi(anio_str);
        catalogo.push_back(Libro(titulo, autor, anio));
      }
    }
    archivo.close();
  } else {
    std::cerr << "Error al abrir el archivo de catálogo." << std::endl;
  }
}

void guardarCatalogoEnArchivo(std::string nombreArchivo) {
  std::ofstream archivo(nombreArchivo);
  if (archivo.is_open()) {
    for (const auto& libro : catalogo) {
      archivo << libro.titulo << "," << libro.autor << "," << libro.año << std::endl;
    }
    archivo.close();
  } else {
    std::cerr << "Error al abrir el archivo de catálogo." << std::endl;
  }
}

void agregarLibro(std::string titulo, std::string autor, int anio) {
  catalogo.push_back(Libro(titulo, autor, anio));
  std::cout << "Libro agregado al catálogo." << std::endl;
}

void mostrarCatalogo() {
  std::cout << "Catálogo de libros:" << std::endl;
  for (const auto& libro : catalogo) {
    std::cout << libro.titulo << " - " << libro.autor << " (" << libro.año << ")";
    if (libro.prestado)
      std::cout << " - Prestado";
    std::cout << std::endl;
  }
}

bool prestarLibro(std::string titulo) {
  for (auto& libro : catalogo) {
    if (libro.titulo == titulo && !libro.prestado) {
      libro.prestado = true;
      std::cout << "Libro prestado exitosamente." << std::endl;
      return true;
    }
  }
  std::cout << "El libro no está disponible para préstamo." << std::endl;
  return false;
}

bool devolverLibro(std::string titulo) {
  for (auto& libro : catalogo) {
    if (libro.titulo == titulo && libro.prestado) {
      libro.prestado = false;
      std::cout << "Libro devuelto exitosamente." << std::endl;
      return true;
    }
  }
  std::cout << "No se puede devolver el libro porque no estaba prestado." << std::endl;
  return false;
}
