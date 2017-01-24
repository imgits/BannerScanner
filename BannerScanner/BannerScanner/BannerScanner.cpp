#include "stdafx.h"
#include "BannerScanner.h"


BannerScanner::BannerScanner()
{
}

BannerScanner::~BannerScanner()
{
}

bool BannerScanner::LoadScanItems(char* filename)
{
	FILE *fp = NULL;
	fopen_s(&fp, filename, "rt");
}
