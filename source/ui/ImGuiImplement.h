#ifndef IMGUIIMPLEMENT_CLASS_H
#define IMGUIIMPLEMENT_CLASS_H
#include <SDL.h>
#include <imgui.h>
#include <imgui_impl_sdl2.h>
#include <imgui_impl_sdlrenderer.h>
#include <iostream>
#include "RunWindows.h"

using namespace std;

class ImGuiImplement
{
public:
	RunWindows* windowsHUD = new RunWindows();


	void SetupUI (SDL_Window* window, SDL_Renderer* render) {
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();

		ImGuiIO& io = ImGui::GetIO(); (void)io;
		io.ConfigFlags = ImGuiConfigFlags_DockingEnable;

		ImGui_ImplSDL2_InitForSDLRenderer(window, render);
		ImGui_ImplSDLRenderer_Init(render);

		windowsHUD->Start();
	}

	void Render (SDL_Event event) {
		ImGui_ImplSDL2_ProcessEvent(&event);

		ImGui_ImplSDLRenderer_NewFrame();
		ImGui_ImplSDL2_NewFrame();

		ImGui::NewFrame();
	    DrawUI();
		ImGui::EndFrame();

		ImGui::Render();
	}

	void GetRenderDrawData() {
		ImGui_ImplSDLRenderer_RenderDrawData(ImGui::GetDrawData());
	}

	void DrawUI() {
		ImGui::DockSpaceOverViewport(nullptr, ImGuiDockNodeFlags_PassthruCentralNode);
		windowsHUD->Draw();
	}

	void Clean() {
		ImGui_ImplSDLRenderer_Shutdown();
		ImGui_ImplSDL2_Shutdown();
		ImGui::DestroyContext();
	}

};

#endif