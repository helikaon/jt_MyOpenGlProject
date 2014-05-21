#version 400

layout(points) in;
layout(triangle_strip, max_vertices = 36) out;

in vec3 position2[];
in vec3 color2[];

out vec4 color3;
out vec2 texCoords;

uniform mat4 trans;

void main()
{
	color3 = vec4(color2[0],1);
	float f = 0.5f;

	vec4 vertices[] =
	{
		trans * (vec4(position2[0], 1) + vec4(0,0,0,0)),
		trans * (vec4(position2[0], 1) + vec4(0,0,f,0)),
		trans * (vec4(position2[0], 1) + vec4(0,f,0,0)),
		trans * (vec4(position2[0], 1) + vec4(0,f,f,0)),
		trans * (vec4(position2[0], 1) + vec4(f,0,0,0)),
		trans * (vec4(position2[0], 1) + vec4(f,0,f,0)),
		trans * (vec4(position2[0], 1) + vec4(f,f,0,0)),
		trans * (vec4(position2[0], 1) + vec4(f,f,f,0)),
	};

	vec2 tex[] =
	{
		vec2(+0,+0),
		vec2(+0,+1),
		vec2(+1,+0),
		vec2(+1,+1),
	};

	int texElements[] =
	{
		0,1,2,
		2,1,3
	};

	int elements[] =
	{
		6,4,2,
		2,4,0,
			
		1,5,3,
		3,5,7,
			
		1,3,0,
		0,3,2,
			
		4,6,5,
		5,6,7,

		2,3,6,
		6,3,7,

		0,4,1,
		1,4,5,
	};

	uint uiIndex = 0;
	for(uint uiTri = 0; uiTri < 12; ++uiTri)
	{
		for(uint uiVert = 0; uiVert < 3; ++uiVert)
		{
			gl_Position = vertices[elements[uiIndex]];
			texCoords = tex[texElements[uiIndex % 6]];
			++uiIndex;
			EmitVertex();
		}
        
		EndPrimitive();
	}
}