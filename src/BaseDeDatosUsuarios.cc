

#include "../include/BaseDeDatosUsuarios.h"
#include <fstream>
#include <stdexcept>
#include <iostream>


BaseDeDatosUsuarios::BaseDeDatosUsuarios() {
  std::ifstream password_file("information/usr_pass.txt");
  if (!password_file) {
    // No hay usuarios registrados en la base de datos
    return;
  }
  std::ifstream roles_file("information/usr_roles.txt");
  if (!roles_file) {
    // Si uno de los archivos incluye información y el otro no, hubo un error y los datos no se pueden recuperar
    throw std::logic_error("El archivo usr_roles.txt fue modificado");
  }
  std::string user_passwd_name;
  std::string user_passwd;
  std::string user_role_name;
  std::string user_role;
  while (password_file >> user_passwd_name >> user_passwd &&
      roles_file >> user_role_name >> user_role) {
    if (user_passwd_name != user_role_name) {
      throw std::logic_error("Los archivos usr_roles.txt o usr_pass.txt fueron modificados. No contienen la misma información.");
    }
    // passwd_file contiene usuario - contraseña, mientras que roles_file contiene usuario - rol
    Usuario user(user_passwd_name, user_passwd, this->ConvertirRol(user_role));
    this->usuarios_[user_passwd_name] = user;
  }
 
  this->modified_ = false;
  return;
}

BaseDeDatosUsuarios::~BaseDeDatosUsuarios() {
  if (!this->modified_) {
    return;
  }
  // Vaciamos la información de los archivos antes de escribir la nueva información
  std::ofstream password_file("information/usr_pass.txt", std::ios::trunc);
  std::ofstream roles_file("information/usr_roles.txt", std::ios::trunc);

  for (auto& user: this->usuarios_) {
    password_file << user.second.getNombreUsuario() << " ";
    roles_file << user.second.getNombreUsuario() << " ";
    password_file << user.second.getContrasena() << "\n";
    roles_file << this->ConvertirRol(user.second.getRol()) << "\n";
  }
}

Role BaseDeDatosUsuarios::ObtenerRol(const std::string& user_name) const {
  return this->usuarios_.at(user_name).getRol();
}

Role BaseDeDatosUsuarios::ConvertirRol(const std::string& role) const {
  if (role == "user") {
    return Role::USER;
  }
  if (role == "librarian") {
    return Role::LIBRARIAN;
  }
  return Role::ADMIN;
}

std::string BaseDeDatosUsuarios::ConvertirRol(Role role) const {
  std::string str_role;
  switch (role) {
    case Role::USER:
      str_role = "user";
      break;
    case Role::LIBRARIAN:
      str_role = "librarian";
      break;
    case Role::ADMIN:
      str_role = "admin";
      break;
  }
  return str_role;
}

bool BaseDeDatosUsuarios::ExisteUsuario(const std::string& username) const {
  if (this->usuarios_.find(username) != this->usuarios_.end()) {
    return true;
  }
  return false;
}

bool BaseDeDatosUsuarios::IniciarSesion(const std::string& username, const std::string& passwd) const {
  if (!this->ExisteUsuario(username)) {
    return false;
  }
  const Usuario& user_credentials = this->usuarios_.at(username);
  if (user_credentials.getContrasena() == passwd) {
    return true;
  }
  return false;
}

bool BaseDeDatosUsuarios::RegistrarUsuario(const std::string& username, const std::string& passwd, Role rol) {
  if (this->ExisteUsuario(username)) {
    return false;
  }
  this->usuarios_[username] = Usuario(username, passwd, rol);
  this->modified_ = true;
  return true;
}

