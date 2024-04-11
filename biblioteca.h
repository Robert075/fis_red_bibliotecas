// biblioteca.h
#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <vector>
#include <string>

class Libro {
public:
  std::string titulo;
  std::string autor;
  int año;
  bool prestado;

  Libro(std::string t, std::string a, int an);

};

void cargarCatalogoDesdeArchivo(std::string nombreArchivo);
void guardarCatalogoEnArchivo(std::string nombreArchivo);
void agregarLibro(std::string titulo, std::string autor, int anio);
void mostrarCatalogo();
bool prestarLibro(std::string titulo);
bool devolverLibro(std::string titulo);

#endif
