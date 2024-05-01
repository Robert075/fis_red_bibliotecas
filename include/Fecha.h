#ifndef FECHA_H
#define FECHA_H

#include <fstream>
#include <random>
#include <sstream>

class Fecha {
  public:
    /**
     * @brief Constructor por defecto. Se crea con la fecha actual.
     */
    Fecha();

    Fecha(unsigned int anio, unsigned int mes, unsigned int dia) : 
      anio_(anio), mes_(mes), dia_(dia) {};

    friend std::istream& operator>>(std::istream& is, Fecha& fecha) {
      std::string fecha_completa;
      is >> fecha_completa;
      std::stringstream stream_fecha{fecha.EliminarBarras(fecha_completa)};
      stream_fecha >> fecha.dia_ >> fecha.mes_ >> fecha.anio_;
      return is;
    }

    friend std::ostream& operator<<(std::ostream& os, const Fecha& fecha) {
      os << fecha.dia_ << "/" << fecha.mes_ << "/" << fecha.anio_;
      return os;
    }
    
    /**
     * @brief Se ordenan de más antiguo a más reciente
     */
    bool operator<(const Fecha&) const;
    unsigned int Anio() const { return this->anio_; }
    unsigned int Mes() const { return this->mes_; }
    unsigned int Dia() const { return this->dia_; }

    void AgregarDias(unsigned int dias);
    unsigned int DiasEnMes(unsigned int anio, unsigned int mes) const;
    bool EsBisiesto(unsigned int anio) const;
  
  private:
    std::string EliminarBarras(const std::string&) const;
    unsigned int anio_;
    unsigned int mes_;
    unsigned int dia_;
};




#endif
