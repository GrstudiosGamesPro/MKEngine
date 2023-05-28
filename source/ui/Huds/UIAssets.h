#ifndef UIASSET_CLASS_H
#define UIASSET_CLASS_H

#include "../UIBuilder.h"
#include "imgui.h"

class UIAssets : public UIBuilder
{
public:
	void Start() {
		Name = "Assets";
	}

	void Draw() {
		ImGui::Begin (Name.c_str());

		ImGui::End   ();
	}
};
#endif // !UIHIERARCHY