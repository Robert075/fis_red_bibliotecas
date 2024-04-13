#ifndef USUARIO_H
#define USUARIO_H

#include <string>

class Usuario {
private:
    std::string nombreUsuario;
    std::string contrasena;
    std::string rol;

public:
    Usuario(const std::string& nombreUsuario, const std::string& contrasena, const std::string& rol);
    std::string getNombreUsuario() const;
    std::string getContrasena() const;
    std::string getRol() const;
};

#endif // USUARIO_H

