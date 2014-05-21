#version 400

in vec4 color3;
in vec2 texCoords;
out vec4 outColor;

uniform vec4 override;

uniform sampler2D texture1;

void main()
{
	outColor = override * color3 * texture(texture1, texCoords);
}