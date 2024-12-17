// Import WiFi and ESPSupabase Library
#include <WiFi.h>
#include <ESPSupabase.h>

// Add you Wi-Fi credentials
const char *ssid = "Chamal's Galaxy M02s";
const char *password = "00000000";

// Supabase credentials
const char *supabaseUrl = "YOUR SUPABASE URL";
const char *supabaseKey = "SUPABASE ANON KEY";

Supabase supabase;

void setup()
{
    Serial.begin(115200);

    // Connect to Wi-Fi
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(1000);
        Serial.println("Connecting to Wi-Fi...");
    }
    Serial.println("Wi-Fi connected!");

    // Init Supabase
    supabase.begin(supabaseUrl, supabaseKey);

    // Add the table name here
    String tableName = "healthdata";
    // change the correct columns names you create in your table
    String jsonData = "{\"heartrate\": \"70\", \"bodytemp\": \"37\"}";

    // sending data to supabase
    int response = supabase.insert(tableName, jsonData, false);
    if (response == 200)
    {
        Serial.println("Data inserted successfully!");
    }
    else
    {
        Serial.print("Failed to insert data. HTTP response: ");
        Serial.println(response);
    }
}

void loop()
{
}