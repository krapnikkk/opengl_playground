#version 330 core
// in vec4 vertexColor;
//in vec2 texCoord;
uniform sampler2D sampler;
uniform sampler2D sampler2;
uniform vec3 objColor;
uniform vec3 ambientColor;

uniform vec3 lightPos;
uniform vec3 lightColor;


in vec3 fragPos;
in vec3 normal;

out vec4 FragColor;
void main(){
	vec3 lightDirection = normalize(lightPos - fragPos);
	vec3 diffuse = max(dot(lightDirection,normal),0)*lightColor;
	// FragColor = vertexColor;
//	FragColor = mix(texture(sampler,texCoord),texture(sampler2,texCoord),0.2);
//	FragColor = vec4((objColor * ambientColor),1.0); 
	FragColor = vec4(vec3(diffuse + diffuse)* objColor,1.0); 
}