#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "tree.h"

/*
bool isValid(Scanner * s){
        Token nextT = nextToken(s);
        if (nextT.type == T_VAL)
                return true;
        else if (nextT.type == T_LPAREN){
		isValid(s);
		if( ( (nextT.type == T_ADD) || (nextT.type == T_SUB) ||(nextT.type == T_MULT) ||(nextT.type == T_DIV)) != 1 )
		{ return false }
		else { 
		  isValid(s);
		  if (nextT.type == T_RPAREN)
			return true;
		  else
			return false;
		}
        }
	else {return false;}
}
*/

#ifndef BUILDTREE_OFF
TreeNode * buildExpressionTree(Scanner * s) {
        Token nextT = nextToken(s);
	TreeNode * root = NULL;
	if ( nextT.type == T_VAL){ // isDigit( nextT )
		root->t = nextT;  
                return root;
	   }
        else if ( nextT.type == T_LPAREN ){
                root->left = buildExpressionTree(s); // ??
                if( ( (nextT.type == T_ADD) || (nextT.type == T_SUB) ||(nextT.type == T_MUL) ||(nextT.type == T_DIV)) != 1 )
                  root->right = buildExpressionTree(s); // ???
                else if (nextT.type == T_RPAREN)
                        return root;
                }
	return root;        
}
#endif

#ifndef POSTFIX_OFF
void makePostFix(TreeNode * t, FILE * fptr) {
	if (t == NULL)
		return;
	else{
	  makePostFix(t->left, fptr);
	  makePostFix(t->right, fptr);
	  printToken(t->t,fptr); // what type is this ??
	}
	return;
}
#endif
