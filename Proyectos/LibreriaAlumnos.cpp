/**
 * Esta función lee un archivo CSV que contiene información sobre los estudiantes (nombre y edad) y
 * devuelve un vector de objetos del alumno.
 * 
 * return: Un vector de objetos del alumno.
 */
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

/**
 * La función escribe una lista de nombres y edades de los estudiantes en un archivo CSV.
 * 
 * parametro: alumnos un vector de objetos de tipo Alumno, que contiene información sobre los alumnos, como
 * su nombre y edad.
 */
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

/**
 * La función muestra una lista de nombres y edades de los estudiantes.
 * 
 * parametro: alumnos Un vector de objetos de tipo Alumno, que contiene información sobre los alumnos, como
 * su nombre y edad.
 */
void mostrarAlumnos(const vector<Alumno>& alumnos) {
    cout << "\nAlumnos:\n";
    for (const auto& alumno : alumnos) {
        cout << "Nombre: " << alumno.nombre << "\n";
        cout << "Edad: " << alumno.edad << "\n\n";
    }
}

/**
 * La función agrega un nuevo estudiante a un vector de estudiantes solicitando al usuario que ingrese
 * su nombre y edad.
 * 
 * parametro: alumnos. Un vector de objetos de tipo Alumno, que es una clase personalizada que representa a
 * un alumno. La función agrega un nuevo estudiante al vector solicitando al usuario que ingrese su
 * nombre y edad, creando un nuevo objeto Alumno con esa información y luego empujándolo al final del
 * vector.
 */
void agregarAlumno(vector<Alumno>& alumnos) {
    Alumno nuevoAlumno;
    cout << "Ingrese el nombre del alumno: ";
    cin >> nuevoAlumno.nombre;
    cout << "Ingrese la edad del alumno: ";
    cin >> nuevoAlumno.edad;
    alumnos.push_back(nuevoAlumno);
}

/**
 * La función permite al usuario editar el nombre y la edad de un estudiante específico en un vector de
 * estudiantes.
 * 
 * parametro: alumnos. Un vector de objetos de tipo Alumno, que representa una colección de alumnos.
 * 
 * return: La función no devuelve nada, es una función nula. Solo modifica el vector de Alumnos pasado
 * como parámetro.
 */
void editarAlumnos(vector<Alumno>& alumnos) {
    cout << "Ingrese el nombre del alumno a editar: ";
    string nombreAlumno;
    cin >> nombreAlumno;

    /* Esta línea de código usa el algoritmo `find_if` de la biblioteca `<algorithm>` para buscar un
    elemento en el vector `alumnos`. Busca un elemento que satisfaga la condición especificada en la
    función lambda pasada como tercer argumento. En este caso, está buscando un elemento cuya
    variable miembro `nombre` coincida con la cadena `nombreAlumno` pasada como entrada. La palabra
    clave `auto` se utiliza para deducir automáticamente el tipo de iterador devuelto por `find_if`. */
    auto it = find_if(alumnos.begin(), alumnos.end(), [&nombreAlumno](const Alumno& alumno) {
        return alumno.nombre == nombreAlumno;
    });

    /* Este bloque de código verifica si un estudiante específico (identificado por su nombre) existe
    en el vector de estudiantes. Si se encuentra al estudiante, la función solicita al usuario que
    ingrese un nuevo nombre y edad para el estudiante, y actualiza el objeto correspondiente en el
    vector con la nueva información. Si no se encuentra el alumno, la función imprime un mensaje
    indicando que no se encontró al alumno. */
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

    /* Esta línea de código usa el algoritmo `find_if` de la biblioteca `<algorithm>` para buscar un
    elemento en el vector `alumnos`. Busca un elemento que satisfaga la condición especificada en la
    función lambda pasada como tercer argumento. En este caso, está buscando un elemento cuya
    variable miembro `nombre` coincida con la cadena `nombreAlumno` pasada como entrada. La palabra
    clave `auto` se utiliza para deducir automáticamente el tipo de iterador devuelto por `find_if`. */
    auto it = find_if(alumnos.begin(), alumnos.end(), [&nombreAlumno](const Alumno& alumno) {
        return alumno.nombre == nombreAlumno;
    });

    /* Este bloque de código verifica si un estudiante específico (identificado por su nombre) existe
    en el vector de estudiantes. Si se encuentra al alumno, la función elimina el objeto
    correspondiente del vector utilizando la función `borrar` e imprime un mensaje que indica que el
    alumno ha sido eliminado. Si no se encuentra el alumno, la función imprime un mensaje indicando
    que no se encontró al alumno. */
    if (it != alumnos.end()) {
        alumnos.erase(it);
        cout << "Alumno eliminado.\n";
    } else {
        cout << "Alumno no encontrado.\n";
    }
}

/**
 * La función captura las calificaciones de un estudiante, calcula su promedio y asigna un mensaje
 * basado en el promedio y guarda los datos en un archivo CSV.
 * 
 * parametro: alumnos. Un vector de objetos de tipo Alumno, que representa una colección de alumnos con sus
 * respectivos nombres y grados. La función capturarCalificaciones toma este vector como parámetro y le
 * permite al usuario ingresar calificaciones para un estudiante específico, calcula su calificación
 * promedio, asigna un mensaje basado en su desempeño y
 * 
 * return: No se devuelve nada. La función es nula, lo que significa que no devuelve ningún valor.
 */
void capturarCalificaciones(vector<Alumno>& alumnos) {
    cout << "Ingrese el nombre del alumno: ";
    string nombreAlumno;
    cin >> nombreAlumno;

    /* Esta línea de código usa el algoritmo `find_if` de la biblioteca `<algorithm>` para buscar un
    elemento en el vector `alumnos`. Busca un elemento que satisfaga la condición especificada en la
    función lambda pasada como tercer argumento. En este caso, está buscando un elemento cuya
    variable miembro `nombre` coincida con la cadena `nombreAlumno` pasada como entrada. La palabra
    clave `auto` se utiliza para deducir automáticamente el tipo de iterador devuelto por `find_if`. */
    auto it = find_if(alumnos.begin(), alumnos.end(), [&nombreAlumno](const Alumno& alumno) {
        return alumno.nombre == nombreAlumno;
    });

    /* Esta línea de código verifica si el iterador `it` devuelto por el algoritmo `find_if` apunta a
    un elemento válido en el vector `alumnos`. Si `it` no es igual a `alumnos.end()`, significa que
    el elemento se encontró en el vector y se ejecutará el bloque de código subsiguiente. Si `it` es
    igual a `alumnos.end()`, significa que el elemento no se encontró en el vector y el bloque de
    código subsiguiente no se ejecutará. */
    if (it != alumnos.end()) {
        int numCalificaciones;
        cout << "Ingrese el numero de calificaciones a capturar: ";
        cin >> numCalificaciones;

        vector<int> calificaciones;

        /* Este bloque de código captura las calificaciones de un estudiante específico. Solicita al
        usuario que ingrese el número de calificaciones para capturar, luego usa un bucle for para
        solicitar al usuario que ingrese cada calificación una por una. Cada calificación se
        almacena en una variable entera `calificación` y luego se suma a un vector de enteros
        `calificaciones` usando la función `push_back`. El ciclo continúa hasta que el número de
        calificaciones ingresadas coincida con el valor de `numCalificaciones`. */
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

        /* Este bloque de código asigna un mensaje a un estudiante en función de su calificación
        promedio. Si la nota media es menor o igual a 59, se le asigna al alumno el mensaje
        "Reprobado". Si la nota media está entre 60 y 79, se asigna el mensaje "Regular". Si la nota
        media está entre 80 y 89, se asigna el mensaje "Muy bien". Si la calificación promedio es de
        90 o más, se asigna el mensaje "Excelente". */
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

       /* Este bloque de código está escribiendo el nombre de un estudiante, sus calificaciones, su
       calificación promedio y un mensaje basado en su calificación promedio en un archivo CSV
       llamado "Calificaciones.csv". Primero verifica si el archivo está abierto para escritura
       usando la función `is_open()` del objeto `ofstream`. Si el archivo está abierto, escribe los
       datos en el archivo usando el operador `<<` y luego cierra el archivo usando la función
       `close()`. Si el archivo no está abierto, imprime un mensaje de error. Si el alumno no se
       encuentra en el vector de alumnos, imprime un mensaje indicando que no se encontró al alumno. */
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


    /* Esta línea de código usa el algoritmo `find_if` de la biblioteca `<algorithm>` para buscar un
    elemento en el vector `alumnos`. Busca un elemento que satisfaga la condición especificada en la
    función lambda pasada como tercer argumento. En este caso, está buscando un elemento cuya
    variable miembro `nombre` coincida con la cadena `nombreAlumno` pasada como entrada. La palabra
    clave `auto` se utiliza para deducir automáticamente el tipo de iterador devuelto por `find_if`. */
    auto it = find_if(alumnos.begin(), alumnos.end(), [&nombreAlumno](const Alumno& alumno) {
        return alumno.nombre == nombreAlumno;
    });

    /* El código verifica si el iterador "eso" apunta a un elemento en el contenedor "alumnos". Si
    apunta a un elemento, se ejecutará el código dentro de la instrucción if. */
    if (it != alumnos.end()) {
        const Alumno& alumno = *it;
        cout << "\nCalificaciones del alumno " << alumno.nombre << ":\n";
        /* El código anterior está comprobando si el vector "calificaciones" del objeto "alumno" está
        vacío o no. Si está vacío, se ejecutará el código dentro de la instrucción if. */
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
