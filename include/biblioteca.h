#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include "usuario.h"
#include "libro.h"
#include <vector>
#include <fstream>
#include <iostream>

class Biblioteca {
private:
    std::vector<Usuario> usuarios;
    std::vector<Libro> catalogo;

public:
    void registrarUsuario(const Usuario& usuario);
    bool iniciarSesion(const std::string& nombreUsuario, const std::string& contrasena);
    void agregarLibro(const Libro& libro);
    void mostrarCatalogo() const;
    void cargarUsuariosDesdeArchivo(const std::string& nombreArchivo);
    void guardarUsuariosEnArchivo(const std::string& nombreArchivo) const;
    void cargarCatalogoDesdeArchivo(const std::string& nombreArchivo);
    void guardarCatalogoEnArchivo(const std::string& nombreArchivo) const;
};

#endif // BIBLIOTECA_H
