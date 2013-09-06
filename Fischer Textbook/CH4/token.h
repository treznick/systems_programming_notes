// =============================================================================
// Project: Bracket-matching example of stack usage                File: token.h 
// ============================================================================= 
#ifndef TOKEN_H
#define TOKEN_H

#include "tools.h"

typedef enum {BKT_SQ, BKT_RND, BKT_CURLY, BKT_ANGLE, BKT_NONE} Bracket_type;
typedef enum {SENSE_LEFT, SENSE_RIGHT} Token_sense;

typedef struct {
	Bracket_type typ;
	Token_sense sense;
	char ch; 
} Token;

Token classify( char ch );
#endif // TOKEN_H 
