#include "../include/Sancion.h"

Sancion::Sancion(const std::string& fecha) {
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
  os << "/" << sancion.limiteSancion_.Anio();
  return os;
}

std::istream& operator>>(std::istream& is, Sancion& sancion) {
  std::string aux;
  is >> aux;
  std::stringstream{sancion.EliminarBarras(aux)} >> sancion.limiteSancion_;
  return is;
}