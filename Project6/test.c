#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdint.h>
#include "weights.h"   // The file exported from Python

#define INPUT_SIZE 784
#define HIDDEN_SIZE 128
#define OUTPUT_SIZE 10

// ReLU activation
float relu(float x) {
    return x > 0 ? x : 0;
}

int predict(float input[INPUT_SIZE]) {
    float hidden[HIDDEN_SIZE];
    float output[OUTPUT_SIZE];

    // Hidden Layer: hidden = relu(W1*x + B1)
    for (int i = 0; i < HIDDEN_SIZE; i++) {
        float sum = B1[i];
        for (int j = 0; j < INPUT_SIZE; j++)
            sum += W1[i*INPUT_SIZE + j] * input[j];
        hidden[i] = relu(sum);
    }

    // Output Layer: output = W2*hidden + B2
    for (int i = 0; i < OUTPUT_SIZE; i++) {
        float sum = B2[i];
        for (int j = 0; j < HIDDEN_SIZE; j++)
            sum += W2[i*HIDDEN_SIZE + j] * hidden[j];
        output[i] = sum;  // no softmax needed for prediction
    }

    // Argmax
    int max_index = 0;
    float max_value = output[0];
    for (int i = 1; i < OUTPUT_SIZE; i++) {
        if (output[i] > max_value) {
            max_value = output[i];
            max_index = i;
        }
    }

    return max_index;
}
void load_mnist(const char* image_path, int index, float input[784]) {
    FILE* f = fopen(image_path, "rb");
    if (!f) {
        printf("Error: Cannot open file %s\n", image_path);
        exit(1);
    }

    // Read header
    uint32_t magic, num_images, rows, cols;

    fread(&magic, 4, 1, f);
    fread(&num_images, 4, 1, f);
    fread(&rows, 4, 1, f);
    fread(&cols, 4, 1, f);

    // Convert big-endian → little-endian
    magic = __builtin_bswap32(magic);
    num_images = __builtin_bswap32(num_images);
    rows = __builtin_bswap32(rows);
    cols = __builtin_bswap32(cols);

    if (magic != 2051) {
        printf("Error: Invalid MNIST image file (magic=%u)\n", magic);
        exit(1);
    }

    if (index < 0 || index >= num_images) {
        printf("Error: index %d out of range (0-%u)\n", index, num_images - 1);
        exit(1);
    }

    // Each image = 28 * 28 = 784 bytes
    const int image_size = rows * cols;

    // Seek to the image you want
    fseek(f, 16 + index * image_size, SEEK_SET);

    unsigned char buffer[784];
    fread(buffer, 1, image_size, f);
    fclose(f);

    // Normalize pixels to 0.0–1.0
    for (int i = 0; i < 784; i++) {
        input[i] = buffer[i] / 255.0f;
    }
}

int main() {
    float sample[784];

    // Example: load a test image or fill array manually
    // For now, fill with zero:
    for (int i = 0; i < 784; i++) sample[i] = 0;

    int digit = predict(sample);
    printf("Predicted digit: %d\n", digit);

    return 0;
}
