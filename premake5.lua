workspace "EppoCompiles"
    architecture "x86_64"
    startproject "EppoCompiles"

    configurations {
        "Debug",
        "Release"
    }

    flags {
        "MultiProcessorCompile"
    }

    OutputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

    include "EppoCompiles"
    include "EppoCompilesC"
