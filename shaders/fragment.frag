#version 460

out vec4 FragColor;
in vec2 TexCoord;

uniform sampler2D tex;

void main()
{
    FragColor = texture(tex, TexCoord) * vec4(1.f, 1.f, 0.f, 1.f);
}