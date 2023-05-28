#ifndef UIHIERARCHY_CLASS_H
#define UIHIERARCHY_CLASS_H

#include "../UIBuilder.h"
#include "imgui.h"

class UIHierarchy : public UIBuilder
{
public:
	void Start() {
		Name = "Hierarchy";
	}

	void Draw() {
		ImGui::Begin (Name.c_str());

		ImGui::End   ();
	}
};
#endif // !UIHIERARCHY