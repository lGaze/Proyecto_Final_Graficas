//--------------------------------------------------------------------------------------
// File: Tutorial07.fx
//
// Copyright (c) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------
#version 400
//--------------------------------------------------------------------------------------
// Constant Buffer Variables
//--------------------------------------------------------------------------------------
in sampler2D txDiffuse;

    in mat4 View;
    in mat4 Projection;
    in mat4 World;
    vec4 vMeshColor;

    layout(location = 0) in vec4 Position;
    layout(location = 1) in vec2 Tex;
    

//--------------------------------------------------------------------------------------

  in vec2 Texcrd;




  out vec2 Texcrd;



  
//--------------------------------------------------------------------------------------
// Vertex Shader
//--------------------------------------------------------------------------------------
 
void main(void)
{
    mat4 vp = Projection * View;
    gl_position = vp * World * Position;
    Texcrd = Tex;
}