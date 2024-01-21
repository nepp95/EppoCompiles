project "EppoCompiles"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"

    targetdir ("%{wks.location}/Bin/" .. OutputDir .. "/%{prj.name}")
    objdir ("%{wks.location}/Bin-Int/" .. OutputDir .. "/%{prj.name}")

    pchheader "pch.h"
    pchsource "Source/pch.cpp"

    files {
        "Source/**.h",
        "Source/**.cpp"
    }

    includedirs {
        "Source"
    }

    filter "configurations:Debug"
        defines "EPPO_DEBUG"
        runtime "Debug"
        symbols "On"
    
    filter "configurations:Release"
        defines "EPPO_RELEASE"
        runtime "Release"
        optimize "On"
