struct TempAndHumidity {
  float temperature;
  float humidity;
};

struct ParticleRangeMeasurement {
  uint16_t pm1;
  uint16_t pm25;
  uint16_t pm10;  
};

struct
{
    uint32_t total;
    uint32_t ok;
    uint32_t crc_error;
    uint32_t time_out;
    uint32_t connect;
    uint32_t ack_l;
    uint32_t ack_h;
    uint32_t unknown;
} counter = { 0,0,0,0,0,0,0,0};