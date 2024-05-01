

#include "../include/BaseDeDatosSanciones.h"

#include <fstream>

BaseDeDatosSanciones::BaseDeDatosSanciones() {
  std::ifstream sanction_file("information/usr_sanctions.txt");
  if (!sanction_file) {
    return; // No hay prestamos de ningun usuario
  }
  
  Sancion sanction;
  std::string username;
  while (sanction_file >> username >> sanction) {
    this->sanciones_.insert(std::make_pair(username, sanction));
    if (sanction.getIDSancion() > newest_id_) { newest_id_ = sanction.getIDSancion(); }
  }
  this->modified_ = false;
  return;
}

BaseDeDatosSanciones::~BaseDeDatosSanciones() {
  if (!this->modified_) {
    return; // No se modificó. No hay que cambiar nada.
  }
  std::ofstream sanction_file("information/usr_sanctions.txt", std::ios::trunc);

  for (auto& sanction_info: this->sanciones_) {
    sanction_file << sanction_info.first << " " << sanction_info.second << "\n";
  }
}

std::vector<Sancion> BaseDeDatosSanciones::ObtenerSanciones(const std::string& usr) const {
  if (!this->TieneSanciones(usr)) {
    return std::vector<Sancion>(); // Devuelve un vector vacío
  }
  auto sancion = this->sanciones_.find(usr);
  std::vector<Sancion> lista_sanciones;
  while (sancion->first == usr) {
    lista_sanciones.push_back(sancion->second);
    sancion++;
  }
  return lista_sanciones;
}

bool BaseDeDatosSanciones::TieneSanciones(const std::string& usr) const {
  return (this->sanciones_.find(usr) != this->sanciones_.end());
}

// inline bool BaseDeDatosSanciones::AñadirSancion(const std::string& usr, const Sancion& sancion) {
//   this->sanciones_.insert(std::make_pair(usr, sancion));
//   return;
// }

bool BaseDeDatosSanciones::AñadirSancion(const std::string& usr, const Fecha& fecha, const std::string& motivo) {
  int id = GenerarID();
  sanciones_.insert(std::make_pair(usr, Sancion(fecha, id, motivo)));
  this->modified_ = true;
  return true;
}
