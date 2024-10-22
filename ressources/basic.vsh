attribute highp vec4 posAttr;
attribute lowp vec4 colAttr;
varying lowp vec4 col;
uniform highp mat4 matrix;

void main() {
   col = colAttr;
   gl_PointSize = 4.0;
   gl_Position = matrix * posAttr;
}

