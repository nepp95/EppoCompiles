project "EppoCompilesC"
    kind "ConsoleApp"
    language "C"

    targetdir ("%{wks.location}/Bin/" .. OutputDir .. "/%{prj.name}")
    objdir ("%{wks.location}/Bin-Int/" .. OutputDir .. "/%{prj.name}")

    files {
        "Source/**.h",
        "Source/**.c"
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
