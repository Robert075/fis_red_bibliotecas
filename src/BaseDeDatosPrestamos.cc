#include "../include/BaseDeDatosPrestamos.h"
#include "../include/BaseDeDatosLibros.h"
#include "../include/Fecha.h"

#include <fstream>

BaseDeDatosPrestamos::BaseDeDatosPrestamos() {
  std::ifstream loan_file("information/usr_loan.txt");
  if (!loan_file) {
    return; // No hay prestamos de ningun usuario
  }
  
  Prestamo read_loan;
  while (loan_file >> read_loan) {
    this->prestamos_.insert(std::make_pair(read_loan.Usuario(), read_loan)); 
  }
  this->modified_ = false;
  return;
  
}

BaseDeDatosPrestamos::~BaseDeDatosPrestamos() {
  if (!this->modified_) {
    return; // No se modificó. No hay que cambiar nada.
  }
  std::ofstream loan_file("information/usr_loan.txt", std::ios::trunc);

  for (auto& loan: this->prestamos_) {
    loan_file << loan.second << "\n";
  }
}

std::vector<Prestamo> BaseDeDatosPrestamos::ObtenerPrestamos(const std::string& usr) const {
  if (!this->TienePrestamos(usr)) {
    return std::vector<Prestamo>(); // Devuelve un vector vacío
  }
  auto prestamo = this->prestamos_.find(usr);
  std::vector<Prestamo> lista_prestamos;
  while (prestamo->first == usr) {
    lista_prestamos.push_back(prestamo->second);
    prestamo++;
  }
  return lista_prestamos;
}

bool BaseDeDatosPrestamos::SolicitarPrestamo(const std::string& nombreUsuario, unsigned int idLibro) {
    BaseDeDatosLibros libros;
    // Verificar si el libro existe en la base de datos
    if (!libros.existeLibro(idLibro)) {
      std::cerr << "El libro con ID " << idLibro << " no existe en la base de datos." << std::endl;
      return false;
    }
    
    // Verificar la disponibilidad del libro
    bool disponible = libros.consultarDisponibilidad(idLibro);
    if (!disponible) {
      std::cerr << "El libro no está disponible para préstamo en este momento." << std::endl;
      return false;
    }

    // Obtener la fecha actual
    Fecha fechaInicio;

    // Calcular la fecha límite para el préstamo (por ejemplo, sumar 14 días a la fecha actual)
    Fecha fechaLimite = fechaInicio;
    fechaLimite.AgregarDias(14);

    Prestamo nuevoPrestamo(nombreUsuario, fechaInicio, fechaLimite, idLibro);

    // Añadir el préstamo a la base de datos de préstamos
    AñadirPrestamo(nombreUsuario, nuevoPrestamo);

    // Actualizar la disponibilidad del libro en la base de datos de libros
    libros.actualizarDisponibilidad(idLibro, !disponible);

    std::cout << "El préstamo se realizó con éxito." << std::endl;
    return true;
}

bool BaseDeDatosPrestamos::TienePrestamos(const std::string& usr) const {
  if (this->prestamos_.find(usr) == this->prestamos_.end()) {
    return false;
  }
  return true;
}

inline void BaseDeDatosPrestamos::AñadirPrestamo(const std::string& usr, const Prestamo& prestamo) {
  this->modified_ = true;
  this->prestamos_.insert(std::make_pair(usr, prestamo));
  return;
}
