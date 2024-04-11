// main.cc
#include <iostream>
#include "biblioteca.h"
#include "usuario.h"

using namespace std;

int main() {
  cargarUsuariosDesdeArchivo("usuarios.txt");
  cargarCatalogoDesdeArchivo("catalogo.txt");

  string username, password;
  cout << "Ingrese nombre de usuario: ";
  cin >> username;
  cout << "Ingrese contraseña: ";
  cin >> password;

  if (iniciarSesion(username, password)) {
    // Aquí iría el menú principal después del inicio de sesión exitoso
    mostrarMenu();
  } else {
    // Manejo de error o intento de inicio de sesión nuevamente
  }

  guardarUsuariosEnArchivo("usuarios.txt");
  guardarCatalogoEnArchivo("catalogo.txt");

  return 0;
}
