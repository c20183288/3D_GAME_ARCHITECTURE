#version 330 core

in vec2 UV;
in vec3 Position_worldspace;
in vec3 Normal_cameraspace;
in vec3 EyeDirection_cameraspace;
in vec3 LightDirection_cameraspace;

out vec3 color;

uniform sampler2D myTextureSampler;
uniform mat4 MV;
uniform vec3 LightPosition_worldspace;

void main() {

	vec3 LightColor = vec3(1, 1, 1);
	float LightPower = 25.0f;

	vec3 MaterialDiffuseColor = texture(myTextureSampler, UV).rgb;

	float distance = length(LightPosition_worldspace - Position_worldspace);

	vec3 n = normalize(Normal_cameraspace);
	vec3 l = normalize(LightDirection_cameraspace);
	float cosTheta = clamp(dot(n, l), 0, 1);

	vec3 E = normalize(EyeDirection_cameraspace);
	vec3 R = reflect(-l, n);
	float cosAlpha = clamp(dot(E, R), 0, 1);

	vec3 ambient_color = vec3(0.25, 0, 0.25);

	color =
		(MaterialDiffuseColor * LightColor * LightPower * cosTheta / (distance * distance)) +
		(MaterialDiffuseColor * 0.345) +
		ambient_color;
}