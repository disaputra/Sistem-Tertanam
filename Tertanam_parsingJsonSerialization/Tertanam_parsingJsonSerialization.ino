#include <ArduinoJson.h>

void setup() {
  // Initialize Serial port
  Serial.begin(9600);
  while (!Serial) continue;

  // Allocate the JSON document
  //
  // Inside the brackets, 200 is the RAM allocated to this document.
  // Don't forget to change this value to match your requirement.
  // Use arduinojson.org/v6/assistant to compute the capacity.
  StaticJsonDocument<200> doc;

  // StaticJsonObject allocates memory on the stack, it can be
  // replaced by DynamicJsonDocument which allocates in the heap.
  //
  // DynamicJsonDocument  doc(200);

  // Add values in the document
  //
  doc["sensor"] = "dht11";
  doc["time"] = 1351824120;

  // Add an array.
  //
  JsonArray data = doc.createNestedArray("data");
  data.add(40.3);
  data.add(77.7);

  // Generate the minified JSON and send it to the Serial port.
  //
  serializeJson(doc, Serial);
  // The above line prints:
  // {"sensor":"dht11","time":1351824120,"data":[440.3,77.7]}

  // Start a new line
  Serial.println();

  // Generate the prettified JSON and send it to the Serial port.
  //
  serializeJsonPretty(doc, Serial);
  // The above line prints:
  // {
  //   "sensor": "dht11",
  //   "time": 1351824120,
  //   "data": [
  //     40.3,
  //     77.7
  //   ]
  // }
}

void loop() {
  // not used in this example
}
