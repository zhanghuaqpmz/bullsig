#!/bin/bash
MAKE_RULE=./Makefile.rule
set_project_path()
{
	sed -i "s%\(^PROJECT_ROOT_PATH:=\).*%\1$PWD%" $MAKE_RULE
}

if [ $# -eq 0 ] 
then
	set_project_path
fi
