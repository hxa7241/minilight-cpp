@echo off


rem --- using: MS VC++ 2008 ---


set COMPILER=cl
set LINKER=link
rem for x64: maybe add /favor:AMD64 or /favor:INTEL64 to compiler options as appropriate
rem for x64: remove /arch:SSE from compiler options
set COMPILE_OPTIONS=/c /O2 /GL /arch:SSE /fp:fast /EHsc /GR- /GS- /MT /W4 /WL /nologo /Isrc



mkdir obj
del /Q obj\*



@echo.
@echo --- compile --

%COMPILER% %COMPILE_OPTIONS% src/Random.cpp /Foobj/Random.obj
%COMPILER% %COMPILE_OPTIONS% src/Vector3f.cpp /Foobj/Vector3f.obj

%COMPILER% %COMPILE_OPTIONS% src/Image.cpp /Foobj/Image.obj
%COMPILER% %COMPILE_OPTIONS% src/Triangle.cpp /Foobj/Triangle.obj
%COMPILER% %COMPILE_OPTIONS% src/SpatialIndex.cpp /Foobj/SpatialIndex.obj
%COMPILER% %COMPILE_OPTIONS% src/Scene.cpp /Foobj/Scene.obj
%COMPILER% %COMPILE_OPTIONS% src/SurfacePoint.cpp /Foobj/SurfacePoint.obj
%COMPILER% %COMPILE_OPTIONS% src/RayTracer.cpp /Foobj/RayTracer.obj
%COMPILER% %COMPILE_OPTIONS% src/Camera.cpp /Foobj/Camera.obj

%COMPILER% %COMPILE_OPTIONS% src/MiniLight.cpp /Foobj/MiniLight.obj



@echo.
@echo --- link --

%LINKER% /LTCG /NOLOGO /OUT:minilight-cpp.exe kernel32.lib obj/*.obj


del /Q obj\*
