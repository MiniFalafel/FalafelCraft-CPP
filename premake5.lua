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

project "Engine"
	location "Engine"
	kind "StaticLib"
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
		"%{prj.name}/src",
		"%{prj.name}/vendor/glfw/glfw/include"
	}
	
	links
	{
		"glfw"
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
		
	filter "configurations:Release"
		runtime "Release"
		optimize "on"