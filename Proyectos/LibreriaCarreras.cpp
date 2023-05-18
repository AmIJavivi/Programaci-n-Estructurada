vector<Carrera> leerCarreras() {
    vector<Carrera> carreras;
    ifstream archivo("carreras.csv");
    if (archivo.is_open()) {
        string linea;
        while (getline(archivo, linea)) {
            stringstream ss(linea);
            string nombre;
            getline(ss, nombre, ',');

            Carrera carrera;
            carrera.nombre = nombre;
            carreras.push_back(carrera);
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo para leer.\n";
    }
    return carreras;
}

void eliminarCarrera(vector<Carrera>& carreras) {
    cout << "Ingrese el nombre de la carrera a eliminar: ";
    string nombreCarrera;
    cin >> nombreCarrera;

    auto it = find_if(carreras.begin(), carreras.end(), [&nombreCarrera](const Carrera& carrera) {
        return carrera.nombre == nombreCarrera;
    });

    if (it != carreras.end()) {
        carreras.erase(it);
        cout << "Carrera eliminada.\n";
    } else {
        cout << "Carrera no encontrada.\n";
    }
}

void editarCarrera(vector<Carrera>& carreras) {
    cout << "Ingrese el nombre de la carrera a editar: ";
    string nombreCarrera;
    cin >> nombreCarrera;

    auto it = find_if(carreras.begin(), carreras.end(), [&nombreCarrera](const Carrera& carrera) {
        return carrera.nombre == nombreCarrera;
    });

    if (it != carreras.end()) {
        cout << "Ingrese el nuevo nombre de la carrera: ";
        cin >> it->nombre;
        cout << "Carrera editada.\n";
    } else {
        cout << "Carrera no encontrada.\n";
    }
}

void escribirCarreras(const vector<Carrera>& carreras) {
    ofstream archivo("carreras.csv");
    if (archivo.is_open()) {
        for (const auto& carrera : carreras) {
            archivo << carrera.nombre << "\n";
        }
        archivo.close();
        cout << "Carreras guardadas en el archivo.\n";
    } else {
        cout << "No se pudo abrir el archivo para escribir.\n";
    }
}

void agregarCarrera(vector<Carrera>& carreras) {
    cout << "Ingrese el nombre de la carrera: ";
    string nombreCarrera;
    cin >> nombreCarrera;

    Carrera nuevaCarrera;
    nuevaCarrera.nombre = nombreCarrera;
    carreras.push_back(nuevaCarrera);
    cout << "Carrera agregada.\n";
}

void mostrarCarreras(const vector<Carrera>& carreras) {
    cout << "\nCarreras:\n";
    for (const auto& carrera : carreras) {
        cout << "Nombre: " << carrera.nombre << "\n\n";
    }
}