project "ImGui"
	kind "StaticLib"
	language "C++"
    staticruntime "on"

	targetdir ("Bin/" .. outputdir .. "/%{prj.name}")
	objdir ("Bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"imconfig.h",
		"imgui.h",
		"imgui.cpp",
		"imgui_draw.cpp",
		"imgui_internal.h",
		"imgui_widgets.cpp",
		"imstb_rectpack.h",
		"imstb_textedit.h",
		"imstb_truetype.h",
		"imgui_demo.cpp"
	}

	filter "system:windows"
		systemversion "latest"
		cppdialect "C++17"

	filter "system:linux"
		pic "On"
		systemversion "latest"
		cppdialect "C++17"
		toolset "clang"

	filter "configurations:Debug"
		runtime "Debug"
		warnings "Extra"
		symbols "on"
		optimize "on"

	filter "configurations:Release"
		runtime "Release"
		optimize "on"
