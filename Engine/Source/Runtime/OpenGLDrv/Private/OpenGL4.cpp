// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

/*=============================================================================
	OpenGL4.cpp: OpenGL 4.3 implementation.
=============================================================================*/

#include "OpenGLDrvPrivate.h"

#if OPENGL_GL4

GLint FOpenGL4::MaxComputeTextureImageUnits = -1;
GLint FOpenGL4::MaxComputeUniformComponents = -1;
bool FOpenGL4::bSupportsComputeShaders = true;

void FOpenGL4::ProcessQueryGLInt()
{
#ifndef __clang__
#define LOG_AND_GET_GL_INT(IntEnum, Default, Dest) do { if (IntEnum) {glGetIntegerv(IntEnum, &Dest);} else {Dest = Default;} /*FPlatformMisc::LowLevelOutputDebugStringf(TEXT("  ") ## TEXT(#IntEnum) ## TEXT(": %d"), Dest);*/ } while(0)
#else
#define LOG_AND_GET_GL_INT(IntEnum, Default, Dest) do { if (IntEnum) {glGetIntegerv(IntEnum, &Dest);} else {Dest = Default;} /*FPlatformMisc::LowLevelOutputDebugStringf(TEXT("  " #IntEnum ": %d"), Dest);*/ } while(0)
#endif

	LOG_AND_GET_GL_INT(GL_MAX_COMPUTE_TEXTURE_IMAGE_UNITS, 0, MaxComputeTextureImageUnits);
	LOG_AND_GET_GL_INT(GL_MAX_COMPUTE_UNIFORM_COMPONENTS, 0, MaxComputeUniformComponents);
	LOG_AND_GET_GL_INT(GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS, 0, MaxHullUniformComponents);
	LOG_AND_GET_GL_INT(GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS, 0, MaxDomainUniformComponents);
	if ( MaxComputeTextureImageUnits == -1 || MaxComputeUniformComponents == -1 || MaxHullUniformComponents == -1 || MaxDomainUniformComponents == -1 )
	{
		bSupportsComputeShaders = false;
	}
}

void FOpenGL4::ProcessExtensions( const FString& ExtensionsString )
{
	ProcessQueryGLInt();
	FOpenGL3::ProcessExtensions(ExtensionsString);
}

#endif
