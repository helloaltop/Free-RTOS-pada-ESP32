#include <Arduino.h>

// Fungsi tugas pertama
void Task1(void *pvParameters) {
    while (1) {
        digitalWrite(27, HIGH);
        vTaskDelay(500 / portTICK_PERIOD_MS); // Delay 1 detik
        digitalWrite(27, LOW);
        vTaskDelay(500 / portTICK_PERIOD_MS); // Delay 1 detik
    }
}

// Fungsi tugas kedua
void Task2(void *pvParameters) {
    while (1) {
        digitalWrite(14, HIGH);
        vTaskDelay(500 / portTICK_PERIOD_MS); // Delay 1 detik
        digitalWrite(14, LOW);
        vTaskDelay(500 / portTICK_PERIOD_MS); // Delay 1 detik
    }
}

void setup() {
    Serial.begin(115200);
    pinMode(27, OUTPUT);
    pinMode(14, OUTPUT);

    // Membuat tugas pertama
    xTaskCreate(Task1, "Task 1", 2048, NULL, 1, NULL);
    // Membuat tugas kedua
    xTaskCreate(Task2, "Task 2", 2048, NULL, 1, NULL);
}

void loop() {
    // Tidak ada apa-apa di loop()
}
