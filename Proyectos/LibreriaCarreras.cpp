/**
 * Esta función lee un archivo CSV que contiene información sobre carreras y devuelve un vector de
 * objetos de carrera.
 * 
 * return un vector de objetos de tipo Carrera, que representa una lista de carreras.
 */
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

/**
 * La función "eliminarCarrera" toma un vector de objetos "Carrera" y elimina un objeto seleccionado
 * del vector.
 * 
 * parametro: carreras. Un vector de objetos de tipo "Carrera".
 */
void eliminarCarrera(vector<Carrera>& carreras) {
    cout << "Ingrese el nombre de la carrera a eliminar: ";
    string nombreCarrera;
    cin >> nombreCarrera;

    /* Esta línea de código usa el algoritmo `find_if` de la biblioteca `<algorithm>` para buscar un
    elemento en el vector `carreras`. Busca un elemento que satisfaga la condición especificada en la
    función lambda pasada como tercer argumento. En este caso, está buscando un elemento cuya
    variable miembro `nombre` coincida con la cadena `nombreAlumno` pasada como entrada. La palabra
    clave `auto` se utiliza para deducir automáticamente el tipo de iterador devuelto por `find_if`. */
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

/**
 * La función "editarCarrera" toma un vector de objetos "Carrera" como entrada y realiza algunas
 * operaciones de edición sobre ellos.
 * 
 * parametro: carreras. Un vector de objetos de tipo "Carrera".
 */
void editarCarrera(vector<Carrera>& carreras) {
    cout << "Ingrese el nombre de la carrera a editar: ";
    string nombreCarrera;
    cin >> nombreCarrera;


    /* Esta línea de código usa el algoritmo `find_if` de la biblioteca `<algorithm>` para buscar un
    elemento en el vector `carreras`. Busca un elemento que satisfaga la condición especificada en la
    función lambda pasada como tercer argumento. En este caso, está buscando un elemento cuya
    variable miembro `nombre` coincida con la cadena `nombreAlumno` pasada como entrada. La palabra
    clave `auto` se utiliza para deducir automáticamente el tipo de iterador devuelto por `find_if`. */
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

/**
 * La función escribe una lista de objetos "Carrera" en un flujo de salida.
 * 
 * parametro: carreras. Un vector de objetos de tipo Carrera.
 */
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

/**
 * La función agrega un nuevo objeto "Carrera" a un vector de objetos "Carrera".
 * 
 * parametro: carreras. Un vector de objetos de tipo "Carrera".
 */
void agregarCarrera(vector<Carrera>& carreras) {
    cout << "Ingrese el nombre de la carrera: ";
    string nombreCarrera;
    cin >> nombreCarrera;

    Carrera nuevaCarrera;
    nuevaCarrera.nombre = nombreCarrera;
    carreras.push_back(nuevaCarrera);
    cout << "Carrera agregada.\n";
}

/**
 * La función muestra información sobre un vector de objetos "Carrera".
 * 
 * parametro: carreras. Un vector de objetos de tipo Carrera, que presumiblemente contiene información sobre
 * diferentes programas académicos o cursos de estudio.
 */
void mostrarCarreras(const vector<Carrera>& carreras) {
    cout << "\nCarreras:\n";
    for (const auto& carrera : carreras) {
        cout << "Nombre: " << carrera.nombre << "\n\n";
    }
}