#version 400

in vec3 position;
in vec3 color1;

out vec3 position2;
out vec3 color2;

void main()
{
	color2 = color1;
	position2 = position;
}