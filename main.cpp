#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

const int MAX_TURISTAS = 100;

struct Turista {
    string pasaporte;
    string nombre;
    int horarioIngreso;
    string grupo;
    int circuito;
    bool activo;
    stack<int> circuitosVisitados;
};

Turista turistas[MAX_TURISTAS];
int cantidadTuristas = 0;
queue<string> colaIngreso;

void mostrarOpcionesHorario() {
    cout << "\nSeleccione horario de ingreso:\n";
    cout << "1. 06:00 a.m.\n";
    cout << "2. 07:00 a.m.\n";
    cout << "3. 08:00 a.m.\n";
    cout << "4. 09:00 a.m.\n";
    cout << "5. 10:00 a.m.\n";
    cout << "6. 11:00 a.m.\n";
    cout << "7. 12:00 p.m.\n";
}

string obtenerHorarioTexto(int opcion) {
    switch (opcion) {
        case 1: return "06:00 a.m.";
        case 2: return "07:00 a.m.";
        case 3: return "08:00 a.m.";
        case 4: return "09:00 a.m.";
        case 5: return "10:00 a.m.";
        case 6: return "11:00 a.m.";
        case 7: return "12:00 p.m.";
        default: return "Horario no valido";
    }
}

int buscarIndiceTurista(string pasaporte) {
    for (int i = 0; i < cantidadTuristas; i++) {
        if (turistas[i].pasaporte == pasaporte && turistas[i].activo) {
            return i;
        }
    }
    return -1;
}

void registrarTurista() {
    if (cantidadTuristas >= MAX_TURISTAS) {
        cout << "\nNo se pueden registrar mas turistas.\n";
        return;
    }

    Turista nuevo;

    cout << "\n--- REGISTRO DE TURISTA ---\n";
    cout << "Ingrese numero de pasaporte: ";
    cin >> nuevo.pasaporte;
    cin.ignore();

    if (buscarIndiceTurista(nuevo.pasaporte) != -1) {
        cout << "\nYa existe un turista registrado con ese pasaporte.\n";
        return;
    }

    cout << "Ingrese nombre del turista: ";
    getline(cin, nuevo.nombre);

    mostrarOpcionesHorario();
    cout << "Ingrese opcion de horario: ";
    cin >> nuevo.horarioIngreso;

    while (nuevo.horarioIngreso < 1 || nuevo.horarioIngreso > 7) {
        cout << "Opcion invalida. Ingrese nuevamente: ";
        cin >> nuevo.horarioIngreso;
    }

    cin.ignore();
    cout << "Ingrese grupo turistico: ";
    getline(cin, nuevo.grupo);

    cout << "\nSeleccione circuito de Machu Picchu:\n";
    cout << "1. Circuito 1\n";
    cout << "2. Circuito 2\n";
    cout << "3. Circuito 3\n";
    cout << "Ingrese opcion de circuito: ";
    cin >> nuevo.circuito;

    while (nuevo.circuito < 1 || nuevo.circuito > 3) {
        cout << "Opcion invalida. Ingrese nuevamente: ";
        cin >> nuevo.circuito;
    }

    nuevo.activo = true;
    turistas[cantidadTuristas] = nuevo;
    cantidadTuristas++;

    cout << "\nTurista registrado correctamente.\n";
}

void mostrarTuristas() {
    cout << "\n--- LISTA DE TURISTAS REGISTRADOS ---\n";

    if (cantidadTuristas == 0) {
        cout << "No hay turistas registrados.\n";
        return;
    }

    for (int i = 0; i < cantidadTuristas; i++) {
        if (turistas[i].activo) {
            cout << "\nPasaporte: " << turistas[i].pasaporte;
            cout << "\nNombre: " << turistas[i].nombre;
            cout << "\nHorario de ingreso: " << obtenerHorarioTexto(turistas[i].horarioIngreso);
            cout << "\nGrupo turistico: " << turistas[i].grupo;
            cout << "\nCircuito: " << turistas[i].circuito;
            cout << "\n-----------------------------\n";
        }
    }
}

void buscarTurista() {
    string pasaporte;

    cout << "\n--- BUSCAR TURISTA ---\n";
    cout << "Ingrese numero de pasaporte: ";
    cin >> pasaporte;

    int indice = buscarIndiceTurista(pasaporte);

    if (indice == -1) {
        cout << "\nTurista no encontrado.\n";
    } else {
        cout << "\nTurista encontrado:\n";
        cout << "Pasaporte: " << turistas[indice].pasaporte << endl;
        cout << "Nombre: " << turistas[indice].nombre << endl;
        cout << "Horario de ingreso: " << obtenerHorarioTexto(turistas[indice].horarioIngreso) << endl;
        cout << "Grupo turistico: " << turistas[indice].grupo << endl;
        cout << "Circuito: " << turistas[indice].circuito << endl;
    }
}

//codigo aqui Braulio

void registrarCircuitoVisitado() {
    string pasaporte;
    int circuitoVisitado;

    cout << "\n--- REGISTRAR CIRCUITO VISITADO ---\n";
    cout << "Ingrese numero de pasaporte: ";
    cin >> pasaporte;

    int indice = buscarIndiceTurista(pasaporte);

    if (indice == -1) {
        cout << "\nTurista no encontrado.\n";
        return;
    }

    cout << "\nIngrese circuito visitado:\n";
    cout << "1. Circuito 1\n";
    cout << "2. Circuito 2\n";
    cout << "3. Circuito 3\n";
    cout << "Opcion: ";
    cin >> circuitoVisitado;

    while (circuitoVisitado < 1 || circuitoVisitado > 3) {
        cout << "Opcion invalida. Ingrese nuevamente: ";
        cin >> circuitoVisitado;
    }

    turistas[indice].circuitosVisitados.push(circuitoVisitado);

    cout << "\nCircuito registrado correctamente.\n";
}

void mostrarCircuitosVisitados() {
    string pasaporte;

    cout << "\n--- MOSTRAR CIRCUITOS VISITADOS ---\n";
    cout << "Ingrese numero de pasaporte: ";
    cin >> pasaporte;

    int indice = buscarIndiceTurista(pasaporte);

    if (indice == -1) {
        cout << "\nTurista no encontrado.\n";
        return;
    }

    if (turistas[indice].circuitosVisitados.empty()) {
        cout << "\nEl turista no tiene circuitos visitados registrados.\n";
        return;
    }

    stack<int> copia = turistas[indice].circuitosVisitados;

    cout << "\nCircuitos visitados por " << turistas[indice].nombre << ":\n";

    while (!copia.empty()) {
        cout << "- Circuito " << copia.top() << endl;
        copia.pop();
    }
}

void menu() {
    int opcion;

    do {
        cout << "\n=====================================\n";
        cout << " SISTEMA DE INGRESO A MACHU PICCHU\n";
        cout << "=====================================\n";
        cout << "1. Registrar turista\n";
        cout << "2. Mostrar turistas\n";
        cout << "3. Buscar turista\n";
        cout << "4. Eliminar turista\n";
        cout << "5. Ordenar turistas por horario\n";
        cout << "6. Agregar turista a cola de ingreso\n";
        cout << "7. Atender ingreso de turista\n";
        cout << "8. Registrar circuito visitado\n";
        cout << "9. Mostrar circuitos visitados\n";
        cout << "10. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                registrarTurista();
                break;
            case 2:
                mostrarTuristas();
                break;
            case 3:
                buscarTurista();
                break;
            case 4:
                eliminarTurista();
                break;
            case 5:
                ordenarPorHorario();
                break;
            case 6:
                agregarAColaIngreso();
                break;
            case 7:
                atenderIngreso();
                break;
            case 8:
                registrarCircuitoVisitado();
                break;
            case 9:
                mostrarCircuitosVisitados();
                break;
            case 10:
                cout << "\nSaliendo del sistema...\n";
                break;
            default:
                cout << "\nOpcion invalida. Intente nuevamente.\n";
        }

    } while (opcion != 10);
}

int main() {
    menu();
    return 0;
}
