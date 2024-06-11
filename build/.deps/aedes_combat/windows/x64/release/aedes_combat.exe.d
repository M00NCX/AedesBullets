{
    files = {
        [[build\.objs\aedes_combat\windows\x64\release\src\Character.cpp.obj]],
        [[build\.objs\aedes_combat\windows\x64\release\src\Game.cpp.obj]],
        [[build\.objs\aedes_combat\windows\x64\release\src\GameScreen.cpp.obj]],
        [[build\.objs\aedes_combat\windows\x64\release\src\HelpScreen.cpp.obj]],
        [[build\.objs\aedes_combat\windows\x64\release\src\Main.cpp.obj]],
        [[build\.objs\aedes_combat\windows\x64\release\src\Menu.cpp.obj]],
        [[build\.objs\aedes_combat\windows\x64\release\src\Mosquito.cpp.obj]],
        [[build\.objs\aedes_combat\windows\x64\release\src\Mouse.cpp.obj]],
        [[build\.objs\aedes_combat\windows\x64\release\src\Projectile.cpp.obj]],
        [[build\.objs\aedes_combat\windows\x64\release\src\Texture.cpp.obj]]
    },
    values = {
        [[C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.39.33519\bin\HostX64\x64\link.exe]],
        {
            "-nologo",
            "-dynamicbase",
            "-nxcompat",
            "-machine:x64",
            [[-libpath:C:\Users\vinic\AppData\Local\.xmake\packages\f\freeglut\v3.4.0\9e1e9a63d6b948868b158c0a7189e4ed\lib]],
            [[-libpath:C:\Users\vinic\AppData\Local\.xmake\packages\g\glew\2.2.0\6a8fc1e310a44318beb712a418386242\lib]],
            "freeglut_static.lib",
            "glu32.lib",
            "glew32s.lib",
            "gdi32.lib",
            "winmm.lib",
            "user32.lib",
            "advapi32.lib",
            "opengl32.lib"
        }
    }
}