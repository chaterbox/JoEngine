#include "Joepch.h"
#include "ImGuiLayer.h"

//#include "imgui.h"

#include "Joe/Core/Application.h"

namespace Joe{
	ImGuiLayer::ImGuiLayer()
		: Layer("ImGuiLayer"){}

	ImGuiLayer::~ImGuiLayer(){}

	void ImGuiLayer::OnAttach(){
		// Setup Dear ImGui context
		/*IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO(); (void)io;
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;       // Enable Keyboard Controls
		//io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
		io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;           // Enable Docking
		io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;         // Enable Multi-Viewport / Platform Windows
		//io.ConfigFlags |= ImGuiConfigFlags_ViewportsNoTaskBarIcons;
		//io.ConfigFlags |= ImGuiConfigFlags_ViewportsNoMerge;

		// Setup Dear ImGui style
		ImGui::StyleColorsDark();
		//ImGui::StyleColorsClassic();

		// When viewports are enabled we tweak WindowRounding/WindowBg so platform windows can look identical to regular ones.
		ImGuiStyle& style = ImGui::GetStyle();
		if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable){
			style.WindowRounding = 0.0f;
			style.Colors[ImGuiCol_WindowBg].w = 1.0f;
		}
    */
		Application& app = Application::Get();

		// Setup Platform/Renderer bindings
		
    //TODO: add ImGui_ImplVulkan_Init
	}

	void ImGuiLayer::OnDetach(){
    //TODO: add ImGui_ImplVulkan_Shutdown
		//ImGui::DestroyContext();
	}

	void ImGuiLayer::Begin(){
    //TODO: add ImGui_ImplVulkan_NewFrame
		//ImGui::NewFrame();
	}

	void ImGuiLayer::End(){
		/*ImGuiIO& io = ImGui::GetIO();
		Application& app = Application::Get();
		io.DisplaySize = ImVec2((float)app.GetWindow().GetWidth(), (float)app.GetWindow().GetHeight());

		// Rendering
		ImGui::Render();
    //TODO: add ImGui_ImplVulkan_RenderDrawData

		if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable){
			ImGui::UpdatePlatformWindows();
			ImGui::RenderPlatformWindowsDefault();
		}*/
	}

	void ImGuiLayer::OnImGuiRender(){
	}
}
