#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

// Define the output pin and pixel config for the NeoPixel ring
#define LED_PIN1 A0
#define LED_COUNT 24 
#define RING_CYCLE_RATE 20
#define RING_FILL_RATE 50

// Initialize our NeoPixel Ring controller object
Adafruit_NeoPixel ring(LED_COUNT, LED_PIN1, NEO_GRB + NEO_KHZ800);

// Define our color selector swatch keys
#define BLACK       0
#define WHITE       1
#define RED         2
#define ORANGE      3
#define YELLOW      4
#define LIME        5
#define GREEN       6
#define MINT        7
#define CYAN        8
#define CORNFLOWER  9
#define BLUE       10
#define PURPLE     11
#define MAGENTA    12
#define PINK       13

// Define our color swatches
uint32_t colorSwatches [14] = {
  ring.Color(0, 0, 0),          // BLACK
  ring.Color(255, 255, 255),    // WHITE
  ring.Color(255, 0, 0),        // RED
  ring.Color(255, 127, 0),      // ORANGE 
  ring.Color(255, 255, 0),      // YELLOW
  ring.Color(127, 255, 0),      // LIME
  ring.Color(0, 255, 0),        // GREEN
  ring.Color(0, 255, 127),      // MINT
  ring.Color(0, 255, 255),      // CYAN
  ring.Color(0, 127, 255),      // CORNFLOWER
  ring.Color(0, 0, 255),        // BLUE
  ring.Color(127, 0, 255),      // PURPLE
  ring.Color(255, 0, 255),      // MAGENTA
  ring.Color(255, 0, 127),      // PINK
}; 
 
/**
 * @brief Rainbow cycle along whole ring.
 * 
 * @param wait duration (ms) between color cycling
 */
void rainbowCycle(uint16_t wait) {
  // Hue of first pixel runs 5 complete loops through the color wheel.
  for(long firstPixelHue = 0; firstPixelHue < 5*65536; firstPixelHue += 256) {
    for(int i=0; i<ring.numPixels(); i++) { // For each pixel in ring...
      // Offset pixel hue by an amount to make one full revolution
      int pixelHue = firstPixelHue + (i * 65536L / ring.numPixels());
      // ring.ColorHSV() can take 1 or 3 arguments: a hue (0 to 65535) or
      // optionally add saturation and value (brightness) (each 0 to 255).
      ring.setPixelColor(i, ring.gamma32(ring.ColorHSV(pixelHue))); 
    }
    ring.show(); // Update strip with new contents
    delay(wait);
  }
}

/**
 * @brief Fills all pixels with the given color
 * 
 * @param color the 32-bit RGB color to project
 * @param wait the duration (ms) to delay between filling pixels
 */
void fullColor(uint32_t color, uint8_t wait) {
  for(uint16_t i=0; i<ring.numPixels(); i++) {
    ring.setPixelColor(i, color);
    ring.show();
    delay(wait);
  }
}

/**
 * @brief Fills every-other pixel with the given Color
 * 
 * @param color the 32-bit RGB color to project
 * @param offset the pixel offset for the first pixel (0,1)
 * @param wait the duration (ms) to delay between filling pixels
 */
void alternateColor(uint32_t color, uint8_t offset, uint8_t wait) {
  for(uint16_t j=offset; j<ring.numPixels(); j+=2) {
    ring.setPixelColor(j, color);
    ring.show();
    delay(wait);
  }
}

void setup() {
  ring.begin();           // INITIALIZE NeoPixel strip object
  ring.setBrightness(36);
  ring.show();
}

void loop() {
  fullColor(colorSwatches[WHITE], 0);
  ring.show();
  delay(2000);
  fullColor(colorSwatches[RED], RING_FILL_RATE);
  ring.show();
  delay(1200);
  fullColor(colorSwatches[ORANGE], RING_FILL_RATE);
  ring.show();
  delay(1200);
  fullColor(colorSwatches[YELLOW], RING_FILL_RATE);
  ring.show();
  delay(1200);
  fullColor(colorSwatches[LIME], RING_FILL_RATE);
  ring.show();
  delay(1200);
  fullColor(colorSwatches[GREEN], RING_FILL_RATE);
  ring.show();
  delay(1200);
  fullColor(colorSwatches[MINT], RING_FILL_RATE);
  ring.show();
  delay(1200);
  fullColor(colorSwatches[CYAN], RING_FILL_RATE);
  ring.show();
  delay(1200);
  fullColor(colorSwatches[CORNFLOWER], RING_FILL_RATE);
  ring.show();
  delay(1200);
  fullColor(colorSwatches[BLUE], RING_FILL_RATE);
  ring.show();
  delay(1200);
  fullColor(colorSwatches[MAGENTA], RING_FILL_RATE);
  ring.show();
  delay(1200);
  fullColor(colorSwatches[PINK], RING_FILL_RATE);
  ring.show();
  delay(1200);
  rainbowCycle(RING_CYCLE_RATE);
  ring.show();
  delay(2000);
}
