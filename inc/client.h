#pragma once /* Include Guards */

/* @file client.h
 * @authors Tomas Ramos & Shawn Ng
 * @brief Declares and documents all functions from the client side.
 * @date 2/06/2018
 */


/* @brief Launches client-side.
 * @author Tomas Aleixo Ramos
 * @date 2/06/2018
 * @return Integer 0=Successful Launch, 1=Failed Launch.
 *
 * @details Launches the client program and creates socket to seek for
 * connections. Allows user to request for files via terminal based interaction.
 *
 * @todo All functions to by executed by the client should be added in here.
 */
int launch_client(void);
