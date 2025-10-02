#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

// --------------------- Tablas (Structs) ---------------------
struct Autor {
    int id;
    string nombre;
    string nacionalidad;
};

struct Libro {
    int id;
    string titulo;
    string isbn;
    int anio;
    string editorial;
    string categoria;
    int id_autor; // FK
};

struct Estudiante {
    int id;
    string nombre;
    string grado;
    string carrera;
    string email;
};

struct Prestamo {
    int id;
    int id_libro;      // FK
    int id_estudiante; // FK
    string fecha_prestamo;
    string fecha_devolucion;
    bool activo;
};

// --------------------- Clase principal ---------------------
class BibliotecaDB {
public:
    vector<Autor> autores;
    vector<Libro> libros;
    vector<Estudiante> estudiantes;
    vector<Prestamo> prestamos;

    // Métodos CRUD principales
    void agregarAutor();
    void listarAutores();

    void agregarLibro();
    void listarLibros();

    void agregarEstudiante();
    void listarEstudiantes();

    void registrarPrestamo();
    void listarPrestamos();
    void buscarPrestamosPorEstudiante(int id_estudiante);

    // Persistencia
    void guardarDatos();
    void cargarDatos();
};

#endif
