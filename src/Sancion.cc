#include "../include/Sancion.h"

Sancion::Sancion(const std::string& fecha, const int id, const std::string& motivo) :
  IDSancion_{id}, motivoSancion_{motivo} {
  std::stringstream stream{EliminarBarras(fecha)};
  stream >> limiteSancion_;
}

std::string Sancion::EliminarBarras(const std::string& text) const {
  std::string new_str = text;
  for (auto& character: new_str) {
    if (character == '/') {
      character = ' ';
    }
  }
  return new_str;
}

std::ostream& operator<<(std::ostream& os, const Sancion& sancion) {
  os << sancion.limiteSancion_.Dia() << "/" << sancion.limiteSancion_.Mes();
  os << "/" << sancion.limiteSancion_.Anio() << " " << sancion.getIDSancion();
  os << " " << sancion.getMotivo();
  return os;
}

std::istream& operator>>(std::istream& is, Sancion& sancion) {
  std::string aux;
  std::getline(is, aux);
  std::stringstream line{sancion.EliminarBarras(aux)};
  line >> sancion.limiteSancion_ >> sancion.IDSancion_;
  if (!(line >> sancion.motivoSancion_)) {
    sancion.motivoSancion_ = kDefaultMotivo;
  }
  return is;
}