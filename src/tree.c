/**
 The One Programming Language

 File: tree.c
  _        _
 / \ |\ | |_    Max Base
 \_/ | \| |_    Copyright 2021

 **/

#include "tree.h"
#include "vm.h"

size_t ident = 0;

void print_tabs(size_t n)
{
	for (size_t i = 0; i < n; i++)
	{
		printf("   ");
	}
}

void treeInit()
{
}


void treeStatement(AstStatement* stmt)
{
	printf("[STMT] %s\n", vmStatementName(stmt->type));
}
void treeStatements(AstStatements* stmts)
{
	ident++;
	for (size_t i = 0; i < stmts->count; i++)
	{
		print_tabs(ident);
		vmStatement(stmts->data[i]);
	}
	ident--;
}

void treeBlock(AstBlock* block)
{
	vmStatements(block->statements);
}

void treeFunction(AstFunction* func)
{
	print_tabs(ident);
	printf("[FUNC] %s\n", func->name);

	treeBlock(func->block);
}

void treeLog(AstRoot* root)
{
	if (root->package == NULL || strlen(root->package) == 0 || strcmp(root->package, "") == 0)
	{
		root->package = "main";
	}
	printf("=============== TREE ===============\n");

	printf("Package: %s\n", root->package);

	for (size_t i = 0; i < root->functions->count; i++)
	{
		treeFunction(root->functions->data[i]);
	}
}

void treeFree()
{
}