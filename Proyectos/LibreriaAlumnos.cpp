vector<Alumno> leerAlumnos() {
    vector<Alumno> alumnos;
    ifstream archivo("alumnos.csv");
    if (archivo.is_open()) {
        string linea;
        while (getline(archivo, linea)) {
            stringstream ss(linea);
            string nombre, edadStr;
            getline(ss, nombre, ',');
            getline(ss, edadStr, ',');

            int edad = stoi(edadStr);
            alumnos.push_back({nombre, edad});
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo para leer.\n";
    }
    return alumnos;
}

void escribirAlumnos(const vector<Alumno>& alumnos) {
    ofstream archivo("alumnos.csv");
    if (archivo.is_open()) {
        for (const auto& alumno : alumnos) {
            archivo << alumno.nombre << "," << alumno.edad << "\n";
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo para escribir.\n";
    }
}

void mostrarAlumnos(const vector<Alumno>& alumnos) {
    cout << "\nAlumnos:\n";
    for (const auto& alumno : alumnos) {
        cout << "Nombre: " << alumno.nombre << "\n";
        cout << "Edad: " << alumno.edad << "\n\n";
    }
}

void agregarAlumno(vector<Alumno>& alumnos) {
    Alumno nuevoAlumno;
    cout << "Ingrese el nombre del alumno: ";
    cin >> nuevoAlumno.nombre;
    cout << "Ingrese la edad del alumno: ";
    cin >> nuevoAlumno.edad;
    alumnos.push_back(nuevoAlumno);
}

void editarAlumnos(vector<Alumno>& alumnos) {
    cout << "Ingrese el nombre del alumno a editar: ";
    string nombreAlumno;
    cin >> nombreAlumno;

    auto it = find_if(alumnos.begin(), alumnos.end(), [&nombreAlumno](const Alumno& alumno) {
        return alumno.nombre == nombreAlumno;
    });

    if (it != alumnos.end()) {
        cout << "Ingrese el nuevo nombre del alumno: ";
        cin >> it->nombre;
        cout << "Ingrese la nueva edad del alumno: ";
        cin >> it->edad;
        cout << "Alumno editado.\n";
    } else {
        cout << "Alumno no encontrado.\n";
    }
}

void eliminarAlumnos(vector<Alumno>& alumnos) {
    cout << "Ingrese el nombre del alumno a eliminar: ";
    string nombreAlumno;
    cin >> nombreAlumno;

    auto it = find_if(alumnos.begin(), alumnos.end(), [&nombreAlumno](const Alumno& alumno) {
        return alumno.nombre == nombreAlumno;
    });

    if (it != alumnos.end()) {
        alumnos.erase(it);
        cout << "Alumno eliminado.\n";
    } else {
        cout << "Alumno no encontrado.\n";
    }
}

void capturarCalificaciones(vector<Alumno>& alumnos) {
    cout << "Ingrese el nombre del alumno: ";
    string nombreAlumno;
    cin >> nombreAlumno;

    auto it = find_if(alumnos.begin(), alumnos.end(), [&nombreAlumno](const Alumno& alumno) {
        return alumno.nombre == nombreAlumno;
    });

    if (it != alumnos.end()) {
        int numCalificaciones;
        cout << "Ingrese el numero de calificaciones a capturar: ";
        cin >> numCalificaciones;

        vector<int> calificaciones;
        for (int i = 0; i < numCalificaciones; ++i) {
            int calificacion;
            cout << "Ingrese la calificación " << i + 1 << ": ";
            cin >> calificacion;
            calificaciones.push_back(calificacion);
        }

        it->calificaciones = calificaciones;

        double suma = 0.0;
        for (int calificacion : calificaciones) {
            suma += calificacion;
        }
        double promedio = suma / numCalificaciones;

        string mensaje;
        if (promedio <= 59) {
            mensaje = "Reprobado";
        } else if (promedio >= 60 && promedio <= 79) {
            mensaje = "Regular";
        } else if (promedio >= 80 && promedio <= 89) {
            mensaje = "Muy bien";
        } else {
            mensaje = "Excelente";
        }

        cout << "Promedio: " << promedio << "\n";
        cout << "Mensaje: " << mensaje << "\n";

        ofstream archivo("Calificaciones.csv", ios::app);
        if (archivo.is_open()) {
            archivo << nombreAlumno << ",";
            for (int calificacion : calificaciones) {
                archivo << calificacion << ",";
            }
            archivo << promedio << "," << mensaje << "\n";
            archivo.close();
        } else {
            cout << "No se pudo abrir el archivo Calificaciones.csv para guardar las calificaciones.\n";
        }
    } else {
        cout << "Alumno no encontrado.\n";
    }
}

void mostrarCalificaciones(const vector<Alumno>& alumnos) {
    cout << "Ingrese el nombre del alumno: ";
    string nombreAlumno;
    cin >> nombreAlumno;

    auto it = find_if(alumnos.begin(), alumnos.end(), [&nombreAlumno](const Alumno& alumno) {
        return alumno.nombre == nombreAlumno;
    });

    if (it != alumnos.end()) {
        const Alumno& alumno = *it;
        cout << "\nCalificaciones del alumno " << alumno.nombre << ":\n";
        if (alumno.calificaciones.empty()) {
            cout << "No hay calificaciones registradas para este alumno.\n";
        } else {
            for (int calificacion : alumno.calificaciones) {
                cout << calificacion << " ";
            }
            cout << "\n";
        }
    } else {
        cout << "Alumno no encontrado.\n";
    }
}
