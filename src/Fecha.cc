

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

void Fecha::AgregarDias(unsigned int dias) {
    // Crear un objeto de fecha para la fecha actual
    Fecha fechaActual(*this);

    // Variable para llevar el conteo de los días agregados
    unsigned int diasAgregados = 0;

    while (diasAgregados < dias) {
        // Obtener la cantidad de días restantes en el mes actual
        unsigned int diasRestantesMes = DiasEnMes(fechaActual.Anio(), fechaActual.Mes()) - fechaActual.Dia();

        // Si los días restantes en el mes actual son suficientes para completar los días requeridos,
        // simplemente agregamos los días y salimos del bucle
        if (diasRestantesMes >= (dias - diasAgregados)) {
            fechaActual.dia_ += (dias - diasAgregados);
            break;
        } else {
            // Si no son suficientes, agregamos los días restantes del mes actual
            fechaActual.dia_ += diasRestantesMes;
            diasAgregados += diasRestantesMes;

            // Avanzamos al siguiente mes
            if (fechaActual.mes_ < 12) {
                fechaActual.mes_++;
            } else {
                fechaActual.mes_ = 1;
                fechaActual.anio_++;
            }

            // Reiniciamos el día al comienzo del mes
            fechaActual.dia_ = 1;
        }
    }

    // Actualizamos la fecha original con la nueva fecha calculada
    *this = fechaActual;
}

unsigned int Fecha::DiasEnMes(unsigned int anio, unsigned int mes) const {
    // Febrero
    if (mes == 2) {
        // Si el año es bisiesto, febrero tiene 29 días, de lo contrario tiene 28
        return EsBisiesto(anio) ? 29 : 28;
    }
    // Meses con 30 días
    else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        return 30;
    }
    // Meses con 31 días
    return 31;
}

bool Fecha::EsBisiesto(unsigned int anio) const {
    // Un año bisiesto es divisible por 4 y no es divisible por 100, excepto si es divisible por 400
    return (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
}

std::string Fecha::EliminarBarras(const std::string& text) const {
  std::string new_str = text;
  for (auto& character: new_str) {
    if (character == '/') {
      character = ' ';
    }
  }
  return new_str;
}
