// usuario.h
#ifndef USUARIO_H
#define USUARIO_H

#include <string>

void registrarUsuario(std::string username, std::string password);
bool iniciarSesion(std::string username, std::string password);
void cargarUsuariosDesdeArchivo(std::string nombreArchivo);
void guardarUsuariosEnArchivo(std::string nombreArchivo);
void mostrarMenu();

#endif
