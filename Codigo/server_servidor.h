//  
//  server_servidor.h
//  CLASE SERVIDOR
//  


#ifndef SERVIDOR_H
#define SERVIDOR_H


#include "common_thread.h"
#include "common_socket.h"
#include "common_lista.h"
#include "server_conexion_cliente.h"
#include "server_controlador_de_tareas.h"




/* ****************************************************************************
 * DECLARACIÓN DE LA CLASE
 * ***************************************************************************/


class Servidor : public Thread {
private:

	Lista<ConexionCliente*> *clientes;			// Lista de clientes conectados
	int puerto;									// Puerto en el que se escucha.
	Socket socket;								// Socket en el que escucha el 
												// servidor.
	ControladorDeTareas *controlador;			// Controlador de tareas.
	Lista<std::string> *claves;					// Lista de posibles claves.

public:

	// Constructor
	Servidor(int puerto, std::string& msg, int numDigitosClave, 
		int numClientes);

	// Destructor
	~Servidor();

	// Define tareas a ejecutar en el hilo.
	// Mantiene a la escucha al servidor y acepta nuevos clientes.
	virtual void run();

	// Inicia la ejecución del servidor. No debe utilizarse el método start()
	// para iniciar. En caso de error lanza una excepción.
	void iniciar();

	// Espera hasta que se termine de ejecutar el servidor de forna natural.
	// POST: devuelve true al terminar.
	bool esperar();

	// Detiene la ejecución del servidor. No debe utilizarse el método stop()
	// para detener.
	void detener();

	// Envía a la salida estándar la situación en la que se encuentra al
	// momento de ser invocada.
	void imprimirSituacion();
};

#endif
