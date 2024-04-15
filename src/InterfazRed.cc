

#include "../include/InterfazRed.h"
#include <exception>
#include <iostream>

namespace interfaz_red {
  bool IniciarSesion(BaseDeDatosUsuarios& base_datos, std::string& username) noexcept {
    std::cout << "Introduce tu nombre de usuario: ";
    std::cin >> username;
    std::cout << "Introduce la contraseña: ";
    std::string passwd;
    std::cin >> passwd;
    return base_datos.IniciarSesion(username, passwd);
  }

  bool RegistrarUsuario(BaseDeDatosUsuarios& base_datos, std::string& username) noexcept {
    std::cout << "Introduce el nombre de usuario: ";
    std::cin >> username;
    std::cout << "Introduce la contraseña: ";
    std::string passwd;
    std::cin >> passwd;
    return base_datos.RegistrarUsuario(username, passwd);
  }



  std::string PantallaInicio(BaseDeDatosUsuarios& base_datos) {
    bool autenticado = false; 
    std::string username;
    std::cout << "\n=== Bienvenido a la biblioteca ===\n" << std::endl;
    do {
      std::cout << "1. Registrarse\n";
      std::cout << "2. Iniciar sesión\n";
      std::cout << "3. Salir\n";
      std::cout << "Opcion: ";
      std::string str_opcion;
      std::cin >> str_opcion;
      int int_opcion;
      try {
        int_opcion = std::stoi(str_opcion);
      } catch (std::exception& exception) {
        std::cout << "Debes introducir un número.\n";
        continue;
      }
      switch (int_opcion) {
        case 1:
          autenticado = RegistrarUsuario(base_datos, username);
          if (!autenticado) {
            std::cout << "El usuario ya existe en el sistema\n";
          } else {
            std::cout << "Se ha creado el usuario con exito.\n";
          }
          break;
        case 2:
          autenticado = IniciarSesion(base_datos, username);
          if (!autenticado) {
            std::cout << "El usuario o la contraseña son incorrectos\n";
          } else {
            std::cout << "Se ha iniciado sesión con exito\n";
          }
          break;
        case 3:
          throw std::logic_error("Exit"); 
        default:
          std::cout << "Opcion invalida.\n\n";
      }
    } while (!autenticado);
    // El usuario está autenticado, sea por registrarse o por iniciar sesión
    return username;
  }


  void MenuUsuario(const std::string& usr) {
    bool flag = true;
    while (flag) {
      std::cout << "1. Salir.\n";
      std::cout << "2. Mostrar libros disponibles.\n";
      std::cout << "3. Realizar reserva.\n";
      std::cout << "Opcion: ";
      std::string opcion;
      std::cin >> opcion;
      int num_opcion;
      try {
        num_opcion = std::stoi(opcion);
      } catch (std::exception& exception) {
        std::cout << "Opcion no válida\n\n";
        continue;
      }
      switch (num_opcion) {
        case 1:
          return;
        case 2:
          // Mostrar libros disponibles
          break;
        case 3:
          // Realizar reserva
        default:
          std::cout << "Opcion no válida\n\n";
      }
    }
  }
}
