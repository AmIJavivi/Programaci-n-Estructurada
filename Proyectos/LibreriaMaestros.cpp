vector<Maestro> leerMaestros() {
    vector<Maestro> maestros;
    ifstream archivo("maestros.csv");
    if (archivo.is_open()) {
        string linea;
        while (getline(archivo, linea)) {
            stringstream ss(linea);
            string nombre, area;
            getline(ss, nombre, ',');
            getline(ss, area, ',');

            maestros.push_back({nombre, area});
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo para leer.\n";
    }
    return maestros;
}

void eliminarMaestros(vector<Maestro>& maestros) {
    cout << "Ingrese el nombre del maestro a eliminar: ";
    string nombreMaestro;
    cin >> nombreMaestro;

    auto it = find_if(maestros.begin(), maestros.end(), [&nombreMaestro](const Maestro& maestro) {
        return maestro.nombre == nombreMaestro;
    });

    if (it != maestros.end()) {
        maestros.erase(it);
        cout << "Maestro eliminado.\n";
    } else {
        cout << "Maestro no encontrado.\n";
    }
}

void editarMaestros(vector<Maestro>& maestros) {
    cout << "Ingrese el nombre del maestro a editar: ";
    string nombreMaestro;
    cin >> nombreMaestro;

    auto it = find_if(maestros.begin(), maestros.end(), [&nombreMaestro](const Maestro& maestro) {
        return maestro.nombre == nombreMaestro;
    });

    if (it != maestros.end()) {
        cout << "Ingrese el nuevo nombre del maestro: ";
        cin >> it->nombre;
        cout << "Ingrese el nuevo área de especialización del maestro: ";
        cin >> it->area;
        cout << "Maestro editado.\n";
    } else {
        cout << "Maestro no encontrado.\n";
    }
}

void escribirMaestros(const vector<Maestro>& maestros) {
    ofstream archivo("maestros.csv");
    if (archivo.is_open()) {
        for (const auto& maestro : maestros) {
            archivo << maestro.nombre << "," << maestro.area << "\n";
        }
        archivo.close();
        cout << "Maestros guardados en el archivo.\n";
    } else {
        cout << "No se pudo abrir el archivo para escribir.\n";
    }
}

void agregarMaestro(vector<Maestro>& maestros) {
    Maestro nuevoMaestro;
    cout << "Ingrese el nombre del maestro: ";
    cin >> nuevoMaestro.nombre;
    cout << "Ingrese el area de especializacion del maestro: ";
    cin >> nuevoMaestro.area;
    maestros.push_back(nuevoMaestro);
    cout << "Maestro agregado.\n";
}

void mostrarMaestros(const vector<Maestro>& maestros) {
    cout << "\nMaestros:\n";
    for (const auto& maestro : maestros) {
        cout << "Nombre: " << maestro.nombre << "\n";
        cout << "Área de especialización: " << maestro.area << "\n\n";
    }
}