workspace "visualizerGUI"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "visualizerGUI"
	location "visualizerGUI"
	kind "ConsoleApp"
	language "C#"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-obj/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.cs",
		"src/**.xaml",
		"src/**.config"
	}

	filter "system:windows"
		csversion ".Net"
		staticruntime "On"
		systemversion "10.0.19041.0"


    filter { "configurations:Debug" }
		defines { "DEBUG" }
		symbols "On"

    filter { "configurations:Release" }
        defines { "NDEBUG" }
        optimize "On"

	

