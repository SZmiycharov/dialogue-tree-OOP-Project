#include "stdafx.h"
#include "DialogueTree.h"
#include <fstream>



DialogueOption::DialogueOption(string Text, DialogueNode *NextNode)
{
	text = Text;
	nextNode = NextNode;
}

DialogueNode::DialogueNode()
{
	text = "";
	id = 0;
}

DialogueNode::DialogueNode(string Text, int ID)
{
	text = Text;
	id = ID;
}

DialogueTree::DialogueTree()
{
}


void DialogueTree::load()
{
	DialogueNode **nodes;
	nodes = new DialogueNode*[5];

	for (int i = 0; i < 5; i++)
	{
		nodes[i] = new DialogueNode[10];
	}

	/*DialogueNode *node0 = new DialogueNode("", 0);
	DialogueNode *node1 = new DialogueNode("", 1);
	DialogueNode *node2 = new DialogueNode("", 2);
	DialogueNode *node3 = new DialogueNode("", 3);
	DialogueNode *node4 = new DialogueNode("", 4);*/

	string file = "D:\\Users\\Desktop\\file.txt";
	std::ifstream myfile(file);
	std::string str;
	string helper;
	string a, b;
	int c, d;
	char delimeter1 = ':';
	char delimeter2 = '=';
	int index = 0;
	int i = 0;
	while (getline(myfile, str))
	{
		index = str.find(delimeter1);
		c = atoi(str.substr(0, index).c_str()); //0
		a = str.substr(index + 2); //Hello brave warrior
		nodes[i]->text = a;
		nodes[i]->id = c;

		while (getline(myfile, str) && !str.empty())
		{
			index = str.find(delimeter2);
			b = str.substr(0, index); //vmesto: Sub noob
			d = atoi(str.substr(index + 3).c_str()); //vmesto: node4 (id = 3 i tova otgovarq na node4)

			switch (d)
			{
			case -1: nodes[i]->dialogueOptions.push_back(DialogueOption(b, nullptr)); break;
			case 1: nodes[i]->dialogueOptions.push_back(DialogueOption(b, nodes[0])); break;
			case 2: nodes[i]->dialogueOptions.push_back(DialogueOption(b, nodes[1])); break;
			case 3: nodes[i]->dialogueOptions.push_back(DialogueOption(b, nodes[2])); break;
			case 4: nodes[i]->dialogueOptions.push_back(DialogueOption(b, nodes[3])); break;
			case 5: nodes[i]->dialogueOptions.push_back(DialogueOption(b, nodes[4])); break;
			}
		}
		dialogueNodes.push_back(nodes[i]);
		i++;
	}
	

	
	/*getline(myfile, str);
	index = str.find(delimeter1);
	c = atoi(str.substr(0, index).c_str()); //0
	a = str.substr(index + 2); //Hello brave warrior
	node0->text = a;
	node0->id = c;

	while (getline(myfile, str) && !str.empty())
	{
		index = str.find(delimeter2);
		b = str.substr(0, index); //vmesto: Sub noob
		d = atoi(str.substr(index + 3).c_str()); //vmesto: node4 (id = 3 i tova otgovarq na node4)
		
		switch (d)
		{
		case -1: node0->dialogueOptions.push_back(DialogueOption(b, nullptr)); break;
		case 1: node0->dialogueOptions.push_back(DialogueOption(b, node0)); break;
		case 2: node0->dialogueOptions.push_back(DialogueOption(b, node1)); break;
		case 3: node0->dialogueOptions.push_back(DialogueOption(b, node2)); break;
		case 4: node0->dialogueOptions.push_back(DialogueOption(b, node3)); break;
		case 5: node0->dialogueOptions.push_back(DialogueOption(b, node4)); break;
		}
	}
	dialogueNodes.push_back(node0);

	getline(myfile, str);
	index = str.find(delimeter1);
	c = atoi(str.substr(0, index).c_str()); //0
	a = str.substr(index + 2); //Hello brave warrior
	node1->text = a;
	node1->id = c;

	while (getline(myfile, str) && !str.empty())
	{
		index = str.find(delimeter2);
		b = str.substr(0, index); //vmesto: Sub noob
		d = atoi(str.substr(index + 3).c_str()); //vmesto: node4 (id = 3 i tova otgovarq na node4)

		switch (d)
		{
		case -1: node1->dialogueOptions.push_back(DialogueOption(b, nullptr)); break;
		case 1: node1->dialogueOptions.push_back(DialogueOption(b,  node0)); break;
		case 2: node1->dialogueOptions.push_back(DialogueOption(b,  node1)); break;
		case 3: node1->dialogueOptions.push_back(DialogueOption(b,  node2)); break;
		case 4: node1->dialogueOptions.push_back(DialogueOption(b,  node3)); break;
		case 5: node1->dialogueOptions.push_back(DialogueOption(b,  node4)); break;
		}
	}
	dialogueNodes.push_back(node1);

	getline(myfile, str);
	index = str.find(delimeter1);
	c = atoi(str.substr(0, index).c_str()); //0
	a = str.substr(index + 2); //Hello brave warrior
	node2->text = a;
	node2->id = c;

	while (getline(myfile, str) && !str.empty())
	{
		index = str.find(delimeter2);
		b = str.substr(0, index); //vmesto: Sub noob
		d = atoi(str.substr(index + 3).c_str()); //vmesto: node4 (id = 3 i tova otgovarq na node4)

		switch (d)
		{
		case -1: node2->dialogueOptions.push_back(DialogueOption(b, nullptr)); break;
		case 1: node2->dialogueOptions.push_back(DialogueOption(b, node0)); break;
		case 2: node2->dialogueOptions.push_back(DialogueOption(b, node1)); break;
		case 3: node2->dialogueOptions.push_back(DialogueOption(b, node2)); break;
		case 4: node2->dialogueOptions.push_back(DialogueOption(b, node3)); break;
		case 5: node2->dialogueOptions.push_back(DialogueOption(b, node4)); break;
		}
	}
	dialogueNodes.push_back(node2);

	getline(myfile, str);
	index = str.find(delimeter1);
	c = atoi(str.substr(0, index).c_str()); //0
	a = str.substr(index + 2); //Hello brave warrior
	node3->text = a;
	node3->id = c;

	while (getline(myfile, str) && !str.empty())
	{
		index = str.find(delimeter2);
		b = str.substr(0, index); //vmesto: Sub noob
		d = atoi(str.substr(index + 3).c_str()); //vmesto: node4 (id = 3 i tova otgovarq na node4)

		switch (d)
		{
		case -1: node3->dialogueOptions.push_back(DialogueOption(b, nullptr)); break;
		case 1: node3->dialogueOptions.push_back(DialogueOption(b, node0)); break;
		case 2: node3->dialogueOptions.push_back(DialogueOption(b, node1)); break;
		case 3: node3->dialogueOptions.push_back(DialogueOption(b, node2)); break;
		case 4: node3->dialogueOptions.push_back(DialogueOption(b, node3)); break;
		case 5: node3->dialogueOptions.push_back(DialogueOption(b, node4)); break;
		}
	}
	dialogueNodes.push_back(node3);

	getline(myfile, str);
	index = str.find(delimeter1);
	c = atoi(str.substr(0, index).c_str()); //0
	a = str.substr(index + 2); //Hello brave warrior
	node4->text = a;
	node4->id = c;

	while (getline(myfile, str) && !str.empty())
	{
		index = str.find(delimeter2);
		b = str.substr(0, index); //vmesto: Sub noob
		d = atoi(str.substr(index + 3).c_str()); //vmesto: node4 (id = 3 i tova otgovarq na node4)
		
		switch (d)
		{
		case -1: node4->dialogueOptions.push_back(DialogueOption(b, nullptr)); break;
		case 1: node4->dialogueOptions.push_back(DialogueOption(b, node0)); break;
		case 2: node4->dialogueOptions.push_back(DialogueOption(b, node1)); break;
		case 3: node4->dialogueOptions.push_back(DialogueOption(b, node2)); break;
		case 4: node4->dialogueOptions.push_back(DialogueOption(b, node3)); break;
		case 5: node4->dialogueOptions.push_back(DialogueOption(b, node4)); break;
		}
	}
	dialogueNodes.push_back(node4);*/

	//node0->dialogueOptions.push_back(DialogueOption("Sub noob!" /*tuk e 3*/, 0, node1/*idto da e ot 4*/));
	//node0->dialogueOptions.push_back(DialogueOption("Hello strange voice!", 0, node2));
	//dialogueNodes.push_back(node0);

	//node1->dialogueOptions.push_back(DialogueOption("Aww!", 0, nullptr));
	//dialogueNodes.push_back(node1);

	//node2->dialogueOptions.push_back(DialogueOption("K bye.", 0, nullptr));
	//node2->dialogueOptions.push_back(DialogueOption("What is it?", 0, node4));
	//node2->dialogueOptions.push_back(DialogueOption("What's the pay?", 0, node3));
	//dialogueNodes.push_back(node2);

	//node3->dialogueOptions.push_back(DialogueOption("Ok what is it?", 0, node4));
	//node3->dialogueOptions.push_back(DialogueOption("That sucks I'm out.", 0, nullptr));
	//dialogueNodes.push_back(node3);

	//node4->dialogueOptions.push_back(DialogueOption("Let's do it!", 1, nullptr));
	//node4->dialogueOptions.push_back(DialogueOption("No way.", 0, nullptr));
	//dialogueNodes.push_back(node4);
}




int DialogueTree::performDialogue()
{
	if (dialogueNodes.empty())
	{
		return -1;
	}
	DialogueNode *currentNode = dialogueNodes[0];

	while (true)
	{
		cout << currentNode->text << "\n\n";

		for (int i = 0; i < currentNode->dialogueOptions.size(); i++)
		{
			cout << i + 1 << ": " << currentNode->dialogueOptions[i].text << endl;
		}
		cout << endl;
		int input;
		cin >> input;
		input--;
		if (input<0 || input>currentNode->dialogueOptions.size())
		{
			cout << "Invalid input!\n";
		}
		else
		{
			if (currentNode->dialogueOptions[input].nextNode == nullptr)
			{
				return currentNode->dialogueOptions[input].returnCode;
			}
			
			currentNode = currentNode->dialogueOptions[input].nextNode;
		}
		cout << endl;
	}
	return 0;
		
}