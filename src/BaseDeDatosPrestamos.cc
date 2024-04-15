

#include "../include/BaseDeDatosPrestamos.h"

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
