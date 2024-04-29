#include "../include/BaseDeDatosPrestamos.h"
#include "../include/BaseDeDatosLibros.h"
#include "../include/Fecha.h"

#include <fstream>

BaseDeDatosPrestamos::BaseDeDatosPrestamos() {
  std::ifstream loan_file("../information/usr_loan.txt");
  if (!loan_file) {
    return; // No hay prestamos de ningun usuario
  }
  
  Prestamo read_loan;
  while (loan_file >> read_loan) {
    this->prestamos_[read_loan.Usuario()].insert(read_loan); 
  }
  this->modified_ = false;
  return;
  
}

BaseDeDatosPrestamos::~BaseDeDatosPrestamos() {
  if (!this->modified_) {
    return; // No se modificó. No hay que cambiar nada.
  }
  std::ofstream loan_file("../information/usr_loan.txt", std::ios::trunc);

  for (auto& loan_info: this->prestamos_) {
    for (auto& loan: this->prestamos_.at(loan_info.first)) {
      loan_file << loan << "\n";
    }
  }
}


const std::set<Prestamo>* BaseDeDatosPrestamos::ObtenerPrestamos(const std::string& usr) const {
  if (!this->TienePrestamos(usr)) {
    return nullptr;
  }
  return &this->prestamos_.at(usr);
}

bool BaseDeDatosPrestamos::SolicitarPrestamo(const std::string& nombreUsuario, unsigned int idLibro, BaseDeDatosLibros& baseDeDatosLibros) {

    // Verificar si el libro existe en la base de datos
    if (!baseDeDatosLibros.existeLibro(idLibro)) {
        std::cerr << "El libro con ID " << idLibro << " no existe en la base de datos." << std::endl;
        return false;
    }
    
    // Verificar la disponibilidad del libro
    bool disponible = baseDeDatosLibros.consultarDisponibilidad(idLibro);
    if (!disponible) {
        std::cerr << "El libro no está disponible para préstamo en este momento." << std::endl;
        return false;
    }

    // Obtener la fecha actual
    Fecha fechaInicio;

    // Calcular la fecha límite para el préstamo (por ejemplo, sumar 14 días a la fecha actual)
    Fecha fechaLimite = fechaInicio;
    fechaLimite.AgregarDias(14);

    Prestamo nuevoPrestamo;
    nuevoPrestamo.SetUsuario(nombreUsuario);
    nuevoPrestamo.SetLibroID(idLibro);
    nuevoPrestamo.SetFechaInicio(fechaInicio);
    nuevoPrestamo.SetFechaFin(fechaLimite);


    // Añadir el préstamo a la base de datos de préstamos
    AñadirPrestamo(nombreUsuario, nuevoPrestamo);

    // Actualizar la disponibilidad del libro en la base de datos de libros
    baseDeDatosLibros.actualizarDisponibilidad(idLibro, false);

    // Si el libro está disponible, procedemos a realizar el préstamo
    if (TienePrestamos(nombreUsuario) && !baseDeDatosLibros.consultarDisponibilidad(idLibro)) {
        std::cout << "El préstamo se realizó con éxito." << std::endl;
        return true;
    } else {
        std::cerr << "No se pudo realizar el préstamo." << std::endl;
        return false;
    }
}

bool BaseDeDatosPrestamos::TienePrestamos(const std::string& usr) const {
  if (this->prestamos_.find(usr) == this->prestamos_.end()) {
    return false;
  }
  return true;
}

inline void BaseDeDatosPrestamos::AñadirPrestamo(const std::string& usr, const Prestamo& prestamo) {
  this->prestamos_[usr].insert(prestamo);
  return;
}
