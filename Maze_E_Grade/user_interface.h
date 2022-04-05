/*
Description: A automatic maze-generator console-application that trough a simple CLI-type user-interface creates and presents mazes with dimension 11x11 on demand.

Attempted grade: E.

Created by: Jesper Eriksson(jeer1902) @ Mid Sweden Uneversity.

Course: DT026G(Mid Sweden Uneversity).

Last Modified: 2022-04-05.

Used references in project:
Cplusplus.com: https://www.cplusplus.com/reference/cstdlib/rand/

Additional notes: This program was created on and primarly is recomanded to be executed om Microsoft Visual Studio.

*/

#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

void print_startmenu();
void print_op_one(); //defaultmaze 11x11
void print_op_two(); //exit
void print_user_input();
void print_wrong_input();


#endif // !USER_INTERFACE_H
