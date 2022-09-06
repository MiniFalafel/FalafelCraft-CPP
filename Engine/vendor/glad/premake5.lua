project "glad"
	location "glad"
	kind "StaticLib"
	language "C"
	staticruntime "on"
	
	targetdir ("bin/" .. outdir .. "/%{prj.name}")
	objdir ("bin/intermediates/" .. outdir .. "/%{prj.name}")
	
	files
	{
		"%{prj.name}/include/glad/glad.h",
		"%{prj.name}/include/KHR/khrplatform.h",
		"%{prj.name}/src/glad.c"
	}
	
	includedirs
	{
		"%{prj.name}/include"
	}
	
	filter "system:windows"
		systemversion "latest"
		
	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"
		
	filter "configurations:Release"
		runtime "Release"
		optimize "on"