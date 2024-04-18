#include "../include/biblioteca.h"



void Biblioteca::agregarLibro(const Libro& libro) {
    bool libroExiste = false;
    for (const Libro& l : catalogo) {
        if (l.getTitulo() == libro.getTitulo() && l.getAutor() == libro.getAutor()) {
          libroExiste = true;
          break;
        }
    }
    if (libroExiste) {
      std::cout << "El libro ya existe en el catálogo." << std::endl;
    } else {
      catalogo.push_back(libro);
      std::cout << "Libro agregado al catálogo." << std::endl;
      // guardarCatalogoEnArchivo("catalogo.txt"); // Guardar el catálogo actualizado
    }
}


void Biblioteca::mostrarCatalogo() const {
    std::cout << "Catálogo de libros:\n";
    for (const Libro& libro : catalogo) {
        std::cout << "Título: " << libro.getTitulo() << ", Autor: " << libro.getAutor() 
                  << ", Año de publicación: " << libro.getAnoPublicacion() << "\n";
    }
}


