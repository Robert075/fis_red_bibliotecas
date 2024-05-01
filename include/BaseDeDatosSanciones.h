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
    std::vector<Sancion> ObtenerSanciones(const std::string& usr) const;

    inline bool TieneSanciones(const std::string& usr) const;

    /**
     * @brief Añade una sanción relacionada con un usuario específico. Siempre se podrá añadir la sanción
     * @return True, siempre.
    */
    bool AñadirSancion(const std::string& usr, const Fecha& fecha, const std::string& motivo);

  private:
    int GenerarID() { return newest_id_++; } // OJO: estamos modificando newest_id
    std::multimap<std::string, Sancion> sanciones_;
    bool modified_;
    int newest_id_;
};






#endif
