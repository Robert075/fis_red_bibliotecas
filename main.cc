#include <iostream>
#include <stdexcept>
#include "include/BaseDeDatosUsuarios.h"
#include "include/InterfazRed.h"


int main() {
  std::string username;
  Role usr_rol;
  {
    BaseDeDatosUsuarios base_datos_usr; // Cuando se destruya el objeto, se guardarán los datos modificados en el fichero correspondiente
    try {
      username = interfaz_red::PantallaInicio(base_datos_usr);
    } catch (std::logic_error& exception) {
      return 0; // Si hubo una exception es porque el usuario eligió la opción de salir
    }
    
    usr_rol = base_datos_usr.ObtenerRol(username);
    std::cout << "\n\nSE INICIÓ SESIÓN\n\n";
  }
   
  switch (usr_rol) {
    case Role::USER:
      interfaz_red::MenuUsuario(username);
      break;
    case Role::LIBRARIAN:
      std::cout << "librarian\n";
      // interfaz_red::MenuBibliotecario(username);
      break;
    case Role::ADMIN:
      std::cout << "admin";
      // interfaz_red::MenuAdministrador(username);
      break;
  }
  // do {
  //     std::cout << "\n=== Menú de Biblioteca ===" << std::endl;
  //     if (usuarioAutenticado) {
  //         std::cout << "1. Agregar libro al catálogo" << std::endl;
  //         std::cout << "2. Mostrar catálogo de libros" << std::endl;
  //     } else {
  //         std::cout << "1. Registrarse" << std::endl;
  //         std::cout << "2. Iniciar sesión" << std::endl;
  //     }
  //     std::cout << "3. Salir" << std::endl;
  //     std::cout << "Ingrese su opción: ";
  //     std::cin >> opcion;
  //
  //     switch (opcion) {
  //         case 1: {
  //             if (usuarioAutenticado) {
  //                 std::string titulo, autor;
  //                 int anio;
  //                 std::cout << "Ingrese el título del libro: ";
  //                 std::cin.ignore(); // Ignorar el salto de línea pendiente en el buffer
  //                 std::getline(std::cin, titulo);
  //                 std::cout << "Ingrese el autor del libro: ";
  //                 std::getline(std::cin, autor);
  //                 std::cout << "Ingrese el año de publicación del libro: ";
  //                 std::cin >> anio;
  //
  //                 Libro libro(titulo, autor, anio);
  //                 biblioteca.agregarLibro(libro);
  //             } else {
  //                 std::string nombreUsuario, contrasena, rol;
  //                 std::cin.ignore(); // Limpiar el buffer de entrada
  //                 std::cout << "Ingrese su nombre de usuario: ";
  //                 std::getline(std::cin, nombreUsuario);
  //                 std::cout << "Ingrese una contraseña: ";
  //                 std::getline(std::cin, contrasena);
  //                 std::cout << "Ingrese su rol: ";
  //                 std::getline(std::cin, rol);
  //                 
  //                 Usuario nuevoUsuario(nombreUsuario, contrasena, rol);
  //                 biblioteca.registrarUsuario(nuevoUsuario);
  //             }
  //             break;
  //         }
  //         case 2: {
  //             if (usuarioAutenticado) {
  //                 biblioteca.mostrarCatalogo();
  //             } else {
  //                 std::string nombreUsuario, contrasena;
  //                 std::cin.ignore(); // Limpiar el buffer de entrada
  //                 std::cout << "Ingrese su nombre de usuario: ";
  //                 std::getline(std::cin, nombreUsuario);
  //                 std::cout << "Ingrese su contraseña: ";
  //                 std::getline(std::cin, contrasena);
  //
  //                 if (biblioteca.iniciarSesion(nombreUsuario, contrasena)) {
  //                     usuarioAutenticado = true;
  //                 } else {
  //                     std::cout << "Inicio de sesión fallido." << std::endl;
  //                 }
  //             }
  //             break;
  //         }
  //         case 3: {
  //             std::cout << "Saliendo del programa..." << std::endl;
  //             break;
  //         }
  //         default:
  //             std::cout << "Opción inválida. Por favor, intente de nuevo." << std::endl;
  //             break;
  //     }
  // } while (opcion != 3);

  return 0;
}


