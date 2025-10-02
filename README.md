# Reto-3.-Diseno-de-base-de-datos-Rafi-Ruiz
Este proyecto implementa un sistema de gestión de biblioteca escolar en C++ con CRUD completo, manejo de préstamos y persistencia en archivos CSV.

🛠 Requisitos

Compilador de C++ compatible con C++11 o superior (g++ recomendado)

Sistema operativo: Windows, Linux o MacOS

Archivos CSV de datos iniciales (autores.txt, libros.txt, estudiantes.txt, prestamos.txt) en la misma carpeta que los archivos .cpp

💻 Cómo compilar

Abre la terminal o consola en la carpeta del proyecto y ejecuta:

g++ main.cpp Biblioteca.cpp -o biblioteca


Esto generará un ejecutable llamado biblioteca (Linux/Mac) o biblioteca.exe (Windows).

🚀 Cómo ejecutar

En la misma terminal:

./biblioteca   # Linux/Mac
biblioteca.exe # Windows


Se mostrará un menú interactivo con las siguientes opciones:

--- Menu Biblioteca ---
1. Agregar Autor
2. Listar Autores
3. Agregar Libro
4. Listar Libros
5. Agregar Estudiante
6. Listar Estudiantes
7. Registrar Prestamo
8. Listar Prestamos
9. Buscar Prestamos por Estudiante
10. Guardar Datos
0. Salir

📌 Uso rápido

Agregar / Listar: Permite manejar Autores, Libros, Estudiantes y Préstamos.

Registrar Préstamo: Solo permite prestar libros que estén disponibles.

Buscar Préstamos por Estudiante: Muestra todos los préstamos de un estudiante usando su ID.

Guardar Datos: Persiste todos los cambios en los archivos CSV para que estén disponibles en la próxima ejecución.

✅ Notas importantes

Antes de ejecutar por primera vez, asegúrate de que los archivos CSV existan y tengan datos de ejemplo.

Todos los datos modificados se guardan en los archivos CSV.

La aplicación valida ID duplicados y libros no disponibles al registrar préstamos.
