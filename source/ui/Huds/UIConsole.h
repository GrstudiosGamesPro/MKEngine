#ifndef UICONSOLE_CLASS_H
#define UICONSOLE_CLASS_H

#include "../UIBuilder.h"
#include "imgui.h"

class UIConsole : public UIBuilder
{
public:
	void Start() {
		Name = "Console";
	}

	void Draw() {
		ImGui::Begin (Name.c_str());

		ImGui::End   ();
	}
};
#endif // !UIHIERARCHY