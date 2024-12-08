workspace "Engine"
architecture "x64"
startproject "Sandbox"

configurations
{
	"Release",
	"Debug",
	"Dist"
}
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDirs = {}
IncludeDirs["ImGui"] = "Engine/Vendor/imgui"
IncludeDirs["glm"] = "Engine/Vendor/glm"
IncludeDirs["vkBootStrap"] = "Engine/Vendor/vkbootstrap"
IncludeDirs["vma"] = "Engine/Vendor/vma"

include "Engine/Vendor/imgui"

project "Engine"
location "Engine"
kind "StaticLib"
language "C++"
cppdialect "C++17"
staticruntime "on"

targetdir ("Bin/" .. outputdir .. "/%{prj.name}")
objdir ("Bin-int/" .. outputdir .. "/%{prj.name}")

pchheader "Joepch.h"
pchsource "Engine/Src/Joepch.cpp"

filter "system:windows"

systemversion "latest"

files
{
	"%{prj.name}/Src/**.h",
	"%{prj.name}/Src/**.cpp",
	"%{prj.name}/Vendor/glm/glm/**.hpp",
	"%{prj.name}/Vendor/glm/glm/**.inl",
	"%{prj.name}/Vendor/vkbootstrap/**.h",
	"%{prj.name}/Vendor/vkbootstrap/**.cpp",
	"%{prj.name}/Vendor/vma/**.h"
}

defines
{
	"_CRT_SECURE_NO_WARNINGS"
}

includedirs
{
	"%{prj.name}/Src",
	"%{prj.name}/Vendor/spdlog/include",
	"%{IncludeDirs.ImGui}",
	"%{IncludeDirs.glm}",
	"%{IncludeDirs.vkBootStrap}",
	"%{IncludeDirs.vma}",
	"%{prj.name}/Vendor/SDL3/include/",
	"%{prj.name}/Vendor/vulkan/Include",
	"%{prj.name}/Vendor/mINI/Include/"
}

libdirs
{
	"%{prj.name}/Vendor/vulkan/Lib/WIN32",
	"%{prj.name}/Vendor/SDL3/lib/WIN32",
}

links
{
	"SDL3",
	"ImGui",
	"vulkan-1.lib"
}

defines
{
	"JOE_PLATFORM_WINDOWS",
	"JOE_BUILD_DLL",
}

filter "system:linux"

toolset "clang"

files
{
	"%{prj.name}/Src/**.h",
	"%{prj.name}/Src/**.cpp",
	"%{prj.name}/Vendor/glm/glm/**.hpp",
	"%{prj.name}/Vendor/glm/glm/**.inl",
	"%{prj.name}/Vendor/vkbootstrap/**.h",
	"%{prj.name}/Vendor/vkbootstrap/**.cpp",
	"%{prj.name}/Vendor/vma/**.h"
}

defines
{
	"_CRT_SECURE_NO_WARNINGS"
}

includedirs
{
	"%{prj.name}/Src",
	"%{prj.name}/Vendor/spdlog/include",
	"%{IncludeDirs.ImGui}",
	"%{IncludeDirs.glm}",
	"%{IncludeDirs.vkBootStrap}",
	"%{IncludeDirs.vma}",
	"%{prj.name}/Vendor/SDL3/include/",
	"%{prj.name}/Vendor/vulkan/Include",
	"%{prj.name}/Vendor/mINI/Include"
}

libdirs
{
	"%{prj.name}/Vendor/vulkan/Lib/linux",
	"%{prj.name}/Vendor/SDL3/lib/linux",
}

links
{
	"SDL",
	"ImGui",
	"vulkan-1.lib"
}

defines
{
	"JOE_PLATFORM_LINUX",
}

filter "system:macosx"

files
{
	"%{prj.name}/Src/**.h",
	"%{prj.name}/Src/**.cpp",
	"%{prj.name}/Vendor/glm/glm/**.hpp",
	"%{prj.name}/Vendor/glm/glm/**.inl",
	"%{prj.name}/Vendor/vkbootstrap/**.h",
	"%{prj.name}/Vendor/vkbootstrap/**.cpp",
	"%{prj.name}/Vendor/vma/**.h"
}

defines
{
	"_CRT_SECURE_NO_WARNINGS"
}

includedirs
{
	"%{prj.name}/Src",
	"%{prj.name}/Vendor/spdlog/include",
	"%{IncludeDirs.ImGui}",
	"%{IncludeDirs.glm}",
	"%{IncludeDirs.vkBootStrap}",
	"%{IncludeDirs.vma}",
	"%{prj.name}/Vendor/SDL2/include/",
	"%{prj.name}/Vendor/vulkan/Include"
}


libdirs
{
	"%{prj.name}/Vendor/vulkan/Lib/",
	"%{prj.name}/Vendor/SDL2/lib/",
}

links
{
	"SDL2",
	"ImGui",
	"vulkan-1.lib"
}

defines
{
	"JOE_PLATFORM_MACOS",
	"JOE_BUILD_DLL",
}

filter "configurations:Debug"
defines {"JOE_DEBUG","JOE_ENABLE_ASSERTS","JOE_ENABLE_VK_ASSERT"}
warnings "Extra"
symbols "on"
optimize "on"

filter "configurations:Release"
defines "JOE_RELEASE"
optimize "on"

filter "configurations:Dist"
defines "JOE_DIST"
optimize "on"
targetdir ("Bin/%{prj.name}")

project "Sandbox"
location "Sandbox"
kind "ConsoleApp"
language "C++"
cppdialect "C++17"
staticruntime "on"

targetdir ("Bin/" .. outputdir .. "/%{prj.name}")
objdir ("Bin-int/" .. outputdir .. "/%{prj.name}")

filter "system:windows"

systemversion "latest"

files
{
	"%{prj.name}/Src/**.h",
	"%{prj.name}/Src/**.cpp"
}

includedirs
{
	"Engine/Vendor/spdlog/include",
	"Engine/Src",
	"Engine/Vendor",
	"%{IncludeDirs.glm}",
	"Engine/Vendor/SDL3/include/"
}

defines
{
	"JOE_PLATFORM_WINDOWS"
}

libdirs{
	"Engine/Vendor/vulkan/Lib/WIN32",
 	"Engine/Vendor/SDL3/lib/WIN32",
}

links 
{
	"Engine",
	"shaderc_combined"
}

postbuildcommands
{
	{"xcopy /y /d $(SolutionDir)Engine\\Vendor\\SDL3\\lib\\WIN32\\SDL3.dll $(TargetDir)"}
}

filter "system:linux"

toolset "clang"

files
{
	"%{prj.name}/Src/**.h",
	"%{prj.name}/Src/**.cpp"
}

includedirs
{
	"Engine/Vendor/spdlog/include",
	"Engine/Src",
	"Engine/Vendor",
	"%{IncludeDirs.glm}",
	"Engine/Vendor/SDL3/include/",
	"Engine/Vendor/mINI/Include/"
}

libdirs{
	"Engine/Vendor/vulkan/Lib/linux",
 	"Engine/Vendor/SDL3/lib/linux",
}

links
{
	"Engine",
	"SDL3",
	"shaderc_combined",
	"ImGui",
	"Xrandr",
	"Xi",
	"X11",
	"dl",
	"pthread",
	"stdc++fs",
	"vulkan"
}

defines
{
	"JOE_PLATFORM_LINUX"
}

filter "system:macosx"

files
{
	"%{prj.name}/Src/**.h",
	"%{prj.name}/Src/**.cpp"
}

includedirs
{
	"Engine/Vendor/spdlog/include",
	"Engine/Src",
	"Engine/Vendor",
	"%{IncludeDirs.glm}",
	"Engine/Vendor/SDL2/include/"
}

links
{
	"Engine"
}

libdirs{
	"Engine/Vendor/vulkan/Lib/",
 	"Engine/Vendor/SDL2/lib/",
}

defines
{
	"JOE_PLATFORM_MACOS"
}

filter "configurations:Debug"
defines "JOE_DEBUG"
warnings "Extra"
symbols "on"
optimize "on"

filter "configurations:Release"
defines "JOE_RELEASE"
optimize "on"

filter "configurations:Dist"
defines "JOE_DIST"
optimize "on"
targetdir ("Bin/%{prj.name}")

project "Editor"
location "Editor"
kind "ConsoleApp"
language "C++"
cppdialect "C++17"
staticruntime "on"

targetdir ("Bin/" .. outputdir .. "/%{prj.name}")
objdir ("Bin-int/" .. outputdir .. "/%{prj.name}")

filter "system:windows"

systemversion "latest"

files
{
	"%{prj.name}/Src/**.h",
	"%{prj.name}/Src/**.cpp"
}

includedirs
{
	"Engine/Vendor/spdlog/include",
	"Engine/Src",
	"Engine/Vendor",
	"%{IncludeDirs.glm}",
	"Engine/Vendor/SDL3/include/"
}

defines
{
	"JOE_PLATFORM_WINDOWS"
}

libdirs{
	"Engine/Vendor/vulkan/Lib/WIN32",
 	"Engine/Vendor/SDL3/lib/WIN32",
}

links 
{
	"Engine",
	"shaderc_combined"
}

postbuildcommands
{
	{"xcopy /y /d $(SolutionDir)Engine\\Vendor\\SDL3\\lib\\WIN32\\SDL3.dll $(TargetDir)"}
}

filter "system:linux"

toolset "clang"

files
{
	"%{prj.name}/Src/**.h",
	"%{prj.name}/Src/**.cpp"
}

includedirs
{
	"Engine/Vendor/spdlog/include",
	"Engine/Src",
	"Engine/Vendor",
	"%{IncludeDirs.glm}",
	"Engine/Vendor/SDL3/include/",
	"Engine/Vendor/mINI/Include/"
}

libdirs{
	"Engine/Vendor/vulkan/Lib/linux",
 	"Engine/Vendor/SDL3/lib/linux",
}

links
{
	"Engine",
	"SDL3",
	"shaderc_combined",
	"ImGui",
	"Xrandr",
	"Xi",
	"X11",
	"dl",
	"pthread",
	"stdc++fs",
	"vulkan"
}

defines
{
	"JOE_PLATFORM_LINUX"
}

filter "system:macosx"

files
{
	"%{prj.name}/Src/**.h",
	"%{prj.name}/Src/**.cpp"
}

includedirs
{
	"Engine/Vendor/spdlog/include",
	"Engine/Src",
	"Engine/Vendor",
	"%{IncludeDirs.glm}",
	"Engine/Vendor/SDL2/include/"
}

links
{
	"Engine"
}

libdirs{
	"Engine/Vendor/vulkan/Lib/",
 	"Engine/Vendor/SDL2/lib/",
}

defines
{
	"JOE_PLATFORM_MACOS"
}

filter "configurations:Debug"
defines "JOE_DEBUG"
warnings "Extra"
symbols "on"
optimize "on"

filter "configurations:Release"
defines "JOE_RELEASE"
optimize "on"

filter "configurations:Dist"
defines "JOE_DIST"
optimize "on"
targetdir ("Bin/%{prj.name}")
