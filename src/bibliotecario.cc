#include "../include/bibliotecario.h"

Bibliotecario::Bibliotecario(const std::string nombre, const std::string clave, Role rol) {
  nombre_bibliotecario_ = nombre;
  contrasena_ = clave;
  rol_ = rol;
}

Bibliotecario::Bibliotecario(const Bibliotecario& t) {
  nombre_bibliotecario_ = t.Nombre();
  contrasena_ = t.Contrasena();
  rol_ = t.Rol();
}

std::string Bibliotecario::Nombre() const {
  return nombre_bibliotecario_;
}

std::string Bibliotecario::Contrasena() const {
  return contrasena_;
}

Role Bibliotecario::Rol() const {
  return rol_;
}
