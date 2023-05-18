/**
 * Esta función guarda las relaciones entre los estudiantes y sus respectivas carreras en un archivo
 * CSV.
 * 
 * parametro: carreras. Un vector de objetos de tipo Carrera, que contiene información sobre diferentes
 * programas académicos o carreras. Cada objeto Carrera tiene un vector de objetos Alumno, que
 * representan a los estudiantes matriculados en ese programa. La función guarda las relaciones entre
 * cada estudiante y su programa en un archivo CSV llamado "RelacionesAlumnos
 */
void guardarRelacionesAlumnos(const vector<Carrera>& carreras) {
    ofstream archivo("RelacionesAlumnos.csv");
    if (archivo.is_open()) {
        for (const auto& carrera : carreras) {
            for (const auto& alumno : carrera.alumnos) {
                archivo << carrera.nombre << "," << alumno.nombre << "\n";
            }
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo RelacionesAlumnos.csv para guardar las relaciones de alumnos.\n";
    }
}

/**
 * La función guarda las relaciones entre profesores y carreras en un archivo CSV.
 * 
 * parametro: carreras. Un vector de objetos de tipo Carrera, que contiene información sobre diferentes
 * programas académicos o carreras. Cada objeto Carrera tiene un vector de objetos Maestro, que
 * representan a los profesores o instructores asociados a ese programa académico. La función guarda
 * las relaciones entre cada Carrera y sus Maestros asociados en un
 */
void guardarRelacionesMaestros(const vector<Carrera>& carreras) {
    ofstream archivo("RelacionesMaestros.csv");
    if (archivo.is_open()) {
        for (const auto& carrera : carreras) {
            for (const auto& maestro : carrera.maestros) {
                archivo << carrera.nombre << "," << maestro.nombre << "\n";
            }
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo RelacionesMaestros.csv para guardar las relaciones de maestros.\n";
    }
}

/**
 * La función lee un archivo CSV que contiene las relaciones entre los estudiantes y sus carreras y
 * actualiza las estructuras de datos correspondientes.
 * 
 * parametros:
 *  *carreras: Un vector de objetos de tipo Carrera, que representan diferentes programas
 *  *académicos o carreras.
 *  *alumnos: Un vector de objetos de tipo Alumno, que contiene información sobre los alumnos.
 * 
 * return: No se devuelve nada. La función es de tipo `void`, lo que significa que no devuelve ningún
 * valor.
 */
void leerRelacionesAlumnos(vector<Carrera>& carreras, const vector<Alumno>& alumnos) {
    ifstream archivo("RelacionesAlumnos.csv");
    if (archivo.is_open()) {
        string linea;
        while (getline(archivo, linea)) {
            stringstream ss(linea);
            string nombreCarrera, nombreAlumno;
            getline(ss, nombreCarrera, ',');
            getline(ss, nombreAlumno, ',');

            /* Esta línea de código usa el algoritmo `find_if` de la biblioteca `<algorithm>` para buscar un
            elemento en el vector `carreras`. Busca un elemento que satisfaga la condición especificada en la
            función lambda pasada como tercer argumento. En este caso, está buscando un elemento cuya
            variable miembro `nombre` coincida con la cadena `nombreAlumno` pasada como entrada. La palabra
            clave `auto` se utiliza para deducir automáticamente el tipo de iterador devuelto por `find_if`. */
            auto itCarrera = find_if(carreras.begin(), carreras.end(), [&nombreCarrera](const Carrera& carrera) {
                return carrera.nombre == nombreCarrera;
            });

            /* Este bloque de código busca un estudiante específico (identificado por su nombre) en el
            vector de estudiantes (`alumnos`) y lo agrega al vector de estudiantes en una carrera
            específica (`itCarrera->alumnos`). Primero verifica si la carrera existe en el vector de
            carreras (`carreras`) y luego busca al estudiante en el vector de estudiantes. Si se
            encuentran ambos, el alumno se suma al vector de alumnos de la carrera. */
            if (itCarrera != carreras.end()) {
                auto itAlumno = find_if(alumnos.begin(), alumnos.end(), [&nombreAlumno](const Alumno& alumno) {
                    return alumno.nombre == nombreAlumno;
                });

                if (itAlumno != alumnos.end()) {
                    itCarrera->alumnos.push_back(*itAlumno);
                }
            }
        }

        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo RelacionesAlumnos.csv para cargar las relaciones de alumnos.\n";
    }
}

/**
 * La función lee las relaciones entre profesores y carreras.
 * 
 * parametros:
 *      *carreras: Un vector de objetos de tipo "Carrera", que probablemente representa una colección
 *      *de programas académicos o especializaciones que ofrece una institución educativa.
 *      *maestros: Un vector de objetos de tipo Maestro, que probablemente contiene información sobre
 *      *los profesores, como sus nombres, identificaciones y áreas de especialización.
 */
void leerRelacionesMaestros(vector<Carrera>& carreras, const vector<Maestro>& maestros) {
    ifstream archivo("RelacionesMaestros.csv");
    if (archivo.is_open()) {
        string linea;
        while (getline(archivo, linea)) {
            stringstream ss(linea);
            string nombreCarrera, nombreMaestro;
            getline(ss, nombreCarrera, ',');
            getline(ss, nombreMaestro, ',');

            /* Esta línea de código usa el algoritmo `find_if` de la biblioteca `<algorithm>` para buscar un
            elemento en el vector `carreras`. Busca un elemento que satisfaga la condición especificada en la
            función lambda pasada como tercer argumento. En este caso, está buscando un elemento cuya
            variable miembro `nombre` coincida con la cadena `nombreAlumno` pasada como entrada. La palabra
            clave `auto` se utiliza para deducir automáticamente el tipo de iterador devuelto por `find_if`. */
            auto itCarrera = find_if(carreras.begin(), carreras.end(), [&nombreCarrera](const Carrera& carrera) {
                return carrera.nombre == nombreCarrera;
            });

            if (itCarrera != carreras.end()) {
                auto itMaestro = find_if(maestros.begin(), maestros.end(), [&nombreMaestro](const Maestro& maestro) {
                    return maestro.nombre == nombreMaestro;
                });

                if (itMaestro != maestros.end()) {
                    itCarrera->maestros.push_back(*itMaestro);
                }
            }
        }

        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo RelacionesMaestros.csv para cargar las relaciones de maestros.\n";
    }
}

/**
 * La función muestra una lista de estudiantes por su carrera respectiva.
 * 
 * parametro: carreras. Un vector de objetos de tipo "Carrera", que presumiblemente contiene información
 * sobre diferentes programas académicos o carreras.
 */
void mostrarAlumnosPorCarrera(const vector<Carrera>& carreras) {
    cout << "Ingrese el nombre de la carrera: ";
    string nombreCarrera;
    cin >> nombreCarrera;

    bool encontrada = false;
    for (const auto& carrera : carreras) {
        if (carrera.nombre == nombreCarrera) {
            cout << "\nAlumnos en la carrera " << carrera.nombre << ":\n";
            for (const auto& alumno : carrera.alumnos) {
                cout << "Nombre: " << alumno.nombre << "\n";
                cout << "Edad: " << alumno.edad << "\n\n";
            }
            encontrada = true;
            break;
        }
    }
    if (!encontrada) {
        cout << "Carrera no encontrada o sin alumnos asignados.\n";
    }
}

/**
 * La función muestra una lista de estudiantes agrupados por el nombre de su profesor, utilizando
 * información de un vector de objetos "Carrera".
 * 
 * parametro: carreras. Un vector de objetos de tipo "Carrera".
 */
void mostrarAlumnosPorMaestro(const vector<Carrera>& carreras) {
    cout << "Ingrese el nombre del maestro: ";
    string nombreMaestro;
    cin >> nombreMaestro;

    bool encontrado = false;
    for (const auto& carrera : carreras) {
        for (const auto& maestro : carrera.maestros) {
            if (maestro.nombre == nombreMaestro) {
                cout << "\nAlumnos asignados al maestro " << maestro.nombre << " en la carrera " << carrera.nombre << ":\n";
                for (const auto& alumno : carrera.alumnos) {
                    cout << "Nombre: " << alumno.nombre << "\n";
                    cout << "Edad: " << alumno.edad << "\n\n";
                }
                encontrado = true;
                break;
            }
        }
    }
    if (!encontrado) {
        cout << "Maestro no encontrado o sin alumnos asignados.\n";
    }
}

/**
 * La función escribe relaciones entre diferentes objetos "Carrera" en un vector.
 * 
 * parametro: carreras. Un vector de objetos de tipo Carrera, que probablemente representa una colección de
 * diferentes programas académicos o carreras.
 */
void escribirRelaciones(const vector<Carrera>& carreras) {
    ofstream archivo("Relaciones.csv");
    if (archivo.is_open()) {
        for (const auto& carrera : carreras) {
            for (const auto& alumno : carrera.alumnos) {
                archivo << carrera.nombre << "," << alumno.nombre << "\n";
            }
            for (const auto& maestro : carrera.maestros) {
                archivo << carrera.nombre << "," << maestro.nombre << "\n";
            }
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo Relaciones.csv para guardar las relaciones.\n";
    }
}

/**
 * Esta función agrega estudiantes a una carrera en un vector de carreras y un vector de estudiantes.
 * 
 * parametros: 
 *      *Carreras. Un vector de objetos de tipo Carrera, que representa una colección de programas
 *      *académicos o carreras.
 *      *alumnos. Un vector de objetos de tipo Alumno, que probablemente representa una colección de
 *      *registros del alumno.
 */
void agregarAlumnoACarrera(vector<Carrera>& carreras, const vector<Alumno>& alumnos) {
    cout << "Ingrese el nombre de la carrera: ";
    string nombreCarrera;
    cin >> nombreCarrera;

    bool encontrada = false;
    /* El código usa un bucle for basado en rango para iterar sobre cada elemento en el
    contenedor `carreras`. La variable de bucle `carrera` es una referencia a cada elemento del
    contenedor, lo que permite modificar los elementos si es necesario. */
    for (auto& carrera : carreras) {
        if (carrera.nombre == nombreCarrera) {
            cout << "Ingrese el nombre del alumno a agregar: ";
            string nombreAlumno;
            cin >> nombreAlumno;

            auto it = find_if(alumnos.begin(), alumnos.end(), [&nombreAlumno](const Alumno& alumno) {
                return alumno.nombre == nombreAlumno;
            });

            if (it != alumnos.end()) {
                carrera.alumnos.push_back(*it);
                encontrada = true;
                break;
            } else {
                cout << "Alumno no encontrado.\n";
            }
        }
    }

    /* El código está comprobando si una variable "encontrada" es verdadera o falsa. Si es cierto,
    imprime un mensaje "Estudiante agregado a la carrera" y llama a la función
    "guardarRelacionesEstudiantes" con un parámetro "carreras". Si es falso, imprime un mensaje
    "Carrera no encontrada". */
    if (encontrada) {
        cout << "Alumno agregado a la carrera.\n";
        guardarRelacionesAlumnos(carreras);
    } else {
        cout << "Carrera no encontrada.\n";
    }
}

/**
 * La función asigna un docente a una carrera en un vector de carreras y un vector de docentes.
 * 
 * parametros: 
 *      *carreras Vector de objetos de tipo Carrera, que representa una colección de programas
 *      *académicos o carreras que ofrece una institución educativa.
 *      *maestros Un vector de objetos Maestro, que probablemente contiene información sobre
 *      *diferentes maestros o profesores.
 */
void asignarMaestroACarrera(vector<Carrera>& carreras, const vector<Maestro>& maestros) {
    cout << "Ingrese el nombre de la carrera: ";
    string nombreCarrera;
    cin >> nombreCarrera;

    bool encontrada = false;
    /* El código usa un bucle for basado en rango para iterar sobre cada elemento en el
    contenedor `carreras`. La variable de bucle `carrera` es una referencia a cada elemento del
    contenedor, lo que permite modificar los elementos si es necesario. */
    for (auto& carrera : carreras) {
        if (carrera.nombre == nombreCarrera) {
            cout << "Ingrese el nombre del maestro a asignar: ";
            string nombreMaestro;
            cin >> nombreMaestro;

            auto it = find_if(maestros.begin(), maestros.end(), [&nombreMaestro](const Maestro& maestro) {
                return maestro.nombre == nombreMaestro;
            });

            if (it != maestros.end()) {
                carrera.maestros.push_back(*it);
                encontrada = true;
                break;
            } else {
                cout << "Maestro no encontrado.\n";
            }
        }
    }

    /* El código verifica si cierta condición (encontrada) es verdadera. Si es cierto, emitirá un
    mensaje que dice "Maestro asignado a la carrera" y luego llamará a una función llamada
    guardarRelacionesMaestros con un parámetro llamado carreras. Si la condición es falsa, mostrará
    un mensaje que dice "Carrera no encontrada". */
    if (encontrada) {
        cout << "Maestro asignado a la carrera.\n";
        guardarRelacionesMaestros(carreras);
    } else {
        cout << "Carrera no encontrada.\n";
    }
}
