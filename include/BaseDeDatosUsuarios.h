#ifndef BASE_DE_DATOS_USUARIOS_H
#define BASE_DE_DATOS_USUARIOS_H

#include <map>
#include <string>

#include "usuario.h"
#include "Role.h"

struct InformacionUsario {
  std::string password_;
  Role role_;
};

enum class EstadoUsuario {
  EXISTE,
  NOEXISTE,
  NONE
};

class BaseDeDatosUsuarios {
  public:
    /**
     * @brief Constructor por defecto. Lee los archivos usr_pass.txt y usr_roles.txt para obtener los usuarios, las constraseñas y los roles
     */
    BaseDeDatosUsuarios();

    /**
     * @brief Destructor de la clase. Escribe los cambios realizados en los archivos correspondientes. Esto solo se hará si hubo algún cambio. En caso contrario, el destructor no hará nada.
     */
    ~BaseDeDatosUsuarios();

    /**
     * @brief Dado un nombre de usuario, devuelve su rol. Esta función no debe llamarse con un nombre de usuario que no existe
     */
    Role ObtenerRol(const std::string&) const;

    /**
     * @brief Convierte un std::string en un Role 
     */
    Role ConvertirRol(const std::string&) const;

    /**
     * @brief Convierte un Role en un std::string
     */
    std::string ConvertirRol(Role) const;

    /**
     * @brief Comprueba si el usuario y contraseña estan registrados
     * @return True si las credenciales están registradas. False si el usuario no existe o la contraseña es errónea
     */
    bool IniciarSesion(const std::string&, const std::string&) const;  

    /**
     * @brief Crea un nuevo usuario. Por defecto, el rol del usuario será "user"
     */
    bool RegistrarUsuario(const std::string&, const std::string&, Role rol = Role::USER);

     /**
      * @brief Muestra por pantalla la una lista de todos los usuarios con el rol "User" en el sistema
     */
    void MostrarUsuarios() const;

    /**
     * @brief Comprueba si un usuario existe en el sistema
     * @param usr_name El nombre del usuario a comprobar
     * @return True si existe. False en otro caso
    */
    bool ExisteUsuario(const std::string& usr_name) const;

  private:
    std::map<std::string, Usuario> usuarios_;
    bool modified_;
    
};

#endif
