#ifndef PRESTAMO_H
#define PRESTAMO_H

#include "Fecha.h"
#include <iostream>
#include <string>
class Prestamo {
  public:
    Prestamo() = default;

    friend std::istream& operator>>(std::istream& is, Prestamo& prestamo) {
      is >> prestamo.usuario_ >> prestamo.libro_id_ >> prestamo.fecha_inicio_ >> prestamo.fecha_fin_;
      return is;
    }

    friend std::ostream& operator<<(std::ostream& os, const Prestamo& prestamo) {
      os << prestamo.usuario_ << prestamo.libro_id_ << prestamo.fecha_inicio_ << prestamo.fecha_fin_;
      return os;
    }


    bool operator<(const Prestamo& prestamo) const { return this->fecha_inicio_ < prestamo.fecha_inicio_; }
    std::string Usuario() const { return this->usuario_; }
    Fecha FechaInicio() const { return this->fecha_inicio_; }
    Fecha FechaFin() const { return this->fecha_fin_; }
    unsigned int LibroID() const { return this->libro_id_; }
    
  private:
    std::string usuario_;
    Fecha fecha_inicio_;
    Fecha fecha_fin_;
    unsigned int libro_id_;

};



#endif
