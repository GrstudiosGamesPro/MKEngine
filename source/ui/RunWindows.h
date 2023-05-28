#ifndef WINDOWSHUDS_CLASS_H
#define WINDOWSHUDS_CLASS_H
#include "Huds/UIHierarchy.h"
#include "Huds/UIAssets.h"
#include "Huds/UIConsole.h"
#include "Huds/UIInspector.h"
#include "Huds/UIScene.h"

class RunWindows
{
public:
	UIHierarchy* hierarchy = new UIHierarchy();
	UIConsole* console = new UIConsole();
	UIAssets* assets = new UIAssets();
	UIInspector* inspector = new UIInspector();
	UIScene* scene = new UIScene();




	void Start() {
		hierarchy->Start();
		console->Start();
		assets->Start();
		inspector->Start();
		scene->Start();
	}

	void Draw() {
		hierarchy->Draw();
		console->Draw();
		assets->Draw();
		inspector->Draw();
		scene->Draw();
	}
};
#endif