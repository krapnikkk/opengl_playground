#version 330 core
// in vec4 vertexColor;
in vec2 texCoord;
uniform sampler2D sampler;
uniform sampler2D sampler2;
uniform vec3 objColor;
uniform vec3 ambientColor;

out vec4 FragColor;
void main(){
	// FragColor = vertexColor;
//	FragColor = mix(texture(sampler,texCoord),texture(sampler2,texCoord),0.2);
	FragColor = vec4((objColor * ambientColor),1.0); 
}