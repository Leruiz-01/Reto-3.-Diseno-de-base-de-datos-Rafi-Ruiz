#include "Biblioteca.h"

int main() {
    BibliotecaDB db;
    db.cargarDatos(); // carga archivos existentes

    int opcion;
    do {
        cout << "\n--- Menu Biblioteca ---\n";
        cout << "1. Agregar Autor\n2. Listar Autores\n";
        cout << "3. Agregar Libro\n4. Listar Libros\n";
        cout << "5. Agregar Estudiante\n6. Listar Estudiantes\n";
        cout << "7. Registrar Prestamo\n8. Listar Prestamos\n";
        cout << "9. Buscar Prestamos por Estudiante\n";
        cout << "10. Guardar Datos\n0. Salir\n";
        cout << "Seleccione: ";
        cin >> opcion;

        switch (opcion) {
            case 1: db.agregarAutor(); break;
            case 2: db.listarAutores(); break;
            case 3: db.agregarLibro(); break;
            case 4: db.listarLibros(); break;
            case 5: db.agregarEstudiante(); break;
            case 6: db.listarEstudiantes(); break;
            case 7: db.registrarPrestamo(); break;
            case 8: db.listarPrestamos(); break;
            case 9: {
                int idEst; 
                cout << "Ingrese ID estudiante: "; cin >> idEst;
                db.buscarPrestamosPorEstudiante(idEst);
                break;
            }
            case 10: db.guardarDatos(); cout << "Datos guardados!\n"; break;
            case 0: cout << "Saliendo...\n"; break;
            default: cout << "Opcion invalida!\n"; break;
        }
    } while (opcion != 0);

    return 0;
}
