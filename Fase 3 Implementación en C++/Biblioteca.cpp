#include "Biblioteca.h"
#include <sstream>

// ------------------- CRUD Autor -------------------
void BibliotecaDB::agregarAutor() {
    Autor a;
    cout << "ID Autor: "; cin >> a.id;
    for (auto &autor : autores)
        if (autor.id == a.id) { cout << "Error: ID Autor ya existe.\n"; return; }
    cout << "Nombre: "; cin.ignore(); getline(cin, a.nombre);
    cout << "Nacionalidad: "; getline(cin, a.nacionalidad);
    autores.push_back(a);
}

void BibliotecaDB::listarAutores() {
    for (auto &a : autores)
        cout << a.id << " - " << a.nombre << " (" << a.nacionalidad << ")" << endl;
}

// ------------------- CRUD Libro -------------------
void BibliotecaDB::agregarLibro() {
    Libro l;
    cout << "ID Libro: "; cin >> l.id;
    for (auto &lib : libros)
        if (lib.id == l.id) { cout << "Error: ID Libro ya existe.\n"; return; }

    cout << "Titulo: "; cin.ignore(); getline(cin, l.titulo);
    cout << "ISBN: "; getline(cin, l.isbn);
    cout << "Año publicacion: "; cin >> l.anio; cin.ignore();
    cout << "Editorial: "; getline(cin, l.editorial);
    cout << "Categoria: "; getline(cin, l.categoria);
    cout << "ID Autor: "; cin >> l.id_autor;

    bool autorExiste = false;
    for (auto &a : autores)
        if (a.id == l.id_autor) { autorExiste = true; break; }
    if (!autorExiste) { cout << "Error: Autor no existe.\n"; return; }

    libros.push_back(l);
}

void BibliotecaDB::listarLibros() {
    for (auto &l : libros)
        cout << l.id << " - " << l.titulo << " (" << l.anio << ") - Autor ID: " << l.id_autor << endl;
}

// ------------------- CRUD Estudiante -------------------
void BibliotecaDB::agregarEstudiante() {
    Estudiante e;
    cout << "ID Estudiante: "; cin >> e.id;
    for (auto &est : estudiantes)
        if (est.id == e.id) { cout << "Error: ID Estudiante ya existe.\n"; return; }

    cout << "Nombre: "; cin.ignore(); getline(cin, e.nombre);
    cout << "Grado: "; getline(cin, e.grado);
    cout << "Carrera: "; getline(cin, e.carrera);
    cout << "Email: "; getline(cin, e.email);
    estudiantes.push_back(e);
}

void BibliotecaDB::listarEstudiantes() {
    for (auto &e : estudiantes)
        cout << e.id << " - " << e.nombre << " (" << e.carrera << ")" << endl;
}

// ------------------- CRUD Prestamo -------------------
void BibliotecaDB::registrarPrestamo() {
    Prestamo p;
    cout << "ID Prestamo: "; cin >> p.id;
    for (auto &pr : prestamos)
        if (pr.id == p.id) { cout << "Error: ID Prestamo ya existe.\n"; return; }

    cout << "ID Libro: "; cin >> p.id_libro;
    bool libroDisponible = true;
    for (auto &pr : prestamos)
        if (pr.id_libro == p.id_libro && pr.activo) { libroDisponible = false; break; }
    if (!libroDisponible) { cout << "Error: Libro actualmente prestado.\n"; return; }

    cout << "ID Estudiante: "; cin >> p.id_estudiante;
    cout << "Fecha Prestamo: "; cin.ignore(); getline(cin, p.fecha_prestamo);
    cout << "Fecha Devolucion (enter si no aplica): "; getline(cin, p.fecha_devolucion);
    p.activo = true;

    prestamos.push_back(p);
}

void BibliotecaDB::listarPrestamos() {
    for (auto &p : prestamos)
        cout << p.id << " - Libro " << p.id_libro
             << " prestado a Estudiante " << p.id_estudiante
             << " en " << p.fecha_prestamo
             << " Estado: " << (p.activo ? "Activo" : "Devuelto") << endl;
}

void BibliotecaDB::buscarPrestamosPorEstudiante(int id_estudiante) {
    cout << "Prestamos del Estudiante ID " << id_estudiante << ":\n";
    for (auto &p : prestamos)
        if (p.id_estudiante == id_estudiante)
            cout << "Prestamo " << p.id << " - Libro " << p.id_libro
                 << " Fecha: " << p.fecha_prestamo
                 << " Estado: " << (p.activo ? "Activo" : "Devuelto") << endl;
}

// ------------------- Guardar y cargar datos -------------------
void BibliotecaDB::guardarDatos() {
    ofstream fa("autores.txt");
    for (auto &a : autores) fa << a.id << "," << a.nombre << "," << a.nacionalidad << "\n";
    fa.close();

    ofstream fl("libros.txt");
    for (auto &l : libros) fl << l.id << "," << l.titulo << "," << l.isbn << "," << l.anio << "," 
                              << l.editorial << "," << l.categoria << "," << l.id_autor << "\n";
    fl.close();

    ofstream fe("estudiantes.txt");
    for (auto &e : estudiantes) fe << e.id << "," << e.nombre << "," << e.grado << "," 
                                    << e.carrera << "," << e.email << "\n";
    fe.close();

    ofstream fp("prestamos.txt");
    for (auto &p : prestamos) fp << p.id << "," << p.id_libro << "," << p.id_estudiante << "," 
                                  << p.fecha_prestamo << "," << p.fecha_devolucion << "," 
                                  << p.activo << "\n";
    fp.close();
}

void BibliotecaDB::cargarDatos() {
    string linea, token;
    // Autores
    ifstream fa("autores.txt");
    if (fa.is_open()) {
        while (getline(fa, linea)) {
            stringstream ss(linea);
            Autor a;
            getline(ss, token, ','); a.id = stoi(token);
            getline(ss, a.nombre, ',');
            getline(ss, a.nacionalidad, ',');
            autores.push_back(a);
        }
        fa.close();
    }

    // Libros
    ifstream fl("libros.txt");
    if (fl.is_open()) {
        while (getline(fl, linea)) {
            stringstream ss(linea);
            Libro l;
            getline(ss, token, ','); l.id = stoi(token);
            getline(ss, l.titulo, ',');
            getline(ss, l.isbn, ',');
            getline(ss, token, ','); l.anio = stoi(token);
            getline(ss, l.editorial, ',');
            getline(ss, l.categoria, ',');
            getline(ss, token, ','); l.id_autor = stoi(token);
            libros.push_back(l);
        }
        fl.close();
    }

    // Estudiantes
    ifstream fe("estudiantes.txt");
    if (fe.is_open()) {
        while (getline(fe, linea)) {
            stringstream ss(linea);
            Estudiante e;
            getline(ss, token, ','); e.id = stoi(token);
            getline(ss, e.nombre, ',');
            getline(ss, e.grado, ',');
            getline(ss, e.carrera, ',');
            getline(ss, e.email, ',');
            estudiantes.push_back(e);
        }
        fe.close();
    }

    // Prestamos
    ifstream fp("prestamos.txt");
    if (fp.is_open()) {
        while (getline(fp, linea)) {
            stringstream ss(linea);
            Prestamo p;
            getline(ss, token, ','); p.id = stoi(token);
            getline(ss, token, ','); p.id_libro = stoi(token);
            getline(ss, token, ','); p.id_estudiante = stoi(token);
            getline(ss, p.fecha_prestamo, ',');
            getline(ss, p.fecha_devolucion, ',');
            getline(ss, token, ','); p.activo = (token == "1" || token == "true");
            prestamos.push_back(p);
        }
        fp.close();
    }
}
