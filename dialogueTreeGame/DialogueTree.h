#pragma once
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class DialogueNode;

class DialogueOption
{
public:
	DialogueOption(string Text, DialogueNode *NextNode);
	string text;
	DialogueNode *nextNode;
	int returnCode;
};

class DialogueNode
{
public:
	DialogueNode();
	DialogueNode(string Text, int ID);
	string text;
	int id;
	vector <DialogueOption> dialogueOptions;
};

class DialogueTree
{
public:
	DialogueTree();

	void load();

	int performDialogue();
private:
	vector <DialogueNode *> dialogueNodes;
};