#include <iostream>
#include <string>

#define STB_IMAGE_IMPLEMENTATION
#include "third_party/stb/stb_image.h"

void decode_steganography(int image_data[], int data_size, std::string key) {
    int currentIndex = 1000;
    int keyLength = key.length();
    int keyIndex = 0;

    while (true) {

        int jump = (int)key[keyIndex % keyLength];

        currentIndex += jump;

        if (currentIndex >= data_size) {
            std::cerr << "[ERROR] Index out of bounds." << std::endl;
            break;
        }

        int value = image_data[currentIndex];
        if (value == 0) break;

        std::cout << (char)value;

        keyIndex++;
    }
}


// DO NOT EDIT THE MAIN FUNCTION
int main() {
    const char* image_path = "secret.png";
    int width, height, channels;

    unsigned char* img_data_char = stbi_load(image_path, &width, &height, &channels, 1);

    int data_size = width * height;

    int* image_data_int = new int[data_size];
    for (int i = 0; i < data_size; ++i) {
        image_data_int[i] = (int)img_data_char[i];
    }

    stbi_image_free(img_data_char);

    std::string user_key;
    std::cout << "Of the four pillars of OOP, what is the principle of separating interface and implementation? (First letter capitalized): ";
    std::cin >> user_key;

    std::cout << "------------------------------------------" << std::endl;
    decode_steganography(image_data_int, data_size, user_key);
    std::cout << "\n------------------------------------------" << std::endl;

    delete[] image_data_int;

    return 0;
}
