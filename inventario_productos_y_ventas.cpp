/*Objetivo: Desarrollar un programa que permita registrar, listar, buscar, actualizar y eliminar productos, así como gestionar
las ventas.
Requisitos:
• Define una estructura Producto con los campos: nombre (cadena), precio (flotante).
• Define una estructura Venta con los campos: idVenta (entero), producto (cadena), cantidad (entero), precioTotal (flotante).
• Implementa un menú con las siguientes opciones:
    A: Registrar un nuevo producto.
    B: Listar los productos registrados.
    C: Buscar un producto por nombre.
    D: Actualizar los datos de un producto.
    E: Eliminar un producto.
    F: Registrar una venta.
    G: Listar las ventas realizadas.
    H: Calcular el total de ventas realizadas.
    S: Salir del programa.
• El menú debe estar ciclado y permitir volver al menú principal después de cada opción.*/

#include <iostream>
using namespace std;

const int MAX_P = 200;
const int MAX_V = 100;
struct Producto
{
    string nombre;
    float precio;
};

struct Venta
{
    int IdVenta;
    string producto;
    int cantidad;
    float precioTotal;
};
Producto productos[MAX_P];
Venta ventas[MAX_V];
int totalProductos = 0;
int totalV = 0;
int IdVENTA = 1;

void RegistrarProducto (){
    if (totalProductos >= MAX_P){
        cout << "\nNo se puede registrar mas productos.\n";
        return;
    }
    string nombreIngresado;
    float precioIngresado;
    cout << "\n===== REGISTRAR PRODUCTO =====\n";
    cin.ignore();
    cout << "Nombre del producto: ";
    getline(cin, nombreIngresado);
    // Verificar si el nombre ya existe
    for (int i = 0; i < totalProductos; i++) {
        if (productos[i].nombre == nombreIngresado) {
            cout << "Error: El producto ya existe.\n";
            return;
        }
    }
    cout << "Ingrese el precio del producto: ";
    cin >> precioIngresado;
    if (precioIngresado <= 0) {
        cout << "Error: El precio debe ser mayor que cero.\n";
    return;
    }
    productos[totalProductos].nombre = nombreIngresado;
    productos[totalProductos].precio = precioIngresado;
    totalProductos++;
    cout << "Producto registrado exitosamente.\n";
}

void ListaProducto (){
    cout << "\n=== LISTA DE PRODUCTOS REGISTRADOS ===\n";
    if (totalProductos == 0){
        cout << "\nNo hay productos registrados\n";
        return;
    }
    for (int i = 0; i < totalProductos; i++){
        cout << i + 1 << ". " << productos[i].nombre << " - S/ " << productos[i].precio << endl;
        cout << endl;
    }   
}

void BuscarProducto (){
    string nombre;
    cin.ignore();
    cout << "\n=== BUSCAR PRODUCTO ===\n";
    cout << "Ingrese el nombre del producto: ";
    getline(cin, nombre);
    bool encontrado = false;
    for (int i = 0; i < totalProductos; i++){
        if (productos[i].nombre == nombre){
            cout << "Producto encontrado: " << productos[i].nombre << " - S/ " << productos[i].precio << endl;
            encontrado = true;
            cout << endl;
        }
    }
    if (encontrado == false) {
        cout << "Producto no encontrado.\n";
    }
}

void ActualizarProducto (){
    if (totalProductos == 0){
        cout << "\nNo hay productos registrados\n";
        return;
    }
    string nombre;
    cin.ignore();
    cout << "\n=== ACTUALIZAR PRODUCTO ===\n";
    cout << "Ingrese el nombre del producto: ";
    getline(cin, nombre);
    bool encontrado = false;
    for (int i = 0; i < totalProductos; i++){
        if (productos[i].nombre == nombre){
            encontrado = true;
            cout << "Nuevo nombre de producto: ";
            getline(cin,productos[i].nombre);
            cout << "Nuevo precio de producto: ";
            cin >> productos[i].precio;
            if (productos[i].precio <= 0) {
            cout << "Error: El precio debe ser mayor que cero.\n";
            return; 
            }
            cout << "Producto actualizado correctamente.\n";
            return;
        }
    }
    if (encontrado == false){
        cout << "Producto no encontrado.\n";
    }
}

void EliminarProducto (){
    if (totalProductos == 0){
        cout << "\nNo hay productos registrados\n";
        return;
    }
    string nombre;
    cin.ignore();
    cout << "\n=== ELIMINAR PRODUCTO ===\n";
    cout << "Ingrese el nombre del producto: ";
    getline(cin, nombre);
    bool encontrado = false;
    for (int i = 0; i < totalProductos; i++){
        if (productos[i].nombre == nombre){
            for (int j = i; j < totalProductos - 1; j++){
                productos[j] = productos[j+1];
            }
            totalProductos--;
            encontrado = true;
            cout << "Producto eliminado \n";
            return;
        }
    }
    if (encontrado == false) {
    cout << "Producto no encontrado.\n";
    }
}

void RegistrarVenta (){
    if (totalV >= MAX_V){
        cout << "\nNo se puede registrar mas ventas\n";
        return;
    }
    string nombre;
    cin.ignore();
    cout << "\n=== REGISTRAR VENTA ===\n";
    cout << "Ingrese el nombre del producto vendido: ";
    getline(cin, nombre);
    int cantidad;
    cout << "Cantidad vendida: ";
    cin >> cantidad;
    if (cantidad <= 0) {
        cout << "Error: La cantidad debe ser mayor que cero.\n";
    return;
    }  
    for (int i = 0; i < totalProductos; i++){
        if (productos[i].nombre == nombre){
            ventas[totalV].IdVenta = IdVENTA++;
            ventas[totalV].producto = nombre;
            ventas[totalV].cantidad = cantidad;
            ventas[totalV].precioTotal = productos[i].precio * cantidad;
            totalV++;
            cout << "Venta registrada exitosamente.\n";
            return;
        }
    }
    cout << "Producto no encotrado\n";
}
void ListaVenta (){
    cout << "\n=== VENTAS REALIZADAS ===\n";
    if (totalV == 0){
        cout << "No hay ventas registradas.\n";
        return;
    }
    for (int i = 0; i < totalV; i++){
        cout << "Venta ID: " << ventas[i].IdVenta;
        cout << " | Producto : " << ventas[i].producto;
        cout << " | Cantidad : " << ventas[i].cantidad;
        cout << " | Total:  S/ " << ventas[i].precioTotal << endl;
        cout << endl;
    }
}

void TotalVenta (){
    float total = 0;
    for (int i = 0; i < totalV; i++){
        total += ventas[i].precioTotal;
    }
    cout << "\n=== TOTAL DE VENTAS ===\n";
    cout << "S/ " << total << "\n";
    
}

void menu (){
    char opcion;
    do {
        cout << "\n========== MENU PRINCIPAL ==========\n";
        cout << "A: Registrar un nuevo producto. " << endl;
        cout << "B: Listar los productos registrados. " << endl;
        cout << "C: Buscar un producto por nombre. " << endl;
        cout << "D: Actualizar los datos de un producto. " << endl;
        cout << "E: Eliminar un producto. " << endl;
        cout << "F: Registrar una venta. " << endl;
        cout << "G: Listar las ventas realizadas. " << endl;
        cout << "H: Calcular el total de ventas realizadas. " << endl;
        cout << "S: Salir del programa." << endl;
        cout << "====================================\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        opcion = toupper(opcion);
        switch (opcion){
            case 'A' :
                RegistrarProducto();
                break;
            case 'B' :
                ListaProducto();
                break;
            case 'C' :
                BuscarProducto(); 
                break;
            case 'D': 
                ActualizarProducto();
                break;
            case 'E' :
                EliminarProducto();
                break;
            case 'F' : 
                RegistrarVenta();
                break;
            case 'G':
                ListaVenta();
                break;
            case 'H' :
                TotalVenta();
                break;
            case 'S' :
                cout << "Saliendo del programa......\n" << endl;
                break;
            default :
                cout << "Opcion Invalida. Intente Nuevamente.\n" << endl;
        }   
    } while (opcion != 'S');
}

int main(){
    menu();
    return 0;
}