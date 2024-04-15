#ifndef USUARIO_H
#define USUARIO_H

#include <string>

#include "Role.h"


class Usuario {
private:
  std::string nombreUsuario_;
  std::string contrasena_;
  Role rol_;

public:
  Usuario() = default;
  Usuario(const std::string& nombreUsuario, const std::string& contrasena, Role rol);
  Usuario(const Usuario&);
  Usuario& operator=(const Usuario&);
  std::string getNombreUsuario() const;
  std::string getContrasena() const;
  Role getRol() const;
};

#endif // USUARIO_H

