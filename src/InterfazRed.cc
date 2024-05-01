

#include "../include/InterfazRed.h"
#include "../include/BaseDeDatosLibros.h"
#include "../include/BaseDeDatosSanciones.h"
#include "../include/BaseDeDatosPrestamos.h"
#include <exception>
#include <iostream>
#include <limits>

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

  bool RegistrarSancion(BaseDeDatosSanciones& base_datos, std::string& username) noexcept {
    std::cout << "Introduzca fecha límite de sanción: ";
    Fecha fecha_limite;
    // OJO: no estamos haciendo comprobaciones
    std::cin >> fecha_limite;
    std::cout << "Introduzca motivo de la sanción: ";
    std::string motivo{};
    std::cin >> motivo;
    return base_datos.AñadirSancion(username, fecha_limite, motivo);
  }

  std::string CrearMotivo() {
    std::string motivo;
    std::cout << "Introduce el motivo de la sanción: ";
    std::cin.ignore(); // Limpiamos la entrada estandar
    std::getline(std::cin, motivo); // Lee la linea completa, con espacios incluidos
    return motivo;
  }

  void MostrarSanciones(const std::vector<Sancion>& sanciones) {
    for (auto sancion: sanciones) {
      Fecha fecha_limite = sancion.getLimiteSancion();
      std::cout << "Fecha de expiración: " << fecha_limite.Anio() << "/";
      std::cout << fecha_limite.Mes() << "/" << fecha_limite.Dia();
      std::cout << " | Motivo: " << sancion.getMotivo() << "\n";
    }
    return;
  }

  Fecha CrearFecha() {
    std::cout << "Indique el año: ";
    std::string anio;
    std::cin >> anio;
    unsigned int anio_num = 0;
    try {
      anio_num = std::stoi(anio); // No se comprueba si el numero es negativo, ni si el año es anterior al actual
    } catch (std::exception& except) {
      throw std::logic_error("El año introducido no es un numero");
    }
    std::cout << "Indique el mes: ";
    std::string mes;
    std::cin >> mes;
    unsigned int mes_num = 0;
    try {
      mes_num = std::stoi(mes); // No se comprueba si el numero es negativo, ni si es un mes adecuado (1-12 / 0-11).
    } catch (std::exception& except) {
      throw std::logic_error("El mes introducido no es un numero");
    }
    std::cout << "Indique el día: ";
    std::string dia;
    std::cin >> dia;
    unsigned int dia_num = 0;
    try {
      dia_num = std::stoi(dia); // No se comprueba si es un día de mes válido
    } catch (std::exception& except) {
      throw std::logic_error("El dia introducido no es un numero");
    }

    return Fecha(anio_num, mes_num, dia_num);
  }

  std::string SeleccionarUsuario() {
    BaseDeDatosUsuarios base_de_datos;
    std::cout << "Usuarios del sistema:\n";
    base_de_datos.MostrarUsuarios();
    EstadoUsuario usr_state = EstadoUsuario::NONE;
    std::string user_name;
    while (usr_state == EstadoUsuario::NONE) {
      std::cout << "Seleccione un usuario: ";
      std::cin >> user_name;
      if (!base_de_datos.ExisteUsuario(user_name)) {
        std::cout << "El usuario '" << user_name << "' no existe.\n";
        std::cout << "¿Quiere volver a intentarlo? (s/n): ";
        std::string option;
        std::cin >>  option;
        if (option == "n") {
          usr_state = EstadoUsuario::NOEXISTE;
        }
      } else {
        usr_state = EstadoUsuario::EXISTE;
      }
    }
    if (usr_state == EstadoUsuario::EXISTE) {
      return user_name;
    }
    return std::string(); // Devuelve un string vacío
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
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
    (void)usr;
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
        try {
          BaseDeDatosLibros baseDatosLibros;
          const std::map<unsigned int, std::tuple<Libro, Biblioteca, bool>>& libros = baseDatosLibros.getLibros();

          std::cout << "Libros disponibles:\n";
          for (const auto& book_entry : libros) {
              if (std::get<2>(book_entry.second)) {
                const Libro& libro = std::get<0>(book_entry.second);
                std::cout << libro.getTitulo() << " - " << libro.getAutor() << " (" << libro.getAnioPublicacion() << ")\n";
              }
          }
        } catch (const std::exception& e) {
          std::cerr << "Error: " << e.what() << std::endl;
        }
      break;
        case 3:
          try {
            BaseDeDatosSanciones baseDatosSanciones;
            BaseDeDatosLibros libros;
            auto sanciones{baseDatosSanciones.ObtenerSanciones(usr)};
            if (!sanciones.empty()) {
              std::cerr << "Sanción detectada. No puede realizar préstamos. Detalles:\n";
              MostrarSanciones(sanciones);
            } else {

              std::cout << "Quiere mostrar la lista de libros disponibles? (s/n): ";
              std::string opcion_libros_disponibles ;
              std::cin >> opcion_libros_disponibles;
              if (opcion_libros_disponibles != "n") {
                libros.MostrarLibros();
              }

              int idLibro;
              std::string idLibroStr;
              bool libro_disponible = false;
              do {
                std::cout << "Ingrese el ID del libro que desea reservar (-1 para cancelar): ";
                std::cin >> idLibroStr;
                try {
                  idLibro = std::stoi(idLibroStr);
                } catch (std::exception& except) {
                  std::cout << "Debes introducir un numero entero\n";
                  continue;
                }
                libro_disponible = libros.consultarDisponibilidad(idLibro);
                if (!libro_disponible && idLibro != -1) {
                  std::cout << "No existe el libro con id o no está disponible " << idLibroStr << "\n";
                }
              } while (!libro_disponible && idLibro != -1);

              if (idLibro == -1) {
                std::cout << "Reserva cancelada\n";
                break;
              }

              // Realizar el préstamo
              BaseDeDatosPrestamos baseDatosPrestamos;
              baseDatosPrestamos.SolicitarPrestamo(usr, idLibro);
            }
        } catch (std::exception const& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
        break;
        default:
          std::cout << "Opcion no válida\n\n";
      }
    }
  }

  void MenuBibliotecario(const std::string& usr) {
    (void)usr;
    bool flag = true;
    while (flag) {
      std::cout << "1. Salir.\n";
      std::cout << "2. Aplicar Sanción\n";
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
        try {
          std::string usuario_a_sancionar = SeleccionarUsuario();
          if (usuario_a_sancionar.empty()) {
            return; // No se seleccionó ningún usuario
          }

          Fecha limite_sancion = CrearFecha();
          std::string motivo = CrearMotivo();

          BaseDeDatosSanciones datos_sanciones;
          if (!datos_sanciones.AñadirSancion(usuario_a_sancionar, limite_sancion, motivo)) {
            std::cout << "No se pudo crear la sanción\n";
          } else {
            std::cout << "La sanción se creó con éxito\n";
          }

          
        } catch (const std::exception& e) {
          std::cerr << "Error: " << e.what() << std::endl;
        }
      break;
        default:
          std::cout << "Opcion no válida\n\n";
      }
    }
  }
}
