bool esvalido(int seleccion){
    if(float(seleccion) != 1){
        fflush(stdin);
        return false;
    }else{
        fflush(stdin);
        return true;
    }
}

void pedir_datos_amigo(Amigo& amigo, int i){
    cout << "Ingresa el nombre del amigo " << i + 1 << ": ";
    cin.getline(amigo.nombre, 100);

    cout << "Ingresa los apellidos del amigo " << i + 1 << ": ";
    cin.getline(amigo.apellidos, 100);

    cout << "Ingresa la ciudad del amigo " << i + 1 << ": ";
    cin.getline(amigo.ciudad, 100);

    cout << "Ingresa el estado del amigo " << i + 1 << ": ";
    cin.getline(amigo.estado, 100);

    cout << "Ingresa el municipio del amigo " << i + 1 << ": ";
    cin.getline(amigo.municipio, 30);

    cout << "Ingresa la edad del amigo " << i + 1 << ": ";
    while (!(cin >> amigo.edad)) {
        cout << "Ingresa un valor válido para la edad: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Ingresa la estatura del amigo " << i + 1 << ": ";
    while (!(cin >> amigo.estatura)) {
        cout << "Ingresa un valor válido para la estatura: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    system("cls");
}

void imprimir_alumno(int tamano){
    for(int i=0;i<tamano;i++){
		cout<<"Nombre del amigo "<<i+1<<": "<<amigos[i].nombre<<endl;
		cout<<"Apellidos del amigo "<<i+1<<": "<<amigos[i].apellidos<<endl;
		cout<<"Edad del amigo "<<i+1<<": "<<amigos[i].edad<<endl;
		cout<<"Estatura del amigo "<<i+1<<": "<<amigos[i].estatura<<endl;
		cout<<"Ciudad del amigo "<<i+1<<": "<<amigos[i].ciudad<<endl;
		cout<<"Estado del amigo "<<i+1<<": "<<amigos[i].estado<<endl;
		cout<<"Municipio del amigo "<<i+1<<": "<<amigos[i].municipio<<"\n\n";
	}
}

/**
 * Le pide al usuario la cantidad de amigos que desea agregar al archivo, luego solicita los datos de
 * cada amigo y finalmente escribe los datos en el archivo.
 */
void escribir(){
    ofstream archivo("personas.txt");
    int tamano = 0;
    
    cout<<"[Tamano]: ";
    if(!esvalido(scanf("%d",&tamano))){
        fflush(stdin);
        escribir();
        archivo.close();
    }
    
    for(int i = 0; i < tamano; i++){
        pedir_datos_amigo(amigos[i], i);
    }
    imprimir_alumno(tamano);

    for(int i=0;i<tamano;i++){
        archivo<<amigos[i].nombre<<"\n"<<amigos[i].apellidos<<"\n"<<amigos[i].ciudad<<"\n"<<amigos[i].estado<<"\n"<<amigos[i].municipio<<"\n"<<amigos[i].edad<<"\n"<<amigos[i].estatura<<"\n";
    }
    archivo.close();
}

/**
 * Lee el archivo e imprime los datos en la consola
 */
void leer(){
    int amigo = 1;
    /* Crear un objeto de flujo de archivos llamado `archivo` y abre el archivo `personas.txt` para
    leer. */
    ifstream archivo("personas.txt");
    string linea;
    /* Comprobando si el archivo está abierto. */
    if(archivo.is_open()){
        /* Un bucle infinito. */
        while(1){
            getline(archivo, linea);    
            /* Comprobando si la línea está vacía. */
            if(linea.empty()){
                break;
            }
            cout<<"Nombre del amigo "<<amigo<<": "<<linea<<endl;
            getline(archivo, linea);
            cout<<"Apellidos del amigo "<<amigo<<": "<<linea<<endl;
            getline(archivo, linea); 
            cout<<"Ciudad del amigo "<<amigo<<": "<<linea<<endl;
            getline(archivo, linea);
            cout<<"Estado del amigo "<<amigo<<": "<<linea<<endl;
            getline(archivo, linea);
            cout<<"Municipio del amigo "<<amigo<<": "<<linea<<endl;
            getline(archivo, linea);
            cout<<"Edad del amigo "<<amigo<<": "<<linea<<endl;
            getline(archivo, linea);
            cout<<"Estatura del amigo "<<amigo<<": "<<linea<<"\n\n";
            amigo++;
        }
    }
    /* Cierra el archivo. */
    archivo.close();
}