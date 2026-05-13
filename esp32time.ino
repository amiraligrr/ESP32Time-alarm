#include <ESP32Time.h> 
#include <LiquidCrystal.h>

// تنظیمات RTC
ESP32Time rtc(0);

// تنظیمات LCD (پایه‌ها)
const int rs = 15, en = 4, d4 = 5, d5 = 18, d6 = 19, d7 = 21;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// محدوده زمانی هشدار (دقیقه)
const int ALERT_START_MINUTE = 5;
const int ALERT_END_MINUTE = 7;

void setup() {
    Serial.begin(9600);
    lcd.begin(16, 2);
    
    // تنظیم زمان: دقیقه، ساعت، روز، ماه، سال
    // سال 2026، ماه 12 (دسامبر)، روز 5، ساعت 19، دقیقه 46
    rtc.setTime(46, 19, 5, 12, 2026);
}

void loop() {
    int currentMinute = rtc.getMinute();
    
    if (currentMinute > ALERT_START_MINUTE && currentMinute < ALERT_END_MINUTE) {
        alert();
    } else {
        show_time();
    }
    
    delay(1000); // به‌روزرسانی هر ثانیه (اختیاری)
}

void show_time() {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Time: ");
    lcd.print(rtc.getTime());
    
    lcd.setCursor(0, 1);
    lcd.print("Date: ");
    lcd.print(rtc.getDate());
}

void alert() {
    lcd.clear();
    lcd.setCursor(4, 0);
    lcd.print("ALERT!!!");
    lcd.setCursor(2, 1);
    lcd.print("It's time!");
}
