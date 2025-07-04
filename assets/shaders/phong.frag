#version 330 core

struct Light {
    vec3 position;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;

    float constant;
    float linear;
    float quadratic;
};

in vec2 vTexCoord;
in vec3 vFragPos;
in vec3 vNormal;

uniform vec3 uViewPos;
uniform sampler2D uTexture;
uniform Light uLight;

out vec4 oColor;

void main()
{
    vec3 ambient = uLight.ambient * texture(uTexture, vTexCoord).rgb;

    vec3 norm = normalize(vNormal);
    vec3 lightDir = normalize(uLight.position - vFragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = uLight.diffuse * diff * texture(uTexture, vTexCoord).rgb;
    
    vec3 viewDir = normalize(uViewPos - vFragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32.0);
    vec3 specular = uLight.specular * spec * texture(uTexture, vTexCoord).rgb;

    if(diff == 0)
        specular = vec3(0.0, 0.0, 0.0);

    float distance = length(uLight.position - vFragPos);
    float attenuation = 1.0 / (uLight.constant + uLight.linear * distance + uLight.quadratic * (distance * distance));

    ambient *= attenuation;
    diffuse *= attenuation;
    specular *= attenuation;

    vec3 result = ambient + diffuse + specular;
    oColor = vec4(result, 1.0);
}