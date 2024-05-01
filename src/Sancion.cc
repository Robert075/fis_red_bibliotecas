#include "../include/Sancion.h"

Sancion::Sancion(const std::string& fecha, const int id, const std::string& motivo) :
  IDSancion_{id}, motivoSancion_{motivo} {
  std::stringstream stream{fecha};
  stream >> limiteSancion_;
}

std::ostream& operator<<(std::ostream& os, const Sancion& sancion) {
  os << sancion.limiteSancion_ << " " << sancion.getIDSancion();
  os << " " << sancion.getMotivo();
  return os;
}

std::istream& operator>>(std::istream& is, Sancion& sancion) {

  is >> sancion.limiteSancion_ >> sancion.IDSancion_;
  std::getline(is, sancion.motivoSancion_);
  if (sancion.motivoSancion_.empty()) {
    sancion.motivoSancion_ = kDefaultMotivo;
  }
  return is;
}