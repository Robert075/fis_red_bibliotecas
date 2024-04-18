#ifndef BASE_DE_DATOS_SANCIONES_H
#define BASE_DE_DATOS_SANCIONES_H

#include <string>
#include <map>
#include <set>

#include "Sancion.h"

class BaseDeDatosSanciones {
  public:
    BaseDeDatosSanciones();
    ~BaseDeDatosSanciones();

    /**
     * @brief Devuelve un puntero constante a la sanción que tiene un usuario. Si no tiene, devuelve nullptr
     */
    Sancion const* ObtenerSanciones(const std::string& usr) const;

    bool TieneSanciones(const std::string& usr) const;

    inline void AñadirSancion(const std::string&, const Sancion&);


  private:
    std::map<std::string, Sancion> sanciones_;
    bool modified_;
};






#endif
