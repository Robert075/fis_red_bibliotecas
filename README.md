# Desarrollo ágil - Fundamentos de Igneniería del software. Red de bibliotecas en C++
## Compilación
Para compilar el Código utilice: 
```bash
make
```
## Ejecución
Para ejecutar el programa utilice, sin argumentos:
```bash
./biblioteca
```

## Estructura de los datos
Para el correcto menanejo de los datos de la biblioteca se están utilizando diferentes ficheros de texto plano, que serán leidos en le programa según sean necesitados.
A continuación se exponen los diferentes datos que se manejan (expandible en el futuro)

- [Usuarios y contraseñas](#usuarios-y-contraseñas)
- [Usuarios y Roles](#usuarios-y-roles)
- [Catálogo General de libros](#catálogo-general-de-libros)

### Usuarios y contraseñas

En el archivo [usr_pass.txt](information/usr_pass.txt) están guardados los nombres de usuario y contraseñas de los usuarios registrados en la red.
Está planteado para que se guarden todas las entradas de todos los usuarios, sin distinguir entre roles (a excepción del rol de administrador, que tiene un [fichero](information/admin_passwd.txt) separado, pero que por el momento no se está utilizando).
Contiene, por cada línea de texto, un usuario y su contraseña de la forma:
{usuario} {contraseña}

### Usuarios y roles

En el archivo [usr_roles.txt](information/usr_roles.txt) están guradados los nombres de usuario y roles de todos los usuarios registrados en la red (a excepción del rol de administrador, que tiene un [fichero](information/usr_roles.txt) separado, pero que por el momento no se está utilizando).
Contiene, por cada línea de texto, un usuario y su rol de la forma:
{usuario} {rol}

### Catálogo General de libros

En el archivo [library_catalog.txt](information/library_catalog.txt) están guardados las entradas referentes a libros. La información relevante es:

- Título del libro
- Autor
- Año de publicación
- Identificador único del libro en la red
- Nombre de la biblioteca a la que pertenece
- Disponibilidad del libro (en binario, 1 {está disponible} o 0 {no está disponible})

Si una biblioteca tiene, por ejemplo, 4 entradas de un mismo libro, aparecerán 4 entradas exactamente iguales, excepto por el identificador y el valor de disponibilidad. Esto permite que cada libro sea una entidad diferenciable, lo que habilita en un futuro que se pueda añadir más informacion relativa a un libro, o modificarla.





