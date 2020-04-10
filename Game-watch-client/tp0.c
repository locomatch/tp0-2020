/*
 * main.c
 *
 *  Created on: 28 feb. 2019
 *      Author: utnso
 */

#include "tp0.h"
#include "strings.h"

int main(void)
{
	/*---------------------------------------------------PARTE 2-------------------------------------------------------------*/
	int conexion;
	char* ip;
	char* puerto;

	t_log* logger;
	t_config* config;

	logger = iniciar_logger();


	log_info(logger, "Soy el mejor log del mundo");

	config = leer_config();

	ip = config_get_string_value(config, "IP");
	puerto = config_get_string_value(config, "PUERTO");





	/*---------------------------------------------------PARTE 3-------------------------------------------------------------*/

	//antes de continuar, tenemos que asegurarnos que el servidor esté corriendo porque lo necesitaremos para lo que sigue.

	//crear conexion

	conexion = crear_conexion(ip, puerto);

	//enviar mensaje

	enviar_mensaje("Probando", conexion);

	//recibir mensaje

	while(1){

		int operacion;

		recv(conexion, &operacion, sizeof(int), MSG_WAITALL);

		if(operacion == 1){

		log_info(logger, recibir_mensaje(conexion));

		}

	}

	//terminar_programa(conexion, logger, config);
}

//TODO
t_log* iniciar_logger(void)
{
	t_log* log = log_create("tp0.log", "/home/utnso/SANTI/Game-watch-client/", true, LOG_LEVEL_INFO);

	return log;
}

//TODO
t_config* leer_config(void)
{
	t_config* config;

    config = config_create("/home/utnso/SANTI/Game-watch-client/tp0.config");
//	config_save_in_file(config, "/home/utnso/SANTI/Game-watch-client/tpCopia.config");


	return config;
}

//TODO
void terminar_programa(int conexion, t_log* logger, t_config* config)
{
	//Y por ultimo, para cerrar, hay que liberar lo que utilizamos (conexion, log y config) con las funciones de las commons y del TP mencionadas en el enunciado
	log_destroy(logger);
	config_destroy(config);
}
