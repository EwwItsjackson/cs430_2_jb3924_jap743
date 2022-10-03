int main() {


}

float createVector(float x, float y, float z) {
    float *vector = (float*) malloc(sizeof(float) * DIMENTION);
    vector[0] = x;
    vector[1] = y;
    vector[2] = z;
}