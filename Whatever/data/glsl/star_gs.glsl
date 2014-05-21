#version 400

layout(points) in;
layout(triangle_strip, max_vertices = 72) out;

in vec3 position2[];
in vec3 color2[];

out vec4 color3;
out vec2 texCoords;

uniform mat4 trans;

void main()
{
	texCoords = vec2(0,0);
	color3 = vec4(color2[0],1);
	float f = 0.25f;
	float r = 3.141592654f / 180.0f;

	vec4 vertices[] =
	{
		trans * (vec4(position2[0], 1) + vec4(0, 0,-f,0)),

		trans * (vec4(position2[0], 1) + vec4(cos(r *  30),  sin(r *   30), 0,0) * 1.0f),
		trans * (vec4(position2[0], 1) + vec4(cos(r *  60),  sin(r *   60), 0,0) * 0.5f),
		trans * (vec4(position2[0], 1) + vec4(cos(r *  90),  sin(r *   90), 0,0) * 1.0f),
		trans * (vec4(position2[0], 1) + vec4(cos(r * 120),  sin(r *  120), 0,0) * 0.5f),
		trans * (vec4(position2[0], 1) + vec4(cos(r * 150),  sin(r *  150), 0,0) * 1.0f),
		trans * (vec4(position2[0], 1) + vec4(cos(r * 180),  sin(r *  180), 0,0) * 0.5f),
		trans * (vec4(position2[0], 1) + vec4(cos(r * 210),  sin(r *  210), 0,0) * 1.0f),
		trans * (vec4(position2[0], 1) + vec4(cos(r * 240),  sin(r *  240), 0,0) * 0.5f),
		trans * (vec4(position2[0], 1) + vec4(cos(r * 270),  sin(r *  270), 0,0) * 1.0f),
		trans * (vec4(position2[0], 1) + vec4(cos(r * 300),  sin(r *  300), 0,0) * 0.5f),
		trans * (vec4(position2[0], 1) + vec4(cos(r * 330),  sin(r *  330), 0,0) * 5.0f),
		trans * (vec4(position2[0], 1) + vec4(cos(r * 360),  sin(r *  360), 0,0) * 0.5f),
		
		trans * (vec4(position2[0], 1) + vec4(0, 0, f,0)),
	};

	vec4 colours[] =
	{
		vec4(0,0,0,1),

		vec4(1,1,0.65f,1),
		vec4(1,1,0.65f,1),
		vec4(1,1,0.65f,1),
		vec4(1,1,0.65f,1),
		vec4(1,1,0.65f,1),
		vec4(1,1,0.65f,1),
		vec4(1,1,0.65f,1),
		vec4(1,1,0.65f,1),
		vec4(1,1,0.65f,1),
		vec4(1,1,0.65f,1),
		vec4(1,0,0.65f,1),
		vec4(1,1,0.65f,1),
		
		vec4(0,0,0,1),
	};

	int o = 13;
	int elements[] =
	{
		0,  1,  2,
		0,  2,  3,
		0,  3,  4,
		0,  4,  5,
		0,  5,  6,
		0,  6,  7,
		0,  7,  8,
		0,  8,  9,
		0,  9, 10,
		0, 10, 11,
		0, 11, 12,
		0, 12,  1,

		o,  2,  1,
		o,  3,  2,
		o,  4,  3,
		o,  5,  4,
		o,  6,  5,
		o,  7,  6,
		o,  8,  7,
		o,  9,  8,
		o, 10,  9,
		o, 11, 10,
		o, 12, 11,
		o,  1, 12,

	};

	uint uiIndex = 0;
	for(uint uiTri = 0; uiTri < 24; ++uiTri)
	{
		for(uint uiVert = 0; uiVert < 3; ++uiVert)
		{
			gl_Position = vertices[elements[uiIndex]];
			color3 = colours[elements[uiIndex]];
			++uiIndex;
			EmitVertex();
		}
        
		EndPrimitive();
	}
}