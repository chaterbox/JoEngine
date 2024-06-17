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
IncludeDirs["GLFW"] = "Engine/Vendor/glfw/include"
IncludeDirs["glad"] = "Engine/Vendor/glad/include"
IncludeDirs["ImGui"] = "Engine/Vendor/imgui"
IncludeDirs["glm"] = "Engine/Vendor/glm"
IncludeDirs["vkBootStrap"] = "Engine/Vendor/vkbootstrap"
IncludeDirs["vma"] = "Engine/Vendor/vma"

include "Engine/Vendor/glfw"
include "Engine/Vendor/glad"
include "Engine/Vendor/imgui"

project "Engine"
location "Engine"
kind "StaticLib"
language "C++"
cppdialect "C++17"
staticruntime "on"

targetdir ("bin/")
objdir ("bin-int/")

pchheader "Joepch.h"
pchsource "Engine/Src/Joepch.cpp"

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
	"%{prj.name}/Vendor/vulkan/Include/vulkan",
	"%{IncludeDirs.GLFW}",
	"%{IncludeDirs.glad}",
	"%{IncludeDirs.ImGui}",
	"%{IncludeDirs.glm}",
  "%{IncludeDirs.vkBootStrap}",
  "%{IncludeDirs.vma}"
}
libdirs
{
	"%{prj.name}/Vendor/vulkan/Lib"
}


filter "system:windows"

systemversion "latest"

links
{
	"GLFW",
	"glad",
	"ImGui",
	"vulkan-1.lib"
}

defines
{
	"JOE_PLATFORM_WINDOWS",
	"JOE_BUILD_DLL",
	"GLFW_INCLUDE_NONE"
}

filter "system:linux"

toolset "clang"

links
{
	"GLFW",
	"glad",
	"ImGui",
	"vulkan-1.lib"
}

defines
{
	"JOE_PLATFORM_LINUX",
	"GLFW_INCLUDE_NONE"
}

filter "configurations:Debug"
defines {"JOE_DEBUG","JOE_ENABLE_ASSERTS","JOE_ENABLE_VK_ASSERT"}
warnings "Extra"
symbols "on"

filter "configurations:Release"
defines "JOE_RELEASE"
optimize "on"

filter "configurations:Dist"
defines "JOE_DIST"
symbols "on"

project "Sandbox"
location "Sandbox"
kind "ConsoleApp"
language "C++"
cppdialect "C++17"
staticruntime "on"

targetdir ("bin/")
objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

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
	"%{IncludeDirs.glm}"
}

links
{
	"Engine"
}

filter "system:windows"

systemversion "latest"

defines
{
	"JOE_PLATFORM_WINDOWS"
}

filter "system:linux"

toolset "clang"

links
{
	"GLFW",
	"Glad",
	"ImGui",
	"Xrandr",
	"Xi",
	"GLU",
	"GL",
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

filter "configurations:Debug"
defines "JOE_DEBUG"
warnings "Extra"
symbols "on"

filter "configurations:Release"
defines "JOE_RELEASE"
optimize "on"

filter "configurations:Dist"
defines "JOE_DIST"
symbols "on"
