//
// Header para variables globales del proyecto
//

#ifndef GLOBALS_H
#define GLOBALS_H

#include "error_manager.h"
#include "ast.h"

/* DECLARAR VARIABLES GLOBALES COMO EXTERNAS */
extern ErrorManager* global_error_manager;
extern ASTNode* ast_root;

#endif // GLOBALS_H