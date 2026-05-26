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
