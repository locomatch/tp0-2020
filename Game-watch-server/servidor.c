/*
 * servidor.c
 *
 *  Created on: 3 mar. 2019
 *      Author: utnso
 */

#include "servidor.h"


int main(void)
{

	loggerServer = log_create("tp0.log", "/home/utnso/SANTI/Game-watch-server/", true, LOG_LEVEL_INFO);

	log_info(loggerServer, "Bienvenido Nahuelin!");


	iniciar_servidor();

	return EXIT_SUCCESS;
}
/*
t_log* iniciar_logger(void)
{
	t_log* log = log_create("tp0.log", "/home/utnso/SANTI/Game-watch-server/", true, LOG_LEVEL_INFO);

	return log;
}
*/
