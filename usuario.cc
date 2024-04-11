// usuario.cc
#include "usuario.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <map.h>

std::map<std::string, std::string> usuarios;

void registrarUsuario(std::string username, std::string password) {
  usuarios[username] = password;
  std::cout << "Usuario registrado exitosamente." << std::endl;
}

bool iniciarSesion(std::string username, std::string password) {
  if (usuarios.find(username) != usuarios.end() && usuarios[username] == password) {
    std::cout << "Inicio de sesión exitoso. ¡Bienvenido, " << username << "!" << std::endl;
    return true;
  } else {
    std::cout << "Nombre de usuario o contraseña incorrectos." << std::endl;
    return false;
  }
}

void cargarUsuariosDesdeArchivo(std::string nombreArchivo) {
  std::ifstream archivo(nombreArchivo);
  if (archivo.is_open()) {
    std::string linea;
    while (std::getline(archivo, linea)) {
      std::istringstream iss(linea);
      std::string username, password;
      if (std::getline(iss, username, ',') && std::getline(iss, password)) {
        usuarios[username] = password;
      }
    }
    archivo.close();
  } else {
    std::cerr << "Error al abrir el archivo de usuarios." << std::endl;
  }
}

void guardarUsuariosEnArchivo(std::string nombreArchivo) {
  std::ofstream archivo(nombreArchivo);
  if (archivo.is_open()) {
    for (const auto& usuario : usuarios) {
      archivo << usuario.first << "," << usuario.second << std::endl;
    }
    archivo.close();
  } else {
    std::cerr << "Error al abrir el archivo de usuarios." << std::endl;
  }
}

void mostrarMenu() {
  // Aquí puedes implementar el menú principal después del inicio de sesión exitoso
}
