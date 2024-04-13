#include "usuario.h"

Usuario::Usuario(const std::string& nombreUsuario, const std::string& contrasena, const std::string& rol)
    : nombreUsuario(nombreUsuario), contrasena(contrasena), rol(rol) {}

std::string Usuario::getNombreUsuario() const {
    return nombreUsuario;
}

std::string Usuario::getContrasena() const {
    return contrasena;
}

std::string Usuario::getRol() const {
    return rol;
}
