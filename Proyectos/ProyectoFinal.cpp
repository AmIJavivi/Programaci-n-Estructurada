#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

// Definición de estructuras

struct Alumno {
    string nombre;
    int edad;
    vector<int> calificaciones;
};

struct Maestro {
    string nombre;
    string area;
};

struct Carrera {
    string nombre;
    vector<Alumno> alumnos;
    vector<Maestro> maestros;
};

// Inclusión de las librerías de funciones
#include "LibreriaAlumnos.cpp"
#include "LibreriaCarreras.cpp"
#include "LibreriaMaestros.cpp"
#include "LibreriaRelaciones.cpp"

int main() {
    // Lectura de datos desde archivos
    vector<Alumno> alumnos = leerAlumnos();
    vector<Maestro> maestros = leerMaestros();
    vector<Carrera> carreras = leerCarreras();

    char opcion, seleccion;

    // Menú principal
    do {
        system("cls");
        cout << "********** MENU **********\n\n";
        cout << "[1. Alumnos   ]\t\t\t[!Nota: Para que los datos se capturen correctamente]  \n";
        cout << "[2. Maestros  ]\t\t\t[es necesario cerrar el programa con la opcion 0    ]\n";
        cout << "[3. Carreras  ]\n";
        cout << "[R. Relaciones]\n";
        cout << "[0. Salir   ]\n\n";
        cout << "[Seleccion]: ";
        cin >> opcion;
        switch (opcion) {
            case '1':
                do{
                    system("pause");
                    system("cls");
                    cout << "*****Sub-menu alumnos*****\n\n";
                    cout << "[1. Mostrar alumnos]\n";
                    cout << "[2. Agregar alumno ]\n";
                    cout << "[3. Editar alumno  ]\n";
                    cout << "[4. Eliminar alumno]\n";
                    cout << "[5. Calificar      ]\n";
                    cout << "[6. Mostrar calif. ]\n\n";
                    cout << "[0. Volver]\n\n";
                    cout << "[Seleccion]: ";
                    cin>>seleccion;

                    switch (seleccion){
                        case '1':
                            mostrarAlumnos(alumnos);  // Llama a la función para mostrar los alumnos
                            break;
                        case '2':
                            agregarAlumno(alumnos);  // Llama a la función para agregar un alumno
                            break;
                        case '3':
                            mostrarAlumnos(alumnos);
                            editarAlumnos(alumnos);  // Llama a la función para editar un alumno
                            break;
                        case '4':
                            mostrarAlumnos(alumnos);
                            eliminarAlumnos(alumnos);  // Llama a la función para eliminar un alumno
                            break;
                        case '5':
                            mostrarAlumnos(alumnos);
                            capturarCalificaciones(alumnos);  // Llama a la función para capturar calificaciones de un alumno
                            break;
                        case '6':
                            mostrarAlumnos(alumnos);
                            mostrarCalificaciones(alumnos);  // Llama a la función para mostrar las calificaciones de un alumno
                        case '0':
                            break;
                        default:
                            fflush(stdin);
                            break;
                    }
                }while(seleccion != '0');
                break;
            case '2':
                do{
                    system("pause");
                    system("cls");
                    cout << "*****Sub-menu maestros*****\n\n";
                    cout << "[1. Mostrar maestros]\n";
                    cout << "[2. Agregar maestro ]\n";
                    cout << "[3. Editar maestro  ]\n";
                    cout << "[4. Eliminar maestro]\n\n";
                    cout << "[0. Volver]\n\n";
                    cout << "[Seleccion]: ";
                    cin>>seleccion;

                    switch (seleccion){
                        case '1':
                            mostrarMaestros(maestros);  // Llama a la función para mostrar los maestros
                            break;
                        case '2':
                            agregarMaestro(maestros);  // Llama a la función para agregar un maestro
                            break;
                        case '3':
                            mostrarMaestros(maestros);
                            editarMaestros(maestros);  // Llama a la función para editar un maestro
                            break;
                        case '4':
                            mostrarMaestros(maestros);
                            eliminarMaestros(maestros);  // Llama a la función para eliminar un maestro
                            break;
                        case '0':
                            break;
                        default:
                            fflush(stdin);
                            break;
                    }
                }while(seleccion != '0');
                break;
            case '3':
                do{
                    system("pause");
                    system("cls");
                    cout << "*****Sub-menu carreras*****\n\n";
                    cout << "[1. Mostrar carreras]\n";
                    cout << "[2. Agregar carrera ]\n";
                    cout << "[3. Editar carrera  ]\n";
                    cout << "[4. Eliminar carrera]\n\n";
                    cout << "[0. Volver]\n\n";
                    cout << "[Seleccion]: ";
                    cin>>seleccion;

                    switch (seleccion){
                        case '1':
                            mostrarCarreras(carreras);  // Llama a la función para mostrar las carreras
                            break;
                        case '2':
                            agregarCarrera(carreras);  // Llama a la función para agregar una carrera
                            break;
                        case '3':
                            mostrarCarreras(carreras);
                            editarCarrera(carreras);  // Llama a la función para editar una carrera
                            break;
                        case '4':
                            mostrarCarreras(carreras);
                            eliminarCarrera(carreras);  // Llama a la función para eliminar una carrera
                            break;
                        case '0':
                            break;
                        default:
                            fflush(stdin);
                            break;
                    }
                }while(seleccion != '0');
                break;
            case 'r':
            case 'R':
                leerRelacionesAlumnos(carreras, alumnos);  // Llama a la función para leer las relaciones de alumnos desde un archivo
                leerRelacionesMaestros(carreras, maestros);  // Llama a la función para leer las relaciones de maestros desde un archivo
                do{
                    system("pause");
                    system("cls");
                    cout << "*****Sub-menu relaciones*****\n\n";
                    cout << "[1. Asignar alumnos a carrera  ]\n";
                    cout << "[2. Mostrar alumnos por carrera]\n";
                    cout << "[3. Asignar maestro a carrera  ]\n";
                    cout << "[4. Mostrar alumnos por maestro]\n\n";
                    cout << "[0. Volver]\n\n";
                    cout << "[Seleccion]: ";
                    cin>>seleccion;

                    switch (seleccion) {
                        case '1':
                            mostrarCarreras(carreras);
                            mostrarAlumnos(alumnos);
                            agregarAlumnoACarrera(carreras, alumnos);  // Llama a la función para asignar un alumno a una carrera
                            break;
                        case '2':
                            mostrarCarreras(carreras);
                            mostrarAlumnosPorCarrera(carreras);  // Llama a la función para mostrar los alumnos por carrera
                            break;
                        case '3':
                            mostrarCarreras(carreras);
                            mostrarMaestros(maestros);
                            asignarMaestroACarrera(carreras, maestros);  // Llama a la función para asignar un maestro a una carrera
                            break;
                        case '4':
                            mostrarMaestros(maestros);
                            mostrarAlumnosPorMaestro(carreras);  // Llama a la función para mostrar los alumnos por maestro
                            break;
                        case '0':
                            break;
                        default:
                            fflush(stdin);
                            break;
                    }
                }while(seleccion != '0');
                break;
            case '0':
                cout << "Saliendo del programa.\n";
                break;
            default:
                cout << "Opción inválida.\n";
                fflush(stdin);
                break;
        }
        system("pause");
    } while (opcion != '0');

    // Escritura de datos en archivos
    escribirAlumnos(alumnos);
    escribirMaestros(maestros);
    escribirCarreras(carreras);
    escribirRelaciones(carreras);

    return 0;
}
