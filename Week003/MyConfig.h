#pragma once

struct _BufByte {
	char myByte;
};
struct _Version {
	short major;
	short minor;
	short revision;
};
struct _WiFi {
	char SSID[51];
	_BufByte BuffW1;
	char Pswd[51];
	_BufByte BuffW2;
};
struct Config {
	_Version Version;
	_WiFi Wifi;
	_BufByte Buff1;
};