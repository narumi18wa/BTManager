/*
 * btmanager.cpp
 *
 *  Created on: 2014/09/08
 *      Author: derushio
 */

#include "BTManager.h"

SoftwareSerial btSerial(BT_RX, BT_TX);
char esc[] = { 2, 2, 2 };

BTManager::BTManager(String BTName) {
	this->BTName = BTName;
	response = "";

	connectionStatus = false;
	pairingStatus = false;

	btSerial.begin(BT_BAUD);
}

void BTManager::begin() {
	Serial.println("Starting Device...");

	delay(1500);
	btSerial.print(esc);
	Serial.println("esc");
	delay(1500);

	btSerial.print("AT\r");
	Serial.println("AT");

	delay(1500);

	btSerial.print("ATZ\r");
	Serial.println("ATZ");

	delay(1500);

	btSerial.print("AT+BTNAME=" + BTName + "\r");
	Serial.println("AT+BTNAME=" + BTName + "\r");

	delay(1500);

	btSerial.print("AT+BTKEY=1234\r");
	Serial.println("AT+BTKEY=1234");

	delay(1500);

	btSerial.print("AT+BTSCAN\r");
	Serial.println("AT+BTSCAN");
	
	delay(1500);

	btSerial.print("AT+BTINFO?0\r");
	Serial.println("AT+BTINFO?0");

	delay(1500);

	Serial.println("Sterted Device.");
}
