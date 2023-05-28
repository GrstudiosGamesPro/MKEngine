#ifndef ENGINE_MANAGER_H
#define ENGINE_MANAGER_H
#include <iostream>

using namespace std;

class StartEngine
{
public:
	void Start();
	~StartEngine ();

	//Engine name
	string Name = "MKMaker 2D";
	//Engine FPS
	int MaxFPS = 165;
};
#endif