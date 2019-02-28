#version 330 core
out vec4 FragColor;

in float y_offset;

const float PI = 3.141592f;

uniform float seconds;
uniform float scanline;

void main()
{

    float blah = 0.25f * sin(100*y_offset + seconds*3);
    blah += 0.4f;

    float n_offset = (y_offset+1.0f)/2;

    float alpha = cos(PI*n_offset - (scanline*PI)) + 1;
    alpha = 0.007-alpha;
    alpha = alpha *100;

    //blah += alpha;

    alpha = max(blah, alpha);
    alpha = alpha * 0.8;

    FragColor = vec4(1.0f, 0.5f, 0.5f, alpha);
}