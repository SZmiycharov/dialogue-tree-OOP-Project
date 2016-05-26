// dialogueTreeGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <list>

#include "DialogueTree.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	DialogueTree dialogueTree;

	dialogueTree.load();
	dialogueTree.performDialogue();
	cout << "\n              *****************    THE END!    *****************"<<"\n\n";
	
	system("pause");
	return 0;
}

