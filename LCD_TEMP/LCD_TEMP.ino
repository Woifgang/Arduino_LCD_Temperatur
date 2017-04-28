#include <LiquidCrystal.h>
#include <DallasTemperature.h>
#include <OneWire.h>

// --------- LCD Display ---------
LiquidCrystal lcd(9, 8, 6, 5, 4, 3);
#define LCD_WIDTH 16                  // Anzahl der Spalten im Display
#define LCD_HEIGHT 2                  // Anzahl der Zeilen im Display

// --------- Temperatur ---------
#define ONE_WIRE_BUS 13
#define TEMPERATURE_PRECISION 5
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

int numberOfDevices;

DeviceAddress tempDeviceAddress;

DeviceAddress adresseEins;
DeviceAddress adresseZwei;

void setup(void) {

  // --------- LCD Display ---------
  // Display Init
  lcd.begin(LCD_WIDTH, LCD_HEIGHT, 1);
  lcd.setCursor(0,0);
  lcd.print("####  WOID  ####");
  lcd.setCursor(0,1);
  lcd.print("####  v0.0  ####");
  delay(500);
  lcd.clear();

  // Dallas Bibliothek Starten
  sensors.begin();

  numberOfDevices = sensors.getDeviceCount(); // Anzahl der Sensoren
  
  lcd.setCursor(0,0);
  lcd.print("Suche DS1820...");
  delay(1000);
  lcd.setCursor(0,1);
  lcd.print(numberOfDevices, DEC);
  lcd.setCursor(5,1);
  lcd.print(" gefunden");
  delay(1000);
  lcd.clear();
}

void temperaturAusgeben(DeviceAddress deviceaddress, char str[10])
{
  float tempC = sensors.getTempC(deviceaddress);
  lcd.setCursor(0,0);
  lcd.print(str);
  lcd.setCursor(3,1);
  lcd.print(tempC);
  lcd.setCursor(9,1);
  lcd.print((char)223);  // ° Symbol
  lcd.setCursor(10,1);
  lcd.print("C");
  delay(3000);
  lcd.clear();
}

void loop(void) {
 
 sensors.requestTemperatures();
 for(int i=0;i<numberOfDevices; i++)
 {
  if(sensors.getAddress(tempDeviceAddress,0))
  {
    temperaturAusgeben(tempDeviceAddress,"    Buero");
  }
  if(sensors.getAddress(tempDeviceAddress,1))
  {
    temperaturAusgeben(tempDeviceAddress,"    Garten");
  }
 }
 
}
