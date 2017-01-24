#pragma once
#include <string>
#include <list>
#include <Windows.h>
struct ScanItem
{
	UINT32 ip;
	UINT16 port;
};

class BannerScanner
{
	ScanItem* scan_item_list;
	int scan_item_count;
public:
	BannerScanner();
	~BannerScanner();
	bool LoadScanItems(char* filename);
};

