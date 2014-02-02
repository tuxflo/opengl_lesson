uniform float x;
uniform float y;
uniform float max_count;
attribute mat4 transformmatrix;

void main(void)
{
    mat4 matrix = gl_ModelViewProjectionMatrix * transformmatrix;
    vec4 direction = vec4(gl_Vertex); // 4th component is 0

    //direction.y += -3 * gl_InstanceID % 4;
    gl_FrontColor = vec4(0.0,1.0,0.0,1.0);
    gl_Position =gl_Vertex;
    //gl_Position = gl_ModelViewProjectionMatrix * direction;
}
