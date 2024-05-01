#ifndef BASE_DE_DATOS_PRESTAMOS_H
#define BASE_DE_DATOS_PRESTAMOS_H

#include "Prestamo.h"
#include "BaseDeDatosLibros.h"
#include "libro.h"
#include "Fecha.h"
#include <map>
#include <string>
#include <set>


class BaseDeDatosPrestamos {
  public:
    BaseDeDatosPrestamos();
    ~BaseDeDatosPrestamos();

    
    /**
     * @brief Devuelve un puntero constante a los prestamos que tiene un usuario. Si no tiene prestamos, devuelve nullptr
     */
    std::vector<Prestamo> ObtenerPrestamos(const std::string& usr) const;


    bool TienePrestamos(const std::string& usr) const;

    inline void AñadirPrestamo(const std::string&, const Prestamo&);

    bool SolicitarPrestamo(const std::string& nombreUsuario, unsigned int idLibro);


  private:
    std::multimap<std::string, Prestamo> prestamos_;
    bool modified_;
};






#endif
