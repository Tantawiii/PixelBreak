#version 330 core
in vec2 TexCoords;
out vec4 color;

uniform sampler2D scene;
uniform bool confuse;
uniform bool chaos;
uniform bool shake;

void main()
{
    vec3 texColor = texture(scene, TexCoords).rgb;
    if (confuse)
        texColor = texColor.bgr; // Simple confusion effect
    if (chaos)
        texColor += vec3(0.1); // Brightness increase for chaos effect
    if (shake)
        texColor = texColor * vec3(0.5, 0.7, 1.0); // Tint for shake effect
    color = vec4(texColor, 1.0);
}
