project "sdl"
	kind "StaticLib"
	language "C"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"include/SDL.h",
		"include/SDL_vulkan.h"
	}
	filter "system:linux"

		systemversion "latest"
		staticruntime "On"

		toolset "clang"

		files
		{
			"include/SDL.h",
			"include/SDL_vulkan.h"
		}

		defines
		{

		}

	filter "system:windows"
		systemversion "latest"
		staticruntime "On"

		files
		{

		}

		defines 
		{ 
			"_CRT_SECURE_NO_WARNINGS"
		}

	filter "configurations:Debug"
		runtime "Debug"
		warnings "Extra"
		symbols "on"

	filter "configurations:Release"
		runtime "Release"
		optimize "on"
