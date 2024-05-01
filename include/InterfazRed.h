

#ifndef INTERFAZ_RED_H
#define INTERFAZ_RED_H

#include "BaseDeDatosUsuarios.h"
#include "../include/Sancion.h"
#include "Fecha.h"

namespace interfaz_red {
  /**
   * @brief Solicita al usuario su nombre de usuario y su contraseña.
   * @param username Es un valor de retorno. El nombre de usuario con el que se intentó iniciar sesión.
   * @return True si se inció sesión. False en otro caso
   */
  bool IniciarSesion(BaseDeDatosUsuarios& base_datos, std::string& username) noexcept;

  /**
   * @brief Solicita al usuario un nuevo nombre de usuario y contraseña y lo añade a la base de datos.
   * @param username Es un valor de retorno. El nobmre de usuario con el que se intentó iniciar sesión.
   * @return True si se registró el usuario. Falso si el nombre de usuario ya existe en el sistema.
   */
  bool RegistrarUsuario(BaseDeDatosUsuarios& base_datos, std::string& username) noexcept;

  /**
   * @brief Muestra la pantalla de inicio de sesión y permite al usuario iniciar sesión o registrarse. Si elige la opción de salir, se lanzará una excepción de tipo "std::logic_error". En cualquier otro caso, no se saldrá de la función hasta que se haya iniciado sesión o registrado.
   */
  std::string PantallaInicio(BaseDeDatosUsuarios& base_datos);

  /**
   * @brief Inicia el menú de opciones para un usuario con el rol "USER"
  */
  void MenuUsuario(const std::string&);

  /**
   * @brief Inicia el menú de opciones para un usuario con el rol "LIBRARIAN"
  */
  void MenuBibliotecario(const std::string&);

  /**
   * @brief Incia el menú de opciones para un usuario con el rol "ADMIN"
  */
  void MenuAdministrador(const std::string&);

  /**
   * @brief Permite seleccionar un usuario existente en la base de datos.
   * @return El nombre del usuario si existe y fue seleccionado. Si no seleccionó ninguno
   * devolverá un string vacío.
  */
  std::string SeleccionarUsuario();
  
  /**
   * @brief Solicita por linea de comandos una fecha.
   * @return Un objeto de tipo Fecha, con los valores especificados
  */
  Fecha CrearFecha();

  std::string CrearMotivo();

  /**
   * @brief Muestra las sanciones almacenadas en el vector, incluyendo los motivos y fechas de vencimiento
  */
  void MostrarSanciones(const std::vector<Sancion>& sanciones);
}

#endif
