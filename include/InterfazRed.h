

#ifndef INTERFAZ_RED_H
#define INTERFAZ_RED_H

#include "BaseDeDatosUsuarios.h"

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

  void MenuUsuario(const std::string&);

  void MenuBibliotecario(const std::string&);

  void MenuAdministrador(const std::string&);
}

#endif
