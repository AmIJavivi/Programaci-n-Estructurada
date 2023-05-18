#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Alumno {
  string nombre;
  string apellidos;
  int edad;
  string curp;
  string matricula;
  string telefono;
  string email;
  string direccion;
  string sexo;
};

void escribir_alumno(ofstream& archivo, const Alumno& alumno) {
  archivo << alumno.nombre << "," << alumno.apellidos << "," << alumno.edad << ",";
  archivo << alumno.curp << "," << alumno.matricula << "," << alumno.telefono << ",";
  archivo << alumno.email << "," << alumno.direccion << "," << alumno.sexo << ",\n";
}


Alumno leer_alumno(ifstream& archivo) {
  Alumno alumno;
  string linea;
  getline(archivo, linea);
  size_t pos = 0;
  string token;
  int cont = 0;
  while ((pos = linea.find(",")) != string::npos) {
    token = linea.substr(0, pos);
    switch (cont) {
      case 0:
        alumno.nombre = token;
        break;
      case 1:
        alumno.apellidos = token;
        break;
      case 2:
        alumno.edad = stoi(token);
        break;
      case 3:
        alumno.curp = token;
        break;
      case 4:
        alumno.matricula = token;
        break;
      case 5:
        alumno.telefono = token;
        break;
      case 6:
        alumno.email = token;
        break;
      case 7:
        alumno.direccion = token;
        break;
      case 8:
        alumno.sexo = token;
        break;
    }
    linea.erase(0, pos + 1);
    cont++;
  } 
  return alumno;
}

void agregar_alumno() {
  Alumno alumno;
  cout << "Ingresa el nombre de la alumno: ";
  getline(cin, alumno.nombre);
  cout << "Ingresa los apellidos de la alumno: ";
  getline(cin, alumno.apellidos);
  cout << "Ingresa la edad de la alumno: ";
  cin >> alumno.edad;
  cout << "Ingresa la CURP de la alumno: ";
  cin.ignore();
  getline(cin, alumno.curp);
  cout << "Ingresa la matrícula de la alumno: ";
  getline(cin, alumno.matricula);
  cout << "Ingresa el teléfono de la alumno: ";
  getline(cin, alumno.telefono);
  cout << "Ingresa el email de la alumno: ";
  getline(cin, alumno.email);
  cout << "Ingresa la dirección de la alumno: ";
  getline(cin, alumno.direccion);
  cout << "Ingresa el sexo de la alumno: ";
  getline(cin, alumno.sexo);
  
  ofstream archivo("alumnos.csv", ios_base::app);
  escribir_alumno(archivo, alumno);
}


/**
 * Esta función modifica la información de una alumno en un archivo CSV.
 */
void modificar_alumno() {
  string nombre;
  cout << "Ingresa el nombre del alumno a modificar: ";
  getline(cin, nombre);
  fflush(stdin);
  ifstream archivo_lectura("alumnos.csv");
  ofstream archivo_escritura("alumnos_temp.csv");
  Alumno alumno_actual;
  while (!archivo_lectura.eof()) {
    alumno_actual = leer_alumno(archivo_lectura);
    if (alumno_actual.nombre == nombre) {
      Alumno alumno_nuevo;
      cout << "Ingresa el nuevo nombre del alumno: ";
      getline(cin, alumno_nuevo.nombre);
      cout << "Ingresa los nuevos apellidos del alumno: ";
      getline(cin, alumno_nuevo.apellidos);
      cout << "Ingresa la nueva edad del alumno: ";
      cin >> alumno_nuevo.edad;
      cout << "Ingresa el nuevo CURP del alumno: ";
      cin.ignore();
      getline(cin, alumno_nuevo.curp);
      cout << "Ingresa la nueva matricula del alumno: ";
      getline(cin, alumno_nuevo.matricula);
      cout << "Ingresa el nuevo telefono del alumno: ";
      getline(cin, alumno_nuevo.telefono);
      cout << "Ingresa el nuevo email del alumno: ";
      getline(cin, alumno_nuevo.email);
      cout << "Ingresa la nueva direccion del alumno: ";
      getline(cin, alumno_nuevo.direccion);
      cout << "Ingresa el nuevo sexo del alumno: ";
      getline(cin, alumno_nuevo.sexo);
      escribir_alumno(archivo_escritura, alumno_nuevo);
    } else if(alumno_actual.nombre == nombre) {
      escribir_alumno(archivo_escritura, alumno_actual);
    }
  }
  archivo_lectura.close();
  archivo_escritura.close();
  // Se reemplaza el archivo original con el archivo temporal.
  remove("alumnos.csv");
  rename("alumnos_temp.csv", "alumnos.csv");
}


void mostrar_alumnos() {
  ifstream archivo_lectura("alumnos.csv");
  Alumno alumno_actual;
  while (archivo_lectura.good()) {
    alumno_actual = leer_alumno(archivo_lectura);
    if (alumno_actual.nombre != "") {
      cout << "Nombre: " << alumno_actual.nombre <<" "<< alumno_actual.apellidos << endl;
      cout << "Edad: " << alumno_actual.edad << endl;
      cout << "CURP: " << alumno_actual.curp << endl;
      cout << "Matrícula: " << alumno_actual.matricula << endl;
      cout << "Teléfono: " << alumno_actual.telefono << endl;
      cout << "Email: " << alumno_actual.email << endl;
      cout << "Dirección: " << alumno_actual.direccion << endl;
      cout << "Sexo: " << alumno_actual.sexo << endl << endl;
    }
  }
  archivo_lectura.close();
}

int main() {
  int opcion = 0;
  while (opcion != 4) {
    system("cls");
    cout << "¿Qué acción deseas realizar?" << endl;
    cout << "1. Registrar una nueva alumno" << endl;
    cout << "2. Consultar alumnos" << endl;
    cout << "3. Modificar una alumno" << endl;
    cout << "4. Salir" << endl;
    cout << "Ingresa el número de la opción: ";
    cin >> opcion;
    switch (opcion) {
      case 1:
        fflush(stdin);
        agregar_alumno();
        break;
      case 2:
        fflush(stdin);
        system("cls");
        mostrar_alumnos();
        system("pause");
        break;
      case 3:
        fflush(stdin);
        system("cls");
        mostrar_alumnos();
        modificar_alumno();
        break;
      case 4:
        cout << "¡Hasta luego!" << endl;
        break;
      default:
        fflush(stdin);
        cout << "Opción inválida, por favor intenta de nuevo." << endl;
        break;
    }
  }
  return 0;
}