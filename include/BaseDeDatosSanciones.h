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

    // inline bool AñadirSancion(const std::string&, const Sancion&); // mejor usar el otro método
    bool AñadirSancion(const std::string& usr, const Fecha& fecha, const std::string& motivo);

  private:
    int GenerarID() { return newest_id_++; } // OJO: estamos modificando newest_id
    std::map<std::string, Sancion> sanciones_;
    bool modified_;
    int newest_id_;
};






#endif
