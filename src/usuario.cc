#include "../include/usuario.h"
#include <iostream>
Usuario::Usuario(const std::string& nombreUsuario, const std::string& contrasena, Role rol)
    : nombreUsuario_(nombreUsuario), contrasena_(contrasena), rol_(rol) {};

Usuario::Usuario(const Usuario& usuario) {
  this->rol_ = usuario.rol_;
  this->contrasena_ = usuario.contrasena_;
  this->nombreUsuario_ = usuario.nombreUsuario_;
  return;
}

std::string Usuario::getNombreUsuario() const {
  return nombreUsuario_;
}

std::string Usuario::getContrasena() const {
  return contrasena_;
}

Role Usuario::getRol() const {
  return rol_;
}

Usuario& Usuario::operator=(const Usuario& user) {
  this->rol_ = user.rol_;
  this->contrasena_ = user.contrasena_;
  this->nombreUsuario_ = user.nombreUsuario_;
  return *this;
}
