#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include "BannerScanner.h"


BannerScanner::BannerScanner()
{
}

BannerScanner::~BannerScanner()
{
	if (scan_item_list != NULL)
	{
		delete[] scan_item_list;
		scan_item_list = NULL;
	}
}

bool BannerScanner::LoadScanItems(char* filename)
{
	FILE *fp = NULL;
	if (fopen_s(&fp, filename, "rb")!=0)
	{
		return false;
	}
	fseek(fp, 0, SEEK_END);
	int filesize = ftell(fp);
	char* filebuf = new char[filesize + 1];
	if (filebuf == NULL)
	{
		goto error;
	}
	rewind(fp);
	if (fread(filebuf, 1, filesize, fp) != filesize)
	{
		goto error;
	}
	filebuf[filesize] = 0;
	char* line = filebuf;
	scan_item_count = 0;
	//计算扫描项数量
	do
	{
		if (memcmp(line, "open tcp ", 9) == 0) scan_item_count++;
		line = strchr(line, '\n');
		if (line == NULL) break;
		line++;
	} while (*line != 0);
	scan_item_list = new ScanItem[scan_item_count];
	if (scan_item_list == NULL)
	{
		goto error;
	}
	line = filebuf;
	int item_index = 0;
	do
	{
		int port, ip32,ip1, ip2, ip3, ip4, tick;
		if ( sscanf(line, "open tcp %d %d.%d.%d.%d %d\r\n",&port,&ip1,&ip2,&ip3,&ip4,&tick)==6)
		{
			ip32 = (ip1 << 24) + (ip2 << 16) + (ip3 << 8) + ip4;
			scan_item_list[item_index].ip = ip32;
			scan_item_list[item_index++].port = port;
		}
		line = strchr(line, '\n');
		if (line == NULL) break;
		line++;
	}while (*line != 0);

	return true;
error:
	if (fp != NULL) fclose(fp);
	if (filebuf != NULL) delete filebuf;
	return false;
}
