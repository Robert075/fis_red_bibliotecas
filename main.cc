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
      interfaz_red::MenuBibliotecario(username);
      break;
    case Role::ADMIN:
      std::cout << "admin";
      // interfaz_red::MenuAdministrador(username);
      break;
  }


  return 0;
}


