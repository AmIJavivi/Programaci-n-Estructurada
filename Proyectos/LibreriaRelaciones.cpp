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

void leerRelacionesAlumnos(vector<Carrera>& carreras, const vector<Alumno>& alumnos) {
    ifstream archivo("RelacionesAlumnos.csv");
    if (archivo.is_open()) {
        string linea;
        while (getline(archivo, linea)) {
            stringstream ss(linea);
            string nombreCarrera, nombreAlumno;
            getline(ss, nombreCarrera, ',');
            getline(ss, nombreAlumno, ',');

            auto itCarrera = find_if(carreras.begin(), carreras.end(), [&nombreCarrera](const Carrera& carrera) {
                return carrera.nombre == nombreCarrera;
            });

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

void leerRelacionesMaestros(vector<Carrera>& carreras, const vector<Maestro>& maestros) {
    ifstream archivo("RelacionesMaestros.csv");
    if (archivo.is_open()) {
        string linea;
        while (getline(archivo, linea)) {
            stringstream ss(linea);
            string nombreCarrera, nombreMaestro;
            getline(ss, nombreCarrera, ',');
            getline(ss, nombreMaestro, ',');

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

void agregarAlumnoACarrera(vector<Carrera>& carreras, const vector<Alumno>& alumnos) {
    cout << "Ingrese el nombre de la carrera: ";
    string nombreCarrera;
    cin >> nombreCarrera;

    bool encontrada = false;
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

    if (encontrada) {
        cout << "Alumno agregado a la carrera.\n";
        guardarRelacionesAlumnos(carreras);
    } else {
        cout << "Carrera no encontrada.\n";
    }
}

void asignarMaestroACarrera(vector<Carrera>& carreras, const vector<Maestro>& maestros) {
    cout << "Ingrese el nombre de la carrera: ";
    string nombreCarrera;
    cin >> nombreCarrera;

    bool encontrada = false;
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

    if (encontrada) {
        cout << "Maestro asignado a la carrera.\n";
        guardarRelacionesMaestros(carreras);
    } else {
        cout << "Carrera no encontrada.\n";
    }
}
