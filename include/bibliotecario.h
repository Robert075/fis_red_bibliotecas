#include <iostream>
#include "Role.h"

class Bibliotecario {
  private:
    std::string nombre_bibliotecario_;
    std::string contrasena_;
    Role rol_;
  public:
    Bibliotecario(){};
    Bibliotecario(const std::string nombre, const std::string clave, Role rol);
    Bibliotecario(const Bibliotecario& t);
    std::string Nombre() const;
    std::string Contrasena() const;
    Role Rol() const;

};
