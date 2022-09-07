workspace "FalafelCraft"
	architecture "x86_64"
	startproject "Game"
	
	configurations
	{
		"Debug",
		"Release"
	}
	

outdir = "%{cfg.buildcfg}-%{cfg.architecture}"

include "Engine/vendor/glfw/"
include "Engine/vendor/glad/"

project "Engine"
	location "Engine"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"
	
	targetdir ("bin/" .. outdir .. "/%{prj.name}")
	objdir ("bin/intermediates/" .. outdir .. "/%{prj.name}")
	
	files
	{
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/src/**.h"
	}
	
	defines
	{
		"GLFW_INCLUDE_NONE"
	}
	
	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/glfw/glfw/include",
		"%{prj.name}/vendor/glad/glad/include"
	}
	
	links
	{
		"glad",
		"glfw",
		"opengl32.lib"
	}
	
	filter "system:windows"
		systemversion "latest"
	
	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"
		defines "FC_DEBUG"
		
	filter "configurations:Release"
		runtime "Release"
		optimize "on"
		defines "FC_RELEASE"

project "Game"
	location "Game"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"
	
	targetdir ("bin/" .. outdir .. "/%{prj.name}")
	objdir ("intermediates/" .. outdir .. "/%{prj.name}")
	
	files
	{
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/src/**.h"
	}
	
	includedirs
	{
		"Engine/src"
	}
	
	links
	{
		"Engine"
	}
	
	filter "system:windows"
		systemversion "latest"
	
	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"
		defines "FC_DEBUG"
		
	filter "configurations:Release"
		runtime "Release"
		optimize "on"
		defines "FC_RELEASE"