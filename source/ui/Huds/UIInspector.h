#ifndef UIInspector_CLASS_H
#define UIInspector_CLASS_H

#include "../UIBuilder.h"
#include "imgui.h"

class UIInspector : public UIBuilder
{
public:
	void Start() {
		Name = "Inspector";
	}

	void Draw() {
		ImGui::Begin (Name.c_str());

		ImGui::End   ();
	}
};
#endif // !UIHIERARCHY