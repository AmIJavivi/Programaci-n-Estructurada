/**
 * Esta función lee datos de un archivo CSV que contiene información sobre profesores y devuelve un
 * vector de objetos Maestro.
 * 
 * return: Un vector de objetos Maestro.
 */
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

/**
 * La función "eliminarMaestros" elimina un objeto Maestro de un vector de Maestros en función de la
 * entrada del usuario del nombre del Maestro.
 * 
 * parametros:
 *      *maestros. Un vector de objetos Maestro, que representa una colección de maestros.
 * 
 * return: La función no devuelve nada. Simplemente elimina un objeto Maestro de un vector de objetos
 * Maestro si coincide con un nombre dado, e imprime un mensaje que indica si el Maestro fue encontrado
 * y eliminado o no.
 */
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

/**
 * La función "editarMaestros" toma un vector de objetos Maestro como entrada y realiza algunas
 * operaciones de edición sobre ellos.
 * 
 * parametro: maestros Un vector de objetos Maestro, que probablemente contiene información sobre maestros.
 */
void editarMaestros(vector<Maestro>& maestros) {
    cout << "Ingrese el nombre del maestro a editar: ";
    string nombreMaestro;
    cin >> nombreMaestro;

    /* Esta línea de código usa el algoritmo `find_if` de la biblioteca `<algorithm>` para buscar un
    elemento en el vector `carreras`. Busca un elemento que satisfaga la condición especificada en la
    función lambda pasada como tercer argumento. En este caso, está buscando un elemento cuya
    variable miembro `nombre` coincida con la cadena `nombreAlumno` pasada como entrada. La palabra
    clave `auto` se utiliza para deducir automáticamente el tipo de iterador devuelto por `find_if`. */
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

/**
 * La función "escribirMaestros" escribe un vector de objetos "Maestro" en un flujo de salida.
 * 
 * parametro: maestros. Un vector de objetos de tipo Maestro.
 */
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

/**
 * La función agrega un nuevo objeto Maestro a un vector de objetos Maestro.
 * 
 * parametro: maestros. Un vector de objetos de tipo Maestro.
 */
void agregarMaestro(vector<Maestro>& maestros) {
    Maestro nuevoMaestro;
    cout << "Ingrese el nombre del maestro: ";
    cin >> nuevoMaestro.nombre;
    cout << "Ingrese el area de especializacion del maestro: ";
    cin >> nuevoMaestro.area;
    maestros.push_back(nuevoMaestro);
    cout << "Maestro agregado.\n";
}

/**
 * La función muestra una lista de maestros usando un vector de objetos Maestro.
 * 
 * parametro: maestros. Un vector de objetos Maestro, que probablemente contenga información sobre los
 * maestros, como sus nombres, las materias que enseñan y posiblemente otros detalles.
 */
void mostrarMaestros(const vector<Maestro>& maestros) {
    cout << "\nMaestros:\n";
    for (const auto& maestro : maestros) {
        cout << "Nombre: " << maestro.nombre << "\n";
        cout << "Área de especialización: " << maestro.area << "\n\n";
    }
}