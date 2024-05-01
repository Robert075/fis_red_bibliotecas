#ifndef PRESTAMO_H
#define PRESTAMO_H

#include "Fecha.h"
#include <iostream>
#include <string>
class Prestamo {
  public:
    Prestamo() = default;
    Prestamo(const std::string& usuario, Fecha fecha_inicio, Fecha fecha_fin, unsigned int libro_id): 
    usuario_(usuario), fecha_inicio_(fecha_inicio), fecha_fin_(fecha_fin), libro_id_(libro_id) {};

    friend std::istream& operator>>(std::istream& is, Prestamo& prestamo) {
      is >> prestamo.usuario_ >> prestamo.libro_id_ >> prestamo.fecha_inicio_ >> prestamo.fecha_fin_;
      return is;
    }

    friend std::ostream& operator<<(std::ostream& os, const Prestamo& prestamo) {
      os << prestamo.usuario_ << " " << prestamo.libro_id_ << " " << prestamo.fecha_inicio_ << " " << prestamo.fecha_fin_;
      return os;
    }


    bool operator<(const Prestamo& prestamo) const { return this->fecha_inicio_ < prestamo.fecha_inicio_; }
    std::string Usuario() const { return this->usuario_; }
    Fecha FechaInicio() const { return this->fecha_inicio_; }
    Fecha FechaFin() const { return this->fecha_fin_; }
    unsigned int LibroID() const { return this->libro_id_; }

    void SetUsuario(const std::string& usuario) { this->usuario_ = usuario; }
    void SetFechaInicio(const Fecha& fechaInicio) { this->fecha_inicio_ = fechaInicio; }
    void SetFechaFin(const Fecha& fechaFin) { this->fecha_fin_ = fechaFin; }
    void SetLibroID(unsigned int libroID) { this->libro_id_ = libroID; }
    
  private:
    std::string usuario_;
    Fecha fecha_inicio_;
    Fecha fecha_fin_;
    unsigned int libro_id_;

};



#endif
