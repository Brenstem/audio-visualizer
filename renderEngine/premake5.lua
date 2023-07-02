workspace "renderEngine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "renderEngine"
	location "renderEngine"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-obj/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "10.0.19041.0"

		includedirs
        {
            "$(SolutionDir)/external/glfw-3.3.8.bin.WIN64/include",
			"$(SolutionDir)/external/glm-master",
			"C:/VulkanSDK/1.3.250.1/Include"
        }

        libdirs
        {
            "$(SolutionDir)/external/glfw-3.3.8.bin.WIN64/lib-vc2022",
			"C:/VulkanSDK/1.3.250.1/Lib"
        }

        links
        {
			"vulkan-1.lib",
            "glfw3_mt.lib"
        }

		flags 
		{
			"MultiProcessorCompile"
		}


    filter { "configurations:Debug" }
		defines { "DEBUG" }
		symbols "On"

    filter { "configurations:Release" }
        defines { "NDEBUG" }
        optimize "On"

	

