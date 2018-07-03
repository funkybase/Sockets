#pragma once /* Include Guards */

/* @file server.h
 * @authors Tomas Ramos & Shawn Ng
 * @brief Declares and documents all functions from the server.
 * @date 2/06/2018
 */


/* @brief Launches the server code.
 * @author Tomas Aleixo Ramos
 * @date 2/06/2018
 * @return Integer 0=Successful Launch, 1=Failed Launch.
 *
 * @details Launches the server Daemon and creates socket to listen for
 * connections.
 *
 * @todo All functions to execute by the server should be added in here.
 */
void launch_server(void);
