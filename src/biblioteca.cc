#include "biblioteca.h"

void Biblioteca::registrarUsuario(const Usuario& usuario) {
    bool usuarioExiste = false;
    for (const Usuario& u : usuarios) {
        if (u.getNombreUsuario() == usuario.getNombreUsuario()) {
            usuarioExiste = true;
            break;
        }
    }
    if (usuarioExiste) {
        std::cout << "El usuario ya está registrado." << std::endl;
    } else {
        usuarios.push_back(usuario);
        std::cout << "Usuario registrado exitosamente." << std::endl;
        guardarUsuariosEnArchivo("usuarios.txt");
    }
}

bool Biblioteca::iniciarSesion(const std::string& nombreUsuario, const std::string& contraseña) {
    for (const Usuario& usuario : usuarios) {
        if (usuario.getNombreUsuario() == nombreUsuario && usuario.getContrasena() == contraseña) {
            std::cout << "Inicio de sesión exitoso.\n";
            return true;
        }
    }
    std::cout << "Nombre de usuario o contraseña incorrectos.\n";
    return false;
}

void Biblioteca::agregarLibro(const Libro& libro) {
    bool libroExiste = false;
    for (const Libro& l : catalogo) {
        if (l.getTitulo() == libro.getTitulo() && l.getAutor() == libro.getAutor()) {
          libroExiste = true;
          break;
        }
    }
    if (libroExiste) {
      std::cout << "El libro ya existe en el catálogo." << std::endl;
    } else {
      catalogo.push_back(libro);
      std::cout << "Libro agregado al catálogo." << std::endl;
      guardarCatalogoEnArchivo("catalogo.txt"); // Guardar el catálogo actualizado
    }
}


void Biblioteca::mostrarCatalogo() const {
    std::cout << "Catálogo de libros:\n";
    for (const Libro& libro : catalogo) {
        std::cout << "Título: " << libro.getTitulo() << ", Autor: " << libro.getAutor() 
                  << ", Año de publicación: " << libro.getAñoPublicacion() << "\n";
    }
}

void Biblioteca::cargarUsuariosDesdeArchivo(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    if (!archivo) {
        std::cerr << "Error al abrir el archivo " << nombreArchivo << std::endl;
        return;
    }

    std::string nombreUsuario, contrasena, rol;
    while (archivo >> nombreUsuario >> contrasena >> rol) {
        usuarios.push_back(Usuario(nombreUsuario, contrasena, rol));
    }
    archivo.close();
}

void Biblioteca::guardarUsuariosEnArchivo(const std::string& nombreArchivo) const {
    std::ofstream archivo(nombreArchivo, std::ofstream::app); // Abrir en modo de anexar
    if (!archivo) {
        std::cerr << "Error al abrir el archivo " << nombreArchivo << " para escritura." << std::endl;
        return;
    }

    for (const Usuario& usuario : usuarios) {
        archivo << usuario.getNombreUsuario() << " " << usuario.getContrasena() << " " << usuario.getRol() << std::endl;
    }
    archivo.close();
}

void Biblioteca::guardarCatalogoEnArchivo(const std::string& nombreArchivo) const {
    std::ofstream archivo(nombreArchivo, std::ofstream::app); // Abrir en modo de anexar
    if (!archivo) {
        std::cerr << "Error al abrir el archivo " << nombreArchivo << " para escritura." << std::endl;
        return;
    }

    for (const Libro& libro : catalogo) {
        archivo << libro.getTitulo() << "," << libro.getAutor() << "," << libro.getAñoPublicacion() << std::endl;
    }

    archivo.close();
}



void Biblioteca::cargarCatalogoDesdeArchivo(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    if (!archivo) {
        std::cerr << "Error al abrir el archivo " << nombreArchivo << std::endl;
        return;
    }

    std::string titulo, autor;
    int año;
    while (archivo >> titulo >> autor >> año) {
        catalogo.push_back(Libro(titulo, autor, año));
    }
    archivo.close();
}
