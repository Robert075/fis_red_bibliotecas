

#include "../include/Fecha.h"

#include <ctime>

Fecha::Fecha() {
  time_t tiempo_actual = time(nullptr);
  tm* fecha_actual = localtime(&tiempo_actual);

  this->dia_ = fecha_actual->tm_mday;
  this->mes_ = fecha_actual->tm_mon + 1; // Enero es 0
  this->anio_ = fecha_actual->tm_year + 1900; // tm_year devuelve el numero de años desde 1900
  return;
}

bool Fecha::operator<(const Fecha& fecha) const {
  if (this->anio_ < fecha.anio_) {
    return true;
  } else if (this->anio_ > fecha.anio_) {
    return false;
  }
  // Es el mismo año
  if (this->mes_ < fecha.mes_) {
    return true;
  } else if (this->mes_ > fecha.mes_) {
    return false;
  }
  if (this->dia_ < fecha.dia_) {
    return true;
  }
  return false;
}
