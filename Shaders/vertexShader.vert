#version 330 core
layout (location = 0) in vec3 aPos;

out float y_offset;


void main()
{
    y_offset = aPos.y;
    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
}